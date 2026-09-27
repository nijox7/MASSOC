// File : driver.cpp
#include "driver.h"

void driver::prc_driver()
{
	sc_uint<4> pattern;
	pattern=0;

	while (1)
	{
		d_e.write(pattern);
		i.write(pattern);
		wait(5,SC_NS); // wait 5 nanoseconds
		pattern++;
	}
}

