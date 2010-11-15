#include "../libFireBird.h"

bool isInfoBoxVisible(void)
{
  byte                 *iboxTimerId;

  iboxTimerId = (byte*)FIS_viboxTimerId();
  if(!iboxTimerId) return FALSE;

  return (*iboxTimerId != 0xff);
}
