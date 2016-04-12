#include "../include/ckravr/adc.h"

/**
 * Initialise the analog-digital converter with the internal reference
 * voltage and a prescaler of 128
 */
void adc_init()
{
    ADMUX = (1 << REFS0); // For Aref=AVcc;
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); //Rrescalar div factor =128
}

/**
 * Select the analog channel to read from.
 * @param channel - The channel to read from
 */
void adc_select_input(char channel)
{
    channel &= 0b00000111;
    ADMUX = (ADMUX & 0xF8) | channel;
}

/**
 * Start a adc conversion and return the result.
 * @return The adc conversion result.between 0-1023
 */
uint16_t adc_read()
{
    ADCSRA |= (1 << ADSC);
    // wait for conversion to end
    while (!(ADCSRA & (1 << ADIF)));

    ADCSRA |= (1 << ADIF);

    return ADC;
}