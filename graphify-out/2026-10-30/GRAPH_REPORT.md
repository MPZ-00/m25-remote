# Graph Report - m25-remote  (2026-10-30)

## Corpus Check
- 79 files · ~82,449 words
- Verdict: corpus is large enough that graph structure adds value.

## Summary
- 1120 nodes · 1603 edges · 91 communities (78 shown, 13 thin omitted)
- Extraction: 92% EXTRACTED · 8% INFERRED · 0% AMBIGUOUS · INFERRED: 134 edges (avg confidence: 0.8)
- Token cost: 0 input · 0 output

## Graph Freshness
- Built from commit: `31ee8613`
- Run `git rev-parse HEAD` and compare to check if the graph is stale.
- Run `graphify update .` after code changes (no API cost).

## Community Hubs (Navigation)
- [[_COMMUNITY_BLE GATT Client Core|BLE GATT Client Core]]
- [[_COMMUNITY_RFCOMM Emulator Buzzer|RFCOMM Emulator Buzzer]]
- [[_COMMUNITY_RFCOMM Command Crypto|RFCOMM Command Crypto]]
- [[_COMMUNITY_Safety Supervisor State|Safety Supervisor State]]
- [[_COMMUNITY_BLE Scanner and Connect|BLE Scanner and Connect]]
- [[_COMMUNITY_Motor Task and Control State|Motor Task and Control State]]
- [[_COMMUNITY_BLE Diagnostics and Tx Stats|BLE Diagnostics and Tx Stats]]
- [[_COMMUNITY_Buzzer Control and Debug Flags|Buzzer Control and Debug Flags]]
- [[_COMMUNITY_Joystick to Command Mapper|Joystick to Command Mapper]]
- [[_COMMUNITY_Wheel Connection State|Wheel Connection State]]
- [[_COMMUNITY_Bluedroid GAP and Logger|Bluedroid GAP and Logger]]
- [[_COMMUNITY_TX SPP Log Comparison Tool|TX SPP Log Comparison Tool]]
- [[_COMMUNITY_Button Input Handling|Button Input Handling]]
- [[_COMMUNITY_Protocol Design Rationale|Protocol Design Rationale]]
- [[_COMMUNITY_Supervisor Watchdog Handlers|Supervisor Watchdog Handlers]]
- [[_COMMUNITY_Test Harness and Scripts|Test Harness and Scripts]]
- [[_COMMUNITY_RFCOMM Runtime Wheel Config|RFCOMM Runtime Wheel Config]]
- [[_COMMUNITY_BLE Command Stats Struct|BLE Command Stats Struct]]
- [[_COMMUNITY_Serial Command Output Helpers|Serial Command Output Helpers]]
- [[_COMMUNITY_Joystick ADC Input|Joystick ADC Input]]
- [[_COMMUNITY_LED Status Indicators|LED Status Indicators]]
- [[_COMMUNITY_M25 BLE Response Parsing|M25 BLE Response Parsing]]
- [[_COMMUNITY_Serial Profile Commands|Serial Profile Commands]]
- [[_COMMUNITY_Web Joystick UI Script|Web Joystick UI Script]]
- [[_COMMUNITY_BLE Status Query Getters|BLE Status Query Getters]]
- [[_COMMUNITY_M25 Protocol Response Header|M25 Protocol Response Header]]
- [[_COMMUNITY_Supervisor Command Send Loop|Supervisor Command Send Loop]]
- [[_COMMUNITY_Code Generators and Toolkit|Code Generators and Toolkit]]
- [[_COMMUNITY_Failsafe and Vehicle State|Failsafe and Vehicle State]]
- [[_COMMUNITY_Drive Profile Lookup|Drive Profile Lookup]]
- [[_COMMUNITY_Wheel Mode and Connect Handling|Wheel Mode and Connect Handling]]
- [[_COMMUNITY_BLE Record Entry Struct|BLE Record Entry Struct]]
- [[_COMMUNITY_Supervisor Arm Transitions|Supervisor Arm Transitions]]
- [[_COMMUNITY_BLE Client Disconnect Callbacks|BLE Client Disconnect Callbacks]]
- [[_COMMUNITY_RFCOMM Env Loader Script|RFCOMM Env Loader Script]]
- [[_COMMUNITY_Motor Command Struct|Motor Command Struct]]
- [[_COMMUNITY_Log Tag Info Struct|Log Tag Info Struct]]
- [[_COMMUNITY_Graphify Knowledge Graph Docs|Graphify Knowledge Graph Docs]]
- [[_COMMUNITY_Legacy System State Bridge|Legacy System State Bridge]]
- [[_COMMUNITY_Joystick Calibration Persistence|Joystick Calibration Persistence]]
- [[_COMMUNITY_Env Key Injection Script|Env Key Injection Script]]
- [[_COMMUNITY_Test Runner Script|Test Runner Script]]
- [[_COMMUNITY_State Callback Registration|State Callback Registration]]
- [[_COMMUNITY_Firmware Version Injection Script|Firmware Version Injection Script]]
- [[_COMMUNITY_WiFi Joystick Config (Archived)|WiFi Joystick Config (Archived)]]
- [[_COMMUNITY_Fancy Light Module|Fancy Light Module]]
- [[_COMMUNITY_Env Example File|Env Example File]]
- [[_COMMUNITY_Logger Module|Logger Module]]
- [[_COMMUNITY_PlatformIO Build Config|PlatformIO Build Config]]
- [[_COMMUNITY_Local Upload Port Settings|Local Upload Port Settings]]
- [[_COMMUNITY_Shared Type Definitions|Shared Type Definitions]]
- [[_COMMUNITY_Vehicle State Concept|Vehicle State Concept]]
- [[_COMMUNITY_README Hardware Description|README Hardware Description]]
- [[_COMMUNITY_README Quick Start|README Quick Start]]
- [[_COMMUNITY_README State Machine Diagram|README State Machine Diagram]]
- [[_COMMUNITY_Roadmap Enclosure Phase|Roadmap Enclosure Phase]]
- [[_COMMUNITY_Community 58|Community 58]]
- [[_COMMUNITY_Community 59|Community 59]]
- [[_COMMUNITY_Community 60|Community 60]]
- [[_COMMUNITY_Community 61|Community 61]]
- [[_COMMUNITY_Community 62|Community 62]]
- [[_COMMUNITY_Community 63|Community 63]]
- [[_COMMUNITY_Community 64|Community 64]]
- [[_COMMUNITY_Community 65|Community 65]]
- [[_COMMUNITY_Community 66|Community 66]]
- [[_COMMUNITY_Community 67|Community 67]]
- [[_COMMUNITY_Community 68|Community 68]]
- [[_COMMUNITY_Community 69|Community 69]]
- [[_COMMUNITY_Community 70|Community 70]]
- [[_COMMUNITY_Community 71|Community 71]]
- [[_COMMUNITY_Community 73|Community 73]]
- [[_COMMUNITY_Community 74|Community 74]]
- [[_COMMUNITY_Community 75|Community 75]]
- [[_COMMUNITY_Community 76|Community 76]]
- [[_COMMUNITY_Community 77|Community 77]]
- [[_COMMUNITY_Community 78|Community 78]]
- [[_COMMUNITY_Community 79|Community 79]]
- [[_COMMUNITY_Community 80|Community 80]]
- [[_COMMUNITY_Community 81|Community 81]]
- [[_COMMUNITY_Community 82|Community 82]]
- [[_COMMUNITY_Community 83|Community 83]]
- [[_COMMUNITY_Community 84|Community 84]]
- [[_COMMUNITY_Community 85|Community 85]]
- [[_COMMUNITY_Community 86|Community 86]]
- [[_COMMUNITY_Community 87|Community 87]]
- [[_COMMUNITY_Community 89|Community 89]]
- [[_COMMUNITY_Community 90|Community 90]]

