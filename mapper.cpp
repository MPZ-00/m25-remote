/*
 * mapper.cpp - Safety-critical control input transformation
 *
 * Implementation of the Mapper class that transforms raw control inputs
 * into safe vehicle commands.
 *
 * Reference: core/mapper.py (Python implementation)
 */

#include "mapper.h"

bool Mapper::map(const ControlState &state, CommandFrame &outCommand)
{
    uint32_t currentTime = millis();

    // SAFETY RULE 1: Deadman switch must be pressed
    if (!state.deadman)
    {
        _lastCommand = CommandFrame::stop();
        _lastTime = currentTime;
        _hasLastCommand = true;
        outCommand = _lastCommand;
        return true; // Valid command (stop)
    }

    // SAFETY RULE 2: STOP mode = no movement
    if (state.mode == DRIVE_MODE_STOP)
    {
        _lastCommand = CommandFrame::stop();
        _lastTime = currentTime;
        _hasLastCommand = true;
        outCommand = _lastCommand;
        return true; // Valid command (stop)
    }

    // Apply processing pipeline
    float vx = applyDeadzone(state.vx);
    float vy = applyDeadzone(state.vy);

    vx = applyCurve(vx);
    vy = applyCurve(vy);

    // Convert to differential drive
    float left, right;
    differentialDrive(vx, vy, left, right);

    // Apply mode-specific speed limit
    int maxSpeed = _config.getMaxSpeed(state.mode);

    // SAFETY: low wheel battery caps speed in every mode (graceful degradation
    // instead of the wheel cutting out under load)
    if (_lowBatteryLimit && maxSpeed > _config.maxSpeedLowBattery)
    {
        maxSpeed = _config.maxSpeedLowBattery;
    }
    left = left * maxSpeed; // Scale to actual speed values
    right = right * maxSpeed;
    left = clamp(left, -maxSpeed, maxSpeed);
    right = clamp(right, -maxSpeed, maxSpeed);

    // SAFETY: cap reverse speed to a fraction of the forward maximum
    // (device_config.h VMAX_REVERSE_RATIO). This also bounds the reversing
    // wheel during in-place turns. reverseRatio >= 1.0 disables the cap.
    if (_config.reverseRatio < 1.0f)
    {
        float reverseMax = maxSpeed * _config.reverseRatio;
        if (left < -reverseMax)
            left = -reverseMax;
        if (right < -reverseMax)
            right = -reverseMax;
    }

    // Apply ramping if we have previous command
    if (_config.rampRate > 0.0f && _hasLastCommand && _lastTime > 0)
    {
        float dt = (currentTime - _lastTime) / 1000.0f; // Convert to seconds
        if (dt > 0.0f && dt < 1.0f)
        { // Sanity check (prevent huge jumps on overflow)
            left = applyRamp(left, _lastCommand.leftSpeed, dt);
            right = applyRamp(right, _lastCommand.rightSpeed, dt);
        }
    }

    // Build command frame
    CommandFrame frame;
    frame.leftSpeed = (int)roundf(left);
    frame.rightSpeed = (int)roundf(right);
    frame.flags = buildFlags(state);
    frame.timestamp = currentTime;

    // Final safety clamp (redundant but critical)
    frame.leftSpeed = constrain(frame.leftSpeed, -100, 100);
    frame.rightSpeed = constrain(frame.rightSpeed, -100, 100);

    _lastCommand = frame;
    _lastTime = currentTime;
    _hasLastCommand = true;

    outCommand = frame;
    return true;
}

void Mapper::reset()
{
    _lastCommand = CommandFrame::stop();
    _lastTime = 0;
    _hasLastCommand = false;
}

float Mapper::applyDeadzone(float value)
{
    if (fabsf(value) < _config.deadzone)
    {
        return 0.0f;
    }

    // Rescale so deadzone maps to 0, and 1.0 stays 1.0
    float sign = (value > 0) ? 1.0f : -1.0f;
    float magnitude = fabsf(value);
    float scaled = (magnitude - _config.deadzone) / (1.0f - _config.deadzone);
    return sign * scaled;
}

float Mapper::applyCurve(float value)
{
    if (value == 0.0f)
    {
        return 0.0f;
    }

    float sign = (value > 0) ? 1.0f : -1.0f;
    float magnitude = fabsf(value);
    float curved = powf(magnitude, _config.curve);
    return sign * curved;
}

void Mapper::differentialDrive(float vx, float vy, float &outLeft, float &outRight)
{
    // Standard differential drive kinematics:
    // - vx (forward) adds equally to both wheels
    // - vy (turn) adds to one wheel, subtracts from other
    //
    // Basic differential drive: left = vx - vy, right = vx + vy
    // But we need to handle magnitude > 1.0

    // Turn reduction: the inner wheel's turn contribution is scaled by
    // (1 - turnReduction) instead of applying vy at full strength. At vy=+-1
    // this leaves the inner wheel at outer*(1-turnReduction) rather than
    // spinning it to full opposite speed. The outer wheel is unaffected.
    float leftTurn  = (vy >= 0.0f) ? vy * (1.0f - _config.turnReduction) : vy;
    float rightTurn = (vy <  0.0f) ? vy * (1.0f - _config.turnReduction) : vy;

    float left = vx - leftTurn;
    float right = vx + rightTurn;

    // Normalize if magnitude exceeds 1.0
    float maxMagnitude = max(fabsf(left), fabsf(right));
    if (maxMagnitude > 1.0f)
    {
        left /= maxMagnitude;
        right /= maxMagnitude;
    }

    outLeft = left;
    outRight = right;
}

float Mapper::clamp(float value, float minVal, float maxVal)
{
    if (value < minVal)
        return minVal;
    if (value > maxVal)
        return maxVal;
    return value;
}

float Mapper::applyRamp(float target, float current, float dt)
{
    float maxChange = _config.rampRate * dt;
    float delta = target - current;

    if (fabsf(delta) <= maxChange)
    {
        return target;
    }

    // Limit change to maxChange
    float sign = (delta > 0) ? 1.0f : -1.0f;
    return current + sign * maxChange;
}

uint8_t Mapper::buildFlags(const ControlState &state)
{
    uint8_t flags = 0;

    // Encode drive mode in lower bits
    flags |= (state.mode & 0x0F);

    return flags;
}