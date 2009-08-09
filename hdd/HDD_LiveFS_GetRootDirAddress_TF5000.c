#include "../libFireBird.h"

#ifndef _TMS_

dword HDD_LiveFS_GetRootDirAddress (void)
{
  return FIS_vHDDLiveFSRootDir();
}

#endif
