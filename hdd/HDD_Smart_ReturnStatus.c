#include "FBLib_hdd.h"
#include "../libFireBird.h"

int HDD_Smart_ReturnStatus (void)
{
#ifdef _TMS_

  unsigned char         CommandBlock[HDIO_DRIVE_TASK_HDR_SIZE] = {WIN_SMART,        //COMMAND
                                                                  SMART_STATUS,     //FEATURE
                                                                  0x00,             //NSECTOR
                                                                  0,                //SECTOR
                                                                  0x4f,             //LCYL
                                                                  0xc2,             //HCYL
                                                                  0,                //SELECT
                                                                  0};               //COMMAND

  if(SendHDDCommand(HDIO_DRIVE_TASK, CommandBlock, 0)) return 19;
  if((CommandBlock[4] == 0x4f) && (CommandBlock[5] == 0xc2)) return 0;
  if((CommandBlock[4] == 0xf4) && (CommandBlock[5] == 0x2c)) return 20;
  return 19;

#else

  int                   Ret;

  Ret = SendHDDCommand (SMART_STATUS, 0, 0, 0x4F, 0xC2, 0x00, WIN_SMART);
  if (Ret != 0)
  {
    //If the ERR flag in the status register has been set,
    //the SMART feature has been disabled.
#ifdef DEBUG_FIREBIRDLIB
    TAP_Print ("FireBirdLib: HDDSmartReturnStatus: Ret=%d\r\n", Ret);
#endif
    return 19;
  }
  if (*HDD_pLBAMid == 0x4F) return 0;
                       else return 20;

#endif

}

