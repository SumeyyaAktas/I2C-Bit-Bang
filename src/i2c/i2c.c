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

void i2c_stop(void)
{
    gpio_write(SDA_PIN, 0);
    i2c_delay();

    gpio_write(SCL_PIN, 1);
    i2c_delay();

    gpio_write(SDA_PIN, 1);
    i2c_delay();
}

static void i2c_write_bit(uint8_t bit)
{
    gpio_write(SDA_PIN, bit);
    i2c_delay();

    gpio_write(SCL_PIN, 1);
    i2c_delay();

    gpio_write(SCL_PIN, 0);
    i2c_delay();
}

static uint8_t i2c_read_bit(void)
{
    gpio_set_input(SDA_PIN);
    i2c_delay();

    gpio_write(SCL_PIN, 1);
    i2c_delay();

    uint8_t bit = gpio_read(SDA_PIN);

    gpio_write(SCL_PIN, 0);
    gpio_set_output(SDA_PIN);
    i2c_delay();

    return bit;
}
