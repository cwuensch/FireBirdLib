#include                <string.h>
#include                "FBLib_flash.h"

bool FlashServiceSetInfo(int SvcType, int SvcNum, tFlashService *Service)
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
    case ST_T5800:
    case ST_TF7k7HDPVR: return FALSE;

    case ST_TMSS:
    {
      TYPE_Service_TMSS    *p;

      if(SvcType == SVC_TYPE_Tv)
        p = (TYPE_Service_TMSS*)(FIS_vFlashBlockTVServices() + SvcNum * sizeof(TYPE_Service_TMSS));
      else
        p = (TYPE_Service_TMSS*)(FIS_vFlashBlockRadioServices() + SvcNum * sizeof(TYPE_Service_TMSS));
      if(!p) return FALSE;

      return FlashServiceEncode(p, Service);
    }

    case ST_TMST:
    {
      TYPE_Service_TMST    *p;

      if(SvcType == SVC_TYPE_Tv)
        p = (TYPE_Service_TMST*)(FIS_vFlashBlockTVServices() + SvcNum * sizeof(TYPE_Service_TMST));
      else
        p = (TYPE_Service_TMST*)(FIS_vFlashBlockRadioServices() + SvcNum * sizeof(TYPE_Service_TMST));
      if(!p) return FALSE;

      return FlashServiceEncode(p, Service);
    }

    case ST_TMSC:
    {
      TYPE_Service_TMSC    *p;

      if(SvcType == SVC_TYPE_Tv)
        p = (TYPE_Service_TMSC*)(FIS_vFlashBlockTVServices() + SvcNum * sizeof(TYPE_Service_TMSC));
      else
        p = (TYPE_Service_TMSC*)(FIS_vFlashBlockRadioServices() + SvcNum * sizeof(TYPE_Service_TMSC));
      if(!p) return FALSE;

      return FlashServiceEncode(p, Service);
    }

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashServiceEncode(void *Data, tFlashService *Service)
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
    case ST_T5800:
    case ST_TF7k7HDPVR: return FALSE;

    case ST_TMSS: return FlashServiceEncode_ST_TMSS(Data, Service);
    case ST_TMST: return FlashServiceEncode_ST_TMST(Data, Service);
    case ST_TMSC: return FlashServiceEncode_ST_TMSC(Data, Service);

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashServiceEncode_ST_TMSS(TYPE_Service_TMSS *Data, tFlashService *Service)
{

  char                 *Text;

  memset(Data, 0, sizeof(TYPE_Service_TMSS));
  Data->SatIdx          = Service->SatIndex;
  Data->VideoStreamType = Service->VideoStreamType;
  Data->DelFlag         = Service->FlagDelete;
  Data->CASFlag         = Service->FlagCAS;
  Data->LockFlag        = Service->FlagLock;
  Data->SkipFlag        = Service->FlagSkip;
  Data->TunerNum        = Service->Tuner;
  Data->TPIdx           = Service->TransponderIndex;
  Data->SVCID           = Service->ServiceID;
  Data->PMTPID          = Service->PMTPID;
  Data->PCRPID          = Service->PCRPID;
  Data->VideoPID        = Service->VideoPID;
  Data->AudioPID        = Service->AudioPID;
  Data->LCN             = Service->LCN;
  Data->AudioStreamType = Service->AudioStreamType;
  Data->unknown1        = Service->unknown1;
  memcpy(Data->unknown2, Service->unknown2, 6);

  Text = (char*)FIS_vFlashBlockServiceName();
  while(Text[0])
  {
    if(strncmp(Text, Service->ServiceName, MAX_SvcName) == 0) break;
    Text += (strlen(Text) + 1);
  }
  if(!Text[0]) strncpy(Text, Service->ServiceName, MAX_SvcName);
  Data->NameOffset = (dword)Text - FIS_vFlashBlockServiceName();

  Text = (char*)FIS_vFlashBlockProviderInfo();
  Data->ProviderIdx = 0;
  while(Text[0])
  {
    if(strncmp(Text, Service->ProviderName, 20) == 0) break;
    Text += 21;
    Data->ProviderIdx = Data->ProviderIdx + 1;
  }
  if(!*Text) strncpy(Text, Service->ProviderName, 20);

  return TRUE;
}

bool FlashServiceEncode_ST_TMST(TYPE_Service_TMST *Data, tFlashService *Service)
{
  //The TV and radio service structures are identical
  return FlashServiceEncode_ST_TMSS(Data, Service);
}

bool FlashServiceEncode_ST_TMSC(TYPE_Service_TMSC *Data, tFlashService *Service)
{
  //The TV and radio service structures are identical
  return FlashServiceEncode_ST_TMSS(Data, Service);
}
