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

void setup(){
  Serial.begin(9600);
  moteur.init(); //Connecte chaque attribut pin à son attribut servo respectif. Maintenant obligatoire.
  IrReceiver.begin(IRpin, ENABLE_LED_FEEDBACK);
}

void loop(){
    if(IrReceiver.decode()){
        bool isHeldDown = IrReceiver.decodedIRData.decodedRawData == 0;
        int currentState = IrReceiver.decodedIRData.decodedRawData;
        Serial.println(IrReceiver.decodedIRData.decodedRawData);
        IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
        IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
        switch(currentState{
            case 3860463360:
            moteur.Forward();
            break;
            //Et ainsi de suite...
        })
        IrReceiver.resume();
    
  }
}
