#include "common.h"
#include "../libultra_internal.h"

extern s32 D_800D5554;
extern s32 D_800CE174;
extern s32 D_800D6A8C;
extern s32 D_800CC43C;
extern s32 D_800D1FC8;

void osInitRdb(u8 *sendBuf, u32 sendSize) {
    register u32 int_disabled;

    sendSize >>= 2;

    if (((u32)sendBuf & 3) != 0) {
        sendBuf = ((u32)sendBuf & 3) + 4;
        sendSize--;
    }

    int_disabled = __osDisableInt();

    D_800D5554 = sendBuf;
    D_800CE174 = sendSize;
    D_800D6A8C = 0;
    D_800CC43C = 0;
    D_800D1FC8 = 0;

    __osRestoreInt(int_disabled);
}
