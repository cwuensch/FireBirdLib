#include                "FBLib_TMSOSDKeyboard.h"

void OSDKeyboard_Free(void)
{
  TRACEENTER();

  if (OSDKeyboard_isVisible())
    OSDKeyboard_Destroy();

  Keyb_DictHeapSize = 0;
  Keyb_DictHeapPos = 0;
  Keyb_DictNrEntries = 0;
  Keyb_DictMaxEntries = 0;

  if (Keyb_Clipboard)
  {
    TAP_MemFree(Keyb_Clipboard);
    Keyb_Clipboard = NULL;
  }
  if (Keyb_Dictionary)
  {
    TAP_MemFree(Keyb_Dictionary);
    Keyb_Dictionary = NULL;
  }
  if (Keyb_DictHeap)
  {
    TAP_MemFree(Keyb_DictHeap);
    Keyb_DictHeap = NULL;
  }

  TRACEEXIT();
}
