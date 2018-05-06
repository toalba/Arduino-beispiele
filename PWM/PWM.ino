void setup() {

pinMode(6,OUTPUT);

}
double pot=0;
double starke=0;
void loop() {
  
pot=analogRead(A2);
starke=exp(((100/1023.0)*pot)/(100/log(256)))-1;
analogWrite(6,starke);




}
