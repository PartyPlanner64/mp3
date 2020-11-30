#include "common.h"
#include "../libultra_internal.h"

INCLUDE_ASM(s32, "libultra/os/osSetTimer", osSetTimer, OSTimer* timer, OSTime countdown, OSTime interval, OSMesgQueue* mq, OSMesg msg);
