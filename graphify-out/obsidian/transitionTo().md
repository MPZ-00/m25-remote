---
source_file: "supervisor.cpp"
type: "code"
community: "BLE Threading & Connection State"
location: "L745"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/BLE_Threading__Connection_State
---

# transitionTo()

## Connections
- [[SupervisorState]] - `references` [EXTRACTED]
- [[_triggerPartialReconnect()]] - `calls` [EXTRACTED]
- [[bleAnyConnected()]] - `calls` [INFERRED]
- [[bleResetMotorWriteOk()]] - `calls` [INFERRED]
- [[bleResetNotifyTimers()]] - `calls` [INFERRED]
- [[bleSendMotorCommand()]] - `calls` [EXTRACTED]
- [[checkWatchdogs()]] - `calls` [EXTRACTED]
- [[enterFailsafe()]] - `calls` [EXTRACTED]
- [[handleConnecting()]] - `calls` [EXTRACTED]
- [[handleStopRequest()]] - `calls` [EXTRACTED]
- [[notifyStateCallbacks()]] - `calls` [EXTRACTED]
- [[processInput()]] - `calls` [EXTRACTED]
- [[requestArm()]] - `calls` [EXTRACTED]
- [[requestConnect()]] - `calls` [EXTRACTED]
- [[requestDisarm()]] - `calls` [EXTRACTED]
- [[reset()]] - `calls` [EXTRACTED]
- [[supervisor.cpp]] - `contains` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/BLE_Threading__Connection_State