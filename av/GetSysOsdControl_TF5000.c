#include "FBLib_av.h"
#include "../libFireBird.h"

#ifndef _TMS_

bool GetSysOsdControl (TYPE_TapSysOsdId OSDID)
{
  static byte             *TapSysOsdVars;

  if (!(TapSysOsdVars = (byte*)FIS_vSysOsdControl())) return FALSE;

  return (TapSysOsdVars [OSDID] != 0);
}

#endif
