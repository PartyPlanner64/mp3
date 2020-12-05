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
     * 4: ?
     */
    u8 flags;
    s8 pad5[1];
    s16 bonus_coins; // 6, coins collected in a mini-game
    s16 coins_won; // 8, coins from mini-game win
    /**
     * Current coin count.
     */
    s16 coins; // 10 (0xA)
    /**
     * Coins obtained during a Mini-Game.
     */
    s16 minigame_coins; // 12 (0xC)
    s8 stars; // 14 (0xE)

    u8 cur_chain_index; // 15 (0xF)
    u8 cur_space_index; // 16 (0x10)
    u8 next_chain_index; // 17 (0x11)
    u8 next_space_index; // 18 (0x12)
    u8 unk1_chain_index; // 19 (0x13)
    u8 unk1_space_index; // 20 (0x14)
    u8 reverse_chain_index; // 21 (0x15)
    u8 reverse_space_index; // 22 (0x16)

    u8 flags2; // 23 (0x17)
    u8 items[3]; // 24 (0x18)
    s8 bowser_suit_flag; // 27 (0x1B)
    u8 turn_color_status; // 28 (0x1C)

    s8 pad1[3]; // 29 - 31

    void *unk20; // 32 (0x20)
    struct object *obj; // 36 (0x24)
    s16 minigame_star; // 40 (0x28)
    s16 max_coins; // 42 (0x2A)
    s8 happening_space_count; // 44 (0x2C)
    s8 red_space_count;
    s8 blue_space_count;
    s8 chance_space_count;
    s8 bowser_space_count; // 48 (0x30)
    s8 battle_space_count;
    s8 item_space_count;
    s8 bank_space_count;
    s8 game_guy_space_count; // 52 (0x34)

    // s8 pad2[3];
}; // sizeof == 56 | 0x38

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
