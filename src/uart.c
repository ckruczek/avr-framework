#include "uart.h"

FILE uart_output = FDEV_SETUP_STREAM(uart_putc, NULL, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_recieve, _FDEV_SETUP_READ);

static uint8_t data_count = 0;
static char uart_data[UART_MAX_BUFFER_SIZE];
static uart_callback callback;

void uart_init(uint32_t baudrate, uart_callback world_callback) {

    uint16_t UBRR_val = (F_CPU / 16) / (baudrate - 1);

    UBRR0H = UBRR_val >> 8;
    UBRR0L = UBRR_val;

    // enable transmitting and reading
    UCSR0B |= (1 << TXEN0) | (1 << RXEN0) | (1 << RXCIE0);
    UCSR0C |= (1 << USBS0) | (3 << UCSZ00); //Modus Asynchron 8N1 (8 Datenbits, No Parity, 1 Stopbit)

    stdout = &uart_output;
    stdin = &uart_input;

    callback = world_callback;
}

ISR(USART0_RX_vect) {
    char c = UDR0;
    
    if (!((c == '\n') || (c == '\r'))) {
        uart_data[data_count++] = c;
    }
    else{
        data_count = 0;
        callback(uart_data);
    }
}

int uart_putc(char c, FILE *stream) {

    while (!(UCSR0A & (1 << UDRE0))); // wait until sending is possible
    UDR0 = c; // output character saved in c
    return 0;
}

void uart_puts(char *s) {
    while (*s) {
        uart_putc(*s, stdout);
        s++;
    }
    uart_putc('\n', stdout);
}

int uart_recieve(FILE *stream) {
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}
