#include "../libFireBird.h"

#ifdef _TMS_

inline dword FIS_vgrid(void)
{
  static dword          _grid = 0;

  if (!_grid)
    _grid = TryResolve("_grid");

  return _grid;
}

#endif