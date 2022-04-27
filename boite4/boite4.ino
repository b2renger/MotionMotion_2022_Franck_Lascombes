// inclure la bibliothèque servo
#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 30
// 3 

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
Servo myservo1;
Adafruit_NeoPixel pixels(NUMPIXELS, 6, NEO_GRB + NEO_KHZ800);


void setup() {
  pinMode(3, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo1.attach(3); 

   pixels.begin();
 

}

void loop() {
  myservo1.write(92); // mettre le servo en position de repos


   for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(180, 180, 180));
   }

    pixels.show(); 
 
  //delay(100);
 
}
