#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

bool OSDMenuEvent(word *event, dword *param1, dword *param2)
{
  (void) param2;

  if(OSDRgn)
  {
    if(event && param1 && (*event == EVT_KEY))
    {
      switch(*param1)
      {
        case RKEY_Up:
        {
          OSDMenuScrollUp();
          OSDMenuUpdate();
          *param1 = 0;
          return TRUE;
        }

        case RKEY_Down:
        {
          OSDMenuScrollDown();
          OSDMenuUpdate();
          *param1 = 0;
          return TRUE;
        }

        case RKEY_ChDown:
        case RKEY_VolDown:
        {
          OSDMenuScrollPageDown();
          OSDMenuUpdate();
          *param1 = 0;
          return TRUE;
        }

        case RKEY_ChUp:
        case RKEY_VolUp:
        {
          OSDMenuScrollPageUp();
          OSDMenuUpdate();
          *param1 = 0;
          return TRUE;
        }
      }
    }
  }

  if(InfoBoxOSDRgn)
  {
    if(event && param1 && (*event == EVT_KEY))
    {
      if(*param1 == RKEY_Exit) OSDMenuInfoBoxDestroy();
      *param1 = 0;
      return TRUE;
    }

    if(!event || (*event == EVT_IDLE))
    {
      if(TAP_GetTick() > InfoBoxTimeOut) OSDMenuInfoBoxDestroy();
    }
  }

  if(MessageBoxOSDRgn)
  {
    if(event && param1 && (*event == EVT_KEY))
    {
      switch(*param1)
      {
        case RKEY_Ok:
        {
          OSDMenuMessageBoxDestroy();
          break;
        }

        case RKEY_Right:
        {
          if(MessageBox.CurrentButton < (MessageBox.NrButtons - 1))
          {
            MessageBox.CurrentButton++;
            OSDMenuMessageBoxShow();
          }
          break;
        }

        case RKEY_Left:
        {
          if(MessageBox.CurrentButton > 0)
          {
            MessageBox.CurrentButton--;
            OSDMenuMessageBoxShow();
          }
          break;
        }
      }
      *param1 = 0;
      return TRUE;
    }
  }

  return FALSE;
}

#endif
