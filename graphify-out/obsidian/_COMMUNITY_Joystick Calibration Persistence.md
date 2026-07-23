---
type: community
members: 3
---

# Joystick Calibration Persistence

**Members:** 3 nodes

## Members
- [[ROADMAP 2.6 persist joystick full-range calibration to NVS (marked pending)]] - document - ROADMAP.md
- [[joystickRecalibrate()]] - code - joystick.h
- [[nvsSaveJsRange()]] - code - nvs_config.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Joystick_Calibration_Persistence
SORT file.name ASC
```

## Connections to other communities
- 2 edges to [[_COMMUNITY_BLE Diagnostics and Tx Stats]]
- 1 edge to [[_COMMUNITY_Bluedroid GAP and Logger]]
- 1 edge to [[_COMMUNITY_Joystick ADC Input]]

## Top bridge nodes
- [[joystickRecalibrate()]] - degree 3, connects to 2 communities
- [[nvsSaveJsRange()]] - degree 3, connects to 1 community