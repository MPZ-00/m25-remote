# Graph Report - .  (2026-07-06)

## Corpus Check
- 73 files · ~74,788 words
- Verdict: corpus is large enough that graph structure adds value.

## Summary
- 707 nodes · 1228 edges · 63 communities (37 shown, 26 thin omitted)
- Extraction: 92% EXTRACTED · 8% INFERRED · 0% AMBIGUOUS · INFERRED: 95 edges (avg confidence: 0.8)
- Token cost: 0 input · 596,545 output

## Community Hubs (Navigation)
- [[_COMMUNITY_Configuration Priority & Feature Flags|Configuration Priority & Feature Flags]]
- [[_COMMUNITY_BLE Threading & Connection State|BLE Threading & Connection State]]
- [[_COMMUNITY_Buttons & Buzzer Input|Buttons & Buzzer Input]]
- [[_COMMUNITY_Fake Wheel State & Commands (archive)|Fake Wheel State & Commands (archive)]]
- [[_COMMUNITY_WiFi Joystick BLE Scanner (archive)|WiFi Joystick BLE Scanner (archive)]]
- [[_COMMUNITY_Mapper & Supervisor Safety Pipeline|Mapper & Supervisor Safety Pipeline]]
- [[_COMMUNITY_Fake Wheel BLE Server & Buzzer|Fake Wheel BLE Server & Buzzer]]
- [[_COMMUNITY_RFCOMM Transport & Packet Codec (archive)|RFCOMM Transport & Packet Codec (archive)]]
- [[_COMMUNITY_Design Docs & Protocol Rationale|Design Docs & Protocol Rationale]]
- [[_COMMUNITY_BLE Wheel Getters & Diagnostics|BLE Wheel Getters & Diagnostics]]
- [[_COMMUNITY_Wheel Runtime Config CLI (archive)|Wheel Runtime Config CLI (archive)]]
- [[_COMMUNITY_Test Hardware Feedback Harness|Test Hardware Feedback Harness]]
- [[_COMMUNITY_BLE Motor Command Task|BLE Motor Command Task]]
- [[_COMMUNITY_BLE Response Frame Parsing|BLE Response Frame Parsing]]
- [[_COMMUNITY_CLI Debug Printing (archive)|CLI Debug Printing (archive)]]
- [[_COMMUNITY_BLE Transport Event Handling (archive)|BLE Transport Event Handling (archive)]]
- [[_COMMUNITY_RFCOMM Transport Event Handling (archive)|RFCOMM Transport Event Handling (archive)]]
- [[_COMMUNITY_LED & Buzzer Pattern Control|LED & Buzzer Pattern Control]]
- [[_COMMUNITY_BLE TX Stats Struct|BLE TX Stats Struct]]
- [[_COMMUNITY_Code Generator Scripts|Code Generator Scripts]]
- [[_COMMUNITY_BLE Connect & Status Strings|BLE Connect & Status Strings]]
- [[_COMMUNITY_BLE Disconnect & Link State|BLE Disconnect & Link State]]
- [[_COMMUNITY_Buzzer Control (archive)|Buzzer Control (archive)]]
- [[_COMMUNITY_BLE Client Callbacks & Parsing|BLE Client Callbacks & Parsing]]
- [[_COMMUNITY_WiFi Joystick Web UI (archive)|WiFi Joystick Web UI (archive)]]
- [[_COMMUNITY_load_env.py Git Helpers (archive)|load_env.py Git Helpers (archive)]]
- [[_COMMUNITY_LED Status Indicators (archive)|LED Status Indicators (archive)]]
- [[_COMMUNITY_Drive Profile Loading|Drive Profile Loading]]
- [[_COMMUNITY_M25 Packet Encryption|M25 Packet Encryption]]
- [[_COMMUNITY_RFCOMM SPP Callback (archive)|RFCOMM SPP Callback (archive)]]
- [[_COMMUNITY_Motor Command Struct|Motor Command Struct]]
- [[_COMMUNITY_M25 Protocol Constants|M25 Protocol Constants]]
- [[_COMMUNITY_Bluetooth GAP Callback (archive)|Bluetooth GAP Callback (archive)]]
- [[_COMMUNITY_load_env.py Key Injection|load_env.py Key Injection]]
- [[_COMMUNITY_Hardware Pin Assignments|Hardware Pin Assignments]]
- [[_COMMUNITY_Battery Drain Tick (archive)|Battery Drain Tick (archive)]]
- [[_COMMUNITY_Drive Profile Struct|Drive Profile Struct]]
- [[_COMMUNITY_Debounced Button Struct|Debounced Button Struct]]
- [[_COMMUNITY_Wheel Side Selection (fake_wheel)|Wheel Side Selection (fake_wheel)]]
- [[_COMMUNITY_LED State Enum (fake_wheel)|LED State Enum (fake_wheel)]]
- [[_COMMUNITY_Logger Singleton Instance|Logger Singleton Instance]]
- [[_COMMUNITY_Logger Singleton Class|Logger Singleton Class]]
- [[_COMMUNITY_Log Tag Bitmask|Log Tag Bitmask]]
- [[_COMMUNITY_BLE Poll Function (archive)|BLE Poll Function (archive)]]
- [[_COMMUNITY_BLE Send Function (archive)|BLE Send Function (archive)]]
- [[_COMMUNITY_CLI Debug Flag (archive)|CLI Debug Flag (archive)]]
- [[_COMMUNITY_Command Result Enum (archive)|Command Result Enum (archive)]]
- [[_COMMUNITY_Debug Flag Entry (archive)|Debug Flag Entry (archive)]]
- [[_COMMUNITY_LED Speed Indicator (archive)|LED Speed Indicator (archive)]]
- [[_COMMUNITY_Protocol Hex Print (archive)|Protocol Hex Print (archive)]]
- [[_COMMUNITY_RFCOMM Send Function (archive)|RFCOMM Send Function (archive)]]
- [[_COMMUNITY_Battery Safety Interval (archive)|Battery Safety Interval (archive)]]
- [[_COMMUNITY_State Init Function (archive)|State Init Function (archive)]]
- [[_COMMUNITY_Wheel Config Validation (archive)|Wheel Config Validation (archive)]]
- [[_COMMUNITY_Profile Params Struct|Profile Params Struct]]
- [[_COMMUNITY_Roadmap Enclosure Phase|Roadmap Enclosure Phase]]
- [[_COMMUNITY_Drive Mode Enum|Drive Mode Enum]]
- [[_COMMUNITY_WiFi Joystick BLE Callback (archive)|WiFi Joystick BLE Callback (archive)]]

