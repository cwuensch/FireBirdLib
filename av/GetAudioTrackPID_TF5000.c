#include      <string.h>
#include      "FBLib_av.h"
#include      "../libFireBird.h"

#ifndef _TMS_

word GetAudioTrackPID(byte Channel, char *Lang)
{
  word                  ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("GetAudioTrackPID");
#endif

  if (Channel > 63)
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return 0;
  }

  if (pAudioTracks == NULL) InitAudioPointers();

  if (Lang != NULL)
  {
    strncpy (Lang, pAudioTracks->Lang [Channel], 3);
    Lang [3] = 0;
  }

  ret = pAudioTracks->AudioPID [Channel];

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}

#endif
