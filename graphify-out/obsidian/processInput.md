---
source_file: "supervisor.h"
type: "code"
community: "Supervisor Command Send Loop"
location: "L104"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/Supervisor_Command_Send_Loop
---

# processInput

## Connections
- [[ControlState_1]] - `references` [EXTRACTED]
- [[Supervisor_2]] - `defines` [EXTRACTED]
- [[sendCommand]] - `calls` [INFERRED]
- [[sendStop]] - `calls` [INFERRED]
- [[supervisor.cpp]] - `contains` [EXTRACTED]
- [[transitionTo]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/Supervisor_Command_Send_Loop