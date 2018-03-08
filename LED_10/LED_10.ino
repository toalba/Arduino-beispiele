
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6

#define NUMPIXELS      30

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif


  pixels.begin(); 
}

void loop() {

  
  int blau=255;
  int rot=0;
  for(int i=0;i<255;i++)
  {
    rot=i;
    blau=255-i; 
for(int i=0;i<30;i++)
{
    pixels.setPixelColor(i, pixels.Color(rot,0,blau));

    pixels.show(); 
}
    delay(2000.0/255);
 }

  
  
  }


  
