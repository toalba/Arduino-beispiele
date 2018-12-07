
#include <MsTimer2.h>

// Switch on LED on and off each half second

#if ARDUINO >= 100
const int led_pin = LED_BUILTIN;	// 1.0 built in LED pin var
#else
const int led_pin = 13;			// default to pin 13
#endif

long int Zeit = 0;
int zaehler = 0;
long int steigflankzeit = 0;
long int MStime = 0;
long int fallflankzeit = 0;

void flash()
{  
  static boolean output = HIGH;
  
  digitalWrite(led_pin, output);
  output = !output;
  zaehler++;
  
 // if(zaehler > 10 )
  //{ // 10 wegen 5 mal umschalten
    //MsTimer2::stop();
   // zaehler = 0;
  //}
}
void ISRFlanke()
{
  if(digitalRead(3))
  {
    steigflankzeit = millis();  
  }
  else
  {
    fallflankzeit= millis();
    if(fallflankzeit-steigflankzeit>200)
    {
    MsTimer2::stop();
    MsTimer2::set(fallflankzeit-steigflankzeit,flash);
    MsTimer2::start();
  }
  }
  Serial.print(steigflankzeit);
  Serial.print("       ");
  Serial.println(fallflankzeit);
 
}
long int steigZ = 0;
void ISRwiederholen(){
  
  
  if(digitalRead(led_pin) == HIGH)
  {
     steigZ = millis();   
  }
  else
  {
    Zeit = millis() - steigZ;  
    MsTimer2::set(Zeit, flash); 
    MsTimer2::start();
  }
  
}
void setup()
{
  pinMode(led_pin, OUTPUT);
   pinMode(3,INPUT);
  attachInterrupt(1 , ISRwiederholen , CHANGE);

  MsTimer2::set(500, flash); // 500ms period
  MsTimer2::start();
  Serial.begin(9600);
}
void loop() 
{
    
}
