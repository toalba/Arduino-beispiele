#include <Arduino.h>

class CTaster {
  private:
    int pinNr;
    bool steigFlanke;
    bool fallFlanke;
    boolean letzterWert;
    long int zeitSteigFlanke;
    long int zeitFallFlanke;
    int AnzahlSteigendeFlanken;
  public:
    CTaster(int pinNr_);

    boolean istGedrueckt();

    void check();

    int steigendeFlanken();

    bool steigendeFlanke();


    bool fallendeFlanke();


    long int zeitGedrueckt();


    long int zeitLosgelassen();


};
