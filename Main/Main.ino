#include <IRremote.h>
#include <ServoMoteur.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
const int pin1 = 1;
const int pin2 = 2;
const int pin3 = 3;
const int pin4 = 4;
ServoMoteur moteur(servo1, servo2, servo3, servo4, pin1, pin2, pin3, pin4);

const int recvPin = 5;
IRrecv irrecv(recvPin);
decode_results results;

bool isHeldDown;
unsigned long previousState;

void setup(){
Serial.begin(9600);
irrecv.enableIRIn();
irrecv.blink13(true);
moteur.init();
}

void loop(){
  if(irrecv.decode(&results)){
    isHeldDown = results.value == 4294967295;
    Serial.println(results.value);
    if(!isHeldDown){//is not held down
      previousState = results.value;
      switch(results.value){
        case 16718055:
        moteur.Forward();
        delay(500);
        moteur.Stop();
        break;
        case 16730805:
        moteur.Backward();
        delay(500);
        moteur.Stop();
        break;
        case 16716015:
        moteur.Left();
        delay(500);
        moteur.Stop();
        break;
        case 16734885:
        moteur.Right();
        delay(500);
        moteur.Stop();
        break;
        case 16726215:
        moteur.Stop();
        break;
        case 16724175:
        moteur.DiagonalUpLeft;
        break;
        case 16743045:
        moteur.DiagonalUpRight;
        break;
        case 16728765:
        moteur.DiagonalDownLeft;
        break;
        case 16732845:
        moteur.DiagonalDownRight;
        break;
        case 16769055:
        moteur.RotateClockwise;
        break;
        case 16748655:
        moteur.RotateCounterClockwise;
        break;
      }
    }
    else{
      switch(previousState){//is held down
        case 16718055:
        moteur.Forward();
        break;
        case 16730805:
        moteur.Backward();
        break;
        case 16716015:
        moteur.Left();
        break;
        case 16734885:
        moteur.Right();
        break;
        case 16726215:
        moteur.Stop();
        break;
        case 16724175:
        moteur.DiagonalUpLeft;
        break;
        case 16743045:
        moteur.DiagonalUpRight;
        break;
        case 16728765:
        moteur.DiagonalDownLeft;
        break;
        case 16732845:
        moteur.DiagonalDownRight;
        break;
        case 16769055:
        moteur.RotateClockwise;
        break;
        case 16748655:
        moteur.RotateCounterClockwise;
        break;
      }
    }
  
    irrecv.resume();
  }
  //moteur.Forward();
}