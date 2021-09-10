#ifndef _1A580_H
#define _1A580_H

#include <ultra64.h>

struct strD03F8 {
    s8 unk0;
    s8 unk1;
    u8 unk2;
    s8 unk3;
    u8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s8 unks10to40[0x30];

    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;

    s8 unks58toB0[0x58];

    s32 unkB0;
    struct strD03F8 *unkB4;
    s32 unkB8;
    s32 unkBC;
}; // sizeof == 0xC0
extern struct strD03F8 *D_800D03F8;

#endif /* _1A580_H */