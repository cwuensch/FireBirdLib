#include                "FBLib_FontManager.h"

bool FM_LoadFontFile(char *FontFileName, tFontData *FontData)
{
  TRACEENTER();

  TYPE_File            *f;
  dword                 GreyScaleSize;
  dword                 i, j, k;

  if(!FontFileName || !FontFileName[0] || !FontData)
  {
    TRACEEXIT();
    return FALSE;
  }

  memset(FontData, 0, sizeof(tFontData));

  if(!TAP_Hdd_Exist(FontFileName))
  {
    char                s[120];
    extern char         __tap_program_name__[MAX_PROGRAM_NAME];

    TAP_SPrint(s, "failed to load %s", FontFileName);
    LogEntryFBLibPrintf(TRUE, "FontManager: %s", s);
    ShowMessageWin(__tap_program_name__, s, "Please install the font", 300);

    TRACEEXIT();
    return FALSE;
  }

  f = TAP_Hdd_Fopen(FontFileName);
  if(f == NULL)
  {
    TRACEEXIT();
    return FALSE;
  }

  TAP_Hdd_Fread(FontData->FontDef, sizeof(tFontDef), 191, f);

  /* Check for normal or compressed bitmap font */
  if(FontData->FontDef[0].BitmapIndex == 0)
  {
    /* Normal font file. Last font table entry defines total size */
    GreyScaleSize = FontData->FontDef[190].Width * FontData->FontDef[190].Height + FontData->FontDef[190].BitmapIndex;
  }
  else
  {

    /* Compressed font file. The first index for a compressed bitmap font
     * is set to the size of the bitmap so we can identify and read the
     * bitmap array, even though that index is logically zero.
     */
    GreyScaleSize = FontData->FontDef[0].BitmapIndex;
  }

  FontData->pFontData = TAP_MemAlloc(GreyScaleSize);

  i = 0;
  j = GreyScaleSize;
  do
  {
    k = j;
    if(k > 32768) k = 32768;
    TAP_Hdd_Fread(&FontData->pFontData[i], k, 1, f);
    i += k;
    j -= k;
  }while(j > 0);

  TAP_Hdd_Fclose(f);

  TRACEEXIT();
  return TRUE;
}
