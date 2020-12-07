#include "common.h"
#include "object.h"

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

extern struct overlay_info D_800974F4[];

struct str80097560 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
extern struct str80097560 D_80097560[];

extern struct str80097560 D_800975A8[];

struct str8000B364 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
extern struct str8000B364 D_800975F0[];

extern u32 D_80097650; // = 0xD9ED;
extern s16 D_800D1FA2;

extern void func_800124BC(u8, struct str8000B364 *);
extern void func_80012508(u8, struct str80097560 *, struct str80097560 *);
extern void func_8004DB14(void *, void *, u32);

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

u8 GetRandomByte() {
    u32 x;
    s32 x1;
    u32 x2;

    // Obviously a little rough...
    x1 = D_80097650;
    x1 = 0x41C64E6D * x1;
    x2 = x1;
    x = x2;
    x1 = 0x303A;
    D_80097650 = x2 + 0x3039;
    return (x + x1) >> 16;
}

void func_8000B1A0(s32 overlayIndex, u8 flags) {
    u32 rom_start;
    u32 code_start;
    u32 code_end;
    u32 data_start;
    u32 data_end;
    u32 bss_start;
    u32 bss_end;
    u32 ram_start;
    u8 *bssStartTemp;
    u32 bss_start_counter;

    rom_start = D_800974F4[overlayIndex].rom_start;
    code_start = D_800974F4[overlayIndex].code_start;
    code_end = D_800974F4[overlayIndex].code_end;
    data_start = D_800974F4[overlayIndex].data_start;
    data_end = D_800974F4[overlayIndex].data_end;
    bss_start = D_800974F4[overlayIndex].bss_start;
    bss_end = D_800974F4[overlayIndex].bss_end;
    ram_start = D_800974F4[overlayIndex].ram_start;

    if ((flags & 1) != 0) {
        func_8004DB14(rom_start, ram_start, code_end - code_start);
    }
    if ((flags & 2) != 0) {
        func_8004DB14(rom_start + (code_end - code_start), data_start, data_end - data_start);
    }
    if ((flags & 4) != 0) {
        bss_start_counter = bss_start;
        bssStartTemp = bss_start;
        while (bss_start_counter < bss_end) {
            *(bssStartTemp) = 0;
            bss_start_counter++;
            bssStartTemp = bssStartTemp + 1;
        }
    }
}

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

void func_8000B3C8(u32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    u8 i;

    i = arg0;
    D_80097560[i].unk0 = arg1;
    D_80097560[i].unk4 = arg2;
    D_80097560[i].unk8 = arg3;
    D_800975A8[i].unk0 = arg4;
    D_800975A8[i].unk4 = arg5;
    D_800975A8[i].unk8 = arg6;
    func_80012508(arg0, &D_80097560[i], &D_800975A8[i]);
}

void func_8000B460(struct object_indirect *arg0, u16 arg1, s32 arg2) {
    s16 temp_v0;

    temp_v0 = func_8000B13C(arg2);
    if (temp_v0 >= 0) {
        arg0->unk48[arg1] = temp_v0;
    }
}

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
