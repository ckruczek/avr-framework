#include "uart.h"

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


#endif


FILE uart_output = FDEV_SETUP_STREAM(uart_putc, NULL, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_recieve, _FDEV_SETUP_READ);

static uint8_t data_count = 0;
static char uart_data[UART_MAX_BUFFER_SIZE];
static uart_callback callback;

/**
 * This function initialize the uart device with the given baudrate and a callback for 'world' interaction.
 * @param baudrate - The baudrate used for transmission
 * @param world_callback - A callback that is triggered everytime a transmission succeded
 */
void uart_init(uint32_t baudrate, uart_callback world_callback) {

    uint16_t UBRR_val = (F_CPU / 16) / (baudrate - 1);

    UBRRH = UBRR_val >> 8;
    UBRRL = UBRR_val;

    // enable transmitting and reading
    UCSRB |= (1 << TXEN) | (1 << RXEN) | (1 << RXCIE);
    UCSRC |= (1 << USBS) | (3 << UCSZ11); //Modus Asynchron 8N1 (8 Datenbits, No Parity, 1 Stopbit)

    stdout = &uart_output;
    stdin = &uart_input;

    callback = world_callback;
}
#if (M2560 == 1)
ISR(USART0_RX_vect) {
    char c = UDR;
    
    if (!((c == '\n') || (c == '\r'))) {
        uart_data[data_count++] = c;
    }
    else{
        data_count = 0;
        callback(uart_data);
    }
}
#endif
/**
 * This functions sends one character to the uart 
 * @param c - The character to send
 * @param stream - A stream used for stdout redirection
 * @return 
 */
int uart_putc(char c, FILE *stream) {

    while (!(UCSRA & (1 << UDRE))); // wait until sending is possible
    UDR = c; // output character saved in c
    return 0;
}

/**
 * This function sends a complete string to the uart.
 * @param s - The string to send.
 */
void uart_puts(char *s) {
    while (*s) {
        uart_putc(*s, stdout);
        s++;
    }
    uart_putc('\n', stdout);
}

/**
 * This function is used to recieve from the uart and returns the recieved byte.
 * @param stream - A stream used for stdin redirection.
 * @return - The recieved byte.
 */
int uart_recieve(FILE *stream) {
    while (!(UCSRA & (1 << RXC)));
    return UDR;
}
