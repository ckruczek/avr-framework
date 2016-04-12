/* 
 * File:   adc.h
 * Author: ckruczek
 *
 * Created on April 12, 2016, 7:28 PM
 */

#ifndef ADC_H
#define ADC_H

#include <stdint.h>
#include <avr/io.h>

extern void adc_init();
extern void adc_select_input(char channel);
extern uint16_t adc_read();


#endif /* ADC_H */

