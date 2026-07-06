---
source_file: "archive/m25_wheel_rfcomm/packet.h"
type: "code"
community: "RFCOMM Transport & Packet Codec (archive)"
location: "84"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/RFCOMM_Transport__Packet_Codec_archive
---

# _packet_encode_spp(spp, sppLen, key, out)

## Connections
- [[crypto_cbc_encrypt(key, iv, in, len, out)]] - `calls` [EXTRACTED]
- [[crypto_ecb_encrypt(key, in, out)]] - `calls` [EXTRACTED]
- [[crypto_generate_iv(iv)]] - `calls` [EXTRACTED]
- [[packet_encode_ack(state, key, out)]] - `calls` [EXTRACTED]
- [[packet_encode_response(reqService, reqParam, state, key, out)]] - `calls` [EXTRACTED]
- [[proto_frame_build(payload, payloadLen, out)]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/RFCOMM_Transport__Packet_Codec_archive