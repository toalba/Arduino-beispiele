
const int led1=7;
const int led2=6;
const int led3=5;


void setup() {
  // put your setup code here, to run once:

pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);

}

void loop() {
  
  digitalWrite(led1,HIGH);
  delay(200);
  digitalWrite(led1, LOW);

  digitalWrite(led2,HIGH);
  delay(200);
  digitalWrite(led2, LOW);

  digitalWrite(led3,HIGH);
  delay(200);
  digitalWrite(led3, LOW);

  delay(500);

}
