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