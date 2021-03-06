#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6

#define NUMPIXELS      90

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second
int anfang=0;
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

pinMode(5,INPUT);
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
int LED=LEDwert*(15.0/1023)+1; //k*x+d 
if(digitalRead(5)==HIGH)
{
  anfang=(anfang+1)%NUMPIXELS;

for(int i= anfang; i<=anfang +LED-1;i++)
{
  pixels.setPixelColor(i, pixels.Color(R,G,B));
}
pixels.show();
delay(60);
for(int i= anfang; i<=anfang+LED-1;i++)
{
  pixels.setPixelColor(i, pixels.Color(0,0,0));
}
pixels.show();
}
else
{
  for(int i=0; i<LED;i++){
pixels.setPixelColor(i, pixels.Color(R,G,B));
}
pixels.show();
for(int i=0;i<NUMPIXELS;i++)
{
pixels.setPixelColor(i, pixels.Color(0,0,0));
}
pixels.show();
}
}




