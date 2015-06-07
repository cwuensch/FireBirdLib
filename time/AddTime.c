#include "../libFireBird.h"

dword AddTime(dword pvrDate, int addMinutes)
{
  TRACEENTER();

  //Calculate the total number of minutes in the target
  dword tempMinutes = (((pvrDate >> 16) & 0xffff) * 1440) + (((pvrDate >> 8) & 0xff) * 60) + (pvrDate & 0xff) + addMinutes;

  //Extract the whole days
  word mjd = tempMinutes / 1440;

  //Remove the whole days and retain only the minutes
  tempMinutes = (tempMinutes % 1440);

  TRACEEXIT();
  return ((mjd << 16) | ((tempMinutes / 60) << 8) | (tempMinutes % 60));
}
