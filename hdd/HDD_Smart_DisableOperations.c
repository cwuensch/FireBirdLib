#include "FBLib_hdd.h"
#include "../libFireBird.h"

int HDD_Smart_DisableOperations (void)
{
#ifdef _TMS_

  unsigned char         CommandBlock[HDIO_DRIVE_TASK_HDR_SIZE] = {WIN_SMART,        //COMMAND
                                                                  SMART_DISABLE,    //FEATURE
                                                                  0,                //NSECTOR
                                                                  0,                //SECTOR
                                                                  0x4f,             //LCYL
                                                                  0xc2,             //HCYL
                                                                  0,                //SELECT
                                                                  0};               //COMMAND

  return SendHDDCommand(HDIO_DRIVE_TASK, CommandBlock, 0);

#else

  int                   Ret;

  Ret = SendHDDCommand (SMART_DISABLE, 0, 0, 0x4F, 0xC2, 0x00, WIN_SMART);
#ifdef DEBUG_FIREBIRDLIB
  if (Ret != 0) TAP_Print ("FireBirdLib: HDDSmartDisableOperations: Ret=%d\r\n", Ret);
#endif
  return Ret;

#endif
}
