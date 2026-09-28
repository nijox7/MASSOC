#include "systemc.h"
#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H

SC_MODULE(Shift_register)
{
public:
    // In/Output
    sc_in<bool> din;
    sc_out< sc_bv<6> > r;
    
    // Signal
    sc_bv<6> val;

    void do_shift();
    SC_CTOR(Shift_register)
    {
        SC_THREAD(do_shift);
        // sensitive << clk; // TODO -> que le front montant!
    }
};

#endif // SHIFT_REGISTER_H