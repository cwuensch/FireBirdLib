#include "FBLib_av.h"
#include "../libFireBird.h"

void YUV2RGB( word yy, word uu, word vv, byte *r, byte *g, byte *b )
{
  signed int            _r,_g,_b;
  signed int            y, u, v;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("YUV2RGB");
#endif

  y = yy; // - 12;
  u = (int)uu - 128;
  v = (int)vv - 128;

  _r = YUVR(y,u,v);
  _g = YUVG(y,u,v);
  _b = YUVB(y,u,v);

  *r = _Clip(_r);
  *g = _Clip(_g);
  *b = _Clip(_b);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

}
