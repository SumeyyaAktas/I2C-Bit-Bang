#include "i2c/i2c.h"
#include "gpio/gpio.h"

static void i2c_delay(void)
{
    for (volatile int i = 0; i < 100; i++);
}

void i2c_init(void)
{
    gpio_init();
}

void i2c_start(void)
{
    gpio_write(SDA_PIN, 1);
    gpio_write(SCL_PIN, 1);
    i2c_delay();

    gpio_write(SDA_PIN, 0);
    i2c_delay();

    gpio_write(SCL_PIN, 0);
    i2c_delay();
}