---
source_file: "archive/m25_wheel_rfcomm/packet.h"
type: "code"
community: "RFCOMM Transport & Packet Codec (archive)"
location: "125"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/RFCOMM_Transport__Packet_Codec_archive
---

# packet_encode_response(reqService, reqParam, state, key, out)

## Connections
- [[_packet_encode_spp(spp, sppLen, key, out)]] - `calls` [EXTRACTED]
- [[command_apply(spp, sppLen, state, debug)]] - `shares_data_with` [EXTRACTED]
- [[packet_encode_ack(state, key, out)]] - `calls` [EXTRACTED]
- [[struct WheelState]] - `shares_data_with` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/RFCOMM_Transport__Packet_Codec_archive