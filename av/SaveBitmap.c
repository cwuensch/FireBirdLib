#include "FBLib_av.h"
#include "../libFireBird.h"

bool SaveBitmap(char *strName, int width, int height, byte* pBuffer )
{
  TYPE_File             *pFile;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("SaveBitmap");
#endif

  if( !pBuffer || !strName )
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return FALSE;
  }

  TAP_Hdd_Create( strName, ATTR_NORMAL );
  pFile = TAP_Hdd_Fopen( strName );
  if ( !pFile )
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return FALSE;
  }

  // Write Header
  BMP_WriteHeader(pFile, width, height);

  // write bitmap data
  TAP_Hdd_Fwrite(pBuffer, width * 3, height, pFile);

#ifndef _TMS_
  HDD_TouchFile  (pFile);
#endif

  TAP_Hdd_Fclose (pFile);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return TRUE;
}
