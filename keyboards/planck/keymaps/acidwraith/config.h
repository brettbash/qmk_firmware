#pragma once

#ifdef AUDIO_ENABLE
    #define SONIC_RINGS E__NOTE(_E6), E__NOTE(_G6), HD_NOTE(_C7),

    #define COIN \
        E__NOTE(_A5  ), \
        HD_NOTE(_E6  ),

    #define ONE_UP \
        Q__NOTE(_E6  ),  \
        Q__NOTE(_G6  ),  \
        Q__NOTE(_E7  ),  \
        Q__NOTE(_C7  ),  \
        Q__NOTE(_D7  ),  \
        Q__NOTE(_G7  ),

    #define OVERWATCH \
        HD_NOTE(_A4 ), \
        Q__NOTE(_E4 ), \
        Q__NOTE(_A4 ), \
        HD_NOTE(_B4 ), \
        Q__NOTE(_E4 ), \
        Q__NOTE(_B4 ), \
        W__NOTE(_CS5),

    #define MARIO \
        Q__NOTE(_E5), \
        H__NOTE(_E5), \
        H__NOTE(_E5), \
        Q__NOTE(_C5), \
        H__NOTE(_E5), \
        W__NOTE(_G5), \
        Q__NOTE(_G4),

    #define GAMEOVER \
        HD_NOTE(_C5 ), \
        HD_NOTE(_G4 ), \
        H__NOTE(_E4 ), \
        H__NOTE(_A4 ), \
        H__NOTE(_B4 ), \
        H__NOTE(_A4 ), \
        H__NOTE(_AF4), \
        H__NOTE(_BF4), \
        H__NOTE(_AF4), \
        WD_NOTE(_G4 ),

    #define GREEN_DAY \
        QD_NOTE(_G3), E__NOTE(_F3), E__NOTE(_E3), Q__NOTE(_F3), M__NOTE(_G3, 8+32), Q__NOTE(_REST), \
        Q__NOTE(_B4), Q__NOTE(_C4), Q__NOTE(_B4), E__NOTE(_A4), Q__NOTE(_G3), M__NOTE(_G3, 8+32), Q__NOTE(_REST), \
        Q__NOTE(_B4), Q__NOTE(_C4), Q__NOTE(_B4), E__NOTE(_A4), Q__NOTE(_G3), Q__NOTE(_G3), Q__NOTE(_G3), Q__NOTE(_G3), E__NOTE(_A4), E__NOTE(_C4), QD_NOTE(_B4), HD_NOTE(_B4)

    #define ZELDA_2 \
        Q__NOTE(_G5),     \
        Q__NOTE(_FS5),    \
        Q__NOTE(_DS5),     \
        Q__NOTE(_A4),    \
        Q__NOTE(_GS4),     \
        Q__NOTE(_E5),     \
        Q__NOTE(_GS5),     \
        HD_NOTE(_C6),

    #define ZELDA_1 \
        Q__NOTE(_A4 ), \
        Q__NOTE(_AS4), \
        Q__NOTE(_B4 ), \
        HD_NOTE(_C5 ), \

    #define DOOM  \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E4 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_D4 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_C4 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_BF3), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_B3 ), \
        Q__NOTE(_C4 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E4 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_D4 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_C4 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        H__NOTE(_BF3), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_B3 ), \
        Q__NOTE(_C4 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E4 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_D4 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_C4 ), \
        Q__NOTE(_E3 ), \
        Q__NOTE(_E3 ), \
        H__NOTE(_BF3),

    #define STARTUP_SONG SONG(DOOM)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2


/*
 * Mouse Keys
 */
// #define MK_3_SPEED

// Cursor
#define MOUSEKEY_DELAY 30
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_TIME_TO_MAX 40
#define MOUSEKEY_MAX_SPEED 20

// Scroll Wheel
#define MOUSEKEY_WHEEL_DELAY 30
#define MOUSEKEY_WHEEL_INTERVAL 16
#define MOUSEKEY_WHEEL_TIME_TO_MAX 80
#define MOUSEKEY_WHEEL_MAX_SPEED 8

// Tap Dancing
#define TAPPING_TERM 200

// Encoder
#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 10
