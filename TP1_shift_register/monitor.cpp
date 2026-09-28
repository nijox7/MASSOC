// File : monitor.cpp
#include "monitor.h"

void monitor::prc_monitor()
{
  while(1) {
    cout << "At time " << sc_time_stamp() << "::";
//    cout << " r: " << r.read() << endl;
    cout << " din: " << din.read() << endl;
  }
}

