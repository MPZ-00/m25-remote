# m25-remote

ESP32 firmware for one-handed remote control of Alber e-motion M25 power-assist wheels.

Replaces the €595 ECS remote. Runs standalone — no phone or PC required during operation.

## Hardware

ESP32-WROOM-32 with:
- Analog joystick (KY-023 or similar) on GPIO 32 (X) / 33 (Y) — ADC1 only, ADC2 blocked by BLE
- E-stop button GPIO 14, hill-hold GPIO 25, assist GPIO 26, power GPIO 13
- Status LEDs GPIO 16/17/18/19/27, buzzer GPIO 23

Full pinout and timing constants: [`device_config.h`](device_config.h)

## Quick Start

### 1. Credentials

```bash
cp .env.example .env
# Fill in M25_LEFT_MAC, M25_LEFT_KEY, M25_RIGHT_MAC, M25_RIGHT_KEY
# Keys come from the QR sticker on each wheel hub — use m25_qr_to_key.py from the Python toolkit
```

### 2. Build & Flash

```bash
pio run -t upload --upload-port COMx    # Windows
pio run -t upload --upload-port /dev/ttyUSB0   # Linux
```

Or set `upload_port` once in a local `settings.ini` (gitignored):
```ini
[env:esp32dev]
upload_port = COM9
```

### 3. Serial interface

Connect at 115200 baud, type `help`. Key commands:

```
status          System state, BLE, telemetry, watchdogs
arm / disarm    PAIRED ↔ ARMED
stop            Emergency stop → FAILSAFE
reset           FAILSAFE → reconnect
setmac / setkey Change wheel credentials (persisted to NVS)
config show     Show active MAC/key source (NVS vs build default)
js              Joystick snapshot
log tag motor on  Enable 20 Hz motor command logging
record start [N]  Capture BLE traffic for N seconds
```

## State Machine

```
BOOT → (safety check) → CONNECTING → PAIRED → ARMED → DRIVING
                                                         ↓
                                               FAILSAFE (e-stop / watchdog / link loss)
                                                         ↓
                                               reset → CONNECTING
```

Power button enters deep sleep (OFF) from any state; wakes on power button press.

## Configuration

Three-tier priority (highest wins):
1. **NVS** — set at runtime via `setmac`/`setkey`, survives reboot
2. **`.env`** — injected by `load_env.py` at build time (`ENV_*` macros)
3. **`device_config.h`** — compiled-in fallback

Key feature flags in `device_config.h`:

| Flag | Purpose |
|------|---------|
| `WHEEL_MODE` | `DUAL` / `LEFT_ONLY` / `RIGHT_ONLY` — single-wheel bench testing |
| `NO_JOYSTICK` | ADC reads disabled, always returns centered (bench testing) |
| `NO_DEADMAN_HARDWARE` | Deadman tied HIGH — joystick leaving deadzone is sufficient |
| `ENABLE_BATTERY_MONITOR` | ADC battery read on GPIO36 + auto-shutdown |

## Repo Layout

```
.                   Main firmware (flat, src_dir = .)
├── device_config.h All pins, timing, feature flags
├── remote_control.ino  Main loop + system state machine
├── m25_ble.h/.cpp  Full M25 BLE stack (encryption, GATT, response parser)
├── supervisor.h/.cpp   State machine, watchdogs, reconnect
├── mapper.h/.cpp   Input → command transformation (safety-critical)
├── types.h         Shared data structures
├── fake_wheel/     Simulated M25 wheel — for testing without real hardware
├── tests/          Unit test sketches (mapper, supervisor)
├── tools/          Code generators (need m5squared Python toolkit to run)
├── archive/        Experiments: wifi_joystick, m25_wheel_rfcomm
└── doc/            Protocol and design documentation
```

## Testing Without Hardware

Flash `fake_wheel/` to a second ESP32. It advertises as an M25 wheel over BLE and
responds to the connection handshake and motor commands, letting you develop and test
the remote firmware without access to real wheels.

## Protocol

Bluetooth SPP / BLE GATT. Packets:
```
[0xEF] [len:2] [IV encrypted AES-128-ECB: 16B] [payload AES-128-CBC: N] [CRC-16: 2]
```
Keys from QR codes on wheel hubs. See [`doc/m25-protocol.md`](doc/m25-protocol.md).

## Related

- Python toolkit + full protocol implementation: [codeberg.org/roll2own/m5squared](https://codeberg.org/roll2own/m5squared)
  — use `m25_qr_to_key.py` to derive keys, `m25_ecs.py` for live protocol debugging
