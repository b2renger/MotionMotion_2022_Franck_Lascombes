// inclure la bibliothèque servo
#include <Servo.h>
// 3 - 6 - 9 -

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
Servo myservo1;
Servo myservo2;
Servo myservo3;


void setup() {
  pinMode(3, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo1.attach(3); 

  pinMode(6, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo2.attach(6); 

  pinMode(9, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo3.attach(9); 
  

}

void loop() {
  myservo1.write(99); // mettre le servo en position de repos

  myservo2.write(102);

  myservo3.write(82);

  delay(100);
 
}
