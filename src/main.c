
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/dma.h"
#include "uart.h"

int main() {
    stdio_init_all();
    uart_init_ble();

    uart_send_string("UART initialized.\n");

    while (true) {
        char buf[100];
        int len = uart_readline(buf, sizeof(buf));
        if (len > 0) {
            uart_send_string("Received: ");
            uart_send_string(buf);
        }
    }

    return 0;
}