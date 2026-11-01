/*
 * button.h - Debounced push-button driver
 *
 * Buttons are momentary switches between a GPIO and GND with INPUT_PULLUP.
 * Normally-open buttons read LOW when pressed (default). A normally-closed
 * switch reads HIGH when pressed: set activeHigh (pinmap does this).
 * Pins can be remapped at runtime from NVS (see pinmap.h) before buttonsInit().
 *
 * The driver exposes "wasPressed()" which returns true exactly once per
 * physical button press (falling-edge detection after debounce window).
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>
#include "device_config.h"
#include "Logger.h"

 // ---------------------------------------------------------------------------
 // Single-button state machine
 // ---------------------------------------------------------------------------
struct Button {
    uint8_t  pin;
    bool     lastStableState;  // true = released (HIGH)
    bool     currentReading;
    uint32_t readingChangeTime;
    bool     pressedEvent;     // consumed by wasPressed()
    uint32_t pressStartMs;
    bool     holdConsumed;     // long-press fired or press cancelled: no short-release event
    bool     shortReleaseEvent; // consumed by wasShortReleased()
    bool     activeHigh;       // pressed level is HIGH (normally-closed switch)

    bool readReleased() const { return (digitalRead(pin) == HIGH) != activeHigh; }

    // Call once in setup()
    void init() {
        pinMode(pin, INPUT_PULLUP);
        delay(10);  // Allow pull-up to settle

        // Read actual initial state instead of assuming released
        bool initialState = readReleased();
        lastStableState = initialState;
        currentReading = initialState;
        readingChangeTime = 0;
        pressedEvent = false;
        pressStartMs = 0;
        holdConsumed = !initialState;  // held at boot: its release is not a press
        shortReleaseEvent = false;
    }

    // Call every loop iteration; updates internal state
    void tick() {
        bool reading = readReleased();
        uint32_t now = millis();

        if (reading != currentReading) {
            // Input changed - restart debounce window
            currentReading = reading;
            readingChangeTime = now;
        }

        if ((now - readingChangeTime) >= DEBOUNCE_MS) {
            // Stable long enough - check for press event
            if (currentReading != lastStableState) {
                lastStableState = currentReading;
                if (!lastStableState) {
                    // Transitioned to LOW (pressed)
                    pressedEvent = true;
                    pressStartMs = now;
                    holdConsumed = false;
                }
                else if (!holdConsumed) {
                    shortReleaseEvent = true;
                }
            }
        }
    }

    // Returns true once per button press; clears the flag
    bool wasPressed() {
        if (pressedEvent) {
            pressedEvent = false;
            return true;
        }
        return false;
    }

    bool wasShortReleased() {
        if (shortReleaseEvent) {
            shortReleaseEvent = false;
            return true;
        }
        return false;
    }

    // True once per press; the following release is then not a short press
    bool wasHeldFor(uint32_t holdMs) {
        if (isHeld() && !holdConsumed && (millis() - pressStartMs) >= holdMs) {
            holdConsumed = true;
            return true;
        }
        return false;
    }

    // For button combos: the press must not also fire its single action
    void cancelPress() {
        holdConsumed = true;
        shortReleaseEvent = false;
    }

    // Current debounced state: true = button is being held down
    bool isHeld() const {
        return !lastStableState;
    }
};

// ---------------------------------------------------------------------------
// Button instances - defined once in remote_control.ino, declared extern here.
// Keeping them extern prevents an ODR (multiple-definition) linker error if
// this header is ever included from more than one translation unit.
// ---------------------------------------------------------------------------
extern Button btnEstop;
extern Button btnHillHold;
extern Button btnAssist;
extern Button btnPower;

// ---------------------------------------------------------------------------
// Convenience functions
// ---------------------------------------------------------------------------
inline void buttonsInit() {
    btnEstop.init();
    btnHillHold.init();
    btnAssist.init();
    btnPower.init();

    // Diagnostic: all buttons "pressed" at boot is almost always a wiring problem
    delay(50);  // Extra settle time
    if (!btnEstop.readReleased() && !btnHillHold.readReleased()
        && !btnAssist.readReleased() && !btnPower.readReleased()) {
        LOG_WARN(TAG_BUTTON, "All buttons read pressed at startup - check wiring");
        LOG_WARN(TAG_BUTTON, "- Pins E-stop=%u Hill=%u Assist=%u Power=%u, other terminal to GND",
            btnEstop.pin, btnHillHold.pin, btnAssist.pin, btnPower.pin);
        LOG_WARN(TAG_BUTTON, "- Normally-closed switch? map it with 'pinmap btn <name> <gpio> nc'");
        LOG_WARN(TAG_BUTTON, "- Check for shorts to GND on breadboard");
    }
}

inline void buttonsTick() {
    btnEstop.tick();
    btnHillHold.tick();
    btnAssist.tick();
    btnPower.tick();
}

// Debug: print raw button pin states (call from serial command)
inline void buttonsPrintDebug() {
    LOG_INFO(TAG_BUTTON, "RAW pins: E-Stop(%u)=%d%s HillHold(%u)=%d%s Assist(%u)=%d%s Power(%u)=%d%s",
        btnEstop.pin, digitalRead(btnEstop.pin), btnEstop.activeHigh ? " NC" : "",
        btnHillHold.pin, digitalRead(btnHillHold.pin), btnHillHold.activeHigh ? " NC" : "",
        btnAssist.pin, digitalRead(btnAssist.pin), btnAssist.activeHigh ? " NC" : "",
        btnPower.pin, digitalRead(btnPower.pin), btnPower.activeHigh ? " NC" : "");
    LOG_INFO(TAG_BUTTON, "Debounced: E-Stop=%s HillHold=%s Assist=%s Power=%s",
        btnEstop.isHeld() ? "HELD" : "released",
        btnHillHold.isHeld() ? "HELD" : "released",
        btnAssist.isHeld() ? "HELD" : "released",
        btnPower.isHeld() ? "HELD" : "released");
}

#endif // BUTTON_H
