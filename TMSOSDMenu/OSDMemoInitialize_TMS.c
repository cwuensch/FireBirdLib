#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMemoInitialize(bool ScrollLoop, char *TitleLeft, char *TitleRight, char *Text)
{
  char                 *from, *to, *p, c;
  int                   Width;
  char                 *Buffer;

#define HORSPACE        560

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
    p = strpbrk(to, " \n");

    if(p == NULL)
    {
      //Nothing has been found, terminate
      //if from != to
      break;
    }
    else if(p == to)
    {
      //if p points to a LF then add an empty line, else ignore
      if(*p == '\n')
      {
        from = p + 1;
        OSDMenuItemAdd(" ", NULL, NULL, NULL, TRUE, FALSE, 0);
      }
      to = p + 1;
    }
    else if(*p == '\n')
    {
      //We've found a LF; print the line
      *p = '\0';
      Width = FM_GetStringWidth(from, &Calibri_14_FontData);
      if(Width < HORSPACE)
      {
        //Everything fits into a single line; print it
        OSDMenuItemAdd(from, NULL, NULL, NULL, TRUE, FALSE, 0);
      }
      else
      {
        //We need to break it into 2 separate lines (from-to, to-p)
        *(to - 1) = '\0';
        OSDMenuItemAdd(from, NULL, NULL, NULL, TRUE, FALSE, 0);
        OSDMenuItemAdd(to, NULL, NULL, NULL, TRUE, FALSE, 0);
      }
      from = p + 1;
      to = from;
    }
    else
    {
      //We've found a SPACE. Check the width
      c = *p;
      *p = 0;
      Width = FM_GetStringWidth(from, &Calibri_14_FontData);

      if(Width < HORSPACE)
      {
        //Still within the available space
        to = p + 1;
      }
      else
      {
        //Needs too much space. Print from-to and advance pointers
        *(to - 1) = 0;
        OSDMenuItemAdd(from, NULL, NULL, NULL, TRUE, FALSE, 0);
        from = to;
      }
      *p = c;
    }
  }
  TAP_MemFree(Buffer);
}

#endif
