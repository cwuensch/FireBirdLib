#include                <unistd.h>
#include                "../libFireBird.h"

bool FrontPanelGetPatch(byte *Version, byte *Type)
{
  TRACEENTER();

  byte                  ExpectedResponseCode = 0xf2;
  int                   ExpectedResponseLen = 6;

  int                  *__frontfd = NULL;
  int                   localfd = 0;
  ssize_t               ret;
  dword                 WaitTimeout;
  byte                  Buffer[128];
  byte                  InBufferPtr;
  byte                  Retry;
  bool                  Timeout;

  static byte           FPVersion = 0, FPType = 0;
  static bool           AlreadyChecked = FALSE;
  static bool           Result = FALSE;

  if(!AlreadyChecked)
  {
    //Find the int* variable _frontfd
    __frontfd = (int*)FIS_vfrontfd();
    if(__frontfd == NULL)
    {
      TRACEEXIT();
      return FALSE;
    }

    //Take over the handle from _frontfd
    localfd = *__frontfd;
    *__frontfd = 0;

    Retry = 3;
    do
    {
      //Send the F0 command
      Buffer[0] = 0x02;
      Buffer[1] = 0xf0;
      Buffer[2] = 0x03;

      write(localfd, Buffer, 3);
      fsync(localfd);

      //Wait for the F2 response
      InBufferPtr = 0;
      WaitTimeout = TAP_GetTick() + 50;

      do
      {
        ret = read(localfd, &Buffer[InBufferPtr], 64);
        if(ret > 0) InBufferPtr += ret;
        Timeout = (TAP_GetTick() > WaitTimeout);
      }while(!Timeout && (InBufferPtr != ExpectedResponseLen));

      Retry--;

    }while((Buffer[2] != ExpectedResponseCode) && !Timeout && (Retry > 0));

    if((InBufferPtr == ExpectedResponseLen) && (Buffer[2] == ExpectedResponseCode))
    {
      FPVersion = Buffer[3];
      FPType = Buffer[4];
      Result = TRUE;
    }

    //Restore the communication
    *__frontfd = localfd;
    localfd = 0;
  }

  AlreadyChecked = TRUE;
  if(Version) *Version = FPVersion;
  if(Type) *Type = FPType;

  TRACEEXIT();
  return Result;
}
