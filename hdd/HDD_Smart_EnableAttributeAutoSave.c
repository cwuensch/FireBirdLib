#include "FBLib_hdd.h"
#include "../libFireBird.h"

int HDD_Smart_EnableAttributeAutoSave (void)
{
#ifdef _TMS_

  unsigned char         CommandBlock[HDIO_DRIVE_TASK_HDR_SIZE] = {WIN_SMART,        //COMMAND
                                                                  SMART_AUTOSAVE,   //FEATURE
                                                                  0xf1,             //NSECTOR
                                                                  0,                //SECTOR
                                                                  0x4f,             //LCYL
                                                                  0xc2,             //HCYL
                                                                  0,                //SELECT
                                                                  0};               //COMMAND

  return SendHDDCommand(HDIO_DRIVE_TASK, CommandBlock, 0);

#else

  int                   Ret;

  Ret = SendHDDCommand (SMART_AUTOSAVE, 0xF1, 0, 0x4F, 0xC2, 0xA0, WIN_SMART);
#ifdef DEBUG_FIREBIRDLIB
  if (Ret != 0) TAP_Print ("FireBirdLib: HDDSmartEnableAttributeAutoSave: Ret=%d\r\n", Ret);
#endif
  return Ret;

#endif
}
