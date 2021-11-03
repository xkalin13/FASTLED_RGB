#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    114
#define BRIGHTNESS  64
#define FRAMES_PER_SECOND 60
#define MAX_POWER_MILLIAMPS 500
#define MAX_VOLTAGE 5

#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
CRGB leds[NUM_LEDS];

// This function sets up the ledsand tells the controller about them
void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
 	delay(3000);   
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( BRIGHTNESS );
  FastLED.setMaxPowerInVoltsAndMilliamps( MAX_VOLTAGE, MAX_POWER_MILLIAMPS);
    
}

// This function runs over and over, and is where you do the magic to light
// your leds.
void loop() {
   // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::White;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(1000/FRAMES_PER_SECOND);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
   }
}
