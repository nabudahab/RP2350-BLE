#include <stdio.h>
#include "pico/stdlib.h"

//Initialize UART for pmodBLE
void uart_init_ble() {
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);

    uart_init(uart0, 115200);
    uart_set_format(uart0, 8, 1, UART_PARITY_NONE);
    uart_set_fifo_enabled(uart0, true);
}


//Send byte over UART
void uart_send_byte(char c) {
    // Wait until UART TX FIFO has space
    while (!uart_is_writable(uart0)) {
        tight_loop_contents();   // optional, just prevents optimizer issues
    }

    uart_putc_raw(uart0, c);
}

//Send string over UART
void uart_send_string(const char *s) {
    while (*s) {
        uart_send_byte(*s++);
    }
}

//Get char from UART
int uart_getchar_blocking() {
    return uart_getc(uart0);
}

//Read line from UART
int uart_readline(char *buf, int max) {
    int i = 0;
    while (i < max - 1) {
        char c = uart_getc(uart0);
        buf[i++] = c;
        if (c == '\n') break;
    }
    buf[i] = 0;
    return i;
}
