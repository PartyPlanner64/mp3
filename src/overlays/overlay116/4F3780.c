#include "common.h"
#include "../../board.h"

extern s32 D_80108908_4F66E8[];

INCLUDE_ASM(s32, "overlays/overlay116/4F3780", func_801059A0_4F3780);

INCLUDE_ASM(s32, "overlays/overlay116/4F3780", func_80105CAC_4F3A8C);

INCLUDE_ASM(s32, "overlays/overlay116/4F3780", func_80105E0C_4F3BEC);

INCLUDE_ASM(s32, "overlays/overlay116/4F3780", func_80105E64_4F3C44);

void func_80105EF4_4F3CD4() {
    s32 phi_a0;
    struct strCD058 *cd058 = &D_800CD058;

    func_800E6630_FA250(&bin_hvq_ROM_START);
    phi_a0 = 0x17;
    if ((cd058->unk0 & 2) == 0) {
        phi_a0 = D_80108908_4F66E8[cd058->current_board_index];
    }
    func_800E6720_FA340(phi_a0, 0);
    func_80105F50_4F3D30();
}

INCLUDE_ASM(s32, "overlays/overlay116/4F3780", func_80105F50_4F3D30);

INCLUDE_ASM(s32, "overlays/overlay116/4F3780", func_80105F78_4F3D58);

INCLUDE_ASM(s32, "overlays/overlay116/4F3780", func_801060A4_4F3E84);

INCLUDE_ASM(s32, "overlays/overlay116/4F3780", func_80106660_4F4440);

void func_80106908_4F46E8(void) {
}

void func_80106910_4F46F0(void) {
}

INCLUDE_ASM(s32, "overlays/overlay116/4F3780", func_80106918_4F46F8);

INCLUDE_ASM(s32, "overlays/overlay116/4F3780", func_801069FC_4F47DC);
