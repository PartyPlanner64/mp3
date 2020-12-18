#include "common.h"
#include "../../object.h"
#include "../../player.h"
#include "../../spaces.h"

struct unkArrows {
    u8 unks[0x68];
    struct player *player; // 0x68
};

struct unkfunc_800D7568_EB188 {
    s32 unk0;
    struct object *unk4;
};

extern void func_80089AF0(struct coords_3d *, f32, struct coords_3d *);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6B70_EA790);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6C3C_EA85C);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6C6C_EA88C);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6CA0_EA8C0);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6D2C_EA94C);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6E00_EAA20);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6EC8_EAAE8);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6EE0_EAB00);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D7250_EAE70);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D7280_EAEA0);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D742C_EB04C);

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D7518_EB138);

void func_800D7568_EB188(struct unkfunc_800D7568_EB188 *arg0, struct coords_3d *arg1, struct coords_3d *arg2, f32 arg3) {
    struct coords_3d coords;
    func_800ECB58_100778(arg1, arg2, &coords);
    func_80089A20(&arg0->unk4->unk18, &coords);
    func_80089AF0(&coords, arg3, &coords);
    func_80089A70(&arg0->unk4->coords, &coords, arg1);
}

// shows arrows pointing from player to each space in list.
// space list end is signaled by -1.
struct unkArrows *func_800D75E8_EB208(s16 playerIndex, s16 *spaceIndices, s32 arg2) {
    void *temp_s0;
    struct unkArrows *unkStruct;
    struct player *player;

    player = GetPlayerStruct(playerIndex);
    unkStruct = func_800D6C6C_EA88C();
    unkStruct->player = player;
    while (*spaceIndices >= 0) {
        temp_s0 = func_800D6B70_EA790(arg2);
        func_800D7568_EB188(temp_s0, &player->obj->coords, &(GetSpaceData(*spaceIndices)->coords), 18.0f);
        func_800D6D2C_EA94C(unkStruct, temp_s0, 0);
        spaceIndices++;
    }
    return unkStruct;
}

void func_800D76A0_EB2C0(s16 playerIndex, void *arg1, s32 arg2) {
    func_800D75E8_EB208(playerIndex, arg1, 0);
}
