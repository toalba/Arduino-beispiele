
#include <MsTimer2.h>

// Switch on LED on and off each half second

#if ARDUINO >= 100
const int led_pin = LED_BUILTIN; // 1.0 built in LED pin var
#else
const int led_pin = 13;     // default to pin 13
#endif


void flash()
{
  static boolean output = HIGH;
  static int counter= 0;
  if(counter >=7)
  {
    MsTimer2::stop();
  }
  digitalWrite(led_pin, output);
  output = !output;

  digitalWrite(led_pin, !digitalRead(led_pin));
  counter++;
}

void setup()
{
  pinMode(led_pin, OUTPUT);

  MsTimer2::set(500, flash); // 500ms period
  MsTimer2::start();
}

void loop()
{
  delay(10000);
}
