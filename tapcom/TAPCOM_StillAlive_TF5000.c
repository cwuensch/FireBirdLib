#include                "FBLib_tapcom.h"

#ifndef _TMS_

void TAPCOM_StillAlive (TAPCOM_Channel Channel)
{
  if (isValidChannel (Channel))
  {
    //Reset the server timeout
    ((TAPCOM_InternalMesBuf *) Channel)->ServerAlive = TAP_GetTick();
  }
}

#endif
