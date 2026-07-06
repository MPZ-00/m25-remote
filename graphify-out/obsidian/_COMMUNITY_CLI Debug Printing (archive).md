---
type: community
members: 18
---

# CLI Debug Printing (archive)

**Members:** 18 nodes

## Members
- [[CliActions]] - code - archive/m25_wheel_rfcomm/cli.h
- [[UBaseType_t]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[WheelState]] - code - archive/m25_wheel_rfcomm/cli.h
- [[_cli_print_debug_flags()]] - code - archive/m25_wheel_rfcomm/cli.h
- [[_cli_print_hardware()]] - code - archive/m25_wheel_rfcomm/cli.h
- [[_cli_print_help()]] - code - archive/m25_wheel_rfcomm/cli.h
- [[_cli_print_key()]] - code - archive/m25_wheel_rfcomm/cli.h
- [[_cli_print_key(key)]] - code - archive/m25_wheel_rfcomm/cli.h
- [[ble_conn_time()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_first_valid()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[ble_rx_queue_waiting()]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[cli.h]] - code - archive/m25_wheel_rfcomm/cli.h
- [[cli_dbg()]] - code - archive/m25_wheel_rfcomm/cli.h
- [[cli_poll()]] - code - archive/m25_wheel_rfcomm/cli.h
- [[cli_poll(act, state)]] - code - archive/m25_wheel_rfcomm/cli.h
- [[led_show_battery(level)]] - code - archive/m25_wheel_rfcomm/led.h
- [[rfcomm_server_channel()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[state_print(state)]] - code - archive/m25_wheel_rfcomm/state.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/CLI_Debug_Printing_archive
SORT file.name ASC
```

## Connections to other communities
- 11 edges to [[_COMMUNITY_Buzzer Control (archive)]]
- 6 edges to [[_COMMUNITY_BLE Transport Event Handling (archive)]]
- 4 edges to [[_COMMUNITY_Wheel Runtime Config CLI (archive)]]
- 4 edges to [[_COMMUNITY_Fake Wheel State & Commands (archive)]]
- 4 edges to [[_COMMUNITY_RFCOMM Transport Event Handling (archive)]]
- 2 edges to [[_COMMUNITY_LED Status Indicators (archive)]]
- 1 edge to [[_COMMUNITY_RFCOMM Transport & Packet Codec (archive)]]

## Top bridge nodes
- [[cli_poll()]] - degree 22, connects to 6 communities
- [[cli.h]] - degree 14, connects to 6 communities
- [[cli_poll(act, state)]] - degree 19, connects to 5 communities
- [[ble_rx_queue_waiting()]] - degree 4, connects to 1 community
- [[ble_first_valid()]] - degree 3, connects to 1 community