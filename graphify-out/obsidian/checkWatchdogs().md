---
source_file: "supervisor.cpp"
type: "code"
community: "BLE Threading & Connection State"
location: "L649"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/BLE_Threading__Connection_State
---

# checkWatchdogs()

## Connections
- [[BLE threading model loop() on Core 1, motor writes on Core 0]] - `references` [EXTRACTED]
- [[_wheelActive()]] - `calls` [INFERRED]
- [[bleGetLastNotifyMs()]] - `calls` [INFERRED]
- [[bleIsConnected()]] - `calls` [INFERRED]
- [[bleLastMotorWriteOk()]] - `calls` [EXTRACTED]
- [[enterFailsafe()]] - `calls` [EXTRACTED]
- [[logForced()]] - `calls` [EXTRACTED]
- [[sendHeartbeat()]] - `calls` [EXTRACTED]
- [[supervisor.cpp]] - `contains` [EXTRACTED]
- [[transitionTo()]] - `calls` [EXTRACTED]
- [[update()]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/BLE_Threading__Connection_State