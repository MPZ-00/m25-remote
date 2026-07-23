---
type: community
members: 9
---

# M25 Protocol Response Header

**Members:** 9 nodes

## Members
- [[ResponseHeader]] - code - m25_ble.h
- [[destId]] - code - m25_ble.h
- [[paramId]] - code - m25_ble.h
- [[payload]] - code - m25_ble.h
- [[payloadLen]] - code - m25_ble.h
- [[protocolId]] - code - m25_ble.h
- [[serviceId]] - code - m25_ble.h
- [[sourceId]] - code - m25_ble.h
- [[telegramId]] - code - m25_ble.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/M25_Protocol_Response_Header
SORT file.name ASC
```

## Connections to other communities
- 3 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 2 edges to [[_COMMUNITY_M25 BLE Response Parsing]]

## Top bridge nodes
- [[ResponseHeader]] - degree 13, connects to 2 communities