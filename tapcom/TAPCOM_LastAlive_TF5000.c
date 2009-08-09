#include                "FBLib_tapcom.h"

#ifndef _TMS_

dword TAPCOM_LastAlive (TAPCOM_Channel Channel)
{
  if (isValidChannel (Channel))
  {
    return ((TAPCOM_InternalMesBuf *) Channel)->ServerAlive;
  }

  return 0;
}

#endif
