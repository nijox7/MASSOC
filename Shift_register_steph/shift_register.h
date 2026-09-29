#include "systemc.h"
#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H

SC_MODULE(shift)
{
public:
    // In/Output
    sc_in<bool> din;
    sc_in<bool> clk;
    sc_out<bool> r;
    
    sc_uint<6> val;

    void do_shift();

    SC_CTOR(shift) : din("din"), r("r")
    {
        SC_THREAD(do_shift);
        sensitive << clk.pos();
    }
};

#endif // SHIFT_REGISTER_H