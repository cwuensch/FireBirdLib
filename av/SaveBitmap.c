#include "FBLib_av.h"
#include "../libFireBird.h"

bool SaveBitmap(char *strName, int width, int height, byte* pBuffer)
{
  TRACEENTER();

  TYPE_File             *pFile;
  dword									rowlength;

  if(!pBuffer ||!strName)
  {
    TRACEEXIT();
    return FALSE;
  }

  if(!TAP_Hdd_Exist(strName)) TAP_Hdd_Create(strName, ATTR_NORMAL);
  pFile = TAP_Hdd_Fopen(strName);
  if(!pFile)
  {
    TRACEEXIT();
    return FALSE;
  }

  // Write Header
  BMP_WriteHeader(pFile, width, height);

  // write bitmap data
	// according to spec.: the rowlength must be a multiple of 4 bytes, if necessary fill up with zero-bytes
	rowlength = (width*3%4==0) ? width*3 : ((width*3/4)+1)*4;
  TAP_Hdd_Fwrite(pBuffer, rowlength, height, pFile);
  TAP_Hdd_Fclose(pFile);

  TRACEEXIT();
  return TRUE;
}
