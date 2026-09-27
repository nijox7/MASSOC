#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H

SC_MODULE(shift_register)
{
public:
    // In/Output
    sc_in<bool> din;
    sc_out<bool> r;
    bool VECT = {}
    
    // Signal
    sc_bv<6> val;

    void do_shift();
    SC_CTOR(shift_register)
    {
        SC_THREAD(do_shift);
        // sensitive << clk; // TODO -> que le front montant!
    }
}

#endif // SHIFT_REGISTER_H