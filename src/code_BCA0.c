#include "common.h"

extern u8 D_800962F0;

struct overlay_info {
    u32 rom_start;
    u32 rom_end;
    u32 ram_start;
    u32 code_start;
    u32 code_end;
    u32 data_start;
    u32 data_end;
    u32 bss_start;
    u32 bss_end;
}; // sizeof 0x24
extern struct overlay_info D_800962F4[];

struct str8000B364 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
extern struct str8000B364 D_800975F0[];

extern s32 D_80097650;
extern s16 D_800D1FA2;

extern void func_800124BC(u8, struct str8000B364 *);

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

// copies in an overlay and clears bss region.
void func_8000B2C4(s32 overlayIndex) {
    s32 rom_start;
    s32 rom_end;
    s8 *bss_start;
    s8 *bss_end;
    s8 *temp;

    rom_start = D_800962F4[overlayIndex].rom_start;
    rom_end = D_800962F4[overlayIndex].rom_end;
    bss_start = D_800962F4[overlayIndex].bss_start;
    bss_end = D_800962F4[overlayIndex].bss_end;

    func_8004DB14(rom_start, D_800962F4[overlayIndex].ram_start, rom_end - rom_start);

    temp = bss_start;
    while (bss_start < bss_end) {
        *(temp++) = 0;
        bss_start++;
    }

    D_800962F0 = 0;
}

void func_8000B364(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    u8 i;

    i = arg0;
    D_800975F0[i].unk0 = arg1;
    D_800975F0[i].unk4 = arg2;
    D_800975F0[i].unk8 = arg3;
    D_800975F0[i].unkC = arg4;
    func_800124BC(arg0, &D_800975F0[i]);
}

INCLUDE_ASM(s32, "code_BCA0", func_8000B3C8);

INCLUDE_ASM(s32, "code_BCA0", func_8000B460);

s8 func_8000B4B4() {
    s8 ret;
    if (D_800D1FA2 > D_800962F0) {
        ret = D_800962F0++;
    }
    else {
        ret = -1;
    }
    return ret;
}

s32 func_8000B4F8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = ReadMainFS(arg0);
    temp_s0 = func_8001443C(temp_s1, arg1, arg2 & 0xFF);
    FreePerm(temp_s1);
    return temp_s0 & 0xFFFF;
}

s16 func_8000B554(s32 arg0, s32 arg1, s32 arg2) {
    s16 temp_s0;
    s32 temp_s1;

    temp_s1 = ReadMainFS(arg1);
    temp_s0 = func_800323CC(arg0, temp_s1, 0, arg2);
    FreePerm(temp_s1);
    return temp_s0;
}

s16 func_8000B5BC(s32 arg0) {
    return func_8001A150(func_80009CD8(arg0, 0x7918), 0);
}
