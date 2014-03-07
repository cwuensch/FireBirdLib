#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/xattr.h>
#include "../libFireBird.h"

bool ExtAttribSetAbsPath(char *AbsFileName, char *AttrName, byte *Data, int DataLen)
{
  TRACEENTER();

  char                  FullAttrName[128];
  int                   f;

  if(!AbsFileName || !*AbsFileName || !AttrName || !*AttrName)
  {
    TRACEEXIT();
    return FALSE;
  }

  f = open(AbsFileName, O_RDWR, 0600);
  if(f)
  {
    TAP_SPrint(FullAttrName, "user.%s", AttrName);

    if(fsetxattr(f, FullAttrName, Data, DataLen, XATTR_CREATE) == 0)
    {
      close(f);

      TRACEEXIT();

      return TRUE;
    }
    else
    {
      //As the attribute may already exist, retry with the replace flag
      if(fsetxattr(f, FullAttrName, Data, DataLen, XATTR_REPLACE) == 0)
      {
        close(f);

        TRACEEXIT();
        return TRUE;
      }
    }
    close(f);
  }

  TRACEEXIT();
  return FALSE;
}
