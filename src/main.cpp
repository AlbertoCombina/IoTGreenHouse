#include "Arduino.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "myDHTSensor.h"
#include "randomMatrix.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor 
// Uncomment the type of sensor in use:
//#define DHTTYPE    DHT11     // DHT 11
#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT_Unified dht(DHTPIN, DHTTYPE);

// Arduino Matrix
ArduinoLEDMatrix matrix;

// Delay in MS
uint32_t delayMS;

void setup() {
  Serial.begin(9600);
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
  randomMatrix(matrix);

  // Read sensor
  readDhtTemp(dht);
  readDhtHum(dht);
}