#include "../libFireBird.h"


inline dword FIS_vRECSlotAddress(byte Slot)
{
#ifdef _TMS_

  byte               *_pvrRecInfo;

  if (Slot > 2) return 0;

  _pvrRecInfo = (byte*)TryResolve("_pvrRecInfo");

  if(!_pvrRecInfo) return 0;

  switch(Slot)
  {
    case 0: return (dword)&_pvrRecInfo[0]; break;
    case 1: return (dword)&_pvrRecInfo[sizeof(TYPE_TimerSTMS)]; break;
    case 2: return (dword)&_pvrRecInfo[2 * sizeof(TYPE_TimerSTMS)]; break;
  }

  return 0;

#else

  dword                 *vRECSlotAddress = NULL;

  if (Slot > 1) return 0;

  if (!vRECSlotAddress)
  {
    vRECSlotAddress = (dword*)FindInstructionSequence ("0c05dd59 00002025 304200ff 10400008 24040001 3c1981b2 9339dddc 17230004 24040001 1000000e 24020001 24040001 0c05dd59 00000000 304200ff 10400008 00001025 3c1981b2 9339de64",
                                                       "fc000000 ffffffff ffffffff ffffffff ffffffff ffe00000 fc000000 fc000000 ffffffff ffff0000 ffffffff ffffffff fc000000 ffffffff ffffffff ffff0000 ffffffff ffe00000 fc000000",
                                                       0x80140000, 0x80200000, 5, FALSE);

    if (!vRECSlotAddress) return 0;
  }

  //i holds the address of the lui opcode of RECSlot 1.
  return (Slot ? ((vRECSlotAddress[12] << 16) + (short)(vRECSlotAddress[13] & 0xffff)) : ((vRECSlotAddress[0] << 16) + (short)(vRECSlotAddress[1] & 0xffff)));

#endif
}

