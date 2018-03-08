
const int led=7;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 pinMode(led, OUTPUT);
 pinMode(LED_BUILTIN, OUTPUT); 
 delay(20);

}


void loop() {
  


 for(int i=0; i<3;i++)
  {
   
  digitalWrite(led, HIGH);   
  delay(1000);                  
  digitalWrite(led, LOW);    
  delay(300);}
for(int i=0;i<3;i++)
{
digitalWrite(led, HIGH);   
  delay(500);                       
  digitalWrite(led, LOW);    
  delay(300);
  }
for(int i=0;i<3;i++)
{
  digitalWrite(led, HIGH);  
  delay(10);                      
  digitalWrite(led, LOW);    
  delay(300);
}

  
  digitalWrite(led, HIGH);
  delay(2000);
   digitalWrite(led, LOW);
   delay(10);




   
}
