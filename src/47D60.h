#ifndef _47D60_H
#define _47D60_H

#include <ultra64.h>

struct strD2010 {
    s32 overlayIndex;
    s16 entrypointIndex;
    u16 unk6;
};
extern struct strD2010 D_800D2010[];
extern struct strD2010 D_800D20F0[];

struct process *InitProcess(void *func, u16 priority, s32 stackSize, s32 extraDataSize);

struct unk80047620 {
    s8 unks[0x14];
    void *unk14;
};

#endif /* _47D60_H */
