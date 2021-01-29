#include "common.h"
#include "process.h"
#include "object.h"
#include "heap_temporary.h"
#include "code_47D60.h"

extern s8 D_800A1762;
extern s16 D_800A1768;
extern struct object_indirect *D_800A1770;
extern s16 D_800A1774;
extern s16 D_800A1776;
extern s16 D_800A1778;

struct str800A177C {
    u16 unk0;
    s16 unk2;
    struct process *process;
    s32 unk8;
};
extern struct str800A177C *D_800A177C;

extern s16 D_800A1780;

extern s16 D_800B23C0;

extern f32 D_800CB890;
extern s16 D_800CC430;
extern s16 D_800CCF50;
extern s16 D_800CCF8C;
extern f32 D_800CCF98[];
extern s16 D_800CD050;

struct strCD1E4 {
    s16 unk0;
    u16 unk2;
    s16 unk4;
    s32 unk8;
    s32 unkC;
};
extern struct strCD1E4 D_800CD1E0[];

extern s8 D_800CD280;
extern s16 D_800CD2F4;

extern s16 D_800D0A3A;
extern s8 D_800D1710;
extern s32 D_800D2118;
extern s16 D_800D4082;
extern f32 D_800D4198[];
extern f32 D_800D5210;
extern s16 D_800D530C;
extern s16 D_800D5560;
extern s32 D_800D6A40;
extern s16 D_800D6A56;
extern s8 D_800D6A90;
extern s16 D_800D6B40;

extern void D_80048054();
extern void func_80047CDC(u16 arg0, struct object_indirect *arg1);

void InitObjSys(s32 maxObjects, s16 maxProcesses) {
    s32 i;

    D_800CCF50 = maxObjects + 1;
    D_800CCF8C = 0;
    D_800D6B40 = 0;
    D_800CC430 = -1;
    D_800D5560 = -1;
    D_800D2118 = 0;
    D_800D530C = 0;
    D_800D6A90 = 0;

    {
        void *ptr = D_800A1770;
        if (ptr != NULL) {
            FreeTemp(ptr);
        }
    }

    {
        f32 zero;
        struct object_indirect *objind;

        D_800A1770 = MallocTemp(D_800CCF50 * sizeof(struct object_indirect));

        for (i = 0; i < D_800CCF50; i++) {
            objind = &D_800A1770[i];
            objind->unk0 = 1;
            objind->unk8 = -1;
            objind->unk6 = -1;
            objind->unk4 = -1;
            objind->unk10 = 0;
            zero = 0.0f;
            objind->unk2C = zero;
            objind->unk28 = 0.0f;
            objind->unk24 = 0.0f;
            objind->unk20 = 0.0f;
            objind->unk1C = 0.0f;
            objind->unk18 = 0.0f;
            objind->unk38 = 1.0f;
            objind->unk34 = 1.0f;
            objind->unk30 = 1.0f;
            objind->unk48 = NULL;
            objind->unk40 = NULL;
            objind->unk5C = NULL;
            objind->unk14 = NULL;
            objind->unkA = i + 1;
            objind->unk44 = 0;
            objind->unk48 = NULL;
        }
    }

    for (i = 0; i < 10; i++) {
        D_800CD1E0[i].unk2 = 0;
        D_800CD1E0[i].unk4 = 0;
        D_800CD1E0[i].unk0 = 0;
        D_800CD1E0[i].unkC = 0;
        D_800CD1E0[i].unk8 = 0;
    }

    D_800A1774 = maxProcesses + 2;
    D_800A1776 = 0;
    D_800A1778 = 0;
    D_800A177C = MallocTemp(D_800A1774 * sizeof(struct str800A177C));

    {
        struct str800A177C *str;

        for (i = 0; i < D_800A1774; i++) {
            str = &D_800A177C[i];
            str->unk0 = 1;
            str->unk2 = i + 1;
            str->process = NULL;
            str->unk8 = 0;
        }
    }

    D_800D5210 = 20000.0f;
    D_800CB890 = 10000.0f;

    for (i = 0; i < 4; i++) {
        D_800CCF98[i] = 20000.0f;
        D_800D4198[i] = 10000.0f;
    }

    D_800D6A40 = 0;
    D_800CD050 = 0x5A;
}

