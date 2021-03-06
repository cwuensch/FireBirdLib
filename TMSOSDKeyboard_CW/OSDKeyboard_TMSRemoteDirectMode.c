#include                "FBLib_TMSOSDKeyboard.h"

void OSDKeyboard_TMSRemoteDirectMode(bool DirectMode)
{
  TAPCOM_Channel      Channel;

  TRACEENTER();
  Channel = TAPCOM_OpenChannel(TMSREMOTETAPID, DirectMode ? TMSREMOTE_TAPCOM_SERVICE_SETDIRECT : TMSREMOTE_TAPCOM_SERVICE_CLEARDIRECT, 0, NULL);
  TAPCOM_CloseChannel(Channel);
  TRACEEXIT();
}
