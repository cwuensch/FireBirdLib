#include "FBLib_rec.h"

tRECSlot                *RECSlot[5] = {NULL, NULL, NULL, NULL, NULL};

bool getRECSlotAddress(void)
{
  int                   i;

  for(i = 0; i < (int)HDD_NumberOfRECSlots(); i++)
    RECSlot[i] = (tRECSlot*) FIS_vRECSlotAddress(i);

  return TRUE;
}
