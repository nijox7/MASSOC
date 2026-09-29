#include "shift_register.h"
bool V[6] = {false, false, false, false, false, false};
bool mask[6] = {true, false, true, false, true, false};

void shift(bool val)
{
    bool temp = V[0];
    for (int i = 5; i >= 0; i--){
        V[(i+1) % 6] = V[i]; // shift to the right
        if (mask[(i+1) % 6]) V[(i+1) % 6] = V[i] ^ V[5]; 
    }
    V[1] = temp; // remplace r1 avec la valeur initiale de r0
    V[0] = val; // remplace V[0] par l'entrée din
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
        // cout << "SHIFT_REGISTER: " << endl << "din = " << din << endl;
        // cout << "r = " << r << endl;
        wait(2, SC_NS);
    }
}
