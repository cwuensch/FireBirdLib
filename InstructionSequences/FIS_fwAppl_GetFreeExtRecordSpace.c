#include "../libFireBird.h"

inline dword FIS_fwAppl_GetFreeExtRecordSpace(void)
{
  static dword          _Appl_GetFreeExtRecordSpace = 0;

  if (!_Appl_GetFreeExtRecordSpace)
    _Appl_GetFreeExtRecordSpace = TryResolve("_Z26Appl_GetFreeExtRecordSpacePc");

  return _Appl_GetFreeExtRecordSpace;
}
