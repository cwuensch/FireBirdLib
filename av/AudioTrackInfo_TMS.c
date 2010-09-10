#include      <string.h>
#include      "FBLib_av.h"
#include      "../libFireBird.h"

#ifdef _TMS_

tAudioTrk *AudioTrackInfo(void)
{
  return (tAudioTrk*)FIS_vAudioTrack();
}

#endif
