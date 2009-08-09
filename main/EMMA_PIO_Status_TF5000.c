#include "tap.h"

#ifndef _TMS_

volatile dword *EMMA_PIO1_Status = (dword *) 0xb2010c10;
volatile dword *EMMA_PIO2_Status = (dword *) 0xb2010c14;

#endif