void func_80047420() {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s1_3;
    s32 phi_s1;
    s32 phi_s1_2;
    s32 phi_s1_3;
    s32 phi_s1_4;
    s32 i;
    struct object_indirect *objind;
    struct str800A177C *str7c;

    D_800CC430 = -1;
    for (i = 0; i < D_800CCF50; i++) {
        objind = &D_800A1770[i];
        if ((u16)objind->unk0 == 1) {
            phi_s1_2 = phi_s1 + 1;
        }
        else {
            temp_a0 = objind->unk40;
            if (temp_a0 != NULL) {
                FreeTemp(temp_a0);
            }
            temp_a0_2 = objind->unk48;
            if (temp_a0_2 != NULL) {
                FreeTemp(temp_a0_2);
            }
            temp_a0_3 = objind->unk5C;
            temp_s1 = i + 1;
            phi_s1_2 = temp_s1;
            if (temp_a0_3 != NULL) {
                func_80019A98(temp_a0_3);
                phi_s1_2 = temp_s1;
            }
        }
    }
    FreeTemp(D_800A1770);
    D_800A1770 = NULL;
    D_800CCF50 = 0;

    for (i = 0; i < 10; i++) {
        if (D_800CD1E0[i].unk2 != 0) {
            temp_a0_4 = D_800CD1E0[i].unkC;
            if (temp_a0_4 != NULL) {
                FreeTemp(temp_a0_4);
                D_800CD1E0[i].unkC = NULL;
            }
            temp_a0_5 = D_800CD1E0[i].unk8;
            if (temp_a0_5 != 0) {
                FreeTemp(temp_a0_5);
                D_800CD1E0[i].unk8 = NULL;
            }
            D_800CD1E0[i].unk2 = 0;
        }
    }

    for (i = 0; i < D_800A1774; i++) {
        str7c = &D_800A177C[i];
        if (str7c->unk0 != 1) {
            SetProcessDestructor(str7c->process, str7c->unk8);
            KillProcess(str7c->process);
        }
    }
    D_800A1774 = 0;
    D_800A1776 = 0;
    FreeTemp(D_800A177C);
    D_800A177C = NULL;

    func_80019B34(0x7918);
    D_800D6A40 = 0;
}

struct object_indirect *func_80047620(u16 arg0, u16 arg1, u16 arg2, s16 arg3, void *arg4) {
    struct object_indirect *objind;
    s32 i;

    if (D_800CCF8C == D_800CCF50) {
        return NULL;
    }
    objind = &D_800A1770[D_800D6B40];
    objind->unk2 = D_800D6B40;
    objind->unk4 = arg0;
    func_80047898(objind);

    if (arg1 != 0) {
        objind->unk40 = MallocTemp(arg1 * 2);
        objind->unk3C = arg1;
        for (i = 0; i < arg1; i++) {
            *(objind->unk40 + i) = -1;
        }
    }
    else {
        objind->unk40 = NULL;
        objind->unk3C = 0;
    }

    if (arg2 != 0) {
        objind->unk48 = MallocTemp(arg2 * 2);
        objind->unk44 = arg2;
    }
    else {
        objind->unk48 = NULL;
        objind->unk44 = 0;
    }

    if (arg3 >= 0) {
        func_80047CDC(arg3, objind);
    }
    else {
        objind->unkC = arg3;
        objind->unkE = 0;
    }

    objind->unk0 = 4;
    objind->unk10 = 0;
    objind->unk14 = arg4;
    objind->unk58 = 0;
    objind->unk54 = 0;
    objind->unk50 = 0;
    objind->unk4C = 0;
    D_800D6B40 = objind->unkA;
    D_800CCF8C++;
    return objind;
}

INCLUDE_ASM(s32, "code_47D60", func_800477A4);

INCLUDE_ASM(s32, "code_47D60", func_80047898);

INCLUDE_ASM(s32, "code_47D60", func_800479AC);

INCLUDE_ASM(s32, "code_47D60", func_80047B30);

void func_80047B38(struct object_indirect *arg0, s32 arg1) {
    arg0->unk0 |= arg1;
}

void func_80047B48(struct object_indirect *arg0, s32 arg1) {
    arg0->unk0 &= ~arg1;
}

INCLUDE_ASM(s32, "code_47D60", func_80047B5C);

INCLUDE_ASM(s32, "code_47D60", func_80047B80);

INCLUDE_ASM(s32, "code_47D60", func_80047BAC);

INCLUDE_ASM(s32, "code_47D60", func_80047BDC);

INCLUDE_ASM(s32, "code_47D60", func_80047BEC);

INCLUDE_ASM(s32, "code_47D60", func_80047BFC);

