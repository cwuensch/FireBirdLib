#include "FBLib_flash.h"

void FlashProgram (void)
{
#ifdef _TMS_
  //Do not recalculate the CRCs as this will make the update routine think that everything is ok
  *(word *)(FlashBlockOffset[TVServices]) = *(word *)(FlashBlockOffset[TVServices]) ^ 0x01;
#endif

  TAP_WriteSystemVar();
}
