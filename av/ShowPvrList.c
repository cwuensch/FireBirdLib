#include "../libFireBird.h"

bool ShowPvrList(tPvrListType PvrListType)
{
  void (*__Appl_PvrList)(unsigned int, unsigned int);
  void (*__Appl_PvrList_SetListType)(tPvrListType ListType);

  __Appl_PvrList = (void*)FIS_fwAppl_PvrList();
  if(!__Appl_PvrList) return FALSE;

  __Appl_PvrList_SetListType = (void*)FIS_fwAppl_PvrList_SetListType();
  if(!__Appl_PvrList_SetListType) return FALSE;

  __Appl_PvrList_SetListType(PvrListType);
  __Appl_PvrList(0, 0xffff);

  return TRUE;
}
