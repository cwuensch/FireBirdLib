#include "FBLib_shutdown.h"
#include "../libFireBird.h"

bool Reboot (bool StopRecordings)
{
#ifdef _TMS_
  TAP_Reboot();
#else
  dword                 HDDShutdown;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return FALSE;

  if (HDD_isRecording (0) || HDD_isRecording (1))
  {
    if (StopRecordings)
    {
      Shutdown (TaskRecordings);
    }
    else
    {
      return FALSE;
    }
  }

  //Remove the HDD shutdown command
  //Some f/w versions have these power down routine twice. Patch them all
  do
  {
    HDDShutdown = FIS_vHDDShutdown();
    if (HDDShutdown) *(dword*)HDDShutdown = HDDIDLE;

  } while (HDDShutdown);

  CallBIOS (14, 1, 4, 0, 0);
#endif

  return TRUE;
}
