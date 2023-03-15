# INT-NPE-Arduino
## Projet d'intégration session Hiver 2023


### **La version la plus récente est la branche testing.**

<br/>
<br/>
<br/>

Pour les servo-moteurs, utilisez la *forme* suivante (pour tester):
```
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
  moteur.init(); //Connecte chaque attribut pin à son attribut servo respectif. Maintenant obligatoire.
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
    if(results.value == 0XFFFFFFFF)
      results.value = key_value;
    switch(results_value){
      case 0xFF18E7:
      moteur.Forward();
      break;
      //Et ainsi de suite...
    }
    key_value = results.value;
    irrecv.resume();
  }
}
```

~~Allez donc apprendre comment utiliser GitHub, bande d'analphabètes.~~

[Tutoriel](https://docs.github.com/en/get-started)

Allez tout lire. Please. Avant de me DM sur comment utiliser GitHub.

Pour ce projet, clonez tout d'abord ce repository:

![Étape 1:](https://github.com/BongHead/INT-NPE-Arduino/blob/main/Images%20readme/0.PNG?raw=true)
Allez dans VSC:

![Étape 2:](https://github.com/BongHead/INT-NPE-Arduino/blob/main/Images%20readme/1.PNG?raw=true)

Pastez le lien du repo ici:

![3:](https://github.com/BongHead/INT-NPE-Arduino/blob/main/Images%20readme/2.PNG?raw=true)

Choisissez le folder dans votre ordi auquel vous voulez cloner le repo (peut être n'importe lequel)

Puis, ouvrez Arduino IDE.

Cliquez sur "Open":

![4:](https://github.com/BongHead/INT-NPE-Arduino/blob/main/Images%20readme/3.PNG?raw=true)

Ouvrez le fichier Main.ino:

![5:](https://github.com/BongHead/INT-NPE-Arduino/blob/main/Images%20readme/4.PNG?raw=true)

Ou si vous êtes familier avec Git:

``` git clone https://github.com/BongHead/INT-NPE-Arduino.git ```

dans le folder désiré.



<br/>
<br/>

### **Veuillez vous référer aux liens suivants pour les libraries:**

[Syntaxe](https://www.arduino.cc/reference/en/)

[Capteur ultrasons](https://www.arduino.cc/reference/en/libraries/hcsr04-ultrasonic-sensor/)

[Servo-moteur](https://docs.arduino.cc/learn/electronics/servo-motors)

[IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote)


<br/>
<br/>

### **Prenez note de ces choses suivantes lors du codage:**
Il est fortement suggéré de mettre un delay entre chaque signal électrique différent:
```
void loop(){
  ToggleLight();
  delay(10); //Donner du temps pour éviter d'avoir 2 (ou plus) signals en même temps qui peuvent bugger le truc.
  RotateEngine(25);
  delay(10);
  ToggleLight();
}
```
<br/>
Je vais probablement faire des libraries pour rendre plus facile le codage. Il suffit de mettre `#include <my_library>` au début du fichier.

Si vous voulez faire des libraries vous-mêmes, suivez la structure suivante:
```
INT-NPE-Arduino
     |_____Images Readme
     |
     |_____Main
     |
     |_____My_Library
     |          |____My_library.h
     |          |____My_library.cpp
     |
     |_____README.md
```
