#include "shift_register.h"
#include "driver.h"

int sc_main(int argc,char *argv[]){
    sc_signal<bool> din("din");
    sc_signal<sc_bv<6>> r("r");

	Shift_register sr1("Shift_register");
    sr1.din(din);
    sr1.r(r);

	driver d1("Driver");
	d1.din(din);

//	monitor mo1("Monitor");

	sc_trace_file* tfp = sc_create_vcd_trace_file("shift_register_main");
	    sc_trace(tfp, din, din.name());
        sc_trace(tfp, r, r.name());
	sc_start(100,SC_NS);
	sc_close_vcd_trace_file(tfp);

    return 0;
}