#include <string.h>
#include "libFireBird.h"

bool StringEndsWith(char *text, char *postfix)
{
  TRACEENTER();

  char                 *p;
  int                   l, i;
  bool                  ret = FALSE;

  if(!text || !*text || !postfix || !*postfix)
  {
    TRACEEXIT();
    return FALSE;
  }

  l = strlen(text);
  i = strlen(postfix);

  if (l >= i)
  {
    p = &text[l - i];
    ret = (memcmp(p, postfix, i) == 0);
  }

  TRACEEXIT();
  return ret;
}
