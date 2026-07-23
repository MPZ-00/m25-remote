# Graph Report - .  (2026-07-23)

## Corpus Check
- 76 files · ~75,940 words
- Verdict: corpus is large enough that graph structure adds value.

## Summary
- 775 nodes · 1392 edges · 58 communities (43 shown, 15 thin omitted)
- Extraction: 83% EXTRACTED · 17% INFERRED · 0% AMBIGUOUS · INFERRED: 236 edges (avg confidence: 0.8)
- Token cost: 0 input · 49,758 output

## Community Hubs (Navigation)
- BLE GATT Client Core
- RFCOMM Emulator Buzzer
- RFCOMM Command Crypto
- Safety Supervisor State
- BLE Scanner and Connect
- Motor Task and Control State
- BLE Diagnostics and Tx Stats
- Buzzer Control and Debug Flags
- Joystick to Command Mapper
- Wheel Connection State
- Bluedroid GAP and Logger
- TX SPP Log Comparison Tool
- Button Input Handling
- Protocol Design Rationale
- Supervisor Watchdog Handlers
- Test Harness and Scripts
- RFCOMM Runtime Wheel Config
- BLE Command Stats Struct
- Serial Command Output Helpers
- Joystick ADC Input
- LED Status Indicators
- M25 BLE Response Parsing
- Serial Profile Commands
- Web Joystick UI Script
- BLE Status Query Getters
- M25 Protocol Response Header
- Supervisor Command Send Loop
- Code Generators and Toolkit
- Failsafe and Vehicle State
- Drive Profile Lookup
- Wheel Mode and Connect Handling
- BLE Record Entry Struct
- Supervisor Arm Transitions
- BLE Client Disconnect Callbacks
- RFCOMM Env Loader Script
- Motor Command Struct
- Log Tag Info Struct
- Graphify Knowledge Graph Docs
- Legacy System State Bridge
- Joystick Calibration Persistence
- Env Key Injection Script
- Test Runner Script
- State Callback Registration
- Firmware Version Injection Script
- Env Example File
- Logger Module
- PlatformIO Build Config
- Local Upload Port Settings
- Shared Type Definitions
- Vehicle State Concept
- README Hardware Description
- README Quick Start
- README State Machine Diagram
- Roadmap Enclosure Phase

## God Nodes (most connected - your core abstractions)
1. `Supervisor` - 81 edges
2. `_scDispatch()` - 67 edges
3. `Logger` - 41 edges
4. `WheelConnState_t` - 33 edges
5. `Mapper` - 25 edges
6. `cli_poll()` - 22 edges
7. `bleIsConnected()` - 22 edges
8. `_wheelActive()` - 20 edges
9. `_sendCommand()` - 20 edges
10. `_scPrintStatus()` - 18 edges

## Surprising Connections (you probably didn't know these)
- `ROADMAP Phase 2: Telemetry & UI (in progress)` --references--> `_parseResponseData()`  [EXTRACTED]
  ROADMAP.md → m25_ble.cpp
- `RSSI-gated arming: block arming below BLE signal threshold (planned safety feature, 3.2)` --conceptually_related_to--> `bleIsConnected()`  [INFERRED]
  ROADMAP.md → m25_ble.cpp
- `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)` --references--> `nvsSaveJsRange()`  [AMBIGUOUS]
  ROADMAP.md → nvs_config.h
- `ROADMAP Phase 1: Core safety (done)` --references--> `Supervisor`  [EXTRACTED]
  ROADMAP.md → supervisor.h
- `m25_wheel_rfcomm README (fake M25 wheel RFCOMM simulator)` --semantically_similar_to--> `tools/ README (code generation tools overview)`  [INFERRED] [semantically similar]
  archive/m25_wheel_rfcomm/README.md → tools/README.md

## Import Cycles
- None detected.

