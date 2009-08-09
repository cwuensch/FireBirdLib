#include                "../libFireBird.h"

#ifndef _TMS_

//Return codes: 1 = file not found
//              2 = failed to open the file
//              3 = failed to reserve memory
//              4 = invalid file
//              5 = unsupported tfp version
//   >=0x80000000 = Pointer to the patch module. Use TAP_MemFree after processing the patch
//
tPatchModule *PatchLoadModule (char *FileName)
{
  return PatchLoadModuleGP(FileName, 0);
}

#endif
