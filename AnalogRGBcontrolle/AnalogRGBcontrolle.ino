
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
  
int Rwert= analogRead(A4);
int Gwert= analogRead(A5);
int Bwert= analogRead(A6);
int LEDwert=analogRead(A3);

int R=Rwert/4;
int G=Gwert/4;
int B=Bwert/4;
int LED=LEDwert*(15/1023)+1; //k*x+d 
for(int i=0; i<LED;i++){
pixels.setPixelColor(i, pixels.Color(R,G,B));
}
pixels.show();
}
