#include "common.h"
#include "board.h"

extern s32 D_800B1A30;

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

INCLUDE_ASM(s32, "36650", func_80035AB4);

INCLUDE_ASM(s32, "36650", func_80035B2C);

INCLUDE_ASM(s32, "36650", func_80035B80);

INCLUDE_ASM(s32, "36650", func_80035BD8);

void func_80035C20(s16 arg0, s16 arg1) {
    if (func_80035EB0(0xF) == 0) {
        D_800CC0CA[arg0] = arg1;
    }
}

u16 func_80035C6C(s16 arg0) {
    return D_800CC0CA[arg0];
}

void func_80035C84(s8 arg0) {
    D_800CD058.current_board_index = arg0;
}

INCLUDE_ASM(u8 *, "36650", func_80035C90);

u8 func_80035CF8(s16 arg0) {
    return *func_80035C90(arg0);
}

INCLUDE_ASM(s32, "36650", func_80035D1C);

INCLUDE_ASM(s32, "36650", func_80035DA4);

INCLUDE_ASM(s32, "36650", func_80035E3C);

u8 *func_80035E60(s16 arg0) {
    u8 *temp_v0 = func_80035C90(arg0);
    *temp_v0 = *temp_v0; // ?
    return temp_v0;
}

u8 *func_80035E88(s16 arg0) {
    u8 *temp_v0 = func_80035C90(arg0);
    *temp_v0 = *temp_v0; // ?
    return temp_v0;
}

INCLUDE_ASM(s32, "36650", func_80035EB0);

INCLUDE_ASM(s32, "36650", func_80035EF4);

INCLUDE_ASM(s32, "36650", func_80035F44);

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
    } else {
        b = feature + 7;
    }

    b >>= 3;
    b <<= 3;
    b = feature - b;

    return ret & (1 << b);
}

INCLUDE_ASM(s32, "36650", func_80035FDC);

INCLUDE_ASM(s32, "36650", func_8003602C);

INCLUDE_ASM(s32, "36650", func_80036080);

s32 func_800360B8() {
    return D_800B1A30;
}
