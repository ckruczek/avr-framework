#include "../include/ckravr/ds3231.h"
#include "../include/ckravr/i2c.h"


void ds3231_set_date_time(struct date_time *dt)
{
    ds3231_set_hours(dt->hours);
    ds3231_set_minutes(dt->minutes);
    ds3231_set_seconds(dt->seconds);
}
void ds3231_get_date_time(struct date_time *dt)
{
    dt->hours = ds3231_get_hours();
    dt->minutes = ds3231_get_minutes();
    dt->seconds = ds3231_get_seconds();
}
uint8_t bcd_to_dec(uint8_t bcd)
{
    return ((bcd & 0xF0) >> 4) * 10 + (bcd & 0x0F);
}

uint8_t dec_to_bcd(uint8_t dec)
{
    return ((dec / 10) << 4) | (dec % 10);
}

uint8_t ds3231_get_seconds()
{
    uint8_t sec = i2c_read8(DS3231_ADDRESS,DS3231_SECONDS);
    return bcd_to_dec(sec);

}

void ds3231_set_seconds(uint8_t seconds)
{
    i2c_write8(DS3231_ADDRESS,DS3231_SECONDS,dec_to_bcd(seconds));
}

uint8_t ds3231_get_minutes()
{
    uint8_t min = i2c_read8(DS3231_ADDRESS,DS3231_MINUTES);
    return bcd_to_dec(min);
}
void ds3231_set_minutes(uint8_t min)
{
    i2c_write8(DS3231_ADDRESS,DS3231_MINUTES,dec_to_bcd(min));
}

uint8_t ds3231_get_hours()
{
    uint8_t hours = i2c_read8(DS3231_ADDRESS,DS3231_HOURS);
    return bcd_to_dec(hours);
}

void ds3231_set_hours(uint8_t hours)
{
    i2c_write8(DS3231_ADDRESS,DS3231_HOURS,dec_to_bcd(hours));
}

uint8_t ds3231_get_dayofweek()
{
    
}
uint8_t ds3231_get_day()
{
    
}
uint8_t ds3231_get_month()
{
    
}
uint8_t ds3231_get_year()
{
    
}
