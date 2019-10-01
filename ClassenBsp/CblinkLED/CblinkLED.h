#include <Arduino.h>


class CBlinkLED {
  private:
    int pinNr;
    bool blinkenAktiv;
    long int letzteBlinkZeit;
    long int blinkZeit;
    bool letzterWert = LOW;
    long int zeitsteig;
    long int zeitfall;
  public:
    CBlinkLED(int pinNr0);
    void ein();
    void aus();
    void umschalten();
    void startBlink(long int blinkZeit0);
    void stopBlink();
    void check();
    long int zeitein();
    long int zeitaus();
    boolean isBlinking();
    boolean isOn();

};
