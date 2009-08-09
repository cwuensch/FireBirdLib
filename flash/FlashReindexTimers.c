#include "FBLib_flash.h"

void FlashReindexTimers(word ServiceIndex, int ServiceType, ReindexType itype)
{
  if (itype != delete && itype != insert) return;

  switch (SystemType)
  {
    case ST_DVBS:
    {
#ifndef _TMS_
      TYPE_TimerS *Timer;

      Timer = (TYPE_TimerS *) (FlashBlockOffset[Timers] + 4);

      while (Timer->StartTime != 0)
      {
        if (delete)
        {
          if (Timer->ServiceIndex > ServiceIndex && Timer->ServiceType == ServiceType) Timer->ServiceIndex--;
        }
        else // insert
        {
          if (Timer->ServiceIndex >= ServiceIndex && Timer->ServiceType == ServiceType) Timer->ServiceIndex++;
        }

        Timer++;
      }
#endif
      break;
    }

    case ST_DVBT:
    case ST_DVBT5700:
    {
#ifndef _TMS_
      byte *Timer;

      Timer = (byte *) (FlashBlockOffset[Timers] + 4);

      // fortunately, the structures are identical for all members we have to access
      while (((TYPE_TimerT *) Timer)->StartTime != 0)
      {
        if (delete)
        {
          if (((TYPE_TimerT *) Timer)->ServiceIndex > ServiceIndex && ((TYPE_TimerT *) Timer)->ServiceType == ServiceType) ((TYPE_TimerT *) Timer)->ServiceIndex--;
        }
        else // insert
        {
          if (((TYPE_TimerT *) Timer)->ServiceIndex >= ServiceIndex && ((TYPE_TimerT *) Timer)->ServiceType == ServiceType) ((TYPE_TimerT *) Timer)->ServiceIndex++;
        }

        Timer += (SystemType == ST_DVBT ? sizeof(TYPE_TimerT) : sizeof(TYPE_TimerT5700));
      }
#endif
      break;
    }

    case ST_DVBC:
    {
#ifndef _TMS_
      TYPE_TimerC *Timer;

      Timer = (TYPE_TimerC *) (FlashBlockOffset[Timers] + 4);

      while (Timer->StartTime != 0)
      {
        if (delete)
        {
          if (Timer->ServiceIndex > ServiceIndex && Timer->ServiceType == ServiceType) Timer->ServiceIndex--;
        }
        else // insert
        {
          if (Timer->ServiceIndex >= ServiceIndex && Timer->ServiceType == ServiceType) Timer->ServiceIndex++;
        }

        Timer++;
      }
#endif
      break;
    }

    case ST_DVBSTMS:
    {
#ifdef _TMS_

      TYPE_TimerSTMS *Timer;

      Timer = (TYPE_TimerSTMS *) (FlashBlockOffset[Timers] + 4);

      while (Timer->StartTime != 0)
      {
        if (delete)
        {
          if (Timer->ServiceIndex > ServiceIndex && Timer->ServiceType == ServiceType) Timer->ServiceIndex--;
        }
        else // insert
        {
          if (Timer->ServiceIndex >= ServiceIndex && Timer->ServiceType == ServiceType) Timer->ServiceIndex++;
        }

        Timer++;
      }
#endif
      break;
    }

    default:
      ;
  }
}
