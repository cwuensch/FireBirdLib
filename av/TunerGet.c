#include "FBLib_av.h"
#include "../libFireBird.h"

byte TunerGet(int MainSub)
{
#ifndef _TMS_
  byte                  ret;
#endif

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("TunerGet");
#endif


  //Parameter sanity check
  if (MainSub != CHANNEL_Main && MainSub != CHANNEL_Sub)
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return -1;
  }

#ifdef _TMS_

  //Has been forgotten :-)
  extern unsigned char (*TAP_GetActiveTuner)(unsigned char);

  return TAP_GetActiveTuner(MainSub);

#else


  //Get the tuner number
  ret = *(byte *)(GetEEPROMAddress() + 0x16 + MainSub);

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

  return ret;

#endif

}