## Hyperedges (group relationships)
- **BLE Notification Power-Efficiency Pattern** — doc_ble_cross_platform, doc_ble_notifications_how_it_works, concept_ble_notifications_vs_polling, concept_nordic_uart_service [INFERRED 0.85]
- **M25 Remote Control Protocol Command Mapping** — doc_m25_protocol, doc_remote_control_design, doc_esp32_remote_design_spec [INFERRED 0.80]
- **Joystick to Motor Data Flow** — claude_joystick_h, claude_controlstate, claude_mapper, claude_commandframe, claude_supervisor, claude_m25_ble, claude_m25_wheels [EXTRACTED 1.00]
- **Safety-Critical Code and Tests** — claude_mapper, claude_supervisor, claude_test_mapper, claude_test_supervisor, claude_logforced [EXTRACTED 1.00]
- **Configuration Priority Chain** — claude_nvs_config_h, claude_load_env_py, claude_device_config_h, claude_config_show [EXTRACTED 1.00]
- **Supervisor State Machine** — claude_supervisorstate, claude_systemstate, claude_onsupervisorstatechange [EXTRACTED 1.00]
- **BLE Dual-Core Threading Model** — claude_core0, claude_core1, claude_blestartmotortask, claude_blelastmotorwriteok, claude_supervisor, claude_remote_control_ino [EXTRACTED 1.00]
- **device_config.h Feature Flags** — claude_wheel_mode, claude_no_joystick, claude_no_deadman_hardware, claude_enable_battery_monitor, claude_enable_idle_watchdog, claude_auto_arm_on_connect, claude_device_config_h [EXTRACTED 1.00]

## Communities (58 total, 15 thin omitted)

### Community 0 - "BLE GATT Client Core"
Cohesion: 0.06
Nodes (76): BLERemoteCharacteristic, buzzerTick(), esp_bd_addr_t, esp_bluedroid_status_t, esp_bt_controller_status_t, ledTick(), _addDelimiters(), bleConnect() (+68 more)

### Community 1 - "RFCOMM Emulator Buzzer"
Cohesion: 0.05
Nodes (33): buzzer_beep(), buzzer_disable(), buzzer_enable(), buzzer_is_enabled(), buzzer_speed_tone(), buzzer_stop(), buzzer_test(), buzzer_tone() (+25 more)

### Community 2 - "RFCOMM Command Crypto"
Cohesion: 0.06
Nodes (41): command_apply(), WheelState, crypto_cbc_decrypt(), crypto_cbc_encrypt(), crypto_ecb_decrypt(), crypto_ecb_encrypt(), crypto_generate_iv(), WheelState (+33 more)

### Community 3 - "Safety Supervisor State"
Cohesion: 0.05
Nodes (39): StateCallback, SupervisorConfig, SupervisorState, VehicleState, Supervisor, _activateHoldStartMs, _armedEntryMs, _callbackCount (+31 more)

### Community 4 - "BLE Scanner and Connect"
Cohesion: 0.08
Nodes (29): connectToBLE(), connectToWheel(), disconnectBLE(), BLEClient, BLEClientCallbacks, String, MyAdvertisedDeviceCallbacks, MyClientCallback (+21 more)

### Community 5 - "Motor Task and Control State"
Cohesion: 0.07
Nodes (30): ADC1, ADC2, AUTO_ARM_ON_CONNECT flag, bleStartMotorTask(), CommandFrame, config show serial command, ControlState, Core 0 (+22 more)

### Community 6 - "BLE Diagnostics and Tx Stats"
Cohesion: 0.09
Nodes (29): bleGetMotorStopLogEnabled(), bleGetMotorStopLogEvery(), bleGetWheelMode(), blePrintTxStats(), bleRecordStart(), bleRecordStop(), bleResetTxStats(), bleSetAutoReconnect() (+21 more)

### Community 7 - "Buzzer Control and Debug Flags"
Cohesion: 0.09
Nodes (19): playBeep(), playTone(), testBuzzers(), DebugFlagInfo, description, mask, name, BLECharacteristic (+11 more)

### Community 8 - "Joystick to Command Mapper"
Cohesion: 0.11
Nodes (21): CommandFrame, ControlState, CommandFrame, MapperConfig, Mapper, applyCurve, applyDeadzone, applyRamp (+13 more)

### Community 9 - "Wheel Connection State"
Cohesion: 0.07
Nodes (27): _getWheels(), WheelConnState_t, batteryPct, batteryValid, connected, consecutiveFails, distanceKm, distanceValid (+19 more)

### Community 10 - "Bluedroid GAP and Logger"
Cohesion: 0.17
Nodes (19): esp_bt_gap_cb_event_t, esp_bt_gap_cb_param_t, LogLevel, filename(), LogLevel, Logger, begin, _level (+11 more)

### Community 11 - "TX SPP Log Comparison Tool"
Cohesion: 0.13
Nodes (20): m25_wheel_rfcomm README (fake M25 wheel RFCOMM simulator), Path, bag_compare(), _cmd_from_spp_bytes(), diff_sequences(), main(), parse_stream(), summarize() (+12 more)

