#ifndef _47D60_H
#define _47D60_H

#include <ultra64.h>

struct process *InitProcess(void *func, u16 priority, s32 stackSize, s32 extraDataSize);

#endif /* _47D60_H */
