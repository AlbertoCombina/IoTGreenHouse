#include "Arduino.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "my_gh_sensor.h"
#include "Arduino_LED_Matrix.h"


// ENABLE Macros - 0 = DISABLED, 1 = ENABLED
#define ENABLE_DHT_SEN       0 
#define ENABLE_CAP_MOIST_SEN 1 

// DHT Sensor (Air temperature and humidity)
#define DHT_SEN_PIN  2     // Digital pin connected to the DHT sensor 
#define DHT_TYPE DHT22     // Possible values: DHT 11, DHT 22 (AM2302), DHT 21 (AM2301)
DHT_Unified dht(DHT_SEN_PIN, DHT_TYPE);

// Capacitive moisture sensor
#define CAP_MOIST_SEN_PIN 0 // Analog pin (290/630)

// Arduino Led Matrix
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

  if(ENABLE_DHT_SEN){
    // Initialize DHT sensor.
    dht.begin();
    log_dht_temp_sens_spec(dht);
    log_dht_hum_sens_spec(dht);
  }
  
  delayMS = 1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);

  // Random Matrix animation
  randomMatrix();

  // Read DHT sensor temp and humidity
  if(ENABLE_DHT_SEN){
    read_dht_temp(dht);
    read_dht_hum(dht);
  }

  // Read Capacitive moisture sensor
  if(ENABLE_CAP_MOIST_SEN){
    read_cms_soil_hum(CAP_MOIST_SEN_PIN);
  }
  
}

