#include "../libFireBird.h"

#ifndef _TMS_

void HDD_SetFileDateTime (TYPE_File *fp, dword FileDateTime, byte Sec, int LocalOffset)
{
  if (fp == NULL || fp->handle == NULL) return;

  fp->mjd         = FileDateTime >> 16;
  fp->hour        = (FileDateTime >> 8) & 0xff;
  fp->min         = FileDateTime & 0xff;
  fp->sec         = Sec;
  fp->localOffset = LocalOffset;

  ((tFileSlot *) fp->handle)->FileDateTimeMJD     = FileDateTime >> 16;
  ((tFileSlot *) fp->handle)->FileDateTimeHour    = (FileDateTime >> 8) & 0xff;
  ((tFileSlot *) fp->handle)->FileDateTimeMin     = FileDateTime & 0xff;
  ((tFileSlot *) fp->handle)->FileDateTimeSeconds = Sec;
  ((tFileSlot *) fp->handle)->FileDateTimeOffset  = LocalOffset;

  return;
}

#endif
