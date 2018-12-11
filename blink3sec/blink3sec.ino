void setup() {

  pinMode(5,INPUT);
  pinMode(6,OUTPUT);

}
int jetzigerWert;
int letzerWert;
int long letzteZeit =0;


void loop() {
  int steigendFlanke;
  jetzigerWert=digitalRead(5);
  steigendFlanke=!letzerWert && jetzigerWert;

  if(steigendFlanke)
  {
    digitalWrite(6,HIGH);
    letzteZeit=millis();
  }


  if(millis()> (letzteZeit+3000))
  {
    digitalWrite(6,LOW);
  }
 
 letzerWert= jetzigerWert;


}
