#include "common.h"
#include "../../heap_temporary.h"
#include "../../object.h"
#include "../../player.h"
#include "../../process.h"
#include "../../spaces.h"
#include "../../47D60.h"

// Supporting code for the "direction choice arrows" shown during board play.

struct arrow_instance {
    s16 unk0;
    struct object *obj;
};

struct arrow_state {
    s16 unk0;
    s16 arrowCount;
    struct arrow_instance **arrows;
    struct process *unk8;
    s16 selectedArrowIndex; // 0xC
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
INCLUDE_ASM(struct arrow_instance *, "overlays/shared_board/EA790", func_800D6B70_EA790);
// struct arrow_instance *D_800D6B70_EA790(s32 arg0) {
//     struct arrow_instance *arrow;
//     struct object *obj;

//     // FIXME: there is a static struct copy here

//     arrow = (struct arrow_instance *)MallocTemp(sizeof(struct arrow_instance));
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
void func_800D6C3C_EA85C(struct arrow_instance *arrow) {
    func_800D9B54_ED774(arrow->obj);
    FreeTemp(arrow);
}

struct arrow_state *func_800D6C6C_EA88C() {
    struct arrow_state *arrowState;

    arrowState = (struct arrow_state *)MallocTemp(sizeof(struct arrow_state));
    arrowState->unk0 = 0;
    arrowState->arrowCount = 0;
    arrowState->arrows = NULL;
    arrowState->unk8 = NULL;
    arrowState->selectedArrowIndex = 0;
    arrowState->player = 0;
    return arrowState;
}

// Frees arrow data.
void func_800D6CA0_EA8C0(struct arrow_state *arrowState) {
    struct process *process;
    struct arrow_instance **arrTemp;
    s32 i, count;

    count = arrowState->arrowCount;
    if (count != 0) {
        arrTemp = arrowState->arrows;
        for (i = 0; i < arrowState->arrowCount; i++) {
            func_800D6C3C_EA85C(*arrTemp++);
        }
        FreeTemp(arrowState->arrows);
    }

    process = arrowState->unk8;
    if (process != 0) {
        EndProcess(process);
    }
    FreeTemp(arrowState);
}

// adds an arrow to the arrows state struct.
void func_800D6D2C_EA94C(struct arrow_state *arrowState, struct arrow_instance *arrow, s16 arg2) {
    struct arrow_instance **newArrowPtrs;
    struct arrow_instance **oldArrowPtrs;
    struct arrow_instance **newArrowPtrsTemp;
    struct arrow_instance **oldArrowPtrsTemp;
    s32 i;

    arrowState->arrowCount++;
    newArrowPtrs = (struct arrow_instance **)MallocTemp(arrowState->arrowCount * sizeof(struct arrow_instance *));
    oldArrowPtrs = arrowState->arrows;
    newArrowPtrsTemp = newArrowPtrs;
    if (oldArrowPtrs != NULL) {
        oldArrowPtrsTemp = oldArrowPtrs;
        for (i = 0; i < arrowState->arrowCount - 1; i++) {
            *newArrowPtrsTemp++ = *oldArrowPtrsTemp++;
        }
    }

    *newArrowPtrsTemp = arrow;

    if (arrowState->arrows != NULL) {
        FreeTemp(arrowState->arrows);
    }
    arrowState->arrows = newArrowPtrs;

    arrow->unk0 = arg2;
    if ((arg2 & 1) != 0) {
        arrowState->selectedArrowIndex = arrowState->arrowCount - 1;
    }
}

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6E00_EAA20);

// Gets a particular arrow instance from the state struct.
struct arrow_instance *func_800D6EC8_EAAE8(struct arrow_state *arrowState, s16 index) {
    return arrowState->arrows[index];
}

// jtables
// 800D7048
// 800D7034
// 800D7008
// 800D6FE4
// 800D6FB8
// 800D706C

// 800DA63C
// 800DA1F0
// 800DA20C
// 800DA2AC
// 800DA2BC
// 800DA3F4
// 800DA424
// 800DA440
// 800DA458
// 800DA47C
// 800DA49C
// 800DA4B0
// 800DA530
// 800DA54C
// 800DA588
// 800DA59C
// 800DA5F8
// 00000000
// 800DA2F4
// 800DA31C
// 800DA344
// 800DA370
// 800DA39C
// 800DA3C8

