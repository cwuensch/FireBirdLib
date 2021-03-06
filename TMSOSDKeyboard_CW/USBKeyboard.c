#include                <linux/input.h>
#include                <pthread.h>
#include                <fcntl.h>
#include                <unistd.h>
#include                <string.h>
#include                "../libFireBird.h"
#include                "USBKeyboard.h"

void *KeyboardRedirect_Thread(void);

dword Hooked_ApplTap_CallEventHandler(word event, dword param1, dword param2);
dword Hooked_Appl_EvtProcWirelessUSB(dword param1, dword param2);

bool  StopKeyboardRedirect = FALSE;
dword TAPID = 0;
dword LastKeyboardTick = 0;
bool  CookedMode = FALSE;

dword (*ApplTap_CallEventHandler)(word event, dword param1, dword param2) = NULL;

void *KeyboardRedirect_Thread(void)
{
  int                   fd;
  int                   yalv;
  struct input_event    ev[64];
  size_t                rb;
  struct timeval        tv;
  fd_set                readfds;

  bool                  KeyShiftLeft = FALSE, KeyShiftRight = FALSE;
  bool                  KeyCtrlLeft = FALSE, KeyCtrlRight = FALSE;
  bool                  KeyAltLeft = FALSE, KeyAltRight = FALSE;
  bool                  KeyWinLeft = FALSE, KeyWinRight = FALSE;
  bool                  KeyOption = FALSE;
  bool                  CapsState = FALSE;

  byte                  KeysASCII[]      = {0x1b,'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0x8, ' ',
                                            'q', 'w', 'e', 'r', 't', 'z', 'u', 'i', 'o', 'p', '[', ']', 0xd, 0x0,
                                            'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';','\'', '`', 0x0, '\\',
                                            'y', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0x0, '*', 0x0, ' '};
  byte                  KeysASCIIShift[] = {0x1b,'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', 0x8, ' ',
                                            'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'P', '{', '}', 0xd, 0x0,
                                            'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~', 0x0, '|',
                                            'Y', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0x0, '*', 0x0, ' '};
  byte                  KeysNumpad[]     = {'7', '8', '9', '-', '4', '5', '6', '+', '1', '2', '3', '0', ','};

  TRACEENTER();

  StopKeyboardRedirect = FALSE;

  if((fd = open("/dev/event0", O_RDONLY)) < 0)
  {
    TRACEEXIT();
    return NULL;
  }

  TAP_PrintNet("Keyboard thread has been started\n");

  do
  {
    tv.tv_sec = 0;
    tv.tv_usec = 500000;

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);
    select(fd+1, &readfds, NULL, NULL, &tv);

    if (FD_ISSET(fd, &readfds))
    {
      rb = read(fd, ev, sizeof(struct input_event) * 64);
//TAP_PrintNet("Neuer Read: %u Bytes\n", rb);

      for(yalv = 0; yalv < (int)(rb / sizeof(struct input_event)); yalv++)
      {
        if (EV_KEY == ev[yalv].type)
        {
          //type = always 1?
          //code = scan code of keyboard
          //value = 0:key pressed, 1:key release, 2:key repeat
          LastKeyboardTick = TAP_GetTick();

//TAP_PrintNet("  0x%x (%d)\ttype=%u\tvalue=%d\n", ev[yalv].code, ev[yalv].code, ev[yalv].type, ev[yalv].value);

          if(CookedMode)
          {
            switch(ev[yalv].code)
            {
              case 0x38:  KeyAltLeft    = ev[yalv].value; break;
              case 0x64:  KeyAltRight   = ev[yalv].value; break;
              case 0x1d:  KeyCtrlLeft   = ev[yalv].value; break;
              case 0x61:  KeyCtrlRight  = ev[yalv].value; break;
              case 0x2a:  KeyShiftLeft  = ev[yalv].value; CapsState = FALSE; break;
              case 0x36:  KeyShiftRight = ev[yalv].value; CapsState = FALSE; break;
              case 0x7d:  KeyWinLeft    = ev[yalv].value; break;
              case 0x7e:  KeyWinRight   = ev[yalv].value; break;
              case 0x7f:  KeyOption     = ev[yalv].value; break;
              case 0x3a:  CapsState     = TRUE; break;

              default:
              {
                dword newChar = 0;
                dword code  = ev[yalv].code;
                dword flags = ev[yalv].value | USBKBD_FLAGS_COOKEDMODE;

                if (KeyShiftLeft)  flags |= USBKBD_FLAGS_KEYSHIFTLEFT;
                if (KeyShiftRight) flags |= USBKBD_FLAGS_KEYSHIFTRIGHT;
                if (KeyCtrlLeft)   flags |= USBKBD_FLAGS_KEYCTRLLEFT;
                if (KeyCtrlRight)  flags |= USBKBD_FLAGS_KEYCTRLRIGHT;
                if (KeyAltLeft)    flags |= USBKBD_FLAGS_KEYALTLEFT;
                if (KeyAltRight)   flags |= USBKBD_FLAGS_KEYALTRIGHT;
                if (KeyWinLeft)    flags |= USBKBD_FLAGS_KEYWINLEFT;
                if (KeyWinRight)   flags |= USBKBD_FLAGS_KEYWINRIGHT;
                if (KeyOption)     flags |= USBKBD_FLAGS_KEYOPTION;               

                if (KeyAltLeft || KeyAltRight || KeyCtrlLeft || KeyCtrlRight)
                {
                  if (KeyShiftLeft || KeyShiftRight)
                  {
                    if(code == 0x1e) newChar = (byte) 'Ä';
                    else if (code == 0x18) newChar = (byte) 'Ö';
                    else if (code == 0x16) newChar = (byte) 'Ü';
                  }
                  else
                  {
                    if(code == 0x1e) newChar = (byte) 'ä';
                    else if (code == 0x18) newChar = (byte) 'ö';
                    else if (code == 0x16) newChar = (byte) 'ü';
                    else if (code == 0x1f) newChar = (byte) 'ß';
                  }
                }

//                else if (code == 0x01)  newChar = 0x1b;    // ESC
                else if (code == 0x6f)  newChar = 0x7f;    // Entf
                else if (code == 0x66)  newChar = 0x0124;  // Pos1
                else if (code == 0x6b)  newChar = 0x0123;  // Ende
                else if (code == 0x69)  newChar = 0x0125;  // Left
                else if (code == 0x6a)  newChar = 0x0127;  // Right
                else if (code == 0x3b)  newChar = 0x0170;  // F1 (Rot)
                else if (code == 0x3c)  newChar = 0x0171;  // F2 (Grün)
                else if (code == 0x3d)  newChar = 0x0172;  // F3 (Gelb)
                else if (code == 0x3e)  newChar = 0x0173;  // F4 (Blau)
                else if (code == 0x62)  newChar = '/';

                else if (code >= 0x46 && code <= 0x53)
                  newChar = KeysNumpad[code-0x47];
                else if (code >= 1 && code <= 0x39)
                {
                  if (KeyShiftLeft || KeyShiftRight || CapsState)
                    newChar = KeysASCIIShift[code-1];
                  else
                    newChar = KeysASCII[code-1];
                }

//TAP_PrintNet("0x%x (%hhu)\n", newChar, newChar);
                if (newChar)
                  HDD_TAP_SendEvent(TAPID, FALSE, EVT_USBKEYBOARD, newChar, flags);
              }
            }
          }
          else
            HDD_TAP_SendEvent(TAPID, FALSE, EVT_USBKEYBOARD, ev[yalv].code, ev[yalv].value);
        }
      }
    }
  } while(!StopKeyboardRedirect);
  close(fd);

  TAP_PrintNet("Keyboard thread has been stopped\n");

  TRACEEXIT();
  return NULL;
}

