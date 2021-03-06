#include                "FBLib_TMSOSDMenu.h"

bool OSDColorPickerEvent(word *event, dword *param1, dword *param2)
{
  TRACEENTER();

  (void) param2;

  if(ColorPickerOSDRgn)
  {
    if(event && param1 && (*event == EVT_KEY))
    {
      switch(*param1)
      {
        case RKEY_Red:
        {
          if(CurrentColorSelected != CCS_Red)
          {
            OSDMenuColorPickerDrawCursor(CCS_Red, TRUE);
            OSDMenuColorPickerDrawCursor(CurrentColorSelected, FALSE);
            CurrentColorSelected = CCS_Red;
            TAP_Osd_Sync();
          }

          *param1 = 0;
          break;
        }

        case RKEY_Green:
        {
          if(CurrentColorSelected != CCS_Green)
          {
            OSDMenuColorPickerDrawCursor(CCS_Green, TRUE);
            OSDMenuColorPickerDrawCursor(CurrentColorSelected, FALSE);
            CurrentColorSelected = CCS_Green;
            TAP_Osd_Sync();
          }

          *param1 = 0;
          break;
        }

        case RKEY_Blue:
        {
          if(CurrentColorSelected != CCS_Blue)
          {
            OSDMenuColorPickerDrawCursor(CCS_Blue, TRUE);
            OSDMenuColorPickerDrawCursor(CurrentColorSelected, FALSE);
            CurrentColorSelected = CCS_Blue;
            TAP_Osd_Sync();
          }

          *param1 = 0;
          break;
        }

        case RKEY_Down:
        {
          int Color = 0;

          switch(CurrentColorSelected)
          {
            case CCS_Red:   Color = (ColorPickerColor >> 16) & 0xff; break;
            case CCS_Green: Color = (ColorPickerColor >>  8) & 0xff; break;
            case CCS_Blue:  Color =  ColorPickerColor        & 0xff; break;
          }

          Color -= 10;
          if(Color < 0x00) Color = 0x00;
          switch(CurrentColorSelected)
          {
            case CCS_Red:   ColorPickerColor = (ColorPickerColor & 0xff00ffff) | (Color << 16); break;
            case CCS_Green: ColorPickerColor = (ColorPickerColor & 0xffff00ff) | (Color <<  8); break;
            case CCS_Blue:  ColorPickerColor = (ColorPickerColor & 0xffffff00) |  Color; break;
          }
          OSDMenuColorPickerDrawCursor(CurrentColorSelected, TRUE);
          TAP_Osd_Sync();

          *param1 = 0;
          break;
        }

        case RKEY_Up:
        {
          int Color = 0;

          switch(CurrentColorSelected)
          {
            case CCS_Red:   Color = (ColorPickerColor >> 16) & 0xff; break;
            case CCS_Green: Color = (ColorPickerColor >>  8) & 0xff; break;
            case CCS_Blue:  Color =  ColorPickerColor        & 0xff; break;
          }

          Color += 10;
          if(Color > 0xff) Color = 0xff;
          switch(CurrentColorSelected)
          {
            case CCS_Red:   ColorPickerColor = (ColorPickerColor & 0xff00ffff) | (Color << 16); break;
            case CCS_Green: ColorPickerColor = (ColorPickerColor & 0xffff00ff) | (Color <<  8); break;
            case CCS_Blue:  ColorPickerColor = (ColorPickerColor & 0xffffff00) |  Color; break;
          }
          OSDMenuColorPickerDrawCursor(CurrentColorSelected, TRUE);
          TAP_Osd_Sync();

          *param1 = 0;
          break;
        }

        case RKEY_Right:
        {
          int Color = 0;

          switch(CurrentColorSelected)
          {
            case CCS_Red:   Color = (ColorPickerColor >> 16) & 0xff; break;
            case CCS_Green: Color = (ColorPickerColor >>  8) & 0xff; break;
            case CCS_Blue:  Color =  ColorPickerColor        & 0xff; break;
          }

          if(Color < 0xff)
          {
            Color++;
            switch(CurrentColorSelected)
            {
              case CCS_Red:   ColorPickerColor = (ColorPickerColor & 0xff00ffff) | (Color << 16); break;
              case CCS_Green: ColorPickerColor = (ColorPickerColor & 0xffff00ff) | (Color <<  8); break;
              case CCS_Blue:  ColorPickerColor = (ColorPickerColor & 0xffffff00) |  Color; break;
            }
            OSDMenuColorPickerDrawCursor(CurrentColorSelected, TRUE);
            TAP_Osd_Sync();
          }

          *param1 = 0;
          break;
        }

        case RKEY_Left:
        {
          int Color = 0;

          switch(CurrentColorSelected)
          {
            case CCS_Red:   Color = (ColorPickerColor >> 16) & 0xff; break;
            case CCS_Green: Color = (ColorPickerColor >>  8) & 0xff; break;
            case CCS_Blue:  Color =  ColorPickerColor        & 0xff; break;
          }

          if(Color > 0x00)
          {
            Color--;
            switch(CurrentColorSelected)
            {
              case CCS_Red:   ColorPickerColor = (ColorPickerColor & 0xff00ffff) | (Color << 16); break;
              case CCS_Green: ColorPickerColor = (ColorPickerColor & 0xffff00ff) | (Color <<  8); break;
              case CCS_Blue:  ColorPickerColor = (ColorPickerColor & 0xffffff00) |  Color; break;
            }
            OSDMenuColorPickerDrawCursor(CurrentColorSelected, TRUE);
            TAP_Osd_Sync();
          }

          *param1 = 0;
          break;
        }

        case RKEY_Ok:
        {
          OSDMenuColorPickerDestroy();
          *param1 = 0;
          break;
        }

        case RKEY_Exit:
        {
          ColorPickerColor = ColorPickerDefaultColor;
          OSDMenuColorPickerDestroy();
          *param1 = 0;
          break;
        }
      }

      LastUnprocessedOSDMenuKey = *param1;

      TRACEEXIT();
      return TRUE;
    }

    TRACEEXIT();
    return FALSE;
  }

  TRACEEXIT();
  return FALSE;
}