### Community 12 - "Button Input Handling"
Cohesion: 0.11
Nodes (13): buttonsPrintDebug(), buttonsTick(), tick(), buzzerPlay(), BuzzerPattern, JoystickNorm, inDeadzone, x (+5 more)

### Community 13 - "Protocol Design Rationale"
Cohesion: 0.16
Nodes (18): data/index.html web joystick UI, wifi_joystick README, BLE Notifications vs Polling (Power Efficiency), Deadman Switch Design (button vs capacitive touch), ESP32 MicroPython BLE Prototype (ubluetooth-based), M25 Encrypted Packet Format (AES-128-CBC + CRC-16 + byte stuffing), m5squared Python Protocol Toolkit, Nordic UART Service (NUS) (+10 more)

### Community 14 - "Supervisor Watchdog Handlers"
Cohesion: 0.17
Nodes (19): begin, getArmedIdleRemainingMs, getTimeSinceLastInput, getTimeSinceLastLink, handleArmed, handleDisconnected, handleDriving, handleFailsafe (+11 more)

### Community 15 - "Test Harness and Scripts"
Cohesion: 0.17
Nodes (12): buzzFailure(), buzzSuccess(), buzzTestEnd(), buzzTestStart(), displayTestStatus(), ledErrorOff(), ledErrorOn(), ledStatusOff() (+4 more)

### Community 16 - "RFCOMM Runtime Wheel Config"
Cohesion: 0.23
Nodes (15): _cli_handle_config(), String, WheelRuntimeConfig, WheelRuntimeConfig, wheelcfg_clear(), wheelcfg_compiled_default_side(), wheelcfg_fill_runtime(), wheelcfg_is_valid_side() (+7 more)

### Community 17 - "BLE Command Stats Struct"
Cohesion: 0.13
Nodes (15): TxStats, assistLevel, driveMode, driveModeWriteFail, other, readCruise, readFw, readSoc (+7 more)

### Community 18 - "Serial Command Output Helpers"
Cohesion: 0.27
Nodes (13): LogLevel, _scCmdDecorateMsg(), _scCmdOut(), _scCmdOutf(), _scCmdTagFromMsg(), _scLevelName(), _scPrintBle(), _scPrintHelp() (+5 more)

### Community 19 - "Joystick ADC Input"
Cohesion: 0.23
Nodes (13): joystickApplyFullRangeCalibration(), joystickDirectionLabel(), joystickInit(), joystickNormalizeAxis(), JoystickRaw, x, y, joystickRead() (+5 more)

### Community 20 - "LED Status Indicators"
Cohesion: 0.29
Nodes (13): ledInit(), ledSetAssistLevel(), ledSetBattery(), ledSetBleMode(), _ledSetDuty(), ledSetHillHold(), _ledSetMode(), ledSetStatus() (+5 more)

### Community 21 - "M25 BLE Response Parsing"
Cohesion: 0.21
Nodes (11): _isAck(), _isNack(), _parseInt32BE(), _parseResponseData(), _parseUint16BE(), _parseUint32BE(), _parseUint8(), ResponseData (+3 more)

### Community 22 - "Serial Profile Commands"
Cohesion: 0.18
Nodes (11): MapperConfig, _scApplyProfile(), SerialContext, assistLevel, hillHoldOn, mapper, mapperCfg, state (+3 more)

### Community 23 - "Web Joystick UI Script"
Cohesion: 0.31
Nodes (9): active, e(), resetStick(), sendJoystickData(), updateStickPosition(), catch, function, x (+1 more)

### Community 24 - "BLE Status Query Getters"
Cohesion: 0.22
Nodes (8): bleGetAutoReconnect(), bleGetFirmwareVersion(), bleGetMac(), bleRecordEntryCount(), bleRecordIsActive(), _scPrintStatus(), SupervisorState, supervisorStateToString()

### Community 25 - "M25 Protocol Response Header"
Cohesion: 0.22
Nodes (9): ResponseHeader, destId, paramId, payload, payloadLen, protocolId, serviceId, sourceId (+1 more)

### Community 26 - "Supervisor Command Send Loop"
Cohesion: 0.25
Nodes (8): bleGetLastNotifyMs(), bleLastMotorWriteOk(), CommandFrame, ControlState, checkWatchdogs, processInput, sendCommand, sendHeartbeat

### Community 27 - "Code Generators and Toolkit"
Cohesion: 0.29
Nodes (7): constants.h, tools/generate_constants.py, tools/generate_profiles.py, tools/generate_tests.py, M25 Remote Firmware Repo, m5squared Python Protocol Toolkit, profiles.h

