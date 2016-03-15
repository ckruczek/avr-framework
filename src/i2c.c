#include "i2c.h"

void i2c_init() {
    
    // init pullup resistor for twi
    PORTD |= (1 << PD0);
    PORTD |= (1 << PD1);
    
    TWSR &= ~(1 << TWPS0);
    TWSR &= ~(1 << TWPS1);
    TWBR = ((F_CPU / F_SCL) - 16) / 2;
    TWCR = (1 << TWEN) | (1 << TWIE) | (1 << TWEA);
    
}

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

uint8_t i2c_write(uint8_t data) {
    TWDR = data;

    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWSR & 0xF8;

}

uint8_t i2c_read_ack() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));

    printf("ack");
    
    return TWDR;
}

uint8_t i2c_read_nack() {
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));

    printf("nack");
    
    return TWDR;
}

uint8_t i2c_stop() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
    while(TWCR & (1 << TWSTO));
    return 0;
}

uint8_t i2c_read8(uint8_t baseAddress, uint8_t subAddress) {   
    i2c_start(baseAddress, TW_WRITE);
    i2c_write(subAddress);
    
    i2c_start(baseAddress,TW_READ);
    uint8_t result = i2c_read_nack();
    i2c_stop();
    
    return result;
    
}

void i2c_write8(uint8_t baseAddress, uint8_t subAddress,uint8_t data)
{
    i2c_start(baseAddress, TW_WRITE);
    i2c_write(subAddress);
    i2c_write(data);
    i2c_stop();
}
