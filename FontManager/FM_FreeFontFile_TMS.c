#include                "FBLib_FontManager.h"

#ifdef _TMS_

void FM_FreeFontFile(tFontData *FontData)
{
  if(FontData->pFontData)
  {
    TAP_MemFree(FontData->pFontData);
  }
  memset(FontData, 0, sizeof(tFontData));
}

#endif
