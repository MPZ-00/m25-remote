---
source_file: "archive/m25_wheel_rfcomm/protocol.h"
type: "code"
community: "RFCOMM Transport & Packet Codec (archive)"
location: "140"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/RFCOMM_Transport__Packet_Codec_archive
---

# proto_frame_build(payload, payloadLen, out)

## Connections
- [[_packet_encode_spp(spp, sppLen, key, out)]] - `calls` [EXTRACTED]
- [[proto_crc16(data, len)]] - `calls` [EXTRACTED]
- [[proto_stuff(in, inLen, out)]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/RFCOMM_Transport__Packet_Codec_archive