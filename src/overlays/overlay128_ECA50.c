#include "common.h"
#include "../object.h"
#include "../heap_temporary.h"

struct strD_800D03F8 {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s32 padC0[0xBC];
};

extern struct strD_800D03F8 *D_800D03F8[];

struct strfunc_800D90C8_ECCE8 {
    s32 file;
    s32 shadowFile;
    f32 unk8;
    f32 unk12;
};

extern struct strfunc_800D90C8_ECCE8 D_80100850[]; // model info

// 000200A2 00000009 3F666666 3F4CCCCD
// 000300A2 00000009 3F666666 3F4CCCCD
// 000700A2 00000009 3F666666 3F8CCCCD
// 000400A2 00000009 3F666666 3F800000
// 000500A2 00000009 3F666666 3F800000
// 000600A2 00000009 3F666666 3FB33333
// 000800A2 00000009 3F666666 3F4CCCCD
// 00090003 00000009 3F666666 3F8CCCCD
// 000A002D 00000009 3F333333 3FB33333
// 000A0000 00000009 3F800000 3F800000
// 000A00C4 00000009 3F800000 3FC00000
// 000A00CE 00000009 3F000000 00000000
// 000A00A5 00000009 3F800000 3F800000
// 000A00E7 0013025F 3F800000 40000000
// 000200A0 00000009 3F800000 3F666666
// 000300A0 00000009 3F800000 3F666666
// 000700A0 00000009 3F800000 3F99999A
// 000400A0 00000009 3F800000 3F8CCCCD
// 000500A0 00000009 3F800000 3F8CCCCD
// 000600A0 00000009 3F800000 3FC00000
// 000800A0 00000009 3F800000 3F666666
// 00090000 00000009 3F800000 3F99999A
// 00130145 00000009 3F800000 00000000
// 001301CB 00000009 3F800000 00000000
// 000A0022 00000009 3F99999A 3F333333
// 001301CA 00000009 3E800000 00000000
// 001301CC 00000009 3F800000 00000000
// 000A0000 00000009 3F800000 00000000
// 000B000D 00000009 3F800000 00000000
// 000A00FF 00000009 3F99999A 3F333333
// 00130158 00000009 3F800000 00000000
// 00130200 00000009 3F800000 00000000
// 001301ED 00000009 3F800000 00000000
// 001301EE 00000009 3F800000 00000000
// 000B0026 00000009 3F800000 00000000
// 000A004B 00000009 3F333333 3FB33333
// 001301F9 00000009 3F800000 00000000
// 001301F4 00000009 3F800000 00000000
// 00130162 00000009 3F800000 00000000
// 00130167 00000009 3F800000 00000000
// 0013016E 00000009 3F800000 00000000
// 00130175 00000009 3F800000 00000000
// 0013017F 00000009 3F800000 00000000
// 00130183 00000009 3F800000 00000000
// 000A005B 00000009 3F800000 3F800000
// 00130161 00000009 3F800000 00000000
// 00130166 00000009 3F800000 00000000
// 00130164 00000009 3F800000 40000000
// 00130157 00000009 3F800000 00000000
// 0013015A 00000009 3F800000 00000000
// 00130155 00000009 3F800000 00000000
// 00130159 00000009 3F800000 00000000
// 00130156 00000009 3F800000 00000000
// 000A008E 00000009 3F800000 00000000
// 00330008 00000009 40A00000 00000000
// 00000083 00000009 40000000 00000000
// 00000084 00000009 40000000 00000000
// 000A00EE 00000009 3F800000 3F800000
// 000A0122 00000009 40000000 40400000
// 000A0075 00000009 3F800000 00000000
// 001301F5 00000009 3F800000 40400000
// 001301FA 00000009 3F800000 00000000
// 000A0063 00000009 3FC00000 00000000
// 001301F0 00000009 3F800000 00000000
// 001301F1 00000009 3F800000 00000000
// 00130201 00000009 3F000000 00000000
// 00130202 00000009 3F000000 00000000
// 001301F2 00000009 3F800000 00000000
// 001301F3 00000009 3F800000 00000000
// 000B0006 00000009 40A00000 00000000
// 000B003A 00000009 3F800000 00000000
// 00130172 00000009 3F800000 00000000
// 00130173 00000009 3F800000 00000000
// 00130174 00000009 3F800000 00000000
// 00130170 00000009 3F666666 00000000
// 00130171 00000009 3F666666 00000000
// 00130181 00000009 3F800000 00000000
// 00130182 00000009 3F800000 00000000
// 0013018D 00000009 3F800000 00000000

