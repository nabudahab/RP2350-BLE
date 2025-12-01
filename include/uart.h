/* uart.h - UART function prototypes for RP2350-BLE project */
#ifndef UART_H
#define UART_H

void uart_init_ble(void);
void uart_send_byte(char c);
void uart_send_string(const char *s);
int uart_getchar_blocking(void);
int uart_readline(char *buf, int max);


#endif /* UART_H */
