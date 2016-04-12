#include <avr/io.h>
#include <util/delay.h>

#include "ckravr/uart.h"
#include "ckravr/adc.h"

int main(){
    uart_init(9600,NULL);
    adc_init(); 
    adc_select_input(0);
    
    while(1){
        _delay_ms(100);
        printf("%d\n",adc_read());
        _delay_ms(100);
    }
}