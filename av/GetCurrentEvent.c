#include "../libFireBird.h"

TYPE_TapEvent *GetCurrentEvent (int *nCurEvent)
{
  TYPE_TapEvent         *evtInfo;
  unsigned int          eventNum, i;
  int                   svcType, svcNum;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("GetCurrentEvent");
#endif

  TAP_Channel_GetCurrent( &svcType, &svcNum );          // get current channel
  if ( svcType != SVC_TYPE_Tv )                         // cancel if not in TV mode
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return NULL;
  }
  evtInfo = TAP_GetEvent( svcType, svcNum, &eventNum ); // get events

  if(evtInfo)
  {
    for( i = 0; i < eventNum; i++ )                     // find current event
    {
      if( evtInfo[i].runningStatus == 4 )               // current event found
      break;
    }
  }

  if( evtInfo && evtInfo[i].runningStatus == 4)
  {
    if ( nCurEvent ) *nCurEvent = i;

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return evtInfo;
  }

  if ( evtInfo ) TAP_MemFree( evtInfo );

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return NULL;
}
