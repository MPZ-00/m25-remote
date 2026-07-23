---
source_file: "supervisor.h"
type: "code"
community: "Failsafe and Vehicle State"
location: "L255"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/Failsafe_and_Vehicle_State
---

# enterFailsafe

## Connections
- [[Supervisor_2]] - `defines` [EXTRACTED]
- [[bleAnyConnected()]] - `calls` [INFERRED]
- [[checkWatchdogs]] - `calls` [INFERRED]
- [[notifyConnectionChange]] - `calls` [INFERRED]
- [[requestEmergencyStop]] - `calls` [INFERRED]
- [[sendStop]] - `calls` [INFERRED]
- [[supervisor.cpp]] - `contains` [EXTRACTED]
- [[transitionTo]] - `calls` [INFERRED]
- [[updateVehicleState]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/Failsafe_and_Vehicle_State