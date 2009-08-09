#include "../libFireBird.h"

void InitTAPexFailedMsg(char *ProgramName)
{
  char                  s [28];

#ifdef _TMS_
  TAP_SPrint (s, "%d %4.4x", SysID, ApplID);
#else
  TAP_SPrint (s, "%d %4.4x %8.8x", SysID, ApplID, FWgp);
#endif
  ShowMessageWin (ProgramName ? ProgramName : "", "FBLib failed to init", s, 500);
}
