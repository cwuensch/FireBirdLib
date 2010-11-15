#include "../libFireBird.h"

inline dword FIS_viboxTimerId(void)
{
  static byte   *iboxTimerId = NULL;

  if(!iboxTimerId) iboxTimerId = (byte*)TryResolve("_iboxTimerId");

  return (dword)iboxTimerId;
}
