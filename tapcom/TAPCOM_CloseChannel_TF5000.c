#include                "FBLib_tapcom.h"

#ifndef _TMS_

void TAPCOM_CloseChannel (TAPCOM_Channel Channel)
{
  TAPCOM_InternalMesBuf *buf = (TAPCOM_InternalMesBuf *) Channel;

  if (isValidChannel (Channel) && (buf->FromID == __tap_ud__))
  {
    buf->tapcomSignature = 0;
    TAP_MemFree(Channel);
  }
}

#endif
