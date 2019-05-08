void setup() {

pinMode(6,OUTPUT);

}
double pot=0;
double starke=0;
void loop() {
  
pot=analogRead(A2);

for(int i=0; i<20;i++)
{
  
starke=exp(((100/20.0)*i)/(100.0/log(256)))-1;
analogWrite(6,starke);
delay(500);
}


}
