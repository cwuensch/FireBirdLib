#include                <stdio.h>
#include                <string.h>
#include                "FBLib_TMSOSDKeyboard.h"

static bool SaveDictToFile()
{
  FILE                 *f = NULL;
  int                   i;

  TRACEENTER();

  if ((f = fopen(DICTIONARYPATH, "wb")) != NULL)
  {
    for (i = 0; i < Keyb_DictNrEntries; i++)
    {
//      fputs(&Keyb_DictHeap[Keyb_Dictionary[i]], f);
      fwrite(&Keyb_DictHeap[Keyb_Dictionary[i]], strlen(&Keyb_DictHeap[Keyb_Dictionary[i]]), 1, f);
      fwrite("\r\n", 2, 1, f);
    }
    fclose(f);
    TRACEEXIT();
    return TRUE;
  }

  TRACEEXIT();
  return FALSE;
}

void OSDKeyboard_Destroy(void)
{
  TRACEENTER();
  if(OSDKeyboard_rgn)
  {
    USBKeyboardRedirect(FALSE, FALSE);
    OSDKeyboard_TMSRemoteDirectMode(FALSE);

    if (OSDKeyboard_SaveDict)
      SaveDictToFile();

    TAP_MemFree(OSDKeyboard_Title);
    OSDKeyboard_Title = NULL;
    TAP_MemFree(OSDKeyboard_StringVar);
    OSDKeyboard_StringVar = NULL;
    OSDKeyboard_StringVarOrig = NULL;

    // Dictionary und Clipboard werden absichtlich nicht freigegeben!

#ifdef FB_USE_UNICODE_OSD
    OSDMenuFreeStdFonts();
#endif

    TAP_Osd_Delete(OSDKeyboard_rgn);
    OSDKeyboard_rgn = 0;
    if(OSDKeyboard_ReturnToNormal) TAP_EnterNormalNoInfo();
  }
  TRACEEXIT();
}
