#include "uart/pl011.h"
#include "gpio/gpio.h"

void main(void)
{
    uart_init();

    gpio_init();
    
    gpio_write(SCL_PIN, 0);
    gpio_write(SDA_PIN, 0);

    gpio_read(SCL_PIN);
    gpio_read(SDA_PIN);

    print_uint32(gpio_read(SCL_PIN));
    print_uint32(gpio_read(SDA_PIN));

    __asm__ volatile ("hlt");
}