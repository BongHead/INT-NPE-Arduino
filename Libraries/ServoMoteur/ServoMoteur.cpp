#include "ServoMoteur.h"
#include <IRremote.h>
#include <Servo.h>

ServoMoteur::ServoMoteur(int pin){
    this->pin=pin;
    init();
}

void ServoMoteur::init(){
    pinMode(pin, OUTPUT);
    off();
}

void ServoMoteur::Forward(){
    digitalWrite(pin, HIGH);
}