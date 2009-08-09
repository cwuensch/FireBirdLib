#include "FBLib_hook.h"
#include "../libFireBird.h"

#ifndef _TMS_

void HookExit ()
{
  dword                 i;

  for (i = 0; i < NrHooks; i++)
    if (Hooks [i].Enabled) HookEnable (i, FALSE);
}

#endif
