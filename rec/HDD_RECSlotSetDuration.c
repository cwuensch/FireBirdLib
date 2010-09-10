#include "../libFireBird.h"
#include "FBLib_rec.h"

bool HDD_RECSlotSetDuration(byte Slot, word Duration)
{
  //Sanity check of the parameters
  if (Slot > HDD_NumberOfRECSlots()) return FALSE;

  //Find the address of the two RECslot structures
  if (RECSlot[0] == NULL) getRECSlotAddress();
  if (RECSlot[0] == NULL) return FALSE;

  //Check if the selected REC-slot is currently in use
  if (RECSlot[Slot]->Duration == 0) return FALSE;

  RECSlot[Slot]->Duration = Duration;

  return TRUE;
}
