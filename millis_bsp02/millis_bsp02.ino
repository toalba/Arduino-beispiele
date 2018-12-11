void setup() {
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,INPUT);

}

int a=0;
int b=0;
int c=1;

void loop() {

  if(digitalRead(9)==HIGH && c==1)
  {
    a=millis();
    c--;
  }
  if(millis()>a+1000 && digitalRead(9)==HIGH)
  {
    digitalWrite(10,HIGH);
  }
    if(millis()>a+2000 && digitalRead(9)==HIGH)
  {
    digitalWrite(11,HIGH);
  }
    if(millis()>a+3000 && digitalRead(9)==HIGH)
  {
    digitalWrite(12,HIGH);
  }
    if(millis()>a+4000 && digitalRead(9)==HIGH)
  {
    digitalWrite(13,HIGH);
  }

    if(digitalRead(9)==LOW && c==0)
  {
   b=millis();
      c++;
  }
  if(millis()>b+500)
  {
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }

}
