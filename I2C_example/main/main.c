#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "driver/i2c_master.h"

#define I2C_SCL_PIN 22
#define I2C_SDA_PIN 21

i2c_master_bus_handle_t bus_handle;

void i2c_init(void);

void app_main(void)
{
    i2c_init();
}

void i2c_init(void)
{
    i2c_master_bus_config_t bus_config = {
        .i2c_port = -1,
        .sda_io_num = I2C_SDA_PIN,
        .scl_io_num = I2C_SCL_PIN,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };
    ESP_ERROR_CHECK(i2c_new_master_bus(&bus_config, &bus_handle));

}
