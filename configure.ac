# Define the minimum version of autoconf required
AC_PREREQ([2.69])
AC_INIT([NoClueCoin], [1.0], [your-email@example.com])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Set up compiler flags
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB

# Check for required libraries
PKG_CHECK_MODULES([LIBSSL], [openssl >= 1.0.0], [], [
    AC_MSG_ERROR([OpenSSL library is required])
])
PKG_CHECK_MODULES([BOOST], [boost >= 1.55], [], [
    AC_MSG_ERROR([Boost libraries are required])
])

# Configure the output files
AC_CONFIG_FILES([
    Makefile
    src/Makefile
    doc/Makefile
    test/Makefile
])

# Complete the configuration
AC_OUTPUT
