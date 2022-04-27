#include "Ultrasonic.h" // importer la bibliothèque
Ultrasonic ultrasonic1(2); // la broche "sig" du capteur est branchée sur "D2" de l'arduino
Ultrasonic ultrasonic2(3); // la broche "sig" du capteur est branchée sur "D2" de l'arduino
Ultrasonic ultrasonic3(4); // la broche "sig" du capteur est branchée sur "D2" de l'arduino
Ultrasonic ultrasonic4(5); // la broche "sig" du capteur est branchée sur "D2" de l'arduino

void setup() {
  Serial.begin(9600);
}

void loop() {
  long v1 = ultrasonic1.MeasureInCentimeters(); // mesurer la distance en cm
  long v2 = ultrasonic2.MeasureInCentimeters();
  long v3 = ultrasonic3.MeasureInCentimeters();
  long v4 = ultrasonic4.MeasureInCentimeters();


   // construire une chaine de caractère par concatenation
  String json;
  json = "{\"d1\":"; // on ajoute la première clé "photor1"
  json = json + v1; // on ajoute la première valeur  
  json = json +";\"d2\":"; // on ajoute la seconde clé "photor2"
  json = json +  v2;// on ajoute la seconde valeur  
  json = json +";\"d3\":"; // on ajoute la seconde clé "photor2"
  json = json +  v3;// on ajoute la seconde valeur  
  json = json +";\"d4\":"; // on ajoute la seconde clé "photor2"
  json = json +  v4;// on ajoute la seconde valeur  
  json = json + "}";

  Serial.println(json);
  
  delay(5); // attendre un peu entre deux mesures.
}
