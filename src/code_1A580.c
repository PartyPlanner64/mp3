#include "common.h"

// struct strCB8C0 {
//     s16 unk0;
//     s16 unk2;
//     s16 unk4;
//     s16 unk6;
//     s16 unk8;
//     s16 unkA;
//     s16 unkC;
//     s16 unkE;
// };

// extern struct strCB8C0 *D_800CB8C0;
extern s16 D_800CB8CE[];

extern s16 D_800CDD6A;

struct strD03F8 {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    u8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s8 unks10to40[0x30];

    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;

    s8 unks58toC0[0x68];
}; // sizeof == 0xC0
extern struct strD03F8 *D_800D03F8;

extern void (*D_800D135C)(u8 *);
extern s16 D_800D5204;

INCLUDE_ASM(s32, "code_1A580", func_80019980);

INCLUDE_ASM(s32, "code_1A580", func_800199F8);

INCLUDE_ASM(s32, "code_1A580", func_80019A14);

INCLUDE_ASM(s32, "code_1A580", func_80019A98);

INCLUDE_ASM(s32, "code_1A580", func_80019AF0);

INCLUDE_ASM(s32, "code_1A580", func_80019B34);

INCLUDE_ASM(s32, "code_1A580", func_80019C00);

INCLUDE_ASM(s32, "code_1A580", func_80019C68);

INCLUDE_ASM(s32, "code_1A580", func_80019CDC);

INCLUDE_ASM(s32, "code_1A580", func_80019CEC);

INCLUDE_ASM(s32, "code_1A580", func_80019D64);

INCLUDE_ASM(s32, "code_1A580", func_80019DB0);

INCLUDE_ASM(s32, "code_1A580", func_80019E04);

INCLUDE_ASM(s32, "code_1A580", func_80019E40);

INCLUDE_ASM(s32, "code_1A580", func_80019E84);

INCLUDE_ASM(s32, "code_1A580", func_8001A070);

// Loads a model
INCLUDE_ASM(s16, "code_1A580", func_8001A150);

INCLUDE_ASM(s32, "code_1A580", func_8001A61C);

INCLUDE_ASM(s32, "code_1A580", func_8001A894);

INCLUDE_ASM(s32, "code_1A580", func_8001ABD4);

INCLUDE_ASM(s32, "code_1A580", func_8001AC34);

INCLUDE_ASM(s32, "code_1A580", func_8001AC8C);

INCLUDE_ASM(s32, "code_1A580", func_8001ACDC);

INCLUDE_ASM(s32, "code_1A580", func_8001AFE4);

INCLUDE_ASM(s32, "code_1A580", func_8001B0B4);

INCLUDE_ASM(s32, "code_1A580", func_8001BD24);

INCLUDE_ASM(s32, "code_1A580", func_8001BF14);

INCLUDE_ASM(s32, "code_1A580", func_8001BF90);

INCLUDE_ASM(s32, "code_1A580", func_8001C0C4);

INCLUDE_ASM(s32, "code_1A580", func_8001C114);

INCLUDE_ASM(s32, "code_1A580", func_8001C150);

INCLUDE_ASM(s32, "code_1A580", func_8001C1A0);

INCLUDE_ASM(s32, "code_1A580", func_8001C1F0);

INCLUDE_ASM(s32, "code_1A580", func_8001C258);

INCLUDE_ASM(s32, "code_1A580", func_8001C2FC);

INCLUDE_ASM(s32, "code_1A580", func_8001C39C);

INCLUDE_ASM(s32, "code_1A580", func_8001C448);

INCLUDE_ASM(s32, "code_1A580", func_8001C514);

INCLUDE_ASM(s32, "code_1A580", func_8001C5B4);

void func_8001C624(s16 arg0, u8 arg1, s16 arg2, s16 arg3, u16 arg4) {
    struct strD03F8 *temp_a0;

    temp_a0 = D_800D03F8 + arg0;
    if (temp_a0->unk4 != 0xFF) {
        temp_a0->unk2 = temp_a0->unk4;
        temp_a0->unk40 = temp_a0->unk4C;
        temp_a0->unk3 = temp_a0->unk5;
        temp_a0->unk48 = temp_a0->unk54;
    }
    temp_a0->unk4 = (u8)arg1;
    temp_a0->unk4C = arg2;
    temp_a0->unkE = (u16)0;
    temp_a0->unkC = arg3;
    temp_a0->unk5 = (u8)arg4;
    temp_a0->unk54 = 0.0f;
}

INCLUDE_ASM(s32, "code_1A580", func_8001C6A8);

INCLUDE_ASM(s32, "code_1A580", func_8001C718);

INCLUDE_ASM(s32, "code_1A580", func_8001C760);

INCLUDE_ASM(s32, "code_1A580", func_8001C7D0);

INCLUDE_ASM(s32, "code_1A580", func_8001C814);

