#include <cstdio>
#include <string>
#include "driver/uart.h"
#include "GPIO_driver/GPIO.hpp"
#include "esp_log.h"

#define ledPIN  25
#define DHT11_PIN  26
#define DHTTYPE  DHT11
#define servoPIN  27

#define BUF_SIZE 1024

std::string readFromUART(uint8_t rx_buffer[BUF_SIZE], int &rx_index) {
        uint8_t byte;
        int len = uart_read_bytes(UART_NUM_0, &byte, 1, pdMS_TO_TICKS(20));

        std::string receivedString = "";
        if (len > 0) {
            if (byte == '\n' || byte == '\r') {
                if (rx_index > 0) {
                    rx_buffer[rx_index] = '\0';
                    receivedString = std::string((char*)rx_buffer);
                    rx_index = 0;
                }
            } else if (rx_index < BUF_SIZE - 1) {
                rx_buffer[rx_index++] = byte;
            }
        }
        return receivedString;
}

void UART_Init() {
    uart_config_t uart_config = {};
    uart_config.baud_rate = 115200;
    uart_config.data_bits = UART_DATA_8_BITS;
    uart_config.parity    = UART_PARITY_DISABLE;
    uart_config.stop_bits = UART_STOP_BITS_1;
    uart_config.flow_ctrl = UART_HW_FLOWCTRL_DISABLE;
    uart_config.source_clk = UART_SCLK_DEFAULT;

    ESP_ERROR_CHECK(uart_param_config(UART_NUM_0, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(UART_NUM_0, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
    ESP_ERROR_CHECK(uart_driver_install(UART_NUM_0, BUF_SIZE * 2, 0, 0, NULL, 0));
}


extern "C" void app_main(void) {
    UART_Init();

    uint8_t rx_buffer[BUF_SIZE];
    int rx_index = 0;

    while (1) {
        std::string receivedString = readFromUART(rx_buffer, rx_index);
        if (!receivedString.empty()) {
            printf("Received string: %s\n", receivedString.c_str());
        }
    }
}
