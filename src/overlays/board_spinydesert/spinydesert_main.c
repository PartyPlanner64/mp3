#include "common.h"

#include "common.h"
#include "../../board.h"
#include "../../code_365E0.h"

extern s16 D_800A1764;
extern void func_80107934_3507A4();
extern void func_80107970_3507E0();
extern void func_80107CA4_350B14();
extern void func_80107D28_350B98();
extern void func_8011B41C_36428C();

struct overlay_entrypoint spinydesert_entrypoints[] = {
    { 0, func_80107934_3507A4 },
    { 1, func_80107970_3507E0 },
    { 2, func_80107CA4_350B14 },
    { 3, func_80107D28_350B98 },
    { 4, func_8011B41C_36428C },
    { -1, NULL }
};

void func_801059A0_34E810() {
    func_800359E0(spinydesert_entrypoints, D_800A1764);
}
