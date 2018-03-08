
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

int richtung=1;
int LEDnr=1;

void loop() {

 for(int i=0;i<5;i++)
 {
  int LED= i+ LEDnr;
  pixels.setPixelColor(LED, pixels.Color(8,0,255));
 }
  pixels.show();
  delay(80);
 for(int i=0;i<5;i++)
 {
 int LED= i+ LEDnr;
  pixels.setPixelColor(LED, pixels.Color(0,0,0));
 }
  pixels.show();
  if(LEDnr==NUMPIXELS-1||LEDnr==0)
  {
    richtung=-richtung;
  }
  LEDnr=LEDnr +richtung;
  
  }

