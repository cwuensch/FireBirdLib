#define                 FB_DEBUG_CHK
#define                 FB_LOG_ENTRY_LIB_PRINTF
#include                "libFireBird.h"

int TAP_Osd_FillBox_Chk(char *Comment, word rgn, dword x, dword y, dword w, dword h, dword color)
{
  TRACEENTER();

  int                   ret;
  dword                 RgnH, RgnW;

  if(Comment)
  {
    RgnH = GetOSDRegionHeight(rgn);
    RgnW = GetOSDRegionWidth(rgn);

    if(!isOSDRegionAlive(rgn)) LogEntryFBLibPrintf(TRUE, "TAP_Osd_FillBox_Chk Warning: rgn(%d) points to an undefined region @ %s", rgn, Comment);
    if(x >= RgnW) LogEntryFBLibPrintf(TRUE, "TAP_Osd_FillBox_Chk Warning: x(%lu) out of range @ %s", x, Comment);
    if(y >= RgnH) LogEntryFBLibPrintf(TRUE, "TAP_Osd_FillBox_Chk Warning: y(%lu) out of range @ %s", y, Comment);
    if((x + w) > RgnW) LogEntryFBLibPrintf(TRUE, "TAP_Osd_FillBox_Chk Warning: x(%lu) + w(%lu) out of range @ %s", x, w, Comment);
    if((y + h) > RgnH) LogEntryFBLibPrintf(TRUE, "TAP_Osd_FillBox_Chk Warning: y(%lu) + h(%lu) out of range @ %s", y, h, Comment);
  }

  ret = TAP_Osd_FillBox(rgn, x, y, w, h, color);

  if(Comment && ret) LogEntryFBLibPrintf(TRUE, "TAP_Osd_FillBox_Chk Warning: TAP_Osd_Create() returned %d @ %s", ret, Comment);

  TRACEEXIT();
  return ret;
}
