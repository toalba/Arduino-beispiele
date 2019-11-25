#include <Arduino.h>
#define rot 4
#define gruen 5
int zustandsnr;
int startzeit;

void rot_start_1()
{
  digitalWrite(rot,HIGH);
  digitalWrite(gruen,LOW);
  startzeit=millis();
  zustandsnr=2;
}
void rot_warten_2()
{
  if(millis()>startzeit+7000) zustandsnr=3;
}
void gruen_start_3()
{
  digitalWrite(rot,LOW);
  digitalWrite(gruen,HIGH);
  startzeit=millis();
  zustandsnr=4;
}
void gruen_warten_4()
{
  if(millis()>startzeit+5000) zustandsnr=1;
}




void setup() {
  pinMode(red,OUTPUT);
  pinMode(gruen,OUTPUT);
  

}
void loop() {

  switch (zustandsnr)
  {
  case 1: rot_start_1();
  break;
  case 2: rot_warten_2();
  break;
  case 3: gruen_start_3();
  break;
  case 4: gruen_warten_4();
  break;
  }
  

}
