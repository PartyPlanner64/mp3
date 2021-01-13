#include "common.h"

extern s8 D_80102C48;

INCLUDE_ASM(s32, "overlays/shared_board/F5070", D_800E1450_F5070);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E17B0_F53D0);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E1828_F5448);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E18FC_F551C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E1934_F5554);

void func_800E1F28_F5B48() {
    D_80102C48 = 0;
    func_800E1934_F5554();
}

void func_800E1F48_F5B68() {
    D_80102C48 = 1;
    func_800E1934_F5554();
}
