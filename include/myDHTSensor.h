#include "Arduino.h"
#include <DHT.h>
#include <DHT_U.h>
// Initial logging with specs
void logDhtTempSpec(DHT_Unified dht_sensor);
void logDhtHumSpec (DHT_Unified dht_sensor);
// Read temp and relative hum, logging the value is requested
float readDhtTemp(DHT_Unified dht_sensor, boolean is_log_en=true);
float readDhtHum (DHT_Unified dht_sensor, boolean is_log_en=true);