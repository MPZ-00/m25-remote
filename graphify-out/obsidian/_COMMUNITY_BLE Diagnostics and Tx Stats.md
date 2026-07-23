---
type: community
members: 32
---

# BLE Diagnostics and Tx Stats

**Members:** 32 nodes

## Members
- [[ROADMAP Phase 2 Telemetry & UI (in progress)]] - document - ROADMAP.md
- [[_scDispatch()]] - code - serial_commands.h
- [[_scParseHex16()]] - code - serial_commands.h
- [[_scPrintWheels()]] - code - serial_commands.h
- [[_scTryGetTagByName()]] - code - serial_commands.h
- [[bleGetMotorStopLogEnabled()]] - code - m25_ble.cpp
- [[bleGetMotorStopLogEvery()]] - code - m25_ble.cpp
- [[bleGetWheelMode()]] - code - m25_ble.cpp
- [[blePrintTxStats()]] - code - m25_ble.cpp
- [[bleRecordStart()]] - code - m25_ble.cpp
- [[bleRecordStop()]] - code - m25_ble.cpp
- [[bleResetTxStats()]] - code - m25_ble.cpp
- [[bleSetAutoReconnect()]] - code - m25_ble.cpp
- [[bleSetMotorStopLogEnabled()]] - code - m25_ble.cpp
- [[bleSetMotorStopLogEvery()]] - code - m25_ble.cpp
- [[bleSetWheelMode()]] - code - m25_ble.cpp
- [[nvsClearAll()]] - code - nvs_config.h
- [[nvsLoadActiveProfile()]] - code - nvs_config.h
- [[nvsLoadAssistLevel()]] - code - nvs_config.h
- [[nvsLoadJsRange()]] - code - nvs_config.h
- [[nvsLoadKey()]] - code - nvs_config.h
- [[nvsLoadMac()]] - code - nvs_config.h
- [[nvsLoadMaxSpeed()]] - code - nvs_config.h
- [[nvsLoadWheelMode()]] - code - nvs_config.h
- [[nvsPrintAll()]] - code - nvs_config.h
- [[nvsSaveActiveProfile()]] - code - nvs_config.h
- [[nvsSaveAssistLevel()]] - code - nvs_config.h
- [[nvsSaveKey()]] - code - nvs_config.h
- [[nvsSaveMac()]] - code - nvs_config.h
- [[nvsSaveMaxSpeed()]] - code - nvs_config.h
- [[nvsSaveWheelMode()]] - code - nvs_config.h
- [[nvs_config.h]] - code - nvs_config.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_Diagnostics_and_Tx_Stats
SORT file.name ASC
```

## Connections to other communities
- 26 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 14 edges to [[_COMMUNITY_Serial Command Output Helpers]]
- 5 edges to [[_COMMUNITY_BLE Status Query Getters]]
- 4 edges to [[_COMMUNITY_Joystick ADC Input]]
- 2 edges to [[_COMMUNITY_Bluedroid GAP and Logger]]
- 2 edges to [[_COMMUNITY_Button Input Handling]]
- 2 edges to [[_COMMUNITY_LED Status Indicators]]
- 2 edges to [[_COMMUNITY_Wheel Mode and Connect Handling]]
- 2 edges to [[_COMMUNITY_M25 BLE Response Parsing]]
- 2 edges to [[_COMMUNITY_Joystick Calibration Persistence]]
- 2 edges to [[_COMMUNITY_Serial Profile Commands]]
- 1 edge to [[_COMMUNITY_Failsafe and Vehicle State]]

## Top bridge nodes
- [[_scDispatch()]] - degree 67, connects to 11 communities
- [[nvs_config.h]] - degree 20, connects to 5 communities
- [[_scPrintWheels()]] - degree 3, connects to 2 communities
- [[nvsPrintAll()]] - degree 6, connects to 1 community
- [[bleRecordStart()]] - degree 2, connects to 1 community