# Customize below to fit your system

# paths
DESTDIR =
PREFIX = /usr/local

BIGINTINC = 'libs/bigint/Big Integer Library in Single file/'

# includes and libs
INCS = -I${BIGINTINC}
LIBS =

# flags
CXXFLAGS = ${INCS}
LDFLAGS  = ${LIBS}

# compiler and linker
CXX = clang++
