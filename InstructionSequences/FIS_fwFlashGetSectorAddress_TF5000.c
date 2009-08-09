#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_fwFlashGetSectorAddress (void)
{
  static dword          fwFlashGetSectorAddress = 0;
  dword                 *p, i, gp;

  if (!fwFlashGetSectorAddress)
  {
    ;
    if (!(fwFlashGetSectorAddress = FIS_fwFlashEraseSector()) || !(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    //A structure, referenced via $gp, contains 4 pointers to the needed functions
    p = (dword*)(gp - 32768);
    for (i = 0; i < 0x4000; i++)
    {
      if (*p == fwFlashGetSectorAddress) break;
      p++;
    }

    if (i >= 0x4000)
    {
      fwFlashGetSectorAddress = 0;
      return 0;
    }

    //Are these valid pointers?
    if (!isValidRAMPtr (p [0]) || !isValidRAMPtr (p [1]) || !isValidRAMPtr (p [2]) || !isValidRAMPtr (p [3]))
    {
      fwFlashGetSectorAddress = 0;
      return 0;
    }

    fwFlashGetSectorAddress = p [3];
  }

  return fwFlashGetSectorAddress;
}

#endif
