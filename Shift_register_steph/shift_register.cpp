#include "shift_register.h"

void shift::do_shift()
{
    val = 0;
    while(true){
        wait();

        bool msb = val[5];
        val = val << 1;
        val[0] = din.read();

        if (msb){
            val = val ^ 0x05;
        }
        r.write(msb);
    }
}