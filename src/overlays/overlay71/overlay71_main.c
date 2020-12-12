#include "common.h"
#include "../../board.h"
#include "../../code_365E0.h"

extern s16 D_800A1764;
extern void func_801059D0_31B3E0();
extern void func_80105A44_31B454();
extern void func_80105A98_31B4A8();

struct overlay_entrypoint overlay71_entrypoints[] = {
    { 0, func_801059D0_31B3E0 },
    { 1, func_80105A44_31B454 },
    { 2, func_80105A98_31B4A8 },
    { -1, NULL }
};

void func_801059A0_31B3B0() {
    func_800359E0(overlay71_entrypoints, D_800A1764);
}
