#ifndef _PLAYER_H
#define _PLAYER_H

#include <ultra64.h>
#include "object.h"
#include "process.h"

/**
 * Represents a player's state during a game.
 */
struct player {
    /*  0 (0x00) 800D1108 */ s8 id;
    /*  1 (0x01) 800D1109 */ s8 cpu_difficulty;
    /*  2 (0x02) 800D110A */ u8 controller;
    /*  3 (0x03) 800D110B */ u8 character;
    /**
     * Player flags.
     * 1: Is CPU player
     * 4: ?
     */
    /*  4 (0x04) 800D110C */ u8 flags;
    s8 pad5[1];
    /** Coins collected in a mini-game. */
    /*  6 (0x06) 800D110E */ s16 bonus_coins;
    /** Coins from mini-game wins. */
    /*  8 (0x08) 800D1110 */ s16 coins_won;
    /** Current coin count. */
    /* 10 (0x0A) 800D1112 */ s16 coins;
    /** Coins obtained during a Mini-Game. */
    /* 12 (0x0C) 800D1114 */ s16 minigame_coins;
    /* 14 (0x0E) 800D1116 */ s8 stars;

    /* 15 (0x0F) 800D1117 */ u8 cur_chain_index;
    /* 16 (0x10) 800D1118 */ u8 cur_space_index;
    /* 17 (0x11) 800D1119 */ u8 next_chain_index;
    /* 18 (0x12) 800D111A */ u8 next_space_index;
    /* 19 (0x13) 800D111B */ u8 unk1_chain_index;
    /* 20 (0x14) 800D111C */ u8 unk1_space_index;
    /* 21 (0x15) 800D111D */ s8 reverse_chain_index;
    /* 22 (0x16) 800D111E */ s8 reverse_space_index;

    /**
     * Movement flags.
     * 1: Is moving in reverse.
     */
    /* 23 (0x17) 800D111F */ u8 flags2;
    /* 24 (0x18) 800D1120 */ s8 items[3];
    /* 27 (0x1B) */ s8 bowser_suit_flag;
    /* 28 (0x1C) */ u8 turn_color_status;
    /* 29 (0x1D) */ s8 unk1D;

    s8 unks1E1F[2]; // 20 - 31

    /* 32 (0x20) */ struct process *process;
    /* 36 (0x24) */ struct object *obj;
    /* 40 (0x28) */ s16 minigame_star;
    /* 42 (0x2A) */ s16 max_coins;
    /* 44 (0x2C) */ s8 happening_space_count;
    s8 red_space_count;
    s8 blue_space_count;
    s8 chance_space_count;
    /* 48 (0x30) */ s8 bowser_space_count;
    s8 battle_space_count;
    s8 item_space_count;
    s8 bank_space_count;
    /* 52 (0x34) */ s8 game_guy_space_count;

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
