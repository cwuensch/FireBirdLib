#include "../libFireBird.h"

inline dword FIS_vselectedPartition(void)
{
  static dword          vselectedPartition = 0;

  if(!vselectedPartition) vselectedPartition = (dword)TryResolve("_selectedPartition");

  return vselectedPartition;
}
