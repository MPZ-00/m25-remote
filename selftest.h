/*
 * selftest.h - Interactive hardware self-test, run from setup() before BLE starts
 *
 * Runs while NVS "st_done" is not set (fresh board, or scheduled via the
 * serial 'selftest' command). Motors cannot move: no wheel connection exists yet.
 *
 *   1. LEDs: all on together, then one at a time (tester watches)
 *   2. Buttons: press each once; its LED lights and a beep confirms
 *        E-stop -> status (red), Hill-Hold -> yellow, Assist -> green, Power -> battery (red)
 *   3. Joystick: full 'cal full' sequence, saved to NVS
 *
 * A missing or broken part must not trap the device in self-test every boot:
 *   - during the LED step, holding E-stop SELFTEST_SKIP_HOLD_MS skips everything
 *   - during the button step, holding any working button that long skips the
 *     missing buttons and continues with the joystick
 */

#ifndef SELFTEST_H
#define SELFTEST_H

#include <Arduino.h>
#include "device_config.h"
#include "led_control.h"
#include "button.h"
#include "buzzer.h"
#include "joystick.h"
#include "serial_commands.h"
#include "Logger.h"

#define SELFTEST_SKIP_HOLD_MS     3000
#define SELFTEST_BUTTON_TIMEOUT_MS 60000

enum SelfTestResult : uint8_t {
    SELFTEST_PASS = 0,
    SELFTEST_FAIL,
    SELFTEST_SKIPPED,
    SELFTEST_PARTIAL,   // passed with missing buttons skipped by the tester
};

static void _stLog(const char* msg) {
    Logger::instance().logForced(LogLevel::INFO, TAG_BOOT, __FILE__, __LINE__, "[SelfTest] %s", msg);
}

static void _stAllLeds(bool on) {
    const uint8_t pins[] = { LED_STATUS_PIN, LED_BATTERY_PIN, LED_HILL_HOLD_PIN, LED_ASSIST_PIN, LED_BLE_PIN };
    for (uint8_t pin : pins) _ledSetDuty(pin, on ? LED_DUTY_ON : LED_DUTY_OFF);
}

// Presses during one phase must not count in the next, or reach loop() as actions
static void _stClearButtonEvents() {
    Button* all[] = { &btnEstop, &btnHillHold, &btnAssist, &btnPower };
    for (Button* b : all) {
        (void)b->wasPressed();
        b->cancelPress();
    }
}

static bool _stSkipRequested() {
    return btnEstop.isHeld() && (millis() - btnEstop.pressStartMs) >= SELFTEST_SKIP_HOLD_MS;
}

// Returns false if the tester asked to skip
static bool _stWait(unsigned long ms) {
    unsigned long end = millis() + ms;
    while (millis() < end) {
        buttonsTick();
        buzzerTick();
        if (_stSkipRequested()) return false;
        delay(5);
    }
    return true;
}

static void _stWaitRelease() {
    unsigned long until = millis() + 600;
    while (millis() < until || btnEstop.isHeld() || btnHillHold.isHeld()
           || btnAssist.isHeld() || btnPower.isHeld()) {
        buttonsTick();
        buzzerTick();
        delay(5);
    }
}

// Tester sets the pace between steps; any button, since one may be missing
static void _stWaitForAnyPress() {
    _stClearButtonEvents();
    while (true) {
        buttonsTick();
        buzzerTick();
        if (btnEstop.wasPressed() | btnHillHold.wasPressed()
            | btnAssist.wasPressed() | btnPower.wasPressed()) break;
        delay(5);
    }
    buzzerPlay(BUZZ_BUTTON);
    _stWaitRelease();
    _stClearButtonEvents();
}

static bool _stLedPhase() {
    _stLog("Step 1/3: LEDs - all on, then one by one. Watch that each lights. A beep plays now.");
    buzzerPlay(BUZZ_BUTTON);
    _stAllLeds(true);
    if (!_stWait(1500)) return false;
    _stAllLeds(false);

    struct { uint8_t pin; const char* name; } leds[] = {
        { LED_STATUS_PIN,    "status (red)" },
        { LED_BATTERY_PIN,   "battery (red)" },
        { LED_HILL_HOLD_PIN, "hill-hold (yellow)" },
        { LED_ASSIST_PIN,    "assist (green)" },
        { LED_BLE_PIN,       "BLE (white)" },
    };
    for (auto& l : leds) {
        Logger::instance().logForced(LogLevel::INFO, TAG_BOOT, __FILE__, __LINE__, "[SelfTest]   %s", l.name);
        _ledSetDuty(l.pin, LED_DUTY_ON);
        bool ok = _stWait(500);
        _ledSetDuty(l.pin, LED_DUTY_OFF);
        if (!ok) return false;
    }
    return true;
}