## God Nodes (most connected - your core abstractions)
1. `_scDispatch()` - 46 edges
2. `cli_poll()` - 22 edges
3. `bleIsConnected()` - 22 edges
4. `_sendCommand()` - 21 edges
5. `_wheelActive()` - 19 edges
6. `cli_poll(act, state)` - 19 edges
7. `transitionTo()` - 17 edges
8. `TxStats` - 15 edges
9. `logForced()` - 14 edges
10. `handleSerialCommand()` - 13 edges

## Surprising Connections (you probably didn't know these)
- `handleSerialCommand()` --semantically_similar_to--> `handleSerialCommand()`  [INFERRED] [semantically similar]
  fake_wheel/command_handler.h → archive/wifi_joystick/serial_commands.h
- `RSSI-gated arming: block arming below BLE signal threshold (planned safety feature, 3.2)` --conceptually_related_to--> `bleIsConnected()`  [INFERRED]
  ROADMAP.md → m25_ble.cpp
- `calculateMotorCommand()` --semantically_similar_to--> `differentialDrive()`  [INFERRED] [semantically similar]
  motor_control.h → mapper.cpp
- `ROADMAP Phase 2: Telemetry & UI (in progress)` --references--> `nvsLoadAssistLevel()`  [EXTRACTED]
  ROADMAP.md → nvs_config.h
- `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)` --references--> `nvsSaveJsRange()`  [AMBIGUOUS]
  ROADMAP.md → nvs_config.h

## Import Cycles
- None detected.

