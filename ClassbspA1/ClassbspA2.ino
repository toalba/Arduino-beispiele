
class CLED
{
    private:
    int pinNr;
    long int blinkzeit;
    long int letzteZeit;

    public:
    CLED(int pinNr0)
    {
        pinNr=pinNr0;
        pinMode(pinNr,OUTPUT);

    }
    void ein()
    {
        digitalWrite(pinNr,HIGH)
    }
    void aus()
    {
        digitalWrite(pinNr,OUTPUT)
    }
    void check()
    {
        if(millis()>=letzteZeit+blinkzeit)
        {
            blinken();
            letzteZeit=millis();
        }
    }
    void blinken(long int blinkzeit0)
    {
        long int blinkzeit=blinkzeit0;
        umschalten();
    }
    void umschalten()
    {
        digitalWrite(pinNr,!digitalRead(pinNr))
    }
};

CLED led13(13);
void setup()
{
    led13.blinken(500);
}
void loop()
{
 led13.check();
}
