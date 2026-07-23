---
type: community
members: 6
---

# BLE Client Disconnect Callbacks

**Members:** 6 nodes

## Members
- [[BLEClient_1]] - code
- [[BLEClientCallbacks_1]] - code
- [[M25DisconnectCallback]] - code - m25_ble.h
- [[onConnect]] - code - m25_ble.h
- [[onDisconnect]] - code - m25_ble.h
- [[wheelIdx]] - code - m25_ble.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_Client_Disconnect_Callbacks
SORT file.name ASC
```

## Connections to other communities
- 2 edges to [[_COMMUNITY_BLE GATT Client Core]]
- 1 edge to [[_COMMUNITY_Wheel Mode and Connect Handling]]
- 1 edge to [[_COMMUNITY_M25 BLE Response Parsing]]

## Top bridge nodes
- [[onDisconnect]] - degree 4, connects to 2 communities
- [[M25DisconnectCallback]] - degree 5, connects to 1 community
- [[onConnect]] - degree 3, connects to 1 community