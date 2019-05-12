// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

#include <Arduino.h>
#include <Wire.h>
  int x=0;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);   
  pinMode(7,OUTPUT);        // start serial for output
}

void loop() {
  delay(x*10);
  digitalWrite(13,HIGH);
  delay(x*10);
  digitalWrite(13,LOW);
  
  
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
   x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}

