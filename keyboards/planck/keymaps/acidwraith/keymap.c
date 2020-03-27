/*
 * the._A C I D W R A I T H_
 * アシッドレイス
 * A Custom Planck Layout for Quantum Cyber Programming & Time Hacking
 * @brettbash
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _VIM,
  _NAV,
  _FNC,
  _EMOJI,
  _ADJUST
};

enum planck_keycodes {
    COLEMAK = SAFE_RANGE,

    // Macros
    CODE,
    TEACODE,
    CODEBRWR,
    DEV_TOOLS,
    SRC_CODE,
    THINGS,
    DAYONE,
    ONEPASS,
    COLRPIK,
    COLRSWT,
    SCREEN,

    // VIM
    JUMP_TOP,

    SCN_LT,
    SCN_RT,

    // Emoji
    KISS
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define KC_TABR LGUI(KC_RBRC)  // Send Command + ]
#define KC_TABL LGUI(KC_LBRC)  // Send Command + [
#define SPACE_FN LT(_NAV, KC_SPC)
#define BSPC_VIM LT(_VIM, KC_BSPC)
#define EMOJI_ESC LT(_EMOJI, KC_ESC)
#define VIM_ALF LT(KC_LSFT, LGUI(KC_SPC)) // Not working currently.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// π ----
// :: COLEMAK ---------------------------::
// ____
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,     KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,     KC_J,     KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    EMOJI_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,     KC_H,     KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_K,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    MO(_FNC),   KC_LCTL, KC_LALT, KC_LGUI, LOWER,   BSPC_VIM, SPACE_FN, RAISE,   KC_MFFD, KC_VOLD, KC_VOLU, KC_MPLY
),

// π ----
// :: LOWER ---------------------------::
// ____
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,   KC_EXLM,   KC_AT,             KC_HASH,        KC_DLR,   KC_PERC,        KC_CIRC,  KC_AMPR,  KC_ASTR,     KC_PIPE,  KC_EQL,     LSFT(KC_SCLN),
    KC_TILD,  KC_BSLS,   KC_LCBR,           KC_LBRC,        KC_LPRN,  KC_LT,          KC_GT,    KC_RPRN,  KC_RBRC,     KC_RCBR,  KC_SLSH,    KC_PLUS,
    _______,  _______,   LALT(LSFT(KC_A)),  LGUI(KC_SLSH),  KC_TABL,  KC_MINS,        KC_UNDS,  KC_TABR,  LGUI(KC_P),  LGUI(LSFT(KC_P)),     _______, KC_ENT,
    _______,  _______,   _______,           _______,        _______,  LGUI(KC_SPC),   KC_SPC,   _______,  KC_MRWD,     LALT(LSFT(KC_VOLD)),  LALT(LSFT(KC_VOLU)),  KC_MUTE
),

// π ----
// :: RAISE ---------------------------::
// ____
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     LSFT(KC_SCLN),
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,    KC_SLSH,  KC_PPLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    KC_ASTR,  KC_MINS,
    _______, _______, _______, _______, _______, KC_BSPC, KC_SPC,  _______, KC_0,    KC_PDOT, KC_EQL,   KC_ENT
),

// π ----
// :: VIM ---------------------------::
// ____
[_VIM] = LAYOUT_planck_grid(
    _______,  _______, LSFT(KC_G), JUMP_TOP, _______, _______, KC_CIRC, LCTL(KC_F),  LCTL(KC_D), LCTL(KC_U), LCTL(KC_B), _______,
    KC_ESC,   KC_B,    KC_RCBR,    KC_LCBR,  KC_W,    KC_E,    KC_0,          KC_H,        KC_J,       KC_K,       KC_L,       KC_DLR,
    _______,  _______, _______,    _______,  _______, _______, _______,       _______,     _______,    _______,    _______,    _______,
    _______,  _______, _______,    _______,  _______, _______, KC_LSFT,       _______,     _______,    _______,    _______,    _______
),

// π ----
// :: NAVIGATION ---------------------------::
// ____
[_NAV] = LAYOUT_planck_grid(
    KC_MS_BTN3,   KC_MS_WH_LEFT, KC_MS_WH_UP,   KC_MS_WH_DOWN, KC_MS_WH_RIGHT, _______,    _______, _______, _______, _______, _______, _______,
    KC_MS_BTN2,   KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,      KC_MS_RIGHT,    KC_MS_BTN1, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______,      _______,       _______,       _______,       LGUI(KC_GRV),   _______,    _______, SCN_LT,  SCN_RT,  _______, _______, _______,
    _______,      _______,       _______,       _______,       _______,        _______,    _______, _______, _______, _______, _______, _______),

// π ----
// :: MACROS ---------------------------::
// ____
[_FNC] = LAYOUT_planck_grid(
    SRC_CODE,  CODEBRWR, TEACODE, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    DEV_TOOLS, THINGS,   DAYONE,  ONEPASS, _______, _______, _______, _______, _______, _______, _______, _______,
    CODE,      COLRPIK,  COLRSWT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,   SCREEN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

// Emoji
[_EMOJI] = LAYOUT_planck_grid(
    SRC_CODE,  CODEBRWR, TEACODE, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    DEV_TOOLS, THINGS,   DAYONE,  ONEPASS, _______, _______, _______, _______, _______, _______, _______, _______,
    CODE,      COLRPIK,  COLRSWT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,   SCREEN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* [_EMOJI] = LAYOUT_planck_grid(
    _______, CRY,     SHOCK,   SAD,     THUMBDN, HEART,     SSMILE,  THUMBUP, METAL,   OK,      MUSCLE,  ALIEN,
    _______, _______, _______, _______, _______, HEARTEYES, KISS,    SMILE,   PRAISE,  LMAO,    ROFL,    VULCAN,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______
), */


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |Colemk|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  COLEMAK,  _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (biton32(state)) {
      case _COLEMAK:
          autoshift_enable();
          break;
      default:
          autoshift_disable();
          break;
      }
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;

    /* Macros */
    case CODE:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_LCMD("e") SS_UP(X_LCTRL));
        }
      return false;
      break;
    case TEACODE:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_LCMD("i") SS_UP(X_LALT) SS_UP(X_LSHIFT));
        }
      return false;
      break;
    case CODEBRWR:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_LCMD) SS_DOWN(X_SPC) SS_UP(X_SPC) SS_UP(X_LSHIFT) SS_UP(X_LCMD));
        }
      return false;
      break;
    case DEV_TOOLS:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LALT) SS_LCMD("i") SS_UP(X_LALT));
        }
      return false;
      break;
    case SRC_CODE:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LALT) SS_LCMD("u") SS_UP(X_LALT));
        }
      return false;
      break;
    case THINGS:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LSHIFT) SS_DOWN(X_SPC) SS_UP(X_LCTRL) SS_UP(X_LSHIFT) SS_UP(X_SPC));
        }
      return false;
      break;
    case DAYONE:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_LSFT("d") SS_UP(X_LCTRL));
        }
      return false;
      break;
    case ONEPASS:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_LCMD("/") SS_UP(X_LCTRL));
        }
      return false;
      break;
    case COLRPIK:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_LCMD("x") SS_UP(X_LCTRL) SS_UP(X_LALT));
        }
      return false;
      break;
    case COLRSWT:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_LCMD("d") SS_UP(X_LCTRL) SS_UP(X_LALT));
        }
      return false;
      break;
    case SCREEN:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LSHIFT) SS_LCMD("4") SS_UP(X_LSHIFT));
        }
      return false;
      break;

    /* VIM */
    case JUMP_TOP:
        if (record->event.pressed) {
            SEND_STRING("gg");
        }
      return false;
      break;

    /* Navigation */
    case SCN_LT:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LEFT) SS_UP(X_LCTRL) SS_UP(X_LEFT));
        }
      return false;
      break;
    case SCN_RT:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_RIGHT) SS_UP(X_LCTRL) SS_UP(X_RIGHT));
        }
      return false;
      break;

    // Emoji
    case KISS:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("D83D+DE18"));
        }
        return false;
        break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
