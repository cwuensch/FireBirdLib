#include                "ELF.h"
#include                "FBLib_elf.h"

int                      fTAP = 0;
Elf32_Ehdr              *ELFHeader = NULL;
Elf32_Shdr              *SectionHeaders = NULL;
char                    *shstrtab = NULL;
char                    *strtab = NULL;
Elf32_Sym               *symtab = NULL;


bool ELFOpenAbsFile(const char *FileName)
{
  fTAP = open(FileName, O_RDONLY);

  return (fTAP != 0);
}
