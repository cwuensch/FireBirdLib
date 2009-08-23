#include                "FBLib_tmsvfd.h"

#ifdef _TMS_

bool VFD_Clear(void)
{
  byte *grid = (byte*)FIS_vgrid();

  if(!VFDUsedByTAP || !grid) return FALSE;

  memset(grid, 0, 48);

  return TRUE;
}

#endif
