#ifndef _PLAYER_H
#define _PLAYER_H

#include <ultra64.h>
#include "../object.h"
#include "../process.h"

/**
 * Represents a player's state during a game.
 */
struct player {
    s8 id;
    s8 cpu_difficulty;
    s8 controller;
    u8 character;
    /**
     * Miscellaneous flags.
     * 1: Is CPU player
     */
    u8 flags;
    s8 pad0[5];
    /**
     * Current coin count.
     */
    s16 coins; // 10
    /**
     * Coins obtained during a Mini-Game.
     */
    s16 minigame_coins; // 12
    s8 stars; // 14

    u8 cur_chain_index; // 15
    u8 cur_space_index; // 16
    u8 next_chain_index; // 17
    u8 next_space_index; // 18
    u8 unk1_chain_index; // 19
    u8 unk1_space_index; // 20
    u8 reverse_chain_index; // 21
    u8 reverse_space_index; // 22

    u8 flags2; // 23
    u8 items[3]; // 24
    u8 bowser_suit_flag; // 27
    u8 turn_color_status; // 28

    s8 pad1[7]; // 29 - 35

    struct object *obj; // 36
    s16 minigame_star; // 40
    s16 max_coins; // 42
    s8 happening_space_count; // 44
    s8 red_space_count;
    s8 blue_space_count;
    s8 chance_space_count;
    s8 bowser_space_count; // 48
    s8 battle_space_count;
    s8 item_space_count;
    s8 bank_space_count;
    s8 game_guy_space_count; // 52

    // s8 pad2[3];
}; // sizeof == 56

extern struct player gPlayers[4];

s16 GetCurrentPlayerIndex();
struct player *GetPlayerStruct(s32 index);
// s16 PlayerIsCurrent(s16 index);
// u32 PlayerStructIsCurrent(struct player *player);
// u32 PlayerIsCPU(s16 index);
// void AdjustPlayerCoins(s32 index, s32 count);
// u32 PlayerHasCoins(s32 index, s32 count);
// void SetPlayerAnimation(s32 index, s32 animation, s32 unk);

#endif /* _PLAYER_H */
