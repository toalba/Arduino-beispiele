void setup() {
  pinMode(13,OUTPUT);

}

int a=1000;
int x=2000;
int y=400;
int z=800;

void loop() {

int u= millis();
  if(u>=a)
  {
   digitalWrite(13,HIGH);
   a=a+2000;
  }
  if(u>=x)
  {
   digitalWrite(13,LOW);
   x=x+2000;
  }

    if(u>=y)
  {
   digitalWrite(12,HIGH);
   y=y+800;
  }
  if(u>=z)
  {
   digitalWrite(12,LOW);
   z=z+800;
  }

}
