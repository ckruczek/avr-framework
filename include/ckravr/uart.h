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

#include "../../config.h"

#if (M32U4 == 1)

#define UBRRH UBRR1H
#define UBRRL UBRR1L
#define UCSRB UCSR1B
#define UCSRC UCSR1C
#define TXEN  TXEN1
#define RXEN  RXEN1
#define RXCIE RXCIE1
#define USBS  USBS1
#define UDR   UDR1
#define UCSRA UCSR1A
#define UDRE  UDRE1
#define RXC   RXC1
#define UCSZ  UCSZ11

#endif

#if (M2560 == 1)

#define UBRRH UBRR0H
#define UBRRL UBRR0L
#define UCSRB UCSR0B
#define UCSRC UCSR0C
#define TXEN  TXEN0
#define RXEN  RXEN0
#define RXCIE RXCIE0
#define USBS  USBS0
#define UDR   UDR0
#define UCSRA UCSR0A
#define UDRE  UDRE0
#define RXC   RXC0
#define UCSZ  UCSZ11

#endif

#if (M328P == 1)

#define UBRRH UBRR0H
#define UBRRL UBRR0L
#define UCSRB UCSR0B
#define UCSRC UCSR0C
#define TXEN  TXEN0
#define RXEN  RXEN0
#define RXCIE RXCIE0
#define USBS  USBS0
#define UDR   UDR0
#define UCSRA UCSR0A
#define UDRE  UDRE0
#define RXC   RXC0
#define UCSZ  UCSZ01

#endif

#define UART_MAX_BUFFER_SIZE     100


typedef void(*uart_callback)(char *buffer);

void uart_init(uint32_t baudrate,uart_callback callback);
int uart_putc(char c,FILE *stream);
void uart_puts(char *s);
int uart_recieve(FILE *stream);

#endif /* UART_H */

