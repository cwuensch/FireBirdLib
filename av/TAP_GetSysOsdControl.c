#include "../libFireBird.h"

bool TAP_GetSysOsdControl(TYPE_TapSysOsdId osdId)
{
  dword                *__tapSysOsdCtrl = NULL;

  __tapSysOsdCtrl = (dword*)FIS_vTapSysOsdCtrl();
  if(!__tapSysOsdCtrl) return FALSE;

  switch(osdId)
  {
    case SYSOSD_InfoBox:        return *__tapSysOsdCtrl & 0x00000001;
    case SYSOSD_PvrInfo:        return *__tapSysOsdCtrl & 0x00000100;
    case SYSOSD_VolumeBar:      return *__tapSysOsdCtrl & 0x00010000;
    case SYSOSD_ServiceStatus:  return *__tapSysOsdCtrl & 0x01000000;
  }

  return FALSE;
}