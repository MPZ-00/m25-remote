---
type: community
members: 48
---

# Buttons & Buzzer Input

**Members:** 48 nodes

## Members
- [[ADC constraint joystick must use ADC1 pins (GPIO 32-39)]] - document - CLAUDE.md
- [[AssistConfig table (IndoorOutdoorLearning Vmax)]] - code - motor_control.h
- [[BuzzerPattern]] - code - buzzer.h
- [[JoystickNorm]] - code - joystick.h
- [[JoystickNorm_1]] - code - motor_control.h
- [[JoystickRaw]] - code - joystick.h
- [[LogLevel]] - code - Logger.cpp
- [[Logger.cpp]] - code - Logger.cpp
- [[MotorCommand]] - code - motor_control.h
- [[NO_JOYSTICK stub ADC disabled, joystick always centered for bench testing]] - rationale - joystick.h
- [[begin()]] - code - Logger.cpp
- [[button.h]] - code - button.h
- [[buttonsInit()]] - code - button.h
- [[buttonsPrintDebug()]] - code - button.h
- [[buttonsTick()]] - code - button.h
- [[buzzer.h_1]] - code - buzzer.h
- [[buzzerInit()]] - code - buzzer.h
- [[buzzerIsActive()]] - code - buzzer.h
- [[buzzerPlay()]] - code - buzzer.h
- [[buzzerStop()]] - code - buzzer.h
- [[buzzerTick()]] - code - buzzer.h
- [[calculateMotorCommand()]] - code - motor_control.h
- [[device_config.h_1]] - code - device_config.h
- [[filename()]] - code - Logger.cpp
- [[joystick.h]] - code - joystick.h
- [[joystickApplyFullRangeCalibration()]] - code - joystick.h
- [[joystickDirectionLabel()]] - code - joystick.h
- [[joystickInit()]] - code - joystick.h
- [[joystickNormalizeAxis()]] - code - joystick.h
- [[joystickRead()]] - code - joystick.h
- [[joystickReadRaw()]] - code - joystick.h
- [[joystickReadRawAxis()]] - code - joystick.h
- [[joystickSampleAxisMax()]] - code - joystick.h
- [[joystickSampleAxisMin()]] - code - joystick.h
- [[joystickToMotorCommand()]] - code - motor_control.h
- [[levelString()]] - code - Logger.cpp
- [[loadFromNVS()]] - code - Logger.cpp
- [[log()]] - code - Logger.cpp
- [[logForced()]] - code - Logger.cpp
- [[motor_control.h]] - code - motor_control.h
- [[printMotorCommand()]] - code - motor_control.h
- [[saveToNVS()]] - code - Logger.cpp
- [[setLevel()]] - code - Logger.cpp
- [[setTagEnabled()]] - code - Logger.cpp
- [[setTagMask()]] - code - Logger.cpp
- [[tagString()]] - code - Logger.cpp
- [[tick()]] - code - button.h
- [[wasPressed()]] - code - button.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Buttons__Buzzer_Input
SORT file.name ASC
```

## Connections to other communities
- 15 edges to [[_COMMUNITY_Configuration Priority & Feature Flags]]
- 3 edges to [[_COMMUNITY_BLE Threading & Connection State]]
- 2 edges to [[_COMMUNITY_Mapper & Supervisor Safety Pipeline]]
- 1 edge to [[_COMMUNITY_BLE Motor Command Task]]
- 1 edge to [[_COMMUNITY_LED & Buzzer Pattern Control]]
- 1 edge to [[_COMMUNITY_BLE Client Callbacks & Parsing]]

## Top bridge nodes
- [[logForced()]] - degree 14, connects to 3 communities
- [[device_config.h_1]] - degree 8, connects to 3 communities
- [[log()]] - degree 11, connects to 2 communities
- [[joystick.h]] - degree 13, connects to 1 community
- [[motor_control.h]] - degree 6, connects to 1 community