
#include "CZaehler.h"

CZaehler anzahlpakete;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  anzahlpakete.erhoehe();
  if(anzahlpakete.getzaehlerstand()>10)
    {
    digitalWrite(7,LOW);
    }

}
