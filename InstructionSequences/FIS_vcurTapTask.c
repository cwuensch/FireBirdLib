#include "../libFireBird.h"

#ifdef _TMS_

inline dword FIS_vcurTapTask(void)
{
  static dword          *vcurTapTask = NULL;

  if(!vcurTapTask) vcurTapTask = (dword*)TryResolve("_curTapTask");
  return (dword)vcurTapTask;

#endif

}
