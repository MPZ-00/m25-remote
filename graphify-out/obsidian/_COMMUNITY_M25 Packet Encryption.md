---
type: community
members: 6
---

# M25 Packet Encryption

**Members:** 6 nodes

## Members
- [[README protocol summary (BLE GATT packet structure)]] - document - README.md
- [[_addDelimiters()]] - code - m25_ble.cpp
- [[_buildAndEncrypt()]] - code - m25_ble.cpp
- [[_m25Encrypt()]] - code - m25_ble.cpp
- [[m25_crypto.py (external, AES-128-CBC reference)]] - concept - m25_ble.h
- [[m25_protocol.py (external, CRC-16byte-stuffing reference)]] - concept - m25_ble.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/M25_Packet_Encryption
SORT file.name ASC
```

## Connections to other communities
- 3 edges to [[_COMMUNITY_BLE Wheel Getters & Diagnostics]]
- 1 edge to [[_COMMUNITY_BLE Response Frame Parsing]]
- 1 edge to [[_COMMUNITY_BLE Motor Command Task]]

## Top bridge nodes
- [[_m25Encrypt()]] - degree 7, connects to 2 communities
- [[_buildAndEncrypt()]] - degree 3, connects to 2 communities
- [[_addDelimiters()]] - degree 2, connects to 1 community