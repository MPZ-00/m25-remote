---
type: community
members: 7
---

# LED Status Indicators (archive)

**Members:** 7 nodes

## Members
- [[led.h]] - code - archive/m25_wheel_rfcomm/led.h
- [[led_init()]] - code - archive/m25_wheel_rfcomm/led.h
- [[led_set_advertising()]] - code - archive/m25_wheel_rfcomm/led.h
- [[led_set_connected()]] - code - archive/m25_wheel_rfcomm/led.h
- [[led_set_speed_indicator()]] - code - archive/m25_wheel_rfcomm/led.h
- [[led_show_battery()]] - code - archive/m25_wheel_rfcomm/led.h
- [[led_update()]] - code - archive/m25_wheel_rfcomm/led.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/LED_Status_Indicators_archive
SORT file.name ASC
```

## Connections to other communities
- 2 edges to [[_COMMUNITY_CLI Debug Printing (archive)]]
- 1 edge to [[_COMMUNITY_Fake Wheel State & Commands (archive)]]
- 1 edge to [[_COMMUNITY_RFCOMM Transport & Packet Codec (archive)]]

## Top bridge nodes
- [[led.h]] - degree 8, connects to 2 communities
- [[led_init()]] - degree 2, connects to 1 community
- [[led_show_battery()]] - degree 2, connects to 1 community