#include		"../libFireBird.h"

#ifdef _TMS_

byte *GetMacAddress(void)
{
  return (byte*)FIS_vMACAddress();
}
#endif
