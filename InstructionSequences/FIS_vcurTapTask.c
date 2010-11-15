#include "../libFireBird.h"

inline dword FIS_vcurTapTask(void)
{
  static dword          *vcurTapTask = NULL;

  if(!vcurTapTask) vcurTapTask = (dword*)TryResolve("_curTapTask");
  return (dword)vcurTapTask;
}
