#include "common.h"
#include "../../board.h"
#include "../../object.h"

struct strD_80107530_3C7EA0 {
    struct coords_3d unk0;
    struct coords_3d unkC;
};

extern struct strD_80107530_3C7EA0 D_80107530_3C7EA0;

extern void func_800E69BC_FA5DC(s32);
extern void func_800E9344_FCF64(f32, f32);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_801059A0_3C6310);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80105A68_3C63D8);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80105AAC_3C641C);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80105B04_3C6474);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80105C9C_3C660C);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80105CD4_3C6644);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80105DEC_3C675C);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80105F9C_3C690C);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_801060A4_3C6A14);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80106100_3C6A70);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_801066E0_3C7050);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80106768_3C70D8);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80107178_3C7AE8);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_801072B0_3C7C20);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_801072FC_3C7C6C);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80107358_3C7CC8);

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80107384_3C7CF4);

void func_801073B0_3C7D20() {
    struct coords_3d temp_s0[2];
    s32 *s0arr = (s32 *)(&temp_s0);
    temp_s0[0] = D_80107530_3C7EA0.unk0;
    temp_s0[1] = D_80107530_3C7EA0.unkC;
    func_80012220(1, &D_80107530_3C7EA0);
    func_800E6630_FA250(&bin_hvq_ROM_START);
    func_800E69BC_FA5DC(s0arr[D_800CD058.current_board_index]);
    func_800E9344_FCF64(1000.0f, 10000.0f);
}

INCLUDE_ASM(s32, "overlays/overlay81/3C6310", func_80107450_3C7DC0);
