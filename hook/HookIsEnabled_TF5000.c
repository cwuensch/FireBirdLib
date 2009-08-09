#include "FBLib_hook.h"
#include "../libFireBird.h"

#ifndef _TMS_

bool HookIsEnabled (dword HookIndex)
{
  return (HookIndex >= NrHooks ? FALSE : Hooks [HookIndex].Enabled);
}

#endif
