---
type: community
members: 16
---

# LED & Buzzer Pattern Control

**Members:** 16 nodes

## Members
- [[BuzzerPatternDef  PATTERNS table]] - code - buzzer.h
- [[LedMode]] - code - led_control.h
- [[LedState]] - code - led_control.h
- [[_ledSetDuty()]] - code - led_control.h
- [[_ledSetMode()]] - code - led_control.h
- [[_ledUpdate()]] - code - led_control.h
- [[ledInit()]] - code - led_control.h
- [[ledSetAssistLevel()]] - code - led_control.h
- [[ledSetBattery()]] - code - led_control.h
- [[ledSetBleMode()]] - code - led_control.h
- [[ledSetHillHold()]] - code - led_control.h
- [[ledSetStatus()]] - code - led_control.h
- [[ledStartupTest()]] - code - led_control.h
- [[ledTick()]] - code - led_control.h
- [[ledUpdateBle()]] - code - led_control.h
- [[led_control.h_1]] - code - led_control.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/LED__Buzzer_Pattern_Control
SORT file.name ASC
```

## Connections to other communities
- 3 edges to [[_COMMUNITY_Configuration Priority & Feature Flags]]
- 1 edge to [[_COMMUNITY_Buttons & Buzzer Input]]

## Top bridge nodes
- [[led_control.h_1]] - degree 14, connects to 2 communities
- [[ledSetHillHold()]] - degree 3, connects to 1 community
- [[ledSetAssistLevel()]] - degree 3, connects to 1 community