#include "FBLib_hdd.h"
#include "../libFireBird.h"

#ifndef _TMS_

dword HDD_LiveFS_GetFAT1Address (void)
{
  return FIS_vHDDLiveFSFAT1();
}

#endif
