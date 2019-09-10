
#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  static int counter= 0
Serial.println("Hallo")
counter++;
delay(2000);

}
