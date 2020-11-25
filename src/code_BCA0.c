#include "common.h"

extern s32 D_80097650;

s32 func_8000B0A0(s32 arg0, s32 arg1) {
    return func_8001A150(ReadMainFS(arg0), arg1) & 0xFFFF;
}

s32 func_8000B0D4(s32 arg0, s32 arg1) {
    return func_8001A150(ReadMainFS(arg0), arg1) & 0xFFFF;
}

u32 func_8000B108(s32 arg0, s32 arg1) {
    return func_8001A150(ReadMainFS(arg0), arg1) & 0xFFFF;
}

s16 func_8000B13C(s32 arg0) {
    return func_8001A150(ReadMainFS(arg0), 0x1D);
}

INCLUDE_ASM(u8, "code_BCA0", GetRandomByte);
// u8 GetRandomByte() {
//     u32 x;

//     x = D_80097650 * 0x41C64E6D; // FIXME: reg alloc
//     D_80097650 = x + 0x3039;
//     return ((x + 0x303A) >> 0x10);
// }

INCLUDE_ASM(s32, "code_BCA0", func_8000B1A0);

INCLUDE_ASM(s32, "code_BCA0", func_8000B2C4);

INCLUDE_ASM(s32, "code_BCA0", func_8000B364);

INCLUDE_ASM(s32, "code_BCA0", func_8000B3C8);

INCLUDE_ASM(s32, "code_BCA0", func_8000B460);

INCLUDE_ASM(s32, "code_BCA0", func_8000B4B4);

INCLUDE_ASM(s32, "code_BCA0", func_8000B4F8);

INCLUDE_ASM(s32, "code_BCA0", func_8000B554);

INCLUDE_ASM(s32, "code_BCA0", func_8000B5BC);
