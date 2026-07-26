# Remote control redesign — no-deadman, 3-button, integrated-LED version

Status: exploratory design, not yet implemented. This is a thought-in-progress; the
project expects to try several versions before settling. It doubles as the
handoff spec for enclosure/CAD work (button + LED placement, pinout, cabling).

## Context

Today's firmware (`device_config.h`, `remote_control.ino`, `led_control.h`,
`button.h`) implements a 4-button, 5-discrete-LED test rig with no display,
where `NO_DEADMAN_HARDWARE` already ties the deadman permanently true
(joystick-only drive). This spec describes a redesign toward a compact
3-primary-button layout with LEDs built into the buttons themselves, plus two
standalone status LEDs. It does not change `mapper.cpp` or any speed/turn/reverse
safety limits.

## Goals

- No dedicated deadman button — arming and driving are triggered by joystick
  movement alone (formalizing what `NO_DEADMAN_HARDWARE` already does today).
- Auto-arm on joystick movement, auto-disarm after standing idle.
- Primary controls: E-stop, hill-hold toggle, assist-level cycle.
- Each of those three buttons has its own integrated LED.
- Two standalone status LEDs: white = connection status, red = error status.
- No display.
- Stay close to what's currently defined in `device_config.h` so the eventual
  firmware change is incremental, not a rewrite.

## Non-goals (for this version)

- No firmware code changes yet — this document is the spec; an implementation
  plan and code changes are a separate, later step.
- No enclosure/CAD work performed here — this spec is written so it can be
  handed to a separate enclosure-design workflow (Fusion MCP), but that work
  is out of scope for this document.
- No battery-level LED indication (dropped for this version; battery % stays
  available over serial if `ENABLE_BATTERY_MONITOR` is enabled).
- No decision on E-stop-long-press-as-power — see Open Questions.

## State machine changes

No new `SupervisorState` values. The existing state machine
(`DISCONNECTED → CONNECTING → PAIRED → ARMED → DRIVING`, with `FAILSAFE` as an
interrupt state) is kept. One behavioral addition:

- **PAIRED auto-arms.** Today, `PAIRED → ARMED` only happens via an explicit
  `requestArm()` call (serial command); `ARMED → DRIVING` already auto-transitions
  when the joystick leaves the deadzone continuously for `JS_ACTIVATE_HOLD_MS`
  (100 ms). This spec extends the same hysteresis to `PAIRED`: joystick out of
  deadzone continuously for `JS_ACTIVATE_HOLD_MS` while PAIRED arms and starts
  driving in the same tick. ARMED remains a real but effectively instantaneous
  transit state — there is no user-facing "armed and waiting" moment, no arm
  button, no arm confirmation tone.
- **Disarm ("standby") is already correct as-is.** `DRIVING → ARMED` after
  `JS_IDLE_HOLD_MS` (300 ms) of a centered stick, then `ARMED → PAIRED` after
  `armIdleTimeoutMs` (60 s, unchanged) of continued idle. This satisfies
  "disarm on standby" with no timeout change.
- `requestArm()` / `requestDisarm()` stay available for serial/manual use
  exactly as they work today.

## Buttons

All 4 physical buttons from today are kept: **E-stop, hill-hold, assist,
power.** No long-press or dual-duty logic is introduced in this version — the
power button keeps working exactly as it does today (separate from E-stop).

Existing per-state behavior is preserved:
- Hill-hold: toggles while PAIRED/ARMED, ignored while DRIVING or disconnected.
- Assist: cycles indoor/outdoor/learning while PAIRED; cycles drive-feel
  presets while ARMED/DRIVING (dual behavior added recently — kept as-is,
  since the redesign's "cycle assist level" wording was shorthand, not a
  request to remove the feel-preset cycling).
- E-stop: unchanged — immediate stop/reconnect on press, no delay.

## LEDs

