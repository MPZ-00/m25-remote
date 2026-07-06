---
type: community
members: 17
---

# BLE Transport Event Handling (archive)

**Members:** 17 nodes

## Members
- [[BLECharacteristicCallbacks()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[BLEServerCallbacks()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_check_events()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_check_events(onConnect, onDisconnect)]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_connected()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_disconnect()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_init()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_mark_valid()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_on_connect()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_on_disconnect()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_poll()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_send()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_stale_count()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_stale_inc()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_start_advertising()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[class]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[transport_ble.h]] - code - archive/m25_wheel_rfcomm/transport_ble.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/BLE_Transport_Event_Handling_archive
SORT file.name ASC
```

## Connections to other communities
- 6 edges to [[_COMMUNITY_CLI Debug Printing (archive)]]
- 2 edges to [[_COMMUNITY_RFCOMM Transport Event Handling (archive)]]
- 1 edge to [[_COMMUNITY_Fake Wheel State & Commands (archive)]]
- 1 edge to [[_COMMUNITY_Fake Wheel BLE Server & Buzzer]]

## Top bridge nodes
- [[transport_ble.h]] - degree 20, connects to 3 communities
- [[ble_on_connect()]] - degree 4, connects to 1 community
- [[ble_stale_count()]] - degree 3, connects to 1 community
- [[ble_check_events(onConnect, onDisconnect)]] - degree 3, connects to 1 community