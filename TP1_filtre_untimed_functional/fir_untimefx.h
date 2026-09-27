#include "systemc.h"

SC_MODULE(FIR_4pts)
{
public:

  sc_fifo_in<int> d_e;
  sc_fifo_out<int> s;

  void do_fir();

  SC_CTOR(FIR_4pts) {
    SC_THREAD(do_fir);
    sensitive << d_e;
  }
};