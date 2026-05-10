#include "uart/pl011.h"

void main(void)
{
    uart_init();
    uart_puts("\nHello!\n");

    __asm__ volatile ("hlt");
}