// FIXME: very far off
INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D6EE0_EAB00);
// void D_800D6EE0_EAB00() {
//     f32 temp_f20;
//     f32 temp_f22;
//     f32 temp_f24;
//     s16 temp_s3;
//     s16 temp_v0_4;
//     s32 temp_a2;
//     s32 temp_s0;
//     s32 temp_s0_2;
//     s32 temp_v0_3;
//     u16 temp_s4;
//     u16 temp_v0;
//     u16 temp_v0_2;
//     u32 temp_v1;
//     struct arrow_state *arrowState;
//     s16 phi_s3;
//     s32 phi_s5;
//     u16 phi_v0;
//     s32 phi_v0_2;
//     s32 phi_v0_3;
//     s16 phi_s3_2;
//     f32 phi_f24;
//     f32 phi_f0;
//     f32 phi_f24_2;
//     s16 phi_s4;
//     s16 phi_s0;
//     s32 phi_v0_4;
//     s16 phi_s4_2;
//     f32 phi_f24_3;
//     OSMesg msg;

//     arrowState = GetCurrentProcess()->user_data;
//     phi_s3 = -1;
//     phi_s5 = 0;
//     phi_s4_2 = arrowState->selectedArrowIndex;
//     phi_f24_3 = 0.0f;

//     while (TRUE) {
//         SleepVProcess();
//         phi_v0_3 = phi_s4_2 << 0x10;
//         phi_s3_2 = phi_s3;
//         phi_f24 = phi_f24_3;
//         phi_s4 = phi_s4_2;
//         if (phi_s3 & 0x8000) {
//             if (phi_s5 != 0) {
//                 phi_s5--;
//             }
//             else {
//                 if (osRecvMesg(arrowState->unk10, &msg, 0) == -1) {

//                 }
//                 if ((arrowState->unk0 & 1) != 0) {
//                     phi_s5 = 8;
//                 }
//             }

//             switch ((s32)msg) {
//                 case -2:
//                     arrowState->selectedArrowIndex++;
//                     if (arrowState->selectedArrowIndex >= arrowState->arrowCount) {
//                         arrowState->selectedArrowIndex = 0;
//                     }
//                     break;

//                 case -1:
//                     break;

//                 case -3:
//                     arrowState->selectedArrowIndex--;
//                     phi_s3_2 = phi_s3;
//                     if (arrowState->selectedArrowIndex & 0x8000) {
//                         phi_v0 = (u16) arrowState->arrowCount - 1;
//                     }
//                     break;

//                 case -4:
//                     phi_v0_2 = phi_s4_2 << 0x10;
//                     phi_s3_2 = phi_s3;
//                     if ((s32) (s16) arrowState->selectedArrowIndex < 0) {
// block_25:
//                         temp_s0 = phi_v0_2 >> 0x10;
//                         phi_v0_3 = phi_s4_2 << 0x10;
//                         phi_f24 = phi_f24_3;
//                         phi_s4 = phi_s4_2;
//                         if (temp_s0 != (s16) arrowState->selectedArrowIndex) {
//                             func_8004AA88(1);
//                             phi_f24 = phi_f24_3;
//                             if (temp_s0 >= 0) {
//                                 func_80089A10(func_800D6EC8_EAAE8(&arrowState, temp_s0)->obj->unk24, 1.0f, 1.0f, 1.0f);
//                                 phi_f24 = 0.0f;
//                             }
//                             temp_s4 = arrowState->selectedArrowIndex;
//                             phi_v0_3 = temp_s4 << 0x10;
//                             phi_s4 = (s16) temp_s4;
//                         }
// block_29:
//                         phi_f24_3 = phi_f24;
//                         if (phi_v0_3 >= 0) {
//                             phi_f0 = 25.0f;
//                             if ((phi_s3_2 << 0x10) >= 0) {
//                                 phi_f0 = 50.0f;
//                             }
//                             temp_f24 = phi_f24 + phi_f0;
//                             phi_f24_2 = temp_f24;
//                             if (360.0f < temp_f24) {
//                                 phi_f24_2 = temp_f24 - 360.0f;
//                             }
//                             temp_f22 = (func_8008E3F0(phi_f24_2) * 0.3f) + 1.2f;
//                             temp_f20 = (func_8008E3F0(phi_f24_2) * 0.2f) + 1.2f;
//                             func_80089A10(func_800D6EC8_EAAE8(arrowState, phi_s4)->obj + 0x24, temp_f20, 0x3F800000, temp_f22);
//                             phi_f24_3 = phi_f24_2;
//                         }
//                         temp_v0_3 = phi_s3_2 << 0x10;
//                         phi_v0_4 = temp_v0_3;
//                         phi_s3 = phi_s3_2;
//                         if (temp_v0_3 > 0) {
//                             temp_v0_4 = phi_s3_2 - 1;
//                             temp_s3 = temp_v0_4;
//                             if ((s32) arrowState->arrowCount > 0) {
//                                 phi_s0 = (u16)0;
// loop_38:
//                                 if (phi_s0 != phi_s4) {
//                                     temp_a2 = func_800D6EC8_EAAE8(arrowState, phi_s0)->obj + 0x24;
//                                     func_80089AF0(temp_a2, (f32) temp_v0_4 * 0.033333335f, temp_a2);
//                                 }
//                                 temp_s0_2 = phi_s0 + 1;
//                                 phi_s0 = (s16) temp_s0_2;
//                                 if (temp_s0_2 < (s32) arrowState->arrowCount) {
//                                     goto loop_38;
//                                 }
//                             }
//                             phi_v0_4 = temp_s3 << 0x10;
//                             phi_s3 = temp_s3;
//                         }
//                         phi_s4_2 = phi_s4;
//                         if (phi_v0_4 != 0) {
//                             goto loop_1;
//                         }
//                         EndProcess(0);
//                         return;
//                     }
//                     func_8004AA88(3);
//                     D_800CDD58 = (u16)0;
//                     D_800D51F8 = (u16)0;
//                     phi_s3_2 = (u16)0x1E;
//                     goto block_24;

