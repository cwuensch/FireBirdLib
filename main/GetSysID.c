#include "FBLib_main.h"

word GetSysID(void)
{
  if (!LibInitialized) InitTAPex();
  if (!LibInitialized) return 0;

  return SysID;
}
