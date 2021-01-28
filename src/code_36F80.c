#include "common.h"

extern void *D_800B1A40; // strings ROM pointer
extern s32 D_800B1A44; // string directory count
extern void *D_800B1A48; // string directory table
extern s32 D_800B1A4C; // string directory table size

void func_80036380(void *stringsRomPtr) {
    s32 stringDirTableSize;
    void *stringDirTable;
    u32 *stringsHeader;

    D_800B1A40 = stringsRomPtr;
    stringsHeader = MallocPerm(16);
    func_8004DA40(stringsRomPtr, stringsHeader, 16);
    D_800B1A44 = *stringsHeader;
    FreePerm(stringsHeader);
    stringDirTableSize = D_800B1A44 * 4;
    D_800B1A4C = stringDirTableSize;
    stringDirTable = MallocPerm(stringDirTableSize);
    D_800B1A48 = stringDirTable;
    func_8004DA40(stringsRomPtr + 4, stringDirTable, D_800B1A4C);
}

INCLUDE_ASM(s32, "code_36F80", func_80036414);

INCLUDE_ASM(s32, "code_36F80", func_80036448);

INCLUDE_ASM(s32, "code_36F80", func_800364DC);

INCLUDE_ASM(s32, "code_36F80", func_800365E8);
