#include                "../libFireBird.h"

char *GetApplVer(void)
{
  static void (*Appl_SetApplVer)(char *) = NULL;
  static char  *osdOutBuf = NULL;

  if(!osdOutBuf)
  {
    osdOutBuf = (void*)TryResolve("_osdOutBuf");
    if(!osdOutBuf) return NULL;
  }

  osdOutBuf[0] = '\0';

  if(!Appl_SetApplVer)
  {
    Appl_SetApplVer = (void*)TryResolve("_Z15Appl_SetApplVerPc");
    if(!Appl_SetApplVer) return osdOutBuf;
  }

  //According to the disass listing, the char* parameter is not used.
  //The output is buffered into the 0x1000 bytes buffer _osdOutBuf.
  Appl_SetApplVer(NULL);

  return osdOutBuf;
}
