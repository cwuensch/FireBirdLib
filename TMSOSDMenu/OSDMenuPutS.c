#include                "FBLib_TMSOSDMenu.h"

void OSDMenuPutS(word rgn, dword x, dword y, dword maxX, const char * str, dword fcolor, dword bcolor, byte fntSize, byte bDot, byte align)
{
  switch(fntSize)
  {
    case 12: FM_PutString(rgn, x, y, maxX, str, fcolor, bcolor, &Miriam_12_FontData, bDot, align); break;
    case 14: FM_PutString(rgn, x, y, maxX, str, fcolor, bcolor, &Miriam_14_FontData, bDot, align); break;
    case 16: FM_PutString(rgn, x, y, maxX, str, fcolor, bcolor, &Miriam_16_FontData, bDot, align); break;
    case 20: FM_PutString(rgn, x, y, maxX, str, fcolor, bcolor, &Miriam_20_FontData, bDot, align); break;
  }
}
