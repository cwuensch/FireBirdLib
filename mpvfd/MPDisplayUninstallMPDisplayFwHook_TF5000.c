#include "FBLib_mpvfd.h"

#ifndef _TMS_

// This function uninstalls the firmware hook.
void MPDisplayUninstallMPDisplayFwHook (void)
{
  if(bFwHookInstalled)
  {
    // restore the original instructions of the FW function
    dword *pBuffer = (dword*)exitHook;
    pFwSendToVfdDisplay[0] = pBuffer[0];
    pFwSendToVfdDisplay[1] = pBuffer[1];
    bFwHookInstalled = FALSE;
  }
}

#endif
