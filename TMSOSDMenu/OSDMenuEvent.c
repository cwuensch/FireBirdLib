#include                "FBLib_TMSOSDMenu.h"

word                    OSDRgn = 0, MyOSDRgn = 0;
dword                   LastUnprocessedOSDMenuKey = 0;

bool OSDMenuEvent(word *event, dword *param1, dword *param2)
{
  TRACEENTER();

  (void) param2;

  OSDMessageEvent(event, param1, param2);

  if(OSDRgn)
  {
    if(event && param1 && (*event == EVT_KEY))
    {
      LastUnprocessedOSDMenuKey = 0;

      switch(*param1)
      {
        case RKEY_Up:
        {
          OSDMenuScrollUp();
          OSDMenuUpdate(FALSE);
          *param1 = 0;

          TRACEEXIT();
          return TRUE;
        }

        case RKEY_Down:
        {
          OSDMenuScrollDown();
          OSDMenuUpdate(FALSE);
          *param1 = 0;

          TRACEEXIT();
          return TRUE;
        }

        case RKEY_ChDown:
        case RKEY_VolDown:
        {
          OSDMenuScrollPageDown();
          OSDMenuUpdate(FALSE);
          *param1 = 0;

          TRACEEXIT();
          return TRUE;
        }

        case RKEY_ChUp:
        case RKEY_VolUp:
        {
          OSDMenuScrollPageUp();
          OSDMenuUpdate(FALSE);
          *param1 = 0;

          TRACEEXIT();
          return TRUE;
        }

        case RKEY_Left:
        {
          if(!Menu[CurrentMenuLevel].hasValueArrows)
          {
            OSDMenuScrollPageUp();
            OSDMenuUpdate(FALSE);
            *param1 = 0;

            TRACEEXIT();
            return TRUE;
          }
          break;
        }

        case RKEY_Right:
        {
          if(!Menu[CurrentMenuLevel].hasValueArrows)
          {
            OSDMenuScrollPageDown();
            OSDMenuUpdate(FALSE);
            *param1 = 0;

            TRACEEXIT();
            return TRUE;
          }
          break;
        }
      }

      LastUnprocessedOSDMenuKey = *param1;
    }
  }

  TRACEEXIT();
  return FALSE;
}
