---
source_file: "mapper.h"
type: "code"
community: "Joystick to Command Mapper"
location: "L54"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/Joystick_to_Command_Mapper
---

# map

## Connections
- [[CommandFrame]] - `references` [EXTRACTED]
- [[ControlState]] - `references` [EXTRACTED]
- [[Mapper]] - `defines` [EXTRACTED]
- [[applyCurve]] - `calls` [INFERRED]
- [[applyDeadzone]] - `calls` [INFERRED]
- [[applyRamp]] - `calls` [INFERRED]
- [[buildFlags]] - `calls` [INFERRED]
- [[clamp]] - `calls` [INFERRED]
- [[differentialDrive]] - `calls` [INFERRED]
- [[mapper.cpp]] - `contains` [EXTRACTED]

#graphify/code #graphify/INFERRED #community/Joystick_to_Command_Mapper