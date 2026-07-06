---
type: community
members: 25
---

# BLE Wheel Getters & Diagnostics

**Members:** 25 nodes

## Members
- [[_debugLogTxPacket()]] - code - m25_ble.cpp
- [[_findWheelByBda()]] - code - m25_ble.cpp
- [[_paramName()]] - code - m25_ble.cpp
- [[_wheelNameOrDefault()]] - code - m25_ble.cpp
- [[bleFullReset()]] - code - m25_ble.cpp
- [[bleGetAutoReconnect()]] - code - m25_ble.cpp
- [[bleGetFirmwareVersion()]] - code - m25_ble.cpp
- [[bleGetMac()]] - code - m25_ble.cpp
- [[bleGetMotorStopLogEnabled()]] - code - m25_ble.cpp
- [[bleGetMotorStopLogEvery()]] - code - m25_ble.cpp
- [[bleGetWheelMode()]] - code - m25_ble.cpp
- [[bleInit()]] - code - m25_ble.cpp
- [[blePrintTxStats()]] - code - m25_ble.cpp
- [[blePrintWheelDetails()]] - code - m25_ble.cpp
- [[bleRecordEntryCount()]] - code - m25_ble.cpp
- [[bleRecordIsActive()]] - code - m25_ble.cpp
- [[bleRecordStart()]] - code - m25_ble.cpp
- [[bleRecordStop()]] - code - m25_ble.cpp
- [[bleResetTxStats()]] - code - m25_ble.cpp
- [[bleSetAutoReconnect()]] - code - m25_ble.cpp
- [[bleSetMotorStopLogEnabled()]] - code - m25_ble.cpp
- [[bleSetMotorStopLogEvery()]] - code - m25_ble.cpp
- [[bleSetWheelMode()]] - code - m25_ble.cpp
- [[bleWheelModeName()]] - code - m25_ble.cpp
- [[m25_ble.cpp]] - code - m25_ble.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_Wheel_Getters__Diagnostics
SORT file.name ASC
```

## Connections to other communities
- 18 edges to [[_COMMUNITY_BLE Motor Command Task]]
- 16 edges to [[_COMMUNITY_BLE Response Frame Parsing]]
- 13 edges to [[_COMMUNITY_BLE Threading & Connection State]]
- 12 edges to [[_COMMUNITY_BLE Disconnect & Link State]]
- 9 edges to [[_COMMUNITY_BLE Connect & Status Strings]]
- 3 edges to [[_COMMUNITY_M25 Packet Encryption]]
- 3 edges to [[_COMMUNITY_RFCOMM SPP Callback (archive)]]
- 2 edges to [[_COMMUNITY_BLE Client Callbacks & Parsing]]
- 2 edges to [[_COMMUNITY_Configuration Priority & Feature Flags]]
- 1 edge to [[_COMMUNITY_Motor Command Struct]]
- 1 edge to [[_COMMUNITY_Bluetooth GAP Callback (archive)]]
- 1 edge to [[_COMMUNITY_BLE TX Stats Struct]]

## Top bridge nodes
- [[m25_ble.cpp]] - degree 100, connects to 11 communities
- [[_debugLogTxPacket()]] - degree 5, connects to 2 communities
- [[bleFullReset()]] - degree 4, connects to 2 communities
- [[bleWheelModeName()]] - degree 4, connects to 1 community
- [[blePrintWheelDetails()]] - degree 3, connects to 1 community