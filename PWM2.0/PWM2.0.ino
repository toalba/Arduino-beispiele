void setup() {

pinMode(6,OUTPUT);

}
double starke=0;
void loop() {
  for(double i=0;i<20;i++)
  {
   starke=exp(((100/20.0)*i)/(100/log(256)))-1;
   analogWrite(6,starke);
   delay(500);
  }




}
