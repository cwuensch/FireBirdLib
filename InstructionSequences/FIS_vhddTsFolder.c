#include "../libFireBird.h"

inline dword FIS_vhddTsFolder(void)
{
  static dword          _hddTsFolder = 0;

  if (!_hddTsFolder)
    _hddTsFolder = TryResolve("_hddTsFolder");

  return _hddTsFolder;
}
