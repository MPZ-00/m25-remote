/*
 * pinmap.h - Runtime GPIO assignment for buttons and LEDs.
 *
 * Lets testers rewire the remote to whatever buttons/LEDs they have without
 * rebuilding. Assignments live in their own NVS namespace ("m25pins"), so
 * 'config reset' does not wipe them. They apply at the next boot only:
 * pinmapApplyBoot() runs before ledInit()/buttonsInit().
 *
 * Serial commands (wired in serial_commands.h):
 *   pinmap [show]                      Active vs saved assignment
 *   pinmap btn <name> <gpio> [nc|no]   estop|hill|assist|power
 *   pinmap led <name> <gpio>           status|battery|hill|assist|ble
 *   pinmap learn [btn|led]             Guided wizard (requires 'scan off')
 *   pinmap reset                       Back to device_config.h defaults
 *
 * Button values encode the pin in bits 0-5 and "normally closed" in bit 7.
 */

#ifndef PINMAP_H
#define PINMAP_H

#include <Arduino.h>
#include <Preferences.h>
#include <driver/gpio.h>
#include "device_config.h"
#include "button.h"
#include "led_control.h"
#include "buzzer.h"
#include "eventlog.h"
#include "Logger.h"

#define PINMAP_NAMESPACE "m25pins"
#define PM_NC_BIT        0x80
#define PM_PIN_MASK      0x3F

enum PinFn : uint8_t {
    PF_BTN_ESTOP = 0,
    PF_BTN_HILL,
    PF_BTN_ASSIST,
    PF_BTN_POWER,
    PF_LED_STATUS,
    PF_LED_BATTERY,
    PF_LED_HILL,
    PF_LED_ASSIST,
    PF_LED_BLE,
    PF_COUNT
};
#define PF_BTN_COUNT 4

struct PinFnInfo {
    const char* key;      // serial name
    const char* label;
    const char* nvsKey;
    uint8_t     dflt;
};

static const PinFnInfo _pmFns[PF_COUNT] = {
    { "estop",   "E-stop button",          "estop",  BTN_ESTOP_PIN },
    { "hill",    "Hill-Hold button",       "hill",   BTN_HILL_HOLD_PIN },
    { "assist",  "Assist button",          "assist", BTN_ASSIST_PIN },
    { "power",   "Power button",           "power",  BTN_POWER_PIN },
    { "status",  "status LED (red)",       "lstat",  LED_STATUS_PIN },
    { "battery", "battery LED (red)",      "lbatt",  LED_BATTERY_PIN },
    { "hill",    "hill-hold LED (yellow)", "lhill",  LED_HILL_HOLD_PIN },
    { "assist",  "assist LED (green)",     "lasst",  LED_ASSIST_PIN },
    { "ble",     "BLE LED (white)",        "lble",   LED_BLE_PIN },
};

struct PinMap {
    uint8_t v[PF_COUNT];
};

static PinMap _pmActive;   // what this boot runs with

static Button* const _pmButtons[PF_BTN_COUNT] = { &btnEstop, &btnHillHold, &btnAssist, &btnPower };

inline bool    _pmIsButton(uint8_t fn) { return fn < PF_BTN_COUNT; }
inline uint8_t _pmPin(uint8_t v)       { return v & PM_PIN_MASK; }
inline bool    _pmNc(uint8_t v)        { return (v & PM_NC_BIT) != 0; }

