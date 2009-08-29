#include                <string.h>
#include                "FBLib_tmsvfd.h"

#ifdef _TMS_

bool HDDEnabled = FALSE;

bool VFD_EnableHDD(bool Enable)
{
  byte *grid = (byte*)FIS_vgrid();

  if(!VFDUsedByTAP || !grid) return FALSE;

  grid[29] &= 0x1f;
  grid[28] &= 0x80;

  if(Enable)
    grid[28] |= 0x20;

  HDDEnabled = Enable;

  return TRUE;
}

#endif
