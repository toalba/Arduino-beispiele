#include <CblinkLED.h>
#include <CTaster.h>


CBlinkLED internalLED(13);
CBlinkLED grueneLED(6);
CTaster taster1(4);

void setup() {
  
  
  //grueneLED.startBlink(200);
  //internalLED.startBlink(1200);
  Serial.begin(9600);
}

void loop() {
 
 
 //internalLED.check();
 grueneLED.check();
 taster1.check();
 //Serial.println(taster1.zeitGedrueckt());
  long int zeit = taster1.zeitGedrueckt();
 if(zeit< 1000){
  grueneLED.startBlink(200); 
 }
 if(zeit >= 1000)
 {
   grueneLED.startBlink(1000);
 }
 //Serial.println(grueneLED.zeitein());
 //Serial.println(grueneLED.zeitaus());
 Serial.println(taster1.steigendeFlanken());

 /*
 if(taster1.fallendeFlanke())
 {
  internalLED.stopBlink();
  grueneLED.stopBlink();  
 } 
 if(taster1.steigendeFlanke())
 {
  grueneLED.startBlink(1500);
  internalLED.startBlink(1000);  
 }*/
}
