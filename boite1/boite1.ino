float t = 0; // une variable pour stocker le temps

void setup() {
  Serial.begin(9600);

  for (int i = 3; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {

  t += 0.25; // on augmente la valeur du temps (on peut changer la valeur pour faire pulse + ou - vite)

  for (int i = 4; i < 14; i++) {

    double l = ((sin(t + i) + 1) / 2.0) * 255; // on calcule une luminosité l doit être compris entre 0 et 255
    analogWrite(i, l);
    Serial.println(l);
  }

  double l2 = (((sin(t/5) + 1) / 2.0) * 205) + 50;
  analogWrite(3, l2);


}
