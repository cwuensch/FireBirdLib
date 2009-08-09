#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vSysOsdControl (void)
{
  static dword          vSysOsdControl = 0;
  dword                *p, gp;

  if (!vSysOsdControl)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    //We're looking for the first "sb x($gp)" after TAP_SysOsdControl

    p = (dword*)TAP_SysOsdControl;
    while (((dword)(p) < 0x80400000) && ((*p & 0xffe00000) != 0xa3800000)) p++;

    if ((*p & 0xffe00000) != 0xa3800000) return 0;

    vSysOsdControl = (gp + (short)(*p & 0xffff));
  }

  return vSysOsdControl;
}

#endif
