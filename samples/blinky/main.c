#include "../../include/io.h"
#include <util/delay.h>

// Example how to 'declare' a output that can be used by the new io_ functions
// This is the built-in led on an atmega2560 board
#define LED (DDRB,PORTB,PB7,PINB)

int main(){
    
    io_out(LED);
    
    while(1){
        
        io_high(LED);
        _delay_ms(1000);
        io_low(LED);
        _delay_ms(1000);
    }
}