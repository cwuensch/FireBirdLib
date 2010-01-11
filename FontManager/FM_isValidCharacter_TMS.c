#include                "FBLib_FontManager.h"

#ifdef _TMS_

bool FM_isValidCharacter(byte Char)
{
  if(Char < 0x20) return FALSE;
  if((Char > 0x7e) && (Char < 0xa0)) return FALSE;

  return TRUE;
}

#endif
