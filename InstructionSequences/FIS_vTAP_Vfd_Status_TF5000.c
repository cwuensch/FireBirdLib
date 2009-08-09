#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vTAP_Vfd_Status (void)
{
  dword                *p, gp;
  static dword          vTAP_Vfd_Status = 0;

  if (!vTAP_Vfd_Status)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    p = (dword*)TAP_Vfd_GetStatus;
    while (*p != JR_RA_CMD)
    {
      if ((*p & 0xffff0000) == 0x93840000)
      {
        vTAP_Vfd_Status = gp + (short)(*p & 0xffff);
        break;
      }
      p++;
    }
  }

  return vTAP_Vfd_Status;
}

#endif
