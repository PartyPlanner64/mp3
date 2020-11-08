#ifndef _HEAP_TEMP_H
#define _HEAP_TEMP_H

#include <ultra64.h>

struct heap_node *MakeTempHeap(void *ptr, u32 size);
void *MallocTemp(u32 size);
void FreeTemp(void *ptr);
void *ReallocTemp(void *mem, u32 new_size);

#endif /* _HEAP_TEMP_H */
