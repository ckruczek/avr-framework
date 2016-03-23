/* 
 * File:   io.h
 * Author: Christopher Kruczek
 *
 * Created on March 23, 2016, 10:58 AM
 */

#ifndef IO_H
#define IO_H

#include <avr/io.h>

#define _PORT_(ddr,port,pin,inp) port
#define PORT(p) _PORT_ p

#define _DDR_(ddr,port,pin,inp) ddr
#define DDR(d) _DDR_ d

#define _PIN_(ddr,port,pin,inp) pin
#define PIN(p) _PIN_ p

#define _INPUT_(ddr,port,pin,inp) inp
#define INPUT(p) _INPUT_ p

#define io_out(out)  \
        DDR(out) |= (1 << PIN(out))        \

#define io_in(inp)      \
      DDR(inp) &= ~(1 << PIN(inp));       \
      PORT(inp) |= (1 << PIN(inp))        \
      

#define io_get(inp) ((INPUT(inp)) & (1 << PIN(inp)))
#define io_high(out) ((PORT(out)) |= (1 << PIN(out)))
#define io_low(out) ((PORT(out)) &= ~(1 << PIN(out)))
#endif /* IO_H */

