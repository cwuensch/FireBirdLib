#include "FBLib_av.h"
#include "../libFireBird.h"

#ifndef _TMS_
volatile tScalerSettings    *ScalerSettings;
#endif

bool GetPIPPosition (int *North, int *South, int *East, int *West)
{
#ifdef _TMS_

  byte                *_isPipActive;
  word                *_pipX, *_pipY, *_pipW, *_pipH;

  _isPipActive = (byte*)TryResolve("_isPipActive");
  if(_isPipActive)
  {
    _pipX = (word*)TryResolve("_pipX");
    _pipY = (word*)TryResolve("_pipY");
    _pipW = (word*)TryResolve("_pipW");
    _pipH = (word*)TryResolve("_pipH");

    *West  = *_pipX;
    *East  = *_pipX + *_pipW;
    *North = *_pipY;
    *South = *_pipY + *_pipH;
  }

  return (_isPipActive != 0);

#else

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return FALSE;

  if (!pScalerSettingsPIP->Active) return FALSE;

  //Let the scaler structure point to the scaler settings of the PIP
  ScalerSettings = (tScalerSettings *) (pScalerSettingsPIP->Address | 0x80000000);

  if (North) *North = ScalerSettings->WindowY - 1;
  if (South) *South = ScalerSettings->WindowY + ScalerSettings->WindowHeight + 2;
  if (East)  *East = ScalerSettings->WindowX + ScalerSettings->WindowWidth + 1;
  if (West)  *West = ScalerSettings->WindowX - 1;

  return TRUE;
#endif
}
