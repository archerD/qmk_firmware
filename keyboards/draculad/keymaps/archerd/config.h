/*
 * My draculad keyboard config
 */

#pragma once

// setup hand configuration
#define EE_HANDS
// initial configuration for ee_hands requires using the
// dfu-split-left and dfu-split-right bootloaders

// rgb light support
#ifdef RGB_DI_PIN
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLED_NUM 10
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
    #define RGBLIGHT_SLEEP
#endif

// oled support
#ifdef OLED_ENABLE
    #undef OLED_TIMEOUT
    #define OLED_TIMEOUT 60000
#endif

/* leader settings */
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT
#define LEADER_TIMEOUT 300

/* space saving configurations */
// I do not have a locking switch
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
// Removes oneshots (I have one for media layer)
//#define NO_ACTION_ONESHOT
// restore complete layers
// restrict the number of layers:
#undef LAYER_STATE_8BIT
//#define LAYER_STATE_8BIT
//#define LAYER_STATE_16BIT


/* from miryoku config.h */
// default but important
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