## Hyperedges (group relationships)
- **Safety-critical control pipeline: input state -> mapper safety rules -> supervisor watchdogs** — types_controlstate, mapper_map, supervisor_processinput, supervisor_checkwatchdogs [INFERRED 0.85]
- **Dual-core BLE threading pattern: Core 0 connect/motor tasks serialized via TX mutex, Core 1 loop** — supervisor_connecttaskbody, m25_ble_blestartmotortask, m25_ble_bletxmutex [INFERRED 0.85]
- **Three-tier configuration priority: NVS overrides > .env build flags > compiled device_config.h defaults** — nvs_config_nvsloadmac, load_env_module, device_config_wheel_mode [INFERRED 0.85]
- **M25 packet encode/decode pipeline (protocol framing + crypto + packet codec)** — m25_wheel_rfcomm_proto_frame_parse, m25_wheel_rfcomm_proto_frame_build, m25_wheel_rfcomm_crypto_ecb_decrypt, m25_wheel_rfcomm_crypto_ecb_encrypt, m25_wheel_rfcomm_crypto_cbc_decrypt, m25_wheel_rfcomm_crypto_cbc_encrypt, m25_wheel_rfcomm_packet_decode, m25_wheel_rfcomm__packet_encode_spp [EXTRACTED 1.00]
- **Mirrored connect/disconnect event handling across BLE and RFCOMM transports** — m25_wheel_rfcomm_ble_check_events, m25_wheel_rfcomm_ble_on_connect, m25_wheel_rfcomm_ble_on_disconnect, m25_wheel_rfcomm_rfcomm_check_events, m25_wheel_rfcomm_rfcomm_on_connect, m25_wheel_rfcomm_rfcomm_on_disconnect [EXTRACTED 1.00]
- **Wheel identity/config/state management (compile defaults + NVS runtime override + simulated state)** — m25_wheel_rfcomm_config, m25_wheel_rfcomm_wheelruntimeconfig, m25_wheel_rfcomm_wheelstate, m25_wheel_rfcomm__cli_handle_config, m25_wheel_rfcomm_wheelcfg_load [INFERRED 0.85]
- **Joystick input to encrypted BLE wheel command pipeline** — wifi_joystick_joystick_input_readphysicaljoystick, wifi_joystick_wheel_command_joysticktowheelspeeds, wifi_joystick_wheel_command_sendwheelcommand, wifi_joystick_encryption_encryptpacket, wifi_joystick_websocket_handlers_websocketevent [INFERRED 0.85]
- **Fake wheel serial command drives state, LED and buzzer feedback** — fake_wheel_command_handler_handleserialcommand, fake_wheel_wheel_state_wheelstate, fake_wheel_led_control_showbatterylevel, fake_wheel_buzzer_control_playbeep [INFERRED 0.80]
- **BLE wheel discovery, connect/disconnect exposed via serial and WebSocket UI** — wifi_joystick_ble_scanner_startwheelscan, wifi_joystick_ble_scanner_connecttoble, wifi_joystick_websocket_handlers_websocketevent, wifi_joystick_serial_commands_handleserialcommand [INFERRED 0.80]
- **Arduino Test Hardware Feedback System** — tests_test_base, tests_hardware_setup, tests_readme, concept_test_hardware_feedback [INFERRED 0.85]
- **BLE Notification Power-Efficiency Pattern** — doc_ble_cross_platform, doc_ble_notifications_how_it_works, concept_ble_notifications_vs_polling, concept_nordic_uart_service [INFERRED 0.85]
- **M25 Remote Control Protocol Command Mapping** — doc_m25_protocol, doc_remote_control_design, doc_esp32_remote_design_spec [INFERRED 0.80]

## Communities (63 total, 26 thin omitted)

### Community 0 - "Configuration Priority & Feature Flags"
Cohesion: 0.07
Nodes (55): Configuration priority: NVS > .env build flags > device_config.h defaults, Feature flags documentation table, AUTO_ARM_ON_CONNECT flag, ENCRYPTION_KEY_LEFT/RIGHT compiled-in default AES keys, NO_DEADMAN_HARDWARE: joystick-only trigger, no deadman button (safety bypass - remove once wired), NO_JOYSTICK flag (bench testing without ADC hardware), WHEEL_MODE (DUAL/LEFT_ONLY/RIGHT_ONLY) compile-time default, joystickRecalibrate() (+47 more)

