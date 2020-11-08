#include "common.h"
#include "../process.h"

/* Message Check */

extern u16 D_800A1760;
extern s16 D_800A1786;
extern u8 D_800CD280;
extern f32 D_800CE1C8;
extern f32 D_800D138C;
extern f32 D_800D6AC0;

extern u16 D_80106500;

extern void func_80019568(s32, f32, f32, f32);
extern void func_8004819C(s32);
extern void func_8004B340();
extern s32 func_800620BC();

extern void func_80105B50_4F6BA0();
extern s32 func_80106334_4F7384();
extern s32 func_801063BC_4F740C();
extern s32 func_80105B8C_4F6BDC();

void func_801059A0_4F69F0() {
    s32 temp_v0;

    func_80012220(1);
    func_8001FE20(1);
    func_800142A0(0x19);
    func_80047160(0x33, 0xA);
    func_8005A6B0();
    temp_v0 = func_80047620(0x7FDA, 0, 0, -1, func_8004B340);
    D_800D6AC0 = 100.0f;
    D_800CE1C8 = 600.0f;
    D_800D138C = -30.0f;
    func_80047B38(temp_v0, 0xA0);
    if (D_800A1760 != 0) {
        D_800A1760 = 0;
        func_8004DEC8(D_800A1786);
        D_800A1786 = -1;
    }
    func_80047620(0x2710, 0, 0, -1, func_80106334_4F7384);
    func_80019490(3);
    func_80019514(0, 0x78, 0x78, 0x78);
    func_80019514(1, 0x40, 0x40, 0x60);
    func_80019568(1, -100.0f, 100.0f, 100.0f);
    func_80019514(2, 0, 0, 0);
    func_80019514(3, 0, 0, 0);
    func_80047EA0(func_80105B50_4F6BA0, 0x3F00, 0x800, 0);
    func_80047EA0(func_801063BC_4F740C, 0x3F00, 0x800, 0);
    func_80061FE8(0, 0);
    D_800CD280 = 1;
    func_8001F38C(0xFF, 0xFF, 0xFF);
}

void func_80105B50_4F6BA0() {
    func_80105B8C_4F6BDC();
    D_80106500 = 1;
    func_8005F524();
    while (1) {
        SleepVProcess();
    }
}

INCLUDE_ASM(s32, "overlays/overlay118_4F69F0", func_80105B8C_4F6BDC);

INCLUDE_ASM(s32, "overlays/overlay118_4F69F0", func_80106334_4F7384);

void func_80106390_4F73E0(void) {
    if (func_800620BC() == 0) {
        func_8004819C(1);
    }
}

INCLUDE_ASM(s32, "overlays/overlay118_4F69F0", func_801063BC_4F740C);
