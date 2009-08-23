#include "../libFireBird.h"

#ifdef _TMS_

inline dword FIS_fwApplVfdStart(void)
{
  static dword          ApplNewVfd_Start = 0;

  if(!ApplNewVfd_Start)
    ApplNewVfd_Start = TryResolve("_Z16ApplNewVfd_Startv");

  return ApplNewVfd_Start;
}

#endif