### Community 1 - "BLE Threading & Connection State"
Cohesion: 0.07
Nodes (50): BLE threading model: loop() on Core 1, motor writes on Core 0, bleAllConnected(), bleAnyConnected(), bleConnectWheel(), bleGetBattery(), bleGetDistanceKm(), bleGetLastNotifyMs(), bleLastMotorWriteOk() (+42 more)

### Community 2 - "Buttons & Buzzer Input"
Cohesion: 0.07
Nodes (38): buttonsInit(), buttonsPrintDebug(), buttonsTick(), tick(), buzzerInit(), buzzerPlay(), BuzzerPattern, ADC constraint: joystick must use ADC1 pins (GPIO 32-39) (+30 more)

### Community 3 - "Fake Wheel State & Commands (archive)"
Cohesion: 0.09
Nodes (31): WheelState, WheelState, WheelState, WheelState, CmdResult, command_apply(), crypto_cbc_decrypt(), crypto_cbc_encrypt() (+23 more)

### Community 4 - "WiFi Joystick BLE Scanner (archive)"
Cohesion: 0.09
Nodes (28): class, String, PhysicalJoystickState, BLEAdvertisedDeviceCallbacks(), BLEClientCallbacks(), connectToBLE(), connectToWheel(), disconnectBLE() (+20 more)

### Community 5 - "Mapper & Supervisor Safety Pipeline"
Cohesion: 0.09
Nodes (30): Data flow: Joystick -> ControlState -> Mapper -> CommandFrame -> Supervisor -> BLE -> M25 wheels, Safety-critical code guidance (mapper.h/.cpp, supervisor.h/.cpp), Supervisor state machine documentation, SystemState enum (legacy, serial-command compatibility), core/mapper.py (external Python reference implementation), core/supervisor.py (external Python reference implementation), core/types.py (external Python reference implementation), applyCurve() (+22 more)

### Community 6 - "Fake Wheel BLE Server & Buzzer"
Cohesion: 0.09
Nodes (19): BLECharacteristic, BLEServer, playBeep(), playTone(), testBuzzers(), WheelState, handleSerialCommand(), initCommandHandler() (+11 more)

### Community 7 - "RFCOMM Transport & Packet Codec (archive)"
Cohesion: 0.09
Nodes (30): class _BleRxCB, class _BleServerCB, _packet_encode_spp(spp, sppLen, key, out), _rfcomm_spp_callback(event, param), _rfcomm_try_parse(out, outLen), ble_init(name, serviceUUID, txUUID, rxUUID), buzzer_init(), struct CliActions (+22 more)

### Community 8 - "Design Docs & Protocol Rationale"
Cohesion: 0.12
Nodes (26): BLE Notifications vs Polling (Power Efficiency), Deadman Switch Design (button vs capacitive touch), ESP32 MicroPython BLE Prototype (ubluetooth-based), M25 Encrypted Packet Format (AES-128-CBC + CRC-16 + byte stuffing), m5squared Python Protocol Toolkit, Nordic UART Service (NUS), Watchdog / Timeout Safety Mechanism, data/index.html web joystick UI (+18 more)

### Community 9 - "BLE Wheel Getters & Diagnostics"
Cohesion: 0.10
Nodes (8): bleFullReset(), bleGetMac(), bleInit(), blePrintWheelDetails(), bleWheelModeName(), _debugLogTxPacket(), _paramName(), _wheelNameOrDefault()

### Community 10 - "Wheel Runtime Config CLI (archive)"
Cohesion: 0.14
Nodes (23): String, WheelRuntimeConfig, WheelRuntimeConfig, _cli_handle_config(arg, cfg), _cli_handle_config(), wheelcfg_clear(), wheelcfg_compiled_default_side(), wheelcfg_fill_runtime() (+15 more)

### Community 11 - "Test Hardware Feedback Harness"
Cohesion: 0.16
Nodes (16): OLED/Buzzer/LED Test Feedback Harness, test_mapper.ino (Mapper safety tests), test_supervisor.ino (Supervisor state machine tests), tests/README.md, buzzFailure(), buzzSuccess(), buzzTestEnd(), buzzTestStart() (+8 more)

