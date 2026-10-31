# Graph Report - m25-remote  (2026-10-31)

## Corpus Check
- 81 files · ~83,951 words
- Verdict: corpus is large enough that graph structure adds value.
- Unclassified: 19 file(s) not represented in the graph (top: .ino 9, (none) 4, .ini 2)

## Summary
- 1390 nodes · 2166 edges · 89 communities (72 shown, 17 thin omitted)
- Extraction: 88% EXTRACTED · 12% INFERRED · 0% AMBIGUOUS · INFERRED: 265 edges (avg confidence: 0.85)
- Token cost: 0 input · 0 output

## Graph Freshness
- Built from commit: `339c40c8`
- Run `git rev-parse HEAD` and compare to check if the graph is stale.
- Run `graphify update .` after code changes (no API cost).

## Community Hubs (Navigation)
- m25_ble.cpp
- cli_poll
- transport_rfcomm.h
- Safety Supervisor State
- handleSerialCommand
- device_config.h
- BLE Diagnostics and Tx Stats
- command_handler.h
- Mapper
- _wheelActive
- Supervisor
- compare_tx_spp.py
- Cross-Platform BLE Communication
- Supervisor Watchdog Handlers
- test_base.h
- m25_wheel_rfcomm/nvs_config.h
- BLE Command Stats Struct
- serial_commands.h
- Joystick ADC Input
- led_control.h
- m25_ble.h
- Serial Profile Commands
- sendJoystickData
- state.h
- M25 Protocol Response Header
- LogTag
- WheelConnState_t
- selftest.h
- m25_protocol.h
- bleIsConnected
- BLE Record Entry Struct
- transport_ble.h
- BLE Client Disconnect Callbacks
- RFCOMM Env Loader Script
- Motor Command Struct
- Log Tag Info Struct
- Legacy System State Bridge
- Joystick Calibration Persistence
- supervisor.h
- ble-cross-platform.md
- run
- SerialContext
- WiFi Joystick Config (Archived)
- Fancy Light Module
- Env Example File
- Logger Module
- PlatformIO Build Config
- Local Upload Port Settings
- mirror-to-6static.yml
- Vehicle State Concept
- Constructor
- README Hardware Description
- arduino
- Logger
- Roadmap Enclosure Phase
- ESP32 One-Handed Remote Control - Design Specification
- Primary Controls
- Status LEDs
- blePrintWheelDetails
- Remote control redesign — no-deadman, 3-button, integrated-LED version
- Development Roadmap
- Critical Safety Systems
- MUST-HAVE Features (Essential for MVP)
- NICE-TO-HAVE Features (Post-MVP)
- Client Questions for Feedback Session
- Universal Design Elements
- Communication Requirements
- config.h
- .transitionTo
- Technical Specifications
- Design Process & Client Iteration
- Components
- Remote Control Battery
- Usage Examples
- Summary Checklist
- References
- Testing Protocol
- DriveFeelPreset
- Troubleshooting
- ble-cross-platform.md
- JOYSTICK_SETUP.md guide
- _scPrintStatus
- _BleRxCB

## God Nodes (most connected - your core abstractions)
1. `Supervisor` - 89 edges
2. `_scDispatch()` - 75 edges
3. `Logger` - 44 edges
4. `WheelConnState_t` - 33 edges
5. `Mapper` - 25 edges
6. `LogTag` - 22 edges
7. `cli_poll()` - 22 edges
8. `bleIsConnected()` - 22 edges
9. `_wheelActive()` - 20 edges
10. `_sendCommand()` - 20 edges

## Surprising Connections (you probably didn't know these)
- `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)` --references--> `nvsSaveJsRange()`  [AMBIGUOUS]
  ROADMAP.md → nvs_config.h
- `wifi_joystick README` --references--> `fake_wheel README`  [AMBIGUOUS]
  archive/wifi_joystick/README.md → fake_wheel/README.md
- `RSSI-gated arming: block arming below BLE signal threshold (planned safety feature, 3.2)` --conceptually_related_to--> `bleIsConnected()`  [INFERRED]
  ROADMAP.md → m25_ble.cpp
