idf_component_register(SRCS "main.cpp" "GPIO_driver/GPIO.cpp" "UART_driver/UART.cpp" "LED_driver/LED.cpp" "DHT_driver/DHT.cpp" "SERVO_driver/SERVO.cpp"
                    INCLUDE_DIRS "." "GPIO_driver" "UART_driver" "LED_driver" "DHT_driver" "SERVO_driver"
                    )