### Community 12 - "BLE Motor Command Task"
Cohesion: 0.17
Nodes (20): bleIsConnected(), _bleMotorTask(), bleRequestCruiseValues(), bleRequestFirmwareVersion(), bleRequestSOC(), bleSendAssistLevel(), bleSendHillHold(), bleSendMotorCommand() (+12 more)

### Community 13 - "BLE Response Frame Parsing"
Cohesion: 0.15
Nodes (19): BLERemoteCharacteristic, _bleRecordFrame(), _hexSnippet(), _isAck(), _isNack(), _m25Crc16(), _m25Decrypt(), _nackCodeToString() (+11 more)

### Community 14 - "CLI Debug Printing (archive)"
Cohesion: 0.18
Nodes (16): WheelState, CliActions, _cli_print_key(key), cli_poll(), _cli_print_debug_flags(), _cli_print_hardware(), _cli_print_help(), _cli_print_key() (+8 more)

### Community 15 - "BLE Transport Event Handling (archive)"
Cohesion: 0.15
Nodes (8): class, ble_check_events(onConnect, onDisconnect), ble_check_events(), ble_on_connect(), ble_on_disconnect(), ble_stale_count(), BLECharacteristicCallbacks(), BLEServerCallbacks()

### Community 16 - "RFCOMM Transport Event Handling (archive)"
Cohesion: 0.17
Nodes (12): esp_spp_cb_event_t, esp_spp_cb_param_t, rfcomm_poll(out, outLen), rfcomm_check_events(), _rfcomm_drain(), _rfcomm_drop_until_header(), rfcomm_on_connect(), rfcomm_on_disconnect() (+4 more)

### Community 17 - "LED & Buzzer Pattern Control"
Cohesion: 0.24
Nodes (15): BuzzerPatternDef / PATTERNS table, ledInit(), ledSetAssistLevel(), ledSetBattery(), ledSetBleMode(), _ledSetDuty(), ledSetHillHold(), _ledSetMode() (+7 more)

### Community 18 - "BLE TX Stats Struct"
Cohesion: 0.13
Nodes (15): TxStats, assistLevel, driveMode, driveModeWriteFail, other, readCruise, readFw, readSoc (+7 more)

### Community 19 - "Code Generator Scripts"
Cohesion: 0.21
Nodes (12): generate_constants_header(), main(), Generate constants.h from m25_protocol_data.py, generate_profiles_header(), main(), Generate profiles.h from m25_ecs_driveprofiles.py, generate_mapper_tests(), generate_supervisor_state_tests() (+4 more)

### Community 20 - "BLE Connect & Status Strings"
Cohesion: 0.15
Nodes (13): esp_bd_addr_t, esp_bluedroid_status_t, esp_bt_controller_status_t, bleConnect(), _bleErrStr(), bleRecordDump(), bleTick(), _bluedroidStatusStr() (+5 more)

### Community 21 - "BLE Disconnect & Link State"
Cohesion: 0.22
Nodes (13): bleDisconnect(), bleResetWheel(), bleSetKey(), bleSetMac(), _clearTxFailureState(), _getWheels(), _transportClearLinkState(), _transportDisconnectLink() (+5 more)

### Community 22 - "Buzzer Control (archive)"
Cohesion: 0.24
Nodes (11): buzzer_beep(count), buzzer_beep(), buzzer_disable(), buzzer_enable(), buzzer_is_enabled(), buzzer_speed_tone(), buzzer_stop(), buzzer_test() (+3 more)

### Community 23 - "BLE Client Callbacks & Parsing"
Cohesion: 0.20
Nodes (7): BLEClient, class, M25DisconnectCallback(), onConnect(), onDisconnect(), _parseInt32BE(), _parseUint32BE()

### Community 24 - "WiFi Joystick Web UI (archive)"
Cohesion: 0.31
Nodes (9): active, catch, function, e(), resetStick(), sendJoystickData(), updateStickPosition(), x (+1 more)

### Community 25 - "load_env.py Git Helpers (archive)"
Cohesion: 0.29
Nodes (4): _find_git_root(start_dir), _git_cmd(repo_dir, *args), _hex_to_c_bytes(hex_str), PlatformIO pre-build script: load_env.py  Reads only the local sketch .env and i

