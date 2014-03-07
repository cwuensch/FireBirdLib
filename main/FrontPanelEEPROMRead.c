#include                <unistd.h>
#include                "../libFireBird.h"

bool FrontPanelEEPROMRead(word Address, byte *Data)
{
  TRACEENTER();

  byte                  ExpectedResponseCode = 0xd1;
  int                   ExpectedResponseLen = 5;

  int                  *__frontfd;
  int                   localfd = 0;
  ssize_t               ret;
  dword                 WaitTimeout;
  byte                  Buffer[128];
  byte                  InBufferPtr;
  byte                  Retry;
  bool                  Timeout, Result;

  Result = FALSE;

  __frontfd = (int*)FIS_vfrontfd();

  if(FrontPanelGetPatch(NULL, NULL) && __frontfd && (Address < 512) && Data)
  {
    //Take over the handle from _frontfd
    localfd = *__frontfd;
    *__frontfd = 0;

    Retry = 3;
    do
    {
      //Query: 02 D2 EAH EAL 03
      Buffer[0] = 0x02;
      Buffer[1] = 0xD2;
      Buffer[2] = Address >> 8;
      Buffer[3] = Address & 0xff;
      Buffer[4] = 0x03;

      write(localfd, Buffer, 5);
      fsync(localfd);

      //Wait for the D1 response
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
      //Response: 00 02 D1 DTA 03
      if(Data) *Data = Buffer[3];
      Result = TRUE;
    }

    //Restore the communication
    *__frontfd = localfd;
    localfd = 0;
  }

  return Result;
}
