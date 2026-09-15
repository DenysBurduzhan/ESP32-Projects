#include "GPIO.hpp"
#include "soc/gpio_reg.h"
#include "soc/io_mux_reg.h"

bool GPIO::initGPIO(uint8_t pin){
    volatile uint32_t* io_mux_reg = nullptr;

    switch (pin){
        case 12: io_mux_reg = (volatile uint32_t*)IO_MUX_GPIO12_REG; break;
        case 13: io_mux_reg = (volatile uint32_t*)IO_MUX_GPIO13_REG; break;
        case 14: io_mux_reg = (volatile uint32_t*)IO_MUX_GPIO14_REG; break;
        default: return false;
    }
    *io_mux_reg &= ~(0b111UL << 12);
    *io_mux_reg |=  (0b010UL << 12);

    return true;
}
void GPIO::enableOutput(uint8_t pin) {
    volatile uint32_t* gpio_enable_reg = (volatile uint32_t*)GPIO_ENABLE_REG;
    *gpio_enable_reg |= (1UL << pin);
}

void GPIO::setOutput(uint8_t pin) {
    volatile uint32_t* gpio_out_w1ts_reg = (volatile uint32_t*)GPIO_OUT_W1TS_REG;
    *gpio_out_w1ts_reg = (1UL << pin);
}

void GPIO::clearOutput(uint8_t pin) {
    volatile uint32_t* gpio_out_w1tc_reg = (volatile uint32_t*)GPIO_OUT_W1TC_REG;
    *gpio_out_w1tc_reg = (1UL << pin);
}

void GPIO::enableInput(uint8_t pin) {
   volatile uint32_t* gpio_enable_reg = (volatile uint32_t*)GPIO_ENABLE_REG;
   *gpio_enable_reg &= ~(1UL << pin);
}

void GPIO::pullUp(volatile uint32_t* reg) {
    *reg |= (1UL << 8);
}

uint32_t GPIO::readInput(uint8_t pin) {
    volatile uint32_t* gpio_in_reg = (volatile uint32_t*)GPIO_IN_REG;
    return (*gpio_in_reg >> pin) & 0x01;
}
