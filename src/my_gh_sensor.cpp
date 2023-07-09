#include "my_gh_sensor.h"

void log_dht_temp_sens_spec(DHT_Unified &dht_sensor){
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

void log_dht_hum_sens_spec(DHT_Unified &dht_sensor){
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

float read_dht_temp(DHT_Unified &dht_sensor, boolean is_log_en){
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

float read_dht_hum (DHT_Unified &dht_sensor, boolean is_log_en){
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

float read_cms_soil_hum(const int & analog_pin, boolean is_log_en){
    int raw_val = analogRead(analog_pin);
    if (raw_val > CAP_MOIST_SEN_MAX)
        raw_val = CAP_MOIST_SEN_MAX;
    if (raw_val < CAP_MOIST_SEN_MIN)
        raw_val = CAP_MOIST_SEN_MIN;
    // The raw values goes in the opposite direction. CAP_MOIST_SEN_MIN -> 100% hum, CAP_MOIST_SEN_MAX -> 0% hum
    int reverted_val = -(raw_val - CAP_MOIST_SEN_MAX);
    int reverted_max = -(CAP_MOIST_SEN_MIN - CAP_MOIST_SEN_MAX);
    float perc_val = reverted_val * 100 / reverted_max;

    if(is_log_en){
        Serial.print("CMS RAW = "); Serial.print(raw_val); Serial.print(" / CMS % = "); Serial.println(perc_val);
    }
}