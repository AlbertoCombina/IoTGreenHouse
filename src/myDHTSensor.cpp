#include "myDHTSensor.h"


void logDhtTempSpec(DHT_Unified dht_sensor){
    sensor_t sensor;
    dht_sensor.temperature().getSensor(&sensor);
    // Print temperature sensor details.
    Serial.println(F("------------------------------------"));
    Serial.println(F("Temperature Sensor"));
    Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
    Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
    Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
    Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
    Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
    Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
    Serial.println(F("------------------------------------"));
}

void logDhtHumSpec(DHT_Unified dht_sensor){
    sensor_t sensor;
    dht_sensor.humidity().getSensor(&sensor);
    // Print humidity sensor details.
    Serial.println(F("------------------------------------"));
    Serial.println(F("Humidity Sensor"));
    Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
    Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
    Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
    Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
    Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
    Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
    Serial.println(F("------------------------------------"));
}

float readDhtTemp(DHT_Unified dht_sensor, boolean is_log_en){
    // Get temperature event and print its value.
    sensors_event_t event;
    dht_sensor.temperature().getEvent(&event);
    if (isnan(event.temperature)) {
        Serial.println(F("Error reading temperature!"));
    }
    else if (is_log_en){
        Serial.print(F("Temperature --> "));
        Serial.print(event.temperature);
        Serial.println(F("°C"));
    }

    return event.temperature;
}

float readDhtHum (DHT_Unified dht_sensor, boolean is_log_en){
    // Get temperature event and print its value.
    sensors_event_t event;
    // Get humidity event and print its value.
    dht_sensor.humidity().getEvent(&event);
    if (isnan(event.relative_humidity)) {
        Serial.println(F("Error reading humidity!"));
    }
    else if (is_log_en){
        Serial.print(F("Humidity    --> "));
        Serial.print(event.relative_humidity);
        Serial.println(F("%"));
    }

    return event.relative_humidity;
}