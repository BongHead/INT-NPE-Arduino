#ifndef SERVOMOTEUR_H
#define SERVOMOTEUR_H

#include <Arduino.h>
#include <Servo.h>

class ServoMoteur{
    private:
        Servo servo1;
        Servo servo2;
        Servo servo3;
        Servo servo4;
        int pin1;
        int pin2;
        int pin3;
        int pin4;

    public:
        ServoMoteur(Servo servo1, Servo servo2, Servo servo3, Servo servo4, int pin1, int pin2, int pin3, int pin4);
        void init();
        void Forward();
        void Backward();
        void Left();
        void Right();
};
#endif