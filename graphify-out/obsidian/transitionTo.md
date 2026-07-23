---
source_file: "supervisor.h"
type: "code"
community: "Supervisor Arm Transitions"
location: "L254"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/Supervisor_Arm_Transitions
---

# transitionTo

## Connections
- [[Supervisor_2]] - `defines` [EXTRACTED]
- [[SupervisorState]] - `references` [EXTRACTED]
- [[_triggerPartialReconnect]] - `calls` [INFERRED]
- [[bleAnyConnected()]] - `calls` [INFERRED]
- [[bleResetMotorWriteOk()]] - `calls` [INFERRED]
- [[bleResetNotifyTimers()]] - `calls` [INFERRED]
- [[bleSendMotorCommand()]] - `calls` [INFERRED]
- [[checkWatchdogs]] - `calls` [INFERRED]
- [[enterFailsafe]] - `calls` [INFERRED]
- [[handleConnecting]] - `calls` [INFERRED]
- [[handleStopRequest]] - `calls` [INFERRED]
- [[notifyStateCallbacks]] - `calls` [INFERRED]
- [[processInput]] - `calls` [INFERRED]
- [[requestArm]] - `calls` [INFERRED]
- [[requestConnect]] - `calls` [INFERRED]
- [[requestDisarm]] - `calls` [INFERRED]
- [[supervisor.cpp]] - `contains` [EXTRACTED]
- [[supervisorStateToString()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/Supervisor_Arm_Transitions