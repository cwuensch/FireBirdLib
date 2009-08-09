#include "../libFireBird.h"

#ifndef _TMS_

bool isOSDRegionAlive (word Region)
{
  return (GetOSDRegionWidth(Region) != 0 && GetOSDRegionHeight(Region) != 0);
}

#endif
