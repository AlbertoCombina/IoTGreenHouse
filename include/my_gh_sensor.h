#include "Arduino.h"
#include <DHT.h>
#include <DHT_U.h>

#define CAP_MOIST_SEN_MIN 290
#define CAP_MOIST_SEN_MAX 630

// DHT - Initial DHT logging with specs
void log_dht_temp_sens_spec(DHT_Unified &dht_sensor);
void log_dht_hum_sens_spec (DHT_Unified &dht_sensor);
// DHT - Read temp and relative hum, logging the value is requested
float read_dht_temp(DHT_Unified &dht_sensor, boolean is_log_en=true);
float read_dht_hum (DHT_Unified &dht_sensor, boolean is_log_en=true);

// Capacitive moisture sensor - Read analog value and return %
float read_cms_soil_hum(const int & analog_pin, boolean is_log_en=true);