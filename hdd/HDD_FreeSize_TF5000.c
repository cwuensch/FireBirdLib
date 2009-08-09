#include "FBLib_hdd.h"
#include "../libFireBird.h"

#ifndef _TMS_

// Return value: free space in MB
//
dword HDD_FreeSize (void)
{
  static byte           *pFAT = NULL;
  static dword          SectorsPerCluster = 0;
  dword                 FreeClusters, i;

  FreeClusters = 0;
  if (pFAT == NULL) pFAT = (byte*) HDD_LiveFS_GetFAT1Address();
  if (pFAT != NULL)
  {
    if (SectorsPerCluster == 0) SectorsPerCluster = HDD_GetClusterSize();
    for (i = 0; i < 131072; i++)
    {
      if (((pFAT [3 * i] & pFAT [3 * i + 1] & pFAT [3 * i + 2]) == 0xff) || ((pFAT [3 * i] | pFAT [3 * i + 1] | pFAT [3 * i + 2]) == 0x00)) FreeClusters++;
    }
  }

  return ((FreeClusters * SectorsPerCluster) >> 11);
}

#endif
