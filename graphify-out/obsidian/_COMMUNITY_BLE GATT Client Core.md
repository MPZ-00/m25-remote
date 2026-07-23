---
type: community
members: 79
---

# BLE GATT Client Core

**Members:** 79 nodes

## Members
- [[BLERemoteCharacteristic]] - code
- [[README protocol summary (BLE GATT packet structure)]] - document - README.md
- [[ROADMAP Phase 3 Drive features (planned)]] - document - ROADMAP.md
- [[RSSI-gated arming block arming below BLE signal threshold (planned safety feature, 3.2)]] - rationale - ROADMAP.md
- [[_addDelimiters()]] - code - m25_ble.cpp
- [[_bleErrStr()]] - code - m25_ble.cpp
- [[_bleMotorTask()]] - code - m25_ble.cpp
- [[_bleRecordFrame()]] - code - m25_ble.cpp
- [[_bluedroidStatusStr()]] - code - m25_ble.cpp
- [[_btControllerStatusStr()]] - code - m25_ble.cpp
- [[_buildAndEncrypt()]] - code - m25_ble.cpp
- [[_clearTxFailureState()]] - code - m25_ble.cpp
- [[_connectTaskBody]] - code - supervisor.h
- [[_connectWheel()]] - code - m25_ble.cpp
- [[_debugLogTxPacket()]] - code - m25_ble.cpp
- [[_findWheelByBda()]] - code - m25_ble.cpp
- [[_findWheelByHandle()]] - code - m25_ble.cpp
- [[_handleTxFailure()]] - code - m25_ble.cpp
- [[_hexSnippet()]] - code - m25_ble.cpp
- [[_m25Crc16()]] - code - m25_ble.cpp
- [[_m25Decrypt()]] - code - m25_ble.cpp
- [[_m25Encrypt()]] - code - m25_ble.cpp
- [[_nackCodeToString()]] - code - m25_ble.cpp
- [[_notifyCallback()]] - code - m25_ble.cpp
- [[_paramName()]] - code - m25_ble.cpp
- [[_parseMacToBda()]] - code - m25_ble.cpp
- [[_parseResponseHeader()]] - code - m25_ble.cpp
- [[_parseSppPacket()]] - code - m25_ble.cpp
- [[_printResponse()]] - code - m25_ble.cpp
- [[_removeDelimiters()]] - code - m25_ble.cpp
- [[_requestAll()]] - code - m25_ble.cpp
- [[_requestOne()]] - code - m25_ble.cpp
- [[_rfcommConsumeBuffered()]] - code - m25_ble.cpp
- [[_rfcommSppCb()]] - code - m25_ble.cpp
- [[_sendCommand()]] - code - m25_ble.cpp
- [[_sppEvtName()]] - code - m25_ble.cpp
- [[_transportClearLinkState()]] - code - m25_ble.cpp
- [[_transportDisconnectLink()]] - code - m25_ble.cpp
- [[_transportHasOpenLink()]] - code - m25_ble.cpp
- [[_transportIsProtocolConnected()]] - code - m25_ble.cpp
- [[_transportLinkReadyForSend()]] - code - m25_ble.cpp
- [[_txStatsCountAttempt()]] - code - m25_ble.cpp
- [[_txStatsCountDriveModeWriteFail()]] - code - m25_ble.cpp
- [[_txStatsCountResult()]] - code - m25_ble.cpp
- [[_txStatsCountSpeedSkippedDueToMode()]] - code - m25_ble.cpp
- [[_updateWheelCache()]] - code - m25_ble.cpp
- [[_wheelNameOrDefault()]] - code - m25_ble.cpp
- [[_writeDriveModeIfNeeded()]] - code - m25_ble.cpp
- [[bleConnect()]] - code - m25_ble.cpp
- [[bleConnectWheel()]] - code - m25_ble.cpp
- [[bleDisconnect()]] - code - m25_ble.cpp
- [[bleFullReset()]] - code - m25_ble.cpp
- [[bleGetBattery()]] - code - m25_ble.cpp
- [[bleGetDistanceKm()]] - code - m25_ble.cpp
- [[bleInit()]] - code - m25_ble.cpp
- [[bleIsConnected()]] - code - m25_ble.cpp
- [[blePrintWheelDetails()]] - code - m25_ble.cpp
- [[bleRecordDump()]] - code - m25_ble.cpp
- [[bleRequestCruiseValues()]] - code - m25_ble.cpp
- [[bleRequestFirmwareVersion()]] - code - m25_ble.cpp
- [[bleRequestSOC()]] - code - m25_ble.cpp
- [[bleResetWheel()]] - code - m25_ble.cpp
- [[bleSendAssistLevel()]] - code - m25_ble.cpp
- [[bleSendHillHold()]] - code - m25_ble.cpp
- [[bleSendMotorCommand()]] - code - m25_ble.cpp
- [[bleSendStop()]] - code - m25_ble.cpp
- [[bleSetMac()]] - code - m25_ble.cpp
- [[bleStartMotorTask()]] - code - m25_ble.cpp
- [[bleTick()]] - code - m25_ble.cpp
- [[bleWheelModeName()]] - code - m25_ble.cpp
- [[buzzerTick()]] - code - buzzer.h
- [[esp_bd_addr_t]] - code
- [[esp_bluedroid_status_t]] - code
- [[esp_bt_controller_status_t]] - code
- [[esp_spp_cb_event_t_1]] - code
- [[esp_spp_cb_param_t_1]] - code
- [[ledTick()]] - code - led_control.h
- [[m25_ble.cpp]] - code - m25_ble.cpp
- [[pollTelemetry]] - code - supervisor.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_GATT_Client_Core
SORT file.name ASC
```

## Connections to other communities
- 26 edges to [[_COMMUNITY_BLE Diagnostics and Tx Stats]]
- 17 edges to [[_COMMUNITY_Wheel Mode and Connect Handling]]
- 15 edges to [[_COMMUNITY_Bluedroid GAP and Logger]]
- 8 edges to [[_COMMUNITY_BLE Status Query Getters]]
- 8 edges to [[_COMMUNITY_Supervisor Watchdog Handlers]]
- 7 edges to [[_COMMUNITY_Wheel Connection State]]
- 7 edges to [[_COMMUNITY_M25 BLE Response Parsing]]
- 4 edges to [[_COMMUNITY_Supervisor Command Send Loop]]
- 3 edges to [[_COMMUNITY_M25 Protocol Response Header]]
- 2 edges to [[_COMMUNITY_LED Status Indicators]]
- 2 edges to [[_COMMUNITY_Failsafe and Vehicle State]]
- 2 edges to [[_COMMUNITY_Supervisor Arm Transitions]]
- 2 edges to [[_COMMUNITY_BLE Client Disconnect Callbacks]]
- 2 edges to [[_COMMUNITY_Safety Supervisor State]]
- 1 edge to [[_COMMUNITY_Button Input Handling]]
- 1 edge to [[_COMMUNITY_Motor Command Struct]]
- 1 edge to [[_COMMUNITY_BLE Command Stats Struct]]
- 1 edge to [[_COMMUNITY_Serial Command Output Helpers]]
- 1 edge to [[_COMMUNITY_Serial Profile Commands]]

## Top bridge nodes
- [[m25_ble.cpp]] - degree 100, connects to 12 communities
- [[bleIsConnected()]] - degree 22, connects to 7 communities
- [[bleSendMotorCommand()]] - degree 8, connects to 3 communities
- [[bleSetMac()]] - degree 8, connects to 3 communities
- [[_printResponse()]] - degree 7, connects to 3 communities