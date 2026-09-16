#include <cstdio>
#include "GPIO_driver/GPIO.hpp"
#include "UART_driver/UART.hpp"
#include "LED_driver/LED.hpp"
#include "DHT_driver/DHT.hpp"

#define ledPIN  25
#define DHT11_PIN  26
#define DHTTYPE  DHT_TYPE_DHT11
#define servoPIN  27
#define BUF_SIZE 1024

extern "C" void app_main(void) {
    UART::UART_Init(BUF_SIZE);

    uint8_t rx_buffer[BUF_SIZE];
    int rx_index = 0;
    DHT::DHTdata data;

    while (1) {
        std::string receivedString = UART::readFromUART(rx_buffer, rx_index, BUF_SIZE);
        if (!receivedString.empty()) {
            printf("Received string: %s\n", receivedString.c_str());
        }
        vTaskDelay(pdMS_TO_TICKS(10));

        if(receivedString == "led on"){
            LED::LED_on(ledPIN);
        }else if(receivedString == "led off"){
            LED::LED_off(ledPIN);
        }else if(receivedString == "read temperature"){
               data = DHT::readTemperatureAndHumidity(
                  DHTTYPE, static_cast<gpio_num_t>(DHT11_PIN));
              printf("Received temperature: %.1f C\n", data.temperature);
        }
    }
}
