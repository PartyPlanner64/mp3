#include "common.h"
#include "../../board.h"
#include "../../object.h"

struct strD_80107530_3C7EA0 {
    struct coords_3d unk0;
    struct coords_3d unkC;
};

extern struct strD_80107530_3C7EA0 D_80109048_3CDEA8;

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_801059A0_3CA800);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80105AE0_3CA940);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80105C60_3CAAC0);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80105DC4_3CAC24);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80105F8C_3CADEC);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80106014_3CAE74);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_801060A8_3CAF08);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_801061FC_3CB05C);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_801062CC_3CB12C);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80106388_3CB1E8);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_801066F0_3CB550);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80106CFC_3CBB5C);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_801071F4_3CC054);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_8010727C_3CC0DC);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80107580_3CC3E0);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80107E28_3CCC88);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80107E58_3CCCB8);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80108B3C_3CD99C);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80108BB0_3CDA10);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80108C0C_3CDA6C);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80108C58_3CDAB8);

INCLUDE_ASM(s32, "overlays/overlay83/3CA800", func_80108C8C_3CDAEC);

void func_80108CC0_3CDB20() {
    struct coords_3d temp_s0[2];
    s32 *s0arr = (s32 *)(&temp_s0);
    temp_s0[0] = D_80109048_3CDEA8.unk0;
    temp_s0[1] = D_80109048_3CDEA8.unkC;
    func_80012220(1, &D_80109048_3CDEA8);
    func_800E6630_FA250(&bin_hvq_ROM_START);
    func_800E69BC_FA5DC(s0arr[D_800CD058.current_board_index]);
}

void func_80108D44_3CDBA4() {
    func_800E69D8_FA5F8();
    func_800E66E0_FA300();
}
