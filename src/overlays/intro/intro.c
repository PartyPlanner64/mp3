#include "common.h"

extern s32 D_80105F00_22E660;

INCLUDE_ASM(void, "overlays/intro/intro", D_801059D0_3D7180);

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

INCLUDE_ASM(s32, "overlays/intro/intro", D_80105AF0_3D72A0);

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

INCLUDE_ASM(s32, "overlays/intro/intro", D_80105C14_3D73C4);

INCLUDE_ASM(s32, "overlays/intro/intro", D_80105C80_3D7430);
