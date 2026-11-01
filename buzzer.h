/*
 * buzzer.h - Buzzer control (passive or active)
 *
 * Passive (default): a piezo driven with a BUZZER_TONE_HZ square wave via LEDC.
 *   Its own frequency/resolution gives it a separate LEDC timer from the LEDs.
 * Active (BUZZER_ACTIVE or pinmap): a buzzer with built-in oscillator, driven
 *   HIGH/LOW. Needs a transistor; it draws more than a GPIO should source.
 * Pin and type come from device_config.h, overridden by pinmap.h at boot.
 */

#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>
#include "device_config.h"
#include "Logger.h"

 // ---------------------------------------------------------------------------
 // Sound pattern definitions
 // ---------------------------------------------------------------------------
enum BuzzerPattern : uint8_t {
    BUZZ_SILENT = 0,   // No sound
    BUZZ_BUTTON = 1,   // Short beep (button press)
    BUZZ_CONFIRM = 2,   // Double beep (confirmation)
    BUZZ_CONNECTING = 3,   // Single medium beep (entering CONNECTING)
    BUZZ_READY = 4,   // Two short beeps (connected, ready)
    BUZZ_OPERATING = 5,   // Single short high beep (joystick active)
    BUZZ_ERROR = 6,   // Rapid beeps (error state)
    BUZZ_WARNING = 7,   // Three medium beeps (warning)
    BUZZ_POWER_ON = 8,   // Rising tone pattern (power on)
    BUZZ_POWER_OFF = 9,   // Falling tone pattern (power off)
};

// ---------------------------------------------------------------------------
// Pattern timing structures (on-off sequences in milliseconds)
// ---------------------------------------------------------------------------
struct BuzzerSequence {
    uint16_t onDuration;    // Buzzer ON time (ms)
    uint16_t offDuration;   // Buzzer OFF time (ms)
};

// Maximum pattern steps (adjust if more complex patterns needed)
#define MAX_PATTERN_STEPS 8

struct BuzzerPatternDef {
    uint8_t          stepCount;
    BuzzerSequence   steps[MAX_PATTERN_STEPS];
};

// Pattern definitions
static const BuzzerPatternDef PATTERNS[] = {
    // BUZZ_SILENT
    { 0, {} },

    // BUZZ_BUTTON - short beep (50 ms)
    { 1, { {50, 0} } },

    // BUZZ_CONFIRM - double beep (50 ms on, 80 ms off, 50 ms on)
    { 2, { {50, 80}, {50, 0} } },

    // BUZZ_CONNECTING - single medium beep (150 ms)
    { 1, { {150, 0} } },

    // BUZZ_READY - two short beeps (60 ms on, 80 ms off, 60 ms on)
    { 2, { {60, 80}, {60, 0} } },

    // BUZZ_OPERATING - single short beep (40 ms)
    { 1, { {40, 0} } },

    // BUZZ_ERROR - rapid beeps (100 ms on/off, 3 times)
    { 3, { {100, 100}, {100, 100}, {100, 0} } },

    // BUZZ_WARNING - three medium beeps (80 ms on, 120 ms off, repeat)
    { 3, { {80, 120}, {80, 120}, {80, 0} } },

    // BUZZ_POWER_ON - rising pattern (50, 100, 150 ms with gaps)
    { 3, { {50, 60}, {100, 60}, {150, 0} } },

    // BUZZ_POWER_OFF - falling pattern (150, 100, 50 ms with gaps)
    { 3, { {150, 60}, {100, 60}, {50, 0} } },
};

// ---------------------------------------------------------------------------
// State variables
// ---------------------------------------------------------------------------
static bool     _buzzerActive = false;  // Currently playing a pattern
static uint8_t  _currentPattern = BUZZ_SILENT;
static uint8_t  _currentStep = 0;
static uint32_t _stepStartMs = 0;
static bool     _buzzerOn = false;  // Current output state
static uint8_t  _buzzerPin = BUZZER_PIN;
#ifdef BUZZER_ACTIVE
static bool     _buzzerPassive = false;
#else
static bool     _buzzerPassive = true;
#endif
static bool     _buzzerReady = false;  // pin attached; writes are skipped otherwise

#define BUZZER_TONE_RES  10
#define BUZZER_TONE_DUTY 512   // 50 % at 10 bit

