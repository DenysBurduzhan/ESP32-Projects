#include <cstdio>
#include "GPIO_driver/GPIO.hpp"
#include "UART_driver/UART.hpp"

#define ledPIN  25
#define DHT11_PIN  26
#define DHTTYPE  DHT11
#define servoPIN  27
#define BUF_SIZE 1024


extern "C" void app_main(void) {
    UART::UART_Init(BUF_SIZE);

    uint8_t rx_buffer[BUF_SIZE];
    int rx_index = 0;

    while (1) {
        std::string receivedString = UART::readFromUART(rx_buffer, rx_index, BUF_SIZE);
        if (!receivedString.empty()) {
            printf("Received string: %s\n", receivedString.c_str());
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
