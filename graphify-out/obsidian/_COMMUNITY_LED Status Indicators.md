---
type: community
members: 14
---

# LED Status Indicators

**Members:** 14 nodes

## Members
- [[LedMode]] - code
- [[LedState]] - code
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
- [[ledUpdateBle()]] - code - led_control.h
- [[led_control.h]] - code - led_control.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/LED_Status_Indicators
SORT file.name ASC
```

## Connections to other communities
- 2 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 2 edges to [[_COMMUNITY_BLE Diagnostics and Tx Stats]]
- 1 edge to [[_COMMUNITY_Button Input Handling]]
- 1 edge to [[_COMMUNITY_Serial Command Output Helpers]]

## Top bridge nodes
- [[led_control.h]] - degree 14, connects to 3 communities
- [[_ledUpdate()]] - degree 4, connects to 1 community
- [[ledSetHillHold()]] - degree 3, connects to 1 community
- [[ledSetAssistLevel()]] - degree 3, connects to 1 community