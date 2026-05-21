#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define GPIO0_BASE 0x101E4000U
#define GPIO_DATA 0x3FC        
#define GPIO_DIR 0x400        
#define SCL_PIN 0           
#define SDA_PIN 1           

void gpio_init(void);
void gpio_set_output(uint8_t pin);
void gpio_set_input(uint8_t pin);
void gpio_write(uint8_t pin, uint8_t value);
uint8_t gpio_read(uint8_t pin);

#endif