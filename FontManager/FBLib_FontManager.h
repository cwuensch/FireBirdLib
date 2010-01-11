#ifndef FBLIB_FONTMANAGER_H
#define FBLIB_FONTMANAGER_H

#include "..\libFireBird.h"

#ifdef _TMS_

typedef struct
{
  byte  r;
  byte  g;
  byte  b;
} tAlphaLUT;

tAlphaLUT  AlphaLUT[256];


bool FM_isValidCharacter(byte Char);
byte FM_CharToIndex(byte Char);
byte FM_AlphaBlend(byte Alpha, byte FG, byte BG);
void FM_InitAlphaLUT(dword fgColor, dword bgColor);
dword FM_AlphaBlendRGB(byte Alpha, dword FG, dword BG);


#endif
#endif
