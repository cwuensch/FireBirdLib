#include                "../libFireBird.h"

void ApplHdd_RestoreWorkFolder(void)
{
  void (*__ApplHdd_RestoreWorkFolder)(void);

  __ApplHdd_RestoreWorkFolder = (void*)FIS_fwApplHdd_RestoreWorkFolder();
  if(__ApplHdd_RestoreWorkFolder) __ApplHdd_RestoreWorkFolder();
}
