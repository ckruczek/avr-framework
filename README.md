avr-framework = Is a collection of avr specific functionality like i2c, uart and other interesting driver and helpers[![GitHub release](https://img.shields.io/github/release/ckruczek/avr-framework.svg?style=flat-square)]()
=======

**Table of contents**

1.[Summary](#summary)

2.[Supported devices](#supported-devices)

3.[Building on linux](#building-on-linux-with-git-gccclang-and-autotools)

4.[Building an example](#building-an-example)

## Summary

avr-framwork is a collection of functions and examples used for programming on the avr platform.
For example: i2c implementation, simple uart abstraction with stdin/stdout redirection, simple I/O abstraction layer for communicating with ports
and more. Also there are some examples that are always enhanced by new ones if new functionality swaps in.

## Supported devices

    atmega2560(F_CPU=16000000)

## Building on linux with `git`, `gcc/clang` and `autotools`

Prerequisites

- `avr-gcc`
- `avr-libc` 
- `autotools`

Clone `avr-framework` from github: git@github.com:ckruczek/avr-framework.git

```bash
$ git clone git@github.com:ckruczek/avr-framework.git
$ cd avr-framework
$ autoreconf --install
$ ./configure --host=avr --enable-m2560=yes
$ make
```

The fourth line enables the use of the atmega2560 architecture. 

## Building an example

To build an example change to the example directory.
For example the blinky example.


```bash
$ cd samples/blinky
```

You now find a predefined `Makefile` that you can trigger as follow:

**Build the example**
```bash
$ make -B
```

**Upload the example**
```bash
$ make program
```

If your `tty` is different to `dev/ttyACM0` you have to adapt the port accordingly. So change the `AVRDUDE_PORT` variable in the `Makefile`
according to your port.