## God Nodes (most connected - your core abstractions)
1. `_scDispatch()` - 46 edges
2. `cli_poll()` - 22 edges
3. `_wheelActive()` - 19 edges
4. `_sendCommand()` - 19 edges
5. `bleIsConnected()` - 19 edges
6. `Cross-Platform BLE Communication` - 16 edges
7. `Remote Control Design Specification` - 16 edges
8. `TxStats` - 15 edges
9. `transitionTo()` - 15 edges
10. `WiFi Virtual Joystick Controller` - 15 edges

## Surprising Connections (you probably didn't know these)
- `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)` --references--> `nvsSaveJsRange()`  [AMBIGUOUS]
  ROADMAP.md → nvs_config.h
- `RSSI-gated arming: block arming below BLE signal threshold (planned safety feature, 3.2)` --conceptually_related_to--> `bleIsConnected()`  [INFERRED]
  ROADMAP.md → m25_ble.cpp
- `_scDispatch()` --calls--> `buttonsPrintDebug()`  [INFERRED]
  serial_commands.h → button.h
- `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)` --references--> `joystickRecalibrate()`  [EXTRACTED]
  ROADMAP.md → joystick.h
- `_scDispatch()` --calls--> `joystickSetDeadzonePct()`  [INFERRED]
  serial_commands.h → joystick.h

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

