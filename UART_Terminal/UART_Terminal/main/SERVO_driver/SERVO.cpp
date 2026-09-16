#include "SERVO.hpp"

bool SERVO::init(gpio_num_t pin){
    servo_config_t config = SERVO_CONFIG_DEFAULT(
            LEDC_LOW_SPEED_MODE,
            LEDC_TIMER_0,
            LEDC_CHANNEL_0,
            pin
        );

    esp_err_t result = iot_servo_new(&config, &servo);

    return result == ESP_OK;
}


bool SERVO::setAngle(float angle){
    if (servo == nullptr)
        return false;

    if (angle < 0)
        angle = 0;

    if (angle > 180)
        angle = 180;

    esp_err_t result = iot_servo_write_angle(servo, angle);

    return result == ESP_OK;
}


bool SERVO::getAngle(float& angle){
    if (servo == nullptr)
        return false;

    esp_err_t result = iot_servo_read_angle(servo, &angle);

    return result == ESP_OK;
}


void SERVO::deinit(){
    if (servo != nullptr)
    {
        iot_servo_del(servo);
        servo = nullptr;
    }
}
