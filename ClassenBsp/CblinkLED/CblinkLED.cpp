#include <Arduino.h>
#include "CblinkLED.h"

CBlinkLED:: CBlinkLED(int pinNr0) {
  pinNr = pinNr0;
  blinkenAktiv = false;
  pinMode(pinNr , OUTPUT);
  digitalWrite(pinNr, LOW);
}

void CBlinkLED:: ein()
{
  digitalWrite(pinNr, HIGH);
}

void CBlinkLED:: aus()
{
  digitalWrite(pinNr, LOW);
}

void CBlinkLED:: umschalten()
{
  digitalWrite(pinNr, !digitalRead(pinNr));
}

void CBlinkLED:: startBlink(long int blinkZeit0)
{
  blinkZeit = blinkZeit0;
  blinkenAktiv = true;
}

void CBlinkLED:: stopBlink()
{
  blinkenAktiv = false;
}

void CBlinkLED:: check()
{
  if ( blinkenAktiv && (millis() > letzteBlinkZeit + blinkZeit))
  {
    umschalten();
    letzteBlinkZeit = millis();
  }
  bool jetzigerWert = digitalRead(pinNr);
  bool steigendeflanke = !letzterWert && jetzigerWert;
  bool fallendeflanke = letzterWert && !jetzigerWert;
  letzterWert = jetzigerWert;
  if (steigendeflanke) zeitsteig = millis();
  if (fallendeflanke) zeitfall = millis();
}
long int CBlinkLED:: zeitein() {
  if (isOn())
  {
    return millis() - zeitsteig;
  } else
  {
    return zeitfall - zeitsteig;
  }
}
long int CBlinkLED:: zeitaus() {
  if (!isOn())
  {
    return millis() - zeitfall;
  }
  else
  {
    return zeitsteig - zeitfall;
  }
}
boolean CBlinkLED:: isBlinking()
{
  return blinkenAktiv;
}

boolean CBlinkLED:: isOn()
{
  return digitalRead(pinNr);
}
