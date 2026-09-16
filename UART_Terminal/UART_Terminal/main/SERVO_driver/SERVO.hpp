#include "iot_servo.h"

class SERVO{
    public:
    bool init(gpio_num_t pin);
    bool setAngle(float angle);
    bool getAngle(float& angle);
    void deinit();

    private:
    servo_handle_t servo = nullptr;
};