/*
 * remote_control.ino - ESP32 M25 Remote Control (Test Setup)
 *
 * One-handed remote control for Alber e-motion M25 power-assist wheels.
 * Test-setup variant: simple push buttons, single-color LEDs, no display.
 * Pin assignments and wiring details: device_config.h
 *
 * State machine:
 *   BOOT       -> calibrate joystick, self-test LEDs, power-on safety check
 *   CONNECTING -> attempt BLE connection to both wheels
 *   READY      -> connected, joystick in deadzone, no motor commands
 *   OPERATING  -> joystick active, sending motor commands at 20 Hz
 *   ERROR      -> E-stop pressed / watchdog timeout / connection lost
 *                 Press E-stop button again to reset back to CONNECTING.
 *   OFF        -> device in deep sleep, power consumption ~10-150 µA
 *                 Press power button to wake - device will reboot.
 */

#include <Arduino.h>
#include <esp_sleep.h>
#include "device_config.h"
#include "types.h"
#include "mapper.h"
#include "supervisor.h"
#include "joystick.h"
#include "led_control.h"
#include "button.h"
#include "motor_control.h"
#include "m25_ble.h"
#include "nvs_config.h"
#include "serial_commands.h"
#include "buzzer.h"
#include "Logger.h"

// ---------------------------------------------------------------------------
// Button instances (declared extern in button.h)
// ---------------------------------------------------------------------------
Button btnEstop    = { BTN_ESTOP_PIN };
Button btnHillHold = { BTN_HILL_HOLD_PIN };
Button btnAssist   = { BTN_ASSIST_PIN };
Button btnPower    = { BTN_POWER_PIN };

static SystemState sysState = STATE_BOOT;

// ---------------------------------------------------------------------------
// Persistent control state
// ---------------------------------------------------------------------------
static uint8_t assistLevel = ASSIST_INDOOR;   // overwritten by NVS load in setup()
static bool    hillHoldOn = false;
#ifdef ENABLE_BATTERY_MONITOR
static int     batteryPct = 100;
#endif

static uint32_t lastBleTickMs = 0;

// Loop heartbeat (debug - shows loop() is running)
static uint32_t lastHeartbeatMs = 0;
static uint32_t loopCounter = 0;

// ERROR state: limit BLE stop retries so writeValue() can't block loop() forever.
// We send up to BLE_ERROR_STOP_TRIES stops after entering ERROR, then give up.
// The wheel's own remote-control watchdog will cut power if it hears nothing.
#define BLE_ERROR_STOP_TRIES 3
static uint8_t _errorStopsSent = 0;

static MapperConfig mapperConfig;
static Mapper mapper(mapperConfig);
static SupervisorConfig supervisorConfig;
static Supervisor supervisor(mapper, supervisorConfig);

//! TODO: supervisor.notifyConnectionChange() exists as a fast-path failsafe for
// simultaneous dual-wheel disconnect. It is not yet wired to the BLE disconnect
// callback because it calls enterFailsafe(), which modifies Supervisor state and
// calls bleSendStop(). From Core 0 without synchronisation.  The Supervisor's
// polling in handlePaired/Armed/Driving detects disconnects within one update
// cycle (50 ms); wire this when a thread-safe event queue is available.

