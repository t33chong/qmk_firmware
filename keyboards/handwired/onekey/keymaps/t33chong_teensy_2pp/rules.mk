# MCU name
MCU = at90usb1286

# Bootloader selection
BOOTLOADER = halfkay

DEFAULT_FOLDER = handwired/onekey/teensy_2pp

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

LAYOUTS = ortho_1x1

PS2_MOUSE_ENABLE = yes
PS2_USE_USART = yes

ENCODER_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

AUDIO_ENABLE = yes

# Either NKRO_ENABLE or BLUETOOTH_ENABLE, not both
NKRO_ENABLE = yes
# BLUETOOTH_ENABLE = yes
# BLUETOOTH_DRIVER = AdafruitBLE

HAPTIC_ENABLE = yes
HAPTIC_DRIVER += SOLENOID

# UNOFFICIAL_HAPTIC_ENABLE = yes

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball
POINTING_DEVICE_ADDRESS = 0x0A
