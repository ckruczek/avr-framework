#include "i2c.h"

/**
 * This function intialize the i2c.
 */
void i2c_init() {
    
    // init pullup resistor for twi
    PORTD |= (1 << PD0);
    PORTD |= (1 << PD1);
    
    TWSR &= ~(1 << TWPS0);
    TWSR &= ~(1 << TWPS1);
    TWBR = ((F_CPU / F_SCL) - 16) / 2;
    TWCR = (1 << TWEN) | (1 << TWIE) | (1 << TWEA);
    
}

/**
 * This function intiates the i2c start signal.
 * @param address - The slave address needed for communication
 * @param mode - The slave mode. Either TWI_READ or TWI_WRITE
 * @return - Returns the status the slave send back to the master device.
 */
uint8_t i2c_start(uint8_t address, uint8_t mode) {
    uint8_t status = 0;
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while(!(TWCR & (1 << TWINT)));

    status = TW_STATUS & 0xF8;
    TWDR = (address << 1) | mode;
    TWCR = (1 << TWINT) | (1 << TWEN);
    if((status == TW_MT_SLA_NACK) || (status == TW_MT_DATA_NACK))
    {
        return status;
    }

    while(!(TWCR & (1 << TWINT)));
    status = TW_STATUS & 0xF8;
    return status;

}

/**
 * This function writes data on the i2c signal
 * @param data - The data to transfer to the slave
 * @return - Returns the status of the write.
 */
uint8_t i2c_write(uint8_t data) {
    TWDR = data;

    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWSR & 0xF8;

}

/**
 * This function reads a acknowledge after a transmission ended.
 * @return - Returns the data read by after transmission.
 */
uint8_t i2c_read_ack() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));

    printf("ack");
    
    return TWDR;
}

/**
 * This functions reads a not-acknowledge after a transmission ended.
 * @return - Returns the data read by after transmission.
 */
uint8_t i2c_read_nack() {
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));

    printf("nack");
    
    return TWDR;
}

/**
 * This function stops the i2c communcation.
 * @return 
 */
uint8_t i2c_stop() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
    while(TWCR & (1 << TWSTO));
    return 0;
}

/**
 * This function reads a byte from the slave and his sub component
 * @param baseAddress - The baseaddres of the slave to be adressed
 * @param subAddress - The address of the corresponding component you want to read from.
 * @return - Returns the byte read from the component
 */
uint8_t i2c_read8(uint8_t baseAddress, uint8_t subAddress) {   
    i2c_start(baseAddress, TW_WRITE);
    i2c_write(subAddress);
    
    i2c_start(baseAddress,TW_READ);
    uint8_t result = i2c_read_nack();
    i2c_stop();
    
    return result;
    
}

/**
 * This function writes data to the slave and its addressed component
 * @param baseAddress - The address of the corresponding slave
 * @param subAddress - The component address of the slave.
 * @param data - The one byte of data that is written to the slave component.
 */
void i2c_write8(uint8_t baseAddress, uint8_t subAddress,uint8_t data)
{
    i2c_start(baseAddress, TW_WRITE);
    i2c_write(subAddress);
    i2c_write(data);
    i2c_stop();
}
