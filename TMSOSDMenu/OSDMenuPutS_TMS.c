#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuPutS(word rgn, dword x, dword y, dword maxX, const char * str, dword fcolor, dword bcolor, byte fntSize, byte bDot, byte align)
{
  switch(fntSize)
  {
    case 12: FM_PutString(rgn, x, y + FONTYOFFSET, maxX, str, fcolor, bcolor, &Calibri_12_FontData, bDot, align); break;
    case 14: FM_PutString(rgn, x, y + FONTYOFFSET, maxX, str, fcolor, bcolor, &Calibri_14_FontData, bDot, align); break;
    case 16: FM_PutString(rgn, x, y + FONTYOFFSET, maxX, str, fcolor, bcolor, &Calibri_16_FontData, bDot, align); break;
    case 20: FM_PutString(rgn, x, y + FONTYOFFSET, maxX, str, fcolor, bcolor, &Calibri_20_FontData, bDot, align); break;
  }
}

#endif
