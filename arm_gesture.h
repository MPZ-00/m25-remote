/*
 * arm_gesture.h - Stick gesture that arms the remote without a button
 *
 * Sequence (only evaluated while PAIRED):
 *   1. push forward and hold ARM_GESTURE_FWD_HOLD_MS  -> ARM_GESTURE_STEP
 *   2. short pull back (ARM_GESTURE_BACK_MIN_MS .. ARM_GESTURE_BACK_MAX_MS)
 *   3. release to center                               -> ARM_GESTURE_DONE
 * Any sideways deflection, overlong step or gap between steps resets it.
 */

#ifndef ARM_GESTURE_H
#define ARM_GESTURE_H

#include <stdint.h>
#include <math.h>
#include "device_config.h"

enum ArmGestureEvent : uint8_t {
    ARM_GESTURE_NONE = 0,
    ARM_GESTURE_STEP = 1,   // forward hold recognised, waiting for the pull back
    ARM_GESTURE_DONE = 2,
};

class ArmGesture {
public:
    void reset() { _phase = PH_IDLE; _sinceMs = 0; }

    ArmGestureEvent update(float x, float y, bool inDeadzone, uint32_t nowMs) {
        const bool onAxis = fabsf(x) <= ARM_GESTURE_OFF_AXIS_MAX;
        const bool fwd = onAxis && y >= ARM_GESTURE_THRESHOLD;
        const bool back = onAxis && y <= -ARM_GESTURE_THRESHOLD;

        switch (_phase) {
        case PH_IDLE:
            if (fwd) _enter(PH_FWD_HOLD, nowMs);
            break;

        case PH_FWD_HOLD:
            if (!fwd) {
                reset();
            }
            else if (nowMs - _sinceMs >= ARM_GESTURE_FWD_HOLD_MS) {
                _enter(PH_FWD_DONE, nowMs);
                return ARM_GESTURE_STEP;
            }
            break;

        case PH_FWD_DONE:
            // _sinceMs tracks the last moment the stick was still forward
            if (fwd) {
                _sinceMs = nowMs;
            }
            else if (back) {
                _enter(PH_BACK, nowMs);
            }
            else if (!onAxis || nowMs - _sinceMs > ARM_GESTURE_STEP_TIMEOUT_MS) {
                reset();
            }
            break;

        case PH_BACK:
            if (back) {
                if (nowMs - _sinceMs > ARM_GESTURE_BACK_MAX_MS) reset();
            }
            else if (nowMs - _sinceMs >= ARM_GESTURE_BACK_MIN_MS) {
                _enter(PH_WAIT_CENTER, nowMs);
            }
            else {
                reset();
            }
            break;

        case PH_WAIT_CENTER:
            if (inDeadzone) {
                reset();
                return ARM_GESTURE_DONE;
            }
            if (!onAxis || y >= ARM_GESTURE_THRESHOLD
                || nowMs - _sinceMs > ARM_GESTURE_STEP_TIMEOUT_MS) {
                reset();
            }
            break;
        }
        return ARM_GESTURE_NONE;
    }

private:
    enum Phase : uint8_t { PH_IDLE, PH_FWD_HOLD, PH_FWD_DONE, PH_BACK, PH_WAIT_CENTER };

    void _enter(Phase p, uint32_t nowMs) { _phase = p; _sinceMs = nowMs; }

    Phase    _phase = PH_IDLE;
    uint32_t _sinceMs = 0;
};

#endif // ARM_GESTURE_H
