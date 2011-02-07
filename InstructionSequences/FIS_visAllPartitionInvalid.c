#include "../libFireBird.h"

inline dword FIS_visAllPartitionInvalid(void)
{
  static dword          visAllPartitionInvalid = 0;

  if(!visAllPartitionInvalid) visAllPartitionInvalid = (dword)TryResolve("_isAllPartitionInvalid");

  return visAllPartitionInvalid;
}
