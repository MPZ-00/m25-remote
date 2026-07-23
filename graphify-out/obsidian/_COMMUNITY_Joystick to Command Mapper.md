---
type: community
members: 30
---

# Joystick to Command Mapper

**Members:** 30 nodes

## Members
- [[.Mapper()]] - code - mapper.h
- [[.getLastCommand()]] - code - mapper.h
- [[.isLowBatteryLimited()]] - code - mapper.h
- [[.setConfig()]] - code - mapper.h
- [[.setLowBatteryLimit()]] - code - mapper.h
- [[CommandFrame]] - code
- [[CommandFrame_1]] - code
- [[ControlState]] - code
- [[Mapper]] - code - mapper.h
- [[MapperConfig]] - code
- [[ROADMAP Phase 1 Core safety (done)]] - document - ROADMAP.md
- [[SupervisorSupervisor()]] - code - supervisor.cpp
- [[SupervisorConfig]] - code
- [[_config]] - code - mapper.h
- [[_hasLastCommand]] - code - mapper.h
- [[_lastCommand]] - code - mapper.h
- [[_lastTime]] - code - mapper.h
- [[_lowBatteryLimit]] - code - mapper.h
- [[applyCurve]] - code - mapper.h
- [[applyDeadzone]] - code - mapper.h
- [[applyRamp]] - code - mapper.h
- [[buildFlags]] - code - mapper.h
- [[clamp]] - code - mapper.h
- [[differentialDrive]] - code - mapper.h
- [[map]] - code - mapper.h
- [[mapper.cpp]] - code - mapper.cpp
- [[mapper.h]] - code - mapper.h
- [[reset]] - code - mapper.h
- [[supervisor.h]] - code - supervisor.h
- [[types.h]] - code - types.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Joystick_to_Command_Mapper
SORT file.name ASC
```

## Connections to other communities
- 3 edges to [[_COMMUNITY_Safety Supervisor State]]
- 2 edges to [[_COMMUNITY_Serial Command Output Helpers]]
- 2 edges to [[_COMMUNITY_Supervisor Watchdog Handlers]]
- 1 edge to [[_COMMUNITY_M25 BLE Response Parsing]]
- 1 edge to [[_COMMUNITY_Serial Profile Commands]]
- 1 edge to [[_COMMUNITY_BLE Status Query Getters]]

## Top bridge nodes
- [[supervisor.h]] - degree 5, connects to 3 communities
- [[Mapper]] - degree 25, connects to 2 communities
- [[types.h]] - degree 4, connects to 2 communities
- [[mapper.h]] - degree 5, connects to 1 community
- [[SupervisorSupervisor()]] - degree 3, connects to 1 community