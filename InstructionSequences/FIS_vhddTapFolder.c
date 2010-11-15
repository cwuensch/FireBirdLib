#include "../libFireBird.h"

inline dword FIS_vhddTapFolder(void)
{
  static dword          _hddTapFolder = 0;

  if (!_hddTapFolder)
    _hddTapFolder = TryResolve("_hddTapFolder");

  return _hddTapFolder;
}
