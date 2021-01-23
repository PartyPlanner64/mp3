#include "common.h"
#include "board.h"

extern u8 D_800CD0B6;

INCLUDE_ASM(s32, "code_36650", func_80035A50);

void func_80035AA8(s8 arg0) {
    D_800CD058.unk10 = arg0;
}

INCLUDE_ASM(s32, "code_36650", func_80035AB4);

INCLUDE_ASM(s32, "code_36650", func_80035B2C);

INCLUDE_ASM(s32, "code_36650", func_80035B80);

INCLUDE_ASM(s32, "code_36650", func_80035BD8);

INCLUDE_ASM(s32, "code_36650", func_80035C20);

INCLUDE_ASM(s32, "code_36650", func_80035C6C);

INCLUDE_ASM(s32, "code_36650", func_80035C84);

INCLUDE_ASM(s32, "code_36650", func_80035C90);

INCLUDE_ASM(s32, "code_36650", func_80035CF8);

INCLUDE_ASM(s32, "code_36650", func_80035D1C);

INCLUDE_ASM(s32, "code_36650", func_80035DA4);

INCLUDE_ASM(s32, "code_36650", func_80035E3C);

INCLUDE_ASM(s32, "code_36650", func_80035E60);

INCLUDE_ASM(s32, "code_36650", func_80035E88);

INCLUDE_ASM(s32, "code_36650", func_80035EB0);

INCLUDE_ASM(s32, "code_36650", func_80035EF4);

INCLUDE_ASM(s32, "code_36650", func_80035F44);

// IsBoardFeatureFlagSet
s32 func_80035F98(s32 feature) {
    s32 a, b;
    s32 ret;

    a = feature;
    if (feature < 0) {
        a += 7;
    }
    a >>= 3;

    ret = (&D_800CD0B6)[a];

    if (feature >= 0) {
        b = feature;
    }
    else {
        b = feature + 7;
    }

    b >>= 3;
    b <<= 3;
    b = feature - b;

    return ret & (1 << b);
}

INCLUDE_ASM(s32, "code_36650", func_80035FDC);

INCLUDE_ASM(s32, "code_36650", func_8003602C);

INCLUDE_ASM(s32, "code_36650", func_80036080);

INCLUDE_ASM(s32, "code_36650", func_800360B8);