// Only before buzzerInit(); pinmap.h applies NVS overrides here.
inline void buzzerConfigure(uint8_t pin, bool passive) {
    _buzzerPin = pin;
    _buzzerPassive = passive;
}
inline uint8_t buzzerPin()       { return _buzzerPin; }
inline bool    buzzerIsPassive() { return _buzzerPassive; }

static void _buzzerOutput(bool on) {
    if (!_buzzerReady) return;
    if (_buzzerPassive) ledcWrite(_buzzerPin, on ? BUZZER_TONE_DUTY : 0);
    else                digitalWrite(_buzzerPin, on ? HIGH : LOW);
}

// ---------------------------------------------------------------------------
// buzzerInit() - Initialize buzzer GPIO
// ---------------------------------------------------------------------------
void buzzerInit() {
    if (_buzzerPassive) {
        _buzzerReady = ledcAttach(_buzzerPin, BUZZER_TONE_HZ, BUZZER_TONE_RES);
        if (!_buzzerReady) LOG_ERROR(TAG_BUZZER, "LEDC attach failed on GPIO %d", _buzzerPin);
    }
    else {
        pinMode(_buzzerPin, OUTPUT);
        _buzzerReady = true;
    }
    _buzzerActive = false;
    _currentPattern = BUZZ_SILENT;
    _currentStep = 0;
    _buzzerOn = false;
    _buzzerOutput(false);
    LOG_INFO(TAG_BUZZER, "Initialized on GPIO %d (%s)", _buzzerPin,
        _buzzerPassive ? "passive, tone" : "active, on/off");
}

// Releases the pin (pinmap wizard tests other pins meanwhile); buzzerInit() restores.
void buzzerDeinit() {
    _buzzerOutput(false);
    _buzzerActive = false;
    _buzzerOn = false;
    if (_buzzerReady) {
        if (_buzzerPassive) ledcDetach(_buzzerPin);
        pinMode(_buzzerPin, INPUT);
    }
    _buzzerReady = false;
}

// ---------------------------------------------------------------------------
// buzzerPlay() - Start playing a pattern
// Call this to trigger a sound. Play is non-blocking; buzzerTick() advances.
// ---------------------------------------------------------------------------
void buzzerPlay(BuzzerPattern pattern) {
    if (pattern >= sizeof(PATTERNS) / sizeof(PATTERNS[0])) {
        LOG_WARN(TAG_BUZZER, "Invalid pattern %d", pattern);
        return;
    }

    _currentPattern = pattern;
    _currentStep = 0;
    _stepStartMs = millis();
    _buzzerActive = (PATTERNS[pattern].stepCount > 0);

    if (_buzzerActive) {
        // Start first step immediately
        _buzzerOutput(true);
        _buzzerOn = true;
    }
}

// ---------------------------------------------------------------------------
// buzzerStop() - Immediately stop current pattern
// ---------------------------------------------------------------------------
void buzzerStop() {
    _buzzerOutput(false);
    _buzzerActive = false;
    _buzzerOn = false;
}

// ---------------------------------------------------------------------------
// buzzerTick() - Advance pattern playback (call from main loop)
// ---------------------------------------------------------------------------
void buzzerTick() {
    if (!_buzzerActive) return;

    uint32_t now = millis();
    const BuzzerPatternDef& pattern = PATTERNS[_currentPattern];

    if (_currentStep >= pattern.stepCount) {
        // Pattern complete
        _buzzerOutput(false);
        _buzzerActive = false;
        _buzzerOn = false;
        return;
    }

    const BuzzerSequence& step = pattern.steps[_currentStep];
    uint32_t elapsed = now - _stepStartMs;

    if (_buzzerOn) {
        // Currently in ON phase
        if (elapsed >= step.onDuration) {
            _buzzerOutput(false);
            _buzzerOn = false;
            _stepStartMs = now;

            // If no OFF duration, advance to next step immediately
            if (step.offDuration == 0) {
                _currentStep++;
                if (_currentStep < pattern.stepCount) {
                    _buzzerOutput(true);
                    _buzzerOn = true;
                    _stepStartMs = now;
                }
            }
        }
    }
    else {
        // Currently in OFF phase
        if (elapsed >= step.offDuration) {
            _currentStep++;
            if (_currentStep < pattern.stepCount) {
                _buzzerOutput(true);
                _buzzerOn = true;
                _stepStartMs = now;
            }
        }
    }
}

// ---------------------------------------------------------------------------
// buzzerIsActive() - Check if a pattern is currently playing
// ---------------------------------------------------------------------------
bool buzzerIsActive() {
    return _buzzerActive;
}

#endif // BUZZER_H