extern struct object *D_80102AB0;
extern u16 D_80102AB4;
extern u16 D_80102AB8[];

extern void func_80089A10(void *, f32, f32, f32);

extern struct object *func_800D912C_ECD4C(s32 file, s32 shadowFile, f32 arg2, f32 arg3, void *arg4);

void func_800D8E30_ECA50() {
    s32 i;

    for (i = 0; i < 0x80; i++) {
        D_80102AB8[i] = 0;
    }
}

s16 func_800D8E60_ECA80(s16 arg0) {
    D_80102AB8[arg0]++;
    return arg0;
}

s16 func_800D8E88_ECAA8(s32 mainfs_df) {
    s16 temp_v0;

    temp_v0 = func_8001F1FC(ReadMainFS(mainfs_df), 8);
    D_80102AB8[temp_v0]++;
    return temp_v0;
}

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8ED4_ECAF4);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8F30_ECB50);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8F80_ECBA0);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8FC4_ECBE4);

struct object *func_800D9004_ECC24() {
    struct object *obj;
    struct object *lastobj;

    obj = (struct object *)MallocTemp(sizeof(struct object));
    if (obj != NULL) {
        D_80102AB4++;
        lastobj = D_80102AB0;
        obj->prev = lastobj;
        obj->next = NULL;
        if (lastobj != NULL) {
            lastobj->next = obj;
        }
        D_80102AB0 = obj;
        obj->unkA = 8;
        func_80089A10(&(obj->coords), 0, 0, 0);
        func_80089A10(&(obj->unk18), 0, 0, 1.0f);
        func_80089A10(&(obj->unk24), 1.0f, 1.0f, 1.0f);
        obj->unk30 = 0;
        obj->unk34 = 0;
        obj->unk38 = 0;
        obj->unk44 = -1;
        obj->unk46 = -1;
    }
    return obj;
}

// creates model object
struct object *func_800D90C8_ECCE8(u8 arg0, void *arg1) {
    struct object *ret;

    ret = func_800D912C_ECD4C(
        D_80100850[arg0].file,
        D_80100850[arg0].shadowFile,
        D_80100850[arg0].unk8,
        D_80100850[arg0].unk12,
        arg1
    );
    ret->unk8 = arg0;
    return ret;
}

INCLUDE_ASM(struct object *, "overlays/overlay128_ECA50", func_800D912C_ECD4C, s32 file, s32 shadowFile, f32 arg2, f32 arg3, void *arg4);
// Loads a model from a given file. Also creates a shadow if given.
// struct object *func_800D912C_ECD4C(s32 file, s32 shadowFile, f32 arg2, f32 arg3, void *arg4) {
//     s16 temp_s0;
//     s16 temp_s0_2;
//     s16 temp_s0_3;
//     s16 temp_v0_4;
//     u16 temp_s4;
//     struct strD_800D03F8 *temp_a0;
//     struct object *temp_v0;
//     void *temp_v0_2;
//     struct object_indirect3 *temp_v0_3;
//     void *temp_v0_5;
//     struct object_indirect3 *temp_v0_6;
//     s16 phi_s4;
//     u32 *phi_s2;
//     s16 phi_s0;
//     s32 phi_v1;

