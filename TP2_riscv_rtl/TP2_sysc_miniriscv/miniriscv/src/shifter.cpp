#include "shifter.h"

void shifter::shift() {
    sc_uint<32> res_interne;
    int cmd = CMD_SE.read();
    if (cmd == 0){
        // shift left logical
        res_interne = DIN_SE.read() << SHIFT_VAL_SE.read();
    }
    else if (cmd == 1){
        // shift right logical
        res_interne = DIN_SE.read() >> SHIFT_VAL_SE.read();
    }
    else if (cmd == 2){
        // shift right arithmetic
        res_interne = (DIN_SE.read() >> SHIFT_VAL_SE.read()) || (1 << 31); // conserves sign bit 32
    }
    DOUT_SE.write(res_interne);
}

void shifter::trace(sc_trace_file* tf) {
    sc_trace(tf, DIN_SE, GET_NAME(DIN_SE));
    sc_trace(tf, SHIFT_VAL_SE, GET_NAME(SHIFT_VAL_SE));
    sc_trace(tf, CMD_SE, GET_NAME(CMD_SE));
    sc_trace(tf, DOUT_SE, GET_NAME(DOUT_SE));
}