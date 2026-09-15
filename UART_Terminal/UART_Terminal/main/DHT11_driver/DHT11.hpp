#pragma once

#include <cstdint>

class DHT{
    struct DHTdata{
        uint8_t sensor_type;
        uint8_t pin;
        float humid;
        float temperature;
    };

    DHTdata data;

    public:
    static void init(uint8_t sensor_type, uint8_t pin, float &humid, float &temperature);
    static float readTemperature();
    static float readHumidity();


};