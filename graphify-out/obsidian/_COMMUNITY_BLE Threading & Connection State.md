---
type: community
members: 58
---

# BLE Threading & Connection State

**Members:** 58 nodes

## Members
- [[BLE threading model loop() on Core 1, motor writes on Core 0]] - document - CLAUDE.md
- [[CommandFrame_1]] - code - supervisor.cpp
- [[ControlState_1]] - code - supervisor.cpp
- [[Mapper]] - code - supervisor.cpp
- [[MappersetLowBatteryLimit]] - code - mapper.h
- [[StateCallback]] - code - supervisor.cpp
- [[Supervisor()]] - code - supervisor.cpp
- [[SupervisorConfig]] - code - supervisor.cpp
- [[SupervisorState]] - code - supervisor.cpp
- [[VehicleState]] - code - supervisor.cpp
- [[_bleTxMutex serializes GATT writes to avoid isConnected() deadlock across Core0Core1 tasks]] - rationale - m25_ble.cpp
- [[_connectTaskBody()]] - code - supervisor.cpp
- [[_sConnectTask()]] - code - supervisor.cpp
- [[_triggerPartialReconnect()]] - code - supervisor.cpp
- [[_wheelActive()]] - code - m25_ble.cpp
- [[addStateCallback()]] - code - supervisor.cpp
- [[begin()_1]] - code - supervisor.cpp
- [[bleAllConnected()]] - code - m25_ble.cpp
- [[bleAnyConnected()]] - code - m25_ble.cpp
- [[bleConnectWheel()]] - code - m25_ble.cpp
- [[bleGetBattery()]] - code - m25_ble.cpp
- [[bleGetDistanceKm()]] - code - m25_ble.cpp
- [[bleGetLastNotifyMs()]] - code - m25_ble.cpp
- [[bleLastMotorWriteOk()]] - code - m25_ble.cpp
- [[bleResetMotorWriteOk()]] - code - m25_ble.cpp
- [[bleResetNotifyTimers()]] - code - m25_ble.cpp
- [[bleStartMotorTask()]] - code - m25_ble.cpp
- [[checkWatchdogs()]] - code - supervisor.cpp
- [[enterFailsafe()]] - code - supervisor.cpp
- [[getArmedIdleRemainingMs()]] - code - supervisor.cpp
- [[getTimeSinceLastInput()]] - code - supervisor.cpp
- [[getTimeSinceLastLink()]] - code - supervisor.cpp
- [[handleArmed()]] - code - supervisor.cpp
- [[handleConnecting()]] - code - supervisor.cpp
- [[handleDisconnected()]] - code - supervisor.cpp
- [[handleDriving()]] - code - supervisor.cpp
- [[handleFailsafe()]] - code - supervisor.cpp
- [[handlePaired()]] - code - supervisor.cpp
- [[handleStopRequest()]] - code - supervisor.cpp
- [[isConnected()]] - code - supervisor.cpp
- [[isInputTimeout()]] - code - supervisor.cpp
- [[isLinkTimeout()]] - code - supervisor.cpp
- [[notifyConnectionChange()]] - code - supervisor.cpp
- [[notifyStateCallbacks()]] - code - supervisor.cpp
- [[pollTelemetry()]] - code - supervisor.cpp
- [[processInput()]] - code - supervisor.cpp
- [[requestArm()]] - code - supervisor.cpp
- [[requestConnect()]] - code - supervisor.cpp
- [[requestDisarm()]] - code - supervisor.cpp
- [[requestDisconnect()]] - code - supervisor.cpp
- [[requestEmergencyStop()]] - code - supervisor.cpp
- [[sendCommand()]] - code - supervisor.cpp
- [[sendHeartbeat()]] - code - supervisor.cpp
- [[sendStop()]] - code - supervisor.cpp
- [[supervisor.cpp]] - code - supervisor.cpp
- [[transitionTo()]] - code - supervisor.cpp
- [[update()]] - code - supervisor.cpp
- [[updateVehicleState()]] - code - supervisor.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_Threading__Connection_State
SORT file.name ASC
```

## Connections to other communities
- 16 edges to [[_COMMUNITY_BLE Motor Command Task]]
- 13 edges to [[_COMMUNITY_BLE Wheel Getters & Diagnostics]]
- 8 edges to [[_COMMUNITY_BLE Disconnect & Link State]]
- 4 edges to [[_COMMUNITY_Configuration Priority & Feature Flags]]
- 3 edges to [[_COMMUNITY_Buttons & Buzzer Input]]
- 3 edges to [[_COMMUNITY_BLE Connect & Status Strings]]
- 3 edges to [[_COMMUNITY_Mapper & Supervisor Safety Pipeline]]
- 1 edge to [[_COMMUNITY_BLE Client Callbacks & Parsing]]

## Top bridge nodes
- [[_wheelActive()]] - degree 19, connects to 5 communities
- [[handleConnecting()]] - degree 10, connects to 3 communities
- [[supervisor.cpp]] - degree 40, connects to 2 communities
- [[transitionTo()]] - degree 17, connects to 2 communities
- [[checkWatchdogs()]] - degree 11, connects to 2 communities