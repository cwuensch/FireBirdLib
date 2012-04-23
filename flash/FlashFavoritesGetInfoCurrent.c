#include                <string.h>
#include                "../libFireBird.h"

bool FlashFavoritesGetInfoCurrent(tFavorites *Favorites)
{
  tFavorites           *Favs;
  char                 *CurrentGroup;
  int                   i, NrGrps;

  NrGrps = FlashFavoritesGetTotal();
  CurrentGroup = FlashFavoritesGetSelectedGroupName();

  if((NrGrps == 0) || !Favorites || !CurrentGroup || !CurrentGroup[0]) return FALSE;

  Favs = (tFavorites*)FIS_vFlashBlockFavoriteGroup();
  for(i = 0; i < NrGrps; i++)
  {
    if(strcmp(Favs->GroupName, CurrentGroup) == 0)
    {
      memcpy(Favorites, Favs, sizeof(tFavorites));
      return TRUE;
    }

    Favs++;
  }

  return FALSE;
}
