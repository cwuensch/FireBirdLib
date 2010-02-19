#include "../libFireBird.h"


inline dword FIS_vTAPTable(void)
{
  static dword          *vTAP_TableAddress = NULL;

#ifdef _TMS_

  if(!vTAP_TableAddress) vTAP_TableAddress = (dword*)TryResolve("_tapTask");
  return (dword)vTAP_TableAddress;

#else


  if (!vTAP_TableAddress)
  {
    vTAP_TableAddress = (dword*)TAP_Print;
    while ((vTAP_TableAddress[0] & CMD_MASK) != LUI_CMD || (vTAP_TableAddress[1] & CMD_MASK) != ADDIU_CMD) vTAP_TableAddress++;

    vTAP_TableAddress = (dword*)((vTAP_TableAddress[0] << 16) + (short)(vTAP_TableAddress[1] & 0xffff));
  }


  return (dword)vTAP_TableAddress;
#endif

}
