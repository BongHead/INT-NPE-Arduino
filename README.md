# INT-NPE-Arduino
## Projet d'intégration session Hiver 2023


### **La version la plus récente est la branche testing.**

<br/>


Dépendences:
```
Servo.h             v1.1.8
ServoMoteur.h       Latest
IRremote.h          v0.11
```
<br/>

## Façons d'initialiser les pins

Normal
<br/>
Méthode classique. Rapide et braindead mais mauvaise pratique.
```
int pin = 1;
```
"Fuck man le Arduino a 2kb de ram"
```
byte pin = 1;
```
"Hmmmm je ne sais pas lire..."
```
const int pin = 1; 
const byte = 2;
```
???????????????????????
<br/>
Un macro??? Bro notre projet fait gnr 100 lignes de code
```
#define pin 1
```
Façons troll
```
bool pin = 1;
long pin = 1;
short pin = 1;
unsigned long = 1;
```
A̷̋͊P̶͕̜͂͗l̷̥̯̖̼̂ẽ̵͍̒a̴̠͖̯͌̅̓͐̕s̸̡̖̼͚̏̊ȇ̷̞̻͗͂͊ ̵̢̙̱͛͐h̵̤̝̓̋̾͋̇ẽ̶̡͎̝͎̻l̴̛̪̯͝p̶̗̣̹̞͉̒́̕̚ ̷̡̻̰͍̈́̓a̴̗̟̫̩̙̔̎́̂f̵̣͇̥͐͠g̸̣̫̈́͋́͆o̸̗͆̊̏j̵̧͙̅̓͂̒͠m̵̛̟̀͐̐q̵̠͗̇̍̆͝3̵̼͈͋j̸̩̦̠̈́k̶͕̞̺̍̈́͝d̷̯̈́̚i̵̧̨͓͓̚e̸͇̗̯̠͆ị̷̝̬͛̽r̷̳̯̟̽̍ͅͅK̸̜̹̈̎̀Ķ̷̦̳̘̈̂̀K̴̼͍̬̓̈́̃L̶̝̦̋̇̆̂͘N̸͖̯̺̎̄̌F̴̣̮͈͓̆G̸͍̘̭̀̕̚͠ͅK̶̘̥̉͘k̶̤̯͘͠k̷͍̩̻̞̈́͐͆̀ͅd̸̬̫̗͕̰̃ŝ̷̡̻̋f̶͇̣̉́̕ 
```
#include <stdlib.h>
srand(time(NULL));
int pin;
while (num != 1){
  pin = rand() % 99999999;
}
```


<br/>
Pour les servo-moteurs, utilisez la *forme* suivante:

```

void setup(){
  Serial.begin(9600);
  moteur.init(); //Connecte chaque attribut pin à son attribut servo respectif. Maintenant obligatoire.
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
    if(results.value == 0XFFFFFFFF)
    switch(results_value){
      case 0xFF18E7:
      moteur.Forward();
      break;
      //Et ainsi de suite...
    }
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

[IRremote](https://www.circuitbasics.com/arduino-ir-remote-receiver-tutorial/)


<br/>
<br/>

### **Prenez note de ces choses suivantes lors du codage:**

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
