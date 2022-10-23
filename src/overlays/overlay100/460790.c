#include "common.h"
#include "../../board.h"
#include "../../object.h"

struct strD_80107530_3C7EA0
{
    struct coords_3d unk0;
    struct coords_3d unkC;
};

extern struct strD_80107530_3C7EA0 D_80109550;

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_801059A0_460790);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_80105B3C_46092C);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_80105CBC_460AAC);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_80105E20_460C10);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_80105FE8_460DD8);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_80106070_460E60);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_801061C4_460FB4);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_80106294_461084);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_80106350_461140);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_801066B8_4614A8);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_80106CB4_461AA4);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_80106D18_461B08);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_80108FDC_463DCC);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_80109050_463E40);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_801090AC_463E9C);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_801090F8_463EE8);

INCLUDE_ASM(s32, "overlays/overlay100/460790", func_8010911C_463F0C);

void func_80109158_463F48()
{
    struct coords_3d temp_s0[2];
    s32 *s0arr = (s32 *)(&temp_s0);
    temp_s0[0] = D_80109550.unk0;
    temp_s0[1] = D_80109550.unkC;
    func_80012220(1, &D_80109550);
    func_800E4F50_CCD20(&bin_hvq_ROM_START);
    func_800E52DC_CD0AC(s0arr[D_800CD058.current_board_index]);
}

void func_801091DC_463FCC()
{
    func_800E52F8_CD0C8();
    func_800E5000_CCDD0();
}
