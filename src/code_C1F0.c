#include "common.h"

// Sprite graphics related.

INCLUDE_ASM(s32, "code_C1F0", func_8000B5F0);

INCLUDE_ASM(s32, "code_C1F0", func_8000B638);

INCLUDE_ASM(s32, "code_C1F0", func_8000B690);

INCLUDE_ASM(s32, "code_C1F0", func_8000B710);

INCLUDE_ASM(s32, "code_C1F0", func_8000B7A0);

// Load sprite from main fs.
s16 func_8000B838(s32 dirAndFile) {
    s16 ret;
    void *fsAlloc;

    fsAlloc = ReadMainFS(dirAndFile);
    ret = func_80055810(fsAlloc);
    FreePerm(fsAlloc);
    return ret;
}

INCLUDE_ASM(s32, "code_C1F0", func_8000B880);

INCLUDE_ASM(s32, "code_C1F0", func_8000BA00);

INCLUDE_ASM(s32, "code_C1F0", func_8000BA30);

INCLUDE_ASM(s32, "code_C1F0", func_8000BB54);

INCLUDE_ASM(s32, "code_C1F0", func_8000BB94);

INCLUDE_ASM(s32, "code_C1F0", func_8000BBD4);

INCLUDE_ASM(s32, "code_C1F0", func_8000BBFC);

INCLUDE_ASM(s32, "code_C1F0", func_8000BC48);

INCLUDE_ASM(s32, "code_C1F0", func_8000BC88);

INCLUDE_ASM(s32, "code_C1F0", func_8000BCC8);

INCLUDE_ASM(s32, "code_C1F0", func_8000BD08);

INCLUDE_ASM(s32, "code_C1F0", func_8000BD50);

INCLUDE_ASM(s32, "code_C1F0", func_8000BD94);

INCLUDE_ASM(s32, "code_C1F0", func_8000BDDC);

INCLUDE_ASM(s32, "code_C1F0", func_8000BE1C);

INCLUDE_ASM(s32, "code_C1F0", func_8000BE5C);

INCLUDE_ASM(s32, "code_C1F0", func_8000BEAC);

INCLUDE_ASM(s32, "code_C1F0", func_8000BF00);

INCLUDE_ASM(s32, "code_C1F0", func_8000BF48);

INCLUDE_ASM(s32, "code_C1F0", func_8000BF8C);

INCLUDE_ASM(s32, "code_C1F0", func_8000BFEC);

INCLUDE_ASM(s32, "code_C1F0", func_8000C184);