//     temp_v0 = func_800D9004_ECC24();
//     if (temp_v0 != NULL) {
//         temp_v0->unk8 = 0xFF;
//         phi_s4 = 0;
//         phi_s2 = arg4;
//         if (arg4 != NULL) {
//             phi_s4 = arg4->unk2;
//             phi_s2 = arg4 + 4;
//         }
//         temp_v0_2 = func_80047620(0x4000, 1, phi_s4 & 0xFFFF, -1, func_800D93C0_ECFE0);
//         temp_v0->unk3C = temp_v0_2;
//         temp_s0 = func_8000B108(file, 0x6A9);
//         func_80047B38(temp_v0_2, 0x80); // ORs arg 2 into temp_v0_2->unk0
//         *temp_v0_2->unk40 = temp_s0;
//         func_80047BEC(temp_v0_2, 0, 0, 0);
//         func_8001C814(temp_s0, 2, 2);
//         func_8001C8A8(temp_s0, 1);
//         func_8001C1A0(temp_s0, 0, 0, 0);
//         temp_a0 = &D_800D03F8[temp_s0];
//         if (temp_a0->unk2 != 0xFF) {
//             temp_v0->unk44 = func_800D8E60_ECA80(temp_a0->unk2);
//         }
//         temp_v0_3 = (struct object_indirect3 *)MallocTemp(sizeof(struct object_indirect3));
//         temp_v0_2->unk5C = temp_v0_3;
//         temp_v0_3->unk0 = temp_v0;
//         temp_v0_3->unk4 = arg2;

//         if ((phi_s4 << 0x10) > 0) {
//             phi_s0 = (u16)0;
// loop_7:
//             *(((s32) (phi_s0 << 0x10) >> 0xF) + temp_v0_2->unk30) = func_800D8E88_ECAA8(*phi_s2);
//             temp_v0_4 = phi_s0 + 1;
//             temp_s0_2 = temp_v0_4;
//             phi_s2 = phi_s2 + 4;
//             phi_s0 = temp_s0_2;
//             if ((s32) temp_v0_4 < phi_s4) {
//                 goto loop_7;
//             }
//         }
//         phi_v1 = 1;
//         if (!(0.0f < arg3)) {
//             phi_v1 = 0;
//         }
//         if ((((u32) ~shadowFile >> 0x1F) & phi_v1) != 0) {
//             temp_v0_5 = func_80047620(0x4000, 1, 0, -1, func_800D95D0_ED1F0);
//             temp_v0->unk40 = temp_v0_5;
//             temp_s0_3 = func_8000B108(shadowFile, 0x229);
//             func_80047B38(temp_v0_5, 0x80);
//             *temp_v0_5->unk40 = temp_s0_3;
//             func_80047BEC(temp_v0_5, 0, 0, 0);
//             func_8001C8A8(temp_s0_3, 1);
//             func_8001C1A0(temp_s0_3, 0, 0, 0);
//             temp_v0_6 = (struct object_indirect3 *)MallocTemp(sizeof(struct object_indirect3));
//             temp_v0_5->unk5C = temp_v0_6;
//             temp_v0_6->unk0 = temp_v0;
//             temp_v0_6->unk4 = arg3;
//         }
//         else {
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

void func_800D9A40_ED660(struct object *obj) {
    obj->unkA |= 8;
}

struct object_indirect *func_800D9A50_ED670(struct object *obj) {
    struct object_indirect *temp_v0;
    struct object_indirect *phi_return;

    func_8001C258(obj->unk3C->unk40->unk0, 4, 0);
    temp_v0 = obj->unk40;
    phi_return = temp_v0;
    if (temp_v0 != NULL) {
        phi_return = func_8001C258(temp_v0->unk40->unk0, 4, 0);
    }
    return phi_return;
}

void func_800D9AA4_ED6C4(struct object *obj) {
    func_800D9A50_ED670(obj);
    func_800D9A40_ED660(obj);
}

struct object_indirect *func_800D9AD0_ED6F0(struct object *obj) {
    struct object_indirect *temp_v0;
    struct object_indirect *phi_return;

    func_8001C258(obj->unk3C->unk40->unk0, 4, 4);
    temp_v0 = obj->unk40;
    phi_return = temp_v0;
    if (temp_v0 != NULL) {
        phi_return = func_8001C258(temp_v0->unk40->unk0, 4, 4);
    }
    return phi_return;
}

void func_800D9B24_ED744(struct object *obj) {
    func_800D9AD0_ED6F0(obj);
    obj->unkA &= 0xFFF7;
}

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
