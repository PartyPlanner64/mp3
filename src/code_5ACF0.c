#include "common.h"

// strings-related.

extern s8 D_800A2150;
extern s8 D_800A2151;

extern s32 D_800A25D0[];

extern s8 D_800BDA6A;
extern s16 D_800BDA6C;
extern s8 D_800BDA6D; // ? overlaps
extern s16 D_800BDA6E;

extern s32 D_800CB99C;

struct str800CC69C {
    s8 unks03C[0x3C];
    u16 unk3C;
    u16 unk3E;
    s32 unk40;
    s32 unk44;
    u16 unk48;
    u16 unk4A;
    s16 unk4C;
    s16 unk4E;
    s32 unk50;
    s16 unk54;
    s16 unk56;
    s32 unk58;
    s16 unk5C;
    s16 unk5E;
    s16 unk60;
    s16 unk62;
    s16 unk64;
    s16 unk66;
    s32 unk68;
    s16 unk6C;
    s16 unk6E;
    s8 unks70274[516];
    s16 unk274;
    s16 unk276;
    s32 unk278;
}; // sizeof 0x27C

extern struct str800CC69C *D_800CC69C;

extern s8 D_800CD2A4;
extern s8 D_800D1F34;
extern void *D_800D1FE4;
extern s8 D_800D5206[];
extern s32 D_800D5540;
extern s8 D_800D6A26;
extern u16 D_800D6B62;

extern void func_80054904(s16, s16, s16, s16);
extern void func_800551D8(s32, s32, f32, f32);
extern void func_8005BB18(s16, f32, f32);

extern f32 func_8008EF20(f32);

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

//         temp_v0_5 = InitProcess(&D_8005DDDC, 0x1001, 0x800, 0);
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


INCLUDE_ASM(s16, "code_5ACF0", func_8005A968, s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B040);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B238);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B43C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B5EC);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B614);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B63C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B68C);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B6BC);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B7B8, s16 winId, s32 arg1, s16 arg2, s16 arg3, s16 arg4);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B8F8);

INCLUDE_ASM(s32, "code_5ACF0", func_8005B974);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BA28);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BA54);

INCLUDE_ASM(void, "code_5ACF0", func_8005BA90, s16 winId, s16 arg1, s16 arg2);

INCLUDE_ASM(void, "code_5ACF0", func_8005BB18, s16 arg0, f32 arg1, f32 arg2);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BBC0);

INCLUDE_ASM(void, "code_5ACF0", func_8005BCA4, s16 winId, s16 arg1, s16 arg2);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BDA8);

INCLUDE_ASM(void, "code_5ACF0", func_8005BDFC, s16 winId, s32 arg0);

INCLUDE_ASM(s32, "code_5ACF0", func_8005BE30);

INCLUDE_ASM(void, "code_5ACF0", func_8005BEE0, s16 winId, s32 arg2);

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

INCLUDE_ASM(void, "code_5ACF0", func_8005D294, s16 winId);

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

INCLUDE_ASM(void, "code_5ACF0", func_8005FE90, s16 arg0);

INCLUDE_ASM(s32, "code_5ACF0", func_8005FFA8);

INCLUDE_ASM(s32, "code_5ACF0", func_800600C0);

INCLUDE_ASM(s32, "code_5ACF0", func_8006010C);

INCLUDE_ASM(s32, "code_5ACF0", func_80060144);

INCLUDE_ASM(s32, "code_5ACF0", func_8006014C);

INCLUDE_ASM(s32, "code_5ACF0", func_80060174);

INCLUDE_ASM(s32, "code_5ACF0", func_800601BC);

// Called to indicate that `str` should be the replacement at a
// "replacement index" location in the main string.
void func_8006022C(char *str, s16 index) {
    D_800BDA6A = 1;
    D_800BDA6E = 0;
    D_800BDA6C = 0;
    func_800605A4(str);
    D_800CD2A4 = 0;
    D_800D5206[index] = D_800BDA6D;
}

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

// Obtains a window handle
INCLUDE_ASM(s32, "code_5ACF0", func_80061188);
// s16 func_80061188(s16 arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4, s16 arg5) {
//     s32 temp_s0;
//     s16 temp_s4;
//     s16 winId;
//     s16 temp_v1;
//     s32 temp_s0_2;
//     s32 temp_s1;
//     struct str800CC69C *temp_s2;
//     s32 phi_s3;

//     temp_s0 = arg3 + 2;
//     phi_s3 = arg4;
//     if (((~arg0 != 0) & (arg4 < 0x30)) != 0) {
//         phi_s3 = 0x30;
//     }
//     winId = func_8005A968(arg1, arg2, temp_s0, phi_s3, 0, arg5);
//     func_8005BDFC(winId, 0);
//     temp_s2 = &D_800CC69C[winId];
//     func_8005BCA4(winId, temp_s0 / 2, phi_s3 / 2);
//     func_8005BA90(winId, temp_s2->unk3C + (temp_s0 / 2), temp_s2->unk3E + (phi_s3 / 2));
//     temp_s2->unk276 = arg0;
//     if (arg0 != -1) {
//         temp_s2->unk274 = func_8005B7B8(winId, D_800A25D0[arg0], 0x18 - temp_s2->unk48, 0x18 - temp_s2->unk4A, 0);
//     }
//     temp_s2->unk54 = 6;
//     temp_s2->unk4C = 6;
//     func_8005BEE0(winId, 0xD0);
//     func_8005C060(winId, 1, 0x40, 0xF0, 0xFF);
//     func_8005FBF8(winId, 0x40, 0x20, 0xB0);
//     func_8005D294(winId);
//     func_8005FE90(winId);
//     func_8005F904();
//     return winId;
// }

INCLUDE_ASM(s32, "code_5ACF0", func_80061388);

INCLUDE_ASM(s32, "code_5ACF0", func_800615B8);

void func_80061934(s16 winId, s16 arg1) {
    s16 temp_v0;
    struct str800CC69C *temp_s0;

    temp_s0 = &D_800CC69C[winId];
    func_800600C0(winId, 1);
    func_800615B8(winId, 0);
    func_8005B8F8(winId, temp_s0->unk274);
    temp_v0 = func_8005B7B8(winId, D_800A25D0[arg1], 0x18 - temp_s0->unk48, 0x18 - temp_s0->unk4A, 0);
    temp_s0->unk274 = temp_v0;
    func_80054904(temp_s0->unk6C, temp_v0, 0x18 - temp_s0->unk48, 0x18 - temp_s0->unk4A);
    func_800551D8(temp_s0->unk6C, temp_s0->unk274, 1.0f, 1.0f);
    func_800615B8(winId, 1);
    func_800600C0(winId, 0);
}

void func_80061A5C(s16 arg0, s16 arg1) {
    s16 i;

    if (arg1 == 0) {
        func_8005D294(arg0);

        for (i = 0; i < 5; i++) {
            func_8005BB18(arg0, 1.0f, 1.0f - func_8008EF20(i * 18.0f));
            SleepVProcess();
        }

        func_8005FE90(arg0);
        SleepVProcess();
        return;
    }
    func_8005FE90(arg0);
}
