#include "FBLib_rec.h"

tRECSlot *HDD_RECSlotGetAddress(byte Slot)
{
  //Sanity check of the parameters (Slot 2 = Timeshift on the TMS. Returns NULL on the TF5000)
  if (Slot > HDD_NumberOfRECSlots()) return NULL;

  //Find the address of the two RECslot structures
  if (RECSlot[0] == NULL) getRECSlotAddress();
  if (RECSlot[0] == NULL) return NULL;

  return (RECSlot[Slot]);
}
