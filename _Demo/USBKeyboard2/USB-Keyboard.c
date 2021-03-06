#include                <linux/input.h>
#include                <pthread.h>
#include                <fcntl.h>
#include                <unistd.h>
#include                <string.h>
#include                "USB-Keyboard.h"
#include                "libFireBird.h"

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

  byte                  SpecialKeysCode[]        = {0x3a, 0x45, 0x46, 0x77, 0x63, 0x67, 0x6c, 0x69, 0x6a, 0x68, 0x6d, 0x66, 0x6b, 0x6e, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x57, 0x58, 0};
  byte                  SpecialKeysASCII[]       = {0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xf0, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0};
  byte                  NormalKeysCode[]         = {0x0e, 0x0f, 0x60, 0x1c, 0x01, 0x39, 0x28, 0x37, 0x4e, 0x33, 0x0c, 0x4a, 0x34, 0x35, 0x62, 0x0b, 0x52, 0x02, 0x4f, 0x03, 0x50, 0x04, 0x51, 0x05, 0x4b, 0x06, 0x4c, 0x07, 0x4d, 0x08, 0x47, 0x09, 0x48, 0x0a, 0x49, 0x27, 0x0d, 0x1a, 0x2b, 0x1b, 0x29, 0x1e, 0x30, 0x2e, 0x20, 0x12, 0x21, 0x22, 0x23, 0x17, 0x24, 0x25, 0x26, 0x32, 0x31, 0x18, 0x19, 0x10, 0x13, 0x1f, 0x14, 0x16, 0x2f, 0x11, 0x2d, 0x15, 0x2c, 0x6f, 0x53, 0};
  byte                  NormalKeysASCII[]        = {0x08, 0x09, 0x0d, 0x0d, 0x1b, 0x20, 0x27, 0x2a, 0x2b, 0x2c, 0x2d, 0x2d, 0x2e, 0x2f, 0x2f, 0x30, 0x30, 0x31, 0x31, 0x32, 0x32, 0x33, 0x33, 0x34, 0x34, 0x35, 0x35, 0x36, 0x36, 0x37, 0x37, 0x38, 0x38, 0x39, 0x39, 0x3b, 0x3d, 0x5b, 0x5c, 0x5d, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7f, 0x7f, 0};
  byte                  NormalKeysASCIIShifted[] = {0x08, 0x09, 0x0d, 0x0d, 0x1b, 0x21, 0x01, 0x2a, 0x2b, 0x01, 0x01, 0x2d, 0x01, 0x01, 0x2f, 0x01, 0x30, 0x01, 0x31, 0x01, 0x32, 0x01, 0x33, 0x01, 0x34, 0x01, 0x35, 0x01, 0x36, 0x01, 0x37, 0x01, 0x38, 0x01, 0x39, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x7f, 0x7f, 0};

  StopKeyboardRedirect = FALSE;

  if((fd = open("/dev/event0", O_RDWR)) < 0) return NULL;

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
      if(rb < (int)sizeof(struct input_event)) return NULL;

      for(yalv = 0; yalv < (int)(rb / sizeof(struct input_event)); yalv++)
      {
        if (EV_KEY == ev[yalv].type)
        {
          //type = always 1?
          //code = scan code of keyboard
          //value = 0:key pressed, 1:key release, 2:key repeat
          LastKeyboardTick = TAP_GetTick();

          if(CookedMode)
          {
            switch(ev[yalv].code)
            {
              case 0x38:
              {
                if(ev[yalv].value == 1) KeyAltLeft = TRUE;
                if(ev[yalv].value == 0) KeyAltLeft = FALSE;
                break;
              }

              case 0x64:
              {
                if(ev[yalv].value == 1) KeyAltRight = TRUE;
                if(ev[yalv].value == 0) KeyAltRight = FALSE;
                break;
              }

              case 0x1d:
              {
                if(ev[yalv].value == 1) KeyCtrlLeft = TRUE;
                if(ev[yalv].value == 0) KeyCtrlLeft = FALSE;
                break;
              }

              case 0x61:
              {
                if(ev[yalv].value == 1) KeyCtrlRight = TRUE;
                if(ev[yalv].value == 0) KeyCtrlRight = FALSE;
                break;
              }

              case 0x2a:
              {
                if(ev[yalv].value == 1) KeyShiftLeft = TRUE;
                if(ev[yalv].value == 0) KeyShiftLeft = FALSE;
                break;
              }

              case 0x36:
              {
                if(ev[yalv].value == 1) KeyShiftRight = TRUE;
                if(ev[yalv].value == 0) KeyShiftRight = FALSE;
                break;
              }

              case 0x7d:
              {
                if(ev[yalv].value == 1) KeyWinLeft = TRUE;
                if(ev[yalv].value == 0) KeyWinLeft = FALSE;
                break;
              }

              case 0x7e:
              {
                if(ev[yalv].value == 1) KeyWinRight = TRUE;
                if(ev[yalv].value == 0) KeyWinRight = FALSE;
                break;
              }

              case 0x7f:
              {
                if(ev[yalv].value == 1) KeyOption = TRUE;
                if(ev[yalv].value == 0) KeyOption = FALSE;
                break;
              }

              default:
              {
                dword code;
                dword flags;
                int   i;

                flags = ev[yalv].value | USBKBD_FLAGS_COOKEDMODE;
                if(KeyShiftLeft)  flags |= USBKBD_FLAGS_KEYSHIFTLEFT;
                if(KeyShiftRight) flags |= USBKBD_FLAGS_KEYSHIFTRIGHT;
                if(KeyCtrlLeft)   flags |= USBKBD_FLAGS_KEYCTRLLEFT;
                if(KeyCtrlRight)  flags |= USBKBD_FLAGS_KEYCTRLRIGHT;
                if(KeyAltLeft)    flags |= USBKBD_FLAGS_KEYALTLEFT;
                if(KeyAltRight)   flags |= USBKBD_FLAGS_KEYALTRIGHT;
                if(KeyWinLeft)    flags |= USBKBD_FLAGS_KEYWINLEFT;
                if(KeyWinRight)   flags |= USBKBD_FLAGS_KEYWINRIGHT;
                if(KeyOption)     flags |= USBKBD_FLAGS_KEYOPTION;

                code = ev[yalv].code;
                i = 0;
                while((SpecialKeysCode[i] != code) && SpecialKeysCode[i])
                {
                  i++;
                }

                if(SpecialKeysCode[i])
                  HDD_TAP_SendEvent(TAPID, FALSE, EVT_USBKEYBOARD, SpecialKeysASCII[i], flags);
                else
                {
                  i = 0;
                  while((NormalKeysCode[i] != code) && NormalKeysCode[i])
                    i++;

                  if(NormalKeysCode[i])
                  {
                    if(flags & (USBKBD_FLAGS_KEYSHIFTLEFT | USBKBD_FLAGS_KEYSHIFTRIGHT))
                      HDD_TAP_SendEvent(TAPID, FALSE, EVT_USBKEYBOARD, NormalKeysASCIIShifted[i], flags);
                    else
                      HDD_TAP_SendEvent(TAPID, FALSE, EVT_USBKEYBOARD, NormalKeysASCII[i], flags);

                  }
                }
              }
            }
          }
          else
            HDD_TAP_SendEvent(TAPID, FALSE, EVT_USBKEYBOARD, ev[yalv].code, ev[yalv].value);
        }
      }
    }
  }while(!StopKeyboardRedirect);
  close(fd);

  TAP_PrintNet("Keyboard thread has been stopped\n");

  return NULL;
}

