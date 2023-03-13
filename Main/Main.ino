#include <IRremote.h>
#include <IRremoteInt.h>

#include <Servo.h>

#include <ServoMoteur.h>


//Changez les noms au besoin:
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int pin1;
int pin2;
int pin3;
int pin4;

void setup(){
  ServoMoteur(servo1, servo2, servo3, servo4, pin1, pin2, pin3, pin4);
  Serial.begin(9600);
}

void loop(){
  Forward
}