- `cli_poll()` --calls--> `led_show_battery()`  [INFERRED]
  archive/m25_wheel_rfcomm/cli.h → archive/m25_wheel_rfcomm/led.h
- `cli_poll()` --calls--> `rfcomm_server_channel_known()`  [INFERRED]
  archive/m25_wheel_rfcomm/cli.h → archive/m25_wheel_rfcomm/transport_rfcomm.h

## Import Cycles
- None detected.

## Hyperedges (group relationships)
- **BLE Dual-Core Threading Model** — claude_core0, claude_core1, claude_blestartmotortask, claude_blelastmotorwriteok, claude_supervisor, claude_remote_control_ino [EXTRACTED 1.00]
- **Configuration Priority Chain** — claude_nvs_config_h, claude_load_env_py, claude_device_config_h, claude_config_show [EXTRACTED 1.00]
- **Joystick to Motor Data Flow** — joystick, claude_controlstate, claude_mapper, claude_commandframe, claude_supervisor, claude_m25_ble, claude_m25_wheels [EXTRACTED 1.00]
- **device_config.h Feature Flags** — claude_wheel_mode, claude_no_joystick, claude_no_deadman_hardware, claude_enable_battery_monitor, claude_enable_idle_watchdog, claude_auto_arm_on_connect, claude_device_config_h [EXTRACTED 1.00]
- **Safety-Critical Code and Tests** — claude_mapper, claude_supervisor, claude_test_mapper, claude_test_supervisor, claude_logforced [EXTRACTED 1.00]
- **Supervisor State Machine** — claude_supervisorstate, claude_systemstate, claude_onsupervisorstatechange [EXTRACTED 1.00]
- **M25 Remote Control Protocol Command Mapping** — doc_m25_protocol, doc_remote_control_design, doc_esp32_remote_design_spec [INFERRED 0.80]

## Communities (89 total, 17 thin omitted)

### Community 0 - "m25_ble.cpp"
Cohesion: 0.11
Nodes (23): _addDelimiters(), bleGetLastNotifyMs(), bleLastMotorWriteOk(), _bleRecordFrame(), _buildAndEncrypt(), _debugLogTxPacket(), _findWheelByHandle(), _hexSnippet() (+15 more)

### Community 1 - "cli_poll"
Cohesion: 0.14
Nodes (17): buzzer_beep(), buzzer_disable(), buzzer_enable(), buzzer_is_enabled(), buzzer_speed_tone(), buzzer_stop(), buzzer_test(), buzzer_tone() (+9 more)

### Community 2 - "transport_rfcomm.h"
Cohesion: 0.07
Nodes (24): crypto_cbc_decrypt(), crypto_cbc_encrypt(), crypto_ecb_decrypt(), crypto_ecb_encrypt(), crypto_generate_iv(), packet_decode(), packet_encode_ack(), packet_encode_response() (+16 more)

### Community 3 - "Safety Supervisor State"
Cohesion: 0.05
Nodes (38): 2.1 Battery monitoring (partial), 2.2 Firmware version ✅, 2.3 Button-based UI (partial), 2.4 Settings persistence ✅, 2.5 Serial REPL ✅, 2.6 NVS: joystick calibration ⏳, 2.7 Boot assist level feedback ⏳, 3.1 Runtime WHEEL_MODE switching (+30 more)

### Community 4 - "handleSerialCommand"
Cohesion: 0.09
Nodes (20): connectToBLE(), connectToWheel(), disconnectBLE(), MyAdvertisedDeviceCallbacks, MyClientCallback, startWheelScan(), normalizeJoystickAxis(), printJoystickCalibration() (+12 more)

### Community 5 - "device_config.h"
Cohesion: 0.04
Nodes (44): ADC constraint, Architecture, AUTO_ARM_ON_CONNECT flag, BLE threading, bleStartMotorTask(), Build & Flash, Code Generators, CommandFrame (+36 more)

