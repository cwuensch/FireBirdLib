#include                <string.h>
#include                "FBLib_FontManager.h"

void FM_PutStringAA(word rgn, dword x, dword y, dword maxX, const char * str, dword fcolor, dword bcolor, tFontData *FontData, byte bDot, byte align, float AntiAliasFactor)
{
  dword                 XEnd, YEnd;
  dword                *PixelData;
  byte                 *FontBitmap;
  dword                 i, X, Y;
  dword                 CX, CY, CW, CH;
  dword                 SaveBoxX;
  dword                 dotWidth;
  char                  newstr[256];
  int                   width = 0, newstrlen;
  char                  LastChar;
  int                   CharIndex;

  dword                 LastBackgroundPixel = 0;
  byte                  LastForegroundPixel = 0;
  dword                 LastPixel = 0;
  byte                  Grey;
  dword                 StrLen;
  bool                  bRestricted;

  if(!str || !str[0] || !FontData || !FontData->pFontData || (maxX <= x)) return;

  if(GetOSDRegionWidth(rgn) && GetOSDRegionWidth(rgn) <=  maxX) maxX = GetOSDRegionWidth(rgn) - 1;

  strncpy(newstr, str, sizeof(newstr));
  newstr[sizeof(newstr) - 1] = '\0';
  XEnd = x + FM_GetStringWidthAndRestrict(newstr, FontData, maxX-x, &bRestricted);

  if(bRestricted && bDot)
  {
    dotWidth = FM_GetStringWidth("...", FontData);
    newstrlen = strlen(newstr);
    if(newstrlen)
    {
      do
      {
        LastChar = newstr[newstrlen - 1];
        if(FM_isValidCharacter(LastChar))
        {
            width = FontData->FontDef[FM_CharToIndex(LastChar)].Width;
            XEnd -= width;
        }
        newstr[newstrlen - 1]= '\0';
        newstrlen--;
      }while(((XEnd + dotWidth) > maxX) &&
             (width != 0) &&
             (newstrlen > 0));
    }

    switch(bDot)
    {
      case 2:
      {
        int i;

        i = strlen(newstr) - 1;
        newstr[i+4] = '\0';
        while(i >= 0)
        {
          newstr[i] = newstr[i+3];
          i--;
        }
        newstr[0] = '.';
        newstr[1] = '.';
        newstr[2] = '.';

        break;
      }

      default:
      {
        strcat(newstr, "...");
        break;
      }
    }
    XEnd += dotWidth;
    if(XEnd > maxX) return;
  }

  YEnd = y + FM_GetStringHeight(newstr, FontData);
  if(XEnd > maxX) XEnd = maxX;

  switch(align)
  {
    case ALIGN_LEFT:
    {
      SaveBoxX = x;
      break;
    }

    case ALIGN_CENTER:
    {
      SaveBoxX = x + ((maxX - XEnd) >> 1);
      break;
    }

    case ALIGN_RIGHT:
    {
      SaveBoxX = maxX - (XEnd - x);
      break;
    }

    default:
      SaveBoxX = x;
      break;
  }

  if(bcolor & 0xff000000)
  {
    TAP_Osd_FillBox(rgn, x, y, maxX - x, YEnd - y + 1, bcolor);
    FM_InitAlphaLUT(fcolor, bcolor, AntiAliasFactor);
  }

  PixelData = (dword*)TAP_Osd_SaveBox(rgn, SaveBoxX, y, XEnd - x + 1, YEnd - y + 1);

  if(PixelData)
  {
    CX = 0;
    StrLen = strlen(newstr);
    for(i = 0; i < StrLen; i++)
    {
      if(FM_isValidCharacter(newstr[i]))
      {
          CharIndex = FM_CharToIndex(newstr[i]);
          FontBitmap = &FontData->pFontData[FontData->FontDef[CharIndex].BitmapIndex];
          CW = FontData->FontDef[CharIndex].Width;
          CH = FontData->FontDef[CharIndex].Height;

          for(Y = 0; Y < CH; Y++)
          {
              CY = (XEnd - x + 1) * Y;
              for(X = 0; X < CW; X++)
              {
                Grey = *FontBitmap;
                if(Grey != 0x00)
                {
                    if(Grey == 0xff)
                    {
                      PixelData[CX + X + CY] = fcolor;
                    }
                    else
                    {
                        //Verhalten von bcolor.A
                        if(bcolor & 0xff000000)
                        {
                          PixelData[CX + X + CY] = (fcolor & 0xff000000) | (AlphaLUT[Grey].r << 16) | (AlphaLUT[Grey].g << 8) | AlphaLUT[Grey].b;
                        }
                        else
                        {
                          if((LastForegroundPixel != Grey) || (LastBackgroundPixel != PixelData[CX + X + CY]))
                          {
                            LastBackgroundPixel = PixelData[CX + X + CY];
                            LastForegroundPixel = Grey;
                            LastPixel = (fcolor & 0xff000000) | FM_AlphaBlendRGB(Grey, fcolor, LastBackgroundPixel, AntiAliasFactor);
                          }

                          PixelData[CX + X + CY] = LastPixel;
                        }
                    }
                } // if grey else
                FontBitmap++;
              } // for x
          } // for y
          CX += CW;
      } // if FM_ValidChar
    } // for i

    TAP_Osd_RestoreBox(rgn, SaveBoxX, y, XEnd - x + 1, YEnd - y + 1, PixelData);
    TAP_MemFree(PixelData);
  } // if PixelData
}
