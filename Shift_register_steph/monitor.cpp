// File : monitor.cpp
#include "monitor.h"

void monitor::prc_monitor()
{
  cout << "At time " << sc_time_stamp() << "::";
  cout << " din: " << m_din.read() << endl;
  cout << " r: " << m_r.read() << endl;
}