Existing pin assignments and LEDC channels are **not** renamed or reused.
Where a button's LED needs a pin that doesn't exist yet, a new pin is added —
the "LED built into the button" is a mechanical integration (LED and switch
sharing one physical button body), not a pin-sharing trick; it still needs its
own GPIO and its own cable back to the board.

| LED | Pin | Behavior |
|---|---|---|
| Status (red) | `LED_STATUS_PIN` (16, unchanged) | Error-only: off = normal, fast blink (2 Hz) = FAILSAFE. Drops today's slow-blink-on-CONNECTING case, since that's redundant with the white LED already blinking slow while no wheel is connected. |
| BLE / connection (white) | `LED_BLE_PIN` (17, unchanged) | Unchanged: off = not initialized, slow blink = searching, fast blink = partial connection, solid = all wheels connected. |
| Hill-hold (button-integrated) | `LED_HILL_HOLD_PIN` (18, unchanged) | Unchanged: solid = active, off = inactive. |
| Assist (button-integrated) | `LED_ASSIST_PIN` (19, unchanged) | New encoding: blink-count pattern — 1 blink = indoor, 2 = outdoor, 3 = learning, repeating with a pause between cycles. Replaces today's off/solid/slow-blink encoding (which only worked because there were 3 levels and 3 distinguishable static states available). |
| Battery | `LED_BATTERY_PIN` (27, unchanged) | Indication dropped this version. Pin stays defined/reserved in `device_config.h`; not renamed, not repurposed for anything else. |
| **E-stop (button-integrated, new)** | **New pin — proposing GPIO 21** (alternates: 22, 5, 4) | On solid = ARMED or DRIVING (i.e. "the chair will respond if you touch the stick"), off in DISCONNECTED/CONNECTING/PAIRED/FAILSAFE. New LEDC channel (proposing channel 5, next free slot after 0-4). |

## Pinout summary (for enclosure/wiring handoff)

| Function | Pin | Notes |
|---|---|---|
| Joystick X | GPIO 32 | ADC1_CH4 |
| Joystick Y | GPIO 33 | ADC1_CH5 |
| Battery sense | GPIO 36 | ADC1_CH0, input-only; only wired if `ENABLE_BATTERY_MONITOR` |
| Button: E-stop | GPIO 14 | Active low, internal pull-up; bootstrap pin (MTMS) — safe as input |
| Button: Hill-hold | GPIO 25 | Active low, internal pull-up |
| Button: Assist | GPIO 26 | Active low, internal pull-up |
| Button: Power | GPIO 13 | Active low, internal pull-up; unchanged this version |
| LED: Status (red, standalone) | GPIO 16 | PWM (LEDC ch 0) |
| LED: BLE (white, standalone) | GPIO 17 | PWM (LEDC ch 4) |
| LED: Hill-hold (in button) | GPIO 18 | PWM (LEDC ch 2) |
| LED: Assist (in button) | GPIO 19 | PWM (LEDC ch 3) |
| LED: Battery (reserved, unused) | GPIO 27 | PWM (LEDC ch 1); not driven this version |
| LED: E-stop (in button, new) | GPIO 21 (proposed) | PWM (LEDC ch 5, new) |
| Buzzer | GPIO 23 | Active buzzer, unchanged |

Each button-integrated LED requires its own cable pair back to the controller
board in addition to the button's own switch wiring — i.e. each of the 3
primary buttons is a 4-wire part (switch × 2, LED × 2), not 2-wire.

## Open questions

- **E-stop long-press as power toggle.** Considered during this design pass
  but explicitly deferred: it would let a future enclosure drop to 3 buttons
  total (freeing `BTN_POWER_PIN`/GPIO 13 and its wiring), with E-stop always
  firing its instant stop/reconnect action on press-down (unchanged, zero
  added latency) and a separate one-shot long-hold timer toggling power after
  holding through the stop. Not decided; revisit once the enclosure direction
  firms up.
- **GPIO 21 for the new E-stop LED** is a proposal, not a hardware-verified
  pick — confirm against the final board/enclosure layout before wiring.
