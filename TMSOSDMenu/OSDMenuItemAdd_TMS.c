#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

bool OSDMenuItemAdd(char *Name, char *Value, TYPE_GrData *pNameIconGd, TYPE_GrData *pValueIconGd, bool Selectable, bool ValueArrows, dword ID)
{
  tMenu                *pMenu;

  pMenu = &Menu[CurrentMenuLevel];

  if(pMenu->NrItems >= MAXITEMS) return FALSE;
  if(!Name || !Name[0]) return FALSE;

  strncpy(pMenu->Item[pMenu->NrItems].Name, Name, ITEMNAMESIZE);
  pMenu->Item[pMenu->NrItems].Name[ITEMNAMESIZE - 1] = '\0';

  if(Value && Value[0])
  {
    strncpy(pMenu->Item[pMenu->NrItems].Value, Value, ITEMVALUESIZE);
    pMenu->Item[pMenu->NrItems].Value[ITEMVALUESIZE - 1] = '\0';
  }
  else
    pMenu->Item[pMenu->NrItems].Value[0]    = '\0';

  pMenu->Item[pMenu->NrItems].pNameIconGd   = pNameIconGd;
  pMenu->Item[pMenu->NrItems].pValueIconGd  = pValueIconGd;
  pMenu->Item[pMenu->NrItems].Selectable    = Selectable;
  pMenu->Item[pMenu->NrItems].ValueArrows   = ValueArrows;
  pMenu->Item[pMenu->NrItems].ID            = ID;
  pMenu->NrItems++;

  //TODO: only when in visible area
  ListDirty = TRUE;

  return TRUE;
}

#endif
