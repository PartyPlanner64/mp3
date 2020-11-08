#ifndef _HEAP_H
#define _HEAP_H

#include <ultra64.h>

struct heap_node
{
    s32 size;
    u8 heap_constant;
    u8 used; // bool
    struct heap_node *prev;
    struct heap_node *next;
};

void *MakeHeap(void *ptr, u32 size);
void *Malloc(struct heap_node *heap, s32 size);
void Free(void *ptr);
void *Realloc(struct heap_node *heap, void *mem, u32 new_size);
u32 GetAllocatedHeapSize(struct heap_node *heap);
u32 GetUsedMemoryBlockCount(struct heap_node *heap);
s32 GetMemoryAllocSize(s32 value);

#endif /* _HEAP_H */
