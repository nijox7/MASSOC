SYSTEMC_ARCH = linux

OPT    = -O3
DEBUG  = -g
OTHER  = -Wall -Wno-deprecated
CXXFLAGS = -std=gnu++0x $(OTHER) $(DEBUG)
# CFLAGS = $(DEBUG) $(OTHER)

MODULE = run
SRCS = driver.cpp main.cpp shift_register.cpp monitor.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY:	clean

include ./Makefile.defs

clean::
	rm -f *.vcd Makefile.deps
