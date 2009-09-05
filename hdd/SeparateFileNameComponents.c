#include <string.h>
#include <stdlib.h>
#include "../libFireBird.h"

void SeparateFileNameComponents(char *FileName, char *Name, char *Ext, int *Index, bool *isRec, bool *isDel)
{
  char                 *dot;

  strcpy(Name, FileName);

  *isDel = FALSE;
  if(StringEndsWith(Name, ".del"))
  {
    *isDel = TRUE;
    Name[strlen(Name) - 4] = '\0';
  }

  if(StringEndsWith(Name, ".rec.inf")) Name[strlen(Name) - 4] = '\0';
  if(StringEndsWith(Name, ".rec.nav")) Name[strlen(Name) - 4] = '\0';

  *isRec = FALSE;
  if(StringEndsWith(Name, ".rec")) *isRec = TRUE;

  Ext[0] = '\0';
  dot = strrchr(Name, '.');
  if(dot)
  {
    strcpy(Ext, dot);
    *dot = '\0';
  }

  *Index = 0;
  if(strlen(Name) > 2)
  {
    if((Name[strlen(Name) - 2] == '-') && isdigit(Name[strlen(Name) - 1]))
    {
      *Index = strtol(&Name[strlen(Name) - 1], NULL, 10);
      Name[strlen(Name) - 2] = '\0';
    }

    if(strlen(Name) > 3)
    {
      if((Name[strlen(Name) - 3] == '-') && isdigit(Name[strlen(Name) - 2]) && isdigit(Name[strlen(Name) - 1]))
      {
        *Index = strtol(&Name[strlen(Name) - 2], NULL, 10);
        Name[strlen(Name) - 3] = '\0';
      }
    }
  }
}
