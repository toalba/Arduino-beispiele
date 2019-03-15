#define grueneLED 5
#define roteLED 6
#define A 3
#define B 2
#define dr digitalRead
#define dw digitalWrite


int zustandsnr=1;
int zustandsnralt;
int pos=1;

void zustand1()
{
  if(!dr(A))zustandsnr=2;
  if(!dr(B)) zustandsnr=4;
}

void zustand2()
{
  if(dr(A))zustandsnr=1;
  if(!dr(B)) zustandsnr=3;
}

void zustand3()
{
  if(dr(A))zustandsnr=4;
  if(dr(B)) zustandsnr=2;
}

void zustand4()
{
  if(!dr(A))zustandsnr=3;
  if(dr(B)) zustandsnr=1;
}

void setup() {

  pinMode(A, INPUT);
  pinMode(B, INPUT);
  Serial.begin(9600);
}

void loop() {
    Serial.print(dr(A));
  Serial.print("     ");
    Serial.println(dr(B));
    
    switch(zustandsnr)
  {
    case 1: zustand1();break;
    case 2: zustand2();break;
    case 3: zustand3();break;
    case 4: zustand4();break;

  }

  pos=pos+(zustandsnr-zustandsnralt);
  
  if((zustandsnralt=4)&&(zustandsnr=1))
  {
    pos=pos+4;
  }
  if((zustandsnralt=1)&&(zustandsnr=4))
  {
    pos=pos-4;
  }  
  //Serial.print(pos);
  Serial.print("     ");
  Serial.println(zustandsnr);
}
