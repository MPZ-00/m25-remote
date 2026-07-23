---
type: community
members: 8
---

# Supervisor Command Send Loop

**Members:** 8 nodes

## Members
- [[CommandFrame_2]] - code
- [[ControlState_1]] - code
- [[bleGetLastNotifyMs()]] - code - m25_ble.cpp
- [[bleLastMotorWriteOk()]] - code - m25_ble.cpp
- [[checkWatchdogs]] - code - supervisor.h
- [[processInput]] - code - supervisor.h
- [[sendCommand]] - code - supervisor.h
- [[sendHeartbeat]] - code - supervisor.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Supervisor_Command_Send_Loop
SORT file.name ASC
```

## Connections to other communities
- 7 edges to [[_COMMUNITY_Supervisor Watchdog Handlers]]
- 4 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 4 edges to [[_COMMUNITY_Safety Supervisor State]]
- 2 edges to [[_COMMUNITY_Supervisor Arm Transitions]]
- 1 edge to [[_COMMUNITY_Wheel Mode and Connect Handling]]
- 1 edge to [[_COMMUNITY_Failsafe and Vehicle State]]

## Top bridge nodes
- [[checkWatchdogs]] - degree 10, connects to 6 communities
- [[processInput]] - degree 6, connects to 3 communities
- [[sendCommand]] - degree 6, connects to 3 communities
- [[sendHeartbeat]] - degree 5, connects to 2 communities
- [[bleLastMotorWriteOk()]] - degree 2, connects to 1 community