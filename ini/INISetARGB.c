#include "FBLib_ini.h"
#include "../libFireBird.h"

void INISetARGB (char *Key, byte Alpha, byte Red, byte Green, byte Blue)
{
  static char argb[12];

#ifdef _TMS_
  //Convert to OSD_1555
  sprintf(argb, "%1.1d,%2.2d,%2.2d,%2.2d", Alpha >> 7, (int)(Red / 8.2258) & 0x1f, (int)(Green / 8.2258) & 0x1f, (int)(Blue / 8.2258) & 0x1f);
#else
  sprintf(argb, "%1.1d,%2.2d,%2.2d,%2.2d", Alpha & 1, Red & 0x1f, Green & 0x1f, Blue & 0x1f);
#endif
  INISetString(Key, argb);
}
