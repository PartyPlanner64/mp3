#ifndef _365E0_H
#define _365E0_H

#include <ultra64.h>

struct overlay_entrypoint {
    s16 index;
    void (*fn)();
};

#endif /* _365E0_H */