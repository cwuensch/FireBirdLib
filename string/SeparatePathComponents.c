#include                <string.h>
#include                "../libFireBird.h"

void SeparatePathComponents(char *FullName, char *Path, char *FileName, char *FileExt)
{
  TRACEENTER();

  char                  *Slash, *Dot;
  char                  *p;

  if(FullName == NULL)
  {
    TRACEEXIT();
    return;
  }

  p = SkipCharTableBytes(FullName);

  Slash = strrchr(p, '/');
  Dot   = strrchr(p, '.');

  //Dot needs to be > Slash else it is not part of the file name
  if(Dot < Slash) Dot = NULL;

  if(Path)
  {
    if(Slash)
    {
      memcpy(Path, FullName, Slash - FullName + 1);
      Path[Slash - FullName + 1] = '\0';
    }
    else
      Path[0] = '\0';
  }

  if(FileExt)
  {
    if(Dot) strcpyUC(FileExt, Dot);
       else FileExt[0] = '\0';
  }

  if(FileName)
  {
    if(!Slash) Slash = p - 1;
    if(!Dot) Dot = strrchr(p, '\0');
    strncpyUC(FileName, Slash + 1, Dot - Slash - 1);
    FileName[Dot - Slash - 1] = '\0';
  }

  TRACEEXIT();
}
