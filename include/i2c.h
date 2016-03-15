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

volatile uint8_t buffer_address;
volatile uint8_t txbuffer[0xFF];
volatile uint8_t rxbuffer[0xFF];

typedef void (*i2ccallback)(uint8_t );
i2ccallback i2c_callback;

void i2c_init();
void i2c_init_slave(uint8_t address,i2ccallback);
uint8_t i2c_start(uint8_t address,uint8_t mode);
uint8_t i2c_write(uint8_t data);
uint8_t i2c_read_ack();
uint8_t i2c_read_nack();
uint8_t i2c_stop();

uint8_t i2c_read8(uint8_t baseAddress, uint8_t subAddress);
void i2c_write8(uint8_t baseAddress, uint8_t subAddress,uint8_t data);

#endif

