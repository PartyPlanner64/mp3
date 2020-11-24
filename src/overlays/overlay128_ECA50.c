#include "common.h"
#include "../object.h"
#include "../heap_temporary.h"

struct strfunc_800D90C8_ECCE8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unk12;
};

extern struct strfunc_800D90C8_ECCE8 D_80100850[]; // model info

extern u16 D_80102AB4;

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8E30_ECA50);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8E60_ECA80);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8E88_ECAA8);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8ED4_ECAF4);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8F30_ECB50);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8F80_ECBA0);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8FC4_ECBE4);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9004_ECC24);
// void *func_800D9004_ECC24() {
//     void *temp_s0;
//     void *temp_v0;

//     temp_s0 = MallocTemp(0x48);
//     if (temp_s0 != NULL) {
//         D_80102AB4 = D_0x80102AB4 + 1;
//         temp_v0 = D_80102AB0;
//         temp_s0->unk0 = temp_v0;
//         temp_s0->unk4 = 0;
//         if (temp_v0 != 0) {
//             temp_v0->unk4 = temp_s0;
//         }
//         D_80102AB0 = temp_s0;
//         temp_s0->unkA = (u16)8;
//         func_80089A10(temp_s0 + 0xC, 0, 0, 0);
//         func_80089A10(temp_s0 + 0x18, 0, 0, 0x3F800000);
//         func_80089A10(temp_s0 + 0x24, 0x3F800000, 0x3F800000, 0x3F800000);
//         temp_s0->unk48 = 0;
//         temp_s0->funk52 = 0;
//         temp_s0->funk56 = 0;
//         temp_s0->unk44 = -1;
//         temp_s0->unk70 = -1;
//     }
//     return temp_s0;
// }

// creates model object
struct object *func_800D90C8_ECCE8(u8 arg0, void *arg1) {
    struct object *ret;

    ret = func_800D912C_ECD4C(
        D_80100850[arg0].unk0,
        D_80100850[arg0].unk4,
        D_80100850[arg0].unk8,
        D_80100850[arg0].unk12,
        arg1
    );
    ret->unk8 = arg0;
    return ret;
}

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D912C_ECD4C);
// void *func_800D912C_ECD4C(s32 arg0, ? arg1, f32 arg2, f32 arg3, void *arg4) {
//     s16 temp_s0;
//     s16 temp_s0_2;
//     s16 temp_s0_3;
//     s16 temp_v0_4;
//     u16 temp_s4;
//     void *temp_a0;
//     void *temp_v0;
//     void *temp_v0_2;
//     void *temp_v0_3;
//     void *temp_v0_5;
//     void *temp_v0_6;
//     s16 phi_s4;
//     void *phi_s2;
//     s16 phi_s0;
//     s32 phi_v1;

//     temp_v0 = func_800D9004_ECC24();
//     if (temp_v0 != 0) {
//         temp_v0->unk8 = (u8)0xFF;
//         phi_s4 = (u16)0;
//         phi_s2 = arg4;
//         if (arg4 != 0) {
//             temp_s4 = arg4->unk2;
//             phi_s4 = (s16) temp_s4;
//             phi_s2 = arg4 + 4;
//         }
//         temp_v0_2 = func_80047620(0x4000, 1, phi_s4 & 0xFFFF, -1, 0x800D93C0);
//         temp_v0->unk3C = temp_v0_2;
//         temp_s0 = func_8000B108(arg0, 0x6A9);
//         func_80047B38(temp_v0_2, 0x80);
//         *temp_v0_2->unk40 = temp_s0;
//         func_80047BEC(temp_v0_2, 0, 0, 0);
//         temp_s0 = temp_s0;
//         func_8001C814(temp_s0, 2, 2);
//         func_8001C8A8(temp_s0, 1);
//         func_8001C1A0(temp_s0, 0, 0, 0);
//         temp_a0 = (temp_s0 * 0xC0) + D_800D03F8;
//         if (temp_a0->unk2 != 0xFF) {
//             temp_v0->unk44 = func_800D8E60_ECA80(temp_a0->unk2);
//         }
//         temp_v0_3 = MallocTemp(8);
//         temp_v0_2->unk5C = temp_v0_3;
//         temp_v0_3->unk0 = temp_v0;
//         temp_v0_3->unk4 = arg2;
//         if ((phi_s4 << 0x10) > 0) {
//             phi_s0 = (u16)0;
// loop_7:
//             *(((s32) (phi_s0 << 0x10) >> 0xF) + temp_v0_2->unk48) = func_800D8E88_ECAA8(*phi_s2);
//             temp_v0_4 = phi_s0 + 1;
//             temp_s0_2 = temp_v0_4;
//             phi_s2 = phi_s2 + 4;
//             phi_s0 = temp_s0_2;
//             if ((s32) temp_v0_4 < (s32) phi_s4) {
//                 goto loop_7;
//             }
//         }
//         phi_v1 = 1;
//         if (!(0.0f < arg3)) {
//             phi_v1 = 0;
//         }
//         if ((((u32) ~arg1 >> 0x1F) & phi_v1) != 0) {
//             temp_v0_5 = func_80047620(0x4000, 1, 0, -1, 0x800D95D0);
//             temp_v0->unk40 = temp_v0_5;
//             temp_s0_3 = func_8000B108(arg1, 0x229);
//             func_80047B38(temp_v0_5, 0x80);
//             *temp_v0_5->unk40 = temp_s0_3;
//             func_80047BEC(temp_v0_5, 0, 0, 0);
//             temp_s0_3 = temp_s0_3;
//             func_8001C8A8(temp_s0_3, 1);
//             func_8001C1A0(temp_s0_3, 0, 0, 0);
//             temp_v0_6 = MallocTemp(8);
//             temp_v0_5->unk5C = temp_v0_6;
//             temp_v0_6->unk0 = temp_v0;
//             temp_v0_6->unk4 = arg3;
//         } else {
//             temp_v0->unk40 = NULL;
//         }
//     }
//     return temp_v0;
// }

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D93C0_ECFE0);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D95C4_ED1E4);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D95D0_ED1F0);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9714_ED334);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D975C_ED37C);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9A40_ED660);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9A50_ED670);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9AA4_ED6C4);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9AD0_ED6F0);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9B24_ED744);

// frees model object from func_800D912C_ECD4C
INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9B54_ED774);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9CB0_ED8D0);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9CE8_ED908);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9D84_ED9A4);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9E0C_EDA2C);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9E80_EDAA0);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9ED0_EDAF0);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9F5C_EDB7C);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800DA09C_EDCBC);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800DA190_EDDB0);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800DA748_EE368);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800DA754_EE374);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800DA778_EE398);
