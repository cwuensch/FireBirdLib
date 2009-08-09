#include "FBLib_hdd.h"
#include "../libFireBird.h"

#ifndef _TMS_

int HDD_GetFirmwareDirCluster (void)
{
  if (!LibInitialized) InitTAPex();
  if (!LibInitialized || !pWD1) return -1;

  return *(dword*)(*(dword*)(pWD2) + 8);
}

#endif
