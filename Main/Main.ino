#include <ServoMoteur.h>
#include <Servo.h>
#include <IRremote.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int pin1 = 1;
int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
ServoMoteur moteur(servo1, servo2, servo3, servo4, pin1, pin2, pin3, pin4);

int IRpin = 5;
IRrecv irrecv(IRpin);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  moteur.init(); //Utilisation possible. Essayez sans cette ligne de code pour voir si le constructeur peut setup.
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
    if(results.value == 0XFFFFFFFF)
      results.value = key_value;
    switch(results.value){
      case 0xFF18E7:
      moteur.Forward();
      break;
      //Et ainsi de suite...
    }
    key_value = results.value;
    irrecv.resume();
  }
}
