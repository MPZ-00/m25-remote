---
source_file: "archive/m25_wheel_rfcomm/protocol.h"
type: "code"
community: "RFCOMM Transport & Packet Codec (archive)"
location: "46"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/RFCOMM_Transport__Packet_Codec_archive
---

# proto_crc16(data, len)

## Connections
- [[_rfcomm_try_parse(out, outLen)]] - `calls` [EXTRACTED]
- [[proto_frame_build(payload, payloadLen, out)]] - `calls` [EXTRACTED]
- [[proto_frame_parse(in, inLen, payload, payloadLen)]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/RFCOMM_Transport__Packet_Codec_archive