### Community 6 - "BLE Diagnostics and Tx Stats"
Cohesion: 0.08
Nodes (31): bleGetMotorStopLogEnabled(), bleGetMotorStopLogEvery(), bleGetWheelMode(), blePrintTxStats(), bleRecordStart(), bleRecordStop(), bleResetTxStats(), bleSetAutoReconnect() (+23 more)

### Community 7 - "command_handler.h"
Cohesion: 0.08
Nodes (15): playBeep(), playTone(), testBuzzers(), DebugFlagInfo, description, mask, name, handleSerialCommand() (+7 more)

### Community 8 - "Mapper"
Cohesion: 0.12
Nodes (8): Mapper, _config, _hasLastCommand, _lastCommand, _lastTime, _lowBatteryLimit, ROADMAP Phase 1: Core safety (done), Supervisor::Supervisor()

### Community 9 - "_wheelActive"
Cohesion: 0.10
Nodes (23): bleAllConnected(), bleAnyConnected(), bleConnect(), bleConnectWheel(), bleDisconnect(), _bleErrStr(), bleRecordDump(), bleResetNotifyTimers() (+15 more)

### Community 10 - "Supervisor"
Cohesion: 0.04
Nodes (39): Supervisor, _activateHoldStartMs, _armedEntryMs, _armInhibit, _autoArm, _callbackCount, _config, _connectAbort (+31 more)

### Community 11 - "compare_tx_spp.py"
Cohesion: 0.06
Nodes (17): _git_cmd(), m25_wheel_rfcomm README (fake M25 wheel RFCOMM simulator), M25 Remote Firmware Repo, m5squared Python Protocol Toolkit, bag_compare(), _cmd_from_spp_bytes(), diff_sequences(), main() (+9 more)

### Community 13 - "Cross-Platform BLE Communication"
Cohesion: 0.12
Nodes (16): Architecture, Command-Line Interface, Cross-Platform BLE Communication, Debugging, Dependencies, Encryption, Integration with Transport Layer, Migration from Old Modules (+8 more)

### Community 14 - "Supervisor Watchdog Handlers"
Cohesion: 0.06
Nodes (36): 1. BLE Connection (ESP32), 1. Install Esptool, 1. Install PlatformIO, 2. Create Project, 2. Download MicroPython Firmware, 2. Input Handling, 3. Configure platformio.ini, 3. Erase Flash (+28 more)

### Community 15 - "test_base.h"
Cohesion: 0.06
Nodes (33): tests/, Hardware Setup, Libraries, Pin Connections, Troubleshooting, 1. Prepare Test Build Environment, 2. Open in Arduino IDE, 3. Make Changes (+25 more)

### Community 16 - "m25_wheel_rfcomm/nvs_config.h"
Cohesion: 0.21
Nodes (11): _cli_handle_config(), wheelcfg_clear(), wheelcfg_compiled_default_side(), wheelcfg_fill_runtime(), wheelcfg_is_valid_side(), wheelcfg_load(), wheelcfg_load_side(), wheelcfg_print() (+3 more)

### Community 17 - "BLE Command Stats Struct"
Cohesion: 0.13
Nodes (15): TxStats, assistLevel, driveMode, driveModeWriteFail, other, readCruise, readFw, readSoc (+7 more)

### Community 18 - "serial_commands.h"
Cohesion: 0.13
Nodes (23): joystickApplyFullRangeCalibration(), bleGetAutoReconnect(), nvsSaveJsRange(), LogTagInfo, description, name, tag, _scCalStep() (+15 more)

### Community 19 - "Joystick ADC Input"
Cohesion: 0.13
Nodes (26): ADC1, ADC2, joystickDirectionLabel(), joystickExpectedCenterX(), joystickExpectedCenterY(), joystickGetDeadzonePct(), joystickHasRangeCalibration(), joystickInit() (+18 more)

### Community 20 - "led_control.h"
Cohesion: 0.25
Nodes (13): ledFlashConfirm(), ledInit(), ledSetAssistLevel(), ledSetBattery(), ledSetBleMode(), _ledSetDuty(), ledSetHillHold(), _ledSetMode() (+5 more)