// Returns SELFTEST_PASS when every button was pressed
static SelfTestResult _stButtonPhase() {
    _stLog("Step 2/3: Buttons - press each once (E-stop, Hill-Hold, Assist, Power)");
    _stLog("  missing button? hold any working one 3s to skip it");
    struct { Button* btn; uint8_t led; const char* name; bool seen; } items[] = {
        { &btnEstop,    LED_STATUS_PIN,    "E-stop",    false },
        { &btnHillHold, LED_HILL_HOLD_PIN, "Hill-Hold", false },
        { &btnAssist,   LED_ASSIST_PIN,    "Assist",    false },
        { &btnPower,    LED_BATTERY_PIN,   "Power",     false },
    };
    const uint8_t count = sizeof(items) / sizeof(items[0]);
    _stClearButtonEvents();
    uint8_t seen = 0;
    unsigned long start = millis();

    while (seen < count) {
        buttonsTick();
        buzzerTick();
        for (auto& it : items) {
            if (it.btn->isHeld() && (millis() - it.btn->pressStartMs) >= SELFTEST_SKIP_HOLD_MS) {
                for (auto& m : items) {
                    if (!m.seen) {
                        Logger::instance().logForced(LogLevel::WARN, TAG_BOOT, __FILE__, __LINE__,
                            "[SelfTest]   %s skipped", m.name);
                    }
                }
                buzzerPlay(BUZZ_WARNING);
                _stWaitRelease();
                _stAllLeds(false);
                return SELFTEST_PARTIAL;
            }
        }
        if (millis() - start >= SELFTEST_BUTTON_TIMEOUT_MS) {
            for (auto& it : items) {
                if (!it.seen) {
                    Logger::instance().logForced(LogLevel::WARN, TAG_BOOT, __FILE__, __LINE__,
                        "[SelfTest]   FAIL: %s never pressed", it.name);
                }
            }
            return SELFTEST_FAIL;
        }
        for (auto& it : items) {
            if (it.btn->wasPressed() && !it.seen) {
                it.seen = true;
                seen++;
                _ledSetDuty(it.led, LED_DUTY_ON);
                buzzerPlay(BUZZ_BUTTON);
                Logger::instance().logForced(LogLevel::INFO, TAG_BOOT, __FILE__, __LINE__,
                    "[SelfTest]   %s OK (%u/%u)", it.name, seen, count);
            }
        }
        delay(5);
    }
    // Let the last beep finish and leave the LEDs visible for a moment
    if (!_stWait(800)) return SELFTEST_SKIPPED;
    _stAllLeds(false);
    return SELFTEST_PASS;
}

static SelfTestResult selfTestRun() {
    _stLog("=== Hardware self-test === (hold E-stop 3s to skip)");

    SelfTestResult result = SELFTEST_PASS;
    if (!_stLedPhase()) {
        result = SELFTEST_SKIPPED;
    }
    if (result == SELFTEST_PASS) {
        result = _stButtonPhase();
    }
#ifndef NO_JOYSTICK
    if (result == SELFTEST_PASS || result == SELFTEST_PARTIAL) {
        _stLog("Step 3/3: Joystick - press E-stop (or any working button) to start");
        _stWaitForAnyPress();
        _stLog("  push in each prompted direction and hold; beep = registered, then let go");
        if (!_scRunFullCal(1200, nullptr)) result = SELFTEST_FAIL;
    }
#endif

    _stAllLeds(false);
    static const char* const resultNames[] = { "PASS", "FAIL", "SKIPPED", "PARTIAL" };
    eventLogf("SELFTEST %s", resultNames[result]);
    switch (result) {
    case SELFTEST_PASS:
        _stLog("PASSED - will not run again ('selftest' over serial to repeat)");
        buzzerPlay(BUZZ_CONFIRM);
        break;
    case SELFTEST_PARTIAL:
        _stLog("PASSED with skipped buttons - marked done ('selftest' to repeat)");
        buzzerPlay(BUZZ_READY);
        break;
    case SELFTEST_SKIPPED:
        _stLog("SKIPPED via E-stop hold - marked done");
        buzzerPlay(BUZZ_POWER_OFF);
        break;
    default:
        _stLog("FAILED - runs again on next boot (hold a working button 3s to skip missing ones)");
        buzzerPlay(BUZZ_ERROR);
        break;
    }
    // A skip hold must not reach the main loop as an E-stop or power press
    _stWaitRelease();
    _stClearButtonEvents();
    return result;
}

#endif // SELFTEST_H
