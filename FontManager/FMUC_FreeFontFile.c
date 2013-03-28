#include                "FBLib_FontManager.h"

void FMUC_FreeFontFile(tFontDataUC *FontData)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("FMUC_FreeFontFile");
  #endif

  dword     i;

  if(FontData)
  {
    for(i = 0; i < FontData->GlyphCacheEntries; i++)
      if(FontData->GlyphCache[i].GlyphData) TAP_MemFree(FontData->GlyphCache[i].GlyphData);

    if(FontData->GlyphCache) TAP_MemFree(FontData->GlyphCache);
    if(FontData->FontDef) TAP_MemFree(FontData->FontDef);
    if(FontData->FileHandle) TAP_Hdd_Fclose(FontData->FileHandle);

    memset(FontData, 0, sizeof(tFontDataUC));
  }

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif
}
