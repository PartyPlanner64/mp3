#include "common.h"
#include "../libultra_internal.h"

s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flag) {
    register u32 int_disabled;
    register s32 index;

    int_disabled = __osDisableInt();

    while (mq->validCount >= mq->msgCount) {
        if (flag == OS_MESG_BLOCK) {
            D_800A2DC0->state = 8;
            __osEnqueueAndYield(&mq->fullqueue);
        }
        else {
            __osRestoreInt(int_disabled);
            return -1;
        }
    }

    index = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[index] = msg;
    mq->validCount++;

    if (mq->mtqueue->next != NULL) {
        osStartThread(__osPopThread(&mq->mtqueue));
    }

    __osRestoreInt(int_disabled);
    return 0;
}
