#include "FBLib_main.h"

#ifndef _TMS_

bool SuppressedAutoStart (void)
{
  byte                 *i;

  if (!(i = (byte*)FIS_vSuppressedAutoStart())) return FALSE;

  return *i != 0;
}

#endif
