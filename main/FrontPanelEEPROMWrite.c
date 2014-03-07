#include                <unistd.h>
#include                "../libFireBird.h"

bool FrontPanelEEPROMWrite(word Address, byte Data)
{
  TRACEENTER();

  byte                  Buffer[6];
  bool                  ret;
  int                  *__frontfd;

  ret = FALSE;

  __frontfd = (int*)FIS_vfrontfd();

  if(GetFrontPanelPatch(NULL, NULL) && __frontfd && (Address < 512))
  {
    //Query: 02 D3 EAH EAL DTA 03

    Buffer[0] = 0x02;
    Buffer[1] = 0xD3;
    Buffer[2] = Address >> 8;
    Buffer[3] = Address & 0xff;
    Buffer[4] = Data;
    Buffer[5] = 0x03;

    write(*__frontfd, Buffer, 6);
    fsync(*__frontfd);

    ret = TRUE;
  }

  TRACEEXIT();
  return ret;
}
