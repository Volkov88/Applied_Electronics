#include <FastLED.h>

#define NUM_LEDS 5

#define DATA_PIN 13
#define CLOCK_PIN 13

CRGB leds[NUM_LEDS];


void setup() {
   FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);  
}

void loop() {
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      leds[whiteLed] = CRGB::Blue;
      FastLED.show();
      delay(100);
      leds[whiteLed] = CRGB::Black;
   }
}