#pragma once

#define VIAL_KEYBOARD_UID { 0x21, 0x72, 0x62, 0xA2, 0x6D, 0xD7, 0x3C, 0x39 }

#define TAPPING_TERM 170
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

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

#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X64
#define OLED_FONT_H "lib/glcdfont.c"
#endif