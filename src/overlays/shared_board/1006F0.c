#include "common.h"
#include "../../player.h"
#include "../../object.h"
#include "../../process.h"
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

void func_800ECC28_100848(s16 playerIndex) {
    func_800ECC0C_10082C(&(GetPlayerStruct(playerIndex)->obj->unk18));
}

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECC54_100874);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECD00_100920);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECDD4_1009F4);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECE4C_100A6C);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECE9C_100ABC);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECEE4_100B04);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECF18_100B38);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ECF9C_100BBC);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", D_800ECFC8_100BE8);

INCLUDE_ASM(struct process *, "overlays/shared_board/1006F0", func_800ED128_100D48);
// struct process *func_800ED128_100D48(struct coords_3d *arg0, struct coords_3d *arg1, struct coords_3d *arg2, s32 frameCount) {
//     u8 *temp_s0;
//     struct process *process;

//     process = InitProcess(D_800ECFC8_100BE8, 0x4002, 0, 0x80);
//     temp_s0 = Malloc(process->heap, 0x24);
//     process->user_data = temp_s0;
//     func_80089A10(&temp_s0, arg0->x, 0, arg0->z);
//     func_80089A10(&temp_s0 + 0xC, arg1->x, 0, arg1->z);
//     temp_s0->unk18 = arg2;
//     temp_s0->unk1C = arg3;
//     temp_s0->unk20 = 0;
//     return process;
// }

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED1E4_100E04);
// void func_800ED1E4_100E04() {
//     func_800ED128_100D48()->user_data->unk20 = 1;
// }

// Rotate player towards space over a frame count period.
void func_800ED20C_100E2C(s16 playerIndex, s32 frameCount, s16 spaceIndex) {
    f32 *temp_a2;
    struct player *player;
    struct coords_3d coords;

    player = GetPlayerStruct(playerIndex);
    func_80089AB0(&coords, &GetSpaceData(spaceIndex)->coords, &player->obj->coords);
    func_800D88E8_EC508(&coords);
    temp_a2 = &player->obj->unk18;
    func_800ED128_100D48(temp_a2, &coords, temp_a2, frameCount);
}

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", D_800ED290_100EB0);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED35C_100F7C);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED410_101030);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", D_800ED518_101138);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800ED5E0_101200);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", D_800ED694_1012B4);

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

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", D_800EDAF0_101710);

INCLUDE_ASM(s32, "overlays/shared_board/1006F0", func_800EDB98_1017B8);
// struct process *func_800EDB98_1017B8(void *arg0, f32 arg1, f32 arg2) {
//     void *process;
//     void *temp_v0;

//     process = InitProcess(D_800EDAF0_101710, 0xA, 0, 0x40);
//     temp_v0 = Malloc(process->heap, 16);
//     process->user_data = temp_v0;
//     temp_v0->unk0 = arg0;
//     temp_v0->unk4 = arg1;
//     temp_v0->unk8 = arg2;
//     temp_v0->unkC = (f32) arg0->unk30;
//     return process;
// }