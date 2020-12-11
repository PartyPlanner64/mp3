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

#endif /* _BOARD_H */