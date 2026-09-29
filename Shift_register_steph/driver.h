
#include "systemc.h"

SC_MODULE (driver) {
	sc_out<bool> din;

	void prc_driver();

	SC_CTOR( driver) : din("din")
	{
		SC_THREAD( prc_driver);
	}
};
