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
        void Forward(int speed);
        void Backward(int speed);
        void Left(int speed);
        void Right(int speed);
        void Stop();
        void RotateClockwise(int speed);
        void RotateCounterClockwise(int speed);
        void DiagonalUpLeft(int speed);
        void DiagonalUpRight(int speed);
        void DiagonalDownLeft(int speed);
        void DiagonalDownRight(int speed);
};
#endif