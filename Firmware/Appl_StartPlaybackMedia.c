#include                "../libFireBird.h"

//returns 0 on ok or 1 on failure

int Appl_StartPlaybackMedia(char *FileName, unsigned int p2, bool p3, bool ScaleInPip)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("Appl_StartPlaybackMedia");
  #endif

  int  (*__Appl_StartPlaybackMedia)(char const*, unsigned int, bool, bool);
  int  ret = 1;

  __Appl_StartPlaybackMedia = (void*)FIS_fwAppl_StartPlaybackMedia();
  if(__Appl_StartPlaybackMedia) ret = __Appl_StartPlaybackMedia(FileName, p2, p3, ScaleInPip);

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
