avr-framework = Is a collection of avr specific functionality like i2c, uart and other interesting driver and helpers[![GitHub release](https://img.shields.io/github/release/ckruczek/avr-framework.svg?style=flat-square)]()
=======

**Table of contents**

1.[Summary](#summary)

2.[Building on linux](#building-on-linux-with-git-gccclang-and-autotools)


## Summary

avr-framwork is a collection of functions and examples used for programming on the avr platform.
For example: i2c implementation, simple uart abstraction with stdin/stdout redirection, simple I/O abstraction layer for communicating with ports
and more. Also there are some examples that are always enhanced by new ones if new functionality swaps in.


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
$ ./configure
$ make
```