## Communities (91 total, 13 thin omitted)

### Community 0 - "BLE GATT Client Core"
Cohesion: 0.06
Nodes (36): BLEClient, esp_bd_addr_t, esp_bluedroid_status_t, esp_bt_controller_status_t, _addDelimiters(), bleConnect(), _bleErrStr(), bleFullReset() (+28 more)

### Community 1 - "RFCOMM Emulator Buzzer"
Cohesion: 0.15
Nodes (18): WheelState, CliActions, buzzer_beep(), buzzer_disable(), buzzer_enable(), buzzer_is_enabled(), buzzer_speed_tone(), buzzer_stop() (+10 more)

### Community 2 - "RFCOMM Command Crypto"
Cohesion: 0.18
Nodes (14): WheelState, WheelState, WheelState, CmdResult, command_apply(), safety_battery_interval(), safety_battery_tick(), safety_cmd_timeout() (+6 more)

### Community 3 - "Safety Supervisor State"
Cohesion: 0.05
Nodes (38): 2.1 Battery monitoring (partial), 2.2 Firmware version ✅, 2.3 Button-based UI (partial), 2.4 Settings persistence ✅, 2.5 Serial REPL ✅, 2.6 NVS: joystick calibration ⏳, 2.7 Boot assist level feedback ⏳, 3.1 Runtime WHEEL_MODE switching (+30 more)

### Community 4 - "BLE Scanner and Connect"
Cohesion: 0.11
Nodes (25): class, String, PhysicalJoystickState, BLEAdvertisedDeviceCallbacks(), BLEClientCallbacks(), connectToBLE(), connectToWheel(), disconnectBLE() (+17 more)

### Community 5 - "Motor Task and Control State"
Cohesion: 0.20
Nodes (12): AUTO_ARM_ON_CONNECT flag, config show serial command, device_config.h, ENABLE_BATTERY_MONITOR flag, ENABLE_IDLE_WATCHDOG flag, .env, load_env.py, NO_DEADMAN_HARDWARE flag (+4 more)

### Community 6 - "BLE Diagnostics and Tx Stats"
Cohesion: 0.14
Nodes (19): nvsClearAll(), nvsLoadActiveSource(), nvsLoadAssistLevel(), nvsLoadKey(), nvsLoadMac(), nvsLoadWheelMode(), nvsPrintAll(), nvsSaveActiveSource() (+11 more)

### Community 7 - "Buzzer Control and Debug Flags"
Cohesion: 0.12
Nodes (12): playBeep(), playTone(), testBuzzers(), WheelState, handleSerialCommand(), printDebugFlags(), printHardware(), printHelp() (+4 more)

