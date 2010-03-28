#include "../libFireBird.h"

#ifdef _TMS_

dword UTCtoLocal(dword UTCTime)
{
  static dword (*Appl_TimeToLocal)(dword) = NULL;


  if(!Appl_TimeToLocal)
  {
    Appl_TimeToLocal = (void*)TryResolve("_Z16Appl_TimeToLocalj");
    if(!Appl_TimeToLocal) return 0;
  }


  return Appl_TimeToLocal(UTCTime);
}

#endif
