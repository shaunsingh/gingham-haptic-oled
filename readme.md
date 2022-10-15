# Gingham - shaunsingh

Gingham keymap with support for 
 - dynamic macros
 - SSD1306 128x64 OLED (over i2c)
 - Haptics using pimoroni drv25605l linear actuator
 - Via/Vial keymapping

 Parts Used: 
- [oled, SSD1306 128x64](https://www.amazon.com/Monochrome-Display-Compatible-Leonardo-FireBettle-M0/dp/B087PCKMWB/ref=sr_1_18?crid=3CGBNC91Z2L3J&keywords=SSD1306%2B128x64%2Bpixel%2BOLED%2BDisplays&qid=1665790081&sprefix=ssd1306%2B128x64%2Bpixel%2Boled%2Bdisplays%2Caps%2C83&sr=8-18&th=1)
- [haptics](https://shop.pimoroni.com/products/drv2605l-linear-actuator-haptic-breakout?variant=27859486867539)

Mounted on a modified p3d gingham case

## Original README

![gingham](https://yiancar-designs.com/wp-content/uploads/2019/06/IMG_20190625_233619.jpg)

A 60% keyboard with only through hole components.   

Keyboard Maintainer: [Yiancar](http://yiancar-designs.com/) and on [GitHub](https://github.com/yiancar)  
Hardware Supported: ATMEGA328p with vusb [PCB](https://github.com/yiancar/gingham_pcb)  
Hardware Availability: https://yiancar-designs.com/, https://novelkeys.xyz, https://mechboards.co.uk/  

Make example for this keyboard (after setting up your build environment):

    make yiancardesigns/gingham:default

Flashing example for this keyboard:

    make yiancardesigns/gingham:default:flash

Bootloader:
use usbasploader HSGW's my repository.
https://github.com/hsgw/USBaspLoader/tree/plaid

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
