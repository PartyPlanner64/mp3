#include "common.h"

// strings-related.

extern s8 D_800A2150;
extern s8 D_800A2151;
extern s32 D_800CB99C;

struct str800CC69C {
    s8 unks5E[0x5E];
    s16 unk5E;
    s16 unk60;
    s16 unk62;
    s16 unk64;
}; // sizeof 0x27C

extern struct str800CC69C *D_800CC69C;

extern s32 D_800CD2A4;
extern s8 D_800D1F34;
extern void *D_800D1FE4;
extern s32 D_800D5540;
extern s8 D_800D6A26;
extern u16 D_800D6B62;

INCLUDE_ASM(s32, "code_5ACF0", func_8005A0F0);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A32C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A37C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A3C0);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A428);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A51C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A54C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A580);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A5B0);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A5EC);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A61C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A674);

INCLUDE_ASM(s32, "code_5ACF0", func_8005A6B0);
// void func_8005A6B0() {
//     s32 i;
//     struct str800CC69C *tempst;

//     if (D_800A2150 == 0) {
//         D_800CC69C = MallocTemp(0x27C0);

//         for (i = 0; i < 16; i++) {
//             D_800CC69C[i].unk5E = -1;
//         }

//         D_800CC69C[0]->unk62 = -1;
//         D_800CC69C[0]->unk64 = 1;
//         D_800CC69C[0]->unk5E = 0;
//         D_800CC69C[1]->unk62 = 0;
//         D_800CC69C[1]->unk64 = -1;
//         D_800CC69C[1]->unk5E = -0x218;

//         D_800D6A26 = 0;
//         D_800D1F34 = 0;
//         D_800D6B62 = 0x2710;
//         D_800A2151 = D_800CC0C9;
//         temp_v0_4 = D_800A2151 & 0xFF;
// TODO: contains jtbl in here
//         if ((((temp_v0_4 < 7U) ^ 1) | (temp_v0_4 == 0)) != 0) {
//             D_800A2151 = 2;
//         }
//         if (D_800A2151 == 1) {
//             D_800D1FE4 = func_80009C74(0x2B, D_800CC69C, -1);
//             phi_a0_2 = 0x1209850;
// block_13:
//             func_80036414(phi_a0_2);
//         } else {
//             D_800D1FE4 = func_80009C74(0x2C, D_800CC69C, -1);
//             if ((u32) (D_800A2151 - 2) < 5U) {
//                 phi_a0_2 = 0x121CAA0;
//                 goto block_13;
//             }
//         }

//         temp_v0_5 = func_80047EA0(&D_8005DDDC, 0x1001, 0x800, 0);
//         D_800D040C = temp_v0_5;
//         func_80047B80(temp_v0_5, 0xA0);
//         D_800A2150 = 1;
//         D_800CB99C = 0;
//         D_800D4084 = func_80009C74(0x29);
//         D_800CE2C4 = func_80009C74(0x2A);

//         phi_v0 = (u16)0 << 0x10;
//         phi_a0_3 = (u16)0;
// loop_15:
//         *((phi_v0 >> 0xF) + &D_800BDA50) = (u16)-1;
//         temp_v0_6 = phi_a0_3 + 1;
//         phi_v0 = temp_v0_6 << 0x10;
//         phi_a0_3 = temp_v0_6;
//         if ((s32) temp_v0_6 < 0xC) {
//             goto loop_15;
//         }

//         temp_s0 = ReadMainFS(0x33, &D_800BDA50);
//         D_800BDA68 = func_80055810(temp_s0);
//         FreeMainFS(temp_s0);

//         phi_v0_2 = (u16)0 << 0x10;
//         phi_a0_4 = (u16)0;
// loop_17:
//         *(&D_800D5206 + (phi_v0_2 >> 0x10)) = (u8)0;
//         temp_v0_7 = phi_a0_4 + 1;
//         phi_v0_2 = temp_v0_7 << 0x10;
//         phi_a0_4 = temp_v0_7;
//         if ((s32) temp_v0_7 < 5) {
//             goto loop_17;
//         }

//         D_800D5540 = 12;
//         D_800CD2A4 = 0;
//         //phi_return = 12;
//     }
//     //return phi_return;
// }


INCLUDE_ASM(s32, "code_5ACF0", func_8005A968);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B040);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B238);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B43C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B5EC);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B614);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B63C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B68C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B6BC);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B7B8);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B8F8);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B974);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BA28);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BA54);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BA90);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BB18);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BBC0);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BCA4);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BDA8);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BDFC);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BE30);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BEE0);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BF70);

INCLUDE_ASM(s32, "code_5ACF0", func_8005C02C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005C060);

INCLUDE_ASM(s32, "code_5ACF0", func_8005C154);

INCLUDE_ASM(s32, "code_5ACF0", func_8005C190);

INCLUDE_ASM(s32, "code_5ACF0", func_8005CC18);

