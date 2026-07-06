---
type: community
members: 5
---

# RFCOMM SPP Callback (archive)

**Members:** 5 nodes

## Members
- [[_findWheelByHandle()]] - code - m25_ble.cpp
- [[_rfcommSppCb()]] - code - m25_ble.cpp
- [[_sppEvtName()]] - code - m25_ble.cpp
- [[esp_spp_cb_event_t_1]] - code - m25_ble.cpp
- [[esp_spp_cb_param_t_1]] - code - m25_ble.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/RFCOMM_SPP_Callback_archive
SORT file.name ASC
```

## Connections to other communities
- 3 edges to [[_COMMUNITY_BLE Wheel Getters & Diagnostics]]
- 1 edge to [[_COMMUNITY_BLE Response Frame Parsing]]

## Top bridge nodes
- [[_rfcommSppCb()]] - degree 6, connects to 2 communities
- [[_sppEvtName()]] - degree 3, connects to 1 community
- [[_findWheelByHandle()]] - degree 2, connects to 1 community