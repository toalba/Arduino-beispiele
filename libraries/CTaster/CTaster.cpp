#include <Arduino.h>
#include "CTaster.h"

  CTaster::  CTaster(int pinNr_){
      pinNr = pinNr_;
      pinMode(pinNr, INPUT);
    }

    boolean CTaster:: istGedrueckt()
    {
      return digitalRead(pinNr);
    }
        
    void CTaster::check()
    {
      bool jetzigerWert=istGedrueckt();
      steigFlanke = !letzterWert && jetzigerWert;
      fallFlanke = letzterWert && !jetzigerWert; 
      letzterWert = jetzigerWert;
      if (steigFlanke)
      {
        zeitSteigFlanke=millis();
        AnzahlSteigendeFlanken = AnzahlSteigendeFlanken + 1 ;
      }
      if (fallFlanke) zeitFallFlanke=millis();
    }
    int CTaster::steigendeFlanken()
    {
      return AnzahlSteigendeFlanken;  
    }
    bool CTaster::steigendeFlanke()
    {
      return steigFlanke;   
    }

    bool CTaster::fallendeFlanke()
    {
      return fallFlanke;
    }

    long int CTaster::zeitGedrueckt()
    {
      if (istGedrueckt())
      {
        return millis()-zeitSteigFlanke;
      }
      else
      {
        return zeitFallFlanke - zeitSteigFlanke;
      }
    }

    long int CTaster::zeitLosgelassen()
    {
      if (!istGedrueckt())
      {
        return millis()-zeitFallFlanke;
      }
      else
      {
        return zeitSteigFlanke - zeitFallFlanke;
      }
    }
    
