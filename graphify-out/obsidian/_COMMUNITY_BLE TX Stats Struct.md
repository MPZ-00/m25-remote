---
type: community
members: 15
---

# BLE TX Stats Struct

**Members:** 15 nodes

## Members
- [[TxStats]] - code - m25_ble.cpp
- [[assistLevel]] - code - m25_ble.cpp
- [[driveMode]] - code - m25_ble.cpp
- [[driveModeWriteFail]] - code - m25_ble.cpp
- [[other]] - code - m25_ble.cpp
- [[readCruise]] - code - m25_ble.cpp
- [[readFw]] - code - m25_ble.cpp
- [[readSoc]] - code - m25_ble.cpp
- [[remoteSpeed]] - code - m25_ble.cpp
- [[remoteSpeedMotion]] - code - m25_ble.cpp
- [[remoteSpeedStop]] - code - m25_ble.cpp
- [[speedSkippedDueToMode]] - code - m25_ble.cpp
- [[totalAttempts]] - code - m25_ble.cpp
- [[totalFail]] - code - m25_ble.cpp
- [[totalSuccess]] - code - m25_ble.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_TX_Stats_Struct
SORT file.name ASC
```

## Connections to other communities
- 1 edge to [[_COMMUNITY_BLE Wheel Getters & Diagnostics]]

## Top bridge nodes
- [[TxStats]] - degree 15, connects to 1 community