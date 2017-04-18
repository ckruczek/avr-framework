AC_INIT([ckr-libavr],[1.0],[christopher.kruczek@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC([avr-gcc])
AC_CHECK_HEADERS([avr/io.h])
AC_PROG_RANLIB
AM_PROG_AR

# Add atmega2560 support
AC_ARG_ENABLE(m2560,
  AS_HELP_STRING(
    [--enable-m2560],
    [Enable the atmega2560 architecture]),
    [case "${enableval}" in
      yes) m2560=true ;;
      no)  m2560=false ;;
      *)   AC_MSG_ERROR([bad value ${enableval} for --enable-m2560]) ;;
    esac],
    [m2560=false])

AM_CONDITIONAL(M2560, test x"$m2560" = x"true")
AM_COND_IF(M2560,
    AC_DEFINE(M2560, 1, [Define to 0 if atmega2560 is not used]),
    AC_DEFINE(M2560, 0, [Define to 1 or higher if atmega2560 is used]))


# Add atmega32u4 support
AC_ARG_ENABLE(m32u4,
  AS_HELP_STRING(
    [--enable-m32u4],
    [Enable the atmega32u4 architecture]),
    [case "${enableval}" in
      yes) m32u4=true ;;
      no)  m32u4=false ;;
      *)   AC_MSG_ERROR([bad value ${enableval} for --enable-m32u4]) ;;
    esac],
    [m32u4=false])

AM_CONDITIONAL(M32U4, test x"$m32u4" = x"true")
AM_COND_IF(M32U4,
    AC_DEFINE(M32U4, 1, [Define to 0 if atmega32u4 is not used]),
    AC_DEFINE(M32U4, 0, [Define to 1 or higher if atmega32u4 is used]))


# Add atmega328p support
AC_ARG_ENABLE(m328p,
  AS_HELP_STRING(
    [--enable-m328p],
    [Enable the atmegam328p (nano) architecture]),
    [case "${enableval}" in
      yes) m328p=true ;;
      no)  m328p=false ;;
      *)   AC_MSG_ERROR([bad value ${enableval} for --enable-m328p]) ;;
    esac],
    [m328p=false])

AM_CONDITIONAL(M328P, test x"$m328p" = x"true")
AM_COND_IF(M328P,
    AC_DEFINE(M328P, 1, [Define to 0 if atmegam328p is not used]),
    AC_DEFINE(M328P, 0, [Define to 1 or higher if atmegam328p is used]))


AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
