---
type: community
members: 6
---

# Supervisor Arm Transitions

**Members:** 6 nodes

## Members
- [[SupervisorState]] - code
- [[bleResetMotorWriteOk()]] - code - m25_ble.cpp
- [[notifyStateCallbacks]] - code - supervisor.h
- [[requestArm]] - code - supervisor.h
- [[requestConnect]] - code - supervisor.h
- [[transitionTo]] - code - supervisor.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Supervisor_Arm_Transitions
SORT file.name ASC
```

## Connections to other communities
- 7 edges to [[_COMMUNITY_Supervisor Watchdog Handlers]]
- 4 edges to [[_COMMUNITY_Safety Supervisor State]]
- 2 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 2 edges to [[_COMMUNITY_Failsafe and Vehicle State]]
- 2 edges to [[_COMMUNITY_Wheel Mode and Connect Handling]]
- 2 edges to [[_COMMUNITY_Supervisor Command Send Loop]]
- 1 edge to [[_COMMUNITY_BLE Status Query Getters]]

## Top bridge nodes
- [[transitionTo]] - degree 18, connects to 7 communities
- [[requestArm]] - degree 4, connects to 2 communities
- [[notifyStateCallbacks]] - degree 4, connects to 2 communities
- [[requestConnect]] - degree 3, connects to 2 communities
- [[bleResetMotorWriteOk()]] - degree 3, connects to 1 community