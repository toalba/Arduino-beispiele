#define dr digitalRead
#define tasterA 8
#define tasterB 6
long int zustandsNr = 1;
long int pos;
long int zustandsNr_alt;


void zustand1()
{
  if(!dr(tasterA)) zustandsNr = 2;
  if(!dr(tasterB)) zustandsNr = 4;
}

void zustand2()
{
 if(!dr(tasterB)) zustandsNr = 3;
 if(dr(tasterA)) zustandsNr = 1;
}

void zustand3()
{
  if(dr(tasterA)) zustandsNr = 4;
  if(dr(tasterB)) zustandsNr = 2; 
}

void zustand4()
{
  if(dr(tasterB)) zustandsNr = 1;
  if(!dr(tasterA)) zustandsNr = 3;
}

void setup() {
  Serial.begin(9600);
}


void loop() {

  switch(zustandsNr)
  {
    case 1: zustand1(); break;
    case 2: zustand2(); break;
    case 3: zustand3(); break;
    case 4: zustand4(); break;
  }

  pos = pos + (zustandsNr - zustandsNr_alt);

  if((zustandsNr_alt == 4) &&  (zustandsNr == 1))
  {
    pos = pos + 4;
    
    
  }
  if((zustandsNr_alt == 1) && (zustandsNr == 4)) 
  {
    pos = pos - 4;
    
  }
  zustandsNr_alt = zustandsNr;
  Serial.print(zustandsNr);Serial.print("  ");
  Serial.println(pos);
  
}
