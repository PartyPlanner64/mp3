#include "common.h"
#include "heap_permanent.h"
#include "heap_temporary.h"

INCLUDE_ASM(s32, "mainfs", func_80009880);

INCLUDE_ASM(s32, "mainfs", func_800098FC);

// Likely file break for mainfs.c

// 16 byte portion of a directory or file table, which is initially read from ROM.
struct mainfs_table_header {
    s32 count;
    s32 offsets[3]; // Enough to pad to size 16
};

struct mainfs_entry_info {
    u8 *file_bytes;
    s32 size;
    s32 compression_type;
};

extern void *D_800ABFC0; // FS ROM location
extern u32 D_800ABFC4; // Directory count
extern s32 *D_800ABFC8; // Directory offset table pointer.

extern void *D_800ABFCC; // FS ROM location (copy)
extern u32 D_800ABFD0; // Directory count (copy)
extern s32 *D_800ABFD4; // Directory offset table pointer (copy)

extern struct mainfs_table_header D_800ABFE0;

// Initialize file system from ROM.
void func_80009AC0(void *fs_rom_loc) {
    s32 dir_table_size;
    struct mainfs_table_header *mainfs_table_header;

    D_800ABFC0 = fs_rom_loc;
    mainfs_table_header = &D_800ABFE0;
    func_8004DA40(fs_rom_loc, mainfs_table_header, 16); // ExecRomCopy
    D_800ABFC4 = mainfs_table_header->count;
    dir_table_size = mainfs_table_header->count * 4;
    D_800ABFC8 = (s32 *)MallocPerm(dir_table_size);
    func_8004DA40(fs_rom_loc + 4, D_800ABFC8, dir_table_size);
    D_800ABFCC = D_800ABFC0;
    D_800ABFD0 = D_800ABFC4;
    D_800ABFD4 = D_800ABFC8;
}

void func_80009B64(s32 type, s32 index, struct mainfs_entry_info *info) {
    struct mainfs_table_header *mainfs_table_header;

    mainfs_table_header = &D_800ABFE0;

    switch (type) {
        case 0x2F:
            info->file_bytes = (u8 *)D_800ABFC0 + D_800ABFC8[index];
            break;
        case 0x2E:
            info->file_bytes = (u8 *)D_800ABFCC + D_800ABFD4[index];
            break;
    }

    func_8004DA40(info->file_bytes, mainfs_table_header, 16); // ExecRomCopy
    info->file_bytes += 8;
    info->size = mainfs_table_header->count;
    info->compression_type = mainfs_table_header->offsets[0];
}

/**
 * Reads a file from the main filesystem and decodes it.
 * File is in the permanent heap.
 */
void *ReadMainFS(s32 dirAndFile) {
    u32 dir;
    u32 file;

    dir = dirAndFile >> 16;
    file = dirAndFile & 0xFFFF;

    if (dir < D_800ABFC4) {
        func_80009EAC(0x2F, dir);

        if (file < D_800ABFD0) {
            return func_80009D4C(0x2E, file);
        }
    }

    return NULL;
}

INCLUDE_ASM(s32, "mainfs", func_80009C74);

INCLUDE_ASM(s32, "mainfs", func_80009CD8);

INCLUDE_ASM(s32, "mainfs", func_80009D4C);

INCLUDE_ASM(s32, "mainfs", func_80009DA8);

INCLUDE_ASM(s32, "mainfs", func_80009E04);

/**
 * Free file previously obtained through ReadMainFS.
 */
void FreeMainFS(void *file) {
    if (file != NULL) {
        FreePerm(file);
    }
}

void func_80009E8C(void *file) {
    if (file != NULL) {
        FreePerm(file); //! Should be FreeTemp, but not functionally problematic.
    }
}

INCLUDE_ASM(s32, "mainfs", func_80009EAC);

INCLUDE_ASM(s32, "mainfs", func_80009F64);

INCLUDE_ASM(s32, "mainfs", func_80009FF8);

INCLUDE_ASM(s32, "mainfs", func_8000A028);

INCLUDE_ASM(s32, "mainfs", func_8000A0D4);

INCLUDE_ASM(s32, "mainfs", func_8000A150);
