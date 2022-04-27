

import processing.serial.*;
Serial myPort;  

Path p1;
Path p2;
Path p3;
Path p4;

void setup() {
 // size(800, 800);
 fullScreen();

  printArray(Serial.list());
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');

  p1 = new Path(width*0.1, height/2, 0.5, color(50, 50, 255));
  p2 = new Path(width*0.35, height/2, 0.7, color(255, 20, 20));
  p3 = new Path(width*0.60, height/2, 0.9, color(255, 180, 0));
  p4 = new Path(width*0.85, height/2, 0.3, color(0, 0, 0));
}


void draw() {
  background(255, 255, 240);

  p1.update();
  p1.draw();

  p2.update();
  p2.draw();

  p3.update();
  p3.draw();

  p4.update();
  p4.draw();
}


void serialEvent (Serial myPort) {
  try {
    while (myPort.available() > 0) {
      String inBuffer = myPort.readStringUntil('\n');
      if (inBuffer != null) {
        if (inBuffer.substring(0, 1).equals("{")) {
          JSONObject json = parseJSONObject(inBuffer);
          if (json == null) {
            //println("JSONObject could not be parsed");
          } else {
            //if (abs(json.getInt("distance")-valueFromArduino)> 50) {
            float v1    = constrain(json.getInt("d1"), 0, 150);
            float v2    = constrain(json.getInt("d2"), 0, 150);
            float v3    = constrain(json.getInt("d3"), 0, 150);
            float v4    = constrain(json.getInt("d4"), 0, 150);

            p1.speed = map(v1, 0, 150, 0.1, 4) ;
            p2.speed = map(v2, 0, 150, 0.1, 4) ;
            p3.speed = map(v3, 0, 150, 0.1, 4) ;
            p4.speed = map(v4, 0, 150, 0.1, 4) ;

            //movieSpeed = map(valueFromArduino, 50, 650, 2, 0);
            //movieSpeed = constrain(movieSpeed, 0, 2);
            // }
          }
        } else {
        }
      }
    }
  } 
  catch (Exception e) {
  }
}


class Path {

  float x = 0;
  float y = 0;
  float speed = 0.5;
  float w = 20;
  color c;

  Path(float x, float y, float speed, color c) {
    this.x = x;
    this.y = y;
    this.w = 50;
    this.speed = speed;
    this.c = c;
  }

  void update() {
    
    float mf = map(this.y, -this.w/2, height + this.w,0, PI);
    this.y -= speed * (abs(cos(mf))+1);
    
    println(this.y);
    if (this.y < /*height*0.25*/ - this.w/2) {
      this.y = height + this.w/2 ;
    }
  }

  void draw() {
    pushMatrix();
    noStroke();
    fill(this.c);
    rectMode(CENTER);
    translate(this.x, height/2);
    rect(-this.w, 0, this.w/1.25, height*0.35, 5);
    rect(this.w, 0, this.w/1.25, height*0.35, 5);
    ellipse(0, this.y- height/2, this.w/1.5, this.w/1.5);
    popMatrix();
  }
}
