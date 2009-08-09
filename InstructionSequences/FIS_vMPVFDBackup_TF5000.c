#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vMPVFDBackup (void)
{
  static dword          vMPVFDBackup = 0;
  dword                 p;

  if (!vMPVFDBackup)
  {
    p = FIS_vMPVFD();
    if (p) vMPVFDBackup = p + 48;
  }

  return vMPVFDBackup;
}

#endif
