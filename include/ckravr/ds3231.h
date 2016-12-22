/* 
 * File:   ds3231.h
 * Author: Christopher Kruczek
 *
 * Created on December 22, 2016, 4:21 PM
 */

#ifndef DS3231_H
#define DS3231_H

#include <stdint.h>

struct date_time{
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    char    dayofweek;
    uint8_t day;
    uint8_t month;
    uint8_t year;
};

#define DS3231_ADDRESS      0x68
#define DS3231_SECONDS      0x00
#define DS3231_MINUTES      0x01
#define DS3231_HOURS        0x02
#define DS3231_DAYOFWEEK    0x03
#define DS3231_DAY          0x04
#define DS3231_MONTH        0x05
#define DS3231_YEAR         0x06

void ds3231_set_date_time(struct date_time *dt);
void ds3231_get_date_time(struct date_time *dt);
uint8_t bcd_to_dec(uint8_t bcd);
uint8_t ds3231_get_seconds();
void ds3231_set_seconds(uint8_t seconds);
uint8_t ds3231_get_minutes();
uint8_t ds3231_get_hours();
uint8_t ds3231_get_dayofweek();
uint8_t ds3231_get_day();
uint8_t ds3231_get_month();
uint8_t ds3231_get_year();

#endif /* DS3231_H */

