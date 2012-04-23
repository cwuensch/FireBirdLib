#include                "../libFireBird.h"

char *FlashFavoritesGetSelectedGroupName(void)
{
  return (char*)FIS_vfavName();
}