### Community 8 - "Joystick to Command Mapper"
Cohesion: 0.33
Nodes (9): applyCurve(), applyDeadzone(), applyRamp(), buildFlags(), clamp(), CommandFrame, ControlState, differentialDrive() (+1 more)

### Community 9 - "Wheel Connection State"
Cohesion: 0.27
Nodes (11): bleDisconnect(), bleResetWheel(), bleSetMac(), _clearTxFailureState(), _getWheels(), _transportClearLinkState(), _transportDisconnectLink(), _transportHasOpenLink() (+3 more)

### Community 10 - "Bluedroid GAP and Logger"
Cohesion: 0.36
Nodes (12): begin(), LogLevel, filename(), levelString(), loadFromNVS(), log(), logForced(), saveToNVS() (+4 more)

### Community 11 - "TX SPP Log Comparison Tool"
Cohesion: 0.13
Nodes (19): m25_wheel_rfcomm README (fake M25 wheel RFCOMM simulator), Path, bag_compare(), _cmd_from_spp_bytes(), diff_sequences(), main(), parse_stream(), summarize() (+11 more)

### Community 12 - "Button Input Handling"
Cohesion: 0.25
Nodes (3): buttonsPrintDebug(), buttonsTick(), tick()

### Community 13 - "Protocol Design Rationale"
Cohesion: 0.05
Nodes (42): data/index.html web joystick UI, wifi_joystick README, BLE Notifications vs Polling (Power Efficiency), Deadman Switch Design (button vs capacitive touch), ESP32 MicroPython BLE Prototype (ubluetooth-based), M25 Encrypted Packet Format (AES-128-CBC + CRC-16 + byte stuffing), m5squared Python Protocol Toolkit, Watchdog / Timeout Safety Mechanism (+34 more)

### Community 14 - "Supervisor Watchdog Handlers"
Cohesion: 0.06
Nodes (36): 1. BLE Connection (ESP32), 1. Install Esptool, 1. Install PlatformIO, 2. Create Project, 2. Download MicroPython Firmware, 2. Input Handling, 3. Configure platformio.ini, 3. Erase Flash (+28 more)

### Community 15 - "Test Harness and Scripts"
Cohesion: 0.07
Nodes (32): Hardware Setup, Libraries, Pin Connections, Troubleshooting, 1. Prepare Test Build Environment, 2. Open in Arduino IDE, 3. Make Changes, Alternative: Command Line (Automated) (+24 more)

### Community 16 - "RFCOMM Runtime Wheel Config"
Cohesion: 0.23
Nodes (15): String, WheelRuntimeConfig, WheelRuntimeConfig, _cli_handle_config(), wheelcfg_clear(), wheelcfg_compiled_default_side(), wheelcfg_fill_runtime(), wheelcfg_is_valid_side() (+7 more)

### Community 17 - "BLE Command Stats Struct"
Cohesion: 0.13
Nodes (15): TxStats, assistLevel, driveMode, driveModeWriteFail, other, readCruise, readFw, readSoc (+7 more)

### Community 18 - "Serial Command Output Helpers"
Cohesion: 0.15
Nodes (23): LogLevel, _scApplySource(), _scCmdDecorateMsg(), _scCmdOut(), _scCmdOutf(), _scCmdTagFromMsg(), _scKmhToPct(), _scLevelName() (+15 more)

### Community 19 - "Joystick ADC Input"
Cohesion: 0.16
Nodes (20): JoystickNorm, joystickApplyFullRangeCalibration(), joystickDirectionLabel(), joystickExpectedCenterX(), joystickExpectedCenterY(), joystickGetDeadzonePct(), joystickHasRangeCalibration(), joystickNormalizeAxis() (+12 more)

### Community 20 - "LED Status Indicators"
Cohesion: 0.25
Nodes (15): ledFlashConfirm(), ledInit(), ledSetAssistLevel(), ledSetBattery(), ledSetBleMode(), _ledSetDuty(), ledSetHillHold(), _ledSetMode() (+7 more)