dword Hooked_ApplTap_CallEventHandler(word event, dword param1, dword param2)
{
  dword ret;
  (void)param2;

  TRACEENTER();

  if((TAP_GetTick() - LastKeyboardTick) < 10 && event == EVT_KEY)
    ret = 0;
  else
    ret = ApplTap_CallEventHandler(event, param1, param2);

  TRACEEXIT();
  return ret;
}

bool USBKeyboardRedirect(bool Redirect, bool CookOutput)
{
  static pthread_t      KbdRedirectThread = 0;

  TRACEENTER();
  if(Redirect)
  {
    //Check if already redirected
    if(KbdRedirectThread) return FALSE;

    TAP_PrintNet("USBKeyboardRedirect: starting redirect in %s mode\n", CookOutput ? "cooked" : "raw");

    InitTAPex();
    TAPID = HDD_TAP_GetIDByIndex(TAP_TableIndex);
    CookedMode = CookOutput;
    HookFirmware("_Z24ApplTap_CallEventHandlertjj", Hooked_ApplTap_CallEventHandler, (void*)&ApplTap_CallEventHandler);
    return (pthread_create(&KbdRedirectThread, NULL, (void*)KeyboardRedirect_Thread, NULL) == 0);
  }
  else
  {
    if(KbdRedirectThread)
    {
      TAP_PrintNet("USBKeyboardRedirect: stopping redirection\n");
      UnhookFirmware("_Z24ApplTap_CallEventHandlertjj", Hooked_ApplTap_CallEventHandler, (void*)&ApplTap_CallEventHandler);
      StopKeyboardRedirect = TRUE;
      pthread_join(KbdRedirectThread, NULL);
      KbdRedirectThread = 0;
    }
  }

  TRACEEXIT();
  return TRUE;
}