### Community 21 - "m25_ble.h"
Cohesion: 0.05
Nodes (30): BleRecordEntry, data, direction, ms, rawLen, wheel, _isAck(), _isNack() (+22 more)

### Community 22 - "Serial Profile Commands"
Cohesion: 0.06
Nodes (35): 1. Install Required Libraries, 2. Set Partition Scheme, 3. Configure Device, 3. Connect from Phone, 4. Upload Sketch, Add Multiple Joysticks, Adjust Control Sensitivity, Advanced Usagetly: (+27 more)

### Community 23 - "sendJoystickData"
Cohesion: 0.31
Nodes (4): e(), resetStick(), sendJoystickData(), updateStickPosition()

### Community 24 - "state.h"
Cohesion: 0.18
Nodes (10): command_apply(), safety_battery_interval(), safety_battery_tick(), safety_cmd_timeout(), state_apply_timeout(), state_cmd_timed_out(), state_drain_battery(), state_init() (+2 more)

### Community 25 - "M25 Protocol Response Header"
Cohesion: 0.06
Nodes (31): 1. `generate_constants.py`, 2. `generate_profiles.py`, 3. `generate_tests.py`, Adding New Generators, After Core Algorithm Changes, After Profile Changes, After Protocol Changes, Benefits (+23 more)

### Community 26 - "LogTag"
Cohesion: 0.09
Nodes (22): LogTag, TAG_ALL, TAG_AUTH, TAG_BLE, TAG_BOOT, TAG_BUTTON, TAG_BUZZER, TAG_CMD (+14 more)

### Community 27 - "WheelConnState_t"
Cohesion: 0.07
Nodes (28): _getWheels(), _transportIsProtocolConnected(), WheelConnState_t, batteryPct, batteryValid, connected, consecutiveFails, distanceKm (+20 more)

### Community 28 - "selftest.h"
Cohesion: 0.24
Nodes (17): buttonsTick(), buzzerPlay(), buzzerTick(), SelfTestResult, SELFTEST_FAIL, SELFTEST_PARTIAL, SELFTEST_PASS, SELFTEST_SKIPPED (+9 more)

### Community 29 - "m25_protocol.h"
Cohesion: 0.22
Nodes (6): calculateCRC16(), fake_wheel README, Fake M25 Wheel Simulator, Features, Setup, Troubleshooting

### Community 30 - "bleIsConnected"
Cohesion: 0.20
Nodes (15): bleIsConnected(), _bleMotorTask(), bleSendAssistLevel(), bleSendHillHold(), bleSendMotorCommand(), bleSendStop(), _clearTxFailureState(), _handleTxFailure() (+7 more)

### Community 31 - "BLE Record Entry Struct"
Cohesion: 0.08
Nodes (24): 1. Callback Pattern (Event-Driven), 2. Queue Pattern (Sequential Processing), 3. Polling Pattern (Not Recommended), Best Practices, BLE Notifications - How It Works, BLE Technical Details, CCCD (Client Characteristic Configuration Descriptor), Common Issues (+16 more)

### Community 32 - "transport_ble.h"
Cohesion: 0.10
Nodes (8): ble_check_events(), ble_on_connect(), ble_on_disconnect(), ble_rx_queue_waiting(), _BleRxPacket, data, len, _BleServerCB

### Community 33 - "BLE Client Disconnect Callbacks"
Cohesion: 0.11
Nodes (17): ADC reads only 0 or 4095- **Cause:** Voltage divider not connected properly, Code Files Modified, Code Files Modified, [device_config.h](device_config.h), [device_config.h](device_config.h)Added pin definitions and ADC configuration:, IMPORTANT: Voltage Divider Setup, Joystick values always at extremes- **Cause:** Voltage divider gives wrong ratio (likely missing resistor), Next Steps (+9 more)

