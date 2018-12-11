
class CBlinkLED
{
  private:
  int pinNr;
  bool blinkenAktiv;
  long int letzteBlinkZeit;

  public:
  CBlinkLED(int pinNr0)
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
    if(millis()>= (letzteBlinkZeit+blinkzeit) && (blinkenAktiv=true)
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

//CblinkLED roteLED(5);
//CblinkLED grueneLED(6);
CBlinkLED internalLED(13);

void setup() 
{
  /*
  roteLED.startBlink(700);
  grueneLED.startBlink(850);
*/
internalLED.startblink(600);
}

void loop() 
{
  /*
  roteLED.check();
  grueneLED.check();
  if(digitalRead(4))
  {
    roteLED.stopBlink();
    grueneLED.stopBlink();
  }
  */
internalLED.check(600);

  

}
}
