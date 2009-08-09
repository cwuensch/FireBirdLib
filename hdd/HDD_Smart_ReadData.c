#include "FBLib_hdd.h"
#include "../libFireBird.h"

int HDD_Smart_ReadData (word *DataBuf)
{
#ifdef _TMS_

  unsigned char         CommandBlock[HDIO_DRIVE_CMD_HDR_SIZE + 512] = {WIN_SMART, 0, SMART_READ_VALUES, 1,};

  if(SendHDDCommand(HDIO_DRIVE_CMD, CommandBlock, 512)) return 19;
  memcpy(DataBuf, &CommandBlock[4], 512);
  return 0;

#else

  int                   Ret;
  dword                 RS;

  RS = intLock ();
  Ret = SendHDDCommand (SMART_READ_VALUES, 0, 0, 0x4F, 0xC2, 0xA0, WIN_SMART);
  if (Ret != 0)
  {
    //If the ERR flag in the status register has been set,
    //the SMART feature has been disabled.
    intUnlock (RS);
#ifdef DEBUG_FIREBIRDLIB
    TAP_Print ("FireBirdLib: HDDSmartReadData: Ret=%d\r\n", Ret);
#endif
    return 19;
  }
  Ret = ReceiveSector ((word *) DataBuf);
  intUnlock (RS);
  return Ret;

#endif
}
