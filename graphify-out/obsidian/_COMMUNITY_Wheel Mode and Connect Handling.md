---
type: community
members: 6
---

# Wheel Mode and Connect Handling

**Members:** 6 nodes

## Members
- [[_wheelActive()]] - code - m25_ble.cpp
- [[applyRuntimeWheelConfig]] - code - supervisor.h
- [[bleAllConnected()]] - code - m25_ble.cpp
- [[bleResetNotifyTimers()]] - code - m25_ble.cpp
- [[bleSetKey()]] - code - m25_ble.cpp
- [[handleConnecting]] - code - supervisor.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Wheel_Mode_and_Connect_Handling
SORT file.name ASC
```

## Connections to other communities
- 17 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 6 edges to [[_COMMUNITY_Supervisor Watchdog Handlers]]
- 2 edges to [[_COMMUNITY_Failsafe and Vehicle State]]
- 2 edges to [[_COMMUNITY_BLE Diagnostics and Tx Stats]]
- 2 edges to [[_COMMUNITY_Supervisor Arm Transitions]]
- 2 edges to [[_COMMUNITY_Safety Supervisor State]]
- 1 edge to [[_COMMUNITY_BLE Client Disconnect Callbacks]]
- 1 edge to [[_COMMUNITY_Supervisor Command Send Loop]]
- 1 edge to [[_COMMUNITY_Serial Command Output Helpers]]
- 1 edge to [[_COMMUNITY_Serial Profile Commands]]

## Top bridge nodes
- [[_wheelActive()]] - degree 20, connects to 6 communities
- [[handleConnecting]] - degree 11, connects to 5 communities
- [[bleSetKey()]] - degree 5, connects to 3 communities
- [[applyRuntimeWheelConfig]] - degree 5, connects to 3 communities
- [[bleAllConnected()]] - degree 5, connects to 2 communities