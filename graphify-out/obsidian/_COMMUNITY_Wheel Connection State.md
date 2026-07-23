---
type: community
members: 27
---

# Wheel Connection State

**Members:** 27 nodes

## Members
- [[WheelConnState_t]] - code - m25_ble.h
- [[_getWheels()]] - code - m25_ble.cpp
- [[batteryPct]] - code - m25_ble.h
- [[batteryValid]] - code - m25_ble.h
- [[connected]] - code - m25_ble.h
- [[consecutiveFails]] - code - m25_ble.h
- [[distanceKm]] - code - m25_ble.h
- [[distanceValid]] - code - m25_ble.h
- [[driveModeBits]] - code - m25_ble.h
- [[driveModeReadbackBits]] - code - m25_ble.h
- [[driveModeReadbackMs]] - code - m25_ble.h
- [[driveModeReadbackValid]] - code - m25_ble.h
- [[fwMajor]] - code - m25_ble.h
- [[fwMinor]] - code - m25_ble.h
- [[fwPatch]] - code - m25_ble.h
- [[fwValid]] - code - m25_ble.h
- [[key]] - code - m25_ble.h
- [[lastConnectAttemptMs]] - code - m25_ble.h
- [[lastDriveModeWriteMs]] - code - m25_ble.h
- [[lastNotifyMs]] - code - m25_ble.h
- [[lastTxFailMs]] - code - m25_ble.h
- [[mac]] - code - m25_ble.h
- [[name_1]] - code - m25_ble.h
- [[protocolReady]] - code - m25_ble.h
- [[receivedFirstAck]] - code - m25_ble.h
- [[telegramId_1]] - code - m25_ble.h
- [[txFailStreak]] - code - m25_ble.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Wheel_Connection_State
SORT file.name ASC
```

## Connections to other communities
- 7 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 1 edge to [[_COMMUNITY_M25 BLE Response Parsing]]

## Top bridge nodes
- [[WheelConnState_t]] - degree 33, connects to 2 communities
- [[_getWheels()]] - degree 2, connects to 1 community