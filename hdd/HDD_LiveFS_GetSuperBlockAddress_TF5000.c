#include "FBLib_hdd.h"
#include "../libFireBird.h"

#ifndef _TMS_

dword            pHDDLiveFSSuperBlock = 0;

dword HDD_LiveFS_GetSuperBlockAddress (void)
{
  return FIS_vHDDLiveFSSuperblock();
}

#endif
