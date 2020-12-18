#include "common.h"
#include "../../heap_temporary.h"
#include "../../object.h"
#include "../../player.h"
#include "../../process.h"
#include "../../spaces.h"
#include "../../code_47D60.h"

// Supporting code for the "direction choice arrows" shown during board play.

struct unkArrowInstance {
    s16 unk0;
    struct object *obj;
};

struct unkArrows {
    s16 unk0;
    s16 unk2; // count?
    struct unkArrowInstance **unk4;
    struct process *unk8;
    s16 unkC;
    s16 unkE; // controller
    OSMesgQueue *unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 unks[56];
    struct player *player; // 0x68
}; // sizeof 0x6C

extern void func_80089AF0(struct coords_3d *, f32, struct coords_3d *);

// allocate individual arrow
INCLUDE_ASM(struct unkArrowInstance *, "overlays/shared_board/EA790", func_800D6B70_EA790);
// struct unkArrowInstance *func_800D6B70_EA790(s32 arg0) {
//     struct unkArrowInstance *arrow;
//     struct object *obj;

//     // FIXME: there is a static struct copy here

//     arrow = (struct unkArrowInstance *)MallocTemp(sizeof(struct unkArrowInstance));
//     arrow->unk0 = 0;
//     obj = func_800D90C8_ECCE8(arg0 /*((arg0 * 4) + &subroutine_arg4)->unk3 */, 0);
//     arrow->obj = obj;
//     func_8001C258(obj->unk3C->unk40->unk0, 0x180, 0);
//     func_8001C8E4(arrow->obj->unk3C->unk40->unk0, 0x1400);
//     func_8001C448(arrow->obj->unk3C->unk40->unk0);
//     func_800D9714_ED334(arrow->obj);
//     return arrow;
// }

// frees an individual arrow
void func_800D6C3C_EA85C(struct unkArrowInstance *arrow) {
    func_800D9B54_ED774(arrow->obj);
    FreeTemp(arrow);
}

struct unkArrows *func_800D6C6C_EA88C() {
    struct unkArrows *unkArrows;

    unkArrows = (struct unkArrows *)MallocTemp(sizeof(struct unkArrows));
    unkArrows->unk0 = 0;
    unkArrows->unk2 = 0;
    unkArrows->unk4 = NULL;
    unkArrows->unk8 = NULL;
    unkArrows->unkC = 0;
    unkArrows->player = 0;
    return unkArrows;
}

// Frees arrow data.
void func_800D6CA0_EA8C0(struct unkArrows *unkArrows) {
    struct process *process;
    struct unkArrowInstance **arrTemp;
    s32 i, count;

    count = unkArrows->unk2;
    if (count != 0) {
        arrTemp = unkArrows->unk4;
        for (i = 0; i < unkArrows->unk2; i++) {
            func_800D6C3C_EA85C(*arrTemp++);
        }
        FreeTemp(unkArrows->unk4);
    }

    process = unkArrows->unk8;
    if (process != 0) {
        EndProcess(process);
    }
    FreeTemp(unkArrows);
}

// adds an arrow to the arrows state struct.
void func_800D6D2C_EA94C(struct unkArrows *unkArrows, struct unkArrowInstance *arrow, s16 arg2) {
    struct unkArrowInstance **newArrowPtrs;
    struct unkArrowInstance **oldArrowPtrs;
    struct unkArrowInstance **newArrowPtrsTemp;
    struct unkArrowInstance **oldArrowPtrsTemp;
    s32 i;

    unkArrows->unk2++;
    newArrowPtrs = (struct unkArrowInstance **)MallocTemp(unkArrows->unk2 * sizeof(struct unkArrowInstance *));
    oldArrowPtrs = unkArrows->unk4;
    newArrowPtrsTemp = newArrowPtrs;
    if (oldArrowPtrs != NULL) {
        oldArrowPtrsTemp = oldArrowPtrs;
        for (i = 0; i < unkArrows->unk2 - 1; i++) {
            *newArrowPtrsTemp++ = *oldArrowPtrsTemp++;
        }
    }

    *newArrowPtrsTemp = arrow;

    if (unkArrows->unk4 != NULL) {
        FreeTemp(unkArrows->unk4);
    }
    unkArrows->unk4 = newArrowPtrs;

    arrow->unk0 = arg2;
    if ((arg2 & 1) != 0) {
        unkArrows->unkC = unkArrows->unk2 - 1;
    }
}

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6E00_EAA20);

// Gets a particular arrow instance from the state struct.
struct unkArrowInstance *func_800D6EC8_EAAE8(struct unkArrows *unkArrows, s16 index) {
    return unkArrows->unk4[index];
}

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6EE0_EAB00);

s32 func_800D7250_EAE70(struct unkArrows *unkArrows, OSMesg val) {
    if (unkArrows->unk8 != 0) {
        return osSendMesg(&unkArrows->unk10, val, 0);
    }
    return -1;
}

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D7280_EAEA0);

//INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D742C_EB04C);
s8 func_800D742C_EB04C(struct unkArrows *unkArrows, s16 playerIndex, s32 arg2) {
    struct player *player;
    struct process *process;

    if (unkArrows->unk8 == NULL) {
        process = InitProcess(func_800D6EE0_EAB00, 0xEFFF, 0x1000, 0);
        unkArrows->unk8 = process;
        process->user_data = unkArrows;
        osCreateMesgQueue(&unkArrows->unk10, &unkArrows->unk28, 16);
        unkArrows->unk0 = arg2 | unkArrows->unk0;
        player = GetPlayerStruct(playerIndex);
        if ((player->flags & 1) != 0) {
            unkArrows->unk0 = unkArrows->unk0 | 1;
            func_800D7250_EAE70(unkArrows, -1);
        }
        else {
            unkArrows->unkE = player->controller;
            InitProcess(func_800D7280_EAEA0, 0xEFFF, 0x1000, 0)->user_data = unkArrows;
        }
        return player->flags & 1;
    }
    return -1;
}

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D7518_EB138);

void func_800D7568_EB188(struct unkArrowInstance *arrow, struct coords_3d *arg1, struct coords_3d *arg2, f32 arg3) {
    struct coords_3d coords;
    func_800ECB58_100778(arg1, arg2, &coords);
    func_80089A20(&arrow->obj->unk18, &coords);
    func_80089AF0(&coords, arg3, &coords);
    func_80089A70(&arrow->obj->coords, &coords, arg1);
}

// shows arrows pointing from player to each space in list.
// space list end is signaled by -1.
struct unkArrows *func_800D75E8_EB208(s16 playerIndex, s16 *spaceIndices, s32 arg2) {
    struct unkArrowInstance *arrow;
    struct unkArrows *unkStruct;
    struct player *player;

    player = GetPlayerStruct(playerIndex);
    unkStruct = func_800D6C6C_EA88C();
    unkStruct->player = player;
    while (*spaceIndices >= 0) {
        arrow = func_800D6B70_EA790(arg2);
        func_800D7568_EB188(arrow, &player->obj->coords, &(GetSpaceData(*spaceIndices)->coords), 18.0f);
        func_800D6D2C_EA94C(unkStruct, arrow, 0);
        spaceIndices++;
    }
    return unkStruct;
}

struct unkArrows *func_800D76A0_EB2C0(s16 playerIndex, void *arg1, s32 arg2) {
    return func_800D75E8_EB208(playerIndex, arg1, 0);
}
