#ifndef _SPACES_H
#define _SPACES_H

#include <ultra64.h>
#include "object.h"
#include "board.h"

enum board_space_type {
    SPACE_INVISIBLE = 0,
    SPACE_BLUE = 1,
    SPACE_RED = 2,
    SPACE_MINIGAME = 3,
    SPACE_HAPPENING = 4,
    SPACE_STAR = 5,
    SPACE_CHANCE = 6,
    SPACE_START = 7,
    SPACE_MUSHROOM = 8,
    SPACE_BOWSER = 9
};

struct space_data {
    s8 unk0;
    u8 space_type; // enum board_space_type
    s16 unk2;
    s32 unk4;
    struct coords_3d coords; // 0x8
    f32 sx; // 0x14
    f32 sy;
    f32 sz;
    struct event_list_entry *event_list;
};

extern struct space_data *GetSpaceData(s16 index);

#endif /* _SPACES_H */
