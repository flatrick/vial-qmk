# Vial keymap for Planck rev4

Adds [Vial](https://get.vial.today) support to the OLKB Planck rev4 (ATmega32u4 + atmel-dfu bootloader, 4×12 ortholinear). 
The base layer is **Svorak** (Swedish Dvorak).

After flashing, all keymap/macro/setting changes are made live in the Vial desktop app — no rebuild needed for day-to-day tweaks.

---

## Why this exists

No Vial keymap shipped with the rev4 in vial-qmk. Every other Planck variant with Vial support (`rev6_drop`, `rev7`, `light`, `ez/glow`) uses a more capable MCU (STM32F303 or at90usb1286, both with ≥128 KB flash). 
The rev4's ATmega32u4 has only **28 KB of usable flash** (32 KB total minus the 4 KB atmel-dfu bootloader), which makes fitting Vial non-trivial — every feature flag matters.

---

## Layout

- **Base layer**: Svorak (Swedish DVORAK) — Esc at top-left, Tab on the second row, ISO modifiers
- **Bottom row**: 2u spacebar (MIT layout). Matrix position `(3,6)` is set to `KC_NO` on the base layer because some Planck PCBs bridge `(3,5)` and `(3,6)` electrically; binding both to `KC_SPC` would register two spaces per press. Vial users with a grid (2×1u) PCB can remap `(3,6)` themselves.
- **Layers**: 4 total — Svorak base, Lower (symbols/F-keys/media), Raise (numbers/nav), and a fully transparent spare layer for free use in Vial.

---

## Build configuration

### Enabled

| Setting | Value | Why |
|---------|-------|-----|
| `VIA_ENABLE` / `VIAL_ENABLE` | yes | Core Vial support |
| `TAP_DANCE_ENABLE` | yes | Tap-vs-hold-vs-double-tap behavior, configurable in Vial GUI. Used for paired-bracket behavior (tap `(`, hold `)`, etc.) |
| `COMBO_ENABLE` | yes | Press 2+ keys simultaneously for a different keycode (e.g., `J+K → Esc`). Configurable in Vial. |
| `CAPS_WORD_ENABLE` | yes | Double-tap shift to auto-shift the next word until space/punct — great for `SCREAMING_SNAKE_CASE` in SQL, env vars, Rust consts. |
| `NKRO_ENABLE` | yes (inherited from `keyboard.json`) | Required for gaming — N-key rollover |
| `EXTRAKEY_ENABLE` | yes (inherited) | Media keys (mute/vol/play/prev/next) used on the Lower layer |
| `BOOTMAGIC_ENABLE` | yes (inherited) | Hold top-left key (Esc, at matrix `(0,0)`) during USB plug-in → enters bootloader |
| `LTO_ENABLE` | yes | Compiler dead-code elimination — non-negotiable on a 28 KB budget |

### Disabled

| Setting | Why disabled |
|---------|--------------|
| `AUDIO_ENABLE` | Largest single flash consumer on the chip; would blow the 28 KB budget by itself |
| `MIDI_ENABLE` | Pairs with audio — not needed without it |
| `CONSOLE_ENABLE` | Saves flash + frees a USB endpoint |
| `QMK_SETTINGS` | Was briefly enabled to expose tap-hold/timing settings in Vial, but on inspection none of the exposed settings were useful enough to warrant the ~4.8 KB flash cost. `TAPPING_TERM` etc. are back to being compile-time. |
| `MAGIC_ENABLE` | Magic keycodes (`AG_SWAP`, `NK_TOGG`, `CG_TOGG`, etc.) are not used in the Svorak keymap. NKRO itself still works; only the runtime *toggle* keycode is gone. |
| `BACKLIGHT_ENABLE` | This rev4 has no LEDs installed. Explicit `no` guards against future `keyboard.json` changes pulling it in. |
| `MOUSEKEY_ENABLE` | Already off in `keyboard.json` |

### Tuned settings (`config.h`)

- `VIAL_KEYBOARD_UID` — unique 8-byte ID generated with `util/vial_generate_keyboard_uid.py`
- `VIAL_UNLOCK_COMBO` — Esc `(0,0)` + Space `(3,5)`, held 5 s, to unlock for changes
- `DYNAMIC_KEYMAP_LAYER_COUNT 4` — fits comfortably in the 1 KB EEPROM
- `DEBOUNCE 10` — doubled from QMK's default 5 ms to mitigate spacebar / stabilizer bounce (a previous rev5 board with the same physical layout exhibited double-press symptoms; this is a belt-and-suspenders mitigation on top of the `(3,6) = KC_NO` matrix fix)

---

## Memory budget (avr-size)

```
Program: 23,636 / 28,672 bytes (82% — 5,036 bytes free)
Data:     1,092 /  2,560 bytes (43%)
```

Comfortable headroom on both flash and SRAM. 
Room for one or two more compile-time features if needed (leader key, key overrides, mouse keys, etc.).

---

## Required upstream patch

A small fix is needed in `quantum/send_string/send_string.c` for the build to succeed with `avr-gcc 15.1+`:

```c
#ifdef __AVR__
#    include <avr/io.h>
#endif
```

The `tap_random_base64` function references AVR timer registers (`TCNT0/1/3/4`) which `avr-gcc 15+` no longer pulls in transitively. 
This affects **all** AVR builds in the repo, not just this keymap.

---

## Build

From the vial-qmk root:

```bash
make planck/rev4:vial
```

Output: `planck_rev4_vial.hex` in the repo root.

---

## Flash

Enter bootloader (hold the top-left key while plugging in USB, **or** press the reset button on the PCB), then:

```bash
dfu-programmer atmega32u4 erase --force
dfu-programmer atmega32u4 flash planck_rev4_vial.hex
dfu-programmer atmega32u4 reset
```

Or use QMK Toolbox with the `.hex` file.

---

## Bootloader recovery (if anything goes wrong)

Four independent paths back to DFU, in order of reliability:

1. **Physical reset button on the PCB** — hardware-level, always works
2. **Hold top-left key (matrix `(0,0)` = Esc) + plug in USB** — Bootmagic Lite. Also wipes any corrupt Vial EEPROM state.
3. **Short the RST pad to GND** — equivalent to (1)
4. **Remap a key to `QK_BOOT` in Vial and press it** — only works if firmware still runs

The atmel-dfu bootloader itself lives in protected flash and cannot be erased without an external programmer, so the keyboard cannot be bricked by a bad firmware flash.
