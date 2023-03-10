# INT-NPE-Arduino
## Projet d'intégration session Hiver 2023

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



### **Veuillez vous référer aux liens suivants pour les libraries:**

[Syntaxe](https://www.arduino.cc/reference/en/)

[Capteur ultrasons](https://www.arduino.cc/reference/en/libraries/hcsr04-ultrasonic-sensor/)

[Servo-moteur](https://docs.arduino.cc/learn/electronics/servo-motors)

[IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote)



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
