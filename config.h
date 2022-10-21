#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

// A Custom matrix.c is used to poll the port expander C6 shows that the pins are hardwired there
#define MATRIX_ROW_PINS { D0, C3, D1, C1, C2 }
#define MATRIX_COL_PINS { D4, D4, C0, B5, D5, B4, D6, B1, B0, B2, D7, B3, D4, D4 }
#define PORT_EXPANDER_ADDRESS 0x20

// COL2ROW, ROW2COL
#define DIODE_DIRECTION COL2ROW
#define USB_MAX_POWER_CONSUMPTION 100

// general settings
#define TAPPING_TERM 170
#define TAPPING_TOGGLE 2
#define TAPPING_FORCE_HOLD

// haptic driver settings
#ifdef HAPTIC_ENABLE
#define FB_ERM_LRA 1
#define FB_BRAKEFACTOR 3 // For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7
#define FB_LOOPGAIN 1 // For  Low:0, Medium:1, High:2, Very High:3
#define RATED_VOLTAGE 2
#define V_PEAK 2.85
#define V_RMS 2.0
#define F_LRA 150 // resonance freq
#define DRV_GREETING alert_750ms
#define DRV_MODE_DEFAULT sharp_tick1
#define NO_HAPTIC_MOD
#define NO_HAPTIC_LOCKKEYS
#endif

// oled settings
#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X64
#define OLED_FONT_H "lib/glcdfont.c"
#define OLED_TIMEOUT 0
#endif

// space saving: remove locking key support
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// space saving: disable one-shots
#define NO_ACTION_ONESHOT
