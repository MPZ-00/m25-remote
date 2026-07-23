---
type: community
members: 22
---

# Button Input Handling

**Members:** 22 nodes

## Members
- [[BuzzerPattern]] - code
- [[JoystickNorm]] - code - joystick.h
- [[MotorCommand]] - code
- [[button.h]] - code - button.h
- [[buttonsInit()]] - code - button.h
- [[buttonsPrintDebug()]] - code - button.h
- [[buttonsTick()]] - code - button.h
- [[buzzer.h]] - code - buzzer.h
- [[buzzerInit()]] - code - buzzer.h
- [[buzzerIsActive()]] - code - buzzer.h
- [[buzzerPlay()]] - code - buzzer.h
- [[buzzerStop()]] - code - buzzer.h
- [[calculateMotorCommand()]] - code - motor_control.h
- [[device_config.h]] - code - device_config.h
- [[inDeadzone]] - code - joystick.h
- [[joystickToMotorCommand()]] - code - motor_control.h
- [[motor_control.h]] - code - motor_control.h
- [[printMotorCommand()]] - code - motor_control.h
- [[tick()]] - code - button.h
- [[wasPressed()]] - code - button.h
- [[x_2]] - code - joystick.h
- [[y_2]] - code - joystick.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Button_Input_Handling
SORT file.name ASC
```

## Connections to other communities
- 4 edges to [[_COMMUNITY_Joystick ADC Input]]
- 3 edges to [[_COMMUNITY_Bluedroid GAP and Logger]]
- 2 edges to [[_COMMUNITY_BLE Diagnostics and Tx Stats]]
- 2 edges to [[_COMMUNITY_Serial Command Output Helpers]]
- 1 edge to [[_COMMUNITY_BLE GATT Client Core]]
- 1 edge to [[_COMMUNITY_LED Status Indicators]]
- 1 edge to [[_COMMUNITY_M25 BLE Response Parsing]]

## Top bridge nodes
- [[device_config.h]] - degree 8, connects to 5 communities
- [[motor_control.h]] - degree 7, connects to 3 communities
- [[buzzer.h]] - degree 7, connects to 2 communities
- [[button.h]] - degree 7, connects to 1 community
- [[JoystickNorm]] - degree 6, connects to 1 community