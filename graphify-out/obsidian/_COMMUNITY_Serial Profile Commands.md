---
type: community
members: 11
---

# Serial Profile Commands

**Members:** 11 nodes

## Members
- [[MapperConfig_1]] - code
- [[SerialContext]] - code - serial_commands.h
- [[Supervisor]] - code - serial_commands.h
- [[SystemState]] - code
- [[_scApplyProfile()]] - code - serial_commands.h
- [[assistLevel_1]] - code - serial_commands.h
- [[hillHoldOn]] - code - serial_commands.h
- [[mapper_1]] - code - serial_commands.h
- [[mapperCfg]] - code - serial_commands.h
- [[state]] - code - serial_commands.h
- [[supervisor_1]] - code - serial_commands.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Serial_Profile_Commands
SORT file.name ASC
```

## Connections to other communities
- 5 edges to [[_COMMUNITY_Serial Command Output Helpers]]
- 2 edges to [[_COMMUNITY_BLE Diagnostics and Tx Stats]]
- 1 edge to [[_COMMUNITY_BLE GATT Client Core]]
- 1 edge to [[_COMMUNITY_Wheel Mode and Connect Handling]]
- 1 edge to [[_COMMUNITY_Joystick to Command Mapper]]
- 1 edge to [[_COMMUNITY_BLE Status Query Getters]]

## Top bridge nodes
- [[SerialContext]] - degree 16, connects to 4 communities
- [[_scApplyProfile()]] - degree 5, connects to 4 communities
- [[Supervisor]] - degree 2, connects to 1 community