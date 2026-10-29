/*
 * test_arm_gesture.ino - Unit tests for the stick arm gesture
 *
 * Feeds synthetic stick samples with explicit timestamps into ArmGesture;
 * no joystick hardware needed.
 *
 * Upload this sketch to ESP32 for testing.
 * Open Serial Monitor at 115200 baud to see results.
 */

// Resolved in the merged build dir created by prepare_test.ps1 / run_tests.ps1
#include "arm_gesture.h"

static int testsPassed = 0;
static int testsFailed = 0;

#define ASSERT_EQ(expected, actual, msg) \
    if ((expected) == (actual)) { \
        Serial.printf("  [PASS] %s: expected=%d, actual=%d\n", msg, (int)(expected), (int)(actual)); \
        testsPassed++; \
    } else { \
        Serial.printf("  [FAIL] %s: expected=%d, actual=%d\n", msg, (int)(expected), (int)(actual)); \
        testsFailed++; \
    }

// Holds one stick position for durationMs in 20 ms steps (loop rate order of
// magnitude) and returns the most significant event seen.
static ArmGestureEvent hold(ArmGesture& g, uint32_t& t, float x, float y, uint32_t durationMs) {
    ArmGestureEvent best = ARM_GESTURE_NONE;
    const bool dz = (x == 0.0f && y == 0.0f);
    for (uint32_t el = 0; el <= durationMs; el += 20) {
        ArmGestureEvent ev = g.update(x, y, dz, t);
        if (ev > best) best = ev;
        t += 20;
    }
    return best;
}

void testFullGesture() {
    Serial.println("\n=== Test: Full gesture arms ===");
    ArmGesture g; uint32_t t = 1000;
    ASSERT_EQ(ARM_GESTURE_STEP, hold(g, t, 0.0f, 1.0f, ARM_GESTURE_FWD_HOLD_MS + 40), "Forward hold reports step");
    ASSERT_EQ(ARM_GESTURE_NONE, hold(g, t, 0.0f, 0.0f, 100), "Passing center is fine");
    ASSERT_EQ(ARM_GESTURE_NONE, hold(g, t, 0.0f, -1.0f, 200), "Short pull back");
    ASSERT_EQ(ARM_GESTURE_DONE, hold(g, t, 0.0f, 0.0f, 40), "Release to center completes");
}

void testShortForwardDoesNothing() {
    Serial.println("\n=== Test: Forward too short ===");
    ArmGesture g; uint32_t t = 1000;
    ASSERT_EQ(ARM_GESTURE_NONE, hold(g, t, 0.0f, 1.0f, ARM_GESTURE_FWD_HOLD_MS / 2), "No step");
    hold(g, t, 0.0f, 0.0f, 100);
    hold(g, t, 0.0f, -1.0f, 200);
    ASSERT_EQ(ARM_GESTURE_NONE, hold(g, t, 0.0f, 0.0f, 100), "No arm");
}

void testLongPullBackResets() {
    Serial.println("\n=== Test: Pull back too long ===");
    ArmGesture g; uint32_t t = 1000;
    hold(g, t, 0.0f, 1.0f, ARM_GESTURE_FWD_HOLD_MS + 40);
    hold(g, t, 0.0f, -1.0f, ARM_GESTURE_BACK_MAX_MS + 100);
    ASSERT_EQ(ARM_GESTURE_NONE, hold(g, t, 0.0f, 0.0f, 100), "No arm after long reverse hold");
}

void testGapTimeoutResets() {
    Serial.println("\n=== Test: Gap between steps too long ===");
    ArmGesture g; uint32_t t = 1000;
    hold(g, t, 0.0f, 1.0f, ARM_GESTURE_FWD_HOLD_MS + 40);
    hold(g, t, 0.0f, 0.0f, ARM_GESTURE_STEP_TIMEOUT_MS + 100);
    hold(g, t, 0.0f, -1.0f, 200);
    ASSERT_EQ(ARM_GESTURE_NONE, hold(g, t, 0.0f, 0.0f, 100), "No arm after pause");
}

void testSidewaysResets() {
    Serial.println("\n=== Test: Diagonal movement ===");
    ArmGesture g; uint32_t t = 1000;
    ASSERT_EQ(ARM_GESTURE_NONE, hold(g, t, 0.8f, 0.9f, ARM_GESTURE_FWD_HOLD_MS + 40), "Diagonal forward is not a step");
    ArmGesture g2; t = 1000;
    hold(g2, t, 0.0f, 1.0f, ARM_GESTURE_FWD_HOLD_MS + 40);
    hold(g2, t, 0.9f, -0.9f, 200);
    ASSERT_EQ(ARM_GESTURE_NONE, hold(g2, t, 0.0f, 0.0f, 100), "Diagonal pull back does not arm");
}

void testNoiseBlipResets() {
    Serial.println("\n=== Test: Reverse blip shorter than minimum ===");
    ArmGesture g; uint32_t t = 1000;
    hold(g, t, 0.0f, 1.0f, ARM_GESTURE_FWD_HOLD_MS + 40);
    g.update(0.0f, -1.0f, false, t); t += ARM_GESTURE_BACK_MIN_MS / 2;
    g.update(0.0f, 0.0f, true, t); t += 20;
    ASSERT_EQ(ARM_GESTURE_NONE, hold(g, t, 0.0f, 0.0f, 100), "Blip does not arm");
}

void setup() {
    Serial.begin(115200);
    delay(2000);

    Serial.println("\n=========================================");
    Serial.println("  Arm Gesture Unit Tests");
    Serial.println("=========================================\n");

    testFullGesture();
    testShortForwardDoesNothing();
    testLongPullBackResets();
    testGapTimeoutResets();
    testSidewaysResets();
    testNoiseBlipResets();

    Serial.println("\n=========================================");
    Serial.printf("  TESTS PASSED: %d\n", testsPassed);
    Serial.printf("  TESTS FAILED: %d\n", testsFailed);
    Serial.println("=========================================\n");

    if (testsFailed == 0) {
        Serial.println("  ALL TESTS PASSED!");
    } else {
        Serial.println("  SOME TESTS FAILED!");
    }
}

void loop() {
    delay(1000);
}
