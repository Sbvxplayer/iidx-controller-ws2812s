# iidx-controller
Software that enables you to create your own Arduino based beatmania IIDX controller.

# Features
 - HID lighting support (that works with btools and ttools).
 - GUI configuration tool.
 - Multiple input methods (joystick, keyboard, mouse).
 - Now works with a WS2812S LED Strip (Uses pin 18 for DATA)

# Requirements
 - An Arduino Leonardo (technically compatible with any ATmega32U4 based board, but only tested with a Leonardo).
 - The [Bounce2](https://www.arduino.cc/reference/en/libraries/bounce2/) library.
 - The FASTLED library for lighting support (not required to make the code work) (https://github.com/FastLED/FastLED)


# Uploading the code
Because this code uses LUFA, the process of uploading is a bit more different.
1. Add `https://github.com/CrazyRedMachine/Arduino-Lufa/raw/master/package_arduino-lufa_index.json` as an Additional Board Manager URL (in `File -> Preferences` menu)
2. Install LUFA AVR Boards from the Board Manager
3. Select Arduino Leonardo (LUFA) as your board type
4. Hit `Upload`

NOTE: To upload new code, you need to press reset in the GUI or on your board when the IDE shows `PORTS {COM1, COM6, } / {COM1, COM6, } => {}` or something similar in the log. (to enable showing this, check `File -> Preferences -> Show verbose output during: -> Upload`)

# Setup
Buttons:
 - One terminal to GND and the other terminal to the corresponding pin.

LEDs:
 - Positive terminal to corresponding pin.
 - Negative terminal to GND.

WS2812S Strip: 
- 5v to the 2nd 5v port (Check below for the pin layout)
- Data to pin 18 (this means that one buttons lighting will not be able to be used unless chained together into one wire) 
- GND wire to GND

Encoder:
 - Connect the encoder's wires to the corresponding pins.
 - Set `ENCODER_PPR` in `iidx-controller/config.h` to the PPR of your encoder.

Manufacturer name:
 - By setting `MF_NAME` in `iidx-controller/config.h`, you can change the manufacturer name of your controller.
 - You can change this to whatever you'd like, such as your name.
 
Info:
 - Pinouts are available in `iidx-controller/config.h`, you can edit them there if necessary.
 - Leonardo pinout (what the numbers in the codes pinout arrays mean) at the bottom of this page.
 - Additional settings can be configured via the GUI, more info [here](https://github.com/Gladuin/iidx-controller/tree/master/config-tool)

# Thanks
- Huge thanks to [CrazyRedMachine](https://github.com/CrazyRedMachine) for helping me out when I got stuck, and for their [SoundVoltexIO](https://github.com/CrazyRedMachine/SoundVoltexIO) repository.
- John Lluch's [Timer interrupt based Encoder library](https://github.com/John-Lluch/Encoder)
- The [digitalWriteFast library](https://github.com/watterott/Arduino-Libs/tree/master/digitalWriteFast)
- Gorila Guy for adding WS2812S support

# Leonardo pinout

![Leo pinout](https://raw.githubusercontent.com/Bouni/Arduino-Pinout/master/Arduino%20Leonardo%20Pinout.png)