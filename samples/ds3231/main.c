#include <avr/io.h>
#include <util/delay.h>

#include "ckravr/i2c.h"
#include "ckravr/io.h"
#include "ckravr/uart.h"
#include "ckravr/ds3231.h"

int main(){
    uart_init(9600,NULL);
    i2c_init();
    while(1){
       _delay_ms(1000);
       uint8_t sec = ds3231_get_seconds();
       uint8_t min = ds3231_get_minutes();
       uint8_t hour = ds3231_get_hours();
       printf("%u:%u:%u\n",hour,min,sec);
       
    }
}