### Community 34 - "RFCOMM Env Loader Script"
Cohesion: 0.20
Nodes (10): `async connect(address: str = None, timeout: int = 10) -> bool`, `async connect_async(timeout: int = 10) -> bool`, `async disconnect()`, `async disconnect_async()`, `async receive_packet(timeout: int = 5) -> Optional[bytes]`, `async scan(duration: int = 10, filter_m25: bool = False) -> List[Tuple[str, str]]`, `async send_async(encrypted_data: bytes) -> bool`, `async send_packet(data: bytes) -> bool` (+2 more)

### Community 35 - "Motor Command Struct"
Cohesion: 0.50
Nodes (4): _MotorCmd, isStop, left, right

### Community 36 - "Log Tag Info Struct"
Cohesion: 0.12
Nodes (16): APP_MGMT (0x01), BATT_MGMT (0x02), Byte Stuffing, CRC-16, Decrypting a Packet, Encrypting a Packet, Key Derivation (The Fun Part), M25 Protocol Documentation (+8 more)

### Community 38 - "Legacy System State Bridge"
Cohesion: 0.67
Nodes (3): onSupervisorStateChange callback, SupervisorState, SystemState (legacy)

### Community 39 - "Joystick Calibration Persistence"
Cohesion: 0.14
Nodes (13): 1. Configure `config.h`, 2. Set upload port in `platformio.ini`, 3. Build and upload, 4. Set wheel side once, 5. Connect from Python, Debug flags, Enabling BLE alongside RFCOMM, File structure (+5 more)

### Community 41 - "ble-cross-platform.md"
Cohesion: 0.36
Nodes (5): data/index.html web joystick UI, wifi_joystick README, m5squared Python Protocol Toolkit, Watchdog / Timeout Safety Mechanism, m25_protocol.py (Python M25 protocol spec, external m5squared toolkit)

### Community 42 - "run"
Cohesion: 0.05
Nodes (20): ArmGesture, _phase, _sinceMs, ArmGestureEvent, ARM_GESTURE_DONE, ARM_GESTURE_NONE, ARM_GESTURE_STEP, Phase (+12 more)

### Community 43 - "SerialContext"
Cohesion: 0.22
Nodes (7): SerialContext, assistLevel, hillHoldOn, mapper, mapperCfg, state, supervisor

### Community 44 - "WiFi Joystick Config (Archived)"
Cohesion: 0.18
Nodes (11): Deadman Switch Implementation, Ergonomic Design Considerations, Form Factor Options, Grip and Handling (Option A Details), Joystick Control, Option 1: Joystick Integrated Button, Option 2: Capacitive Touch Strip (RECOMMENDED), Option A: Handheld Grip Device (+3 more)

### Community 45 - "Fancy Light Module"
Cohesion: 0.18
Nodes (11): Advanced Features, Design Philosophy, Ergonomic Layout, Future Enhancements, License, Overview, Potential Additions, Priority-Based Access (+3 more)

### Community 50 - "mirror-to-6static.yml"
Cohesion: 0.17
Nodes (11): jobs, mirror, runs-on, steps, name, on, push, workflow_dispatch (+3 more)

### Community 52 - "Constructor"
Cohesion: 0.33
Nodes (6): `async start_notifications(callback = None) -> bool`, `async stop_notifications() -> bool`, `async wait_notification(timeout: float = None) -> Optional[bytes]`, Class Reference, Constructor, `M25BluetoothBLE`

### Community 53 - "README Hardware Description"
Cohesion: 0.17
Nodes (11): 1. Credentials, 2. Build & Flash, 3. Serial interface, Configuration, Hardware, m25-remote, Quick Start, Related (+3 more)

### Community 54 - "arduino"
Cohesion: 0.14
Nodes (5): buttonsPrintDebug(), tick(), calculateMotorCommand(), joystickToMotorCommand(), printMotorCommand()

### Community 55 - "Logger"
Cohesion: 0.12
Nodes (15): filename(), Logger, _level, _tagMask, LogLevel, DEBUG, ERROR, INFO (+7 more)

