#define grueneLED 5
#define roteLED 6
#define button1 3
#define dr digitalRead
#define dw digitalWrite

long int startzeit=0;
int zustandsnr=1;
int zaehler=0;


void gruenStart_1()
{
  dw(grueneLED,HIGH);
  dw(roteLED, LOW);
  startzeit= millis();
  zustandsnr=2;
}

void gruenWarten_2()
{
  //es gibt koane Befehle
  if((millis()== startzeit+5000))
  {
    zustandsnr=3;
  }
}
void gruenBlinkstart_3()
{
  dw(grueneLED,!dr(grueneLED));
  startzeit=millis();
  zaehler++;
  zustandsnr=4;
}

void gruenBlinkwarten_4()
{
  if((millis()== startzeit+500))
  {
    if(zaehler>8)
    {
      zustandsnr=5;
      zaehler=0;
    }
    else
    {
    
      zustandsnr=3;
    }
  }
}

void rotStart_5()
{
  dw(grueneLED,LOW);
  dw(roteLED, HIGH);
  startzeit= millis();
  zustandsnr=6;
}

void rotWarten_6()
{
  //es gibt koane Befehle
  if((millis()== startzeit+3000) || (dr(button1)==HIGH))
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
    case 1: gruenStart_1();break;
    case 2: gruenWarten_2();break;
    case 3: gruenBlinkstart_3();break;
    case 4: gruenBlinkwarten_4();break;
    case 5: rotStart_5();break;
    case 6: rotWarten_6();break;
  }
}
