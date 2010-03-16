#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDDrawList(void)
{
  int                   i;
  dword                 XStart, XEnd, Y;
  int                   LastIndex;
  tMenu                *pMenu;
  dword                 ItemColor;
  char                  s[4];
  dword                 MaxNameIconWidth, MaxValueIconWidth;

  pMenu = &Menu[CurrentMenuLevel];

  //Get maximum width of icons
  MaxNameIconWidth = 0;
  MaxValueIconWidth = 0;
  for(i = 0; i < pMenu->NrItems; i++)
  {
    if(pMenu->Item[i].pNameIconGd && (pMenu->Item[i].pNameIconGd->width > MaxNameIconWidth)) MaxNameIconWidth = pMenu->Item[i].pNameIconGd->width;
    if(pMenu->Item[i].pValueIconGd && (pMenu->Item[i].pValueIconGd->width > MaxValueIconWidth)) MaxValueIconWidth = pMenu->Item[i].pValueIconGd->width;
  }

  TAP_Osd_Draw3dBoxFill(OSDRgn, 60, 96, 600, 367, RGB(30, 30, 30), RGB(30, 30, 30), RGB(30, 30, 30));

  LastIndex = pMenu->NrItems + pMenu->CurrentTopIndex;
  if(LastIndex >= 10) LastIndex = 10;

  for(i = 0; i < 10; i++)
  {
    if((i + pMenu->CurrentTopIndex) == pMenu->CurrentSelection)
    {
      TAP_Osd_PutGd(OSDRgn,  60 , 95 + (i * 37), &_Selection_Bar_Gd, FALSE);
      if(pMenu->HasValueColumn && pMenu->Item[i + pMenu->CurrentTopIndex].ValueArrows)
      {
        TAP_Osd_PutGd(OSDRgn, pMenu->ValueXPos + 20 , 95 + 10 +(i * 37), &_pfeil_lGd, FALSE);
        TAP_Osd_PutGd(OSDRgn, 640 , 95 + 10 +(i * 37), &_pfeil_rGd, FALSE);
      }
    }
    else
    {
      TAP_Osd_DrawRectangle(OSDRgn, 60, 130 + (i * 37), 600, 2, 1, RGB(16, 16, 16));
    }

    XEnd = (pMenu->HasValueColumn ? pMenu->ValueXPos : 645);
    Y = 99 + (i * 37);

    if(pMenu->Item[i + pMenu->CurrentTopIndex].Selectable)
      ItemColor = RGB(255, 255, 255);
    else
      ItemColor = RGB(128, 128, 140);

    if(pMenu->NumberedItems)
    {
      XStart = 101;
      TAP_SPrint(s, "%2.2d", i + pMenu->CurrentTopIndex + 1);
      OSDMenuPutS(OSDRgn, 71, Y + 5, 100, s, ItemColor, COLOR_None, 14, FALSE, ALIGN_LEFT);
    }
    else
    {
      XStart = 76;
    }

    if(pMenu->Item[i + pMenu->CurrentTopIndex].pNameIconGd)
      TAP_Osd_PutGd(OSDRgn, XStart, Y + 13 - (pMenu->Item[i + pMenu->CurrentTopIndex].pNameIconGd->height >> 1), pMenu->Item[i + pMenu->CurrentTopIndex].pNameIconGd, TRUE);

    OSDMenuPutS(OSDRgn, XStart + MaxNameIconWidth, Y + 5, XEnd, pMenu->Item[i + pMenu->CurrentTopIndex].Name, ItemColor, COLOR_None, 14, TRUE, ALIGN_LEFT);

    if(pMenu->HasValueColumn)
    {
      OSDMenuPutS(OSDRgn, pMenu->ValueXPos + 45 + MaxValueIconWidth, Y + 5, 645, pMenu->Item[i + pMenu->CurrentTopIndex].Value, ItemColor, COLOR_None, 14, TRUE, ALIGN_LEFT);
      if(pMenu->Item[i + pMenu->CurrentTopIndex].pValueIconGd)
        TAP_Osd_PutGd(OSDRgn, pMenu->ValueXPos + 45 , Y + 13 - (pMenu->Item[i + pMenu->CurrentTopIndex].pValueIconGd->height >> 1), pMenu->Item[i + pMenu->CurrentTopIndex].pValueIconGd, TRUE);
    }
  }
}

#endif