static void onSupervisorStateChange(SupervisorState oldState, SupervisorState newState) {
    (void)oldState;
    const char* newName = (newState == SUPERVISOR_DISCONNECTED) ? "DISCONNECTED" :
        (newState == SUPERVISOR_CONNECTING) ? "CONNECTING" :
        (newState == SUPERVISOR_PAIRED) ? "PAIRED" :
        (newState == SUPERVISOR_ARMED) ? "ARMED" :
        (newState == SUPERVISOR_DRIVING) ? "DRIVING" :
        (newState == SUPERVISOR_FAILSAFE) ? "FAILSAFE" : "?";
    LOG_DEBUG(TAG_SUPERVISOR, "State change: %s", newName);

    // Update legacy sysState for serial commands compatibility
    if (newState == SUPERVISOR_DISCONNECTED || newState == SUPERVISOR_CONNECTING) {
        sysState = STATE_CONNECTING;
    }
    else if (newState == SUPERVISOR_PAIRED) {
        sysState = STATE_READY;
    }
    else if (newState == SUPERVISOR_ARMED || newState == SUPERVISOR_DRIVING) {
        sysState = STATE_OPERATING;
    }
    else if (newState == SUPERVISOR_FAILSAFE) {
        sysState = STATE_ERROR;
    }

    // LED and buzzer feedback for state transitions
    switch (newState) {
    case SUPERVISOR_DISCONNECTED:
        ledSetStatus(LED_OFF);
        break;

    case SUPERVISOR_CONNECTING:
        ledSetStatus(LED_BLINK_SLOW);
        break;

    case SUPERVISOR_PAIRED:
        ledSetStatus(LED_OFF);
        buzzerPlay(BUZZ_CONFIRM);
        // Re-sync assist level to wheel, resets to its own default on disconnect.
        bleSendAssistLevel(assistLevel);
        LOG_INFO(TAG_SUPERVISOR, "Assist level re-synced to wheel: %s",
            assistConfigs[assistLevel].name);
        break;

    case SUPERVISOR_ARMED:
        ledSetStatus(LED_OFF);
        break;

    case SUPERVISOR_DRIVING:
        ledSetStatus(LED_OFF);
        break;

    case SUPERVISOR_FAILSAFE:
        ledSetStatus(LED_BLINK_FAST);
        buzzerPlay(BUZZ_ERROR);
        break;
    }
}

#ifdef ENABLE_BATTERY_MONITOR
static uint32_t lastBatteryMs = 0;
#define BATTERY_READ_INTERVAL_MS 10000
static int readBatteryPct() {
    int raw = analogRead(BATTERY_ADC_PIN);
    int pct = (int)(
        (float)(raw - BATT_ADC_EMPTY) * 100.0f
        / (float)(BATT_ADC_FULL - BATT_ADC_EMPTY)
        );
    if (pct < 0)   pct = 0;
    if (pct > 100) pct = 100;
    return pct;
}
#endif



static void enterOff() {
    sysState = STATE_OFF;
    supervisor.requestDisconnect();
    buzzerPlay(BUZZ_POWER_OFF);

    // Turn off all LEDs
    ledSetStatus(LED_OFF);
    ledSetBleMode(LED_OFF);
    ledSetBattery(0);  // force off
    ledSetHillHold(false);
    ledSetAssistLevel(ASSIST_INDOOR);  // shows off
    ledTick();  // Apply LED changes immediately

    LOG_INFO(TAG_POWER, "-> OFF (entering deep sleep)");
    LOG_INFO(TAG_POWER, "Press power button to wake up");
    Serial.flush();  // Wait for serial output to complete

    // Wait for buzzer pattern to complete before sleep
    while (buzzerIsActive()) {
        buzzerTick();
        delay(10);
    }

    delay(100);

    esp_sleep_enable_ext0_wakeup((gpio_num_t)BTN_POWER_PIN, 0);

    LOG_INFO(TAG_POWER, "Entering deep sleep...");
    Serial.flush();
    delay(50);

    esp_deep_sleep_start();
}

