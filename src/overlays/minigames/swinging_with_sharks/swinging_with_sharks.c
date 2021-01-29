#include "common.h"
#include "../../../player.h"

extern s8 D_800CD280;

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", func_801059A0_2E0D20);
// void func_801059A0_2E0D20() {
//     s16 temp_a0_2;
//     s32 temp_a0;
//     s32 temp_v0;
//     s32 temp_v1;
//     s32 phi_v0;
//     s32 phi_a0;
//     s16 phi_a0_2;
//     s32 i;

//     InitObjSys(0x14, 0xA);
//     func_8004A208();
//     func_800142A0(0x14);
//     func_8001F38C(0, 0xFF, 0);
//     D_800CD280 = 1;
//     func_8000B364(0, 0, 0, 0x43A00000, 240.0f);
//     func_8000B3C8(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
//     D_800D138C.unk0 = 334.0f;
//     D_8010BBB0.unk0 = 0.0f;
//     D_800D138C.unk4 = 0.0f;
//     D_800CE1C8 = 2750.0f;
//     D_800D6ABC.unk0 = -698.0f;
//     D_800D6ABC.unk4 = 363.0f;
//     D_800D6ABC.unk8 = -112.9f;
//     D_8010BBB4_197454 = 20.0f;
//     D_8010BBB0.unk-8 = (bitwise s32) D_800D138C.unk0;
//     D_8010BBB0.unk-4 = (bitwise s32) D_800D138C.unk4;
//     D_8010BBB0.unk0 = (bitwise f32) D_800D138C.unk8;
//     D_8010BB90_1B2B60.unk0 = (s32) D_8010BBB0.unk-8;
//     D_8010BB90_1B2B60.unk4 = (s32) D_8010BBB0.unk-4;
//     D_8010BB90_1B2B60.unk8 = (bitwise s32) D_8010BBB0.unk0;
//     D_8010BB9C_22B93C = (f32) D_800CE1C8;
//     D_8010BB78_2A7608.unk0 = (bitwise s32) D_800D6ABC.unk0;
//     D_8010BB78_2A7608.unk4 = (bitwise s32) D_800D6ABC.unk4;
//     D_8010BB78_2A7608.unk8 = (bitwise s32) D_800D6ABC.unk8;
//     func_8001247C(0, D_8010BBB4_197454, 0x43FA0000, 0x45FA0000);
//     func_80019490(3);
//     func_80019514(0, 0x40, 0x40, 0x60);
//     func_80019568(0, 0x42B80000, 0x429E0000, 0x41B00000);
//     func_800194B8(0, 1, 1);
//     func_80019514(2, 0x64, 0xFF, 0xFF);
//     func_80019568(2, 0xC2E60000, 0x40C00000, 0xC2040000);
//     func_800194B8(2, 1, 1);
//     func_80047620(0x2710, 0, 0, -1, &D_801098C0_2E4C40);
//     func_80047B38(func_80047620(0x7FDA, 0, 0, -1, &D_8004B340), 0xA0);
//     D_8010B9E0 = (u16)0;
//     D_8010B9E2 = (u16)0;
//     func_80047620(0x3E8, 0, 0, -1, &D_80105FE4_2E1364);
//     func_80047620(0x3E8, 0, 0, -1, &D_80106398_2E1718);
//     func_80047620(0x384, 0, 0, -1, &D_801073F0_2E2770);
//     func_80047620(0x384, 0, 0, -1, &D_80107954_2E2CD4);
//     func_80047B38(func_80047620(0x384, 0, 0, -1, &D_80108B4C_2E3ECC), 0xA0);
//     func_80047620(0x384, 0, 0, -1, &D_801089A4_2E3D24);

//     phi_v0 = 0 * 8;
//     phi_a0 = 0;
//     for (i = 0; i < 4; i++) {
//         phi_a0_2 = (s16) phi_a0;
//         if (*(&gPlayers + ((phi_v0 - phi_a0) * 8)) != 0) {
//             temp_a0 = phi_a0 + 1;
//             phi_v0 = temp_a0 * 8;
//             phi_a0 = temp_a0;
//             phi_a0_2 = (s16) temp_a0;
//         }
//     }