INCLUDE_ASM(s32, "code_5ACF0", func_8005CC3C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005CCF0);

INCLUDE_ASM(s32, "code_5ACF0", func_8005CD38);

INCLUDE_ASM(s32, "code_5ACF0", func_8005CD84);

INCLUDE_ASM(s32, "code_5ACF0", func_8005CE10);

INCLUDE_ASM(s32, "code_5ACF0", func_8005CEB0);

INCLUDE_ASM(s32, "code_5ACF0", func_8005CF94);

INCLUDE_ASM(s32, "code_5ACF0", func_8005CFE0);

INCLUDE_ASM(s32, "code_5ACF0", func_8005D294);

INCLUDE_ASM(s32, "code_5ACF0", func_8005D2D4);

INCLUDE_ASM(s32, "code_5ACF0", func_8005D2FC);

INCLUDE_ASM(s32, "code_5ACF0", func_8005D30C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005D83C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005DAA4);

INCLUDE_ASM(s32, "code_5ACF0", func_8005DC94);

INCLUDE_ASM(s32, "code_5ACF0", func_8005DD14);

INCLUDE_ASM(s32, "code_5ACF0", func_8005DD54);

INCLUDE_ASM(s32, "code_5ACF0", func_8005DDDC);

INCLUDE_ASM(s32, "code_5ACF0", func_8005E0C0);

INCLUDE_ASM(s32, "code_5ACF0", func_8005E1A8);

INCLUDE_ASM(s32, "code_5ACF0", func_8005E1D8);

INCLUDE_ASM(s32, "code_5ACF0", func_8005E348);

INCLUDE_ASM(s32, "code_5ACF0", func_8005EEE4);

INCLUDE_ASM(s32, "code_5ACF0", func_8005F364);

INCLUDE_ASM(s32, "code_5ACF0", func_8005F524);

INCLUDE_ASM(s32, "code_5ACF0", func_8005F698);

INCLUDE_ASM(s32, "code_5ACF0", func_8005F744);

INCLUDE_ASM(s32, "code_5ACF0", func_8005F784);

INCLUDE_ASM(s32, "code_5ACF0", func_8005F7F4);

INCLUDE_ASM(s32, "code_5ACF0", func_8005F904);

INCLUDE_ASM(s32, "code_5ACF0", func_8005F918);

INCLUDE_ASM(s32, "code_5ACF0", func_8005FA90);

INCLUDE_ASM(s32, "code_5ACF0", func_8005FBA4);

INCLUDE_ASM(s32, "code_5ACF0", func_8005FBF8);

INCLUDE_ASM(s32, "code_5ACF0", func_8005FE54);

INCLUDE_ASM(s32, "code_5ACF0", func_8005FE90);

INCLUDE_ASM(s32, "code_5ACF0", func_8005FFA8);

INCLUDE_ASM(s32, "code_5ACF0", func_800600C0);

INCLUDE_ASM(s32, "code_5ACF0", func_8006010C);

INCLUDE_ASM(s32, "code_5ACF0", func_80060144);

INCLUDE_ASM(s32, "code_5ACF0", func_8006014C);

INCLUDE_ASM(s32, "code_5ACF0", func_80060174);

INCLUDE_ASM(s32, "code_5ACF0", func_800601BC);

INCLUDE_ASM(s32, "code_5ACF0", func_8006022C);

INCLUDE_ASM(s32, "code_5ACF0", func_80060290);

INCLUDE_ASM(s32, "code_5ACF0", func_8006034C);

INCLUDE_ASM(s32, "code_5ACF0", func_80060388);

INCLUDE_ASM(s32, "code_5ACF0", func_80060394);

INCLUDE_ASM(s32, "code_5ACF0", func_800604A8);

INCLUDE_ASM(s32, "code_5ACF0", func_800605A4);

INCLUDE_ASM(s32, "code_5ACF0", func_80060848);

INCLUDE_ASM(s32, "code_5ACF0", func_80060858);

INCLUDE_ASM(s32, "code_5ACF0", func_80060880);

INCLUDE_ASM(s32, "code_5ACF0", func_80060C14);

INCLUDE_ASM(s32, "code_5ACF0", func_80060DEC);

INCLUDE_ASM(s32, "code_5ACF0", func_80060EA8);

INCLUDE_ASM(s32, "code_5ACF0", func_8006105C);

INCLUDE_ASM(s32, "code_5ACF0", func_800610E0);

INCLUDE_ASM(s32, "code_5ACF0", func_80061100);

INCLUDE_ASM(s32, "code_5ACF0", func_80061188);

INCLUDE_ASM(s32, "code_5ACF0", func_80061388);

INCLUDE_ASM(s32, "code_5ACF0", func_800615B8);

INCLUDE_ASM(s32, "code_5ACF0", func_80061934);

INCLUDE_ASM(s32, "code_5ACF0", func_80061A5C);
