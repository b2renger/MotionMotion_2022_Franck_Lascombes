// inclure la bibliothèque servo
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include <SimplexNoise.h>

#define NUMPIXELS 42
// 3

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
Servo myservo1;
Adafruit_NeoPixel pixels(NUMPIXELS, 6, NEO_GRB + NEO_KHZ800);

SimplexNoise sn;
double nx;
double x = 0.0;

double ny;
double y = 0.0;


void setup() {
  pinMode(3, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo1.attach(3);

  pixels.begin();


  // obtenir des valeurs aléatoires au lancement du programme
  x = analogRead(0) / 10.;
  y = analogRead(2) / 10.;


}

void loop() {
  myservo1.write(92.5); // mettre le servo en position de repos
  x += 0.005;
  y += 0.001;

  long t = millis()% 5000;
  int index = map(t, 0, 5000, NUMPIXELS, 0);


  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

    // on calcule une valeur de noise (comprise entre 0 et 1)
    //nx = sn.noise(x, i*.5);
    // on fait de même avec notre seconde valeur.
    //ny = sn.noise(y, i * 2);

    //float mult = map(nx * 100, -100, 100, 5, 150) ;

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    
    if (i > (index-5) && i <= index ) {
      pixels.setPixelColor(i, pixels.Color(255,255,100));
    }
    else {
     pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
    // pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV (55, 50, mult)));
  }

  pixels.show();

  delay(5);

}
