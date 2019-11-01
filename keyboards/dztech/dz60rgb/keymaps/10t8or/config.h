// (Cl) 10t8or, 2ol9
// https://github.com/tentator/qmk_firmware/tree/master/keyboards/dztech/dz60rgb/keymaps/10t8or/
//
// compile with:
//     $ CFLAGS="-Wno-error=deprecated" make dztech/dz60rgb:10t8or:dfu-util
//

#pragma once

#undef  MANUFACTURER
#define MANUFACTURER Me
#undef  PRODUCT
#define PRODUCT      dz10t8or
#undef  DESCRIPTION
#define DESCRIPTION  Another 10tboard
#define FORCE_NKRO
#define TAPPING_TERM 175                // default is 200
#define PERMISSIVE_HOLD                 // for fast typers: makes tap and hold keys trigger the hold if another key is pressed before releasingmakes tap and hold keys trigger the hold if another key is pressed before releasing
#define IGNORE_MOD_TAP_INTERRUPT        // enables rolling combos
// #define RETRO_TAPPING                // https://beta.docs.qmk.fm/features/feature_advanced_keycodes#retro-tapping
#undef TAPPING_FORCE_HOLD               // se lo setti il doppio tap di un key non attiva l'autorepeat 
// #define #GRAVE_ESC_GUI_OVERRIDE      // non dovrebbe servire, ma se usi KC_GESC almeno GUI+ESC non fa nulla (normalmente fa tilde)
#undef NO_ACTION_ONESHOT                // con questo poi non va OSL() !!
#define ONESHOT_TAP_TOGGLE 999
// some speed shit
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
 
#undef DISABLE_RGB_MATRIX_SPLASH
#undef DISABLE_RGB_MATRIX_MULTISPLASH
#undef DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

// #define DISABLE_RGB_MATRIX_SOLID_COLOR
// #define DISABLE_RGB_MATRIX_ALPHAS_MODS
// #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define DISABLE_RGB_MATRIX_BREATHING
// #define DISABLE_RGB_MATRIX_BAND_SAT
// #define DISABLE_RGB_MATRIX_BAND_VAL
// #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #define DISABLE_RGB_MATRIX_CYCLE_ALL
// #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
// #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
// #define DISABLE_RGB_MATRIX_DUAL_BEACON
// #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
// #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define DISABLE_RGB_MATRIX_RAINDROPS
// #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
// #define DISABLE_RGB_MATRIX_DIGITAL_RAIN
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #define DISABLE_RGB_MATRIX_SPLASH
// #define DISABLE_RGB_MATRIX_MULTISPLASH
// #define DISABLE_RGB_MATRIX_SOLID_SPLASH
// #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

#define QMK_KEYS_PER_SCAN 4

// #define RGB_MATRIX_KEYRELEASES


