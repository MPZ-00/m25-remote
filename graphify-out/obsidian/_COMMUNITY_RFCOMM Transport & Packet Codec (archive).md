---
type: community
members: 30
---

# RFCOMM Transport & Packet Codec (archive)

**Members:** 30 nodes

## Members
- [[_packet_encode_spp(spp, sppLen, key, out)]] - code - archive/m25_wheel_rfcomm/packet.h
- [[_rfcomm_spp_callback(event, param)]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[_rfcomm_try_parse(out, outLen)]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[ble_init(name, serviceUUID, txUUID, rxUUID)]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[buzzer_init()]] - code - archive/m25_wheel_rfcomm/buzzer.h
- [[class _BleRxCB]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[class _BleServerCB]] - code - archive/m25_wheel_rfcomm/transport_ble.h
- [[command_apply(spp, sppLen, state, debug)]] - code - archive/m25_wheel_rfcomm/command.h
- [[crypto_cbc_decrypt(key, iv, in, len, out)]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_cbc_encrypt(key, iv, in, len, out)]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_ecb_decrypt(key, in, out)]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_ecb_encrypt(key, in, out)]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[crypto_generate_iv(iv)]] - code - archive/m25_wheel_rfcomm/crypto.h
- [[m25_wheel_rfcomm README (fake M25 wheel RFCOMM simulator)]] - document - archive/m25_wheel_rfcomm/README.md
- [[packet_decode(raw, rawLen, key, spp, sppLen)]] - code - archive/m25_wheel_rfcomm/packet.h
- [[packet_encode_ack(state, key, out)]] - code - archive/m25_wheel_rfcomm/packet.h
- [[packet_encode_response(reqService, reqParam, state, key, out)]] - code - archive/m25_wheel_rfcomm/packet.h
- [[proto_crc16(data, len)]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[proto_frame_build(payload, payloadLen, out)]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[proto_frame_parse(in, inLen, payload, payloadLen)]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[proto_stuff(in, inLen, out)]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[proto_unstuff(in, inLen, out)]] - code - archive/m25_wheel_rfcomm/protocol.h
- [[rfcomm_init(name)]] - code - archive/m25_wheel_rfcomm/transport_rfcomm.h
- [[safety_cmd_timeout(state)]] - code - archive/m25_wheel_rfcomm/safety.h
- [[state_apply_timeout(state)]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_cmd_timed_out(state)]] - code - archive/m25_wheel_rfcomm/state.h
- [[state_simulate_rotation(state, count)]] - code - archive/m25_wheel_rfcomm/state.h
- [[struct CliActions]] - code - archive/m25_wheel_rfcomm/cli.h
- [[struct WheelRuntimeConfig]] - code - archive/m25_wheel_rfcomm/nvs_config.h
- [[struct WheelState]] - code - archive/m25_wheel_rfcomm/state.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/RFCOMM_Transport__Packet_Codec_archive
SORT file.name ASC
```

## Connections to other communities
- 1 edge to [[_COMMUNITY_Buzzer Control (archive)]]
- 1 edge to [[_COMMUNITY_Fake Wheel State & Commands (archive)]]
- 1 edge to [[_COMMUNITY_LED Status Indicators (archive)]]
- 1 edge to [[_COMMUNITY_CLI Debug Printing (archive)]]
- 1 edge to [[_COMMUNITY_RFCOMM Transport Event Handling (archive)]]
- 1 edge to [[_COMMUNITY_Code Generator Scripts]]

## Top bridge nodes
- [[m25_wheel_rfcomm README (fake M25 wheel RFCOMM simulator)]] - degree 13, connects to 4 communities
- [[buzzer_init()]] - degree 2, connects to 1 community
- [[_rfcomm_try_parse(out, outLen)]] - degree 2, connects to 1 community