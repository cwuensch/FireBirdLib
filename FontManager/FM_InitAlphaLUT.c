#include                "FBLib_FontManager.h"

void FM_InitAlphaLUT(dword fgColor, dword bgColor)
{
  int                   i;
  dword                 x;

  for(i = 0; i < 255; i++)
  {
    x = FM_AlphaBlend(i, (fgColor >> 16) & 0xff, (bgColor >> 16) & 0xff);
    AlphaLUT[i].r = (x > 255) ? 255 : x;

    x = FM_AlphaBlend(i, (fgColor >>  8) & 0xff, (bgColor >>  8) & 0xff);
    AlphaLUT[i].g = (x > 255) ? 255 : x;

    x = FM_AlphaBlend(i,  fgColor        & 0xff,  bgColor        & 0xff);
    AlphaLUT[i].b = (x > 255) ? 255 : x;
  }
}
