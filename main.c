#include "uart/pl011.h"
#include "gpio/gpio.h"
#include "i2c/i2c.h"

typedef struct
{
    uint8_t registers[16];
    uint8_t address;
} SoftSlave;

static SoftSlave slave = { .address = 0x42 };

void slave_write(SoftSlave *s, uint8_t reg, uint8_t value)
{
    s->registers[reg] = value;
}

uint8_t slave_read(SoftSlave *s, uint8_t reg)
{
    return s->registers[reg];
}

void main(void)
{
    uart_init();
    uart_puts("\nI2C Bit-Bang Test\n");

    i2c_init();

    i2c_start();
    i2c_write_byte(slave.address << 1 | 0); 
    i2c_write_byte(0x05);                   
    i2c_write_byte(0xAB);                   
    i2c_stop();

    slave_write(&slave, 0x05, 0xAB);

    uart_puts("Write: reg 0x05 = 0xAB\n");

    i2c_start();
    i2c_write_byte(slave.address << 1 | 0); 
    i2c_write_byte(0x05);                   

    i2c_start();
    i2c_write_byte(slave.address << 1 | 1); 

    uint8_t val = slave_read(&slave, 0x05);
    
    i2c_stop();

    uint8_t expected = slave_read(&slave, 0x05);

    uart_puts("Read: reg 0x05 = 0x");
    print_uint32(val);                        
    uart_puts("\n");

    if (val == expected)
    {
        uart_puts("I2C Success: read back matched 0xAB\n");
    }
    else
    {
        uart_puts("I2C Fail: mismatch\n");
    }

    // uart_puts("\nGPIO Pin State Test\n");
    // gpio_init();
    
    // gpio_write(SCL_PIN, 0);
    // gpio_write(SDA_PIN, 0);

    // gpio_read(SCL_PIN);
    // gpio_read(SDA_PIN);

    // print_uint32(gpio_read(SCL_PIN));
    // print_uint32(gpio_read(SDA_PIN));

    __asm__ volatile ("hlt");
}