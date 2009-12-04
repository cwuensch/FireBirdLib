#include                <string.h>
#include                "FBLib_tmsvfd.h"

#ifdef _TMS_

bool CDEnabled = FALSE;

bool VFD_EnableCD(bool Enable)
{
  byte *grid = (byte*)FIS_vgrid();

  if(!VFDUsedByTAP || !grid) return FALSE;

  if(CDEnabledAnimation) VFD_EnableCDAnimation(FALSE);

  grid[25] &= 0xfc;
  grid[26]  = 0x00;
  grid[27] &= 0x1f;

  if(Enable)
    grid[25] |= 0x02;

  CDEnabled = Enable;

  return TRUE;
}

#endif
