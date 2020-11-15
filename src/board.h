#ifndef _BOARD_H
#define _BOARD_H

#include <ultra64.h>

struct board_overlay_entrypoint {
    s16 index;
    void *fn;
};

#endif /* _BOARD_H */