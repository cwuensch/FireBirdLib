#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/xattr.h>
#include "../libFireBird.h"

int ExtAttribExistsAbsPath(char *AbsFileName, char *AttrName)
{
  TRACEENTER();

  char                  FullAttrName[128];
  int                   f, i;

  if(!AbsFileName || !*AbsFileName || !AttrName || !*AttrName)
  {
    TRACEEXIT();
    return 0;
  }

  f = open(AbsFileName, O_RDWR, 0600);
  if(f)
  {
    TAP_SPrint(FullAttrName, "user.%s", AttrName);

    if((i = fgetxattr(f, FullAttrName, NULL, 0)) >= 0)
    {
      close(f);

      TRACEEXIT();

      return i;
    }
    close(f);
  }

  TRACEEXIT();
  return 0;
}
