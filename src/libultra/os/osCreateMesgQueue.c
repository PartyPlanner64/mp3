#include "common.h"
#include "../libultra_internal.h"

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msgBuf, s32 count) {
    mq->mtqueue = (OSThread *) &D_800A2DB0;
    mq->fullqueue = (OSThread *) &D_800A2DB0;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msgBuf;
}
