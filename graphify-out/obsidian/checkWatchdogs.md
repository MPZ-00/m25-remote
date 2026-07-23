---
source_file: "supervisor.h"
type: "code"
community: "Supervisor Command Send Loop"
location: "L237"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/Supervisor_Command_Send_Loop
---

# checkWatchdogs

## Connections
- [[Supervisor_2]] - `defines` [EXTRACTED]
- [[_wheelActive()]] - `calls` [INFERRED]
- [[bleGetLastNotifyMs()]] - `calls` [INFERRED]
- [[bleIsConnected()]] - `calls` [INFERRED]
- [[bleLastMotorWriteOk()]] - `calls` [INFERRED]
- [[enterFailsafe]] - `calls` [INFERRED]
- [[sendHeartbeat]] - `calls` [INFERRED]
- [[supervisor.cpp]] - `contains` [EXTRACTED]
- [[transitionTo]] - `calls` [INFERRED]
- [[update]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/Supervisor_Command_Send_Loop