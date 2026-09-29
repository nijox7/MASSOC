#include "systemc.h"
#include "shift_register.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]){
    sc_clock clk("clk", 2, SC_NS);
    sc_signal<bool> sig_din, sig_r;

    shift u_shift("shift");
    u_shift.clk(clk);
    u_shift.din(sig_din);
    u_shift.r(sig_r);

    driver u_driver("driver");
    u_driver.din(sig_din);

    monitor m1("Monitor");
    m1.m_din(sig_din);
    m1.m_r(sig_r);

    sc_trace_file *tf = sc_create_vcd_trace_file("traces");
    sc_trace(tf, clk, "clk");
    sc_trace(tf, sig_din, "din");
    sc_trace(tf, sig_r, "r");
    sc_trace(tf, u_shift.val, "val");

    sc_start(100, SC_NS);
    sc_close_vcd_trace_file(tf);

    return 0;
}