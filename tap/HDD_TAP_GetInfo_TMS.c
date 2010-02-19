#include                <string.h>
#include                "../libFireBird.h"
#include                "ELF.h"

#ifdef _TMS_

//*** Prototypes ***
bool  ELFOpenFile(char *FileName);
bool  ELFReadELFHeader(void);
bool  ELFReadSectionHeaders(void);
bool  ELFReadShstrtabSection(void);
dword ELFGetSectionIndex(char *SectionName);
bool  ELFReadDWORD(dword SectionIndex, dword *Data);
bool  ELFReadData(dword SectionIndex, byte *Data);
void  Cleanup(void);

TYPE_File               *fTAP = NULL;
Elf32_Ehdr              *ELFHeader = NULL;       //The ELF file header
Elf32_Shdr              *SectionHeaders = NULL;  //Array of all section headers
char                    *shstrtab = NULL;        //Section header string table (a list of the names of the sections)
char                    *strtab = NULL;          //String table section
Elf32_Sym               *symtab = NULL;          //Symbol table section

#define SEEK_SET        0


bool HDD_TAP_GetInfo(char *FileName, tTAPInfo *pTAPInfo)
{
  dword                 Index;
  char                  s[128];

  if(!pTAPInfo) return FALSE;

  if(!ELFOpenFile(FileName))
  {
    Cleanup();
    return FALSE;
  }

  if(!ELFReadELFHeader())
  {
    Cleanup();
    return FALSE;
  }

  if(!ELFReadSectionHeaders())
  {
    Cleanup();
    return FALSE;
  }

  if(!ELFReadShstrtabSection())
  {
    Cleanup();
    return FALSE;
  }

  Index = ELFGetSectionIndex("._tap_id");
  if((Index == 0) || !ELFReadDWORD(Index, &pTAPInfo->TAPID))
  {
    Cleanup();
    return FALSE;
  }

  pTAPInfo->Date = 0;
  Index = ELFGetSectionIndex("._tap_etcinfo");
  if((Index != 0) && ELFReadData(Index, s))
  {
    word                y, m, d;
    int                 i;
    char                Mon[13][4] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    //"Dec  9 2009"
    y = atoi(&s[7]);
    s[6] = '\0';

    d = atoi(&s[4]);

    s[3] = '\0';
    m = 0;
    for(i = 1; i <= 12; i++)
      if(!strcmp(s, Mon[i]))
      {
        m = i;
        break;
      }

    pTAPInfo->Date = TAP_MakeMjd(y, m, d);
  }

  pTAPInfo->TAPName[0] = '\0';
  Index = ELFGetSectionIndex("._tap_program_name");
  if(Index && ELFReadData(Index, pTAPInfo->TAPName))

  pTAPInfo->Author[0] = '\0';
  Index = ELFGetSectionIndex("._tap_author_name");
  if(Index && ELFReadData(Index, pTAPInfo->Author))

  pTAPInfo->Description[0] = '\0';
  Index = ELFGetSectionIndex("._tap_description");
  if(Index && ELFReadData(Index, pTAPInfo->Description))

  Cleanup();

  return TRUE;
}

bool ELFOpenFile(char *FileName)
{
  fTAP = TAP_Hdd_Fopen(FileName);

  return (fTAP != NULL);
}

bool ELFReadELFHeader(void)
{
  if(!(ELFHeader = TAP_MemAlloc(sizeof(Elf32_Ehdr)))) return FALSE;
  if(TAP_Hdd_Fread(ELFHeader, sizeof(Elf32_Ehdr), 1, fTAP) != 1) return FALSE;

  return TRUE;
}

bool ELFReadSectionHeaders(void)
{
  if(ELFHeader->e_shnum == 0) return FALSE;
  if(!(SectionHeaders = TAP_MemAlloc(ELFHeader->e_shnum * sizeof(Elf32_Shdr)))) return FALSE;
  if(!TAP_Hdd_Fseek(fTAP, ELFHeader->e_shoff, SEEK_SET)) return FALSE;
  if(TAP_Hdd_Fread(SectionHeaders, ELFHeader->e_shnum * sizeof(Elf32_Shdr), 1, fTAP) != 1) return FALSE;

  return TRUE;
}

bool ELFReadShstrtabSection(void)
{
  Elf32_Shdr           *pshstrtabSH = NULL;   //Shortcut to speed up access to the .shstrtab section header

  //Read the .shstrtab section. It contains a "string database" with the names of all sections
  if(ELFHeader->e_shtrndx >= ELFHeader->e_shnum) return FALSE;
  pshstrtabSH = &SectionHeaders[ELFHeader->e_shtrndx];
  if(pshstrtabSH->sh_type != SHT_STRTAB) return FALSE;
  if(!(shstrtab = TAP_MemAlloc(pshstrtabSH->sh_size))) return FALSE;
  if(!TAP_Hdd_Fseek(fTAP, pshstrtabSH->sh_offset, SEEK_SET)) return FALSE;
  if(TAP_Hdd_Fread(shstrtab, pshstrtabSH->sh_size, 1, fTAP) != 1) return FALSE;

  return TRUE;
}

dword ELFGetSectionIndex(char *SectionName)
{
  int                   i;

  //Loop through all section headers and locate SectionName
  for(i = 1; i < ELFHeader->e_shnum; i++)
    if(!strcmp(&shstrtab[SectionHeaders[i].sh_name], SectionName)) return i;

  return 0;
}

bool ELFReadDWORD(dword SectionIndex, dword *Data)
{
  Elf32_Shdr           *pSection = NULL;     //Shortcut to speed up access

  pSection = &SectionHeaders[SectionIndex];

  if(pSection->sh_size != sizeof(dword)) return FALSE;

  if(Data)
  {
    if(!TAP_Hdd_Fseek(fTAP, pSection->sh_offset, SEEK_SET)) return FALSE;
    if(TAP_Hdd_Fread(Data, pSection->sh_size, 1, fTAP) != 1) return FALSE;
  }

  return TRUE;
}

bool ELFReadData(dword SectionIndex, byte *Data)
{
  Elf32_Shdr           *pSection = NULL;     //Shortcut to speed up access

  pSection = &SectionHeaders[SectionIndex];

  if(Data)
  {
    if(!TAP_Hdd_Fseek(fTAP, pSection->sh_offset, SEEK_SET)) return FALSE;
    if(TAP_Hdd_Fread(Data, pSection->sh_size, 1, fTAP) != 1) return FALSE;
  }

  return TRUE;
}

void Cleanup(void)
{
  if(fTAP)
  {
    TAP_Hdd_Fclose(fTAP);
    fTAP = NULL;
  }

  if(ELFHeader)
  {
    TAP_MemFree(ELFHeader);
    ELFHeader = NULL;
  }

  if(SectionHeaders)
  {
    TAP_MemFree(SectionHeaders);
    SectionHeaders = NULL;
  }

  if(shstrtab)
  {
    TAP_MemFree(shstrtab);
    shstrtab = NULL;
  }

  if(strtab)
  {
    TAP_MemFree(strtab);
    strtab = NULL;
  }
}

#endif
