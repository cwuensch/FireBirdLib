#include "../libFireBird.h"

inline dword FIS_fwAppl_ConvertToValidUTF8Str(void)
{
  static dword          _Appl_ConvertToValidUTF8Str = 0;

  if(!_Appl_ConvertToValidUTF8Str)
  {
    _Appl_ConvertToValidUTF8Str = TryResolve("_Z26Appl_ConvertToValidUTF8StrPhi");
  }

  return _Appl_ConvertToValidUTF8Str;
}
