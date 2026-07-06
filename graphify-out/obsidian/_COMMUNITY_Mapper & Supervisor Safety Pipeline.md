---
type: community
members: 32
---

# Mapper & Supervisor Safety Pipeline

**Members:** 32 nodes

## Members
- [[CommandFrame]] - code - mapper.cpp
- [[CommandFrame struct]] - code - types.h
- [[ControlState]] - code - mapper.cpp
- [[ControlState struct]] - code - types.h
- [[Data flow Joystick - ControlState - Mapper - CommandFrame - Supervisor - BLE - M25 wheels]] - document - CLAUDE.md
- [[Mapper Safety Rule 1 deadman switch must be pressed or command forced to stop]] - rationale - mapper.cpp
- [[Mapper()]] - code - mapper.h
- [[MapperConfig struct]] - code - types.h
- [[README state machine diagram]] - document - README.md
- [[ROADMAP Phase 1 Core safety (done)]] - document - ROADMAP.md
- [[Safety-critical code guidance (mapper.h.cpp, supervisor.h.cpp)]] - document - CLAUDE.md
- [[SerialContext struct]] - code - serial_commands.h
- [[Supervisor (state machine + safety orchestrator class)]] - code - supervisor.h
- [[Supervisor state machine documentation]] - document - CLAUDE.md
- [[SupervisorConfig struct]] - code - types.h
- [[SupervisorState enum]] - code - types.h
- [[SystemState enum (legacy, serial-command compatibility)]] - code - device_config.h
- [[VehicleState struct]] - code - types.h
- [[applyCurve()]] - code - mapper.cpp
- [[applyDeadzone()]] - code - mapper.cpp
- [[applyRamp()]] - code - mapper.cpp
- [[buildFlags()]] - code - mapper.cpp
- [[clamp()]] - code - mapper.cpp
- [[class_3]] - code - mapper.h
- [[coremapper.py (external Python reference implementation)]] - concept - mapper.h
- [[coresupervisor.py (external Python reference implementation)]] - concept - supervisor.h
- [[coretypes.py (external Python reference implementation)]] - concept - types.h
- [[differentialDrive()]] - code - mapper.cpp
- [[map()]] - code - mapper.cpp
- [[mapper.cpp]] - code - mapper.cpp
- [[mapper.h]] - code - mapper.h
- [[reset()]] - code - mapper.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Mapper__Supervisor_Safety_Pipeline
SORT file.name ASC
```

## Connections to other communities
- 3 edges to [[_COMMUNITY_BLE Threading & Connection State]]
- 2 edges to [[_COMMUNITY_Buttons & Buzzer Input]]
- 2 edges to [[_COMMUNITY_Configuration Priority & Feature Flags]]

## Top bridge nodes
- [[map()]] - degree 13, connects to 1 community
- [[Supervisor (state machine + safety orchestrator class)]] - degree 10, connects to 1 community
- [[ControlState struct]] - degree 4, connects to 1 community
- [[differentialDrive()]] - degree 3, connects to 1 community
- [[Safety-critical code guidance (mapper.h.cpp, supervisor.h.cpp)]] - degree 3, connects to 1 community