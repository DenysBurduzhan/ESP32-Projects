#pragma once

#include <stdint.h>

class GPIO {
public:
    static bool initGPIO(uint8_t pin);
    static void enableOutput(uint8_t pin);
    static void setOutput(uint8_t pin);
    static void clearOutput(uint8_t pin);
    static void enableInput(uint8_t pin);
    static void pullUp(volatile uint32_t* reg);
    static uint32_t readInput(uint8_t pin);
};