### Community 58 - "ESP32 One-Handed Remote Control - Design Specification"
Cohesion: 0.22
Nodes (9): ESP32 One-Handed Remote Control - Design Specification, Leverage Existing m5squared Codebase, New Files to Create, Non-Negotiable Safety Rules, Project Overview, Reference Documentation Links, Repository Integration, Safety Critical Requirements (+1 more)

### Community 59 - "Primary Controls"
Cohesion: 0.22
Nodes (9): 1. Assist Level Selector, 2. Hill Hold Toggle, 3. Emergency Stop, 4. Drive Profile Selector, 5. Cruise Control Toggle, 6. Power/Wake Button, Essential Switches, Primary Controls (+1 more)

### Community 60 - "Status LEDs"
Cohesion: 0.22
Nodes (9): 1. Battery Level Indicator, 2. Connection Status, 3. Assist Level Indicators, 4. Hill Hold Status, 5. Cruise Control Status, 6. Small OLED/LCD Screen (128x64 or similar), Essential Indicators, Optional Display (+1 more)

### Community 61 - "blePrintWheelDetails"
Cohesion: 0.40
Nodes (5): bleFullReset(), bleInit(), blePrintWheelDetails(), bleWheelModeName(), _scPrintWheels()

### Community 62 - "Remote control redesign — no-deadman, 3-button, integrated-LED version"
Cohesion: 0.22
Nodes (8): Buttons, Context, Goals, LEDs, Non-goals (for this version), Open questions, Pinout summary (for enclosure/wiring handoff), Remote control redesign — no-deadman, 3-button, integrated-LED version

### Community 64 - "Development Roadmap"
Cohesion: 0.29
Nodes (7): Development Roadmap, Milestone 1: ESP32 Basic Control (Week 1-2), Milestone 2: Bluetooth Integration (Week 2-3), Milestone 3: Safety Features (Week 3-4), Milestone 4: Full Control (Week 4-5), Milestone 5: Ergonomic Prototype (Week 5-6), Milestone 6: Refinement (Week 6+)

### Community 65 - "Critical Safety Systems"
Cohesion: 0.29
Nodes (7): 1. Deadman Switch (Optional), 2. Timeout Protection, 3. Low Battery Warning, 4. Mode Indication, 5. Connection Loss Handling, Critical Safety Systems, Safety Features

### Community 67 - "MUST-HAVE Features (Essential for MVP)"
Cohesion: 0.33
Nodes (6): 1. Core Hardware Components, 2. Essential Controls (Physical Switches), 3. Essential Indicators (Visual Feedback), 4. Essential Safety Features, 5. Software Requirements (Python + MicroPython), MUST-HAVE Features (Essential for MVP)

### Community 68 - "NICE-TO-HAVE Features (Post-MVP)"
Cohesion: 0.33
Nodes (6): Additional Controls, Advanced Safety, Connectivity Enhancements, Display Enhancement, Enhanced Feedback, NICE-TO-HAVE Features (Post-MVP)

### Community 69 - "Client Questions for Feedback Session"
Cohesion: 0.33
Nodes (6): Additional Features, Client Questions for Feedback Session, Control Feel, Display vs. LEDs, Ergonomics, Safety Preferences

### Community 70 - "Universal Design Elements"
Cohesion: 0.33
Nodes (6): 1. Tactile Markers, 2. Audible Feedback (Optional), 3. Visual Design, 4. Grip Design, Accessibility Features, Universal Design Elements

### Community 71 - "Communication Requirements"
Cohesion: 0.33
Nodes (6): Bluetooth Connection, Command Timing, Communication Requirements, Error Handling, Key Protocol Commands, Protocol Implementation

### Community 75 - "Technical Specifications"
Cohesion: 0.40
Nodes (5): Communication Protocol, ESP32 Module Requirements, GPIO Pin Assignment (Suggested), Power Budget (Rough Estimates), Technical Specifications

### Community 76 - "Design Process & Client Iteration"
Cohesion: 0.40
Nodes (5): Design Process & Client Iteration, Phase 1: Breadboard Prototype (Current Stage), Phase 2: Functional Mockup, Phase 3: Refined Prototype, Phase 4: Final Design

