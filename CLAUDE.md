# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repo is

ESP32 firmware for standalone M25 wheelchair remote control. All firmware files live flat at the repo root (`src_dir = .` in `platformio.ini`). The Python protocol toolkit lives separately at [codeberg.org/roll2own/m5squared](https://codeberg.org/roll2own/m5squared).

## Commands

### Build & Flash

```bash
pio run                                          # build only
pio run -t upload --upload-port COMx            # build + flash (Windows)
pio run -t upload --upload-port /dev/ttyUSB0    # build + flash (Linux)
pio device monitor                               # serial monitor 115200 baud
```

Set port once in a local `settings.ini` (gitignored) instead of repeating `--upload-port`:
```ini
[env:esp32dev]
upload_port = COM9
```

### Credentials

```bash
cp .env.example .env   # fill in M25_LEFT_MAC, M25_LEFT_KEY, M25_RIGHT_MAC, M25_RIGHT_KEY
# load_env.py injects them as compiler flags automatically at build time
```

### Unit Tests

Tests are standalone Arduino sketches flashed to real hardware:

```powershell
# Windows — prepare build dir, then open in Arduino IDE or PlatformIO
cd tests
.\prepare_test.ps1 -TestName test_supervisor   # or test_mapper
# Open tests/_build_test_supervisor/ in IDE, flash, read Serial Monitor at 115200

# Automated CLI (requires Arduino CLI)
.\run_tests.ps1 -Board "esp32:esp32:esp32" -Port "COM8"
```

### Code Generators

The generators in `tools/` read from the Python toolkit — run them from the m5squared directory:

```bash
cd /path/to/m5squared
python tools/generate_constants.py   # → constants.h (commit result)
python tools/generate_profiles.py    # → profiles.h  (commit result)
python tools/generate_tests.py       # → test vectors
```

Generated files (`constants.h`, `profiles.h`) are committed to the repo so builds work without running the generators.

## Architecture

### Data flow

```
Joystick (ADC) → ControlState → Mapper → CommandFrame → Supervisor → BLE → M25 wheels
                                               ↑
                                          safety checks, watchdogs, state machine
```

### Key files

| File | Role |
|------|------|
| `device_config.h` | **All pin assignments, timing, feature flags** — start here for hardware changes |
| `remote_control.ino` | `setup()` / `loop()`, button dispatch, system state machine |
| `types.h` | `ControlState`, `CommandFrame`, `VehicleState`, `SupervisorState`, config structs |
| `mapper.h/.cpp` | Input → command (deadzone, curves, differential drive, speed limits) — **safety-critical** |
| `supervisor.h/.cpp` | State machine, input/link watchdogs, auto-reconnect, BLE connect task — **safety-critical** |
| `m25_ble.h/.cpp` | Full M25 BLE stack: AES-128-CBC, CRC-16, byte stuffing, GATT client, motor write task, response parser |
| `nvs_config.h` | Persist wheel MACs/keys/assist level to NVS (survives reboot); loaded in `setup()` |
| `serial_commands.h` | UART REPL — `serialInit()` in `setup()`, `serialTick()` in `loop()` |
| `Logger.h/.cpp` | Singleton tag-based logger; `logForced()` bypasses runtime filtering for safety events |
| `joystick.h` | ADC1 oversampling, deadzone, `joystickRecalibrate()` |

### Supervisor states

`DISCONNECTED` → `CONNECTING` → `PAIRED` → `ARMED` → `DRIVING` → `FAILSAFE`

There is also a legacy `SystemState` enum (BOOT/CONNECTING/READY/OPERATING/ERROR/OFF) kept only for serial command compatibility — it mirrors `SupervisorState` via `onSupervisorStateChange` callback. The authoritative state is always `SupervisorState`.

### BLE threading

- `loop()` runs on **Core 1**
- `bleStartMotorTask()` spawns motor writes on **Core 0** — prevents `writeValue()` blocking the loop
- `supervisor.update()` checks `bleLastMotorWriteOk()` each cycle; failed writes trigger failsafe

### ADC constraint

Joystick X/Y **must use ADC1 pins (GPIO 32–39)**. ADC2 (GPIO 0,2,4,12–15,25–27) is disabled while BLE/WiFi radio is active.

### Configuration priority

1. NVS (runtime `setmac`/`setkey`/`assist` serial commands — highest priority, survives reboot)
2. `.env` build-time injection via `load_env.py` (`ENV_*` macros)
3. `device_config.h` compiled-in defaults (fallback)

Use `config show` over serial to see which source is active for each setting.

## Feature flags (`device_config.h`)

| Flag | Effect |
|------|--------|
| `WHEEL_MODE` | `WHEEL_MODE_DUAL` / `LEFT_ONLY` / `RIGHT_ONLY` — compile-time default for single-wheel bench testing; runtime `wheels` serial command overrides it (NVS-persisted) |
| `NO_JOYSTICK` | Disables ADC; joystick always returns centered (bench testing without hardware) |
| `NO_DEADMAN_HARDWARE` | Ties deadman permanently HIGH — joystick leaving deadzone is sufficient to drive |
| `ENABLE_BATTERY_MONITOR` | ADC battery voltage on GPIO36 + auto-shutdown at `BATT_AUTO_OFF_PCT` |
| `ENABLE_IDLE_WATCHDOG` | Watchdog fires when joystick idles — only for self-centering (spring-loaded) sticks |
| `AUTO_ARM_ON_CONNECT` | PAIRED → ARMED automatically on BLE connect |

## fake_wheel/

Flash to a second ESP32. Simulates M25 wheel BLE behavior — responds to connection handshake and motor commands. Use when real hardware is unavailable.

## Safety-critical code

`mapper.h/.cpp` and `supervisor.h/.cpp` are safety-critical. Changes must be tested against `tests/test_mapper/` and `tests/test_supervisor/`. Watch for:
- Any path that bypasses the deadman check in Mapper
- Watchdog timeout logic in Supervisor
- State transitions that could leave motors running
- Use `logForced()` (not `LOG_INFO`) for emergency stop / failsafe events
