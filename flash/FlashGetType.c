#include "FBLib_flash.h"

SYSTEM_TYPE FlashGetType (void)
{
  if (!LibInitialized) InitTAPex();
  return (FlashOffset == 0 ? ST_UNKNOWN : SystemType);
}
