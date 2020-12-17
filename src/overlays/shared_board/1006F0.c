#include "common.h"
#include "../../player.h"
#include "../../object.h"
#include "../../spaces.h"

extern s8 D_800CD066;

extern s16 func_800F8858_10C478();

void func_800ECAD0_1006F0(s16 arg0, s16 spaceIndex, struct coords_3d *coords) {
    struct space_data *space;

    space = GetSpaceData(spaceIndex);
    coords->x = space->coords.x;
    coords->y = space->coords.y;
    coords->z = space->coords.z;
}

void func_800ECB14_100734(s16 arg0, s16 arg1) {
    func_800ECAD0_1006F0(arg0, arg1, &(gPlayers[arg0].obj->coords));
}

void func_800ECB58_100778(void *arg0, s32 arg1, void *arg2) {
    func_80089AB0(arg2, arg1, arg0);
    func_800D88E8_EC508(arg2);
}

void func_800ECB90_1007B0(s16 playerIndex, s32 arg1) {
    struct object *obj;

    obj = GetPlayerStruct(playerIndex)->obj;
    func_800ECB58_100778(&obj->coords, arg1, &obj->unk18);
}

void func_800ECBD0_1007F0(struct object *obj, s16 spaceIndex) {
    func_800ECB58_100778(&obj->coords, &GetSpaceData(spaceIndex)->coords, &obj->unk18);
}

void func_800ECC0C_10082C(struct coords_3d *coords) {
    coords->x = 0;
    coords->y = 0;
    coords->z = 1.0f;
}

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECC28_100848);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECC54_100874);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECD00_100920);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECDD4_1009F4);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECE4C_100A6C);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECE9C_100ABC);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECEE4_100B04);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECF18_100B38);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECF9C_100BBC);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECFC8_100BE8);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED128_100D48);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED1E4_100E04);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED20C_100E2C);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED290_100EB0);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED35C_100F7C);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED410_101030);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED518_101138);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED5E0_101200);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED694_1012B4);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED75C_10137C);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED810_101430);

void SetPlayerOntoChain(s16 arg0, s16 chainIndex, s16 spaceIndex) {
    struct player *player;

    player = GetPlayerStruct(arg0);
    if (chainIndex >= 0) {
        player->cur_chain_index = (s8)chainIndex;
        player->next_chain_index = (s8)chainIndex;
        player->reverse_chain_index = (s8)chainIndex;
    }
    if (spaceIndex >= 0) {
        player->cur_space_index = (s8)spaceIndex;
        player->next_space_index = (s8)(spaceIndex + 1);
        player->reverse_space_index = (s8)(spaceIndex - 1);
    }
}

void SetNextChainAndSpace(s16 playerIndex, s16 chainIndex, s16 spaceIndex) {
    struct player *player;

    player = GetPlayerStruct(playerIndex);
    if (chainIndex >= 0) {
        player->next_chain_index = (s8)chainIndex;
    }
    if (spaceIndex >= 0) {
        player->next_space_index = (s8)spaceIndex;
    }
}

void SetPrevChainAndSpace(s16 playerIndex, s16 chainIndex, s16 spaceIndex) {
    struct player *player;

    player = GetPlayerStruct(playerIndex);
    if (chainIndex >= 0) {
        player->reverse_chain_index = (s8)chainIndex;
    }
    if (spaceIndex >= 0) {
        player->reverse_space_index = (s8)spaceIndex;
    }
}

s32 func_800EDA58_101678() {
    s32 ret;

    ret = 0;
    func_80035FDC(D_800CD066);
    func_80035FDC(0xE);

    if (func_800F8858_10C478() == 1) {
        if (func_80035F98(3) != 0) {
            func_800F8610_10C230(-2, 4, 0x192);
            ret = 1;
        }
    }
    else {
        if (func_80035F98(3) != 0) {
            func_800FF7C4_1133E4(-2, 4, 2);
            ret = 1;
        }
    }
    return ret;
}

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800EDAF0_101710);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800EDB98_1017B8);
