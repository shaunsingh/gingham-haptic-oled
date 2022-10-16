SRC = matrix.c \
      i2c_master.c

CUSTOM_MATRIX = lite

# MCU name
MCU = atmega328p

# Bootloader selection
BOOTLOADER = usbasploader

# Default Build Options
MAGIC_ENABLE = no           # Disable bootmagic
NKRO_ENABLE = no            # Nkey Rollover (unsupported on VUSB)
MOUSEKEY_ENABLE = no        # Mouse keys
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow

# Usb Nkey Rollover + audio/system controls
EXTRAKEY_ENABLE = yes

# VIAL
VIA_ENABLE = yes            # Enable VIA support
VIAL_ENABLE = yes           # Enable VIAL support
VIAL_INSECURE = yes         # My keyboard is insecure :(

# OLED
OLED_ENABLE = yes           # Enable OLED
OLED_DRIVER = SSD1306       # 128x64 OLED Driver
WPM_ENABLE = yes            # Enable calculation of WPM

# Audio
AUDIO_ENABLE = yes          # Audio output

# Haptics
HAPTIC_DRIVER = DRV2605L    # Pimoroni Haptics

# Dynamic Macros
DYNAMIC_MACRO_ENABLE = yes  # Live Macro Recording

# Space saving
LTO_ENABLE = yes            # Link Time Optimization
QMK_SETTINGS = no           # I hardcode them in anyways
