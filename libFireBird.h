#ifndef __FBLIB__
  #define __FBLIB__

#define __FBLIB_VERSION__ "2010-01-11"

#ifdef PC_BASED
  #define inline
  #define __attribute__(a)
#else
  #include "tap.h"
#endif

//The lib doesn't use _TF5000_, just ifndef _TMS_, but just to make sure
//that an unmodified compiler may still compile TF5000/TMS-TAPs
#ifndef _TMS_
  #ifndef _TF5000_
    #define _TF5000_
  #endif
#endif

#include "libFireBird_generic.h"

#ifdef _TMS_
  #include "libFireBird_TMS.h"
#else
  #include "libFireBird_TF5000.h"
#endif

#endif
