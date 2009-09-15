#include "../libFireBird.h"

void TAP_Osd_RestoreBox_Chk(char *Comment, word rgn, dword x, dword y, dword w, dword h, void *data)
{

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("TAP_Osd_RestoreBox_Chk");
#endif

  if(!isOSDRegionAlive(rgn))
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_RestoreBox_Chk Warning: rgn(%d) points to an undefined region @ %s\n", rgn, Comment);
#else
    TAP_Print("TAP_Osd_RestoreBox_Chk Warning: rgn(%d) points to an undefined region @ %s\n", rgn, Comment);
#endif

  if(x > 719)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_RestoreBox_Chk Warning: x(%d) out of range @ %s\n", x, Comment);
#else
    TAP_Print("TAP_Osd_RestoreBox_Chk Warning: x(%d) out of range @ %s\n", x, Comment);
#endif

  if(y > 575)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_RestoreBox_Chk Warning: y(%d) out of range @ %s\n", y, Comment);
#else
    TAP_Print("TAP_Osd_RestoreBox_Chk Warning: y(%d) out of range @ %s\n", y, Comment);
#endif

  if((x + w) > 719)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_RestoreBox_Chk Warning: x(%d) + w(%d) out of range @ %s\n", x, w, Comment);
#else
    TAP_Print("TAP_Osd_RestoreBox_Chk Warning: x(%d) + w(%d) out of range @ %s\n", x, w, Comment);
#endif

  if((y + h) > 575)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_RestoreBox_Chk Warning: y(%d) + h(%d) out of range @ %s\n", y, h, Comment);
#else
    TAP_Print("TAP_Osd_RestoreBox_Chk Warning: y(%d) + h(%d) out of range @ %s\n", y, h, Comment);
#endif

  if(data == NULL)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_RestoreBox_Chk Warning: trying to restore from NULL @ %s\n", Comment);
#else
    TAP_Print("TAP_Osd_RestoreBox_Chk Warning: trying to restore from NULL @ %s\n", Comment);
#endif

  TAP_Osd_RestoreBox(rgn, x, y, w, h, data);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

}
