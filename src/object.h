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

    /*0x18*/ f32 rot1;
    f32 rot2;
    f32 rot3;

    /*0x24*/ f32 unk24;
    f32 unk28;
    f32 unk2C;

    /*0x30*/ f32 unk30;
    f32 unk34;
    f32 unk38;

    struct object_indirect *unk3C;
    void *unk40;
    s16 unk44;
    s16 unk46;
};

// Is this really just object? What is up with unk3C?
struct object_indirect {
    s8 pad[24];

    /*0x18*/ f32 rot1;
    f32 rot2;
    f32 rot3;

    /*0x24*/ f32 unk24;
    f32 unk28;
    f32 unk2C;

    /*0x30*/ f32 unk30;
    f32 unk34;
    f32 unk38;

    u16 unk3C;
    struct object_indirect2 *unk40;
    s16 unk68;
    s16 pad70;
    s32 pad72;
    u8 unk76;
};

struct object_indirect2 {
    s16 unk0;
};


#endif /* _OBJECT_H */
