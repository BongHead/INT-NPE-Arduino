#include <IRremote.h>
#include <ServoMoteur.h>
#include <Servo.h>
#include <SR04.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
const byte pin1 = 1;
const byte pin2 = 2;
const byte pin3 = 3;
const byte pin4 = 4;
ServoMoteur moteur(servo1, servo2, servo3, servo4, pin1, pin2, pin3, pin4);

const byte recvPin = 5;
IRrecv irrecv(recvPin);
decode_results results;

bool isHeldDown;
unsigned long previousState;

const byte pinEcho = 6;
const byte pinTrig = 7;
SR04 ultrason = SR04(pinEcho, pinTrig);
long distance;
int speed = 0;
const byte pinGreen = 11;
const byte pinYellow = 12;
const byte pinRed = 13;

const byte pinRes = A0;
const byte pinLight1 = 9;
const byte pinLight2 = 10;
int value;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  moteur.init();
  pinMode(pinLight1, OUTPUT);
  pinMode(pinLight2, OUTPUT);
  pinMode(pinRes, INPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinRed, OUTPUT);
}

void loop(){
  value = analogRead(pinRes); //Untested values
  if(value > 300){
    digitalWrite(pinLight1, LOW);
    digitalWrite(pinLight2, LOW);
  }
  else{
    digitalWrite(pinLight1, HIGH);
    digitalWrite(pinLight2, HIGH);
  }


  distance = ultrason.Distance(); //in cm
  if(distance < 20){
    speed = -45;
    digitalWrite(13, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }
  else if(distance < 35){
    speed = 0;
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  }
  else{
    speed = 0;
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  }

  
  if(irrecv.decode(&results)){
    isHeldDown = results.value == 4294967295;
    Serial.println(results.value);

    if(!isHeldDown){//is not held down
      previousState = results.value;
      switch(results.value){
        case 16718055:
        moteur.Forward(speed);
        delay(500);
        moteur.Stop();
        break;

        case 16730805:
        moteur.Backward(speed);
        delay(500);
        moteur.Stop();
        break;

        case 16716015:
        moteur.Left(speed);
        delay(500);
        moteur.Stop();
        break;

        case 16734885:
        moteur.Right(speed);
        delay(500);
        moteur.Stop();
        break;

        case 16726215:
        moteur.Stop();
        break;

        case 16724175:
        moteur.DiagonalUpLeft(speed);
        delay(500);
        moteur.Stop();
        break;

        case 16743045:
        moteur.DiagonalUpRight(speed);
        delay(500);
        moteur.Stop();
        break;

        case 16728765:
        moteur.DiagonalDownLeft(speed);
        delay(500);
        moteur.Stop();
        break;

        case 16732845:
        moteur.DiagonalDownRight(speed);
        delay(500);
        moteur.Stop();
        break;

        case 16769055:
        moteur.RotateClockwise(speed);
        delay(500);
        moteur.Stop();
        break;

        case 16748655:
        moteur.RotateCounterClockwise(speed);
        delay(500);
        moteur.Stop();
        break;
      }
    }
    else{
      switch(previousState){//is held down
        case 16718055:
        moteur.Forward(speed);
        break;

        case 16730805:
        moteur.Backward(speed);
        break;

        case 16716015:
        moteur.Left(speed);
        break;

        case 16734885:
        moteur.Right(speed);
        break;

        case 16726215:
        moteur.Stop();
        break;

        case 16724175:
        moteur.DiagonalUpLeft(speed);
        break;

        case 16743045:
        moteur.DiagonalUpRight(speed);
        break;

        case 16728765:
        moteur.DiagonalDownLeft(speed);
        break;

        case 16732845:
        moteur.DiagonalDownRight(speed);
        break;

        case 16769055:
        moteur.RotateClockwise(speed);
        break;

        case 16748655:
        moteur.RotateCounterClockwise(speed);
        break;
      }
    }
  
    irrecv.resume();
  }
}