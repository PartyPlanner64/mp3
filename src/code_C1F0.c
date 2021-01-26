#include "common.h"

// Sprite graphics related.

struct strCD1DC {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA; // x center
    s16 unkC; // y center
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s16 unk1C;
    s16 unk1E;
    s32 unk20;
}; // sizeof === 0x24;

extern struct strCD1DC *D_800CD1DC;

extern void func_80055458(s16, s32, u16);
extern void func_800551D8(s16, s32, f32, f32);

INCLUDE_ASM(s32, "code_C1F0", func_8000B5F0);

INCLUDE_ASM(s32, "code_C1F0", func_8000B638);

INCLUDE_ASM(s32, "code_C1F0", func_8000B690);

INCLUDE_ASM(s32, "code_C1F0", func_8000B710);

INCLUDE_ASM(s32, "code_C1F0", func_8000B7A0);

// Load sprite from main fs.
s16 func_8000B838(s32 dirAndFile) {
    s16 ret;
    void *fsAlloc;

    fsAlloc = ReadMainFS(dirAndFile);
    ret = func_80055810(fsAlloc);
    FreePerm(fsAlloc);
    return ret;
}

INCLUDE_ASM(s32, "code_C1F0", func_8000B880);

void func_8000BA00() {
    func_80056BAC();
    func_80019A98(D_800CD1DC);
    D_800CD1DC = NULL;
}

INCLUDE_ASM(s32, "code_C1F0", func_8000BA30);

INCLUDE_ASM(s32, "code_C1F0", func_8000BB54);

INCLUDE_ASM(s32, "code_C1F0", func_8000BB94);

// Set sprite center.
void func_8000BBD4(u16 spriteId, s16 x, s16 y) {
    struct strCD1DC *sprite;

    sprite = D_800CD1DC + spriteId;
    sprite->unkA = x;
    sprite->unkC = y;
}

void func_8000BBFC(u16 spriteId, s16 arg1) {
    struct strCD1DC *sprite;

    sprite = D_800CD1DC + spriteId;
    sprite->unk1E = arg1;
    sprite->unk1C = arg1;
    func_80055458(sprite->unk4, 0, arg1);
}

INCLUDE_ASM(s32, "code_C1F0", func_8000BC48);

INCLUDE_ASM(s32, "code_C1F0", func_8000BC88);

INCLUDE_ASM(s32, "code_C1F0", func_8000BCC8);

INCLUDE_ASM(s32, "code_C1F0", func_8000BD08);

INCLUDE_ASM(s32, "code_C1F0", func_8000BD50);

INCLUDE_ASM(s32, "code_C1F0", func_8000BD94);

INCLUDE_ASM(s32, "code_C1F0", func_8000BDDC);

INCLUDE_ASM(s32, "code_C1F0", func_8000BE1C);

// Scale sprite.
void func_8000BE5C(u16 spriteId, f32 x, f32 y) {
    struct strCD1DC *sprite;

    sprite = D_800CD1DC + spriteId;
    func_800551D8(sprite->unk4, 0, x, y);
}

INCLUDE_ASM(s32, "code_C1F0", func_8000BEAC);

INCLUDE_ASM(s32, "code_C1F0", func_8000BF00);

INCLUDE_ASM(s32, "code_C1F0", func_8000BF48);

INCLUDE_ASM(s32, "code_C1F0", func_8000BF8C);

INCLUDE_ASM(s32, "code_C1F0", func_8000BFEC);

INCLUDE_ASM(s32, "code_C1F0", func_8000C184);
