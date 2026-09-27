#include "fir_untimefx.h"

int X[5] = {0, 0, 0, 0, 0};
double H[5] = {-0.1, -0.2, 1.6, -0.2, -0.1};

int FIR(int xn) {
  double sum = 0;
  for (int k = 0; k < 5; k++) {
    sum += H[k]*X[4 - k];
  }
  return sum;
}

void FIR_4pts::do_fir() {
  while(1) {
    // décale vers la droite le tableau X
    for (int i = 1; i < 5; i++){
      X[i] = X[i-1];
    }
    X[0] = d_e.read();
    for(int i=0; i<5;i++)
      s.write(FIR(i));
  }
}
