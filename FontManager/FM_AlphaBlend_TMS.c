#include                "FBLib_FontManager.h"

#ifdef _TMS_

byte FM_AlphaBlend(byte Alpha, byte FG, byte BG)
{
  dword                  Color;

  if(Alpha == 0) return BG;
  if(Alpha == 0xff) return FG;

  Color = (((dword)Alpha * FG) + ((dword)(255 - Alpha) * BG)) >> 8;

  return (Color > 255) ? 255 : Color;
}

#endif