### Community 21 - "M25 BLE Response Parsing"
Cohesion: 0.14
Nodes (9): class, M25DisconnectCallback(), _parseInt32BE(), _parseUint32BE(), class, Mapper(), ROADMAP Phase 1: Core safety (done), class (+1 more)

### Community 22 - "Serial Profile Commands"
Cohesion: 0.06
Nodes (35): 1. Install Required Libraries, 2. Set Partition Scheme, 3. Configure Device, 3. Connect from Phone, 4. Upload Sketch, Add Multiple Joysticks, Adjust Control Sensitivity, Advanced Usagetly: (+27 more)

### Community 23 - "Web Joystick UI Script"
Cohesion: 0.31
Nodes (9): active, catch, function, e(), resetStick(), sendJoystickData(), updateStickPosition(), x (+1 more)

### Community 24 - "BLE Status Query Getters"
Cohesion: 0.09
Nodes (27): WheelState, esp_spp_cb_event_t, esp_spp_cb_param_t, crypto_cbc_decrypt(), crypto_cbc_encrypt(), crypto_ecb_decrypt(), crypto_ecb_encrypt(), crypto_generate_iv() (+19 more)

### Community 25 - "M25 Protocol Response Header"
Cohesion: 0.06
Nodes (31): 1. `generate_constants.py`, 2. `generate_profiles.py`, 3. `generate_tests.py`, Adding New Generators, After Core Algorithm Changes, After Profile Changes, After Protocol Changes, Benefits (+23 more)

### Community 26 - "Supervisor Command Send Loop"
Cohesion: 0.09
Nodes (28): bleGetLastNotifyMs(), bleLastMotorWriteOk(), bleResetMotorWriteOk(), bleResetNotifyTimers(), StateCallback, addStateCallback(), checkWatchdogs(), CommandFrame (+20 more)

### Community 27 - "Code Generators and Toolkit"
Cohesion: 0.29
Nodes (7): constants.h, tools/generate_constants.py, tools/generate_profiles.py, tools/generate_tests.py, M25 Remote Firmware Repo, m5squared Python Protocol Toolkit, profiles.h

### Community 28 - "Failsafe and Vehicle State"
Cohesion: 0.12
Nodes (24): BLERemoteCharacteristic, _bleRecordFrame(), esp_spp_cb_event_t, esp_spp_cb_param_t, _findWheelByHandle(), _hexSnippet(), _isAck(), _isNack() (+16 more)

### Community 29 - "Drive Profile Lookup"
Cohesion: 0.47
Nodes (5): DriveProfile, ProfileParams, getProfileById(), getProfileByName(), loadProfileParams()

### Community 30 - "Wheel Mode and Connect Handling"
Cohesion: 0.23
Nodes (18): bleAllConnected(), bleAnyConnected(), bleConnectWheel(), bleIsConnected(), _bleMotorTask(), bleSetKey(), _wheelActive(), ROADMAP Phase 3: Drive features (planned) (+10 more)

### Community 31 - "BLE Record Entry Struct"
Cohesion: 0.08
Nodes (24): 1. Callback Pattern (Event-Driven), 2. Queue Pattern (Sequential Processing), 3. Polling Pattern (Not Recommended), Best Practices, BLE Notifications - How It Works, BLE Technical Details, CCCD (Client Characteristic Configuration Descriptor), Common Issues (+16 more)

### Community 32 - "Supervisor Arm Transitions"
Cohesion: 0.12
Nodes (11): class, BLECharacteristic, BLEServer, initCommandHandler(), ble_check_events(), ble_on_connect(), ble_on_disconnect(), ble_rx_queue_waiting() (+3 more)

### Community 33 - "BLE Client Disconnect Callbacks"
Cohesion: 0.11
Nodes (17): ADC reads only 0 or 4095- **Cause:** Voltage divider not connected properly, Code Files Modified, Code Files Modified, [device_config.h](device_config.h), [device_config.h](device_config.h)Added pin definitions and ADC configuration:, IMPORTANT: Voltage Divider Setup, Joystick values always at extremes- **Cause:** Voltage divider gives wrong ratio (likely missing resistor), Next Steps (+9 more)

