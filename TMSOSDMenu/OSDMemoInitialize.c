#include                <stdlib.h>
#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

void OSDMemoInitialize(bool ScrollLoop, char *TitleLeft, char *TitleRight, char *Text)
{
  TRACEENTER();

  char                 *from, *upto, *p, c;
  int                   Width;
  char                 *Buffer;
  tMenu                *pMenu;

  #define HORSPACE      568

  OSDMenuInitialize(FALSE, FALSE, FALSE, ScrollLoop, TitleLeft, TitleRight);
  pMenu = &Menu[CurrentMenuLevel];
  pMenu->OSDMenuDisplayMode = OMDM_Memo;

  if(!Text || !Text[0])
  {
    TRACEEXIT();
    return;
  }

  Buffer = TAP_MemAlloc(strlen(Text) + 2);
  memset(Buffer, 0, strlen(Text) + 2);
  strcpy(Buffer, Text);
  StrReplace(Buffer, "\x8d", "\r");
  StrReplace(Buffer, "\x8a", "\n");
  StrReplace(Buffer, "\r\n", "\n");
  if(Buffer[strlen(Buffer)] != '\n') strcat(Buffer, "\n");

  from = Buffer;
  upto = from - 1;

  while ((p = strpbrk(upto + 1, " \n")))
  {
    c = *p;
    *p = 0;

    Width = FMUC_GetStringWidth(from, pMenu->FontMemo);

    if (Width > HORSPACE)
    {
      if (upto < from) upto = p;

      *upto = 0;
      OSDMenuItemAdd(from, NULL, NULL, NULL, TRUE, FALSE, 0);
      from = upto + 1;
    }
    else
    {
      if (c == '\n')
      {
        OSDMenuItemAdd(*from ? from : " ", NULL, NULL, NULL, TRUE, FALSE, 0);
        from = p + 1;
      }

      upto = p;
    }

    *p = c;
  }

  TAP_MemFree(Buffer);

  TRACEEXIT();
}
