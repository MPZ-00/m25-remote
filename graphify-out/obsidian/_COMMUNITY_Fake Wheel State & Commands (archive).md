---
type: community
members: 40
---

# Fake Wheel State & Commands (archive)

**Members:** 40 nodes

## Members
- [[CmdResult]] - code - archive/m25_wheel_rfcomm/command.h
- [[WheelState_1]] - code - archive/m25_wheel_rfcomm/command.h
- [[WheelState_2]] - code - archive/m25_wheel_rfcomm/packet.h
- [[WheelState_3]] - code - archive/m25_wheel_rfcomm/safety.h
- [[WheelState_4]] - code - archive/m25_wheel_rfcomm/state.h
- [[_packet_encode_spp()]] - code - archive/m25_wheel_rfcomm/packet.h
- [[command.h]] - code - archive/m25_wheel_rfcomm/command.h
- [[command_apply()]] - code - archive/m25_wheel_rfcomm/command.h
- [[config.h]] - code - archive/m25_wheel_rfcomm/config.h
- [[crypto.h]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_cbc_decrypt()]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_cbc_encrypt()]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_ecb_decrypt()]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_ecb_encrypt()]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_generate_iv()]] - code - archive/m25_wheel_rfcomm/crypto.h
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
- [[safety.h]] - code - archive/m25_wheel_rfcomm/safety.h
- [[safety_battery_interval()]] - code - archive/m25_wheel_rfcomm/safety.h
- [[safety_battery_tick()]] - code - archive/m25_wheel_rfcomm/safety.h
- [[safety_button_poll()]] - code - archive/m25_wheel_rfcomm/safety.h
- [[safety_button_poll(advertise_fn)]] - code - archive/m25_wheel_rfcomm/safety.h
- [[safety_cmd_timeout()]] - code - archive/m25_wheel_rfcomm/safety.h
- [[state.h]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_apply_timeout()]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_cmd_timed_out()]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_drain_battery()]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_init()]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_print()]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_simulate_rotation()]] - code - archive/m25_wheel_rfcomm/state.h
- [[struct WheelStaticProfile]] - code - archive/m25_wheel_rfcomm/nvs_config.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Fake_Wheel_State__Commands_archive
SORT file.name ASC
```

## Connections to other communities
- 4 edges to [[_COMMUNITY_CLI Debug Printing (archive)]]
- 3 edges to [[_COMMUNITY_RFCOMM Transport Event Handling (archive)]]
- 1 edge to [[_COMMUNITY_Buzzer Control (archive)]]
- 1 edge to [[_COMMUNITY_LED Status Indicators (archive)]]
- 1 edge to [[_COMMUNITY_load_env.py Git Helpers (archive)]]
- 1 edge to [[_COMMUNITY_Wheel Runtime Config CLI (archive)]]
- 1 edge to [[_COMMUNITY_RFCOMM Transport & Packet Codec (archive)]]
- 1 edge to [[_COMMUNITY_BLE Transport Event Handling (archive)]]

## Top bridge nodes
- [[config.h]] - degree 14, connects to 8 communities
- [[state.h]] - degree 11, connects to 1 community
- [[protocol.h]] - degree 9, connects to 1 community
- [[proto_crc16()]] - degree 4, connects to 1 community
- [[state_simulate_rotation()]] - degree 4, connects to 1 community