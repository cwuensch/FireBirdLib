#include                "ELF.h"
#include                "FBLib_elf.h"

bool ELFOpenAbsFile(char *FileName)
{
  TRACEENTER();

  fTAP = open(FileName, O_RDONLY);

  TRACEEXIT();
  return (fTAP != 0);
}
