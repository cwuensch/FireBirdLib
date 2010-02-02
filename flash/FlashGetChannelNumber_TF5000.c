#include "FBLib_flash.h"

#ifndef _TMS_

void FlashGetChannelNumber (int chType, int chNum, dword *Frequency, dword *ChannelNumber)
{
  TYPE_Service          *FlashService;
  TYPE_TpInfoT          *FlashTpInfo = NULL;
  TYPE_TpInfoT5700      *FlashTp5700Info = NULL;

  if (!LibInitialized) InitTAPex ();

  //Don't do anything on non DVB-ts
  if(!LibInitialized || (FlashOffset == 0) || ((SystemType != ST_DVBT) && (SystemType != ST_DVBT5700)))
  {
    *Frequency = 0;
    *ChannelNumber = 0;
    return;
  }

  //Let FlashService point to the TV or radio service table
  if (chType == SVC_TYPE_Tv) FlashService = (TYPE_Service *) (FlashBlockOffset [TVServices] + 4);
                        else FlashService = (TYPE_Service *) (FlashBlockOffset [RadioServices] + 4);

  //Set a pointer to the transponder table
  if(SystemType == ST_DVBT5700)
  {
    FlashTp5700Info = (TYPE_TpInfoT5700 *) (FlashBlockOffset [Transponders] + 8);
    *Frequency  = FlashTp5700Info [FlashService [chNum].TPIdx].Frequency;
    *ChannelNumber = FlashTp5700Info [FlashService [chNum].TPIdx].ChannelNr;
  }
  else
  {
    FlashTpInfo = (TYPE_TpInfoT *) (FlashBlockOffset [Transponders] + 8);
    *Frequency  = FlashTpInfo [FlashService [chNum].TPIdx].Frequency;
    *ChannelNumber = FlashTpInfo [FlashService [chNum].TPIdx].ChannelNr;
  }
}

#endif
