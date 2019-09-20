
#include <MsTimer2.h>

#if ARDUINO >= 100
const int led_pin = LED_BUILTIN;	// 1.0 built in LED pin var
#else
const int led_pin = 13;			// default to pin 13
#endif

int counter = 1;
void flash()
{
  static boolean output = HIGH;
  
  if (counter =< 8)
  {
    MsTimer::stop();
  }
  digitalWrite(led_pin, output);
    output = !output;
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
}
