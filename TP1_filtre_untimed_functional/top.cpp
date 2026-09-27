
#include "driver.h"
#include "fir_untimefx.h"
#include "monitor.h"

int sc_main(int argc,char *argv[])
{
	sc_fifo<int> d_e("d_e"), s("s"); 
	sc_signal<int> i("i"), o("o");

	FIR_4pts fir("FilterWaveforms");
		fir.d_e(d_e);
		fir.s(s);

	driver d1("GenerateWaveforms");
		d1.d_e(d_e);
		d1.i(i);

	monitor mo1("MonitorWaveforms");
		mo1.s(s);
		mo1.o(o);

	sc_trace_file* tfp = sc_create_vcd_trace_file("FIR_4pts_main");
		// sc_trace(tfp, d_e, d_e.name());
	// 	// sc_trace(tfp, i, i.name());
		// sc_trace(tfp, s, s.name());
	// 	// sc_trace(tfp, o, o.name());
	sc_start(100, SC_NS); // se termine après 100 NS
	sc_close_vcd_trace_file(tfp);
	return 0;
}