static bool powerOnSafetyCheck() {
#ifdef NO_JOYSTICK
    Logger::instance().logForced(LogLevel::INFO, TAG_SAFETY, __FILE__, __LINE__,
        "NO_JOYSTICK: press E-stop to confirm, or send 'confirm' via serial");
#else
    Logger::instance().logForced(LogLevel::INFO, TAG_SAFETY, __FILE__, __LINE__,
        "Power-on check: center joystick and hold for 5 seconds");
    Logger::instance().logForced(LogLevel::INFO, TAG_SAFETY, __FILE__, __LINE__,
        "(Send 'confirm' via serial or press E-stop to skip)");
#endif

    uint32_t centeredSince = 0;
    bool     centered = false;
    char     scBuf[16];
    uint8_t  scLen = 0;

    while (true) {
        buttonsTick();
        JoystickNorm js = joystickRead();

        while (Serial.available() > 0) {
            char c = (char)Serial.read();
            if (c == '\r') continue;
            if (c == '\n') {
                scBuf[scLen] = '\0';
                if (strcmp(scBuf, "confirm") == 0 || strcmp(scBuf, "skip") == 0) {
                    LOG_WARN(TAG_SAFETY, "Check BYPASSED via serial");
                    return true;
                }
                scLen = 0;
            }
            else if (scLen < (uint8_t)(sizeof(scBuf) - 1)) {
                scBuf[scLen++] = c;
            }
        }

#ifndef NO_JOYSTICK
        if (js.inDeadzone) {
            if (!centered) {
                centered = true;
                centeredSince = millis();
                LOG_INFO(TAG_SAFETY, "Joystick centered - hold for 5 seconds");
            }
        }
        else {
            if (centered) {
                centered = false;
                LOG_WARN(TAG_SAFETY, "Joystick off-center, re-center and hold");
            }
        }

        if (centered && ((millis() - centeredSince) >= 5000)) {
            LOG_INFO(TAG_SAFETY, "Check PASSED (auto-confirmed)");
            return true;
        }

        if (btnEstop.wasPressed()) {
            LOG_INFO(TAG_SAFETY, "Check PASSED (E-stop pressed)");
            return true;
        }
#else
        if (btnEstop.wasPressed()) {
            LOG_INFO(TAG_SAFETY, "Check PASSED (no-joystick mode)");
            return true;
        }
#endif

        ledTick();
        buzzerTick();
        delay(10);
    }
    return false;
}

static SerialContext _serialCtx = {
    &sysState,
    &assistLevel,
    &hillHoldOn,
    &supervisor,
    &mapperConfig,
    &mapper,
    enterOff,
    joystickRecalibrate,
#ifdef ENABLE_BATTERY_MONITOR
    & batteryPct,
#endif
};

void setup() {
    Serial.begin(115200);
    delay(200);
    const uint32_t defaultTagMask = TAG_ALL & ~(TAG_MOTOR | TAG_SUPERVISOR);
    Logger::instance().begin(LogLevel::DEBUG, defaultTagMask);
    Logger::instance().logForced(LogLevel::INFO, TAG_BOOT, __FILE__, __LINE__, "M25 Remote Control starting...");

    // Check wake-up reason
    esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();
    switch (wakeup_reason) {
    case ESP_SLEEP_WAKEUP_EXT0:
        Logger::instance().logForced(LogLevel::INFO, TAG_BOOT, __FILE__, __LINE__, "Wake-up from deep sleep via power button");
        break;
    case ESP_SLEEP_WAKEUP_UNDEFINED:
    default:
        Logger::instance().logForced(LogLevel::INFO, TAG_BOOT, __FILE__, __LINE__, "Cold boot or reset");
        break;
    }

    // Peripheral init
    ledInit();
    ledStartupTest();

    buzzerInit();
    buzzerPlay(BUZZ_POWER_ON);

    buttonsInit();
    joystickInit();

#ifdef ENABLE_BATTERY_MONITOR
    analogSetPinAttenuation(BATTERY_ADC_PIN, ADC_11db);
    batteryPct = readBatteryPct();
    ledSetBattery(batteryPct);
    LOG_INFO(TAG_BOOT, "Battery: %d %%", batteryPct);
#endif

    sysState = STATE_BOOT;
    powerOnSafetyCheck();
    Logger::instance().logForced(LogLevel::INFO, TAG_JOYSTICK, __FILE__, __LINE__,
        "Recalibrating joystick after safety check");
    joystickRecalibrate();

    // Load persisted wheel mode before bleInit so the boot log shows the
    // effective mode (falls back to compile-time WHEEL_MODE).
    {
        uint8_t savedMode = 0;
        if (nvsLoadWheelMode(&savedMode)) {
            bleSetWheelMode(savedMode);
            LOG_INFO(TAG_BOOT, "Wheel mode loaded from NVS: %s", bleWheelModeName(savedMode));
        }
    }

    bleInit("M25-Remote");
    // Supervisor manages all reconnection; disable bleTick()'s parallel
    // auto-reconnect path to avoid racing with the connect task on Core 0.
    bleSetAutoReconnect(false);
    bleStartMotorTask();   // spawn async write task on Core 0

    // Load persisted assist level (falls back to ASSIST_INDOOR if not set).
    nvsLoadAssistLevel(&assistLevel);

    // Load persisted max-speed override (only applied if NVS has a value).
    {
        uint8_t savedSpeed = 0;
        if (nvsLoadMaxSpeed(&savedSpeed)) {
            mapperConfig.maxSpeedNormal = savedSpeed;
            // mapper was constructed before setup() with the default config copy
            mapper.setConfig(mapperConfig);
            LOG_INFO(TAG_BOOT, "Max speed (normal) loaded from NVS: %u%%", savedSpeed);
        }
    }

    // Load persisted joystick full-range calibration.
    // Without this, theoretical ADC min/max (0/4095) are used and most joysticks
    // will never reach 1.0 normalized, capping effective speed.
    {
        int xMin, xMax, yMin, yMax;
        if (nvsLoadJsRange(&xMin, &xMax, &yMin, &yMax)) {
            joystickApplyFullRangeCalibration(xMin, xMax, yMin, yMax);
        } else {
            LOG_INFO(TAG_BOOT, "No joystick range cal in NVS - run 'cal full' to calibrate");
        }
    }

    ledSetAssistLevel(assistLevel);
    ledSetHillHold(hillHoldOn);

    char    leftMac[18], rightMac[18];
    uint8_t leftKey[16], rightKey[16];
    nvsLoadMac(WHEEL_LEFT, leftMac, sizeof(leftMac));
    nvsLoadMac(WHEEL_RIGHT, rightMac, sizeof(rightMac));
    nvsLoadKey(WHEEL_LEFT, leftKey);
    nvsLoadKey(WHEEL_RIGHT, rightKey);
    LOG_INFO(TAG_BOOT, "Left  wheel: %s", leftMac);
    LOG_INFO(TAG_BOOT, "Right wheel: %s", rightMac);
    supervisor.begin();
    supervisor.addStateCallback(onSupervisorStateChange);
    supervisor.requestConnect(leftMac, rightMac, leftKey, rightKey);

    serialInit(_serialCtx);
}

