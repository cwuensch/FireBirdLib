#include                <string.h>
#include                "FBLib_flash.h"

bool FlashTransponderTablesGetInfo(int SatNum, int TransponderNum, tFlashTransponderTable *TransponderTable)
{
  //SatNum out of range
  if((SatNum < 0) || (SatNum >= FlashSatTablesGetTotal())) return FALSE;

  //TransponderNum out of range
  if((TransponderNum < 0) || (TransponderNum >= FlashTransponderTablesGetTotal(SatNum))) return FALSE;

  //TransponderTable is NULL
  if(!TransponderTable) return FALSE;

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
    case ST_TF7k7HDPVR: return FALSE;

    case ST_TMSS:
    {
      TYPE_TpInfo_TMSS *p;
      int               d, i, TPIdx;

      p = (TYPE_TpInfo_TMSS*)(FIS_vFlashBlockTransponderInfo());
      if(!p) return FALSE;

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
      if((i >= d) || (p->SatIdx != SatNum) || (TPIdx != TransponderNum)) return FALSE;

      return FlashTransponderTablesDecode(p, TransponderTable);
    }

    case ST_TMST:
    {
      TYPE_TpInfo_TMST     *p;

      p = (TYPE_TpInfo_TMST*)FIS_vFlashBlockTransponderInfo();
      if(!p) return FALSE;
      p = p + TransponderNum;

      return FlashTransponderTablesDecode(p, TransponderTable);
    }

    case ST_TMSC:
    {
      TYPE_TpInfo_TMSC     *p;

      p = (TYPE_TpInfo_TMSC*)FIS_vFlashBlockTransponderInfo();
      if(!p) return FALSE;
      p = p + TransponderNum;

      return FlashTransponderTablesDecode(p, TransponderTable);
    }

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashTransponderTablesDecode(void *Data, tFlashTransponderTable *TransponderTable)
{
  //TransponderTable is NULL
  if(!Data || !TransponderTable) return FALSE;

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
    case ST_TF7k7HDPVR: return FALSE;

    case ST_TMSS: return FlashTransponderTablesDecode_ST_TMSS(Data, TransponderTable);
    case ST_TMST: return FlashTransponderTablesDecode_ST_TMST(Data, TransponderTable);
    case ST_TMSC: return FlashTransponderTablesDecode_ST_TMSC(Data, TransponderTable);

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashTransponderTablesDecode_ST_TMSS(TYPE_TpInfo_TMSS *Data, tFlashTransponderTable *TransponderTable)
{
  memset(TransponderTable, 0, sizeof(tFlashTransponderTable));
  TransponderTable->SatIndex          = Data->SatIdx;
  TransponderTable->Polarisation      = Data->Polar;
  TransponderTable->ModSystem         = Data->ModulationSystem;
  TransponderTable->Modulation        = Data->ModulationType;
  TransponderTable->FEC               = Data->FECMode;
  TransponderTable->Pilot             = Data->Pilot;
  TransponderTable->Frequency         = Data->Frequency;
  TransponderTable->SymbolRate        = Data->SymbolRate;
  TransponderTable->TSID              = Data->TSID;
  TransponderTable->ClockSync         = Data->AllowTimeSync;
  TransponderTable->OriginalNetworkID = Data->OriginalNetworkID;
  TransponderTable->unused1           = Data->unused1;
  TransponderTable->unused2           = Data->unused2;
  TransponderTable->unused3           = Data->unused3;
  TransponderTable->unused4           = Data->unused4;

  return TRUE;
}

bool FlashTransponderTablesDecode_ST_TMST(TYPE_TpInfo_TMST *Data, tFlashTransponderTable *TransponderTable)
{
  memset(TransponderTable, 0, sizeof(tFlashTransponderTable));
  TransponderTable->SatIndex          = Data->SatIdx;
  TransponderTable->ChannelNr         = Data->ChannelNr;
  TransponderTable->Bandwidth         = Data->Bandwidth;
  TransponderTable->Frequency         = Data->Frequency;
  TransponderTable->TSID              = Data->TSID;
  TransponderTable->LPHP              = Data->LPHP;
  TransponderTable->OriginalNetworkID = Data->OriginalNetworkID;
  TransponderTable->NetworkID         = Data->NetworkID;
  TransponderTable->unused1           = Data->unused1;
  TransponderTable->unused2           = Data->unused2;

  return TRUE;
}

bool FlashTransponderTablesDecode_ST_TMSC(TYPE_TpInfo_TMSC *Data, tFlashTransponderTable *TransponderTable)
{
  memset(TransponderTable, 0, sizeof(tFlashTransponderTable));
  TransponderTable->Frequency         = Data->Frequency >> 8;
  TransponderTable->SymbolRate        = Data->SymbolRate;
  TransponderTable->TSID              = Data->TSID;
  TransponderTable->OriginalNetworkID = Data->OriginalNetworkID;
  TransponderTable->Modulation        = Data->ModulationType;
  TransponderTable->unused1           = Data->unused1;

  return TRUE;
}
