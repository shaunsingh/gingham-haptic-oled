SRC = matrix.c \
      i2c_master.c

CUSTOM_MATRIX = lite

# MCU name
MCU = atmega328p

# Bootloader selection
BOOTLOADER = usbasploader

# Default Build Options
BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

# Usb Nkey Rollover + audio/system controls
NKRO_ENABLE = yes
EXTRAKEY_ENABLE = yes

# VIAL
VIA_ENABLE = yes            # Enable VIA support
VIAL_ENABLE = yes           # Enable VIAL support
VIAL_INSECURE = yes         # My keyboard is insecure :(

# OLED
OLED_ENABLE = yes           # SSD1306 OLED

# Haptics
HAPTIC_DRIVER = DRV2605L    # Pimoroni Haptics

# Space saving
LTO_ENABLE = yes            # Link Time Optimization
