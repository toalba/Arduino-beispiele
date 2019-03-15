int startzeit=0;
int zustandsnr=1;
bool Alarm=true;


void zeitmessung_Starten()
{
  startzeit=millis();
}

void Warten()
{
  if(digitalRead(6))
  {
    zustandsnr=4;
  }
  if(millis()>= startzeit+10000)
  {
    zustandsnr=3;
  }

 
}
void Alarm_an()
{
  Alarm=true;
  zustandsnr=1;
}
void Alarm_aus()
{
  Alarm=false;
  zustandsnr=1;
}



void setup() {
pinMode(6,INPUT);
pinMode(7,OUTPUT);
}

void loop() {
 switch(zustandsnr)
 {
  case 1: zeitmessung_Starten(); break;
  case 2: Warten();break;
  case 3: Alarm_an();break;
  case 4:Alarm_aus();break;
 }
digitalWrite(7,Alarm);


}
