#include <Arduino.h>

void setup() {
 attachInterrupt(0, isr,CHANGE);
 Serial.begin(9600);
}
int counter = 0;
int steigzeit;
int time;
boolean zustandneu;
boolean zustandalt;
boolean steigflanke;
int dauer=0;
boolean ausgabe;



void loop() {
if(ausgabe)
{
  Serial.println(counter);
  Serial.println(dauer);
  ausgabe=false;
}
}
void isr()
{
  int a=millis();
  if(a-time>1000)
  {
  zustandneu=digitalRead(2);
  steigflanke = zustandneu && !zustandalt;
  zustandalt=zustandneu;
  if(steigflanke)
  {
  counter++;
  steigzeit=millis();
  ausgabe=false;
  }
  else{
  dauer=millis()-steigzeit;
  ausgabe=true;
  }
  }
  time=millis();

}
