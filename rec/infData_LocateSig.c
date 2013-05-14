#include <string.h>
#include <tap.h>
#include "FBLib_rec.h"

bool infData_LocateSig(char *NameTag, dword *PayloadSize)
{
  bool                  ret;
  tTFRPlusHdr           TFRPlusHdr;
  char                  NameTagHdr[256];
  dword                 CurrentPos;

  //Format
  //  char Magic[4]             //TFr+
  //  dword PayloadSize
  //  word NameTagLength        //includes the NULL character
  //  char NameTag[SigLength]
  //  byte Payload[PayloadSize]

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("infData_LocateSig");
  #endif

  ret = FALSE;
  if(PayloadSize) *PayloadSize = 0;

  if(NameTag && *NameTag && infDatainfFile && (TAP_Hdd_Flen(infDatainfFile) > INFDATASTART))
  {
    TAP_Hdd_Fseek(infDatainfFile, INFDATASTART, SEEK_SET);

    while((CurrentPos = TAP_Hdd_Ftell(infDatainfFile)) < TAP_Hdd_Flen(infDatainfFile))
    {
      TAP_Hdd_Fread(&TFRPlusHdr, sizeof(tTFRPlusHdr), 1, infDatainfFile);

      //Stop parsing if the magic is invalid
      if(memcmp(TFRPlusHdr.Magic, INFDATMAGIC, 4) != 0) break;

      TAP_Hdd_Fread(NameTagHdr, TFRPlusHdr.NameTagLen, 1, infDatainfFile);

      if(strcmp(NameTag, NameTagHdr) == 0)
      {
        ret = TRUE;
        if(PayloadSize) *PayloadSize = TFRPlusHdr.PayloadSize;
        TAP_Hdd_Fseek(infDatainfFile, CurrentPos, SEEK_SET);
        break;
      }
      TAP_Hdd_Fseek(infDatainfFile, TFRPlusHdr.PayloadSize, SEEK_CUR);
    }
  }

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
