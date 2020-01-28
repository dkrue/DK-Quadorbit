# DK-Quadorbit
QUADORBIT is a MIDI controller compatible with any computer music software. There are two versions:

### Quadorbit Classic
Features 4 knobs with corresponding color changing LED, and an XY joystick.

### Quadorbit Polar
Features 4 knobs, and an XY joystick surrounded by an LED ring. The position of the joystick and knobs are indicated by the colors on the LED ring.

![Quadorbit Classic and Quadorbit Polar](/images/quadorbit_midi_duo.jpg)

## About
This is one of my high-quality projects I have made several times and sell in my
[Etsy Store: Circuits & Sawdust](https://www.etsy.com/shop/CircuitsAndSawdust). 
- [Quadorbit Classic](https://www.etsy.com/listing/508669593/quadorbit-handmade-midi-usb-controller)
- [Quadorbit Polar](https://www.etsy.com/listing/572038574/quadorbit-polar-handmade-midi-controller)

## How it works
This is a [Teensy LC](https://www.pjrc.com/teensy/) based USB MIDI controller with 4 potentiometers, a joystick with 2 potentiometers, and [Neopixel](https://github.com/adafruit/Adafruit_NeoPixel) addressable RGB LEDs. There are several smoothing algorithms in the code to provide quality MIDI signals. It is programmed within Arduino, and extended by my own C++ classes to manage the knob values, LEDs, and value scaling across my collection of MIDI projects.

The code for the Quadorbit Classic with MIDI DIN output is shared here.

![Quadorbit MIDI Controller](/images/quadorbit_dark_off.jpg)

## Feedback
I've made several improvements to the code based on customer feedback and having other people use it with different equipment. A recent customer request was to add a 5-pin MIDI DIN port to interface with hardware instruments without a USB connection. This is available as an optional upgrade in my Etsy listings, and the code for that is included here. More info on that type of MIDI output can be found in the [Arduino MIDI Library](https://github.com/FortySevenEffects/arduino_midi_library)