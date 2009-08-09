#include "FBLib_av.h"
#include "../libFireBird.h"

//It is not possible to set the tuner for the PIP
bool TunerSet(byte Tuner)
{
  int                   tvRadio, chNum;

  //Parameter sanity check
  if (Tuner > 1) return FALSE;

#ifdef _TMS_

  dword * _etcInfo;

  if (!(_etcInfo  = (dword*)FIS_vEtcInfo())) return FALSE;

  *(byte*)(*_etcInfo + 0x12 + CHANNEL_Main) = Tuner;
  *(byte*)(*_etcInfo + 0x12 + CHANNEL_Sub)  = 1 - Tuner;


#else

  //Set the tuner number for the channel
  *(byte *)(FIS_vEEPROM() + 0x17) = Tuner;

#endif

  TAP_Channel_GetCurrent (&tvRadio, &chNum);
  TAP_Channel_Start (CHANNEL_Main, tvRadio, chNum);

  return TRUE;
}

