#include "Arduino.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "myDHTSensor.h"
#include "Arduino_LED_Matrix.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor 
// Uncomment the type of sensor in use:
//#define DHTTYPE    DHT11     // DHT 11
#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT_Unified dht(DHTPIN, DHTTYPE);

// Arduino Matrix
ArduinoLEDMatrix matrix;
void randomMatrix(){
  uint32_t frame[] = {random(0, UINT32_MAX/2), random(0, UINT32_MAX/2), random(0, UINT32_MAX/2)};
  matrix.loadFrame(frame);
} 

// Delay in MS
uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  matrix.begin();
  // Initialize device.
  dht.begin();
  logDhtTempSpec(dht);
  logDhtHumSpec(dht);
  delayMS = 1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);

  // Random Matrix animation
  randomMatrix();

  // Read sensor
  readDhtTemp(dht);
  readDhtHum(dht);
}

