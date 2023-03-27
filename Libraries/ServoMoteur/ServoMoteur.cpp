#include "ServoMoteur.h"
#include <IRremote.h>
#include <Servo.h>

ServoMoteur::ServoMoteur(
    //Constructor
    Servo servo1,
    Servo servo2,
    Servo servo3,
    Servo servo4,
    int pin1,
    int pin2,
    int pin3,
    int pin4
    ){
    this->servo1 = servo1;
    this->servo2 = servo2;
    this->servo3 = servo3;
    this->servo4 = servo4;
    this->pin1 = pin1;
    this->pin2 = pin2;
    this->pin3 = pin3;
    this->pin4 = pin4;
}

void ServoMoteur::init(){
    //Attach each pin to the motors (in void setup())
    //servo.attach => pinmode(pin, OUTPUT);
    servo1.attach(pin1);
    servo2.attach(pin2);
    servo3.attach(pin3);
    servo4.attach(pin4);
}
/*Servos:
          (front)
          1    2    
  (Left)          (Right)
          3    4
          (Back)
    (looking from top)
*/

void ServoMoteur::Forward(){
    //Rotate all 4 wheels forward *while* IR remote -> up arrow
    servo1.write(180);
    servo2.write(0);
    servo3.write(180);
    servo4.write(0);
    //delay(15); //allow the servo some time to spin
}

void ServoMoteur::Backward(){
    //Rotate all 4 wheels backward *while* IR remote -> down arrow
    servo1.write(0);
    servo2.write(180);
    servo3.write(0);
    servo4.write(180);
    //delay(15);
}

void ServoMoteur::Left(){
    //Rotate 1 and 4 backward, 2 and 3 forward *while* IR remote -> left arrow
    servo1.write(0);
    servo2.write(0);
    servo3.write(180);
    servo4.write(180);
    //delay(15);
}

void ServoMoteur::Right(){
    //Rotate 1 and 4 forward, 2 and 3 backward *while* IR remote -> right arrow
    servo1.write(180);
    servo2.write(180);
    servo3.write(0);
    servo4.write(0);
    //delay(15);
}

void ServoMoteur::Stop(){
    //All stop
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
}

void ServoMoteur::RotateClockwise(){
    //Rotate 1 and 3 forward, 2 and 4 backward
    servo1.write(180);
    servo2.write(180);
    servo3.write(180);
    servo4.write(180);
}

void ServoMoteur::RotateCounterClockwise(){
    //Rotate 1 and 3 backward, 2 and 4 forward
    servo1.write(0);
    servo2.write(0);
    servo3.write(0);
    servo4.write(0);
}

void ServoMoteur::DiagonalUpRight(){
    //Stop 2 and 3, 1 and 4 forward
    servo1.write(180);
    servo2.write(90);
    servo3.write(90);
    servo4.write(0);
}

void ServoMoteur::DiagonalDownLeft(){
    //Stop 2 and 3, 1 and 4 backward
    servo1.write(0);
    servo2.write(90);
    servo3.write(90);
    servo4.write(180);
}

void ServoMoteur::DiagonalUpLeft(){
    //Stop 1 and 4, 2 and 3 forward
    servo1.write(90);
    servo2.write(0);
    servo3.write(180);
    servo4.write(90);
}

void ServoMoteur::RotateCounterClockwise(){
    //Stop 1 and 4, 2 and 3 backward
    servo1.write(90);
    servo2.write(180);
    servo3.write(0);
    servo4.write(90);
}

/*
To-do list

add numerical parameter to functions (to control speed) - Figure out which angle = which speed
void RotateClockWise
void RotateCounterClockWise
void DiagonalUpLeft
void DiagonalUpRight
void DiagonalDownLeft
void DiagonalDownRight

*/
