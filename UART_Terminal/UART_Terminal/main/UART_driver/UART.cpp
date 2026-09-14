#include "UART.hpp"

void UART::UART_Init(uint16_t BUF_SIZE) {
    uart_config_t uart_config = {};
    uart_config.baud_rate = 115200;
    uart_config.data_bits = UART_DATA_8_BITS;
    uart_config.parity    = UART_PARITY_DISABLE;
    uart_config.stop_bits = UART_STOP_BITS_1;
    uart_config.flow_ctrl = UART_HW_FLOWCTRL_DISABLE;
    uart_config.source_clk = UART_SCLK_DEFAULT;

    ESP_ERROR_CHECK(uart_param_config(UART_NUM_0, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(UART_NUM_0, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
    ESP_ERROR_CHECK(uart_driver_install(UART_NUM_0,  BUF_SIZE * 2, 0, 0, NULL, 0));
}

std::string UART::readFromUART(uint8_t *rx_buffer, int &rx_index, uint16_t BUF_SIZE) {
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
