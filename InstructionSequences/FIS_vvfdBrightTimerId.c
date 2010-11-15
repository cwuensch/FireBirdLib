#include "../libFireBird.h"

inline dword FIS_vvfdBrightTimerId(void)
{
  static dword          _vfdBrightTimerId = 0;

  if (!_vfdBrightTimerId)
    _vfdBrightTimerId = TryResolve("_vfdBrightTimerId");

  return _vfdBrightTimerId;
}
