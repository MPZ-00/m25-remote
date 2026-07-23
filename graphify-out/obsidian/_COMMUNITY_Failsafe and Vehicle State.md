---
type: community
members: 7
---

# Failsafe and Vehicle State

**Members:** 7 nodes

## Members
- [[VehicleState]] - code
- [[bleAnyConnected()]] - code - m25_ble.cpp
- [[enterFailsafe]] - code - supervisor.h
- [[isConnected]] - code - supervisor.h
- [[notifyConnectionChange]] - code - supervisor.h
- [[requestEmergencyStop]] - code - supervisor.h
- [[updateVehicleState]] - code - supervisor.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Failsafe_and_Vehicle_State
SORT file.name ASC
```

## Connections to other communities
- 8 edges to [[_COMMUNITY_Supervisor Watchdog Handlers]]
- 5 edges to [[_COMMUNITY_Safety Supervisor State]]
- 2 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 2 edges to [[_COMMUNITY_Wheel Mode and Connect Handling]]
- 2 edges to [[_COMMUNITY_Supervisor Arm Transitions]]
- 1 edge to [[_COMMUNITY_BLE Diagnostics and Tx Stats]]
- 1 edge to [[_COMMUNITY_Serial Command Output Helpers]]
- 1 edge to [[_COMMUNITY_Supervisor Command Send Loop]]

## Top bridge nodes
- [[bleAnyConnected()]] - degree 12, connects to 6 communities
- [[enterFailsafe]] - degree 9, connects to 4 communities
- [[updateVehicleState]] - degree 4, connects to 2 communities
- [[notifyConnectionChange]] - degree 4, connects to 2 communities
- [[requestEmergencyStop]] - degree 3, connects to 2 communities