### Community 34 - "RFCOMM Env Loader Script"
Cohesion: 0.12
Nodes (16): `async connect(address: str = None, timeout: int = 10) -> bool`, `async connect_async(timeout: int = 10) -> bool`, `async disconnect()`, `async disconnect_async()`, `async receive_packet(timeout: int = 5) -> Optional[bytes]`, `async scan(duration: int = 10, filter_m25: bool = False) -> List[Tuple[str, str]]`, `async send_async(encrypted_data: bytes) -> bool`, `async send_packet(data: bytes) -> bool` (+8 more)

### Community 35 - "Motor Command Struct"
Cohesion: 0.50
Nodes (4): _MotorCmd, isStop, left, right

### Community 36 - "Log Tag Info Struct"
Cohesion: 0.12
Nodes (16): APP_MGMT (0x01), BATT_MGMT (0x02), Byte Stuffing, CRC-16, Decrypting a Packet, Encrypting a Packet, Key Derivation (The Fun Part), M25 Protocol Documentation (+8 more)

### Community 37 - "Graphify Knowledge Graph Docs"
Cohesion: 0.25
Nodes (6): Feature flags (`device_config.h`), GRAPH_REPORT.md, graphify, graphify-out/wiki/index.md, Safety-critical code, What this repo is

### Community 38 - "Legacy System State Bridge"
Cohesion: 0.67
Nodes (3): onSupervisorStateChange callback, SupervisorState, SystemState (legacy)

### Community 39 - "Joystick Calibration Persistence"
Cohesion: 0.14
Nodes (13): 1. Configure `config.h`, 2. Set upload port in `platformio.ini`, 3. Build and upload, 4. Set wheel side once, 5. Connect from Python, Debug flags, Enabling BLE alongside RFCOMM, File structure (+5 more)

### Community 42 - "State Callback Registration"
Cohesion: 0.22
Nodes (9): CommandFrame, Core 1, mapper.h/.cpp, prepare_test.ps1, remote_control.ino, serial_commands.h, supervisor.h/.cpp, test_mapper (+1 more)

### Community 44 - "WiFi Joystick Config (Archived)"
Cohesion: 0.18
Nodes (11): Deadman Switch Implementation, Ergonomic Design Considerations, Form Factor Options, Grip and Handling (Option A Details), Joystick Control, Option 1: Joystick Integrated Button, Option 2: Capacitive Touch Strip (RECOMMENDED), Option A: Handheld Grip Device (+3 more)

### Community 45 - "Fancy Light Module"
Cohesion: 0.18
Nodes (11): Advanced Features, Design Philosophy, Ergonomic Layout, Future Enhancements, License, Overview, Potential Additions, Priority-Based Access (+3 more)

### Community 53 - "README Hardware Description"
Cohesion: 0.17
Nodes (11): 1. Credentials, 2. Build & Flash, 3. Serial interface, Configuration, Hardware, m25-remote, Quick Start, Related (+3 more)

### Community 54 - "README Quick Start"
Cohesion: 0.20
Nodes (9): Buttons, Context, Goals, LEDs, Non-goals (for this version), Open questions, Pinout summary (for enclosure/wiring handoff), Remote control redesign — no-deadman, 3-button, integrated-LED version (+1 more)

### Community 55 - "README State Machine Diagram"
Cohesion: 0.16
Nodes (7): buzzerPlay(), BuzzerPattern, calculateMotorCommand(), JoystickNorm, joystickToMotorCommand(), printMotorCommand(), MotorCommand

### Community 58 - "Community 58"
Cohesion: 0.22
Nodes (9): ESP32 One-Handed Remote Control - Design Specification, Leverage Existing m5squared Codebase, New Files to Create, Non-Negotiable Safety Rules, Project Overview, Reference Documentation Links, Repository Integration, Safety Critical Requirements (+1 more)

