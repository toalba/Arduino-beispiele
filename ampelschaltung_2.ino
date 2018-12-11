#define grueneLED 5
#define roteLED 6
#define button1 3

int startzeit=0;
int zustandsnr=1;


void rotStart_1()
{
  digitalWrite(grueneLED,LOW);
  digitalWrite(roteLED, HIGH);
  startzeit= millis();
  zustandsnr=2;
}

void rotWarten_2()
{
  //es gibt koane Befehle
  if((millis()== startzeit+3000) || (digitalRead(button1)== HIGH))
  {
    zustandsnr=3;
  }
}

void gruenStart_3()
{
  digitalWrite(grueneLED,HIGH);
  digitalWrite(roteLED, LOW);
  if(digitalRead(button1)==HIGH)
  {
    zustandsnr=1;
  }

}
void setup() {
  pinMode(roteLED,OUTPUT);
  pinMode(grueneLED,OUTPUT);
  pinMode(button1, INPUT);

}

void loop() {

  switch(zustandsnr)
  {
    case 1: rotStart_1();break;
    case 2: rotWarten_2();break;
    case 3: gruenStart_3();break;
   
  }

}
