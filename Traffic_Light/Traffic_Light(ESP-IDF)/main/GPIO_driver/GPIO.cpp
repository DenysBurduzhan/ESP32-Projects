#include "GPIO.hpp"
#include "soc/gpio_reg.h"
#include "soc/io_mux_reg.h"
#include "driver/gpio.h"

bool GPIO::initGPIO(uint8_t pin){
    switch (pin){
        case 12:
            PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, FUNC_MTDI_GPIO12);
            break;
        case 13:
            PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, FUNC_MTCK_GPIO13);
            break;
        case 14:
            PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTMS_U, FUNC_MTMS_GPIO14);
            break;
        default: return false;
    }
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

void GPIO::setInput(uint8_t pin) {
   volatile uint32_t* gpio_enable_reg = (volatile uint32_t*)GPIO_ENABLE_REG;
   *gpio_enable_reg &= ~(1UL << pin);
}

void GPIO::pullUp(volatile uint32_t* reg) {
   // volatile uint32_t* pull_up = (volatile uint32_t*)IO_MUX_GPIO0_REG; //Example
    *reg |= (1UL << 8);
}

uint32_t GPIO::readInput(uint8_t pin) {
    volatile uint32_t* gpio_in_reg = (volatile uint32_t*)GPIO_IN_REG;
    return (*gpio_in_reg >> pin) & 0x01;
}