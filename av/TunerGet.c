#include "FBLib_av.h"
#include "../libFireBird.h"

byte TunerGet(int MainSub)
{
  //Parameter sanity check
  if (MainSub != CHANNEL_Main && MainSub != CHANNEL_Sub) return -1;

#ifdef _TMS_

  //Has been forgotten :-)
  extern unsigned char (*TAP_GetActiveTuner)(unsigned char);

  return TAP_GetActiveTuner(MainSub);

#else


  //Get the tuner number
  return *(byte *)(GetEEPROMAddress() + 0x16 + MainSub);

#endif

}
