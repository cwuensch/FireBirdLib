#include "FBLib_tap.h"

// Return codes: 0..15 = Position in the TAP table
//                  -1 = TAPID not found
//
int HDD_TAP_GetIndexByID (dword TAPID)
{

#ifdef _TMS_

  int                   i;

  for (i = 0; i < TAP_MAX; i++)
  {
    if(HDD_TAP_GetIDByIndex(i) == TAPID) return i;
  }

  return -1;

#else

  dword                 LoadAddress;
  int                   i;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return -1;

  for (i = 0; i < TAP_MAX; i++)
  {
    LoadAddress = *(dword*) (TAP_TableAddress + (i << 5) + 12);
    if (LoadAddress != 0)
    {
      if (*(dword*)(LoadAddress + 0x0020) == TAPID) return i;
    }
  }

  return -1;

#endif

}