### Community 27 - "Drive Profile Loading"
Cohesion: 0.47
Nodes (5): DriveProfile, ProfileParams, getProfileById(), getProfileByName(), loadProfileParams()

### Community 28 - "M25 Packet Encryption"
Cohesion: 0.33
Nodes (6): _addDelimiters(), _buildAndEncrypt(), _m25Encrypt(), m25_crypto.py (external, AES-128-CBC reference), m25_protocol.py (external, CRC-16/byte-stuffing reference), README protocol summary (BLE GATT packet structure)

### Community 29 - "RFCOMM SPP Callback (archive)"
Cohesion: 0.50
Nodes (5): esp_spp_cb_event_t, esp_spp_cb_param_t, _findWheelByHandle(), _rfcommSppCb(), _sppEvtName()

### Community 30 - "Motor Command Struct"
Cohesion: 0.50
Nodes (4): _MotorCmd, isStop, left, right

### Community 31 - "M25 Protocol Constants"
Cohesion: 0.67
Nodes (3): M25 protocol constants (auto-generated), M25_* protocol constants (service/param IDs, NACK codes), m25_protocol_data.py (external, source of generated constants)

### Community 32 - "Bluetooth GAP Callback (archive)"
Cohesion: 0.67
Nodes (3): esp_bt_gap_cb_event_t, esp_bt_gap_cb_param_t, _rfcommGapCb()

## Ambiguous Edges - Review These
- `nvsSaveJsRange()` → `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)`  [AMBIGUOUS]
  ROADMAP.md · relation: references
- `WheelConnState_t (per-wheel connection state)` → `Force-include override of CONFIG_BT_HFP_ENABLE to suppress unwanted BT pragma warning`  [AMBIGUOUS]
  suppress_bt_pragma.h · relation: conceptually_related_to
- `_find_git_root(start_dir)` → `_git_cmd(repo_dir, *args)`  [AMBIGUOUS]
  archive/m25_wheel_rfcomm/load_env.py · relation: calls
- `packet_decode(raw, rawLen, key, spp, sppLen)` → `struct WheelState`  [AMBIGUOUS]
  archive/m25_wheel_rfcomm/packet.h · relation: shares_data_with
- `wifi_joystick README` → `fake_wheel README`  [AMBIGUOUS]
  archive/wifi_joystick/README.md · relation: references

## Knowledge Gaps
- **141 isolated node(s):** `String`, `WheelRuntimeConfig`, `CliActions`, `WheelState`, `CmdResult` (+136 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **26 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **What is the exact relationship between `nvsSaveJsRange()` and `ROADMAP 2.6: persist joystick full-range calibration to NVS (marked pending)`?**
  _Edge tagged AMBIGUOUS (relation: references) - confidence is low._
- **What is the exact relationship between `WheelConnState_t (per-wheel connection state)` and `Force-include override of CONFIG_BT_HFP_ENABLE to suppress unwanted BT pragma warning`?**
  _Edge tagged AMBIGUOUS (relation: conceptually_related_to) - confidence is low._
- **What is the exact relationship between `_find_git_root(start_dir)` and `_git_cmd(repo_dir, *args)`?**
  _Edge tagged AMBIGUOUS (relation: calls) - confidence is low._
- **What is the exact relationship between `packet_decode(raw, rawLen, key, spp, sppLen)` and `struct WheelState`?**
  _Edge tagged AMBIGUOUS (relation: shares_data_with) - confidence is low._
- **What is the exact relationship between `wifi_joystick README` and `fake_wheel README`?**
  _Edge tagged AMBIGUOUS (relation: references) - confidence is low._
- **Why does `_scDispatch()` connect `Configuration Priority & Feature Flags` to `LED & Buzzer Pattern Control`, `Buttons & Buzzer Input`, `BLE Motor Command Task`, `BLE Threading & Connection State`?**
  _High betweenness centrality (0.079) - this node is a cross-community bridge._
- **Why does `BLEServer` connect `Fake Wheel BLE Server & Buzzer` to `BLE Transport Event Handling (archive)`?**
  _High betweenness centrality (0.049) - this node is a cross-community bridge._