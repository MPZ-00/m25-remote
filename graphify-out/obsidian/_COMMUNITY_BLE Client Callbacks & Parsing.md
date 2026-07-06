---
type: community
members: 11
---

# BLE Client Callbacks & Parsing

**Members:** 11 nodes

## Members
- [[BLEClient]] - code - m25_ble.cpp
- [[M25DisconnectCallback()]] - code - m25_ble.h
- [[_parseInt16BE()]] - code - m25_ble.h
- [[_parseInt32BE()]] - code - m25_ble.h
- [[_parseUint16BE()]] - code - m25_ble.h
- [[_parseUint32BE()]] - code - m25_ble.h
- [[_parseUint8()]] - code - m25_ble.h
- [[class_2]] - code - m25_ble.h
- [[m25_ble.h]] - code - m25_ble.h
- [[onConnect()]] - code - m25_ble.cpp
- [[onDisconnect()]] - code - m25_ble.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_Client_Callbacks__Parsing
SORT file.name ASC
```

## Connections to other communities
- 2 edges to [[_COMMUNITY_BLE Wheel Getters & Diagnostics]]
- 1 edge to [[_COMMUNITY_Buttons & Buzzer Input]]
- 1 edge to [[_COMMUNITY_BLE Threading & Connection State]]

## Top bridge nodes
- [[onDisconnect()]] - degree 3, connects to 2 communities
- [[m25_ble.h]] - degree 8, connects to 1 community
- [[onConnect()]] - degree 2, connects to 1 community