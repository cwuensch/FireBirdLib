#include "FBLib_tap.h"

#ifndef _TMS_

dword HDD_TAP_DisabledEventHandler (word event, dword param1, dword param2)
{
  //Don't access any variables here as this routine is called in the context of the disabled TAP!!!

  (void) event;
  (void) param2;
  return param1;
}

#endif
