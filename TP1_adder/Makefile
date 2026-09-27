SYSTEMC_ARCH = linux

OPT    = -O3
DEBUG  = -g
OTHER  = -Wall -Wno-deprecated
CXXFLAGS = -std=gnu++0x $(OTHER) $(DEBUG)
#CXXFLAGS = -std=gnu++98 $(OTHER) $(DEBUG)
# CFLAGS = $(DEBUG) $(OTHER)

MODULE = run
SRCS = driver.cpp full_adder.cpp full_adder_main.cpp half_adder.cpp monitor.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY:	clean

include ./Makefile.defs

clean::
	rm -f *.vcd Makefile.deps
