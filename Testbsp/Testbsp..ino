void setup() {
  pinMode(8, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  int ontime = analogRead(A2);
  digitalWrite(8, HIGH);
  delay(4000 / 1023.0 * ontime + 1000);
  int offtime = analogRead(A3);
  digitalWrite(8, LOW);
  delay(2000 / 1023.0 * offtime + 2000);
analogWrite(8,onetime);
}
