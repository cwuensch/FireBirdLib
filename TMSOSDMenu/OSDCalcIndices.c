#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

void OSDCalcIndices(void)
{
  TRACEENTER();

  tMenu                *pMenu;

  pMenu = &Menu[CurrentMenuLevel];

  //if TopIndex or SelectionIndex has changed, make list dirty
  if(pMenu->OSDMenuDisplayMode == OMDM_Memo || pMenu->OSDMenuDisplayMode == OMDM_Text)
  {
    pMenu->CurrentTopIndex = pMenu->CurrentSelection;

    if (pMenu->OSDMenuDisplayMode == OMDM_Text)
    {
      if (pMenu->CurrentTopIndex + 15 > pMenu->NrItems)
      {
        pMenu->CurrentTopIndex = pMenu->NrItems - 15;

        if (pMenu->CurrentTopIndex < 0) pMenu->CurrentTopIndex = 0;

        pMenu->CurrentSelection = pMenu->CurrentTopIndex;
      }
    }
  }
  else
  {
    if(pMenu->CurrentSelection < pMenu->CurrentTopIndex)
    {
      if(pMenu->CurrentSelection > 0)
      {
        //Check if there are selectable items above the current selection
        bool            Selectable;
        int             i;

        Selectable = FALSE;
        for(i = pMenu->CurrentSelection - 1; i >= 0; i--)
        {
          if(pMenu->Item[i].Selectable)
          {
            Selectable = TRUE;
            break;
          }
        }
        if(Selectable)
          pMenu->CurrentTopIndex = pMenu->CurrentSelection;
        else
          pMenu->CurrentTopIndex = 0;
      }
      else
      {
        pMenu->CurrentTopIndex = pMenu->CurrentSelection;
      }
    }


    if(pMenu->CurrentSelection > (pMenu->CurrentTopIndex + 9))
    {
      if(pMenu->CurrentSelection < pMenu->NrItems - 1)
      {
        //Check if there are selectable items above the current selection
        bool            Selectable;
        int             i;

        Selectable = FALSE;
        for(i = pMenu->CurrentSelection + 1; i < pMenu->NrItems; i++)
        {
          if(pMenu->Item[i].Selectable)
          {
            Selectable = TRUE;
            break;
          }
        }
        if(Selectable)
          pMenu->CurrentTopIndex = pMenu->CurrentSelection - 9;
        else
          pMenu->CurrentTopIndex = pMenu->NrItems - 10;

        if((pMenu->CurrentSelection - pMenu->CurrentTopIndex) > 10)
          pMenu->CurrentTopIndex = pMenu->CurrentSelection - 10;
      }
      else
      {
        pMenu->CurrentTopIndex = pMenu->CurrentSelection - 9;
      }
    }
  }

  TRACEEXIT();
}
