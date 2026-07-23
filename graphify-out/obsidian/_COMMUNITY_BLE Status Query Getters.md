---
type: community
members: 9
---

# BLE Status Query Getters

**Members:** 9 nodes

## Members
- [[.getTagMask()]] - code - Logger.h
- [[SupervisorState_2]] - code
- [[_scPrintStatus()]] - code - serial_commands.h
- [[bleGetAutoReconnect()]] - code - m25_ble.cpp
- [[bleGetFirmwareVersion()]] - code - m25_ble.cpp
- [[bleGetMac()]] - code - m25_ble.cpp
- [[bleRecordEntryCount()]] - code - m25_ble.cpp
- [[bleRecordIsActive()]] - code - m25_ble.cpp
- [[supervisorStateToString()]] - code - types.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_Status_Query_Getters
SORT file.name ASC
```

## Connections to other communities
- 8 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 6 edges to [[_COMMUNITY_Serial Command Output Helpers]]
- 5 edges to [[_COMMUNITY_BLE Diagnostics and Tx Stats]]
- 3 edges to [[_COMMUNITY_Bluedroid GAP and Logger]]
- 1 edge to [[_COMMUNITY_Serial Profile Commands]]
- 1 edge to [[_COMMUNITY_Supervisor Arm Transitions]]
- 1 edge to [[_COMMUNITY_Joystick to Command Mapper]]

## Top bridge nodes
- [[_scPrintStatus()]] - degree 18, connects to 5 communities
- [[supervisorStateToString()]] - degree 5, connects to 3 communities
- [[.getTagMask()]] - degree 3, connects to 2 communities
- [[bleRecordIsActive()]] - degree 3, connects to 2 communities
- [[bleRecordEntryCount()]] - degree 3, connects to 2 communities