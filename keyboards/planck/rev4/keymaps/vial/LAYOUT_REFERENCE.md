# Layout Reference: QMK keycodes → character output

All mappings assume the **operating system** is set to **Swedish (SE)** keyboard layout.  
"shifted" means sent with Shift; "AltGr" means sent with Right-Alt / AltGr.

---

## Number row & special keys

| QMK keycode   | US output (no mod) | SE output (no mod) | SE shifted | SE AltGr |
|---------------|--------------------|--------------------|------------|----------|
| `KC_GRV`      | `` ` ``            | `§`                | `°`        | —        |
| `KC_1`        | `1`                | `1`                | `!`        | —        |
| `KC_2`        | `2`                | `2`                | `"`        | `@`      |
| `KC_3`        | `3`                | `3`                | `#`        | `£`      |
| `KC_4`        | `4`                | `4`                | `¤`        | `$`      |
| `KC_5`        | `5`                | `5`                | `%`        | `€`      |
| `KC_6`        | `6`                | `6`                | `&`        | —        |
| `KC_7`        | `7`                | `7`                | `/`        | `{`      |
| `KC_8`        | `8`                | `8`                | `(`        | `[`      |
| `KC_9`        | `9`                | `9`                | `)`        | `]`      |
| `KC_0`        | `0`                | `0`                | `=`        | `}`      |
| `KC_MINS`     | `-`                | `+`                | `?`        | `\`      |
| `KC_EQL`      | `=`                | `` ´ `` (dead)     | `` ` ``    | —        |

---

## Upper letter row (QWERTY positions)

| QMK keycode | US | SE     | SE shifted | SE AltGr |
|-------------|-----|--------|------------|----------|
| `KC_Q`      | `q` | `q`    | `Q`        | —        |
| `KC_W`      | `w` | `w`    | `W`        | —        |
| `KC_E`      | `e` | `e`    | `E`        | `€`      |
| `KC_R`      | `r` | `r`    | `R`        | —        |
| `KC_T`      | `t` | `t`    | `T`        | —        |
| `KC_Y`      | `y` | `y`    | `Y`        | —        |
| `KC_U`      | `u` | `u`    | `U`        | —        |
| `KC_I`      | `i` | `i`    | `I`        | —        |
| `KC_O`      | `o` | `o`    | `O`        | —        |
| `KC_P`      | `p` | `p`    | `P`        | —        |
| `KC_LBRC`   | `[` | `å`    | `Å`        | —        |
| `KC_RBRC`   | `]` | `^` (dead circumflex) | `¨` (dead diaeresis) | `~`  |
| `KC_BSLS`   | `\` | `'`    | `*`        | —        |

---

## Home row (QWERTY positions)

| QMK keycode | US  | SE  | SE shifted | SE AltGr |
|-------------|-----|-----|------------|----------|
| `KC_A`      | `a` | `a` | `A`        | —        |
| `KC_S`      | `s` | `s` | `S`        | —        |
| `KC_D`      | `d` | `d` | `D`        | —        |
| `KC_F`      | `f` | `f` | `F`        | —        |
| `KC_G`      | `g` | `g` | `G`        | —        |
| `KC_H`      | `h` | `h` | `H`        | —        |
| `KC_J`      | `j` | `j` | `J`        | —        |
| `KC_K`      | `k` | `k` | `K`        | —        |
| `KC_L`      | `l` | `l` | `L`        | —        |
| `KC_SCLN`   | `;` | `ö` | `Ö`        | —        |
| `KC_QUOT`   | `'` | `ä` | `Ä`        | —        |

---

## Bottom row (QWERTY positions)

| QMK keycode | US  | SE  | SE shifted | SE AltGr |
|-------------|-----|-----|------------|----------|
| `KC_NUBS`   | `<` (ISO only) | `<` | `>` | `\|`  |
| `KC_Z`      | `z` | `z` | `Z`        | —        |
| `KC_X`      | `x` | `x` | `X`        | —        |
| `KC_C`      | `c` | `c` | `C`        | —        |
| `KC_V`      | `v` | `v` | `V`        | —        |
| `KC_B`      | `b` | `b` | `B`        | —        |
| `KC_N`      | `n` | `n` | `N`        | —        |
| `KC_M`      | `m` | `m` | `M`        | `µ`      |
| `KC_COMM`   | `,` | `,` | `;`        | —        |
| `KC_DOT`    | `.` | `.` | `:`        | —        |
| `KC_SLSH`   | `/` | `-` | `_`        | —        |
| `KC_NUHS`   | `#` (ISO only) | `'` | `*` | —  |

---

## QMK shifted aliases → SE output

These QMK macros expand to `S(keycode)`, so they send Shift+key.  
The result depends on what that physical key produces on SE layout when shifted.

