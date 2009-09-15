#include "../libFireBird.h"

byte* TAP_Osd_SaveBox_Chk(char *Comment, word rgn, dword x, dword y, dword w, dword h)
{
  byte                 *ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("TAP_Osd_SaveBox_Chk");
#endif

  if(!isOSDRegionAlive(rgn))
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_SaveBox_Chk Warning: rgn(%d) points to an undefined region @ %s\n", rgn, Comment);
#else
    TAP_Print("TAP_Osd_SaveBox_Chk Warning: rgn(%d) points to an undefined region @ %s\n", rgn, Comment);
#endif


  if(x > 719)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_SaveBox_Chk Warning: x(%d) out of range @ %s\n", x, Comment);
#else
    TAP_Print("TAP_Osd_SaveBox_Chk Warning: x(%d) out of range @ %s\n", x, Comment);
#endif

  if(y > 575)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_SaveBox_Chk Warning: y(%d) out of range @ %s\n", y, Comment);
#else
    TAP_Print("TAP_Osd_SaveBox_Chk Warning: y(%d) out of range @ %s\n", y, Comment);
#endif

  if((x + w) > 719)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_SaveBox_Chk Warning: x(%d) + w(%d) out of range @ %s\n", x, w, Comment);
#else
    TAP_Print("TAP_Osd_SaveBox_Chk Warning: x(%d) + w(%d) out of range @ %s\n", x, w, Comment);
#endif

  if((y + h) > 575)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_SaveBox_Chk Warning: y(%d) + h(%d) out of range @ %s\n", y, h, Comment);
#else
    TAP_Print("TAP_Osd_SaveBox_Chk Warning: y(%d) + h(%d) out of range @ %s\n", y, h, Comment);
#endif

  ret = TAP_Osd_SaveBox(rgn, x, y, w, h);

  if(ret == NULL)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_SaveBox_Chk Warning: TAP_Osd_SaveBox() returned a NULL pointer @ %s\n", Comment);
#else
    TAP_Print("TAP_Osd_SaveBox_Chk Warning: TAP_Osd_SaveBox() returned a NULL pointer @ %s\n", Comment);
#endif

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}
