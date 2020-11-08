#include <ultra64.h>
#include "heap.h"

/*
 * Primary heap. Never reset during gameplay.
 */
extern struct heap_node *perm_heap_addr;

/*
 * Creates the "permanent" heap that is never reset.
 * Called once during startup.
 */
struct heap_node *MakePermHeap(void *ptr, u32 size)
{
    perm_heap_addr = (struct heap_node *)MakeHeap(ptr, size);
}

/*
 * Allocates memory in the permanent heap.
 */
void *MallocPerm(u32 size)
{
    Malloc(perm_heap_addr, size);
}

/*
 * Frees a memory pointer in the permanent heap.
 */
void FreePerm(void *ptr)
{
    Free(ptr);
}

/*
 * Resizes a previously allocated permanent heap buffer.
 */
void *ReallocPerm(void *mem, u32 new_size)
{
    return (void *)Realloc(perm_heap_addr, mem, new_size);
}

/*
 * Returns the total size of allocated buffers in the permanent heap.
 */
u32 GetAllocatedPermHeapSize(void)
{
    return GetAllocatedHeapSize(perm_heap_addr);
}

u32 GetUsedMemoryBlockCountPerm(void)
{
    return GetUsedMemoryBlockCount(perm_heap_addr);
}
