#include                <string.h>
#include                "FBLib_FontManager.h"

#ifdef _TMS_

dword FM_GetStringHeight(const char *Text, tFontData *FontData)
{
  dword                 i;
  dword                 h, Height = 0;

  if(!Text || !Text[0] || !FontData || !FontData->pFontData) return 0;

  for(i = 0; i < strlen(Text); i++)
  {
    if(FM_isValidCharacter(Text[i]))
    {
      h = FontData->FontDef[FM_CharToIndex(Text[i])].Height;
      if(h > Height) Height = h;
    }
  }

  return Height;
}

#endif