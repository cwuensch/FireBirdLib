#include                "FBLib_TMSOSDMenu.h"

word                    OSDRgn = 0, MyOSDRgn = 0;
dword                   LastUnprocessedOSDMenuKey = 0;


bool OSDMessageEvent(word *event, dword *param1, dword *param2)
{
  TRACEENTER();

  (void) param2;

  if(InfoBoxOSDRgn)
  {
    if(event && param1 && (*event == EVT_KEY))
    {
      if(*param1 == RKEY_Exit)
      {
        OSDMenuInfoBoxDestroy();
        *param1 = 0;
      }

      LastUnprocessedOSDMenuKey = *param1;

      TRACEEXIT();
      return TRUE;
    }

    if(!event || (*event == EVT_IDLE))
    {
      if(TAP_GetTick() > InfoBoxTimeOut) OSDMenuInfoBoxDestroy();
    }

    TRACEEXIT();
    return FALSE;
  }

  if(MessageBoxOSDRgn)
  {
    if(event && param1 && (*event == EVT_KEY))
    {
      switch(*param1)
      {
        case RKEY_Ok:
        {
          if(MessageBoxNoNormalMode)
            OSDMenuMessageBoxDestroyNoOSDUpdate();
          else
            OSDMenuMessageBoxDestroy();

          *param1 = 0;
          break;
        }

        case RKEY_Exit:
        {
          if(MessageBoxNoNormalMode)
            OSDMenuMessageBoxDestroyNoOSDUpdate();
          else
            OSDMenuMessageBoxDestroy();
          MessageBox.CurrentButton = (dword) -1;

          *param1 = 0;
          break;
        }

        case RKEY_Right:
        {
          if(MessageBox.CurrentButton < (MessageBox.NrButtons - 1))
          {
            MessageBox.CurrentButton++;
            OSDMenuMessageBoxShow();
          }
          else if(MessageBoxAllowScrollOver)
          {
            MessageBox.CurrentButton = 0;
            OSDMenuMessageBoxShow();
          }

          *param1 = 0;
          break;
        }

        case RKEY_Left:
        {
          if(MessageBox.CurrentButton > 0)
          {
            MessageBox.CurrentButton--;
            OSDMenuMessageBoxShow();
          }
          else if(MessageBoxAllowScrollOver)
          {
            MessageBox.CurrentButton = MessageBox.NrButtons - 1;
            OSDMenuMessageBoxShow();
          }

          *param1 = 0;
          break;
        }
      }

      LastUnprocessedOSDMenuKey = *param1;

      TRACEEXIT();
      return TRUE;
    }

    TRACEEXIT();
    return FALSE;
  }

  TRACEEXIT();
  return FALSE;
}
