#include                "FBLib_tapcom.h"

bool isValidChannel (TAPCOM_Channel Channel)
{

#ifndef _TMS_
  //Zeigt der Pointer ausserhalb des zulässigen Speicherbereichs?
  if (((dword) Channel < 0x80000000) || ((dword) Channel > 0x84000000 - sizeof(TAPCOM_InternalMesBuf))) return FALSE;
#endif

  //Gültige Signatur?
  return (((TAPCOM_InternalMesBuf *) Channel)->tapcomSignature == TAPCOM_SIGNATURE);
}
