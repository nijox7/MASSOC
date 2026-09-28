// File : monitor.h
#ifndef MONITOR_H
#define MONITOR_H

#include "systemc.h"

SC_MODULE(monitor)
{
  	sc_in<sc_bv<6>> r;
	sc_in<bool> din;

	void prc_monitor();

	SC_CTOR(monitor)
	{
		SC_THREAD(prc_monitor);
		sensitive << r;
	}
};

#endif // MONITOR_H
