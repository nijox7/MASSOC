// File : driver.h
#ifndef DRIVER_H
#define DRIVER_H

#include "systemc.h"

SC_MODULE(driver)
{
	sc_fifo_out<int> d_e;
  	sc_out<int> i;

	void prc_driver();

	SC_CTOR(driver) : d_e("d_e")
	{
		SC_THREAD(prc_driver);
	}
};

#endif // DRIVER_H
