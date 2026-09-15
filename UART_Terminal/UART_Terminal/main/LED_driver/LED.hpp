#pragma once

#include <stdint.h>
#include "GPIO.hpp"

class LED{
    public:
    static void LED_on(uint8_t pin);
    static void LED_off(uint8_t pin);
};