//                 case -5:
//                     func_8004AA88(4);
//                     arrowState->selectedArrowIndex = -1;
//                     phi_s3_2 = (u16)0;
//                     break;

//                 case -6:
//                     arrowState->selectedArrowIndex = -1;
//                     break;
//                 }
//             }
//         }
//         else {
//             if ((s32)msg < arrowState->arrowCount) {
//                 arrowState->selectedArrowIndex = (s32)msg;
//             }
//         }
//         }
//     }

//     EndProcess(NULL);
// }

s32 func_800D7250_EAE70(struct arrow_state *arrowState, OSMesg val) {
    if (arrowState->unk8 != 0) {
        return osSendMesg(&arrowState->unk10, val, 0);
    }
    return -1;
}

INCLUDE_ASM(s32, "overlays/shared_board/EA790", func_800D7280_EAEA0);

s8 func_800D742C_EB04C(struct arrow_state *arrowState, s16 playerIndex, s32 arg2) {
    struct player *player;
    struct process *process;

    if (arrowState->unk8 == NULL) {
        process = InitProcess(func_800D6EE0_EAB00, 0xEFFF, 0x1000, 0);
        arrowState->unk8 = process;
        process->user_data = arrowState;
        osCreateMesgQueue(&arrowState->unk10, &arrowState->unk28, 16);
        arrowState->unk0 = arg2 | arrowState->unk0;
        player = GetPlayerStruct(playerIndex);
        if ((player->flags & 1) != 0) {
            arrowState->unk0 = arrowState->unk0 | 1;
            func_800D7250_EAE70(arrowState, -1);
        }
        else {
            arrowState->unkE = player->controller;
            InitProcess(func_800D7280_EAEA0, 0xEFFF, 0x1000, 0)->user_data = arrowState;
        }
        return player->flags & 1;
    }
    return -1;
}

// Ends the arrow process and returns the current selected index.
s16 func_800D7518_EB138(struct arrow_state *arrowState) {
    if (arrowState->unk8 != 0) {
        LinkChildProcess(GetCurrentProcess(), arrowState->unk8);
        WaitForChildProcess();
        arrowState->unk8 = 0;
    }
    return arrowState->selectedArrowIndex;
}

void func_800D7568_EB188(struct arrow_instance *arrow, struct coords_3d *arg1, struct coords_3d *arg2, f32 arg3) {
    struct coords_3d coords;
    func_800ECB58_100778(arg1, arg2, &coords);
    func_80089A20(&arrow->obj->unk18, &coords);
    func_80089AF0(&coords, arg3, &coords);
    func_80089A70(&arrow->obj->coords, &coords, arg1);
}

// shows arrows pointing from player to each space in list.
// space list end is signaled by -1.
struct arrow_state *func_800D75E8_EB208(s16 playerIndex, s16 *spaceIndices, s32 arg2) {
    struct arrow_instance *arrow;
    struct arrow_state *arrowState;
    struct player *player;

    player = GetPlayerStruct(playerIndex);
    arrowState = func_800D6C6C_EA88C();
    arrowState->player = player;
    while (*spaceIndices >= 0) {
        arrow = func_800D6B70_EA790(arg2);
        func_800D7568_EB188(arrow, &player->obj->coords, &(GetSpaceData(*spaceIndices)->coords), 18.0f);
        func_800D6D2C_EA94C(arrowState, arrow, 0);
        spaceIndices++;
    }
    return arrowState;
}

struct arrow_state *func_800D76A0_EB2C0(s16 playerIndex, s16 *spaceIndices, s32 arg2) {
    return func_800D75E8_EB208(playerIndex, spaceIndices, 0);
}
