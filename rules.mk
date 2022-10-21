SRC = matrix.c \
      i2c_master.c

MCU = atmega328p
BOOTLOADER = usbasploader

CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

VIA_ENABLE = yes
LTO_ENABLE = yes
OLED_ENABLE = yes
HAPTIC_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
HAPTIC_DRIVER = DRV2605L
DYNAMIC_MACRO_ENABLE = yes

CUSTOM_MATRIX = lite
