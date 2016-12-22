#include "../include/ckravr/ds3231.h"
#include "../include/ckravr/i2c.h"


void ds3231_set_date_time(struct date_time *dt)
{
    
}
void ds3231_get_date_time(struct date_time *dt)
{
    
}
uint8_t bcd_to_dec(uint8_t bcd)
{
    return ((bcd & 0xF0) >> 4) * 10 + (bcd & 0x0F);
}
uint8_t ds3231_get_seconds()
{
    uint8_t sec = i2c_read8(DS3231_ADDRESS,DS3231_SECONDS);
    return bcd_to_dec(sec);

}
void ds3231_set_seconds(uint8_t seconds)
{
    
}

uint8_t ds3231_get_minutes()
{
    
}
uint8_t ds3231_get_hours()
{
    
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
