#include                <string.h>
#include                "FBLib_flash.h"

bool FlashServiceGetInfo(int SvcType, int SvcNum, tFlashService *Service)
{
  //SvcType out of range
  if((SvcType < 0) || (SvcType > SVC_TYPE_Radio)) return FALSE;

  //SvcNum out of range
  if((SvcNum < 0) || (SvcNum >= FlashServiceGetTotal(SvcType))) return FALSE;

  //Service is NULL
  if(!Service) return FALSE;

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
    case ST_TUK:  return FALSE;

    case ST_TMSS:
    {
      TYPE_Service_TMSS    *p;

      if(SvcType == SVC_TYPE_Tv)
        p = (TYPE_Service_TMSS*)(FIS_vFlashBlockTVServices() + SvcNum * sizeof(TYPE_Service_TMSS));
      else
        p = (TYPE_Service_TMSS*)(FIS_vFlashBlockRadioServices() + SvcNum * sizeof(TYPE_Service_TMSS));
      if(!p) return FALSE;

      return FlashServiceDecode(p, Service);
    }

    case ST_TMST:
    {
      TYPE_Service_TMST    *p;

      if(SvcType == SVC_TYPE_Tv)
        p = (TYPE_Service_TMST*)(FIS_vFlashBlockTVServices() + SvcNum * sizeof(TYPE_Service_TMST));
      else
        p = (TYPE_Service_TMST*)(FIS_vFlashBlockRadioServices() + SvcNum * sizeof(TYPE_Service_TMST));
      if(!p) return FALSE;

      return FlashServiceDecode(p, Service);
    }

    case ST_TMSC:
    {
      TYPE_Service_TMSC    *p;

      if(SvcType == SVC_TYPE_Tv)
        p = (TYPE_Service_TMSC*)(FIS_vFlashBlockTVServices() + SvcNum * sizeof(TYPE_Service_TMSC));
      else
        p = (TYPE_Service_TMSC*)(FIS_vFlashBlockRadioServices() + SvcNum * sizeof(TYPE_Service_TMSC));
      if(!p) return FALSE;

      return FlashServiceDecode(p, Service);
    }

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashServiceDecode(void *Data, tFlashService *Service)
{
  //Service is NULL
  if(!Data || !Service) return FALSE;

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
    case ST_TUK:  return FALSE;

    case ST_TMSS: return FlashServiceDecode_ST_TMSS(Data, Service);
    case ST_TMST: return FlashServiceDecode_ST_TMST(Data, Service);
    case ST_TMSC: return FlashServiceDecode_ST_TMSC(Data, Service);

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashServiceDecode_ST_TMSS(TYPE_Service_TMSS *Data, tFlashService *Service)
{

  char                 *Text;

  memset(Service, 0, sizeof(tFlashService));
  Service->SatIndex        = Data->SatIdx;
  Service->VideoStreamType = Data->VideoStreamType;
  Service->FlagDelete      = Data->DelFlag;
  Service->FlagCAS         = Data->CASFlag;
  Service->FlagLock        = Data->LockFlag;
  Service->FlagSkip        = Data->SkipFlag;
  Service->Tuner           = Data->TunerNum;
  Service->TransponderIndex= Data->TPIdx;
  Service->ServiceID       = Data->SVCID;
  Service->PMTPID          = Data->PMTPID;
  Service->PCRPID          = Data->PCRPID;
  Service->VideoPID        = Data->VideoPID;
  Service->AudioPID        = Data->AudioPID;
  Service->LCN             = Data->LCN;
  Service->AudioStreamType = Data->AudioStreamType;
  Service->unknown1        = Data->unknown1;
  memcpy(Service->unknown2, Data->unknown2, 6);

  Text = (char*)(FIS_vFlashBlockServiceName() + Data->NameOffset);
  strncpy(Service->ServiceName, Text, MAX_SvcName - 1);

  Text = (char*)(FIS_vFlashBlockProviderInfo() + 21 * Data->ProviderIdx);
  strncpy(Service->ProviderName, Text, 20);

  return TRUE;
}

bool FlashServiceDecode_ST_TMST(TYPE_Service_TMST *Data, tFlashService *Service)
{
  //The TV and radio service structures are identical
  return FlashServiceDecode_ST_TMSS(Data, Service);
}

bool FlashServiceDecode_ST_TMSC(TYPE_Service_TMSC *Data, tFlashService *Service)
{
  //The TV and radio service structures are identical
  return FlashServiceDecode_ST_TMSS(Data, Service);
}
