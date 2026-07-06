---
source_file: "supervisor.cpp"
type: "code"
community: "BLE Threading & Connection State"
location: "L326"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/BLE_Threading__Connection_State
---

# _connectTaskBody()

## Connections
- [[_bleTxMutex serializes GATT writes to avoid isConnected() deadlock across Core0Core1 tasks]] - `conceptually_related_to` [INFERRED]
- [[_sConnectTask()]] - `calls` [EXTRACTED]
- [[_wheelActive()]] - `calls` [INFERRED]
- [[bleConnectWheel()]] - `calls` [EXTRACTED]
- [[bleIsConnected()]] - `calls` [INFERRED]
- [[bleResetWheel()]] - `calls` [EXTRACTED]
- [[supervisor.cpp]] - `contains` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/BLE_Threading__Connection_State