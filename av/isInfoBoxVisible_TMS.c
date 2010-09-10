#include "../libFireBird.h"

#ifdef _TMS_

bool isInfoBoxVisible(void)
{
  byte                 *iboxTimerId;

  iboxTimerId = (byte*)FIS_viboxTimerId();
  if(!iboxTimerId) return FALSE;

  return (*iboxTimerId != 0xff);
}

#endif
