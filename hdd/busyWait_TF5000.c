#include "FBLib_hdd.h"
#include "../libFireBird.h"

#ifndef _TMS_

volatile byte *HDD_pAltStatus   = (byte*) 0xb0012d5b;   // alternate status register

void busyWait (void)
{
  while ((*HDD_pAltStatus & 0x80) != 0);
}

#endif