### Community 77 - "Components"
Cohesion: 0.40
Nodes (5): Components, Cost Estimation (DIY Build), Electronics, Housing, Manufacturing Considerations

### Community 78 - "Remote Control Battery"
Cohesion: 0.40
Nodes (5): Power Management, Power Saving, Power States, Remote Control Battery, Requirements

### Community 80 - "Usage Examples"
Cohesion: 0.33
Nodes (6): Basic Connection (No Encryption), Connection with Encryption, Power-Efficient Notifications (Recommended), Scanning for Devices, Synchronous Wrappers, Usage Examples

### Community 82 - "Summary Checklist"
Cohesion: 0.50
Nodes (4): Design Questions for Client, Must-Have (MVP), Nice-to-Have (Post-MVP), Summary Checklist

### Community 83 - "References"
Cohesion: 0.50
Nodes (4): External References, References, Related Documentation, Source Code

### Community 84 - "Testing Protocol"
Cohesion: 0.50
Nodes (4): Field Testing, Pre-Use Testing, Safety Testing, Testing Protocol

### Community 85 - "DriveFeelPreset"
Cohesion: 0.33
Nodes (6): DriveFeelPreset, curve, maxSpeedNormal, name, rampRate, turnReduction

### Community 86 - "Troubleshooting"
Cohesion: 0.40
Nodes (5): Connection timeout, Encryption errors, "No TX characteristic found", "Not connected or no TX char", Troubleshooting

### Community 87 - "ble-cross-platform.md"
Cohesion: 0.28
Nodes (6): ESP32 MicroPython BLE Prototype (ubluetooth-based), M25 Encrypted Packet Format (AES-128-CBC + CRC-16 + byte stuffing), Characteristic Discovery, Naming Convention, Nordic UART Service (NUS), Service and Characteristics

### Community 99 - "_scPrintStatus"
Cohesion: 0.20
Nodes (13): bleGetBattery(), bleGetDistanceKm(), bleGetFirmwareVersion(), bleGetMac(), bleRecordEntryCount(), bleRecordIsActive(), bleRequestCruiseValues(), bleRequestFirmwareVersion() (+5 more)

## Ambiguous Edges - Review These
- `nvsSaveJsRange()` → `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)`  [AMBIGUOUS]
  ROADMAP.md · relation: references
- `fake_wheel README` → `wifi_joystick README`  [AMBIGUOUS]
  archive/wifi_joystick/README.md · relation: references

## Knowledge Gaps
- **199 isolated node(s):** `NONE`, `ERROR`, `WARN`, `INFO`, `DEBUG` (+194 more)
  These have ≤1 connection - possible missing edges or undocumented components. (Counts symbols only; 715 node(s) total have ≤1 connection when file, concept and rationale nodes are included.)
- **17 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `wifi_joystick README` connect `ble-cross-platform.md` to `m25_protocol.h`?**
  _High betweenness centrality (0.174) - this node is a cross-community bridge._
- **Are the 54 inferred relationships involving `_scDispatch()` (e.g. with `buttonsPrintDebug()` and `joystickGetDeadzonePct()`) actually correct?**
  _`_scDispatch()` has 54 INFERRED edges - model-reasoned connections that need verification._
- **What connects `NONE`, `ERROR`, `WARN` to the rest of the system?**
  _199 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `m25_ble.cpp` be split into smaller, more focused modules?**
  _Cohesion score 0.11397849462365592 - nodes in this community are weakly interconnected._
- **Why does `fake_wheel README` connect `m25_protocol.h` to `ble-cross-platform.md`?**
  _High betweenness centrality (0.174) - this node is a cross-community bridge._

### Low-confidence Hints
_AMBIGUOUS edges — the extractor was unsure. Verify before acting on these._

- **What is the exact relationship between `nvsSaveJsRange()` and `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)`?**
  _Edge tagged AMBIGUOUS (relation: references) - confidence is low._
- **What is the exact relationship between `fake_wheel README` and `wifi_joystick README`?**
  _Edge tagged AMBIGUOUS (relation: references) - confidence is low._