#include "../libFireBird.h"

#ifndef _TMS_

tPlaySlot *HDD_PlaySlotGetAddress (void)
{
  return (tPlaySlot *)FIS_vPlaySlot();
}

#endif
