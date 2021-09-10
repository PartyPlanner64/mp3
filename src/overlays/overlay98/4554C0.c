#include "common.h"

extern void func_800E8180_CFF50(f32, f32);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_801059A0_4554C0);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80105B60_455680);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80105BD0_4556F0);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80106800_456320);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_8010690C_45642C);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_801069DC_4564FC);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80106A24_456544);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80106C4C_45676C);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80106D48_456868);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80106EF8_456A18);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_8010709C_456BBC);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_8010753C_45705C);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80107644_457164);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80107A58_457578);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80107AF4_457614);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80107BC0_4576E0);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80107E7C_45799C);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80107F3C_457A5C);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80108138_457C58);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_80108174_457C94);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_801082C0_457DE0);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_8010856C_45808C);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_8010A938_45A458);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_8010A978_45A498);

INCLUDE_ASM(s32, "overlays/overlay98/4554C0", func_8010AA9C_45A5BC);

void func_8010AAE8_45A608() {
    func_800D7EB8_BFC88();
    func_800F3F4C_DBD1C();
    func_800EF840_D7610();
    func_800F4300_DC0D0();
}

void func_8010AB1C_45A63C() {
    func_800F4314_DC0E4();
    func_800EF880_D7650();
    func_800F4030_DBE00();
    func_800D7F0C_BFCDC();
}

void func_8010AB50_45A670() {
    func_80012220(1);
    func_80019514(1, 0xFF, 0xFF, 0xFF);
    func_800E4F50_CCD20(&bin_hvq_ROM_START);
    func_800E52DC_CD0AC(0);
    func_800E8180_CFF50(1000.0f, 10000.0f);
}

void func_8010ABB0_45A6D0() {
    func_800E52F8_CD0C8();
    func_800E5000_CCDD0();
}