dword Hooked_ApplTap_CallEventHandler(word event, dword param1, dword param2)
{
  dword ret;

  (void)param2;

  if((TAP_GetTick() - LastKeyboardTick) < 10 && event == EVT_KEY)
    ret = 0;
  else
    ret = ApplTap_CallEventHandler(event, param1, param2);

  return ret;
}

bool USBKeyboardRedirect(bool Redirect, bool CookOutput)
{
  static pthread_t      KbdRedirectThread = 0;

  if(Redirect)
  {
    //Check if already redirected
    if(KbdRedirectThread) return FALSE;

    TAP_PrintNet("USBKeyboardRedirect: starting redirect in %s mode\n", CookOutput ? "cooked" : "raw");

    InitTAPex();
    TAPID = HDD_TAP_GetIDByIndex(TAP_TableIndex);
    CookedMode = CookOutput;
    HookFirmware("_Z24ApplTap_CallEventHandlertjj", Hooked_ApplTap_CallEventHandler, (dword*)&ApplTap_CallEventHandler);
    return (pthread_create(&KbdRedirectThread, NULL, (void*)KeyboardRedirect_Thread, NULL) == 0);
  }
  else
  {
    if(KbdRedirectThread)
    {
      TAP_PrintNet("USBKeyboardRedirect: stopping redirection\n");
      UnhookFirmware("_Z24ApplTap_CallEventHandlertjj", Hooked_ApplTap_CallEventHandler, (dword*)&ApplTap_CallEventHandler);
      StopKeyboardRedirect = TRUE;
      pthread_join(KbdRedirectThread, NULL);
      KbdRedirectThread = 0;
    }
  }

  return TRUE;
}
