SRC = matrix.c \
      i2c_master.c

CUSTOM_MATRIX = lite

# MCU name
MCU = atmega328p

# Bootloader selection
BOOTLOADER = usbasploader

# Default Build Options
MAGIC_ENABLE = no           # Disable bootmagic
NKRO_ENABLE = no            # Disable Nkey Rollover (unsupported on VUSB)
CONSOLE_ENABLE = no         # Disable console for debug
COMMAND_ENABLE = no         # Disable commands for debug and configuration
SLEEP_LED_ENABLE = no       # Disable breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = no       # Disable backlight functionality
RGBLIGHT_ENABLE = no        # Disable RGB underglow
SPACE_CADET_ENABLE = no     # Disable wierd parenthesis shift thing we don't need

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
KEY_OVERRIDE_ENABLE = no    # Key overrides just feel weird

# OLED
OLED_ENABLE = yes           # Enable OLED
OLED_DRIVER = SSD1306       # 128x64 OLED Driver

# VIAL
VIA_ENABLE = yes            # Enable VIA support
VIAL_ENABLE = yes           # Enable VIAL support
VIAL_INSECURE = yes         # My keyboard is insecure :(
