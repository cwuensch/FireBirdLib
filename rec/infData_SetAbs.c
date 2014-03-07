#include <stdio.h>
#include <string.h>
#include <tap.h>
#include "FBLib_rec.h"

extern FILE            *infDatainfFileAbs;

bool infData_SetAbs(char *infFileName, char *NameTag, dword PayloadSize, byte *Payload)
{
  bool                  ret;
  tTFRPlusHdr           TFRPlusHdr;

  TRACEENTER();

  ret = FALSE;

  infData_DeleteAbs(infFileName, NameTag);
  if(NameTag && *NameTag && infData_OpenFileAbs(infFileName))
  {
    ret = TRUE;

    //Ensure the minimum size of INFDATASTART bytes
    if(infData_FlenAbs() < INFDATASTART)
    {
      infData_CloseFileAbs();
      infData_TruncateAbs(infFileName, INFDATASTART);
      infData_OpenFileAbs(infFileName);
    }

    //Add the data block
    fseek(infDatainfFileAbs, 0, SEEK_END);

    memcpy(TFRPlusHdr.Magic, INFDATMAGIC, 4);
    TFRPlusHdr.NameTagLen = strlen(NameTag) + 1;
    TFRPlusHdr.PayloadSize = PayloadSize;

    if(PayloadSize && (Payload == NULL))
    {
      LogEntryFBLibPrintf(TRUE, "infData: PayloadSize of %s:%s is not 0, but data pointer is NULL!", infFileName, NameTag);
      TFRPlusHdr.PayloadSize = 0;
      ret = FALSE;
    }

    fwrite(&TFRPlusHdr, sizeof(tTFRPlusHdr), 1, infDatainfFileAbs);
    fwrite(NameTag, TFRPlusHdr.NameTagLen, 1, infDatainfFileAbs);

    if(Payload)
      fwrite(Payload, TFRPlusHdr.PayloadSize, 1, infDatainfFileAbs);
  }
  infData_CloseFileAbs();

  TRACEEXIT();
  return ret;
}
