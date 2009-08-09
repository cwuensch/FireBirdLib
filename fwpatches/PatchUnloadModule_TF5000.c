#include                "../libFireBird.h"

#ifndef _TMS_

void PatchUnloadModule (tPatchModule *PatchModule)
{
  if ((void*)PatchModule < (void*)0x80000000) return;

  TAP_MemFree (PatchModule);
  PatchModule = NULL;
}

#endif
