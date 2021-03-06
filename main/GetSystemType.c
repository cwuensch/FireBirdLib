#include                "libFireBird.h"

SYSTEM_TYPE GetSystemType(void)
{
  TRACEENTER();

  static SYSTEM_TYPE    SystemType = ST_UNKNOWN;
  word                  SystemID;
  tToppyInfo           *ToppyInfo;
  tFWDATHeader         *FWDatHeader;
  int                   i;

  if(SystemType == ST_UNKNOWN)
  {
    SystemID = TAP_GetSystemId();
    if(LoadFirmwareDat(&FWDatHeader, &ToppyInfo, NULL))
    {
      for(i = 0; i < (int)FWDatHeader->NrOfToppyInfoEntries; i++, ToppyInfo++)
      {
        if(ToppyInfo->SysID == SystemID)
        {
          SystemType = ToppyInfo->SystemType;

          TRACEEXIT();
          return SystemType;
        }
      }
    }
    else
    {
      switch(SystemID)
      {
//        case 22010:    // TMS-2100
        case 22121:    // SRP-2410
        case 22122:    // SRP-2410M
        case 22120:    // SRP-2401CI+ Conax
        case 22130:    // SRP-2401CI+
//        case 22361:    // SRP-2401CI+ M7 ?
//        case 22561:    // SRP-2401CI+ M7 ?
        case 22570:    // SRP-2401CI+ Eco
          SystemType = ST_TMSS;
          break;

        case 42031:    // CRP-2401CI+
        case 42561:    // CRP-2401CI+ Conax
          SystemType = ST_TMSC;
          break;
      }
    }
  }

  TRACEEXIT();
  return SystemType;
}
