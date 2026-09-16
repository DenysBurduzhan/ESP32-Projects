#include "DHT.hpp"

//wrapper. I am going to improve this with registers
DHT::DHTdata DHT::readTemperatureAndHumidity(dht_sensor_type_t sensor_type, gpio_num_t pin){
    DHTdata data;
    dht_read_float_data(sensor_type, pin, &data.humidity, &data.temperature);
    return data;
};
