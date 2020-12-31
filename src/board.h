#ifndef _BOARD_H
#define _BOARD_H

#include <ultra64.h>

struct event_list_entry {
    s16 activation_type;
    s16 execution_type;
    void (*event_fn)();
};

struct event_table_entry {
    s16 space_index;
    struct event_list_entry *event_list;
};

struct strCD058 {
    /* 0x00 - 800CD058 */ s8 unk0;
    /* 0x01 - 800CD059 */ s8 current_board_index;
    /* 0x02 - 800CD05A */ s8 total_turns;
    /* 0x03 - 800CD05B */ s8 current_turn;
    /* 0x04 - 800CD05C */ s8 current_game_length; // 00=Lite Play,01=Standard Play,02=Full Play,03=Custom Play
    /* 0x05 - 800CD05D */ s8 current_star_spawn; // Index of star space (index into star_spawn_indices)
    /* 0x06 - 800CD05E */ s8 star_spawn_indices[9];
    /* 0x0F - 800CD067 */ s8 current_player_index;
    /* 0x10 - 800CD068 */ s8 unk10;
    /* 0x11 - 800CD069 */ s8 current_space_index;
    /* 0x12 - 800CD06A */ s8 unk12;
    /* 0x13 - 800CD06B */ s8 unk13;
    /* 0x14 - 800CD06C */ s8 unk14;
    /* 0x15 - 800CD06D */ s8 unk15;
    /* 0x16 - 800CD06E */ s8 unk16;

    // 800cd09c flag for re-roll
};
extern struct strCD058 D_800CD058;

extern u16 D_800CD0AE;

#endif /* _BOARD_H */