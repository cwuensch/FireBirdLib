#include "../libFireBird.h"

#include <dlfcn.h>

dword TryResolve(char *Function)
{
  void                *pvr;
  dword               *ret;

  pvr = dlopen(NULL, RTLD_GLOBAL | RTLD_LAZY);
  if(!pvr) return 0;

  ret = dlsym(pvr, Function);
  if (dlerror() != NULL)
  {
    dlclose(pvr);
    return 0;
  }

  dlclose(pvr);
  return (dword)ret;
}
