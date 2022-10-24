#include "common.h"

// string table parsing code.

extern void *D_800B1A40; // strings ROM pointer
extern s32 D_800B1A44;   // string directory count
extern u32 *D_800B1A48;  // string directory table
extern s32 D_800B1A4C;   // string directory table size

void func_80036380(void *stringsRomPtr) {
    s32 stringDirTableSize;
    u32 *stringDirTable;
    u32 *stringsHeader;

    D_800B1A40 = stringsRomPtr;
    stringsHeader = MallocPerm(16);
    HuRomDmaRead(stringsRomPtr, stringsHeader, 16);
    D_800B1A44 = *stringsHeader;
    FreePerm(stringsHeader);
    stringDirTableSize = D_800B1A44 * 4;
    D_800B1A4C = stringDirTableSize;
    stringDirTable = MallocPerm(stringDirTableSize);
    D_800B1A48 = stringDirTable;
    HuRomDmaRead(stringsRomPtr + 4, stringDirTable, D_800B1A4C);
}

void func_80036414(void *ptr) {
    D_800B1A40 = ptr;
    HuRomDmaRead(ptr + 4, D_800B1A48, D_800B1A4C);
}

struct str80036448 {
    void *unk0;
    s32 unk4; // decompressed size
    s32 unk8; // compression type
};

struct string_dir_header {
    s32 decompressedSize;
    s32 compressionType;
};

void func_80036448(s32 arg0, struct str80036448 *arg1) {
    s32 temp_a0;
    struct string_dir_header *dirHeader;

    dirHeader = MallocPerm(16);
    temp_a0 = ((s8 *)D_800B1A40) + *(D_800B1A48 + arg0);
    arg1->unk0 = temp_a0;
    HuRomDmaRead(temp_a0, dirHeader, 16);
    arg1->unk0 = arg1->unk0 + 8;
    arg1->unk4 = dirHeader->decompressedSize;
    arg1->unk8 = dirHeader->compressionType;
    FreePerm(dirHeader);
}

INCLUDE_ASM(s32, "36F80", func_800364DC);

void func_800365E8(void *ptr) {
    if (ptr != NULL) {
        FreePerm(ptr);
    }
}
