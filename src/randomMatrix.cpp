#include "randomMatrix.h"

void randomMatrix(ArduinoLEDMatrix matrix){
  uint32_t frame[] = {random(0, UINT32_MAX/2), random(0, UINT32_MAX/2), random(0, UINT32_MAX/2)};
  matrix.loadFrame(frame);
}