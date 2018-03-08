// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      30

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.

}
void loop() {
int R=255;
int G=0;
int B=0;

for(int i=0;B<255;B++){

 for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(R,G,B)); 
  pixels.show();
  }
 delay(50);
  
}
for(int i=0;R>0;R--){

 for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(R,G,B)); 
  pixels.show();
  
  
  }
 delay(50);
  
  
}
for(int i=0;G<255;G++){

 for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(R,G,B)); 
  pixels.show();
 
  }
delay(50);
  
  
}
for(int i=0;B>0;B--){

 for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(R,G,B)); 
  pixels.show();
 
  }
  delay(50);
  
}
for(int i=0;R<255;R++){

 for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(R,G,B)); 
  pixels.show();
  
  }
delay(50);
  
  
}
for(int i=0;G>0;G--){

 for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(R,G,B)); 
  pixels.show();
  
  }
 delay(50);
  
}
}






