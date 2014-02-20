#include                "../libFireBird.h"

//returns 0 on ok or -1 on failure

int Appl_StartPlayback(char *FileName, unsigned int p2, bool p3, bool ScaleInPip)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("Appl_StartPlayback");
  #endif

  int (*__Appl_StartPlayback)(char const*, unsigned int, bool, bool);
  int  ret = -1;

  __Appl_StartPlayback = (void*)FIS_fwAppl_StartPlayback();
  if(__Appl_StartPlayback) ret = __Appl_StartPlayback(FileName, p2, p3, ScaleInPip);

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
