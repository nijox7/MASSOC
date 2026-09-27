// File : monitor.h
#ifndef MONITOR_H
#define MONITOR_H

#include "systemc.h"

SC_MODULE(monitor)
{
	sc_fifo_in<int> s;
  	sc_out<int> o;

	void prc_monitor();

	SC_CTOR(monitor) : s("m_s")
	{
		SC_THREAD(prc_monitor);
		sensitive << s;
	}
};

#endif // MONITOR_H