### Community 59 - "Community 59"
Cohesion: 0.22
Nodes (9): 1. Assist Level Selector, 2. Hill Hold Toggle, 3. Emergency Stop, 4. Drive Profile Selector, 5. Cruise Control Toggle, 6. Power/Wake Button, Essential Switches, Primary Controls (+1 more)

### Community 60 - "Community 60"
Cohesion: 0.22
Nodes (9): 1. Battery Level Indicator, 2. Connection Status, 3. Assist Level Indicators, 4. Hill Hold Status, 5. Cruise Control Status, 6. Small OLED/LCD Screen (128x64 or similar), Essential Indicators, Optional Display (+1 more)

### Community 61 - "Community 61"
Cohesion: 0.29
Nodes (6): ArmGesture(), _enter(), class, update(), ArmGestureEvent, Phase

### Community 62 - "Community 62"
Cohesion: 0.39
Nodes (8): bleGetBattery(), bleGetDistanceKm(), bleRequestCruiseValues(), bleRequestFirmwareVersion(), bleRequestSOC(), _requestAll(), _requestOne(), pollTelemetry()

### Community 63 - "Community 63"
Cohesion: 0.29
Nodes (7): ADC constraint, Architecture, BLE threading, Configuration priority, Data flow, Key files, Supervisor states

### Community 64 - "Community 64"
Cohesion: 0.29
Nodes (7): Development Roadmap, Milestone 1: ESP32 Basic Control (Week 1-2), Milestone 2: Bluetooth Integration (Week 2-3), Milestone 3: Safety Features (Week 3-4), Milestone 4: Full Control (Week 4-5), Milestone 5: Ergonomic Prototype (Week 5-6), Milestone 6: Refinement (Week 6+)

### Community 65 - "Community 65"
Cohesion: 0.29
Nodes (7): 1. Deadman Switch (Optional), 2. Timeout Protection, 3. Low Battery Warning, 4. Mode Indication, 5. Connection Loss Handling, Critical Safety Systems, Safety Features

### Community 67 - "Community 67"
Cohesion: 0.33
Nodes (6): 1. Core Hardware Components, 2. Essential Controls (Physical Switches), 3. Essential Indicators (Visual Feedback), 4. Essential Safety Features, 5. Software Requirements (Python + MicroPython), MUST-HAVE Features (Essential for MVP)

### Community 68 - "Community 68"
Cohesion: 0.33
Nodes (6): Additional Controls, Advanced Safety, Connectivity Enhancements, Display Enhancement, Enhanced Feedback, NICE-TO-HAVE Features (Post-MVP)

### Community 69 - "Community 69"
Cohesion: 0.33
Nodes (6): Additional Features, Client Questions for Feedback Session, Control Feel, Display vs. LEDs, Ergonomics, Safety Preferences

### Community 70 - "Community 70"
Cohesion: 0.33
Nodes (6): 1. Tactile Markers, 2. Audible Feedback (Optional), 3. Visual Design, 4. Grip Design, Accessibility Features, Universal Design Elements

### Community 71 - "Community 71"
Cohesion: 0.33
Nodes (6): Bluetooth Connection, Command Timing, Communication Requirements, Error Handling, Key Protocol Commands, Protocol Implementation

### Community 73 - "Community 73"
Cohesion: 0.40
Nodes (5): bleStartMotorTask(), Core 0, fake_wheel/, m25_ble.h/.cpp, M25 wheels (hardware)

### Community 74 - "Community 74"
Cohesion: 0.40
Nodes (5): Build & Flash, Code Generators, Commands, Credentials, Unit Tests

### Community 75 - "Community 75"
Cohesion: 0.40
Nodes (5): Communication Protocol, ESP32 Module Requirements, GPIO Pin Assignment (Suggested), Power Budget (Rough Estimates), Technical Specifications

### Community 76 - "Community 76"
Cohesion: 0.40
Nodes (5): Design Process & Client Iteration, Phase 1: Breadboard Prototype (Current Stage), Phase 2: Functional Mockup, Phase 3: Refined Prototype, Phase 4: Final Design