void loop() {
    uint32_t now = millis();
    loopCounter++;

    SupervisorState supState = supervisor.getState();

    const char* supStateName = supervisorStateToString(supState);

    if (now - lastHeartbeatMs >= 5000) {
        lastHeartbeatMs = now;
        LOG_DEBUG(TAG_SUPERVISOR, "loop heartbeat count=%u state=%s", loopCounter, supStateName);
    }

    serialTick(_serialCtx);

    buttonsTick();
    JoystickNorm js = joystickRead();

    ControlState control;
    control.vx = js.y;
    control.vy = js.x;
#ifdef NO_DEADMAN_HARDWARE
    control.deadman = true;   // no hardware button - always engaged
#else
    control.deadman = !js.inDeadzone;
#endif
    control.mode = js.inDeadzone ? DRIVE_MODE_STOP : DRIVE_MODE_NORMAL;
    control.timestamp = now;

    bool estopPressed = btnEstop.wasPressed();
    bool hillHoldPressed = btnHillHold.wasPressed();
    bool assistPressed = btnAssist.wasPressed();
    bool powerPressed = btnPower.wasPressed();

    if (estopPressed) {
        LOG_DEBUG(TAG_BUTTON, "E-STOP pressed (state=%s)", supStateName);
    }
    if (hillHoldPressed) {
        LOG_DEBUG(TAG_BUTTON, "HILL-HOLD pressed (state=%s)", supStateName);
    }
    if (assistPressed) {
        LOG_DEBUG(TAG_BUTTON, "ASSIST pressed (state=%s)", supStateName);
    }
    if (powerPressed) {
        LOG_DEBUG(TAG_BUTTON, "POWER pressed (state=%s)", supStateName);
    }

    if (powerPressed && sysState != STATE_BOOT) {
        if (sysState == STATE_OFF) {
            LOG_INFO(TAG_POWER, "Turning ON...");
            char    leftMac[18], rightMac[18];
            uint8_t leftKey[16], rightKey[16];
            nvsLoadMac(WHEEL_LEFT, leftMac, sizeof(leftMac));
            nvsLoadMac(WHEEL_RIGHT, rightMac, sizeof(rightMac));
            nvsLoadKey(WHEEL_LEFT, leftKey);
            nvsLoadKey(WHEEL_RIGHT, rightKey);
            bleInit("M25-Remote");
            ledSetAssistLevel(assistLevel);
            ledSetHillHold(hillHoldOn);
#ifdef ENABLE_BATTERY_MONITOR
            ledSetBattery(batteryPct);
#endif
            supervisor.requestConnect(leftMac, rightMac, leftKey, rightKey);
        }
        else {
            LOG_INFO(TAG_POWER, "Turning OFF...");
            enterOff();
        }
        ledTick();
        return;
    }

    if (estopPressed) {
        if (supState == SUPERVISOR_FAILSAFE) {
            LOG_WARN(TAG_SAFETY, "E-Stop reset: requesting reconnect...");
            supervisor.requestReconnect();
        }
        else {
            LOG_FATAL(TAG_SAFETY, "E-Stop emergency stop");
            supervisor.requestEmergencyStop("E-Stop button pressed");
        }
    }

    if (hillHoldPressed && assistPressed) {
        LOG_WARN(TAG_BUTTON, "Dual press: forcing reconnect...");
        supervisor.requestReconnect();
        ledTick();
        return;
    }

    if (hillHoldPressed) {
        if (supState == SUPERVISOR_PAIRED || supState == SUPERVISOR_ARMED) {
            hillHoldOn = !hillHoldOn;
            ledSetHillHold(hillHoldOn);
            buzzerPlay(BUZZ_BUTTON);
            bleSendHillHold(hillHoldOn);
            LOG_INFO(TAG_BUTTON, "HillHold %s", hillHoldOn ? "ON" : "OFF");
        }
        else if (supState == SUPERVISOR_DRIVING) {
            buzzerPlay(BUZZ_WARNING);
            LOG_WARN(TAG_BUTTON, "HillHold ignored - motors active");
        }
        else {
            LOG_WARN(TAG_BUTTON, "HillHold ignored - not connected");
        }
    }

    if (assistPressed) {
        if (supState == SUPERVISOR_PAIRED || supState == SUPERVISOR_ARMED) {
            assistLevel = (assistLevel + 1) % ASSIST_COUNT;
            nvsSaveAssistLevel(assistLevel);
            ledSetAssistLevel(assistLevel);
            buzzerPlay(BUZZ_CONFIRM);
            bleSendAssistLevel(assistLevel);
            LOG_INFO(TAG_BUTTON, "Assist -> %s (Vmax fwd %d %%)",
                assistConfigs[assistLevel].name,
                assistConfigs[assistLevel].vmaxForward);
        }
        else if (supState == SUPERVISOR_DRIVING) {
            buzzerPlay(BUZZ_WARNING);
            LOG_WARN(TAG_BUTTON, "Assist ignored - motors active, stop first");
        }
        else {
            LOG_WARN(TAG_BUTTON, "Assist ignored - not connected");
        }
    }

    supervisor.processInput(control);
    supervisor.update();

#ifdef ENABLE_BATTERY_MONITOR
    if (now - lastBatteryMs >= BATTERY_READ_INTERVAL_MS && sysState != STATE_OFF) {
        lastBatteryMs = now;
        batteryPct = readBatteryPct();
        ledSetBattery(batteryPct);
        LOG_INFO(TAG_TELEMETRY, "Battery %d %%", batteryPct);

        if (batteryPct <= BATT_AUTO_OFF_PCT && sysState != STATE_ERROR && sysState != STATE_OFF) {
            LOG_FATAL(TAG_POWER, "Battery critical - forcing disconnect");
            supervisor.requestDisconnect();
            buzzerPlay(BUZZ_ERROR);
        }
    }
#endif

    // BLE LED: derived from actual connection state every loop (none/partial/all)
    ledUpdateBle(bleAnyConnected(), bleAllConnected());
    ledTick();
    buzzerTick();
    // BLE housekeeping: auto-stops the traffic recorder when its duration expires.
    // Auto-reconnect is disabled (bleSetAutoReconnect(false) in setup); the
    // Supervisor owns all reconnection logic.
    bleTick();
}
