---
type: community
members: 13
---

# M25 BLE Response Parsing

**Members:** 13 nodes

## Members
- [[ResponseData]] - code - m25_ble.h
- [[_isAck()]] - code - m25_ble.cpp
- [[_isNack()]] - code - m25_ble.cpp
- [[_parseInt16BE()]] - code - m25_ble.h
- [[_parseInt32BE()]] - code - m25_ble.h
- [[_parseResponseData()]] - code - m25_ble.cpp
- [[_parseUint16BE()]] - code - m25_ble.h
- [[_parseUint32BE()]] - code - m25_ble.h
- [[_parseUint8()]] - code - m25_ble.h
- [[isAck]] - code - m25_ble.h
- [[isNack]] - code - m25_ble.h
- [[m25_ble.h]] - code - m25_ble.h
- [[nackCode]] - code - m25_ble.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/M25_BLE_Response_Parsing
SORT file.name ASC
```

## Connections to other communities
- 7 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 2 edges to [[_COMMUNITY_M25 Protocol Response Header]]
- 2 edges to [[_COMMUNITY_BLE Diagnostics and Tx Stats]]
- 1 edge to [[_COMMUNITY_BLE Scanner and Connect]]
- 1 edge to [[_COMMUNITY_Button Input Handling]]
- 1 edge to [[_COMMUNITY_BLE Record Entry Struct]]
- 1 edge to [[_COMMUNITY_BLE Client Disconnect Callbacks]]
- 1 edge to [[_COMMUNITY_Wheel Connection State]]
- 1 edge to [[_COMMUNITY_Serial Command Output Helpers]]
- 1 edge to [[_COMMUNITY_Supervisor Watchdog Handlers]]
- 1 edge to [[_COMMUNITY_Joystick to Command Mapper]]

## Top bridge nodes
- [[m25_ble.h]] - degree 17, connects to 11 communities
- [[_parseResponseData()]] - degree 10, connects to 3 communities
- [[ResponseData]] - degree 7, connects to 1 community
- [[_isNack()]] - degree 2, connects to 1 community
- [[_isAck()]] - degree 2, connects to 1 community