#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

void OSDMenuMessageBoxShow(void)
{
  dword                 x, y, dx, dy, i;
  char                 *pText;
  char                 *EndOfText;
  dword                 Lines;
  char                  s[256];
  TYPE_GrData          *MB;

  if(MessageBox.NrButtons == 0) return;

  MB = &_MessageBoxSelectedButtonBackground_Gd;

  if(!MessageBoxOSDRgn)
  {
    x = (720 - _InfoBox_Gd.width) >> 1;
    y = (576 - _InfoBox_Gd.height) >> 1;
    MessageBoxOSDRgn = TAP_Osd_Create(x, y, _InfoBox_Gd.width, _InfoBox_Gd.height, 0, 0);
    TAP_ExitNormal();
  }
  TAP_Osd_PutGd(MessageBoxOSDRgn, 0, 0, &_InfoBox_Gd, FALSE);

  OSDMenuPutS(MessageBoxOSDRgn, 0, 10, 380, MessageBox.Title, RGB(232,146,17), COLOR_None, 14, FALSE, ALIGN_CENTER);

  //Count the number of lines
  strncpy(s, MessageBox.Text, 256);
  s[255] = '\0';
  pText = s;
  EndOfText = s + strlen(s);
  Lines = 0;
  while(pText < EndOfText)
  {
    Lines++;
    pText = strpbrk(pText, "\x0d\x0a");
    if(!pText) break;
    *pText = '\0';
    pText++;
  }

  dy = 20;
  y = 38 - 10 * (Lines - 1);
  pText = s;
  for(i = 0; i < Lines; i++)
  {
    OSDMenuPutS(MessageBoxOSDRgn, 0, y - 7 + 36, 380, pText, RGB(192,192,192), COLOR_None, 14, FALSE, ALIGN_CENTER);
    y += dy;
    pText += (strlen(pText) + 1);
  }

  dx = _InfoBox_Gd.width / (MessageBox.NrButtons + 1);
  x = dx;
  for(i = 0; i < MessageBox.NrButtons; i++)
  {
    if(i == MessageBox.CurrentButton)
    {
      TAP_Osd_PutGd(MessageBoxOSDRgn, x - (MB->width >> 1), 120, MB, FALSE);
      OSDMenuPutS(MessageBoxOSDRgn, x - (MB->width >> 1), 124, x + (MB->width >> 1), MessageBox.Button[i], RGB(40,40,40), COLOR_None, 14, FALSE, ALIGN_CENTER);
    }
    else
    {
      TAP_Osd_FillBox(MessageBoxOSDRgn, x - (MB->width >> 1), 120, MB->width, MB->height, RGB(36,36,36));
      OSDMenuPutS(MessageBoxOSDRgn, x - (MB->width >> 1), 124, x + (MB->width >> 1), MessageBox.Button[i], RGB(230,230,250), COLOR_None, 14, FALSE, ALIGN_CENTER);
    }
    x += dx;
  }

  TAP_Osd_Sync();
}
