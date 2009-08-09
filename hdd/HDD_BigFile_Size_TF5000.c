#include "FBLib_hdd.h"
#include "../libFireBird.h"

#ifndef _TMS_

dword HDD_BigFile_Size (TYPE_File *fp)
{
  return (fp->totalCluster * HDD_GetClusterSize());
}

#endif
