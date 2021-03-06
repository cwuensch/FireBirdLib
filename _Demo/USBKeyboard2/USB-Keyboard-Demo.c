#include                <string.h>
#include                "tap.h"
#include                "USB-Keyboard.h"
#include                "libFireBird.h"

#define PROGRAM_NAME    "USB-Keyboard Demo"
#define VERSION         "V0.3"

TAP_ID                  (0x8E0Affe2);
TAP_PROGRAM_NAME        (PROGRAM_NAME" "VERSION);
TAP_AUTHOR_NAME         ("FireBird");
TAP_DESCRIPTION         ("USB-Keyboard Demo");
TAP_ETCINFO             (__DATE__);


char                Text[255];
dword               CursorPos = 0;
dword               TextLen = 0;

dword TAP_EventHandler(word event, dword param1, dword param2)
{
  (void) param1;
  (void) param2;

  //if(event != EVT_IDLE)
  //{
  //  switch(event)
  //  {
  //    case EVT_KEY:         TAP_PrintNet("EVT_KEY(%x, %x)\n", param1, param2); break;
  //    case EVT_UART:        TAP_PrintNet("EVT_UART(%x, %x)\n", param1, param2); break;
  //    case EVT_RBACK:       TAP_PrintNet("EVT_RBACK(%x, %x)\n", param1, param2); break;
  //    case EVT_SVCSTATUS:   TAP_PrintNet("EVT_SVCSTATUS(%x, %x)\n", param1, param2); break;
  //    case EVT_VIDEO_CONV:  TAP_PrintNet("EVT_VIDEO_CONV(%x, %x)\n", param1, param2); break;
  //    case EVT_DEMUX:       TAP_PrintNet("EVT_DEMUX(%x, %x)\n", param1, param2); break;
  //    case EVT_USBKEYBOARD: TAP_PrintNet("EVT_USBKEYBOARD(%x, %x)\n", param1, param2); break;
  //    case EVT_STOP:        TAP_PrintNet("EVT_STOP(%x, %x)\n", param1, param2); break;
  //  }
  //}

  if(event == EVT_USBKEYBOARD)
  {
    //Key down events only
    if((param2 & 0x03) == 0x01)
    {
      //Add a character
      if((param1 >= 0x20) && (param1 < 0x7f))
      {
        if(CursorPos != TextLen)
          memmove(&Text[CursorPos + 1], &Text[CursorPos], TextLen - CursorPos + 1);

        Text[CursorPos] = param1;
        TextLen++;
        CursorPos++;
        Text[TextLen] = '\0';

        TAP_PrintNet("%s  (C=%d, L=%d)\n", Text, CursorPos, TextLen);
      }

      //Backspace
      if((param1 == 0x08) && Text[0] && CursorPos)
      {
        CursorPos--;
        TextLen--;

        if(CursorPos == TextLen)
        {
          Text[CursorPos] = '\0';
        }
        else
          memmove(&Text[CursorPos], &Text[CursorPos + 1], TextLen - CursorPos + 1);

        TAP_PrintNet("%s  (C=%d, L=%d)\n", Text, CursorPos, TextLen);
      }

      //DEL
      if((param1 == 0x7f) && Text[0])
      {
        if(TextLen && (CursorPos < TextLen))
        {
          TextLen--;
          memmove(&Text[CursorPos], &Text[CursorPos + 1], TextLen - CursorPos + 1);

          Text[TextLen] = '\0';

          TAP_PrintNet("%s  (C=%d, L=%d)\n", Text, CursorPos, TextLen);
        }
      }

      //LEFT
      if((param1 == 0xe2) && (CursorPos > 0))
      {
        CursorPos--;
        TAP_PrintNet("%s  (C=%d, L=%d)\n", Text, CursorPos, TextLen);
      }

      //RIGHT
      if((param1 == 0xe3) && (CursorPos < TextLen))
      {
        CursorPos++;
        TAP_PrintNet("%s  (C=%d, L=%d)\n", Text, CursorPos, TextLen);
      }

      //HOME
      if((param1 == 0xe6) && (CursorPos > 0))
      {
        CursorPos = 0;
        TAP_PrintNet("%s  (C=%d, L=%d)\n", Text, CursorPos, TextLen);
      }

      //END
      if((param1 == 0xe7) && (CursorPos < TextLen))
      {
        CursorPos = TextLen;
        TAP_PrintNet("%s  (C=%d, L=%d)\n", Text, CursorPos, TextLen);
      }
    }
  }

  if((event == EVT_STOP && param1 < 2) || (event == EVT_KEY && param1 == RKEY_Exit))
  {
    if(param1 == RKEY_Exit) param1 = 0;
    USBKeyboardRedirect(FALSE, FALSE);
    TAP_Exit();
  }

  return param1;
}

int TAP_Main(void)
{
  TAP_PrintNet("ApplVer=%s (0x%4.4x)\n", GetApplVer(), TAP_GetVersion());

  Text[0] = '\0';

  USBKeyboardRedirect(TRUE, TRUE);

  return 1;
}
