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

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
