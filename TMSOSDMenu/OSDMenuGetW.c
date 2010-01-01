#include                "FBLib_TMSOSDMenu.h"

#include                "fonts/Miriam_12.c"
#include                "fonts/Miriam_14.c"
#include                "fonts/Miriam_16.c"
#include                "fonts/Miriam_18.c"
#include                "fonts/Miriam_20.c"
#include                "fonts/Miriam_20B.c"

int OSDMenuGetW(const char * str, byte fntSize)
{
  switch(fntSize)
  {
    case 12: return FM_GetStringWidth(str, &Miriam_12_FontData);
    case 14: return FM_GetStringWidth(str, &Miriam_14_FontData);
    case 16: return FM_GetStringWidth(str, &Miriam_16_FontData);
    case 20: return FM_GetStringWidth(str, &Miriam_20_FontData);
  }

  return 0;
}
