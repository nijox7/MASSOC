#include "shift_register.h"
bool V[6] = {false, false, false, false, false, false};
bool mask[6] = {false, false, true, false, true, false};

void shift(bool val)
{
    bool temp = V[0];
    for (int i = 5; i >= 0; i--){
        V[(i+1) % 6] = V[i]; // shift to the right
        if (mask[(i+1) % 6]) V[(i+1) % 6] = V[i] ^ V[5]; 
    }
    V[1] = temp; // replace V[1] by initial value of V[0]
    V[0] = val;  // replace V[0] by the entry din
}

void Shift_register::do_shift()
{
    while(1){
        shift(din);
        int res = 0;
        for (int i = 0; i < 6; i++){
            if (V[i]) res += (1 << i);
        }
        r.write(res);
        wait(2, SC_NS);
    }
}
