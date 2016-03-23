#include "../../include/io.h"
#include <util/delay.h>

// Example how to 'declare' a input that can be used by the new io_ functions

// This is a button connected to the corresponding pin
#define BUTTON (DDRC,PORTC,PC5,PINC)

// This is the built-in led on an atmega2560 board
#define LED (DDRB,PORTB,PB7,PINB)

int main(){
    
    io_in(BUTTON);
    io_out(LED);
    
    while(1){
        if(io_get(BUTTON)){
            io_high(LED);
        }
        else{
            io_low(LED);
        }
    }
}
