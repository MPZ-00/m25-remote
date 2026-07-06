---
type: community
members: 20
---

# BLE Motor Command Task

**Members:** 20 nodes

## Members
- [[ROADMAP Phase 3 Drive features (planned)]] - document - ROADMAP.md
- [[RSSI-gated arming block arming below BLE signal threshold (planned safety feature, 3.2)]] - rationale - ROADMAP.md
- [[_bleMotorTask()]] - code - m25_ble.cpp
- [[_handleTxFailure()]] - code - m25_ble.cpp
- [[_requestAll()]] - code - m25_ble.cpp
- [[_requestOne()]] - code - m25_ble.cpp
- [[_sendCommand()]] - code - m25_ble.cpp
- [[_txStatsCountAttempt()]] - code - m25_ble.cpp
- [[_txStatsCountResult()]] - code - m25_ble.cpp
- [[_txStatsCountSpeedSkippedDueToMode()]] - code - m25_ble.cpp
- [[_writeDriveModeIfNeeded()]] - code - m25_ble.cpp
- [[bleIsConnected()]] - code - m25_ble.cpp
- [[bleRequestCruiseValues()]] - code - m25_ble.cpp
- [[bleRequestFirmwareVersion()]] - code - m25_ble.cpp
- [[bleRequestSOC()]] - code - m25_ble.cpp
- [[bleSendAssistLevel()]] - code - m25_ble.cpp
- [[bleSendHillHold()]] - code - m25_ble.cpp
- [[bleSendMotorCommand()]] - code - m25_ble.cpp
- [[bleSendStop()]] - code - m25_ble.cpp
- [[m25_spp.py PacketBuilder (external reference)]] - concept - m25_ble.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_Motor_Command_Task
SORT file.name ASC
```

## Connections to other communities
- 18 edges to [[_COMMUNITY_BLE Wheel Getters & Diagnostics]]
- 16 edges to [[_COMMUNITY_BLE Threading & Connection State]]
- 4 edges to [[_COMMUNITY_BLE Disconnect & Link State]]
- 4 edges to [[_COMMUNITY_Configuration Priority & Feature Flags]]
- 2 edges to [[_COMMUNITY_BLE Connect & Status Strings]]
- 1 edge to [[_COMMUNITY_Buttons & Buzzer Input]]
- 1 edge to [[_COMMUNITY_BLE Response Frame Parsing]]
- 1 edge to [[_COMMUNITY_M25 Packet Encryption]]

## Top bridge nodes
- [[_sendCommand()]] - degree 21, connects to 6 communities
- [[bleIsConnected()]] - degree 22, connects to 4 communities
- [[bleSendMotorCommand()]] - degree 8, connects to 3 communities
- [[bleSendStop()]] - degree 6, connects to 3 communities
- [[_writeDriveModeIfNeeded()]] - degree 7, connects to 2 communities