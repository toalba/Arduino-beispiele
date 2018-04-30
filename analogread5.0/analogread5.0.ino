#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6

#define NUMPIXELS      30

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int lednr=0;
int leds=0;
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
pixels.begin();
  for(int i=15;i<20;i++)
{
     pixels.setPixelColor(i,(156,156,156));

}
for(int i=15;i<=10;i--)
{
     pixels.setPixelColor(i,(156,156,156));

}

pixels.show();
}
void loop() {

  leds=analogRead(A2);
   lednr=(10.0/1023)*leds+5;
   for(int i=0;i<lednr;i++)
   {
     pixels.setPixelColor(i+15,(156,156,156));
     pixels.setPixelColor(14-i,(156,156,156));
     
   }
   pixels.show();
   delay(10);
      for(int i=0;i<=lednr;i++)
   {
     pixels.setPixelColor(i+15,(0,0,0));
     pixels.setPixelColor(14-i,(0,0,0));
     
   }
   pixels.show();
}
