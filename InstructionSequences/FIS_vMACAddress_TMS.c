#include "../libFireBird.h"

#ifdef _TMS_

inline dword FIS_vMACAddress(void)
{
  static dword          MacAddress;
  dword                 MacAddressSize;

  int (*DevEeprom_GetMacAddr)(unsigned char *pMacAddress, dword *MacAddressSize);

  if (!MacAddress)
  {
    DevEeprom_GetMacAddr = (void*)TryResolve("DevEeprom_GetMacAddr");

    if(DevEeprom_GetMacAddr)
      DevEeprom_GetMacAddr((unsigned char*)&MacAddress, &MacAddressSize);
  }

  return MacAddress;
}

#endif
