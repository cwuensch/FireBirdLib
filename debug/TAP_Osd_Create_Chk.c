#include "../libFireBird.h"

int TAP_Osd_Create_Chk(char *Comment, dword x, dword y, dword w, dword h, byte lutIdx, int flag)
{
  int ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("TAP_Osd_Create_Chk");
#endif

  if(x > 719)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Create_Chk Warning: x(%d) out of range @ %s\n", x, Comment);
#else
    TAP_Print("TAP_Osd_Create_Chk Warning: x(%d) out of range @ %s\n", x, Comment);
#endif

  if(y > 575)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Create_Chk Warning: y(%d) out of range @ %s\n", y, Comment);
#else
    TAP_Print("TAP_Osd_Create_Chk Warning: y(%d) out of range @ %s\n", y, Comment);
#endif

  if((x + w) > 719)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Create_Chk Warning: x(%d) + w(%d) out of range @ %s\n", x, w, Comment);
#else
    TAP_Print("TAP_Osd_Create_Chk Warning: x(%d) + w(%d) out of range @ %s\n", x, w, Comment);
#endif

  if((y + h) > 575)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Create_Chk Warning: y(%d) + h(%d) out of range @ %s\n", y, h, Comment);
#else
    TAP_Print("TAP_Osd_Create_Chk Warning: y(%d) + h(%d) out of range @ %s\n", y, h, Comment);
#endif

  ret = TAP_Osd_Create(x, y, w, h, lutIdx, flag);

  if(ret < 128)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Create_Chk Warning: TAP_Osd_Create() returned %d @ %s\n", ret, Comment);
#else
    TAP_Print("TAP_Osd_Create_Chk Warning: TAP_Osd_Create() returned %d @ %s\n", ret, Comment);
#endif

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}
