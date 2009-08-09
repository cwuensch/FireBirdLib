#include                "FBLib_tapcom.h"

#ifndef _TMS_

void TAPCOM_Reject (TAPCOM_Channel Channel)
{
  TAPCOM_InternalMesBuf *buf = (TAPCOM_InternalMesBuf *) Channel;

  if (isValidChannel (Channel))
  {
    buf->Status = TAPCOM_Status_REJECTED;

    //Server-Timeout zur�cksetzen
    buf->ServerAlive = TAP_GetTick();
  }
}

#endif
