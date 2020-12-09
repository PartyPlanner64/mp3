#ifndef _OBJECT_H
#define _OBJECT_H

#include <ultra64.h>

struct coords_3d {
    f32 x;
    f32 y;
    f32 z;
};

struct object {
    /*0x00*/ struct object *prev; // may be NULL
    /*0x04*/ struct object *next;
    /*0x08*/ u8 unk8;
    /*0x09*/ s8 unk9;
    /*0x0A*/ u16 unkA;

    /*0x0C*/ struct coords_3d coords;

    f32 unk18; // Rotation?
    f32 unk1C;
    f32 unk20;

    f32 unk24; // Scale?
    f32 unk28;
    f32 unk2C;

    f32 unk30;
    f32 unk34;
    f32 unk38;

    struct object_indirect *unk3C;
    struct object_indirect *unk40; // is type right?
    s16 unk44;
    s16 unk46;
};

struct strA1770 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
};

// temp_v0_2->unk0 = (u16)1;
// temp_v0_2->unk8 = (u16)-1;
// temp_v0_2->unk6 = (u16)-1;
// temp_v0_2->unk4 = (u16)-1;
// temp_v0_2->unk10 = 0;
// temp_v0_2->unk2C = 0.0f;
// temp_v0_2->unk28 = 0.0f;
// temp_v0_2->unk24 = 0.0f;
// temp_v0_2->unk20 = 0.0f;
// temp_v0_2->unk1C = 0.0f;
// temp_v0_2->unk18 = 0.0f;
// temp_v0_2->unk38 = 1.0f;
// temp_v0_2->unk34 = 1.0f;
// temp_v0_2->unk30 = 1.0f;
// temp_v0_2->unk48 = 0;
// temp_v0_2->unk40 = 0;
// temp_v0_2->unk5C = 0;
// temp_v0_2->unk14 = 0;
// temp_v1_2 = phi_a0 + 1;
// temp_v0_2->unkA = temp_v1_2;
// temp_v0_2->unk44 = (u16)0;
// temp_v0_2->unk48 = 0;

// What is this, in relation to object?
struct object_indirect {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;

    void *unk14;

    f32 unk18;
    f32 unk1C;
    f32 unk20;

    // Rotation?
    f32 unk24;
    f32 unk28;
    f32 unk2C;

    f32 unk30;
    f32 unk34;
    f32 unk38;

    u16 unk3C;
    struct object_indirect2 *unk40;
    u16 unk44; // count of unk48
    s16 pad46;
    s16 *unk48;
    u8 pad4C;
    u8 pad4D;
    u16 pad4E;
    s32 pad50;
    s32 pad54;
    s32 pad58;
    struct object_indirect3 *unk5C;
}; // sizeof 0x60

struct object_indirect2 {
    s16 unk0;
};

struct object_indirect3 {
    struct object *unk0;
    f32 unk4;
};


#endif /* _OBJECT_H */
