#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

void OSDMemoInitialize(bool ScrollLoop, char *TitleLeft, char *TitleRight, char *Text)
{
  char                 *from, *to, *p, c;
  int                   Width;
  char                 *Buffer;

#define HORSPACE        550

  OSDMenuInitialize(FALSE, FALSE, FALSE, ScrollLoop, TitleLeft, TitleRight);
  OSDMenuDisplayMode = OMDM_Memo;

  if(!Text || !Text[0]) return;

  Buffer = TAP_MemAlloc(strlen(Text) + 2);
  memset(Buffer, 0, strlen(Text) + 2);
  strcpy(Buffer, Text);
  StrReplace(Buffer, "\x8d", "\r");
  StrReplace(Buffer, "\x8a", "\n");
  StrReplace(Buffer, "\r\n", "\n");
  if(Buffer[strlen(Buffer)] != '\n') strcat(Buffer, "\n");

  from = Buffer;
  to = Buffer;
  while(*from)
  {
    p = strpbrk(to + 1, " \n");

    if(p == NULL)
    {
      //Nothing has been found, terminate
      break;
    }
    else
    {
      if(from > to) to = p;

      c = *p;
      *p = '\0';
      Width = FM_GetStringWidth(from, &Calibri_14_FontData);
      if(Width > HORSPACE)
      {
        *to = '\0';
        OSDMenuItemAdd(from, NULL, NULL, NULL, TRUE, FALSE, 0);
        from = to + 1;
        to = p;
      }
      *p = c;

      if(c == '\n')
      {
        if(from >= to)
        {
          OSDMenuItemAdd(" ", NULL, NULL, NULL, TRUE, FALSE, 0);
        }
        else
        {
          *p = '\0';
          OSDMenuItemAdd(from, NULL, NULL, NULL, TRUE, FALSE, 0);
        }
        from = p + 1;
      }
      to = p;
    }
  }

  TAP_MemFree(Buffer);
}