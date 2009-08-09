#include                "FBLib_tapcom.h"

#ifndef _TMS_

bool isValidChannel (TAPCOM_Channel Channel)
{
  //Zeigt der Pointer ausserhalb des zul�ssigen Speicherbereichs?
  if (((dword) Channel < 0x80000000) || ((dword) Channel > 0x84000000 - sizeof(TAPCOM_InternalMesBuf))) return FALSE;

  //G�ltige Signatur?
  return (((TAPCOM_InternalMesBuf *) Channel)->tapcomSignature == TAPCOM_SIGNATURE);
}

#endif
