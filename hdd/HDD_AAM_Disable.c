#include "FBLib_hdd.h"
#include "../libFireBird.h"

int HDD_AAM_Disable (void)
{
#ifdef _TMS_

  unsigned char         CommandBlock[HDIO_DRIVE_TASK_HDR_SIZE] = {WIN_SETFEATURES,      //COMMAND
                                                                  SETFEATURES_DIS_AAM,  //FEATURE
                                                                  0,                    //NSECTOR
                                                                  0,                    //SECTOR
                                                                  0,                    //LCYL
                                                                  0,                    //HCYL
                                                                  0,                    //SELECT
                                                                  0};                   //COMMAND

  return SendHDDCommand(HDIO_DRIVE_TASK, CommandBlock, 0);

#else

  int                   Ret;

  Ret = SendHDDCommand (SETFEATURES_DIS_AAM, 0, 0, 0, 0, 0xA0, WIN_SETFEATURES);
  if (Ret != 0)
  {
#ifdef DEBUG_FIREBIRDLIB
    TAP_Print ("FireBirdLib: HDDDisableAAM: Ret=%d\r\n", Ret);
#endif

    //Send a "AAM Maximum Performance" to circumvent devices, which do not implement the "Disable AAM" command
    Ret=SendHDDCommand (SETFEATURES_EN_AAM, 0xFE, 0, 0, 0, 0xA0, WIN_SETFEATURES);
#ifdef DEBUG_FIREBIRDLIB
    if (Ret != 0) TAP_Print ("FireBirdLib: HDDAAMDisable: Ret=%d\r\n", Ret);
#endif
  }
  return Ret;

#endif
}
