#include                "FBLib_TMSOSDMenu.h"

void OSDDrawList(void)
{
  int                   i;
  dword                 XStart, XEnd, Y;
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
    if(pMenu->Item[i].ColorPatch && (MaxValueIconWidth < 50)) MaxValueIconWidth = 50;
  }

  if(MaxNameIconWidth) MaxNameIconWidth += 8;
  if(MaxValueIconWidth) MaxValueIconWidth += 8;

  //The background
  TAP_Osd_Draw3dBoxFill(OSDRgn, 60, 96, 600, 367, RGB(30, 30, 30), RGB(30, 30, 30), RGB(30, 30, 30));

  for(i = 0; i < 10; i++)
  {
    //Draw the background or selection bar and the optional value arrows
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
      ItemColor = pMenu->Item[i + pMenu->CurrentTopIndex].TextColor;
    else
      ItemColor = RGB(128, 128, 140);

    //Line numbers
    if(pMenu->NumberedItems)
    {
      int MaxX = 100;

      XStart = 101;
      TAP_SPrint(s, "%2.2d", i + pMenu->CurrentTopIndex + 1);
      if(i + pMenu->CurrentTopIndex + 1 > 99)
      {
        XStart += 10;
        MaxX += 10;
      }
      if(i + pMenu->CurrentTopIndex + 1 > 999)
      {
        XStart += 10;
        MaxX += 10;
      }
      OSDMenuPutS(OSDRgn, 71, Y + 5, MaxX, s, ItemColor, COLOR_None, 14, FALSE, ALIGN_LEFT);
    }
    else
    {
      XStart = 76;
    }

    //Icons on the left column
    if(pMenu->Item[i + pMenu->CurrentTopIndex].pNameIconGd)
      TAP_Osd_PutGd(OSDRgn, XStart, Y + 13 - (pMenu->Item[i + pMenu->CurrentTopIndex].pNameIconGd->height >> 1), pMenu->Item[i + pMenu->CurrentTopIndex].pNameIconGd, TRUE);

    //The text of the left column
    OSDMenuPutS(OSDRgn, XStart + MaxNameIconWidth, Y + 5, XEnd, pMenu->Item[i + pMenu->CurrentTopIndex].Name, ItemColor, COLOR_None, 14, TRUE, ALIGN_LEFT);

    if(pMenu->HasValueColumn)
    {
      //The text of the right column
      OSDMenuPutS(OSDRgn, pMenu->ValueXPos + 45 + MaxValueIconWidth, Y + 5, 645, pMenu->Item[i + pMenu->CurrentTopIndex].Value, ItemColor, COLOR_None, 14, TRUE, ALIGN_LEFT);

      //The color patch or icon of the right column. The former has priority
      if(pMenu->Item[i + pMenu->CurrentTopIndex].ColorPatch)
      {
        TAP_Osd_FillBox(OSDRgn, pMenu->ValueXPos + 45, Y + 5, 50, 18, (pMenu->Item[i + pMenu->CurrentTopIndex].ColorPatch & 0x00ffffff) | 0xff000000);
        TAP_Osd_DrawRectangle(OSDRgn, pMenu->ValueXPos + 45, Y + 5, 50, 18, 1, RGB(192,192,192));
      }
      else
      {
        if(pMenu->Item[i + pMenu->CurrentTopIndex].pValueIconGd)
          TAP_Osd_PutGd(OSDRgn, pMenu->ValueXPos + 45 , Y + 13 - (pMenu->Item[i + pMenu->CurrentTopIndex].pValueIconGd->height >> 1), pMenu->Item[i + pMenu->CurrentTopIndex].pValueIconGd, TRUE);
      }
    }
  }

  if(CallbackProcedure) CallbackProcedure(OSDCB_List, OSDRgn);
}
