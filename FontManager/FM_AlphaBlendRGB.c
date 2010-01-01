#include                "FBLib_FontManager.h"

dword FM_AlphaBlendRGB(byte Alpha, dword FG, dword BG)
{
  dword              red, green, blue;

  red = FM_AlphaBlend(Alpha, (FG >> 16) & 0xff, (BG >> 16) & 0xff);
  green = FM_AlphaBlend(Alpha, (FG >> 8) & 0xff, (BG >> 8) & 0xff);
  blue = FM_AlphaBlend(Alpha, FG & 0xff, BG & 0xff);

  return ARGB(0, red, green, blue);
}
