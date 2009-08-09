#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vTAP_Vfd_Control (void)
{
  dword                *p, gp;
  static dword          vTAP_Vfd_Control = 0;

  if (!vTAP_Vfd_Control)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    p = (dword*)TAP_Vfd_Control;
    while (*p != JR_RA_CMD)
    {
      if ((*p & 0xffff0000) == 0xa3840000)
      {
        vTAP_Vfd_Control = gp + (short)(*p & 0xffff);
        break;
      }
      p++;
    }
  }

  return vTAP_Vfd_Control;
}

#endif
