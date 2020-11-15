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

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8E30_ECA50);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8E60_ECA80);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8E88_ECAA8);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8ED4_ECAF4);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8F30_ECB50);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8F80_ECBA0);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D8FC4_ECBE4);

INCLUDE_ASM(s32, "overlays/overlay128_ECA50", func_800D9004_ECC24);

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
