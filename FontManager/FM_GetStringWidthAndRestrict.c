#include                <string.h>
#include                "FBLib_FontManager.h"

dword FM_GetStringWidthAndRestrict(char *Text, tFontData *FontData, int MaxWidth, bool *pbRestricted)
{
  dword                 i;
  int                   Width = 0;

  if(pbRestricted) *pbRestricted = FALSE;
  if(!Text || !Text[0] || !FontData || !FontData->pFontData) return 0;

  for(i = 0; i < strlen(Text); i++)
  {
    if(FM_isValidCharacter(Text[i]))
      Width += FontData->FontDef[FM_CharToIndex(Text[i])].Width;
    if(Width > MaxWidth)
    {
      Width -= FontData->FontDef[FM_CharToIndex(Text[i])].Width;
      Text[i] = 0;
      if(pbRestricted) *pbRestricted = TRUE;
      break;
    }
  }

  return Width;
}