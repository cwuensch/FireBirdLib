#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

void OSDMenuModifyTitleRight(const char *Text)
{
  TRACEENTER();

  tMenu                *pMenu;

  if(!Text)
  {
    TRACEEXIT();
    return;
  }

  pMenu = &Menu[CurrentMenuLevel];

  strncpy(pMenu->TitleRight, Text, STDSTRINGSIZE);
  pMenu->TitleRight[STDSTRINGSIZE - 1] = '\0';
  TitleDirty = TRUE;

  TRACEEXIT();
}
