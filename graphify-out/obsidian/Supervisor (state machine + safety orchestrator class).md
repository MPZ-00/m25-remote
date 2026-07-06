---
source_file: "supervisor.h"
type: "code"
community: "Mapper & Supervisor Safety Pipeline"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/Mapper__Supervisor_Safety_Pipeline
---

# Supervisor (state machine + safety orchestrator class)

## Connections
- [[Data flow Joystick - ControlState - Mapper - CommandFrame - Supervisor - BLE - M25 wheels]] - `references` [EXTRACTED]
- [[Mapper()]] - `shares_data_with` [EXTRACTED]
- [[ROADMAP Phase 1 Core safety (done)]] - `references` [EXTRACTED]
- [[Safety-critical code guidance (mapper.h.cpp, supervisor.h.cpp)]] - `references` [EXTRACTED]
- [[SerialContext struct]] - `shares_data_with` [EXTRACTED]
- [[SupervisorConfig struct]] - `shares_data_with` [EXTRACTED]
- [[SupervisorState enum]] - `shares_data_with` [EXTRACTED]
- [[VehicleState struct]] - `shares_data_with` [EXTRACTED]
- [[_scPrintStatus()]] - `references` [EXTRACTED]
- [[coresupervisor.py (external Python reference implementation)]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/Mapper__Supervisor_Safety_Pipeline