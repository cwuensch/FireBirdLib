#include                <string.h>
#include                "FBLib_FontManager.h"

#ifdef _TMS_

void FM_PutString(word rgn, dword x, dword y, dword maxX, const char * str, dword fcolor, dword bcolor, tFontData *FontData, byte bDot, byte align)
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

  if(!str || !str[0] || !FontData || !FontData->pFontData) return;

  strncpy(newstr, str, 256);
  newstr[256] = '\0';
  XEnd = x + FM_GetStringWidthAndRestrict(newstr, FontData, maxX-x, &bRestricted);

  if (bRestricted && bDot)
  {
    dotWidth = FM_GetStringWidth("...", FontData);

    newstrlen = strlen(newstr);
    do
    {
      LastChar = newstr[newstrlen-1];
      if(FM_isValidCharacter(LastChar))
      {
          width = FontData->FontDef[FM_CharToIndex(LastChar)].Width;
          XEnd -= width;
      }
      newstr[newstrlen - 1]= '\0';
      newstrlen--;
    }while(  ((XEnd + dotWidth) > maxX)
           &&(width != 0)
           &&(newstrlen > 0));

    strcat(newstr, "...");
    XEnd += FM_GetStringWidth("...", FontData);
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
      SaveBoxX = x + ((maxX - x - (XEnd - x)/*FM_GetStringWidth(newstr, FontData)*/) >> 1);
      break;
    }

    case ALIGN_RIGHT:
    {
      SaveBoxX = maxX - (XEnd - x);
      break;
    }

    default:
      SaveBoxX = x;
  }

  if(bcolor & 0xff000000)
  {
    TAP_Osd_FillBox(rgn, x, y, maxX - x, YEnd - y + 1, bcolor);
    FM_InitAlphaLUT(fcolor, bcolor);
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
                            LastPixel = (fcolor & 0xff000000) | FM_AlphaBlendRGB(Grey, fcolor, LastBackgroundPixel);
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

#endif