INCLUDE_ASM(s32, "code_1A580", func_8001C8A8);

INCLUDE_ASM(s32, "code_1A580", func_8001C8E4);

INCLUDE_ASM(s32, "code_1A580", func_8001C92C);

INCLUDE_ASM(s32, "code_1A580", func_8001C954);

INCLUDE_ASM(s32, "code_1A580", func_8001CAA4);

INCLUDE_ASM(s32, "code_1A580", func_8001CD34);

INCLUDE_ASM(s32, "code_1A580", func_8001CE28);

INCLUDE_ASM(s32, "code_1A580", func_8001CF1C);

INCLUDE_ASM(s32, "code_1A580", func_8001D330);

INCLUDE_ASM(s32, "code_1A580", func_8001D33C);

INCLUDE_ASM(s32, "code_1A580", func_8001D558);

INCLUDE_ASM(s32, "code_1A580", func_8001D638);

INCLUDE_ASM(s32, "code_1A580", func_8001D874);

INCLUDE_ASM(s32, "code_1A580", func_8001DACC);

INCLUDE_ASM(s32, "code_1A580", func_8001DDB8);

INCLUDE_ASM(s32, "code_1A580", func_8001E500);

INCLUDE_ASM(s32, "code_1A580", func_8001E65C);

INCLUDE_ASM(s32, "code_1A580", func_8001E888);

INCLUDE_ASM(s32, "code_1A580", func_8001EBC0);

INCLUDE_ASM(s32, "code_1A580", func_8001ED54);

INCLUDE_ASM(s32, "code_1A580", func_8001EED8);

INCLUDE_ASM(s32, "code_1A580", func_8001EF24);

INCLUDE_ASM(s32, "code_1A580", func_8001EF60);

INCLUDE_ASM(s32, "code_1A580", func_8001EF6C);

INCLUDE_ASM(s32, "code_1A580", func_8001EFEC);

INCLUDE_ASM(s32, "code_1A580", func_8001F038);

INCLUDE_ASM(s32, "code_1A580", func_8001F154);

INCLUDE_ASM(s32, "code_1A580", func_8001F1FC);
// s16 func_8001F1FC(u8 *mtnx, s16 arg1) {
//     s16 temp_s0;

//     if (mtnx[0] != 0x4D || mtnx[1] != 0x54 || mtnx[2] != 0x4E || mtnx[3] != 0x58) {
//         D_800D5204 = 0x2810;
//         D_800CDD6A = 0x2811;
//         D_800CB8CE[0] = 0x2810;
//         func_8000F0A0(&D_800CB8CE[0] - 15, mtnx, arg1);
//         temp_s0 = func_8002D2D8(mtnx, &D_800CB8CE[0] - 15);
//         func_80019B34(D_800D5204);
//         func_80019B34(D_800CDD6A);
//     }
//     else {
//         temp_s0 = func_8002D3AC(mtnx);
//     }

//     if ((arg1 & 8) != 0) {
//         D_800D135C(mtnx);
//     }
//     return temp_s0;
// }

void func_8001F304(s16 arg0, s8 arg1) {
    struct strD03F8 *temp_v0;
    f32 zero;

    temp_v0 = D_800D03F8 + arg0;
    temp_v0->unk2 = arg1;
    temp_v0->unk3 = 0;
    zero = 0.0f;
    temp_v0->unk40 = zero;
    temp_v0->unk48 = zero;
    temp_v0->unk44 = 1.0f;
    temp_v0->unk4 = 0xFF;
}

INCLUDE_ASM(s32, "code_1A580", func_8001F358);

INCLUDE_ASM(s32, "code_1A580", func_8001F38C);

INCLUDE_ASM(s32, "code_1A580", func_8001F3A8);

INCLUDE_ASM(s32, "code_1A580", func_8001F450);

INCLUDE_ASM(s32, "code_1A580", func_8001F4BC);

INCLUDE_ASM(s32, "code_1A580", func_8001F668);

INCLUDE_ASM(s32, "code_1A580", func_8001F6B0);

INCLUDE_ASM(s32, "code_1A580", func_8001F6BC);

INCLUDE_ASM(s32, "code_1A580", func_8001F6F8);

INCLUDE_ASM(s32, "code_1A580", func_8001F734);

INCLUDE_ASM(s32, "code_1A580", func_8001F95C);

INCLUDE_ASM(s32, "code_1A580", func_8001F974);

INCLUDE_ASM(s32, "code_1A580", func_8001F9E4);

INCLUDE_ASM(s32, "code_1A580", func_8001FA68);

INCLUDE_ASM(s32, "code_1A580", func_8001FB34);

INCLUDE_ASM(s32, "code_1A580", func_8001FBBC);

INCLUDE_ASM(s32, "code_1A580", func_8001FBFC);

INCLUDE_ASM(s32, "code_1A580", func_8001FD08);

INCLUDE_ASM(s32, "code_1A580", func_8001FDE8);
