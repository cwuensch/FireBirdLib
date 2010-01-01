#include                "FBLib_TMSOSDMenu.h"

void OSDDrawLogo(void)
{
  tMenu                *pMenu;

  pMenu = &Menu[CurrentMenuLevel];

  if(pMenu->pLogoGd) TAP_Osd_PutGd(OSDRgn, pMenu->LogoX , pMenu->LogoY, pMenu->pLogoGd, FALSE);
}
