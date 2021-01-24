#include "common.h"
#include "board.h"

extern void *D_800CC0C8;
extern s16 D_800CC0CA[];

extern u8 D_800CD0B6;

extern void *D_800D0308;

void func_80035A50() {
    u8 *D_800CC0C8loc;

    D_800CC0C8loc = (u8 *)&D_800CC0C8;

    bzero(D_800CC0C8loc, 0xA4);
    bzero(&D_800D0308, 0x74);
    *D_800CC0C8loc = 0x91;
    D_800CD058.current_board_index = 0;
    D_800CD058.unk10 = 0;
}

void func_80035AA8(s8 arg0) {
    D_800CD058.unk10 = arg0;
}

INCLUDE_ASM(s32, "code_36650", func_80035AB4);

INCLUDE_ASM(s32, "code_36650", func_80035B2C);

INCLUDE_ASM(s32, "code_36650", func_80035B80);

INCLUDE_ASM(s32, "code_36650", func_80035BD8);

void func_80035C20(s16 arg0, s16 arg1) {
    if (func_80035EB0(0xF) == 0) {
        D_800CC0CA[arg0] = arg1;
    }
}

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
