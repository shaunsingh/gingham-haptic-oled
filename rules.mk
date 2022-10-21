SRC = matrix.c \
      i2c_master.c

# MCU name
MCU = atmega328p

# Bootloader selection
BOOTLOADER = usbasploader

# Build Options
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

# Audio/system controls
EXTRAKEY_ENABLE = yes

# Mouse keys
MOUSEKEY_ENABLE = yes

# Audio
AUDIO_ENABLE = no

# Haptics
HAPTIC_DRIVER = DRV2605L    # Pimoroni Haptics

# Dynamic Macros
DYNAMIC_MACRO_ENABLE = yes  # Live Macro Recording

# Space saving
LTO_ENABLE = yes            # Enable Link Time Optimization
SPACE_CADET_ENABLE = no     # Disable wierd parenthesis shift thing we don't need
KEY_OVERRIDE_ENABLE = no    # Key overrides just feel weird

# OLED
OLED_ENABLE = no            # Enable OLED

# VIAL
VIA_ENABLE = yes          # Enable VIA support

CUSTOM_MATRIX = lite
