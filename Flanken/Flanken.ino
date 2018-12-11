void setup() {
pinMode(6,OUTPUT);
pinMode(7,INPUT);  


}

int jetzigerWert;
int letzerWert;
int long letzteZeit =1000;


void loop() {
int steigendFlanke;
int fallendeFlanke;
int long blinkdauer;
int long letzteZeit;
int long zeitsteigendeFlanke;
  
jetzigerWert=digitalRead(7);
steigendFlanke=!letzerWert && jetzigerWert;
fallendeFlanke=letzerWert && !jetzigerWert;
letzerWert= jetzigerWert;

if(steigendFlanke)
{
  zeitsteigendeFlanke=millis();
}
if(fallendeFlanke)
{
int long tastendruck =millis()-zeitsteigendeFlanke;
 if((tastendruck>500)&&(tastendruck<5000))
 {
  blinkdauer=tastendruck;
 }
}
if(millis()>letzteZeit+blinkdauer)
{
  letzteZeit= millis();
  digitalWrite(6,!digitalRead(6));
}

 
}
