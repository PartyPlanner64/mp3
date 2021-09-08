#include "common.h"
#include "../../365E0.h"

extern s16 D_800A1764;

extern void func_80105AAC_3D725C();
extern void func_80105ACC_3D727C();

struct overlay_entrypoint intro_entrypoints[] = {
    { 0, func_80105AAC_3D725C },
    { 1, func_80105ACC_3D727C },
    { -1, NULL }
};

//INCLUDE_ASM(s32, "overlays/intro/intro1", func_801059A0_3D7150);
void func_801059A0_3D7150() {
    func_800359E0(intro_entrypoints, D_800A1764);
}
