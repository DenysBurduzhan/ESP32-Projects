#include "LED.hpp"



void LED::LED_on(uint8_t pin){
    GPIO::initGPIO(pin);
    GPIO::enableOutput(pin);
    GPIO::setOutput(pin);
}
void LED::LED_off(uint8_t pin){
    GPIO::clearOutput(pin);
}