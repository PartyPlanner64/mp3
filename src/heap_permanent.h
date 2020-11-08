#ifndef _HEAP_PERM_H
#define _HEAP_PERM_H

#include <ultra64.h>

struct heap_node *MakePermHeap(void *ptr, u32 size);
void *MallocPerm(u32 size);
void FreePerm(void *ptr);
void *ReallocPerm(void *mem, u32 new_size);

#endif /* _HEAP_PERM_H */
