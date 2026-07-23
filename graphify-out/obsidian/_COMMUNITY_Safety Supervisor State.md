---
type: community
members: 42
---

# Safety Supervisor State

**Members:** 42 nodes

## Members
- [[.getReconnectAttempts()]] - code - supervisor.h
- [[.getState()]] - code - supervisor.h
- [[.isDriving()]] - code - supervisor.h
- [[StateCallback_1]] - code
- [[Supervisor_2]] - code - supervisor.h
- [[SupervisorConfig_1]] - code
- [[SupervisorState_1]] - code
- [[TaskHandle_t]] - code
- [[VehicleState_1]] - code
- [[_activateHoldStartMs]] - code - supervisor.h
- [[_armedEntryMs]] - code - supervisor.h
- [[_callbackCount]] - code - supervisor.h
- [[_config_1]] - code - supervisor.h
- [[_connectAbort]] - code - supervisor.h
- [[_connectAttemptMs]] - code - supervisor.h
- [[_connectDone]] - code - supervisor.h
- [[_connectTask]] - code - supervisor.h
- [[_connectionRequested]] - code - supervisor.h
- [[_deadzoneStopLatched]] - code - supervisor.h
- [[_driveEntryMs]] - code - supervisor.h
- [[_driveSessionActive]] - code - supervisor.h
- [[_idleHoldStartMs]] - code - supervisor.h
- [[_lastArmedKeepaliveMs]] - code - supervisor.h
- [[_lastHeartbeatMs]] - code - supervisor.h
- [[_lastInputTimeMs]] - code - supervisor.h
- [[_lastLeftConnected]] - code - supervisor.h
- [[_lastLinkTimeMs]] - code - supervisor.h
- [[_lastRightConnected]] - code - supervisor.h
- [[_lastTelemetryPollMs]] - code - supervisor.h
- [[_lastUpdateMs]] - code - supervisor.h
- [[_leftAddr]] - code - supervisor.h
- [[_leftKey]] - code - supervisor.h
- [[_partialReconnect]] - code - supervisor.h
- [[_reconnectNotBeforeMs]] - code - supervisor.h
- [[_reconnectReqCooldownUntilMs]] - code - supervisor.h
- [[_rightAddr]] - code - supervisor.h
- [[_rightKey]] - code - supervisor.h
- [[_state]] - code - supervisor.h
- [[_stateCallbacks]] - code - supervisor.h
- [[_stopRequested]] - code - supervisor.h
- [[_vehicleState]] - code - supervisor.h
- [[_wheelRetries]] - code - supervisor.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Safety_Supervisor_State
SORT file.name ASC
```

## Connections to other communities
- 19 edges to [[_COMMUNITY_Supervisor Watchdog Handlers]]
- 5 edges to [[_COMMUNITY_Failsafe and Vehicle State]]
- 4 edges to [[_COMMUNITY_Supervisor Command Send Loop]]
- 4 edges to [[_COMMUNITY_Supervisor Arm Transitions]]
- 3 edges to [[_COMMUNITY_Joystick to Command Mapper]]
- 2 edges to [[_COMMUNITY_Wheel Mode and Connect Handling]]
- 2 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 1 edge to [[_COMMUNITY_State Callback Registration]]

## Top bridge nodes
- [[Supervisor_2]] - degree 81, connects to 8 communities