### Community 28 - "Failsafe and Vehicle State"
Cohesion: 0.33
Nodes (7): bleAnyConnected(), VehicleState, enterFailsafe, isConnected, notifyConnectionChange, requestEmergencyStop, updateVehicleState

### Community 29 - "Drive Profile Lookup"
Cohesion: 0.47
Nodes (5): DriveProfile, ProfileParams, getProfileById(), getProfileByName(), loadProfileParams()

### Community 30 - "Wheel Mode and Connect Handling"
Cohesion: 0.47
Nodes (6): bleAllConnected(), bleResetNotifyTimers(), bleSetKey(), _wheelActive(), applyRuntimeWheelConfig, handleConnecting

### Community 31 - "BLE Record Entry Struct"
Cohesion: 0.33
Nodes (6): BleRecordEntry, data, direction, ms, rawLen, wheel

### Community 32 - "Supervisor Arm Transitions"
Cohesion: 0.47
Nodes (6): bleResetMotorWriteOk(), SupervisorState, notifyStateCallbacks, requestArm, requestConnect, transitionTo

### Community 33 - "BLE Client Disconnect Callbacks"
Cohesion: 0.40
Nodes (6): BLEClient, BLEClientCallbacks, M25DisconnectCallback, onConnect, onDisconnect, wheelIdx

### Community 35 - "Motor Command Struct"
Cohesion: 0.50
Nodes (4): _MotorCmd, isStop, left, right

### Community 36 - "Log Tag Info Struct"
Cohesion: 0.50
Nodes (4): LogTagInfo, description, name, tag

### Community 37 - "Graphify Knowledge Graph Docs"
Cohesion: 0.67
Nodes (3): GRAPH_REPORT.md, graphify knowledge graph tool, graphify-out/wiki/index.md

### Community 38 - "Legacy System State Bridge"
Cohesion: 0.67
Nodes (3): onSupervisorStateChange callback, SupervisorState, SystemState (legacy)

### Community 39 - "Joystick Calibration Persistence"
Cohesion: 0.67
Nodes (3): joystickRecalibrate(), nvsSaveJsRange(), ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)

## Ambiguous Edges - Review These
- `nvsSaveJsRange()` → `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)`  [AMBIGUOUS]
  ROADMAP.md · relation: references
- `wifi_joystick README` → `fake_wheel README`  [AMBIGUOUS]
  archive/wifi_joystick/README.md · relation: references

## Knowledge Gaps
- **156 isolated node(s):** `_level`, `_tagMask`, `data`, `len`, `mask` (+151 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **15 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **What is the exact relationship between `nvsSaveJsRange()` and `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)`?**
  _Edge tagged AMBIGUOUS (relation: references) - confidence is low._
- **What is the exact relationship between `wifi_joystick README` and `fake_wheel README`?**
  _Edge tagged AMBIGUOUS (relation: references) - confidence is low._
- **Why does `Supervisor` connect `Safety Supervisor State` to `BLE GATT Client Core`, `Supervisor Arm Transitions`, `Joystick to Command Mapper`, `State Callback Registration`, `Supervisor Watchdog Handlers`, `Supervisor Command Send Loop`, `Failsafe and Vehicle State`, `Wheel Mode and Connect Handling`?**
  _High betweenness centrality (0.075) - this node is a cross-community bridge._
- **Why does `_scDispatch()` connect `BLE Diagnostics and Tx Stats` to `BLE GATT Client Core`, `Joystick Calibration Persistence`, `Bluedroid GAP and Logger`, `Button Input Handling`, `Serial Command Output Helpers`, `Joystick ADC Input`, `LED Status Indicators`, `Serial Profile Commands`, `BLE Status Query Getters`, `Failsafe and Vehicle State`, `Wheel Mode and Connect Handling`?**
  _High betweenness centrality (0.051) - this node is a cross-community bridge._
- **Why does `WheelConnState_t` connect `Wheel Connection State` to `BLE GATT Client Core`, `M25 BLE Response Parsing`?**
  _High betweenness centrality (0.039) - this node is a cross-community bridge._
- **Are the 49 inferred relationships involving `_scDispatch()` (e.g. with `buttonsPrintDebug()` and `joystickApplyFullRangeCalibration()`) actually correct?**
  _`_scDispatch()` has 49 INFERRED edges - model-reasoned connections that need verification._
- **What connects `_level`, `_tagMask`, `data` to the rest of the system?**
  _156 weakly-connected nodes found - possible documentation gaps or missing edges._