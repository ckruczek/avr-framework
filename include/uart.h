/* 
 * File:   uart.h
 * Author: Christopher Kruczek
 *
 * Created on December 9, 2015, 6:36 AM
 */

#ifndef UART_H
#define UART_H

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define UART_MAX_BUFFER_SIZE     100

typedef void(*uart_callback)(char *buffer);

void uart_init(uint32_t baudrate,uart_callback callback);
int uart_putc(char c,FILE *stream);
void uart_puts(char *s);
int uart_recieve(FILE *stream);

#endif /* UART_H */

