#include <string.h>
#include <tap.h>
#include "FBLib_rec.h"

bool infData_Set(char *infFileName, char *NameTag, dword PayloadSize, byte *Payload)
{
  bool                  ret;
  tTFRPlusHdr           TFRPlusHdr;
  char                  s[256];

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("infData_Set");
  #endif

  ret = FALSE;

  infData_Delete(infFileName, NameTag);
  if(NameTag && *NameTag && infData_OpenFile(infFileName))
  {
    ret = TRUE;

    //Ensure the minimum size of INFDATASTART bytes
    if(TAP_Hdd_Flen(infDatainfFile) < INFDATASTART)
    {
      infData_CloseFile();
      infData_Truncate(infFileName, INFDATASTART);
      infData_OpenFile(infFileName);
    }

    //Add the data block
    TAP_Hdd_Fseek(infDatainfFile, 0, SEEK_END);

    memcpy(TFRPlusHdr.Magic, INFDATMAGIC, 4);
    TFRPlusHdr.NameTagLen = strlen(NameTag) + 1;
    TFRPlusHdr.PayloadSize = PayloadSize;

    if(PayloadSize && (Payload == NULL))
    {
      TAP_SPrint(s, "PayloadSize of %s:%s is not 0, but data pointer is NULL!\n", infFileName, NameTag);
      LogEntryFBLibPrintf(TRUE, "infData: %s", s);
      TFRPlusHdr.PayloadSize = 0;
      ret = FALSE;
    }

    TAP_Hdd_Fwrite(&TFRPlusHdr, sizeof(tTFRPlusHdr), 1, infDatainfFile);
    TAP_Hdd_Fwrite(NameTag, TFRPlusHdr.NameTagLen, 1, infDatainfFile);

    if(Payload)
      TAP_Hdd_Fwrite(Payload, TFRPlusHdr.PayloadSize, 1, infDatainfFile);
  }
  infData_CloseFile();

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