static void _pmOut(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
static void _pmOut(const char* fmt, ...) {
    char buf[200];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    Logger::instance().logForced(LogLevel::INFO, TAG_CMD, __FILE__, __LINE__, "[Pinmap] %s", buf);
}

// ---------------------------------------------------------------------------
// Pin rules
// ---------------------------------------------------------------------------
// Excludes UART (1,3), flash (6-11), and strapping pins 0/2/12/15: a pull-up or
// driven LED there can change boot mode or flash voltage.
static const uint8_t _pmUsablePins[] = {
    4, 5, 13, 14, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33, 34, 35, 36, 37, 38, 39
};

inline bool _pmRtcPin(uint8_t pin) {
    return pin == 4 || pin == 13 || pin == 14 || (pin >= 25 && pin <= 27) || (pin >= 32 && pin <= 39);
}

// Returns nullptr if allowed, otherwise the reason.
inline const char* _pmPinRejectReason(uint8_t fn, uint8_t pin) {
    bool usable = false;
    for (uint8_t p : _pmUsablePins) if (p == pin) usable = true;
    if (!usable) return "not usable (UART, flash, strapping or nonexistent pin)";
#ifndef NO_JOYSTICK
    if (pin == JOYSTICK_X_PIN || pin == JOYSTICK_Y_PIN) return "used by the joystick";
#endif
    if (pin == BUZZER_PIN) return "used by the buzzer";
#ifdef ENABLE_BATTERY_MONITOR
    if (pin == BATTERY_ADC_PIN) return "used by the battery monitor";
#endif
    if (!_pmIsButton(fn) && pin >= 34) return "input-only, cannot drive an LED";
    if (fn == PF_BTN_POWER && !_pmRtcPin(pin)) return "power button must be an RTC pin (4,13,14,25-27,32-39) to wake from sleep";
    return nullptr;
}

// Whole-map check: every pin allowed and no pin used twice.
inline bool _pmValidate(const PinMap& m, char* err, size_t errLen) {
    for (uint8_t i = 0; i < PF_COUNT; i++) {
        uint8_t pin = _pmPin(m.v[i]);
        const char* why = _pmPinRejectReason(i, pin);
        if (why) {
            snprintf(err, errLen, "%s on GPIO %u: %s", _pmFns[i].label, pin, why);
            return false;
        }
        for (uint8_t j = 0; j < i; j++) {
            if (_pmPin(m.v[j]) == pin) {
                snprintf(err, errLen, "GPIO %u used by both %s and %s", pin, _pmFns[j].label, _pmFns[i].label);
                return false;
            }
        }
    }
    return true;
}

// ---------------------------------------------------------------------------
// NVS
// ---------------------------------------------------------------------------
inline void pinmapDefaults(PinMap& m) {
    for (uint8_t i = 0; i < PF_COUNT; i++) m.v[i] = _pmFns[i].dflt;
}

// Returns a bitmask of functions that came from NVS.
inline uint16_t pinmapLoad(PinMap& m) {
    pinmapDefaults(m);
    uint16_t fromNvs = 0;
    Preferences p;
    if (!p.begin(PINMAP_NAMESPACE, /*readOnly=*/false)) return 0;
    for (uint8_t i = 0; i < PF_COUNT; i++) {
        if (p.isKey(_pmFns[i].nvsKey)) {
            m.v[i] = p.getUChar(_pmFns[i].nvsKey, _pmFns[i].dflt);
            fromNvs |= (1u << i);
        }
    }
    p.end();
    return fromNvs;
}

// Values equal to the default are removed so a later default change still applies.
inline bool pinmapSave(const PinMap& m) {
    Preferences p;
    if (!p.begin(PINMAP_NAMESPACE, /*readOnly=*/false)) return false;
    bool ok = true;
    for (uint8_t i = 0; i < PF_COUNT; i++) {
        if (m.v[i] == _pmFns[i].dflt) {
            if (p.isKey(_pmFns[i].nvsKey)) p.remove(_pmFns[i].nvsKey);
        }
        else {
            ok &= p.putUChar(_pmFns[i].nvsKey, m.v[i]) == 1;
        }
    }
    p.end();
    return ok;
}

inline void pinmapClear() {
    Preferences p;
    if (!p.begin(PINMAP_NAMESPACE, /*readOnly=*/false)) return;
    p.clear();
    p.end();
}

// Call before ledInit() and buttonsInit(). An invalid saved map is ignored as
// a whole: a half-applied map could leave the E-stop on the wrong pin.
inline void pinmapApplyBoot() {
    PinMap m;
    uint16_t fromNvs = pinmapLoad(m);
    char err[120];
    if (fromNvs && !_pmValidate(m, err, sizeof(err))) {
        Logger::instance().logForced(LogLevel::ERROR, TAG_BOOT, __FILE__, __LINE__,
            "Saved pin map rejected (%s) - using build defaults", err);
        pinmapDefaults(m);
        fromNvs = 0;
    }
    _pmActive = m;
    for (uint8_t i = 0; i < PF_BTN_COUNT; i++) {
        _pmButtons[i]->pin = _pmPin(m.v[i]);
        _pmButtons[i]->activeHigh = _pmNc(m.v[i]);
    }
    for (uint8_t i = 0; i < LED_ID_COUNT; i++) {
        ledSetPin((LedId)i, _pmPin(m.v[PF_BTN_COUNT + i]));
    }
    if (fromNvs) {
        Logger::instance().logForced(LogLevel::INFO, TAG_BOOT, __FILE__, __LINE__,
            "Pin map from NVS: E-stop=%u%s Hill=%u%s Assist=%u%s Power=%u%s | LEDs %u/%u/%u/%u/%u",
            _pmPin(m.v[0]), _pmNc(m.v[0]) ? "nc" : "", _pmPin(m.v[1]), _pmNc(m.v[1]) ? "nc" : "",
            _pmPin(m.v[2]), _pmNc(m.v[2]) ? "nc" : "", _pmPin(m.v[3]), _pmNc(m.v[3]) ? "nc" : "",
            _pmPin(m.v[4]), _pmPin(m.v[5]), _pmPin(m.v[6]), _pmPin(m.v[7]), _pmPin(m.v[8]));
    }
}

// ---------------------------------------------------------------------------
// Serial answers for the wizard
// ---------------------------------------------------------------------------
enum PmAnswer : uint8_t { PM_NONE, PM_YES, PM_NO, PM_SKIP, PM_CANCEL };

static char     _pmLine[12];
static uint8_t  _pmLineLen = 0;
static uint32_t _pmLastCharMs = 0;

static PmAnswer _pmFinishLine() {
    _pmLine[_pmLineLen] = '\0';
    _pmLineLen = 0;
    const char* s = _pmLine;
    while (*s == ' ') s++;
    if (*s == '\0') return PM_NONE;
    if (strcmp(s, "y") == 0 || strcmp(s, "yes") == 0)    return PM_YES;
    if (strcmp(s, "n") == 0 || strcmp(s, "no") == 0)     return PM_NO;
    if (strcmp(s, "s") == 0 || strcmp(s, "skip") == 0)   return PM_SKIP;
    if (strcmp(s, "c") == 0 || strcmp(s, "cancel") == 0) return PM_CANCEL;
    _pmOut("'%s'? type y, n, s or c", s);
    return PM_NONE;
}

// Non-blocking. A line without terminator counts as complete after a short
// pause, since not every serial monitor is set to send CR/LF.
static PmAnswer _pmPollAnswer() {
    while (Serial.available() > 0) {
        char c = (char)Serial.read();
        _pmLastCharMs = millis();
        if (c == '\r' || c == '\n') {
            if (_pmLineLen) return _pmFinishLine();
            continue;
        }
        if (_pmLineLen < sizeof(_pmLine) - 1) _pmLine[_pmLineLen++] = (char)tolower((unsigned char)c);
    }
    if (_pmLineLen && millis() - _pmLastCharMs > 400) return _pmFinishLine();
    return PM_NONE;
}

static PmAnswer _pmAsk(bool allowSkip) {
    while (true) {
        buzzerTick();
        PmAnswer a = _pmPollAnswer();
        if (a == PM_SKIP && !allowSkip) {
            _pmOut("cannot skip this one");
            continue;
        }
        if (a != PM_NONE) return a;
        delay(5);
    }
}

// ---------------------------------------------------------------------------
// Button wizard
// ---------------------------------------------------------------------------
struct PmScan {
    uint8_t  pins[sizeof(_pmUsablePins)];
    uint8_t  idle[sizeof(_pmUsablePins)];
    uint32_t since[sizeof(_pmUsablePins)];
    uint8_t  n;
};

// 34-39 have no internal pull-up and float, so they would "press" on their own.
static void _pmScanPrepare(PmScan& sc) {
    sc.n = 0;
    uint8_t candidates[sizeof(_pmUsablePins)];
    uint8_t nc = 0;
    for (uint8_t pin : _pmUsablePins) {
        if (pin >= 34 || _pmPinRejectReason(PF_BTN_ESTOP, pin)) continue;
        pinMode(pin, INPUT_PULLUP);
        candidates[nc++] = pin;
    }
    delay(20);
    for (uint8_t i = 0; i < nc; i++) {
        int first = digitalRead(candidates[i]);
        bool stable = true;
        for (int k = 0; k < 5 && stable; k++) {
            delay(2);
            stable = digitalRead(candidates[i]) == first;
        }
        if (!stable) continue;
        sc.pins[sc.n] = candidates[i];
        sc.idle[sc.n] = (uint8_t)first;
        sc.since[sc.n] = 0;
        sc.n++;
    }
}

static void _pmWaitAllIdle(const PmScan& sc) {
    uint32_t idleSince = millis();
    while (millis() - idleSince < 150) {
        for (uint8_t i = 0; i < sc.n; i++) {
            if (digitalRead(sc.pins[i]) != sc.idle[i]) idleSince = millis();
        }
        buzzerTick();
        delay(5);
    }
}

// Returns PM_YES with pin/level filled, or PM_SKIP / PM_CANCEL.
static PmAnswer _pmDetectPress(PmScan& sc, bool allowSkip, uint8_t* pin, uint8_t* pressedLevel) {
    for (uint8_t i = 0; i < sc.n; i++) sc.since[i] = 0;
    while (true) {
        buzzerTick();
        PmAnswer a = _pmPollAnswer();
        if (a == PM_CANCEL || (a == PM_SKIP && allowSkip)) return a;
        if (a != PM_NONE) _pmOut("press the button now%s, or c = cancel", allowSkip ? ", s = skip" : "");

        uint32_t now = millis();
        uint8_t hits = 0, hit = 0;
        for (uint8_t i = 0; i < sc.n; i++) {
            if (digitalRead(sc.pins[i]) != sc.idle[i]) {
                if (!sc.since[i]) sc.since[i] = now | 1;
                if (now - sc.since[i] >= DEBOUNCE_MS) { hits++; hit = i; }
            }
            else {
                sc.since[i] = 0;
            }
        }
        if (hits > 1) {
            _pmOut("several pins changed at once - press one button only, then release");
            _pmWaitAllIdle(sc);
            for (uint8_t i = 0; i < sc.n; i++) sc.since[i] = 0;
            continue;
        }
        if (hits == 1) {
            *pin = sc.pins[hit];
            *pressedLevel = (uint8_t)digitalRead(sc.pins[hit]);
            buzzerPlay(BUZZ_BUTTON);
            _pmWaitAllIdle(sc);
            return PM_YES;
        }
        delay(2);
    }
}

// Returns false if cancelled.
static bool _pmLearnButtons(PinMap& m) {
    PmScan sc;
    _pmScanPrepare(sc);
    _pmOut("Buttons: press each one when asked. Answers: y = keep, n = retry, s = skip (keep saved), c = cancel");
    bool taken[64] = {false};

    for (uint8_t fn = 0; fn < PF_BTN_COUNT; fn++) {
        bool allowSkip = (fn != PF_BTN_ESTOP);
        while (true) {
            _pmOut("Press and release the %s (saved: GPIO %u)%s", _pmFns[fn].label, _pmPin(m.v[fn]),
                allowSkip ? "" : " - required, cannot be skipped");
            uint8_t pin = 0, level = 0;
            PmAnswer a = _pmDetectPress(sc, allowSkip, &pin, &level);
            if (a == PM_CANCEL) return false;
            if (a == PM_SKIP) {
                taken[_pmPin(m.v[fn])] = true;
                _pmOut("%s: kept GPIO %u", _pmFns[fn].label, _pmPin(m.v[fn]));
                break;
            }
            if (taken[pin]) {
                _pmOut("GPIO %u is already assigned in this run - press a different button", pin);
                continue;
            }
            const char* why = _pmPinRejectReason(fn, pin);
            if (why) {
                _pmOut("GPIO %u can't be the %s: %s", pin, _pmFns[fn].label, why);
                continue;
            }
            // Pull-up idles HIGH; idling LOW means the switch is closed at rest.
            bool nc = (level == HIGH);
            _pmOut("%s -> GPIO %u (%s). Keep? y/n/s/c", _pmFns[fn].label, pin,
                nc ? "normally closed" : "normally open");
            a = _pmAsk(allowSkip);
            if (a == PM_CANCEL) return false;
            if (a == PM_NO) continue;
            if (a == PM_SKIP) {
                taken[_pmPin(m.v[fn])] = true;
                break;
            }
            m.v[fn] = pin | (nc ? PM_NC_BIT : 0);
            taken[pin] = true;
            buzzerPlay(BUZZ_CONFIRM);
            break;
        }
    }
    return true;
}

// ---------------------------------------------------------------------------
// LED wizard
// ---------------------------------------------------------------------------
// Returns PM_YES / PM_NO (next) / PM_SKIP / PM_CANCEL for one blinking pin.
static PmAnswer _pmAskLed(uint8_t pin, Button* btns) {
    pinMode(pin, OUTPUT);
    // The candidate may really be a button to GND; weakest drive keeps that
    // short harmless while an LED is still visible.
    gpio_set_drive_capability((gpio_num_t)pin, GPIO_DRIVE_CAP_0);
    for (uint8_t i = 0; i < PF_BTN_COUNT; i++) {
        (void)btns[i].wasPressed();
        (void)btns[i].wasShortReleased();
        if (btns[i].isHeld()) btns[i].cancelPress();
    }
    uint32_t lastToggle = millis();
    bool on = true;
    digitalWrite(pin, on ? HIGH : LOW);
    PmAnswer result = PM_NONE;
    while (result == PM_NONE) {
        uint32_t now = millis();
        if (now - lastToggle >= 250) {
            lastToggle = now;
            on = !on;
            digitalWrite(pin, on ? HIGH : LOW);
        }
        for (uint8_t i = 0; i < PF_BTN_COUNT; i++) btns[i].tick();
        buzzerTick();

        if (btns[PF_BTN_ESTOP].wasHeldFor(2000)) result = PM_CANCEL;
        else if (btns[PF_BTN_ESTOP].wasShortReleased()) result = PM_YES;
        for (uint8_t i = 1; i < PF_BTN_COUNT && result == PM_NONE; i++) {
            if (btns[i].wasPressed()) result = PM_NO;
        }
        if (result == PM_NONE) result = _pmPollAnswer();
        delay(5);
    }
    digitalWrite(pin, LOW);
    pinMode(pin, INPUT);
    gpio_set_drive_capability((gpio_num_t)pin, GPIO_DRIVE_CAP_2);
    return result;
}

static bool _pmLearnLeds(PinMap& m) {
    // Confirm with the buttons as they are about to be saved, not as booted.
    Button btns[PF_BTN_COUNT] = {};
    for (uint8_t i = 0; i < PF_BTN_COUNT; i++) {
        btns[i].pin = _pmPin(m.v[i]);
        btns[i].activeHigh = _pmNc(m.v[i]);
        btns[i].init();
    }
    _pmOut("LEDs: each candidate pin blinks. E-stop or y = this one, other button or n = next pin,");
    _pmOut("  s = skip (keep saved), c or hold E-stop 2s = cancel");

    bool taken[64] = {false};
    for (uint8_t i = 0; i < PF_BTN_COUNT; i++) {
        taken[_pmPin(m.v[i])] = true;
        taken[_pmPin(_pmActive.v[i])] = true;   // may still be wired as a button
    }

    for (uint8_t fn = PF_BTN_COUNT; fn < PF_COUNT; fn++) {
        // Saved pin first, then the build default, then everything else.
        uint8_t order[sizeof(_pmUsablePins) + 2];
        uint8_t n = 0;
        auto push = [&](uint8_t pin) {
            if (taken[pin] || _pmPinRejectReason(fn, pin)) return;
            for (uint8_t k = 0; k < n; k++) if (order[k] == pin) return;
            order[n++] = pin;
        };
        push(_pmPin(m.v[fn]));
        push(_pmFns[fn].dflt);
        for (uint8_t pin : _pmUsablePins) push(pin);
        if (n == 0) {
            _pmOut("%s: no free output pin left - kept GPIO %u", _pmFns[fn].label, _pmPin(m.v[fn]));
            continue;
        }

        bool done = false;
        for (uint8_t k = 0; !done; k = (uint8_t)((k + 1) % n)) {
            if (k == 0) _pmOut("Which pin lights the %s?", _pmFns[fn].label);
            _pmOut("  blinking GPIO %u (%u/%u)", order[k], k + 1, n);
            PmAnswer a = _pmAskLed(order[k], btns);
            if (a == PM_CANCEL) return false;
            if (a == PM_SKIP) {
                taken[_pmPin(m.v[fn])] = true;
                _pmOut("%s: kept GPIO %u", _pmFns[fn].label, _pmPin(m.v[fn]));
                done = true;
            }
            else if (a == PM_YES) {
                m.v[fn] = order[k];
                taken[order[k]] = true;
                buzzerPlay(BUZZ_CONFIRM);
                _pmOut("%s -> GPIO %u", _pmFns[fn].label, order[k]);
                done = true;
            }
        }
    }
    return true;
}

// ---------------------------------------------------------------------------
// Public entry points
// ---------------------------------------------------------------------------
inline void pinmapPrint() {
    PinMap saved;
    uint16_t fromNvs = pinmapLoad(saved);
    _pmOut("%-24s active  saved", "function");
    for (uint8_t i = 0; i < PF_COUNT; i++) {
        bool pending = saved.v[i] != _pmActive.v[i];
        _pmOut("%-24s %3u%-3s  %3u%-3s %s%s", _pmFns[i].label,
            _pmPin(_pmActive.v[i]), _pmNc(_pmActive.v[i]) ? " nc" : "",
            _pmPin(saved.v[i]), _pmNc(saved.v[i]) ? " nc" : "",
            (fromNvs & (1u << i)) ? "[NVS]" : "[default]",
            pending ? "  restart pending" : "");
    }
}

static void _pmRestoreHardware() {
    for (LedState* l : _ledById) {
        ledcDetach(l->pin);
        ledcAttach(l->pin, LEDC_FREQ_HZ, LEDC_RESOLUTION);
        _ledSetDuty(l->pin, LED_DUTY_OFF);
    }
    buttonsInit();
}

static bool _pmCommit(const PinMap& m) {
    char err[120];
    if (!_pmValidate(m, err, sizeof(err))) {
        _pmOut("rejected: %s", err);
        return false;
    }
    if (!pinmapSave(m)) {
        _pmOut("NVS write failed");
        return false;
    }
    eventLogf("PINMAP SAVED");
    return true;
}

// Blocking. Caller guarantees no wheel link (supervisor held in DISCONNECTED).
inline void pinmapLearn(bool doButtons, bool doLeds) {
    PinMap m;
    pinmapLoad(m);
    while (Serial.available() > 0) (void)Serial.read();
    _pmLineLen = 0;

    bool ok = true;
    if (doButtons) ok = _pmLearnButtons(m);
    if (ok && doLeds) ok = _pmLearnLeds(m);

    if (!ok) {
        _pmOut("Cancelled - nothing saved");
        _pmRestoreHardware();
        return;
    }

    _pmOut("Result:");
    for (uint8_t i = 0; i < PF_COUNT; i++) {
        _pmOut("  %-24s GPIO %u%s", _pmFns[i].label, _pmPin(m.v[i]), _pmNc(m.v[i]) ? " (nc)" : "");
    }
    _pmOut("Save? y/n");
    if (_pmAsk(false) != PM_YES || !_pmCommit(m)) {
        _pmOut("Not saved");
        _pmRestoreHardware();
        return;
    }
    _pmOut("Saved. Restart now to apply? y/n");
    if (_pmAsk(false) == PM_YES) {
        _pmOut("Restarting...");
        Serial.flush();
        delay(100);
        ESP.restart();
    }
    _pmOut("Applies on next boot ('restart')");
    _pmRestoreHardware();
}

static int _pmFindFn(const char* name, bool button) {
    uint8_t from = button ? 0 : PF_BTN_COUNT;
    uint8_t to   = button ? PF_BTN_COUNT : PF_COUNT;
    for (uint8_t i = from; i < to; i++) {
        if (strcmp(name, _pmFns[i].key) == 0) return i;
    }
    return -1;
}

// "btn <name> <gpio> [nc|no]" or "led <name> <gpio>"
inline void pinmapSet(const char* args, bool button) {
    char name[12] = {0};
    char mode[4] = {0};
    int pin = -1;
    int n = sscanf(args, "%11s %d %3s", name, &pin, mode);
    int fn = (n >= 2) ? _pmFindFn(name, button) : -1;
    if (fn < 0 || pin < 0 || pin > 39) {
        _pmOut(button ? "use: pinmap btn <estop|hill|assist|power> <gpio> [nc|no]"
                      : "use: pinmap led <status|battery|hill|assist|ble> <gpio>");
        return;
    }
    bool nc = false;
    if (n == 3) {
        if (!button || (strcmp(mode, "nc") != 0 && strcmp(mode, "no") != 0)) {
            _pmOut("last argument must be 'nc' or 'no' (buttons only)");
            return;
        }
        nc = strcmp(mode, "nc") == 0;
    }
    PinMap m;
    pinmapLoad(m);
    m.v[fn] = (uint8_t)pin | (nc ? PM_NC_BIT : 0);
    if (!_pmCommit(m)) return;
    _pmOut("%s -> GPIO %d%s saved, 'restart' to apply", _pmFns[fn].label, pin, nc ? " (nc)" : "");
    if (button && pin >= 34) _pmOut("note: GPIO %d has no internal pull-up, add an external resistor", pin);
}

#endif // PINMAP_H
