#include                <string.h>
#include                "FBLib_flash.h"

bool FlashTransponderTablesGetInfo(int SatNum, int TransponderNum, tFlashTransponderTable *TransponderTable)
{
  TRACEENTER();

  bool ret;

  //TransponderTable is NULL
  if(!TransponderTable)
  {
    TRACEEXIT();
    return FALSE;
  }

  //SatNum out of range
  if((SatNum < 0) || (SatNum >= FlashSatTablesGetTotal()))
  {
    TRACEEXIT();
    return FALSE;
  }

  //TransponderNum out of range
  if((TransponderNum < 0) || (TransponderNum >= FlashTransponderTablesGetTotal(SatNum)))
  {
    TRACEEXIT();
    return FALSE;
  }

  ret = FALSE;
  switch(GetSystemType())
  {
    //Unknown and old 5k/6k systems are not supported
    case ST_UNKNOWN:
    case ST_S:
    case ST_ST:
    case ST_T:
    case ST_C:
    case ST_CT:
    case ST_T5700:
    case ST_T5800:
    case ST_TF7k7HDPVR: break;

    case ST_TMSS:
    {
      TYPE_TpInfo_TMSS *p;
      int               d, i, TPIdx;

      p = (TYPE_TpInfo_TMSS*)(FIS_vFlashBlockTransponderInfo());
      if(!p)
      {
        TRACEEXIT();
        return FALSE;
      }

      d = *(int*)FIS_vFlashBlockTransponderInfo();
      TPIdx = 0;
      for(i = 0; i < d; i++)
      {
        if(p->SatIdx == SatNum)
        {
          if(TPIdx == TransponderNum) break;

          TPIdx++;
        }
        p++;
      }
      if((i >= d) || (p->SatIdx != SatNum) || (TPIdx != TransponderNum))
      {
        TRACEEXIT();
        return FALSE;
      }

      ret = FlashTransponderTablesDecode(p, TransponderTable);
      break;
    }

    case ST_TMST:
    {
      TYPE_TpInfo_TMST     *p;

      p = (TYPE_TpInfo_TMST*)FIS_vFlashBlockTransponderInfo();
      if(!p)
      {
        TRACEEXIT();
        return FALSE;
      }

      p = p + TransponderNum;

      ret = FlashTransponderTablesDecode(p, TransponderTable);
      break;
    }

    case ST_TMSC:
    {
      TYPE_TpInfo_TMSC     *p;

      p = (TYPE_TpInfo_TMSC*)FIS_vFlashBlockTransponderInfo();
      if(!p)
      {
        TRACEEXIT();
        return FALSE;
      }
      p = p + TransponderNum;

      ret = FlashTransponderTablesDecode(p, TransponderTable);
      break;
    }

    case ST_NRTYPES: break;
  }

  TRACEEXIT();
  return ret;
}
