---
source_file: "archive/m25_wheel_rfcomm/packet.h"
type: "code"
community: "RFCOMM Transport & Packet Codec (archive)"
location: "46"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/RFCOMM_Transport__Packet_Codec_archive
---

# packet_decode(raw, rawLen, key, spp, sppLen)

## Connections
- [[crypto_cbc_decrypt(key, iv, in, len, out)]] - `calls` [EXTRACTED]
- [[crypto_ecb_decrypt(key, in, out)]] - `calls` [EXTRACTED]
- [[m25_wheel_rfcomm README (fake M25 wheel RFCOMM simulator)]] - `references` [EXTRACTED]
- [[proto_frame_parse(in, inLen, payload, payloadLen)]] - `calls` [EXTRACTED]
- [[struct WheelState]] - `shares_data_with` [AMBIGUOUS]

#graphify/code #graphify/EXTRACTED #community/RFCOMM_Transport__Packet_Codec_archive