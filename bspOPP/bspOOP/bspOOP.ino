
//#include <arduino.h>
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
    }
    void umschalten()
    {
      digitalWrite(pinNr, !digitalRead(pinNr));
    }
    void ausschalten()
    {
      digitalWrite(pinNr, LOW);
    }

    void startBlink(long int blinkZeit0)
    {
      blinkZeit = blinkZeit0;
      blinkenAktiv = true;
    }

    void stopBlink()
    {
      blinkenAktiv = false;
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
      if (blinkenAktiv && (millis() > letzteBlinkZeit + blinkZeit))
      {
        umschalten();
        letzteBlinkZeit = millis();
      }
    
      bool jetzigerWert = digitalRead(pinNr);
      bool steigendeFlanke = !letzterWert && jetzigerWert;
      bool fallendeFlanke = letzterWert && !jetzigerWert;
      bool letzterWert = jetzigerWert;

      if (steigendeFlanke) zeitSteigFlanke = millis();
      if (fallendeFlanke) zeitFallFlanke = millis();
    }

};

class CTaster
{
  private:
    int pinNr;
    boolean letzterWert;
    boolean fallFlanke;
    boolean steigFlanke;
    long int zeitSteigFlanke;
    long int zeitFallFlanke;
    long int anzahlSteigendeFlanken;


  public:
    CTaster(int pinNr1)
    {
      pinMode(pinNr, INPUT);
      pinNr = pinNr1;
    }

    boolean istGedrueckt()
    {
      return digitalRead(pinNr);
    }

    void check ()
    {
      boolean jetzigerWert = istGedrueckt();
      steigFlanke = !letzterWert && jetzigerWert;
      fallFlanke = letzterWert && !jetzigerWert;
      letzterWert = jetzigerWert;
      if (steigFlanke)
      {
        zeitSteigFlanke = millis();
        anzahlSteigendeFlanken=anzahlSteigendeFlanken+1;
      }
      if (fallFlanke) zeitFallFlanke = millis();
    } 
    
    long int anzahlSteigendeFlanke()
    {
      return anzahlSteigendeFlanken;
    }
    
    
    boolean steigendeFlanke()
    {
      return steigFlanke;
    }

    boolean fallendeFlanke()
    {
      return fallFlanke;
    }

    long int zeitGedrueckt()
    {
      if (istGedrueckt())
      {
        return millis() - zeitSteigFlanke;
      }
      else
      {
        return zeitFallFlanke - zeitSteigFlanke;
      }
    }


    long int zeitLosgelassen()
    {
      if (!istGedrueckt())
      {
        return millis() - zeitFallFlanke;
      }
      else
      {
        return 0;
      }
    }
    
    
};


// CBlinkLED roteLED(5);
CBlinkLED grueneLED(7);
CBlinkLED internalLED(13);
CBlinkLED roteLED(8);
CTaster taster1(6);



void setup()
{
  roteLED.startBlink(200);
  //grueneLED.startBlink(850);
  internalLED.startBlink(1200);
  Serial.begin(9600);
}

void loop()
{
  taster1.check();
  roteLED.check();

  if (taster1.zeitGedrueckt() < 1000)
  {
    roteLED.startBlink(200);
  } else
  {
    roteLED.startBlink(1000);
  }

  // internalLED.check();
  // grueneLED.check();

  Serial.println(taster1.anzahlSteigendeFlanke());
  /*  if(taster1.fallendeFlanke())
    {
      internalLED.stopBlink();
      grueneLED.stopBlink();
    }





    roteLED.check();
    grueneLED.check();
    if (digitalRead(4))
    {
    roteLED.stopBlink();
    grueneLED.stopBlink();}
  */

}
