#include "FBLib_hdd.h"
#include "../libFireBird.h"

int HDD_APM_Disable (void)
{
#ifdef _TMS_

  unsigned char         CommandBlock[HDIO_DRIVE_TASK_HDR_SIZE] = {WIN_SETFEATURES,      //COMMAND
                                                                  SETFEATURES_DIS_APM,  //FEATURE
                                                                  0,                    //NSECTOR
                                                                  0,                    //SECTOR
                                                                  0,                    //LCYL
                                                                  0,                    //HCYL
                                                                  0,                    //SELECT
                                                                  0};                   //COMMAND

  return SendHDDCommand(HDIO_DRIVE_TASK, CommandBlock, 0);

#else

  int                   Ret;

  Ret = SendHDDCommand (SETFEATURES_DIS_APM, 0x00, 0, 0, 0, 0xA0, WIN_SETFEATURES);
  if (Ret != 0)
  {
#ifdef DEBUG_FIREBIRDLIB
    TAP_Print ("FireBirdLib: HDDDisableAPM: Ret=%d\r\n", Ret);
#endif

    //Send a "APM Maximum Performance" to circumvent devices, which do not implement the "Disable APM" command
    Ret = SendHDDCommand (SETFEATURES_EN_APM, 0xFE, 0, 0, 0, 0xA0, WIN_SETFEATURES);
#ifdef DEBUG_FIREBIRDLIB
    if (Ret != 0) TAP_Print ("FireBirdLib: HDDAPMEnable: Ret=%d\r\n", Ret);
#endif
  }
  return Ret;

#endif
}
