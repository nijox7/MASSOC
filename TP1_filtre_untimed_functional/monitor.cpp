// File : monitor.cpp
#include "monitor.h"

void monitor::prc_monitor()
{
  while(1) {
    o = s.read();
    cout << "At time " << sc_time_stamp() << "::";
    cout << " s: " << o.read() << endl;
  }
}

