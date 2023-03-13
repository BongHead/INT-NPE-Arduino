#ifndef SERVOMOTEUR_H
#define SERVOMOTEUR_H

#include <Arduino.h>

class ServoMoteur{
    private:
        int pin;

    public:
        ServoMoteur(int pin)
        void init();
        void Forward();
        void Backward();
        void Left();
        void Right();
};
#endif