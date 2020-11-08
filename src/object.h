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
    /*0x08*/ s8 pad1[2];
    /*0x0A*/ u16 unka;

    /*0x0C*/ struct coords_3d coords;

    /*0x18*/ f32 rot1;
    f32 rot2;
    f32 rot3;

    /*0x24*/ f32 unk36;
    f32 unk40;
    f32 unk44;

    /*0x30*/ f32 unk48;
    f32 funk52;
    f32 funk56;

    struct object_indirect *unk60;
    void *unk64;
    s8 pad5[2];
    s16 unk70;
};

// Is this really just object? What is up with unk60?
struct object_indirect {
    s8 pad[24];

    /*0x18*/ f32 rot1;
    f32 rot2;
    f32 rot3;

    /*0x24*/ f32 unk36;
    f32 unk40;
    f32 unk44;

    /*0x30*/ f32 unk48;
    f32 funk52;
    f32 funk56;

    u16 unk60;
    struct object_indirect2 *unk64;
    s16 unk68;
    s16 pad70;
    s32 pad72;
    u8 unk76;
};

struct object_indirect2 {
    s16 unk0;
};


#endif /* _OBJECT_H */
