#include <Arduino.h>
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void randomMatrix();

void setup() {
  matrix.begin();
  Serial.begin(9600);
}

void loop() {

  randomMatrix();
  delay(1000);
}


void randomMatrix(){
  uint32_t frame[] = {random(0, UINT32_MAX/2), random(0, UINT32_MAX/2), random(0, UINT32_MAX/2)};
  matrix.loadFrame(frame);
}