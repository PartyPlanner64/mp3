#include "common.h"
#include "../../board.h"

extern s32 D_8010AD0C_4EC12C[];

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_801059A0_4E6DC0);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80105C08_4E7028);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80105CE8_4E7108);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80106A80_4E7EA0);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80106C80_4E80A0);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80106D50_4E8170);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80106D88_4E81A8);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80106DB8_4E81D8);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80106DE8_4E8208);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80106F40_4E8360);

void func_80106FC8_4E83E8() {
    s32 phi_a0;
    struct strCD058 *cd058 = &D_800CD058;

    func_800E6630_FA250(&bin_hvq_ROM_START);
    phi_a0 = 0x17;
    if ((cd058->unk0 & 2) == 0) {
        phi_a0 = D_8010AD0C_4EC12C[cd058->current_board_index];
    }
    func_800E6720_FA340(phi_a0, 0);
    func_80107024_4E8444();
}

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80107024_4E8444);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_8010705C_4E847C);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80107188_4E85A8);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80107234_4E8654);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80107650_4E8A70);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80107800_4E8C20);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_801079B0_4E8DD0);

INCLUDE_ASM(s32, "overlays/minigame_results/4E6DC0", func_80107A58_4E8E78);
