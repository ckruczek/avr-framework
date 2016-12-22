/* 
 * File:   i2c.h
 * Author: Christopher Kruczek
 *
 * Created on December 9, 2015, 7:50 AM
 */

#ifndef I2C_H
#define I2C_H

#include <avr/io.h>
#include <util/twi.h>
#include <avr/interrupt.h>

#include <stdint.h>
#include <stdio.h>

#define F_SCL 100000UL // SCL frequency

#define I2C_READ    TW_READ
#define I2C_WRITE   TW_WRITE

volatile uint8_t buffer_address;
volatile uint8_t txbuffer[0xFF];
volatile uint8_t rxbuffer[0xFF];

typedef void (*i2ccallback)(uint8_t );
i2ccallback i2c_callback;

extern void i2c_init();
extern void i2c_init_slave(uint8_t address,i2ccallback);
extern uint8_t i2c_start(uint8_t address,uint8_t mode);
extern uint8_t i2c_write(uint8_t data);
extern uint8_t i2c_read_ack();
extern uint8_t i2c_read_nack();
extern uint8_t i2c_stop();

extern uint8_t i2c_read8(uint8_t baseAddress, uint8_t subAddress);
extern void i2c_write8(uint8_t baseAddress, uint8_t subAddress,uint8_t data);

#endif

