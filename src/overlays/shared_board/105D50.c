#include "common.h"
#include "../../board.h"
#include "../../player.h"

// most likely similar to player.c from mp1.

extern struct object *D_801011FC; // bowser suit model?
extern s8 D_80101630[]; // difficulty data

struct str101634inner {
    s16 unk0;
    s16 unk2;
};
struct str101634 {
    u32 unk0; // count?
    struct str101634inner *unk4;
};
extern struct str101634 D_80101634;

struct str101734 {
    s32 unk0;
    s32 unk4;
};

extern struct str101734 *D_80101734[];
extern u8 D_80101754[];
extern u8 D_8010175C[];

extern s32 func_80017BB8(s16, s16);
extern void func_8001C92C(void *, f32);
extern void func_80089A10(void *, f32, f32, f32);
extern struct process *InitProcess(void *, s32, s32, s32);

extern struct object *func_800D90C8_ECCE8(u8, s32);
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
    func_8001C92C(*(obj->unk3C->unk40), arg1);
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

void func_800F2304_105F24(s32 player_index, s16 arg1, u16 arg2) {
    struct player *player;

    player = GetPlayerStruct(player_index);
    if (player == GetPlayerStruct(-1)) {
        func_800D9CE8_ED908(player->obj, arg1, arg2);
        if ((player->bowser_suit_flag != 0) & (arg1 < 7)) {
            func_800E6420_FA040(arg1, arg2);
        }
    }
}

void func_800F2388_105FA8(s32 player_index, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    struct player *player;

    player = GetPlayerStruct(player_index);
    if (player == GetPlayerStruct(-1)) {
        func_800D9D84_ED9A4(player->obj, arg1, arg2, arg3, arg4);
        if ((player->bowser_suit_flag != 0) & (arg1 < 7)) {
            func_800E644C_FA06C(arg1, arg2, arg3, arg4);
        }
    }
}

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

void func_800F24FC_10611C(s16 arg0, s32 arg1, s32 arg2) {
    u8 temp_v1;
    struct player *player;
    struct process *process;
    u8 phi_a0;

    player = GetPlayerStruct(arg0);
    player->unk1D = arg0;
    temp_v1 = player->character;
    if (arg2 == 0) {
        phi_a0 = D_80101754[temp_v1];
        player->obj = func_800D90C8_ECCE8(phi_a0, arg1);
    }
    else if ((phi_a0 = arg2 >= 0) && (arg2 < 3)) {
        phi_a0 = D_8010175C[temp_v1];
        player->obj = func_800D90C8_ECCE8(phi_a0, arg1);
    }
    process = InitProcess(func_800F248C_1060AC, 0x5000, 0, 0);
    player->process = process;
    process->user_data = player;
}

void func_800F25B4_1061D4(s16 arg0, s32 arg1) {
    func_800F24FC_10611C(arg0, arg1, 0);
}

void func_800F25D8_1061F8(s16 player_index) {
    func_800F24FC_10611C(player_index, (s32)D_80101734[GetPlayerStruct(player_index)->character], 0);
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
// void func_800F26E8_106308() {
//     s32 i, j;

//     for (i = 0; i < 5; i++) {
//         GetPlayerStruct(i)->obj = NULL;
//     }

//     for (i = 1; i < 8; i++) {
//         for (j = 0; j < D_80101634.unk0; j++) {
//             // FIXME: Pretty wrong here.
//             D_80101734[i]->unk4 = func_80017BB8(i, D_80101634.unk4[j].unk2);
//         }
//     }
// }

void func_800F27C4_1063E4() {
}