INCLUDE_ASM(s32, "code_47D60", func_80047C0C);

INCLUDE_ASM(void, "code_47D60", func_80047CDC, u16 arg0, struct object_indirect *arg1);

INCLUDE_ASM(s32, "code_47D60", func_80047D4C);

INCLUDE_ASM(s32, "code_47D60", func_80047DBC);

INCLUDE_ASM(s32, "code_47D60", func_80047DD4);

INCLUDE_ASM(s32, "code_47D60", func_80047DFC);

INCLUDE_ASM(s32, "code_47D60", func_80047E5C);

INCLUDE_ASM(s32, "code_47D60", func_80047E90);

struct process *InitProcess(void *func, u16 priority, s32 stackSize, s32 extraDataSize) {
    s16 dtorIndex;
    s16 temp_v0;
    struct str800A177C *temp_s0;
    struct process *process;

    if (D_800A1776 != D_800A1774) {
        temp_v0 = D_800A1778;
        dtorIndex = temp_v0;
        temp_s0 = &D_800A177C[temp_v0];
        temp_s0->unk0 = 4;
        D_800A1778 = temp_s0->unk2;
        process = CreateProcess(func, priority, stackSize, extraDataSize);
        temp_s0->process = process;
        process->dtor_idx = dtorIndex;
        SetProcessDestructor(temp_s0->process, D_80048054);
        temp_s0->unk8 = 0;
        D_800A1776++;
        return temp_s0->process;
    }
    return NULL;
}

INCLUDE_ASM(s32, "code_47D60", func_80047F50);

INCLUDE_ASM(s32, "code_47D60", EndProcess);

// Process destructor used in InitProcess.
INCLUDE_ASM(void, "code_47D60", D_80048054);

INCLUDE_ASM(s32, "code_47D60", func_800480E4);

// Changes overlay with some logic beforehand.
s32 func_80048128(s32 arg0, s16 arg1, u16 arg2) {
    struct strD2010 *unkStr;

    if (!(D_800A1768 < 12)) {
        return 0;
    }

    unkStr = &D_800D2010[++D_800A1768];
    unkStr->overlayIndex = arg0;
    unkStr->entrypointIndex = arg1;
    unkStr->unk6 = arg2;
    func_80048228(arg0, arg1, arg2);
    return 1;
}

// Changes overlay with some logic beforehand.
s32 func_8004819C(s32 arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s32 temp_v0_3;

    D_800A1768 -= arg0;
    if (D_800A1768 < 0) {
        D_800A1768 = 0;
        func_80048228(D_800D2010[0].overlayIndex, D_800D2010[0].entrypointIndex, D_800D2010[0].unk6);
        return 0;
    }

    func_80048228(
        D_800D2010[D_800A1768].overlayIndex,
        D_800D2010[D_800A1768].entrypointIndex,
        D_800D2010[D_800A1768].unk6
    );
    return 1;
}

// Changes overlay
INCLUDE_ASM(s32, "code_47D60", func_80048228);

INCLUDE_ASM(s32, "code_47D60", func_80048460);

void func_8004849C() {
    D_800A1762 = 4;
    D_800B23C0 = D_800CD050;
    func_80037190();
    func_8001AFE4();
    func_80021AF4();
    func_80047420();
    func_8000BA00();
    func_800166D0();
    D_800CD280 = 1;
}

INCLUDE_ASM(s32, "code_47D60", func_80048504);

INCLUDE_ASM(s32, "code_47D60", func_80048E88);

INCLUDE_ASM(s32, "code_47D60", func_80048EE8);

INCLUDE_ASM(s32, "code_47D60", D_800499B0);

INCLUDE_ASM(s32, "code_47D60", func_80049F98);

INCLUDE_ASM(s32, "code_47D60", func_80049FB8);

INCLUDE_ASM(s32, "code_47D60", func_8004A0E0);

INCLUDE_ASM(s32, "code_47D60", func_8004A208);

INCLUDE_ASM(s32, "code_47D60", D_8004A354);

void func_8004A444(s8 arg0) {
    D_800A1780 = 1;
    D_800D0A3A = 4;
    D_800D1710 = arg0;
}

void func_8004A468(s16 arg0, s16 arg1, s16 arg2) {
    D_800D4082 = arg0;
    D_800CD2F4 = arg1;
    D_800D6A56 = arg2;
    D_800A1780 = 1;
    D_800D0A3A = 4;
}

INCLUDE_ASM(s32, "code_47D60", func_8004A49C);