| QMK alias   | Expands to     | US output | SE output |
|-------------|----------------|-----------|-----------|
| `KC_EXLM`   | `S(KC_1)`      | `!`       | `!`       |
| `KC_AT`     | `S(KC_2)`      | `@`       | `"`       |
| `KC_HASH`   | `S(KC_3)`      | `#`       | `#`       |
| `KC_DLR`    | `S(KC_4)`      | `$`       | `¤`       |
| `KC_PERC`   | `S(KC_5)`      | `%`       | `%`       |
| `KC_CIRC`   | `S(KC_6)`      | `^`       | `&`       |
| `KC_AMPR`   | `S(KC_7)`      | `&`       | `/`       |
| `KC_ASTR`   | `S(KC_8)`      | `*`       | `(`       |
| `KC_LPRN`   | `S(KC_9)`      | `(`       | `)`       |
| `KC_RPRN`   | `S(KC_0)`      | `)`       | `=`       |
| `KC_UNDS`   | `S(KC_MINS)`   | `_`       | `?`  ⚠️   |
| `KC_PLUS`   | `S(KC_EQL)`    | `+`       | `` ` `` (dead grave) ⚠️ |
| `KC_LCBR`   | `S(KC_LBRC)`   | `{`       | `Å`       |
| `KC_RCBR`   | `S(KC_RBRC)`   | `}`       | `^` (dead circumflex) |
| `KC_PIPE`   | `S(KC_BSLS)`   | `\|`      | `*`  ⚠️   |
| `KC_COLN`   | `S(KC_SCLN)`   | `:`       | `Ö`       |
| `KC_DQUO`   | `S(KC_QUOT)`   | `"`       | `Ä`       |
| `KC_LT`     | `S(KC_COMM)`   | `<`       | `;`       |
| `KC_GT`     | `S(KC_DOT)`    | `>`       | `:`       |
| `KC_QUES`   | `S(KC_SLSH)`   | `?`       | `_`       |
| `S(KC_NUBS)`|                | `>`       | `>`  ✓    |
| `S(KC_NUHS)`|                | `~`       | `*`       |
| `S(KC_EQL)` |                | `+`       | `` ` ``   |

> ⚠️ Keycodes marked with ⚠️ do **not** produce the US symbol when the OS is set to SE layout.
> This is a known mismatch that affects `KC_UNDS`, `KC_PLUS`, and `KC_PIPE` on SE systems.

---

## AltGr (RALT) combinations on SE

| QMK keycode       | SE output |
|-------------------|-----------|
| `RALT(KC_2)`      | `@`       |
| `RALT(KC_3)`      | `£`       |
| `RALT(KC_4)`      | `$`       |
| `RALT(KC_5)`      | `€`       |
| `RALT(KC_7)`      | `{`       |
| `RALT(KC_8)`      | `[`       |
| `RALT(KC_9)`      | `]`       |
| `RALT(KC_0)`      | `}`       |
| `RALT(KC_MINS)`   | `\`       |
| `RALT(KC_E)`      | `€`       |
| `RALT(KC_M)`      | `µ`       |
| `RALT(KC_NUBS)`   | `\|`      |
| `RALT(KC_RBRC)`   | `~`       |

> `LCA(KC_x)` = Left Ctrl + Alt + key. On Linux/Windows, Ctrl+Alt is treated as AltGr
> for legacy compatibility, so `LCA(KC_8)` = `[` and `LCA(KC_9)` = `]`.

---

## Full SVORAK A1 character map (what the Planck base layer produces, SE OS)

```
Row 1:  Esc  |  å  |  ä  |  ö  |  p  |  y  |  f  |  g  |  c  |  r  |  l  |  ,
Row 2:  Tab  |  a  |  o  |  e  |  u  |  i  |  d  |  h  |  t  |  n  |  s  |  -
Row 3:  Shft |  .  |  q  |  j  |  k  |  x  |  b  |  m  |  w  |  v  |  z  | Ent
Row 4:  Ctrl | GUI | Alt | Bksp|[Lwr]|   Space   |[Rse]|  ←  |  ↓  |  ↑  |  →
```

Shifted base layer:
```
Row 1:  Esc  |  Å  |  Ä  |  Ö  |  P  |  Y  |  F  |  G  |  C  |  R  |  L  |  ;
Row 2:  Tab  |  A  |  O  |  E  |  U  |  I  |  D  |  H  |  T  |  N  |  S  |  _
Row 3:       |  :  |  Q  |  J  |  K  |  X  |  B  |  M  |  W  |  V  |  Z  |
```

---

## Cross-layout key position reference

Physical position → character produced under each OS layout setting.

| Physical key (US label) | US QWERTY | SE QWERTY | SVORAK (QMK remap, SE OS) |
|-------------------------|-----------|-----------|--------------------------|
| Top-left of letters (`Q`) | q | q | å |
| Next (`W`)              | w | w | ä |
| Next (`E`)              | e | e | ö |
| Next (`R`)              | r | r | p |
| Next (`T`)              | t | t | y |
| Next (`Y`)              | y | y | f |
| Next (`U`)              | u | u | g |
| Next (`I`)              | i | i | c |
| Next (`O`)              | o | o | r |
| Next (`P`)              | p | p | l |
| `[` key                 | `[` | `å` | `,` |
| `]` key                 | `]` | `¨` | *(none mapped to base)* |
| Home row `A`            | a | a | a |
| `S`                     | s | s | o |
| `D`                     | d | d | e |
| `F`                     | f | f | u |
| `G`                     | g | g | i |
| `H`                     | h | h | d |
| `J`                     | j | j | h |
| `K`                     | k | k | t |
| `L`                     | l | l | n |
| `;` key                 | `;` | `ö` | s |
| `'` key                 | `'` | `ä` | `-` |
| Bottom `Z`              | z | z | `.` |
| `X`                     | x | x | q |
| `C`                     | c | c | j |
| `V`                     | v | v | k |
| `B`                     | b | b | x |
| `N`                     | n | n | b |
| `M`                     | m | m | m |
| `,` key                 | `,` | `,` | w |
| `.` key                 | `.` | `.` | v |
| `/` key                 | `/` | `-` | z |
