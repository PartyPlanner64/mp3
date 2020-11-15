#include "common.h"
#include "../../board.h"

extern s16 D_800A1764;
extern void func_80107BF4_31D764();
extern void func_80107C2C_31D79C();
extern void func_80108014_31DB84();
extern void func_80108098_31DC08();
extern void func_8011C58C_3320FC();

struct board_overlay_entrypoint chillywaters_entrypoints[] = {
    { 0, func_80107BF4_31D764 },
    { 1, func_80107C2C_31D79C },
    { 2, func_80108014_31DB84 },
    { 3, func_80108098_31DC08 },
    { 4, func_8011C58C_3320FC },
    { -1, NULL }
};

void func_801059A0_31B510() {
    func_800359E0(chillywaters_entrypoints, D_800A1764);
}
