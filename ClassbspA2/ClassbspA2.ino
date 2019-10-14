#include <Arduino.h>
class CBlinkLED
{
  private:
    int pinNr;
    boolean blinkenAktiv;
    long int letzteBlinkZeit;
    long int blinkZeit;
    long int zeitSteigFlanke;
    long int zeitFallFlanke;
    boolean letzterWert;
    bool blink4ever;
    int anzahl;

  public:
    CBlinkLED(int pinNr0)
    {
      pinNr = pinNr0;
      blinkenAktiv = false;
      pinMode(pinNr, OUTPUT);
      digitalWrite(pinNr, LOW);
    }
    boolean isBlinking()
    {
      return blinkenAktiv;
    }

    boolean isOn()
    {
      return digitalRead(pinNr);
    }

    void einschalten()
    {
      digitalWrite(pinNr, HIGH);
      blinkenAktiv=false;
    }
    void umschalten()
    {
      digitalWrite(pinNr, !digitalRead(pinNr));
    }
    void ausschalten()
    {
      digitalWrite(pinNr, LOW);
      blinkenAktiv=false;
    }

    long int zeitAn()
    {
      if (isOn())
      {
        return millis() - zeitSteigFlanke;
      }
      else
      {
        return zeitFallFlanke - zeitSteigFlanke;
      }
    }

    long int zeitAus()
    {
      if (!isOn())
      {
        return millis() - zeitFallFlanke;
      }
      else
      {
        return zeitSteigFlanke - zeitFallFlanke;
      }
    }



    void check()
    {

      if(!blink4ever && blinkenAktiv && (millis() > letzteBlinkZeit + blinkZeit))
      {
        umschalten();
        letzteBlinkZeit = millis();
      }
      else if (blinkenAktiv && (millis() > letzteBlinkZeit + blinkZeit)&& (anzahl>0))
      {
        umschalten();
        letzteBlinkZeit = millis();
        anzahl--;
      }
    
      bool jetzigerWert = digitalRead(pinNr);
      bool steigendeFlanke = !letzterWert && jetzigerWert;
      bool fallendeFlanke = letzterWert && !jetzigerWert;
      bool letzterWert = jetzigerWert;

      if (steigendeFlanke) zeitSteigFlanke = millis();
      if (fallendeFlanke) zeitFallFlanke = millis();
    }
    void blinken(long int blinkZeit0)
    {
      blinkZeit = blinkZeit0;
      blinkenAktiv = true;
      blink4ever=true;
    }

    void blinken(long int blinkZeit0,int anzahl0)
    {
      blinkZeit = blinkZeit0;
      anzahl=anzahl0;
      blinkenAktiv = true;
    }

};
class CButton
{
  private:
  int pinNr;
  boolean falling;
  boolean rising;
  boolean letzterWert;
  int prellzeit;
  long int settimest;
  long int settimefa;
  int zeitgedrueckt;
  boolean jetzigerWert;

  public:
  CButton(int pinNr0,int prellzeit0)
  {
    pinNr=pinNr0;
    prellzeit=prellzeit0;
    pinMode(pinNr, INPUT);

  }
  boolean ispresed()
  {
    return digitalRead(pinNr);
  }

  void check()
  {
    static bool letzterWert = false;
    bool jetzigerWert;
    static long int risingTime;
    static int letzteZeit;
    bool pressed;
    static bool oldPressed;


    jetzigerWert = ispresed();
      if(!letzterWert && jetzigerWert){
        risingTime = millis();
      }
      if((millis() >= risingTime + prellzeit)&&jetzigerWert)
      {
        pressed = jetzigerWert;
      }
      letzterWert = jetzigerWert;

      rising = pressed && !oldPressed;
      falling = !pressed && oldPressed;

      oldPressed=pressed;
  }
      boolean steigendeFlanke()
    {
      return rising;
    }
    boolean fallendeFlanke()
    {
      return falling;
    }
    boolean zeitGedrueckt()
    {
      return zeitgedrueckt;
    }
    boolean jetzigWert()
    {
      return jetzigerWert;
    }
};

CBlinkLED led13(13);
CButton button5(7,100);
void setup()
{
  Serial.begin(9600);
led13.blinken(1000);
}
void loop()
{
  int i=0;
 led13.check();
 button5.check();
 if(button5.steigendeFlanke())
{
 i++;
}
Serial.println(i);



}
