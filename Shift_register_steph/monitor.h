// File : monitor.h
#ifndef MONITOR_H
#define MONITOR_H

#include "systemc.h"

SC_MODULE(monitor)
{
	sc_in<bool> m_din, m_r;

	void prc_monitor();

	SC_CTOR(monitor) : m_r("m_r"), m_din("m_din")
	{
		SC_METHOD(prc_monitor);
		sensitive << m_din << m_r;
	}
};

#endif // MONITOR_H
