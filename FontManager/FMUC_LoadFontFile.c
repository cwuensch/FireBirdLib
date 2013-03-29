#include                <string.h>
#include                "FBLib_FontManager.h"

bool FMUC_LoadFontFile(const char *FontFileName, tFontDataUC *FontData)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("FMUC_LoadFontFile");
  #endif

  char                  Hdr[5];

  if(!FontFileName || !FontFileName[0] || !FontData)
  {
    #ifdef DEBUG_FIREBIRDLIB
      CallTraceExit(NULL);
    #endif

    return FALSE;
  }

  //Initialize the struct
  memset(FontData, 0, sizeof(tFontDataUC));

  //Open the font file
  HDD_TAP_PushDir();
  HDD_ChangeDir(FONTSDIR);

  if(!TAP_Hdd_Exist(FontFileName))
  {
    TAP_PrintNet("FontManager UC: font file '%s' does not exist\n", FontFileName);
    HDD_TAP_PopDir();

    #ifdef DEBUG_FIREBIRDLIB
      CallTraceExit(NULL);
    #endif

    return FALSE;
  }

  FontData->FileHandle = TAP_Hdd_Fopen(FontFileName);
  HDD_TAP_PopDir();
  if(FontData->FileHandle == NULL)
  {
    TAP_PrintNet("FontManager UC: failed to open '%s'\n", FontFileName);

    #ifdef DEBUG_FIREBIRDLIB
      CallTraceExit(NULL);
    #endif

    return FALSE;
  }

  //Check the header
  TAP_Hdd_Fread(Hdr, 4, 1, FontData->FileHandle);
  Hdr[4] = '\0';
  if(strcmp(Hdr, "UFNT"))
  {
    TAP_Hdd_Fclose(FontData->FileHandle);
    FontData->FileHandle = NULL;
    TAP_PrintNet("FontManager UC: '%s' has invalid header\n", FontFileName);

    #ifdef DEBUG_FIREBIRDLIB
      CallTraceExit(NULL);
    #endif

    return FALSE;
  }

  //Read the size of the FontDef table and allocate the necessary memory
  TAP_Hdd_Fread(&FontData->FontDefEntries, sizeof(dword), 1, FontData->FileHandle);
  FontData->FontDef = TAP_MemAlloc(FontData->FontDefEntries * sizeof(tFontDefUC));
  if(FontData->FontDef == NULL)
  {
    TAP_Hdd_Fclose(FontData->FileHandle);
    FontData->FileHandle = NULL;
    TAP_PrintNet("FontManager UC: failed to allocate %d bytes for the FontDef table of '%s'\n", FontData->FontDefEntries * sizeof(tFontDefUC), FontFileName);

    #ifdef DEBUG_FIREBIRDLIB
      CallTraceExit(NULL);
    #endif

    return FALSE;
  }

  //TAP_PrintNet("FontManager UC: %d glyphs available in '%s'\n", FontData->FontDefEntries, FontFileName);

  //Read the FontDef table
  TAP_Hdd_Fread(FontData->FontDef, sizeof(tFontDefUC), FontData->FontDefEntries, FontData->FileHandle);

  //Reserve memory for the font cache
  FontData->GlyphCacheEntries = 0;
  FontData->GlyphCache = TAP_MemAlloc(FontData->FontDefEntries * sizeof(tGlyphCacheUC));
  if(FontData->GlyphCache == NULL)
  {
    TAP_PrintNet("FontManager UC: failed to allocate %d bytes for the FontCache table of '%s'\n", FontData->FontDefEntries * sizeof(tGlyphCacheUC), FontFileName);

    #ifdef DEBUG_FIREBIRDLIB
      CallTraceExit(NULL);
    #endif

    return FALSE;
  }

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return TRUE;
}
