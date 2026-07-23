---
type: community
members: 54
---

# RFCOMM Command Crypto

**Members:** 54 nodes

## Members
- [[CmdResult]] - code
- [[WheelState_1]] - code
- [[WheelState_2]] - code
- [[WheelState_3]] - code
- [[WheelState_4]] - code
- [[_packet_encode_spp()]] - code - archive/m25_wheel_rfcomm/packet.h
- [[_rfcomm_drain()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[_rfcomm_drop_until_header()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[_rfcomm_spp_callback()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[_rfcomm_try_parse()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[command.h]] - code - archive/m25_wheel_rfcomm/command.h
- [[command_apply()]] - code - archive/m25_wheel_rfcomm/command.h
- [[config.h]] - code - archive/m25_wheel_rfcomm/config.h
- [[crypto.h]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_cbc_decrypt()]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_cbc_encrypt()]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_ecb_decrypt()]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_ecb_encrypt()]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_generate_iv()]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[esp_spp_cb_event_t]] - code
- [[esp_spp_cb_param_t]] - code
- [[packet.h]] - code - archive/m25_wheel_rfcomm/packet.h
- [[packet_decode()]] - code - archive/m25_wheel_rfcomm/packet.h
- [[packet_encode_ack()]] - code - archive/m25_wheel_rfcomm/packet.h
- [[packet_encode_response()]] - code - archive/m25_wheel_rfcomm/packet.h
- [[proto_crc16()]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[proto_frame_build()]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[proto_frame_parse()]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[proto_print_hex()]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[proto_stuff()]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[proto_unstuff()]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[protocol.h]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[rfcomm_check_events()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_connected()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_init()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_on_connect()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_on_disconnect()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_poll()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_send()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_server_channel()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[rfcomm_server_channel_known()]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[safety.h]] - code - archive/m25_wheel_rfcomm/safety.h
- [[safety_battery_interval()]] - code - archive/m25_wheel_rfcomm/safety.h
- [[safety_battery_tick()]] - code - archive/m25_wheel_rfcomm/safety.h
- [[safety_button_poll()]] - code - archive/m25_wheel_rfcomm/safety.h
- [[safety_cmd_timeout()]] - code - archive/m25_wheel_rfcomm/safety.h
- [[state.h]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_apply_timeout()]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_cmd_timed_out()]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_drain_battery()]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_init()]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_print()]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_simulate_rotation()]] - code - archive/m25_wheel_rfcomm/state.h
- [[transport_rfcomm.h]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/RFCOMM_Command_Crypto
SORT file.name ASC
```

## Connections to other communities
- 10 edges to [[_COMMUNITY_RFCOMM Emulator Buzzer]]
- 1 edge to [[_COMMUNITY_RFCOMM Runtime Wheel Config]]
- 1 edge to [[_COMMUNITY_TX SPP Log Comparison Tool]]

## Top bridge nodes
- [[config.h]] - degree 11, connects to 3 communities
- [[transport_rfcomm.h]] - degree 16, connects to 1 community
- [[state.h]] - degree 11, connects to 1 community
- [[state_simulate_rotation()]] - degree 4, connects to 1 community
- [[state_print()]] - degree 3, connects to 1 community