#include      "FBLib_av.h"
#include      "../libFireBird.h"

#ifndef _TMS_

int FindDBTrack (void)
{
  int                   i;

  if (pAudioTracks == NULL) InitAudioPointers();
  for (i = 0; i < 64; i++)
  {
    if ((pAudioTracks->AudioPID [i] & 0x2000) != 0) return i;
  }
  return -1;
}

#endif
