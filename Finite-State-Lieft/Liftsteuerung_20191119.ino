  #include <Arduino.h>
  #define pinMotorUp 12
  #define pinMotorDown 13
  #define pinEU 4
  #define pinEO 5
  #define pinRO 6
  #define pinRU 7
  
  bool EU = false;
  bool EO = false;
  bool RU = false;
  bool RO = false;
  int zustandsnr = 1;
  void lift_oben_1(){
    digitalWrite(pinMotorUp, LOW);
    digitalWrite(pinMotorDown, LOW);
    if(RU && !EU) zustandsnr = 2;
  }
  void lift_faehrt_hinunter_2(){
    digitalWrite(pinMotorDown, HIGH);
    digitalWrite(pinMotorUp, LOW);
    if(EU) zustandsnr = 3;
  }
  void lift_unten_3(){
    digitalWrite(pinMotorUp, LOW);
    digitalWrite(pinMotorDown, LOW);
    if(RO && !EO) zustandsnr = 4;
  }
  void lift_faehrt_hinauf_4(){
    digitalWrite(pinMotorUp, HIGH);
    digitalWrite(pinMotorDown, LOW);
    if(EO) zustandsnr = 1;
  }
void setup() {
  // put your setup code here, to run once:
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
  

}

void loop() {
    EU = !digitalRead(pinEU);
    EO = !digitalRead(pinEO);
    RU = !digitalRead(pinRU);
    RO = !digitalRead(pinRO);
    switch(zustandsnr){
      case 1: lift_oben_1();
      break;
      case 2: lift_faehrt_hinunter_2();
      break;
      case 3: lift_unten_3();
      break;
      case 4: lift_faehrt_hinauf_4();
      break;
    }

}
