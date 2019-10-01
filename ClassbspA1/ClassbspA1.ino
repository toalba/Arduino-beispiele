#include <Arduino.h>
 class CLED
{
  private:
  int pinNr;
  bool blinkenAktiv;
  long int letzteBlinkZeit;

  public:
  CLED(int pinNr0)
  {
    pinNr = pinNr0;
    pinMode(pinNr,OUTPUT);
    blinkenAktiv = false;
    digitalWrite(pinNr,LOW);
  }

  void ein()
  {
    digitalWrite(pinNr,HIGH);
  }
    void aus()
  {
    digitalWrite(pinNr,LOW);
  }
  boolean check(long int blinkzeit0)
  {
    long int blinkzeit=blinkzeit0;
    if((millis()>= letzteBlinkZeit+blinkzeit) && (blinkenAktiv=true))
    {
      return true;
      letzteBlinkZeit=millis();
    }
    
  }

  void umschalten()
  {
    digitalWrite(pinNr,!digitalRead(pinNr));    
  }

  void blinken(long int blinkzeit0)
  {
    long int blinkzeit=blinkzeit0;
    if(millis()>= (letzteBlinkZeit+blinkzeit) && (blinkenAktiv=true))
    {
       umschalten();  
       letzteBlinkZeit=millis();
    }
 
  }
  void startblink(long int blinkzeit0)
  {
   long int blinkzeit=blinkzeit0;
    blinkenAktiv=true;
  }
};

CLED led1(4);
void setup() {
  

}


void loop() 
{
  led1.check();


}
