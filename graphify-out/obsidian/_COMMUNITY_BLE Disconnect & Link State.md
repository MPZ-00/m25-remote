---
type: community
members: 13
---

# BLE Disconnect & Link State

**Members:** 13 nodes

## Members
- [[WheelConnState_t]] - code - m25_ble.cpp
- [[_clearTxFailureState()]] - code - m25_ble.cpp
- [[_getWheels()]] - code - m25_ble.cpp
- [[_transportClearLinkState()]] - code - m25_ble.cpp
- [[_transportDisconnectLink()]] - code - m25_ble.cpp
- [[_transportHasOpenLink()]] - code - m25_ble.cpp
- [[_transportIsProtocolConnected()]] - code - m25_ble.cpp
- [[_transportLinkReadyForSend()]] - code - m25_ble.cpp
- [[applyRuntimeWheelConfig()]] - code - supervisor.cpp
- [[bleDisconnect()]] - code - m25_ble.cpp
- [[bleResetWheel()]] - code - m25_ble.cpp
- [[bleSetKey()]] - code - m25_ble.cpp
- [[bleSetMac()]] - code - m25_ble.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_Disconnect__Link_State
SORT file.name ASC
```

## Connections to other communities
- 12 edges to [[_COMMUNITY_BLE Wheel Getters & Diagnostics]]
- 8 edges to [[_COMMUNITY_BLE Threading & Connection State]]
- 4 edges to [[_COMMUNITY_BLE Motor Command Task]]
- 2 edges to [[_COMMUNITY_Configuration Priority & Feature Flags]]

## Top bridge nodes
- [[bleDisconnect()]] - degree 7, connects to 3 communities
- [[bleSetMac()]] - degree 7, connects to 3 communities
- [[bleSetKey()]] - degree 4, connects to 3 communities
- [[bleResetWheel()]] - degree 6, connects to 2 communities
- [[_transportLinkReadyForSend()]] - degree 3, connects to 2 communities