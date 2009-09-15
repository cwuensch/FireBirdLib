#include "../libFireBird.h"

int TAP_Osd_PutPixel_Chk(char *Comment, word rgn, dword x, dword y, dword pix)
{
  int                   ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("TAP_Osd_PutPixel_Chk");
#endif

  if(!isOSDRegionAlive(rgn))
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_PutPixel_Chk Warning: rgn(%d) points to an undefined region @ %s\n", rgn, Comment);
#else
    TAP_Print("TAP_Osd_PutPixel_Chk Warning: rgn(%d) points to an undefined region @ %s\n", rgn, Comment);
#endif

  if(x > 719)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_PutPixel_Chk Warning: x(%d) out of range @ %s\n", x, Comment);
#else
    TAP_Print("TAP_Osd_PutPixel_Chk Warning: x(%d) out of range @ %s\n", x, Comment);
#endif

  if(y > 575)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_PutPixel_Chk Warning: y(%d) out of range @ %s\n", y, Comment);
#else
    TAP_Print("TAP_Osd_PutPixel_Chk Warning: y(%d) out of range @ %s\n", y, Comment);
#endif

  ret = TAP_Osd_PutPixel(rgn, x, y, pix);

  if(ret)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_PutPixel_Chk Warning: TAP_Osd_PutPixel() returned %d @ %s\n", ret, Comment);
#else
    TAP_Print("TAP_Osd_PutPixel_Chk Warning: TAP_Osd_PutPixel() returned %d @ %s\n", ret, Comment);
#endif

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}
