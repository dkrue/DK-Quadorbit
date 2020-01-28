#include <Adafruit_NeoPixel.h>
#include <KnobDK.h>
#include <UtilityDK.h>
#include <MIDI.h>

#define midiChannel 1

#define DEBUG
#define onboardLED 13
#define neopixelPIN 17

// Controller knobs (analogPin, midiCC, analogMin, analogMax)
KnobDK knob[6] = {
  KnobDK(A6, 14, 0, 1023),
  KnobDK(A5, 15, 0, 1023),
  KnobDK(A4, 16, 0, 1023),
  KnobDK(A2, 17, 0, 1023),
  KnobDK(A1, 18, 1, 1023),
  KnobDK(A0, 19, 349, 672)
};

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(4, neopixelPIN, NEO_RGB + NEO_KHZ800);


void setup() {
  #ifdef DEBUG
    pinMode(onboardLED, OUTPUT);
  #endif
  
  pixels.begin();

  MIDI.begin(); // hardware DIN
}

void loop() {

  // Analog inputs loop
  for (int i=0; i < 6; i++)
  {
    // Refresh controller value
    bool activity = knob[i].refresh();
    
    if(activity)
    {
      #ifdef DEBUG
        digitalWrite(onboardLED, HIGH);
        Serial.print("Knob ");
        Serial.print(i);
        Serial.print(" is ");
        Serial.print(knob[i].val());
        Serial.print(" sent ");
        Serial.print(knob[i].ccVal());
        Serial.print(" on CC ");
        Serial.println(knob[i].ccNum());
      #endif
      
      // Send MIDI CC value 
      usbMIDI.sendControlChange(knob[i].ccNum(), knob[i].ccVal(), midiChannel);
      MIDI.sendControlChange(knob[i].ccNum(), knob[i].ccVal(), midiChannel); // MIDI DIN

    } else {
      #ifdef DEBUG      
        digitalWrite(onboardLED, LOW);
      #endif
    }

    if(i < 4) { // Update LEDs for first 4 knobs
      int val = UtilityDK::scale(knob[i].val(), 0, 1023, 0, 50);
      pixels.setPixelColor(i, pixels.Color(50 - val, 0, val));
    }
  }

  // Send the updated pixel color to the hardware
  pixels.show();

  // Reduce analog sampling rate for smoother action
  delay(20);

  // MIDI Controllers should discard incoming MIDI messages
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}
