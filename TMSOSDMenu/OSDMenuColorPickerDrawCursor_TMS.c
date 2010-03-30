#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuColorPickerDrawCursor(tCurrentColorSelected CursorColor, tColorPickerCursor CursorType)
{
  int                  y = 0, CurrentX = 0, NewX = 0, TextY = 0;
  char                 s[24];

#define CURSORXOFFET   8

  if(ColorPickerOSDRgn)
  {
    switch(CursorColor)
    {
      case CCS_Red:
      {
        y = 56;
        TextY = 44;
        CurrentX = ColorPickerLastCursorRed;
        NewX = ((ColorPickerColor >> 16) & 0xff) + CURSORXOFFET;
        ColorPickerLastCursorRed = NewX;
        break;
      }

      case CCS_Green:
      {
        y = 78;
        TextY =66;
        CurrentX = ColorPickerLastCursorGreen;
        NewX = ((ColorPickerColor >> 8) & 0xff) + CURSORXOFFET;
        ColorPickerLastCursorGreen = NewX;
        break;
      }

      case CCS_Blue:
      {
        y = 100;
        TextY = 88;
        CurrentX = ColorPickerLastCursorBlue;
        NewX = (ColorPickerColor & 0xff) + CURSORXOFFET;
        ColorPickerLastCursorBlue = NewX;
        break;
      }
    }

    if (CurrentX > -1)TAP_Osd_PutGd(ColorPickerOSDRgn, CurrentX , y, &_ColorPicker_CursorNone_Gd, FALSE);
    switch(CursorType)
    {
      case CPC_None:
      {
        TAP_Osd_PutGd(ColorPickerOSDRgn, NewX , y, &_ColorPicker_CursorNone_Gd, FALSE);
        break;
      }

      case CPC_Deselected:
      {
        TAP_Osd_PutGd(ColorPickerOSDRgn, NewX , y, &_ColorPicker_CursorDeselected_Gd, FALSE);
        break;
      }

      case CPC_Selected:
      {
        TAP_Osd_PutGd(ColorPickerOSDRgn, NewX , y, &_ColorPicker_CursorSelected_Gd, FALSE);
        break;
      }
    }

    TAP_SPrint(s, "%d", NewX - CURSORXOFFET);
    TAP_Osd_FillBox(ColorPickerOSDRgn, 280, TextY, 50, 12, RGB(40,40,40));
    OSDMenuPutS(ColorPickerOSDRgn, 280, TextY, 350, s, RGB(192,192,192), COLOR_None, 12, FALSE, ALIGN_LEFT);

    TAP_Osd_FillBox(ColorPickerOSDRgn, 211, 116, 60, 18, ColorPickerColor | 0xff000000);
    TAP_Osd_DrawRectangle(ColorPickerOSDRgn, 211, 116, 60, 18, 1, RGB(192,192,192));
  }
}

#endif
