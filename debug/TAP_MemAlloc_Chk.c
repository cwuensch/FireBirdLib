#include "../libFireBird.h"

void* TAP_MemAlloc_Chk(char *Comment, dword size)
{
  void                 *ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("TAP_MemAlloc_Chk");
#endif

  ret = TAP_MemAlloc(size);

  if(!ret)
#ifdef _TMS_
    TAP_PrintNet("TAP_MemAlloc_Chk Warning: TAP_MemAlloc(%d) returned NULL pointer @ %s\n", size, Comment);
#else
    TAP_Print("TAP_MemAlloc_Chk Warning: TAP_MemAlloc(%d) returned NULL pointer @ %s\n", size, Comment);
#endif

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}
