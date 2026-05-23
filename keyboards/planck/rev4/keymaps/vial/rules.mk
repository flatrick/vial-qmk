# Vial support
VIA_ENABLE = yes
VIAL_ENABLE = yes

# ATmega32u4 has only ~28KB of usable flash (32KB minus 4KB atmel-dfu bootloader).
# Audio is the largest single flash consumer and must be disabled to make Vial fit.
AUDIO_ENABLE = no
MIDI_ENABLE = no
CONSOLE_ENABLE = no
QMK_SETTINGS = no

# Tap Dance: configurable in Vial — tap a key for one keycode, hold or
# double-tap for another. Used for paired-bracket behavior (tap=(, hold=))
# among other things.
TAP_DANCE_ENABLE = yes

# Combos: configurable in Vial — press 2+ keys simultaneously to trigger a
# different keycode (e.g., J+K → Esc, D+F → Tab).
COMBO_ENABLE = yes

# Caps Word: tap shift twice to auto-shift the next word until space/punct,
# perfect for SCREAMING_SNAKE_CASE constants in SQL, env vars, Rust consts.
CAPS_WORD_ENABLE = yes

# Backlight: this rev4 has no LEDs installed. The keyboard.json doesn't enable
# the feature anyway, but setting it explicitly here documents the intent and
# guards against future keyboard.json changes pulling it in unexpectedly.
BACKLIGHT_ENABLE = no

# MAGIC keycodes (AG_SWAP, NK_TOGG, CG_TOGG, etc.) — disabled because the
# Svorak keymap doesn't use them. NKRO itself stays fully active; only the
# runtime-toggle keycode (NK_TOGG) goes away. Can be re-enabled if needed.
MAGIC_ENABLE = no

# LTO is already set in keyboard.json but explicit here for clarity
LTO_ENABLE = yes
