---
type: community
members: 61
---

# Configuration Priority & Feature Flags

**Members:** 61 nodes

## Members
- [[AUTO_ARM_ON_CONNECT flag]] - code - device_config.h
- [[Configuration priority NVS  .env build flags  device_config.h defaults]] - document - CLAUDE.md
- [[ENCRYPTION_KEY_LEFTRIGHT compiled-in default AES keys]] - code - device_config.h
- [[Feature flags documentation table]] - document - CLAUDE.md
- [[Force-include override of CONFIG_BT_HFP_ENABLE to suppress unwanted BT pragma warning]] - rationale - suppress_bt_pragma.h
- [[LogLevel_1]] - code - serial_commands.h
- [[MappersetConfig]] - code - mapper.h
- [[NO_DEADMAN_HARDWARE joystick-only trigger, no deadman button (safety bypass - remove once wired)]] - rationale - device_config.h
- [[NO_JOYSTICK flag (bench testing without ADC hardware)]] - code - device_config.h
- [[README quick start (credentials + buildflash)]] - document - README.md
- [[ROADMAP 2.6 persist joystick full-range calibration to NVS (marked pending)]] - document - ROADMAP.md
- [[SerialContext]] - code - serial_commands.h
- [[Supervisor()_1]] - code - supervisor.h
- [[SupervisorState_1]] - code - types.h
- [[WHEEL_MODE (DUALLEFT_ONLYRIGHT_ONLY) compile-time default]] - code - device_config.h
- [[WheelConnState_t (per-wheel connection state)]] - code - m25_ble.h
- [[_scApplyProfile()]] - code - serial_commands.h
- [[_scCmdDecorateMsg()]] - code - serial_commands.h
- [[_scCmdOut()]] - code - serial_commands.h
- [[_scCmdOutf()]] - code - serial_commands.h
- [[_scCmdTagFromMsg()]] - code - serial_commands.h
- [[_scDispatch()]] - code - serial_commands.h
- [[_scLevelName()]] - code - serial_commands.h
- [[_scParseHex16()]] - code - serial_commands.h
- [[_scPrintBle()]] - code - serial_commands.h
- [[_scPrintHelp()]] - code - serial_commands.h
- [[_scPrintJs()]] - code - serial_commands.h
- [[_scPrintLoggerSettings()]] - code - serial_commands.h
- [[_scPrintStatus()]] - code - serial_commands.h
- [[_scPrintSysInfo()]] - code - serial_commands.h
- [[_scPrintWheels()]] - code - serial_commands.h
- [[_scTryGetTagByName()]] - code - serial_commands.h
- [[_scTryParseLevel()]] - code - serial_commands.h
- [[class_4]] - code - supervisor.h
- [[joystickRecalibrate()]] - code - joystick.h
- [[load_env.py (PlatformIO pre-build .env injector)]] - code - load_env.py
- [[m25_bluetooth.py (external, SPP servicecharacteristic UUID reference)]] - concept - m25_ble.h
- [[nvsClearAll()]] - code - nvs_config.h
- [[nvsLoadActiveProfile()]] - code - nvs_config.h
- [[nvsLoadAssistLevel()]] - code - nvs_config.h
- [[nvsLoadJsRange()]] - code - nvs_config.h
- [[nvsLoadKey()]] - code - nvs_config.h
- [[nvsLoadMac()]] - code - nvs_config.h
- [[nvsLoadMaxSpeed()]] - code - nvs_config.h
- [[nvsLoadWheelMode()]] - code - nvs_config.h
- [[nvsPrintAll()]] - code - nvs_config.h
- [[nvsSaveActiveProfile()]] - code - nvs_config.h
- [[nvsSaveAssistLevel()]] - code - nvs_config.h
- [[nvsSaveJsRange()]] - code - nvs_config.h
- [[nvsSaveKey()]] - code - nvs_config.h
- [[nvsSaveMac()]] - code - nvs_config.h
- [[nvsSaveMaxSpeed()]] - code - nvs_config.h
- [[nvsSaveWheelMode()]] - code - nvs_config.h
- [[nvs_config.h_1]] - code - nvs_config.h
- [[requestReconnect()]] - code - supervisor.cpp
- [[serialInit()]] - code - serial_commands.h
- [[serialTick()]] - code - serial_commands.h
- [[serial_commands.h_1]] - code - serial_commands.h
- [[supervisor.h]] - code - supervisor.h
- [[supervisorStateToString()]] - code - types.h
- [[types.h]] - code - types.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/Configuration_Priority__Feature_Flags
SORT file.name ASC
```

## Connections to other communities
- 15 edges to [[_COMMUNITY_Buttons & Buzzer Input]]
- 4 edges to [[_COMMUNITY_BLE Motor Command Task]]
- 4 edges to [[_COMMUNITY_BLE Threading & Connection State]]
- 3 edges to [[_COMMUNITY_LED & Buzzer Pattern Control]]
- 2 edges to [[_COMMUNITY_BLE Wheel Getters & Diagnostics]]
- 2 edges to [[_COMMUNITY_BLE Disconnect & Link State]]
- 2 edges to [[_COMMUNITY_Mapper & Supervisor Safety Pipeline]]
- 1 edge to [[_COMMUNITY_BLE Response Frame Parsing]]

## Top bridge nodes
- [[_scDispatch()]] - degree 46, connects to 4 communities
- [[_scPrintStatus()]] - degree 9, connects to 3 communities
- [[serial_commands.h_1]] - degree 25, connects to 2 communities
- [[nvsPrintAll()]] - degree 7, connects to 2 communities
- [[nvs_config.h_1]] - degree 18, connects to 1 community