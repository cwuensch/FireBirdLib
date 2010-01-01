#include "FBLib_rec.h"

//Slot 0, Slot 1 and Timeshift
tRECSlot                *RECSlot[3] = {NULL, NULL, NULL};

bool getRECSlotAddress(void)
{
  RECSlot[0] = (tRECSlot*) FIS_vRECSlotAddress(0);
  RECSlot[1] = (tRECSlot*) FIS_vRECSlotAddress(1);
  RECSlot[2] = (tRECSlot*) FIS_vRECSlotAddress(2);

  return TRUE;
}
