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
  _DESIGN,
  _EMOJI,
  _ADJUST
};

enum planck_keycodes {
    COLEMAK = SAFE_RANGE,

    // Macros
    CODE,
    FUNC_TOG,
    DESN_TOG,
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
    MCRL_OPN,
    MCRL_CLS,

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

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(OVERWATCH);
  float caps_lock_on[][2]     = SONG(COIN);
  float caps_lock_off[][2]     = SONG(MARIO);
  float mission_open[][2]     = SONG(SONIC_RINGS);
  float mission_close[][2]     = SONG(ZELDA_2);
  float function_song[][2]     = SONG(ONE_UP);
  float design_song[][2]     = SONG(ZELDA_1);
  float plover_gb_song[][2]  = SONG(GAMEOVER);
#endif

//Tap Dance Declarations
enum {
  TD_SFT_CAPS = 0
};

//Tap Dance Definitions
float caps_active = 0;

void toggle_caps(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_LSFT);
    } else {
        if (caps_active == 0) {
            register_code16(KC_CAPSLOCK);
            PLAY_SONG(caps_lock_on);
            caps_active = 1;
        } else if (caps_active == 1) {
            unregister_code16(KC_CAPSLOCK);
            register_code16(KC_CAPSLOCK);
            unregister_code16(KC_CAPSLOCK);
            PLAY_SONG(caps_lock_off);
            caps_active = 0;
        }

    }
}

void reset_caps(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_LSFT);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
//   [TD_SFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
  [TD_SFT_CAPS]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, toggle_caps, reset_caps)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// π ----
// :: COLEMAK ---------------------------::
// ____
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,          KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,     KC_J,     KC_L,    KC_U,     KC_Y,        KC_SCLN, KC_BSPC,
    EMOJI_ESC,       KC_A,    KC_R,    KC_S,    KC_T,    KC_G,     KC_M,     KC_N,    KC_E,     KC_I,        KC_O,    KC_QUOT,
    TD(TD_SFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,     KC_K,     KC_H,    KC_COMM,  KC_DOT,      KC_SLSH, KC_ENT,
    KC_MPLY,         KC_LCTL, KC_LALT, KC_LGUI, LOWER,   BSPC_VIM, SPACE_FN, RAISE,   MO(_FNC), TG(_DESIGN), XXXXXXX, XXXXXXX
),

// π ----
// :: LOWER ---------------------------::
// ____
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,   KC_EXLM,   KC_AT,             KC_HASH,        KC_DLR,   KC_PERC,        KC_CIRC,  KC_AMPR,  KC_ASTR,     KC_PIPE,           KC_EQL,     LSFT(KC_SCLN),
    KC_TILD,  KC_BSLS,   KC_LCBR,           KC_LBRC,        KC_LPRN,  KC_LT,          KC_GT,    KC_RPRN,  KC_RBRC,     KC_RCBR,           KC_SLSH,    KC_PLUS,
    _______,  _______,   LALT(LSFT(KC_A)),  LGUI(KC_SLSH),  KC_TABL,  KC_MINS,        KC_UNDS,  KC_TABR,  LGUI(KC_P),  LGUI(LSFT(KC_P)),  LGUI(KC_E), KC_ENT,
    _______,  _______,   _______,           _______,        _______,  _______,        KC_SPC,   _______,  XXXXXXX,     XXXXXXX,           XXXXXXX,    XXXXXXX
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
    _______,  _______, LSFT(KC_G), JUMP_TOP, _______, _______, KC_CIRC, LCTL(KC_F),          LCTL(KC_D), LCTL(KC_U), LCTL(KC_B), _______,
    KC_ESC,   KC_B,    KC_RCBR,    KC_LCBR,  KC_W,    KC_E,    KC_0,    KC_H,                KC_J,       KC_K,       KC_L,       KC_DLR,
    _______,  _______, _______,    _______,  _______, _______, _______, _______,             _______,    _______,    _______,    _______,
    _______,  _______, _______,    _______,  _______, _______, KC_LSFT, LGUI(LALT(KC_SPC)),  _______,    _______,    _______,    _______
),

// π ----
// :: NAVIGATION ---------------------------::
// ____
[_NAV] = LAYOUT_planck_grid(
    KC_MS_BTN3,   KC_MS_WH_LEFT, KC_MS_WH_UP,   KC_MS_WH_DOWN, KC_MS_WH_RIGHT, _______,         _______, KC_MS_BTN1, _______, _______,  _______,  _______,
    KC_MS_BTN2,   KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,      KC_MS_RIGHT,    KC_MS_BTN1,      _______, KC_LEFT,    KC_DOWN, KC_UP,    KC_RGHT,  _______,
    _______,      _______,       _______,       _______,       LGUI(KC_GRV),   _______,         _______, SCN_LT,     SCN_RT,  MCRL_OPN, MCRL_CLS, _______,
    _______,      _______,       _______,       _______,       _______,        LGUI(KC_SPC),    _______, _______,    _______, _______,  _______,  _______),

// π ----
// :: FUNCTIONS ---------------------------::
// ____
[_FNC] = LAYOUT_planck_grid(
    SRC_CODE,  CODEBRWR, TEACODE, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    DEV_TOOLS, THINGS,   DAYONE,  ONEPASS, _______, _______, _______, _______, _______, _______, _______, _______,
    CODE,      COLRPIK,  COLRSWT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,   SCREEN,   _______, _______, _______, _______, _______, _______, XXXXXXX, KC_MUTE, KC_MRWD, KC_MFFD
),

// π ----
// :: DESIGN ---------------------------::
// ____
[_DESIGN] = LAYOUT_planck_grid(
    _______, LGUI(KC_MINS), LGUI(KC_PLUS), KC_V,             KC_P,            KC_B,             _______,          _______, _______, _______, _______, _______,
    KC_R,    LGUI(KC_9),    LGUI(KC_0),    LGUI(KC_G),       LGUI(LSFT(KC_G)), LGUI(KC_D),       LGUI(LALT(KC_K)), _______, _______, _______, _______, _______,
    KC_O,    KC_I,          LGUI(KC_R),    LGUI(LSFT(KC_H)), LGUI(LSFT(KC_O)), LGUI(LALT(KC_C)), LGUI(LALT(KC_V)), _______, _______, _______, _______, _______,
    KC_L,    LSFT(KC_R),    LCTL(KC_G),    LGUI(LALT(KC_M)), _______,         _______,          KC_SPACE,         _______, _______, _______, _______, _______
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
    case FUNC_TOG:
        if (record->event.pressed) {
            // MO(_FNC);
            // SEND_STRING(SS_DOWN((LOWER)));
            PLAY_SONG(function_song);
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
    // Mission Control Open
    case MCRL_OPN:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_UP) SS_UP(X_LCTRL) SS_UP(X_UP));
            PLAY_SONG(mission_open);
        }
      return false;
      break;
    // Mission Control Close
    case MCRL_CLS:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_DOWN) SS_UP(X_LCTRL) SS_UP(X_DOWN));
            PLAY_SONG(mission_close);
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
    if (clockwise) {
        tap_code16(A(S(KC__VOLDOWN)));
    } else {
        tap_code16(A(S(KC__VOLUP)));
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