### Community 77 - "Community 77"
Cohesion: 0.40
Nodes (5): Components, Cost Estimation (DIY Build), Electronics, Housing, Manufacturing Considerations

### Community 78 - "Community 78"
Cohesion: 0.40
Nodes (5): Power Management, Power Saving, Power States, Remote Control Battery, Requirements

### Community 79 - "Community 79"
Cohesion: 0.40
Nodes (4): Fake M25 Wheel Simulator, Features, Setup, Troubleshooting

### Community 81 - "Community 81"
Cohesion: 0.50
Nodes (4): ADC1, ADC2, ControlState, joystick.h

### Community 82 - "Community 82"
Cohesion: 0.50
Nodes (4): Design Questions for Client, Must-Have (MVP), Nice-to-Have (Post-MVP), Summary Checklist

### Community 83 - "Community 83"
Cohesion: 0.50
Nodes (4): External References, References, Related Documentation, Source Code

### Community 84 - "Community 84"
Cohesion: 0.50
Nodes (4): Field Testing, Pre-Use Testing, Safety Testing, Testing Protocol

### Community 85 - "Community 85"
Cohesion: 0.67
Nodes (3): _audit(), M25 Remote Enclosure - VARIANT A, 2x2 button cluster ===========================, run()

### Community 86 - "Community 86"
Cohesion: 0.67
Nodes (3): _audit(), M25 Remote Enclosure - VARIANT B, single button row ============================, run()

### Community 87 - "Community 87"
Cohesion: 0.67
Nodes (3): esp_bt_gap_cb_event_t, esp_bt_gap_cb_param_t, _rfcommGapCb()

### Community 89 - "Community 89"
Cohesion: 0.67
Nodes (3): Mapper, Supervisor(), SupervisorConfig

## Ambiguous Edges - Review These
- `nvsSaveJsRange()` → `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)`  [AMBIGUOUS]
  ROADMAP.md · relation: references
- `wifi_joystick README` → `fake_wheel README`  [AMBIGUOUS]
  archive/wifi_joystick/README.md · relation: references

## Knowledge Gaps
- **435 isolated node(s):** `String`, `WheelRuntimeConfig`, `CliActions`, `WheelState`, `CmdResult` (+430 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **13 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **What is the exact relationship between `nvsSaveJsRange()` and `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)`?**
  _Edge tagged AMBIGUOUS (relation: references) - confidence is low._
- **What is the exact relationship between `wifi_joystick README` and `fake_wheel README`?**
  _Edge tagged AMBIGUOUS (relation: references) - confidence is low._
- **Why does `Remote Control Design Specification` connect `Fancy Light Module` to `Community 65`, `Community 70`, `Community 71`, `Community 77`, `Protocol Design Rationale`, `Community 78`, `Community 83`, `Community 84`, `Community 59`, `Community 60`?**
  _High betweenness centrality (0.024) - this node is a cross-community bridge._
- **Why does `ESP32 One-Handed Remote Control - Design Specification` connect `Community 58` to `Community 64`, `Community 67`, `Community 68`, `Community 69`, `Community 75`, `WiFi Joystick Config (Archived)`, `Protocol Design Rationale`, `Community 76`, `Community 82`?**
  _High betweenness centrality (0.019) - this node is a cross-community bridge._
- **Why does `Cross-Platform BLE Communication` connect `Protocol Design Rationale` to `RFCOMM Env Loader Script`?**
  _High betweenness centrality (0.018) - this node is a cross-community bridge._
- **Are the 27 inferred relationships involving `_scDispatch()` (e.g. with `buttonsPrintDebug()` and `joystickApplyFullRangeCalibration()`) actually correct?**
  _`_scDispatch()` has 27 INFERRED edges - model-reasoned connections that need verification._
- **Are the 14 inferred relationships involving `cli_poll()` (e.g. with `buzzer_beep()` and `buzzer_disable()`) actually correct?**
  _`cli_poll()` has 14 INFERRED edges - model-reasoned connections that need verification._