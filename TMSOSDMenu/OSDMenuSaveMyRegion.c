#include                "FBLib_TMSOSDMenu.h"

word                    MyOSDRgn;

void OSDMenuSaveMyRegion(word Rgn)
{
  TRACEENTER();

  MyOSDRgn = Rgn;

  TRACEEXIT();
}
