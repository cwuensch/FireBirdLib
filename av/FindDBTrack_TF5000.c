#include      "FBLib_av.h"
#include      "../libFireBird.h"

#ifndef _TMS_

int FindDBTrack (void)
{
  int                   i;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("FindDBTrack");
#endif

  if (pAudioTracks == NULL) InitAudioPointers();
  for (i = 0; i < 64; i++)
  {
    if ((pAudioTracks->AudioPID [i] & 0x2000) != 0)
    {

#ifdef DEBUG_FIREBIRDLIB
      CallTraceExit(NULL);
#endif

      return i;
    }
  }

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return -1;
}

#endif
