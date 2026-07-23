---
type: community
members: 20
---

# Supervisor Watchdog Handlers

**Members:** 20 nodes

## Members
- [[_sConnectTask]] - code - supervisor.h
- [[_triggerPartialReconnect]] - code - supervisor.h
- [[begin_1]] - code - supervisor.h
- [[getArmedIdleRemainingMs]] - code - supervisor.h
- [[getTimeSinceLastInput]] - code - supervisor.h
- [[getTimeSinceLastLink]] - code - supervisor.h
- [[handleArmed]] - code - supervisor.h
- [[handleDisconnected]] - code - supervisor.h
- [[handleDriving]] - code - supervisor.h
- [[handleFailsafe]] - code - supervisor.h
- [[handlePaired]] - code - supervisor.h
- [[handleStopRequest]] - code - supervisor.h
- [[isInputTimeout]] - code - supervisor.h
- [[isLinkTimeout]] - code - supervisor.h
- [[requestDisarm]] - code - supervisor.h
- [[requestDisconnect]] - code - supervisor.h
- [[requestReconnect]] - code - supervisor.h
- [[sendStop]] - code - supervisor.h
- [[supervisor.cpp]] - code - supervisor.cpp
- [[update]] - code - supervisor.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Supervisor_Watchdog_Handlers
SORT file.name ASC
```

## Connections to other communities
- 19 edges to [[_COMMUNITY_Safety Supervisor State]]
- 8 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 8 edges to [[_COMMUNITY_Failsafe and Vehicle State]]
- 7 edges to [[_COMMUNITY_Supervisor Command Send Loop]]
- 7 edges to [[_COMMUNITY_Supervisor Arm Transitions]]
- 6 edges to [[_COMMUNITY_Wheel Mode and Connect Handling]]
- 2 edges to [[_COMMUNITY_Joystick to Command Mapper]]
- 1 edge to [[_COMMUNITY_Bluedroid GAP and Logger]]
- 1 edge to [[_COMMUNITY_M25 BLE Response Parsing]]
- 1 edge to [[_COMMUNITY_State Callback Registration]]

## Top bridge nodes
- [[supervisor.cpp]] - degree 41, connects to 9 communities
- [[sendStop]] - degree 11, connects to 4 communities
- [[handlePaired]] - degree 8, connects to 4 communities
- [[handleArmed]] - degree 8, connects to 4 communities
- [[update]] - degree 10, connects to 3 communities