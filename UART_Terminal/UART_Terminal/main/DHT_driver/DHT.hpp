#pragma once

#include <cstdint>
#include "dht.h"
class DHT{

    public:
    struct DHTdata{
        float humidity;
        float temperature;
    };

    static DHTdata readTemperatureAndHumidity(dht_sensor_type_t sensor_type, gpio_num_t pin);
};