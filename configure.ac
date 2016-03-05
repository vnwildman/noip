AC_PREREQ([2.69])
AC_INIT([noip], [2.2.4rc1], [bug@no-ip.com],, [http://www.no-ip.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([src/noip2.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

AC_ARG_ENABLE(debug, AS_HELP_STRING([--enable-debug],[enable debugging, default: no]),
 [case "${enableval}" in
             yes) AC_DEFINE([DEBUG], [1], [Enable debug.]) ;;
             no)  AC_DEFINE([DEBUG], [0], [Disable debug.]) ;;
             *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
 esac])

# Checks for libraries.
AC_CHECK_LIB([curl], [curl_easy_init], AC_DEFINE([HAVE_CURL], [1], [Use curl instead of wget]))

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h netdb.h netinet/in.h stdlib.h string.h sys/ioctl.h sys/socket.h sys/time.h syslog.h termios.h unistd.h ifaddrs.h linux/sockios.h net/if_types.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_CHECK_FUNCS([alarm gethostbyname inet_ntoa memset realpath select socket strchr strerror strncasecmp strrchr strstr])

AC_DEFINE([COPYRIGHT_YEAR], [m4_esyscmd([date +%Y])], [Current year that use in copyright message])

AC_CONFIG_FILES([
 Makefile
 src/Makefile
 etc/Makefile
])
AC_OUTPUT
