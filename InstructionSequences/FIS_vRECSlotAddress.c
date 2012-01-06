#include "../flash/FBLib_flash.h"

inline dword FIS_vRECSlotAddress(byte Slot)
{
  static byte          *__pvrRecInfo = NULL;
  static byte          *__isSnapshotComplete = NULL;
  static int            infSize = 200;

  if (Slot > HDD_NumberOfRECSlots()) return 0;

  if(!__pvrRecInfo)
  {
    __pvrRecInfo = (byte*)TryResolve("_pvrRecInfo");
    if(!__pvrRecInfo) return 0;
  }

  if(!__isSnapshotComplete)
  {
    __isSnapshotComplete = (byte*)TryResolve("_isSnapshotComplete");
    if(!__isSnapshotComplete) return 0;

    infSize = ((dword)__isSnapshotComplete - (dword)__pvrRecInfo) / (HDD_NumberOfRECSlots() + 1);
  }

  return (dword)&__pvrRecInfo[Slot * infSize];
}
