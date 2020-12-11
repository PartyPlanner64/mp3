#include "common.h"
#include "../../board.h"
#include "../../player.h"

// most likely similar to player.c from mp1.

extern struct object *D_801011FC; // bowser suit model?
extern s8 D_80101630[]; // difficulty data
extern void *D_80101734[];
extern u8 D_8010175C[];

extern void func_8001C92C(void *, f32);
extern void func_80089A10(void *, f32, f32, f32);

extern void func_800D9CE8_ED908(struct object *, s32, u16);

/**
 * Returns the index of the current player in the turn.
 */
s16 GetCurrentPlayerIndex() {
    return D_800CD058.current_player_index;
}

/**
 * Returns a pointer to a player by index.
 */
struct player *GetPlayerStruct(s32 index) {
    if (index < 0) {
        index = GetCurrentPlayerIndex();
    }
    return &gPlayers[index];
}

/**
 * Returns true if the given index matches the current player index.
 */
s16 PlayerIsCurrent(s16 index) {
    return index == D_800CD058.current_player_index;
}

/**
 * Returns true if the player is CPU-controlled.
 */
u32 PlayerIsCPU(s16 index) {
    return GetPlayerStruct(index)->flags & 1;
}

/**
 * Adjust's a player's coin total by a given count.
 */
void AdjustPlayerCoins(s32 index, s32 count) {
    struct player *player = GetPlayerStruct(index);
    player->coins += count;
    if (player->coins >= 1000) {
        player->coins = 999;
    }
    if (player->coins < 0) {
        player->coins = 0;
    }

    if (player->max_coins <= player->coins) {
        player->max_coins = player->coins;
    }
}

/**
 * Returns true if a player has at least the given coin count.
 */
u32 PlayerHasCoins(s32 index, s32 count) {
    struct player *player = GetPlayerStruct(index);
    return player->coins >= count;
}

void func_800F2260_105E80(s32 player_index, f32 arg1) {
    struct player *player;
    struct object *obj;

    player = GetPlayerStruct(player_index);
    if (player->bowser_suit_flag != 0) {
        obj = D_801011FC;
    }
    else {
        obj = player->obj;
    }
    func_8001C92C(obj->unk3C->unk40->unk0, arg1);
}

void func_800F22C0_105EE0(s32 player_index) {
    struct player *player;
    struct object *obj;

    player = GetPlayerStruct(player_index);
    if (player->bowser_suit_flag != 0) {
        func_800EE97C_10259C(D_801011FC);
    }
    else {
        func_800EE97C_10259C(player->obj);
    }
}

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F2304_105F24);
// s8 func_800F2304_105F24(s32 player_index, s32 arg2) {
//     struct player *player;
//     s8 ret;

//     player = GetPlayerStruct(player_index);
//     if (player == GetPlayerStruct(-1)) {
//         func_800D9CE8_ED908(player->obj, player_index, arg2);
//         ret = (player->bowser_suit_flag != 0) & (player_index < 7);
//         if (ret != 0) {
//             ret = func_800E6420_FA040(player_index, arg2);
//         }
//     }
//     return ret;
// }

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F2388_105FA8);

void func_800F244C_10606C(s32 player_index, u8 difficulty) {
    GetPlayerStruct(player_index)->cpu_difficulty = D_80101630[difficulty];
}

void func_800F2484_1060A4() {
}

void func_800F248C_1060AC() {
    struct player *player;

    player = (struct player *)GetCurrentProcess()->user_data;
    while (TRUE) {
        SleepVProcess();

        if ((player->flags & 4) != 0) {
            continue;
        }

        func_80089A10(&player->obj->unk24, 1.0f, 1.0f, 1.0f);
    }
}

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F24FC_10611C);

void func_800F25B4_1061D4(s16 arg0, s32 arg1) {
    func_800F24FC_10611C(arg0, arg1, 0);
}

void func_800F25D8_1061F8(s16 player_index) {
    func_800F24FC_10611C(player_index, D_80101734[GetPlayerStruct(player_index)->character], 0);
}

void func_800F2624_106244(s16 player_index) {
    GetPlayerStruct(player_index); // TODO: is this returned?
    func_800F24FC_10611C(player_index, 0, 0);
}

u8 func_800F2660_106280(s16 arg0) {
    return D_8010175C[GetPlayerStruct(arg0)->character];
}

void *func_800F2690_1062B0(s16 arg0) {
    struct process *process;
    void *ret;
    s32 temp_v0_2;
    struct player *player;
    struct object *obj;

    player = GetPlayerStruct(arg0);
    obj = ret = player->obj;
    if (obj != NULL) {
        process = player->process;
        if (process != NULL) {
            EndProcess(process);
        }
        ret = func_800D9B54_ED774(player->obj);
        player->obj = NULL;
    }
    return ret;
}

INCLUDE_ASM(s32, "overlays/shared_board/105D50", func_800F26E8_106308);

void func_800F27C4_1063E4() {
}
