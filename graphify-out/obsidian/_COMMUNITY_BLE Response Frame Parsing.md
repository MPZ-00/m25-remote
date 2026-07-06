---
type: community
members: 19
---

# BLE Response Frame Parsing

**Members:** 19 nodes

## Members
- [[BLERemoteCharacteristic]] - code - m25_ble.cpp
- [[ROADMAP Phase 2 Telemetry & UI (in progress)]] - document - ROADMAP.md
- [[ResponseData]] - code - m25_ble.cpp
- [[ResponseHeader]] - code - m25_ble.cpp
- [[_bleRecordFrame()]] - code - m25_ble.cpp
- [[_hexSnippet()]] - code - m25_ble.cpp
- [[_isAck()]] - code - m25_ble.cpp
- [[_isNack()]] - code - m25_ble.cpp
- [[_m25Crc16()]] - code - m25_ble.cpp
- [[_m25Decrypt()]] - code - m25_ble.cpp
- [[_nackCodeToString()]] - code - m25_ble.cpp
- [[_notifyCallback()]] - code - m25_ble.cpp
- [[_parseResponseData()]] - code - m25_ble.cpp
- [[_parseResponseHeader()]] - code - m25_ble.cpp
- [[_parseSppPacket()]] - code - m25_ble.cpp
- [[_printResponse()]] - code - m25_ble.cpp
- [[_removeDelimiters()]] - code - m25_ble.cpp
- [[_rfcommConsumeBuffered()]] - code - m25_ble.cpp
- [[_updateWheelCache()]] - code - m25_ble.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_Response_Frame_Parsing
SORT file.name ASC
```

## Connections to other communities
- 16 edges to [[_COMMUNITY_BLE Wheel Getters & Diagnostics]]
- 1 edge to [[_COMMUNITY_BLE Motor Command Task]]
- 1 edge to [[_COMMUNITY_M25 Packet Encryption]]
- 1 edge to [[_COMMUNITY_RFCOMM SPP Callback (archive)]]
- 1 edge to [[_COMMUNITY_Configuration Priority & Feature Flags]]

## Top bridge nodes
- [[_rfcommConsumeBuffered()]] - degree 5, connects to 2 communities
- [[_bleRecordFrame()]] - degree 4, connects to 2 communities
- [[_m25Crc16()]] - degree 3, connects to 2 communities
- [[_parseResponseData()]] - degree 7, connects to 1 community
- [[_parseSppPacket()]] - degree 7, connects to 1 community