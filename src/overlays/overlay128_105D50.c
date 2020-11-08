#include "common.h"
#include "player.h"

// most likely similar to player.c from mp1.

extern s8 D_800CD067; // current player index

/**
 * Returns the index of the current player in the turn.
 */
s16 GetCurrentPlayerIndex() {
    return D_800CD067;
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
    return index == D_800CD067;
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

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F2260_105E80);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F22C0_105EE0);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F2304_105F24);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F2388_105FA8);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F244C_10606C);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F2484_1060A4);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F248C_1060AC);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F24FC_10611C);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F25B4_1061D4);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F25D8_1061F8);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F2624_106244);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F2660_106280);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F2690_1062B0);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F26E8_106308);

INCLUDE_ASM(s32, "overlays/overlay128_105D50", func_800F27C4_1063E4);
