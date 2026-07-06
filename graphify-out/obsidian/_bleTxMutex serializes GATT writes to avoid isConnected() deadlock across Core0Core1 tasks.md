---
source_file: "m25_ble.cpp"
type: "rationale"
community: "BLE Threading & Connection State"
tags:
  - graphify/rationale
  - graphify/INFERRED
  - community/BLE_Threading__Connection_State
---

# _bleTxMutex: serializes GATT writes to avoid isConnected() deadlock across Core0/Core1 tasks

## Connections
- [[_connectTaskBody()]] - `conceptually_related_to` [INFERRED]

#graphify/rationale #graphify/INFERRED #community/BLE_Threading__Connection_State