#include "../libFireBird.h"

#ifndef _TMS_

void GetHeapParameter (tHeapMap *pHeapMap, dword *HeapStart)
{
  dword                 HeapMap;

  if (!(HeapMap = FIS_vHeapMap())) return;
  *HeapStart = FIS_vHeapStart();

  memcpy (pHeapMap, &HeapMap, 4);
}

#endif
