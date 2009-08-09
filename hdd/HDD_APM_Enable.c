#include "FBLib_hdd.h"
#include "../libFireBird.h"

int HDD_APM_Enable (byte APMLevel)
{
#ifdef _TMS_

  unsigned char         CommandBlock[HDIO_DRIVE_TASK_HDR_SIZE] = {WIN_SETFEATURES,      //COMMAND
                                                                  SETFEATURES_EN_APM,   //FEATURE
                                                                  APMLevel,             //NSECTOR
                                                                  0,                    //SECTOR
                                                                  0,                    //LCYL
                                                                  0,                    //HCYL
                                                                  0,                    //SELECT
                                                                  0};                   //COMMAND

  return SendHDDCommand(HDIO_DRIVE_TASK, CommandBlock, 0);

#else

  int                   Ret;

  Ret = SendHDDCommand (SETFEATURES_EN_APM, APMLevel, 0, 0, 0, 0xA0, WIN_SETFEATURES);
#ifdef DEBUG_FIREBIRDLIB
  if (Ret != 0) TAP_Print ("FireBirdLib: HDDAPMEnable: Ret=%d\r\n", Ret);
#endif
  return Ret;

#endif
}
