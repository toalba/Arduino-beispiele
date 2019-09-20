
#include <Arduino.h>
void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0, isr, RISING);
  Serial.begin(9600);
}

int counter = 0;
int old_counter = 0;
long int fl_time = micros();
long int old_fl_time;
void loop() {
  // put your main code here, to run repeatedly:
  if (old_counter != counter)
  {
    Serial.println(counter);
    old_counter = counter;
    Serial.println(old_fl_time - fl_time);
  }
}

void isr()
{
  counter++;
  old_fl_time = fl_time;
  fl_time = micros();
}
