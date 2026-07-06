---
source_file: "archive/m25_wheel_rfcomm/state.h"
type: "code"
community: "RFCOMM Transport & Packet Codec (archive)"
location: "18"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/RFCOMM_Transport__Packet_Codec_archive
---

# struct WheelState

## Connections
- [[command_apply(spp, sppLen, state, debug)]] - `shares_data_with` [EXTRACTED]
- [[m25_wheel_rfcomm README (fake M25 wheel RFCOMM simulator)]] - `references` [EXTRACTED]
- [[packet_decode(raw, rawLen, key, spp, sppLen)]] - `shares_data_with` [AMBIGUOUS]
- [[packet_encode_ack(state, key, out)]] - `shares_data_with` [EXTRACTED]
- [[packet_encode_response(reqService, reqParam, state, key, out)]] - `shares_data_with` [EXTRACTED]
- [[struct WheelRuntimeConfig]] - `conceptually_related_to` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/RFCOMM_Transport__Packet_Codec_archive