noinst_LIBRARIES = libckravr.a
if M2560
    AM_CFLAGS =  -I$(top_srcdir)/include/ckravr -mmcu=atmega2560 -DF_CPU=16000000
endif
if M32U4
    AM_CFLAGS =  -I$(top_srcdir)/include/ckravr -mmcu=atmega32u4 -DF_CPU=16000000
endif

libckravr_a_SOURCES = i2c.c uart.c adc.c