//     D_8010B9D8 = phi_a0_2;
//     D_8010B9E8 = (gPlayers[phi_a0_2].flags & 1);
//     gPlayers[phi_a0_2].coins_won = -1;
//     D_8010B9DC = gPlayers[phi_a0_2].character;
//     D_8010B9DA = gPlayers[phi_a0_2].controller;
//     func_8010979C_2E4B1C(&D_8010ACEC);
//     if (D_8010B9E8 != 0) {
//         D_8010B9E8 = gPlayers[D_8010B9D8].cpu_difficulty + 1;
//         temp_a0_2 = D_8010B9D8;
//         D_8010B9EA = (s16) ((u32) *(&D_8010B418_2B4CC8 + (*(&D_800D1109 + (temp_a0_2 * 0x38)) * 2)) < (u32) (GetRandomByte() & 0xFF));
//         D_8010B9EC = (s16) ((GetRandomByte(temp_a0_2) & 0x1F & 0xFF) + 0xF);
//         if (D_8010B9EA != 0) {
//             D_8010B9EE = (s16) (s32) ((((((*(&D_8010B8E6 + (((s32) ((GetRandomByte() & 0xFF) * 5) >> 8) * 2)) * 0xC0) + D_800D03F8)->unk1C + 70.0f) / 1000.0f) * 70.0f) + 10.0f);
//         }
//     }
//     D_80107384_2E2704();
//     func_801077C4_2E2B44();
//     D_80108B24_2E3EA4();
//     D_8010AA68_2E5DE8();
//     D_80106334_2E16B4();
//     D_8010ACE4_1E8B04 = 0;
//     D_8010B9D0 = 80.0f;
//     D_8010B9DE = (u16)-1;
//     D_80108C08_2E3F88(0);
//     D_80108DB0_2E4130(&D_8010B9B8);
//     D_8010B9E4_238A54 = (u16)0;
//     func_8001FA68(D_8010B91E);
//     func_8001C514(D_8010B91E);
//     func_80045010(&D_8010B770, 1);
//     D_8010A41C_2E579C();
//     InitProcess(&D_80109950_2E4CD0, 0x3F00, 0x2000, 0);
//     InitProcess(&D_80109950_2E4CD0, 0x3F00, 0x2000, 0);
//     func_8004A520(0x44);
//     InitFadeIn(0xFF, 0x10);
// }

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80105FE4_2E1364);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80106334_2E16B4);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80106398_2E1718);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80106870_2E1BF0);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80106D44_2E20C4);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80107044_2E23C4);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_801071A8_2E2528);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80107384_2E2704);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_801073F0_2E2770);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80107628_2E29A8);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_801076DC_2E2A5C);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", func_801077C4_2E2B44);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80107954_2E2CD4);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80108474_2E37F4);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_801085F4_2E3974);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_801088F0_2E3C70);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_801089A4_2E3D24);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80108B24_2E3EA4);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80108B4C_2E3ECC);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80108C08_2E3F88);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80108DB0_2E4130);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", func_80108E00_2E4180);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", func_80108E50_2E41D0);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80108F20_2E42A0);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80109020_2E43A0);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_801096AC_2E4A2C);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", func_80109730_2E4AB0);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", func_8010979C_2E4B1C);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_801098C0_2E4C40);

void D_80109924_2E4CA4() {
    if (GetFadeStatus() == 0) {
        func_8004819C(1);
    }
}

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80109950_2E4CD0);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80109B04_2E4E84);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_80109C90_2E5010);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", func_8010A0C0_2E5440);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_8010A260_2E55E0);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_8010A41C_2E579C);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", func_8010A4DC_2E585C);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_8010AA68_2E5DE8);

INCLUDE_ASM(s32, "overlays/minigames/swinging_with_sharks/swinging_with_sharks", D_8010AAA0_2E5E20);
