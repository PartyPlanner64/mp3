#include "common.h"

extern s16 func_8000B838(s32);
extern s32 func_8000BFEC(s16, s32, s32);
extern void func_8000BBD4(u16, s32, s32);
extern void func_8000BB54(u16);
extern void func_8000BCC8(u16, s32);
extern void func_8000C184(u16);

extern u16 D_800D530C;
extern u16 D_800D5558;
extern u8 D_800D6A58;

s32 D_80105F00_22E660;
s32 D_80105F04_2A1994;
extern struct process *D_80105F10; // bss

extern void D_80105BA4_3D7354();
extern void D_80105C80_3D7430();
extern void D_80105AF0_3D72A0();
extern void D_80105C14_3D73C4();

void D_801059D0_3D7180() {
    func_80012220(1);
    InitObjSys(0x10, 4);
    D_800D6A58 = 1;
    if (D_80105F00_22E660 == 0) {
        func_80036080();
        D_80105F10 = InitProcess(&D_80105C80_3D7430, 0xA, 0, 0);
        func_80047620(0x3E8, 0, 0, -1, D_80105AF0_3D72A0);
    }
    else {
        D_80105F10 = InitProcess(&D_80105C80_3D7430, 0xA, 0, 0);
        func_80047620(0x3E8, 0, 0, -1, D_80105AF0_3D72A0);
        func_80047620(0xA, 0, 0, -1, D_80105C14_3D73C4);
    }
}

// entrypoint 0
void func_80105AAC_3D725C() {
    D_80105F00_22E660 = 0;
    D_801059D0_3D7180();
}

// entrypoint 1
void func_80105ACC_3D727C() {
    D_80105F00_22E660 = 1;
    D_801059D0();
}

struct unk80105AF0 {
    s8 unks[0x14];
    void *unk14;
};

void D_80105AF0_3D72A0(struct unk80105AF0 *arg0) {
    if (D_800D530C != 0 || D_80105F04_2A1994 != 0) {
        if (func_800620BC() == 0) {
            func_800620C8(0, 0, 0);
            func_80062050(0xB, 9);
            arg0->unk14 = D_80105BA4_3D7354;
            if (D_800D530C != 0) {
                if (func_800620BC() == 0) {
                    func_800620C8(0, 0, 0);
                    func_80062050(0xB, 9);
                    arg0->unk14 = D_80105BA4_3D7354;
                }
            }
        }
    }
}

void D_80105BA4_3D7354() {
    if (func_800620BC() == 0) {
        func_8005F524();
        if (D_80105F00_22E660 != 0) {
            func_80048228(0x7A, 2, 0x92);
            return;
        }
        func_80048128(0x7A, 2, 0x92);
        func_80048460(1, 0x7A, 2, 0x92);
    }
}

void D_80105C14_3D73C4() {
    s32 temp_s0;
    s32 temp_v0;

    if (func_800620BC() == 0) {
        temp_s0 = func_800360B8();
        if (temp_s0 == 1) {
            if (func_8000985C(0) != 0) {
                temp_v0 = D_800D5558 & 0x1000;
                if (temp_v0 != 0) {
                    D_80105F04_2A1994 = temp_s0;
                }
            }
        }
    }
}

void D_80105C80_3D7430() {
    s16 temp_s2;
    s32 temp_s1;

    temp_s2 = func_8000B838(0x00110000);
    temp_s1 = func_8000BFEC(temp_s2, 0, 1);
    func_8000BBD4(temp_s1, 320 / 2, 240 / 2);
    func_8000BB54(temp_s1);
    func_8000BCC8(temp_s1, 0xFFFF);
    func_80061FE8(0xB, 0x1E);

    while (func_800620BC() != 0) {
        SleepVProcess();
    }
    SleepProcess(0x25);

    func_80062050(0xB, 9);

    while (func_800620BC() != 0) {
        SleepVProcess();
    }

    func_8000C184(temp_s1);
    func_80055670(temp_s2);
    SleepProcess(9);

    temp_s2 = func_8000B838(0x00110001);
    temp_s1 = func_8000BFEC(temp_s2, 0, 1);
    func_8000BBD4(temp_s1, 320 / 2, 240 / 2);
    func_8000BB54(temp_s1);
    func_8000BCC8(temp_s1, 0xFFFF);
    func_80061FE8(0xB, 9);

    while (func_800620BC() != 0) {
        SleepVProcess();
    }
    SleepProcess(0x25);

    func_80062050(0xB, 9);

    while (func_800620BC() != 0) {
        SleepVProcess();
    }

    func_8000C184(temp_s1);
    func_80055670(temp_s2);
    SleepProcess(9);

    temp_s2 = func_8000B838(0x00110002);
    temp_s1 = func_8000BFEC(temp_s2, 0, 1);
    func_8000BBD4(temp_s1, 320 / 2, 240 / 2);
    func_8000BB54(temp_s1);
    func_8000BCC8(temp_s1, 0xFFFF);
    func_80061FE8(0xB, 9);

    while (func_800620BC() != 0) {
        SleepVProcess();
    }
    SleepProcess(0x25);
    D_800D530C = 1;

    while (1) {
        SleepVProcess();
    }
}
