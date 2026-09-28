#include "shift_register.h"
bool V[6] = {false, false, false, false, false, false};

void shift(bool val)
{
    for (int i = 0; i < 6; i++){
        V[(i+1) % 6] = V[i]; // shift to the right
    }
    V[0] = val; // V[0] <= din

}

void Shift_register::do_shift()
{
    shift(din);
    for (int i = 0; i < 6; i++){
        r[i].write(V[i]);
    }
    wait(2, SC_NS);
}