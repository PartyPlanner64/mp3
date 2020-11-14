#include "common.h"

struct struct_func_800EC70C_10032C
{
    s16 unk0;
    s16 unk2;
};

extern u8 D_800CB99C;

struct struct_D_800CC69C
{
    u8 unk0[32];
    u8 unk32;
    u8 unk21[604];
};

extern struct struct_D_800CC69C *D_800CC69C;
extern s8 D_800CD067;

extern s16 D_80101480;
extern s16 D_80101482;
extern s16 D_80105702; // window id
extern s16 D_80105714;

extern s32 func_8005B6BC(s32, char *, s32);
extern void func_800EDC74_101894(s16);
extern void func_800EE2C0_101EE0(s16);

void func_800EBEF0_FFB10(s16 arg0) {
    if (D_800CD067 == 4 || D_80101482 != 0) {
        func_800EE2A4_101EC4(arg0);
        return;
    }

    func_800EDC58_101878(arg0, D_800CD067);
}

void func_800EBF48_FFB68(s16 arg0, s8 player_index) {
    if (D_800CD067 == 4 || D_80101482 != 0) {
        func_800EE2C0_101EE0(arg0);
        return;
    }

    func_800EDC74_101894(arg0);
}

void func_800EBF98_FFBB8(s16 arg0) {
    if (D_800CD067 == 4 || D_80101482 != 0) {
        func_800EE2A4_101EC4(arg0);
        return;
    }

    func_800EDC58_101878(arg0);
}

INCLUDE_ASM(s16, "overlays/overlay128_FFB10", func_800EBFE8_FFC08);

void func_800EC134_FFD54(s32 arg0) {
    s16 temp_a0;
    s16 temp_s0;
    struct struct_func_800EC70C_10032C some_struct;

    func_80060394(1, &some_struct, arg0);
    temp_a0 = func_80061188(-1, 0, 0, some_struct.unk0, some_struct.unk2, 2);
    temp_s0 = temp_a0;
    D_80105714 = temp_s0;
    if (D_800CB99C == 0) {
        func_8005B63C(temp_a0, 0x40, 0x40);
    }
    temp_s0 = temp_s0;
    func_8005B43C(temp_s0, arg0, -1, -1);
    func_80061388(temp_s0);
}

INCLUDE_ASM(s32, "overlays/overlay128_FFB10", func_800EC1E8_FFE08);

INCLUDE_ASM(s32, "overlays/overlay128_FFB10", func_800EC39C_FFFBC);

INCLUDE_ASM(s32, "overlays/overlay128_FFB10", func_800EC3C0_FFFE0);

INCLUDE_ASM(s32, "overlays/overlay128_FFB10", func_800EC3E4_100004);

INCLUDE_ASM(s32, "overlays/overlay128_FFB10", func_800EC414_100034);

INCLUDE_ASM(s32, "overlays/overlay128_FFB10", func_800EC4E4_100104);

INCLUDE_ASM(s32, "overlays/overlay128_FFB10", func_800EC590_1001B0);

INCLUDE_ASM(s32, "overlays/overlay128_FFB10", func_800EC5B4_1001D4);

INCLUDE_ASM(s32, "overlays/overlay128_FFB10", func_800EC5EC_10020C);

void func_800EC628_100248(s16 arg0, char *arg1) {
    s16 temp_s0;
    struct struct_func_800EC70C_10032C some_struct;

    func_80060394(1, &some_struct, arg1);
    temp_s0 = func_800EBFE8_FFC08(arg0, &some_struct, -1);
    D_80105702 = temp_s0;
    func_8005B43C(temp_s0, arg1, -1, -1);
    func_80061388(temp_s0);
}

void func_800EC6A8_1002C8() {
    func_80061388(D_80105702);
}

void func_800EC6C8_1002E8() {
    func_80061A5C(D_80105702, 0);
}

void func_800EC6EC_10030C() {
    func_8005F364(D_80105702);
}

// Show message
void func_800EC70C_10032C(s16 arg0, char *arg1, char *arg2, char *arg3, char *arg4, char *arg5, char *arg6, s16 arg7) {
    s16 temp_a1;
    s16 temp_s0;
    s16 temp_s1;
    struct struct_func_800EC70C_10032C some_struct;

    if (arg2 != NULL) {
        func_8006022C(arg2, 0);
    }
    if (arg3 != NULL) {
        func_8006022C(arg3, 1);
    }
    if (arg4 != NULL) {
        func_8006022C(arg4, 2);
    }
    if (arg5 != NULL) {
        func_8006022C(arg5, 3);
    }
    if (arg6 != NULL) {
        func_8006022C(arg6, 4);
    }

    func_80060394(1, &some_struct, arg1);
    temp_s0 = func_800EBFE8_FFC08(arg0, &some_struct, (s16) arg7);
    D_80105702 = temp_s0;

    if (arg2 != NULL) {
        func_8005B6BC(temp_s0, arg2, 0);
    }
    if (arg3 != NULL) {
        func_8005B6BC(temp_s0, arg3, 1);
    }
    if (arg4 != NULL) {
        func_8005B6BC(temp_s0, arg4, 2);
    }
    if (arg5 != NULL) {
        func_8005B6BC(temp_s0, arg5, 3);
    }
    if (arg6 != NULL) {
        func_8005B6BC(temp_s0, arg6, 4);
    }

    temp_a1 = D_80101480;

    if (temp_a1 != 0) {
        func_8005E1A8(temp_s0, temp_a1);
    }

    temp_s1 = temp_s0;
    func_8005B43C(temp_s1, arg1, -1, -1);

    if (arg0 == -1) {
        func_80061388(temp_s1);
    }
    else {
        func_80061388(temp_s0);
    }

    func_800EBF48_FFB68(temp_s0, D_800CD067);
}

void func_800EC8EC_10050C(s16 arg0, char *arg1, char *arg2, char *arg3, char *arg4, char *arg5, char *arg6) {
    func_800EC70C_10032C(arg0, arg1, arg2, arg3, arg4, arg5, arg6, -1);
}

void func_800EC92C_10054C(s16 arg0, char *arg1, char *arg2, char *arg3, char *arg4, char *arg5, char *arg6) {
    D_80101482 = 1;
    func_800EC70C_10032C(arg0, arg1, arg2, arg3, arg4, arg5, arg6, -1);
    D_80101482 = 0;
}

void func_800EC980_1005A0(s16 arg0, char *arg1, char *arg2, char *arg3, char *arg4, char *arg5, char *arg6, s16 arg7) {
    D_80101482 = 1;
    func_800EC70C_10032C(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    D_80101482 = 0;
}

INCLUDE_ASM(s32, "overlays/overlay128_FFB10", func_800EC9DC_1005FC);
// void func_800EC9DC_1005FC() {
//     D_800CC69C[D_80105702].unk32 = 1;
//     SleepVProcess();
//     func_800EBF48_FFB68(D_80105702, D_800CD067);
// }

INCLUDE_ASM(s32, "overlays/overlay128_FFB10", func_800ECA38_100658);
// void func_800ECA38_100658() {
//     D_80101482 = 1;
//     D_800CC69C[D_80105702].unk32 = 1;
//     SleepVProcess();
//     func_800EBF48_FFB68(D_80105702, D_800CD067);
//     D_80101482 = 0;
// }

void func_800ECAA8_1006C8(s16 arg0) {
    D_80101480 = arg0;
}

void func_800ECAB4_1006D4() {
    D_80101480 = 0;
    D_80101482 = 0;
}
