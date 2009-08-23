#include                "FBLib_tmsvfd.h"

#ifdef _TMS_

bool VFD_Update(void)
{
  void (*Vfd_SendData)(void) = (void*)FIS_fwApplVfdSendData();

  if(!VFDUsedByTAP || !Vfd_SendData) return FALSE;

  Vfd_SendData();

  return TRUE;
}

#endif
