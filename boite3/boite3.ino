// inclure la bibliothèque servo
#include <Servo.h>
// 3 - 6 - 9 - 11

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

void setup() {
  pinMode(3, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo1.attach(3); 

  pinMode(6, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo2.attach(6); 

  pinMode(9, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo3.attach(9); 
  
  pinMode(11, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo4.attach(11);  // préciser à notre bibliothèque qu'un servo est connecté à la pin 6
  
}

void loop() {
  myservo1.write(99); // mettre le servo en position de repos

  myservo2.write(83);

  myservo3.write(81);

  myservo4.write(96);

  delay(100);
 
}
