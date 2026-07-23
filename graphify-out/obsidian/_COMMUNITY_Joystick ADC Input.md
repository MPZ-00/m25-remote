---
type: community
members: 14
---

# Joystick ADC Input

**Members:** 14 nodes

## Members
- [[JoystickRaw]] - code - joystick.h
- [[_scPrintJs()]] - code - serial_commands.h
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
- [[x_1]] - code - joystick.h
- [[y_1]] - code - joystick.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Joystick_ADC_Input
SORT file.name ASC
```

## Connections to other communities
- 4 edges to [[_COMMUNITY_Button Input Handling]]
- 4 edges to [[_COMMUNITY_Serial Command Output Helpers]]
- 4 edges to [[_COMMUNITY_BLE Diagnostics and Tx Stats]]
- 3 edges to [[_COMMUNITY_Bluedroid GAP and Logger]]
- 1 edge to [[_COMMUNITY_Joystick Calibration Persistence]]

## Top bridge nodes
- [[joystick.h]] - degree 16, connects to 4 communities
- [[_scPrintJs()]] - degree 7, connects to 2 communities
- [[joystickApplyFullRangeCalibration()]] - degree 3, connects to 2 communities
- [[joystickRead()]] - degree 4, connects to 1 community
- [[joystickSampleAxisMax()]] - degree 3, connects to 1 community