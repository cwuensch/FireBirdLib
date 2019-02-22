#include                <stdlib.h>
#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

void OSDMemoInitialize(bool ScrollLoop, char *TitleLeft, char *TitleRight, char *Text)
{
  TRACEENTER();

  char                 *from, *upto, *p, c;
  dword                 spW, Width = 0;
  tMenu                *pMenu;

  #define HORSPACE      568

  OSDMenuInitialize(FALSE, FALSE, FALSE, ScrollLoop, TitleLeft, TitleRight);
  pMenu = &Menu[CurrentMenuLevel];
  pMenu->OSDMenuDisplayMode = OMDM_Memo;
  pMenu->NrLines = 15;

  if(!Text || !Text[0])
  {
    TRACEEXIT();
    return;
  }

  pMenu->MemoText = TAP_MemAlloc(strlen(Text) + 2);
  memset(pMenu->MemoText, 0, strlen(Text) + 2);
  strcpy(pMenu->MemoText, Text);
  StrReplace(pMenu->MemoText, "\x8d", "\r");
  StrReplace(pMenu->MemoText, "\x8a", "\n");
  StrReplace(pMenu->MemoText, "\r\n", "\n");
  if (pMenu->MemoText[strlen(pMenu->MemoText) - 1] != '\n') strcat(pMenu->MemoText, "\n");

  spW = FMUC_GetStringWidth(" ", pMenu->FontMemo);

  from = pMenu->MemoText;
  upto = from - 1;

  while ((p = strpbrk(upto + 1, " \n")))
  {
    c = *p;
    *p = 0;

    Width += FMUC_GetStringWidth(upto + 1, pMenu->FontMemo) + (c == ' ' ? spW : 0);

    if (Width > HORSPACE)
    {
      if (upto < from) upto = p;

      *upto = 0;
      OSDMenuItemAdd(from, NULL, NULL, NULL, TRUE, FALSE, 0);
      from = upto + 1;
      Width = 0;
    }
    else
    {
      if (c == '\n')
      {
        OSDMenuItemAdd(*from ? from : " ", NULL, NULL, NULL, TRUE, FALSE, 0);
        from = p + 1;
        Width = 0;
      }

      upto = p;
    }

    *p = c;
  }

  TRACEEXIT();
}
