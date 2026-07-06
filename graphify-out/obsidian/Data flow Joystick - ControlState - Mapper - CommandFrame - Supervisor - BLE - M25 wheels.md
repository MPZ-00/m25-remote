---
source_file: "CLAUDE.md"
type: "document"
community: "Mapper & Supervisor Safety Pipeline"
tags:
  - graphify/document
  - graphify/EXTRACTED
  - community/Mapper__Supervisor_Safety_Pipeline
---

# Data flow: Joystick -> ControlState -> Mapper -> CommandFrame -> Supervisor -> BLE -> M25 wheels

## Connections
- [[CommandFrame struct]] - `references` [EXTRACTED]
- [[Mapper()]] - `references` [EXTRACTED]
- [[Supervisor (state machine + safety orchestrator class)]] - `references` [EXTRACTED]

#graphify/document #graphify/EXTRACTED #community/Mapper__Supervisor_Safety_Pipeline