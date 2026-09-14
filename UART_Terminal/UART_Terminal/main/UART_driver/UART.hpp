#pragma once

#include <stdint.h>
#include <string>
#include "driver/uart.h"
#include <array>
 

class UART{
    
    public:
    static std::string readFromUART(uint8_t *rx_buffer, int &rx_index, uint16_t BUF_SIZE);
    static void UART_Init(uint16_t BUF_SIZE);
};