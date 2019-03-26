#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  

  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);

}

void loop() { // run over and over
  if (mySerial.available()) {
    char an = mySerial.read();
    Serial.write(an);
    if(an == 'X')
    {
      digitalWrite(3,HIGH); 
    }
   
    if(an == 'Y')
    {
      digitalWrite(3,LOW);
    }
    if(an == 'W')
    {
      digitalWrite(4,HIGH);
    }
        if(an == 'Z')
    {
      digitalWrite(4,LOW);
    }
  }
  
}
