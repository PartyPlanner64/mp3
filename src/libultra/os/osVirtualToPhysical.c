#include "common.h"

#define	K0BASE 0x80000000
#define	K1BASE 0xA0000000
#define	K2BASE 0xC0000000

#define	IS_KSEG0(x) ((u32)(x) >= (u32)K0BASE && (u32)(x) < (u32)K1BASE)
#define	IS_KSEG1(x) ((u32)(x) >= (u32)K1BASE && (u32)(x) < (u32)K2BASE)

#define	K0_TO_PHYS(x) ((u32)(x)&0x1FFFFFFF)
#define	K1_TO_PHYS(x) ((u32)(x)&0x1FFFFFFF)

INCLUDE_ASM(u32, "libultra/os/osVirtualToPhysical", osVirtualToPhysical, void *addr);

// FIXME: There's an addu instead of a subu. But the code is right?
// u32 osVirtualToPhysical(void *addr)
// {
//     if (IS_KSEG0(addr)) {
//         return K0_TO_PHYS(addr);
//     }
//     else if (IS_KSEG1(addr)) {
//         return K1_TO_PHYS(addr);
//     }
//     else {
//         return __osProbeTLB(addr);
//     }
// }

// u32 osVirtualToPhysical(void *addr) {
//     if ((u32) addr >= 0x80000000 && (u32) addr < 0xa0000000) {
//         return ((u32) addr & 0x1fffffff);
//     } else if ((u32) addr >= 0xa0000000 && (u32) addr < 0xc0000000) {
//         return ((u32) addr & 0x1fffffff);
//     } else {
//         return __osProbeTLB(addr);
//     }
// }
