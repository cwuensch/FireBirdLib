#include "FBLib_av.h"
#include "../libFireBird.h"

#ifndef _TMS_

bool GetSysOsdControl(TYPE_TapSysOsdId OSDID)
{
  static byte          *TapSysOsdVars;
  bool                  ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("GetSysOsdControl");
#endif

  if (!(TapSysOsdVars = (byte*)FIS_vSysOsdControl()))
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return FALSE;
  }

  ret = (TapSysOsdVars [OSDID] != 0);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}

#endif
