#include "common.h"

extern s8 D_800CD280;
extern s16 D_8010A910;
extern s16 D_8010A912_552C82;
extern s16 D_8010A914;
extern void *D_8010AB9C_552F0C;
extern s16 D_8010AC28;
extern s16 D_8010AC2A;

extern void func_800E8180_CFF50(f32, f32);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_80106FF0_54F360);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_80107030_54F3A0);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_801070D8_54F448);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_80107140_54F4B0);

// References hvq rom start
INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_80107204_54F574);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_80107920_54FC90);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_8010818C_5504FC);

void func_8010822C_55059C()
{
    s16 sp10;

    D_800CD280 = 0;
    func_801060D0_54E440(&D_8010AB9C_552F0C);
    D_8010A912_552C82 = 1;
    func_800E4F50_CCD20(&bin_hvq_ROM_START);
    func_800E52DC_CD0AC(0x20);
    func_800E8180_CFF50(1000.0f, 10000.0f);
    D_8010AC2A = 0xB;
    InitFadeIn(0xB, 0x10);

    while (GetFadeStatus() != 0)
    {
        SleepVProcess();
    }
    func_8010818C_5504FC(&sp10, -1);
    while ((s32)sp10 >= -1)
    {
        SleepVProcess();
    }

    D_8010AC2A = 0xB;
    D_8010AC28 = 0x36;
    D_8010A914 = 2;
    D_8010A910 = 1;

    while (TRUE)
    {
        SleepVProcess();
    }
}

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_8010832C_55069C);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_801083A4_550714);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_801085E8_550958);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_801086E4_550A54);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_80108884_550BF4);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_80108AC0_550E30);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_80108CB8_551028);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_80108D04_551074);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_80108D34_5510A4);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_80108F0C_55127C);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_8010A370_5526E0);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_8010A4A4_552814);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_8010A558_5528C8);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_8010A5C4_552934);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_8010A738_552AA8);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_8010A7B0_552B20);

INCLUDE_ASM(s32, "overlays/overlay125/54F360", func_8010A7EC_552B5C);
