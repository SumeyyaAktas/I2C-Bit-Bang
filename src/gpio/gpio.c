#include "gpio/gpio.h"

volatile uint32_t *dir = (volatile uint32_t *)(GPIO0_BASE + GPIO_DIR);
volatile uint32_t *data = (volatile uint32_t *)(GPIO0_BASE + GPIO_DATA);

void gpio_set_output(uint8_t pin) 
{
    uint32_t current_value = *dir;
    current_value |= (1u << pin);
    *dir = current_value;
}

void gpio_set_input(uint8_t pin)
{
    uint32_t current_value = *dir;
    current_value &= ~(1u << pin);
    *dir = current_value;
}

void gpio_write(uint8_t pin, uint8_t value)
{
    uint32_t current_value = *data;

    if (value == 1)
    {
        current_value |= (1u << pin);
    }
    else if (value == 0)
    {
        current_value &= ~(1u << pin);
    }

    *data = current_value;
}

uint8_t gpio_read(uint8_t pin)
{
    uint32_t current_value = *data; 
    uint8_t result = (current_value >> pin) & 1u;
    return result;
}

void gpio_init(void)
{
    gpio_set_output(SCL_PIN);
    gpio_set_output(SDA_PIN);
    gpio_write(SCL_PIN, 1);
    gpio_write(SDA_PIN, 1);
}