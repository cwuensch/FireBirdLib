#include                "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_GetGP (dword *UncompressedFirmware)
{
  dword                 i;
  static dword         *LastAddress = 0, gp = 0;

  if (!isValidRAMPtr(UncompressedFirmware)) return 0;

  //Optimize speed for multiple calls
  if (LastAddress == UncompressedFirmware) return gp;

  //Calculate the $gp register of the loaded FW
  for (i = 0; i < 256; i++)
  {
    if ((UncompressedFirmware [i] & 0xffff0000) == LUI_GP_CMD) gp = (UncompressedFirmware [i] & 0x0000ffff) << 16;
    if ((UncompressedFirmware [i] & 0xffff0000) == ADDIU_GP_CMD)
    {
      gp += (short)(UncompressedFirmware [i] & 0x0000ffff);
      break;
    }
  }
  LastAddress = UncompressedFirmware;

  return gp;
}

#endif
