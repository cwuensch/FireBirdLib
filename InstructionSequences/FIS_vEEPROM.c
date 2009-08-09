#include "../libFireBird.h"

inline dword FIS_vEEPROM(void)
{
#ifdef _TMS_

  static dword         *_applEepromAddr;

  if(!_applEepromAddr)
    _applEepromAddr = (dword*)TryResolve("_applEepromAddr");

  return (_applEepromAddr ? *_applEepromAddr : 0);

#else

  dword                 *p, gp;
  static dword          pEEPROM = 0;

  if (!pEEPROM)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    //Scan for the "lw $??, ????($gp)" instruction in TAP_Channel_GetCurrent
    p = (dword *) TAP_Channel_GetCurrent;
    do
    {
      if ((*p & BASE_MASK) == LW_GP_CMD)
      {
        pEEPROM = gp + (short) (*p & 0x0000ffff);
        break;
      }
      p++;

      //ibbi 2007-01-07: at which address should be stopped anyway if there is no JR_RA_CMD?
      if ((dword) p > 0x82000000) return 0;

    } while (*p != JR_RA_CMD);

    if (pEEPROM) pEEPROM = *(dword *) pEEPROM - 2;
  }

  return pEEPROM;

#endif
}
