---
type: community
members: 16
---

# RFCOMM Transport Event Handling (archive)

**Members:** 16 nodes

## Members
- [[_rfcomm_drain()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[_rfcomm_drop_until_header()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[_rfcomm_spp_callback()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[_rfcomm_try_parse()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[esp_spp_cb_event_t]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[esp_spp_cb_param_t]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_check_events()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_connected()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_init()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_on_connect()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_on_disconnect()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_poll()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_poll(out, outLen)]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_send()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_server_channel_known()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[transport_rfcomm.h]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/RFCOMM_Transport_Event_Handling_archive
SORT file.name ASC
```

## Connections to other communities
- 4 edges to [[_COMMUNITY_CLI Debug Printing (archive)]]
- 3 edges to [[_COMMUNITY_Fake Wheel State & Commands (archive)]]
- 2 edges to [[_COMMUNITY_BLE Transport Event Handling (archive)]]
- 1 edge to [[_COMMUNITY_RFCOMM Transport & Packet Codec (archive)]]

## Top bridge nodes
- [[transport_rfcomm.h]] - degree 16, connects to 2 communities
- [[rfcomm_check_events()]] - degree 4, connects to 1 community
- [[rfcomm_server_channel_known()]] - degree 3, connects to 1 community
- [[rfcomm_on_connect()]] - degree 3, connects to 1 community
- [[_rfcomm_try_parse()]] - degree 3, connects to 1 community