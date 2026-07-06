---
type: community
members: 13
---

# BLE Connect & Status Strings

**Members:** 13 nodes

## Members
- [[_bleErrStr()]] - code - m25_ble.cpp
- [[_bluedroidStatusStr()]] - code - m25_ble.cpp
- [[_btControllerStatusStr()]] - code - m25_ble.cpp
- [[_connectWheel()]] - code - m25_ble.cpp
- [[_parseMacToBda()]] - code - m25_ble.cpp
- [[_txStatsCountDriveModeWriteFail()]] - code - m25_ble.cpp
- [[bleConnect()]] - code - m25_ble.cpp
- [[bleRecordDump()]] - code - m25_ble.cpp
- [[bleTick()]] - code - m25_ble.cpp
- [[esp_bd_addr_t]] - code - m25_ble.cpp
- [[esp_bluedroid_status_t]] - code - m25_ble.cpp
- [[esp_bt_controller_status_t]] - code - m25_ble.cpp
- [[m25_parking.py (external, connection sequence + speed sign convention reference)]] - concept - m25_ble.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_Connect__Status_Strings
SORT file.name ASC
```

## Connections to other communities
- 9 edges to [[_COMMUNITY_BLE Wheel Getters & Diagnostics]]
- 3 edges to [[_COMMUNITY_BLE Threading & Connection State]]
- 2 edges to [[_COMMUNITY_BLE Motor Command Task]]

## Top bridge nodes
- [[_connectWheel()]] - degree 10, connects to 3 communities
- [[bleConnect()]] - degree 4, connects to 2 communities
- [[bleTick()]] - degree 4, connects to 2 communities
- [[_txStatsCountDriveModeWriteFail()]] - degree 3, connects to 2 communities
- [[_btControllerStatusStr()]] - degree 3, connects to 1 community