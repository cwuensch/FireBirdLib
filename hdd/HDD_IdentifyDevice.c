#include "FBLib_hdd.h"
#include "../libFireBird.h"

bool HDD_IdentifyDevice (char *IdentifyDeviceBuffer)
{
#ifdef _TMS_

#include                <linux/hdreg.h>
#include                <fcntl.h>
#include                <sys/ioctl.h>
#include                <linux/fs.h>
#include                <unistd.h>

  unsigned char         parms[HDIO_DRIVE_CMD_HDR_SIZE + sizeof(struct hd_driveid)] = {WIN_IDENTIFY, 0, 0, 1,};

  if(SendHDDCommand(HDIO_DRIVE_CMD, parms, sizeof(struct hd_driveid))) return FALSE;
  memcpy(IdentifyDeviceBuffer, &parms[4], sizeof(struct hd_driveid));

#else

  int                   CharCount;
  dword                 RS;
  word                  Data;

  RS = intLock ();
  if (SendHDDCommand (0, 0, 0, 0, 0, 0xA0, 0xEC) != 0) return FALSE;

  //Copy the data into a buffer
  for (CharCount = 0; CharCount < 256; CharCount++)
  {
    Data = *HDD_pData;
    IdentifyDeviceBuffer [2 * CharCount]  = (Data >> 8);
    IdentifyDeviceBuffer [2 * CharCount + 1] = (Data & 0xFF);
  }

  //Reset the PIC2 interrupt 8 and 9 flags
  *EMMA_PIO1_Status = *EMMA_PIO1_Status & 0xffefffff;
  *EMMA_PIO2_Status = 0xf7ff;
  intUnlock (RS);

#endif

  return TRUE;
}
