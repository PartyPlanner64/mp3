#include "common.h"
#include "process.h"
#include "object.h"
#include "heap_temporary.h"

extern s8 D_800A1762;
extern struct object_indirect *D_800A1770;
extern s16 D_800A1774;
extern s16 D_800A1776;
extern s16 D_800A1778;

struct str800A177C {
    s16 unk0;
    s16 unk2;
    struct process *process;
    s32 unk8;
};
extern struct str800A177C *D_800A177C;

extern s16 D_800B23C0;

extern f32 D_800CB890;
extern s16 D_800CC430;
extern s16 D_800CCF50;
extern s16 D_800CCF8C;
extern f32 D_800CCF98[];
extern s16 D_800CD050;

struct strCD1E4 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s32 unk8;
    s32 unkC;
};
extern struct strCD1E4 D_800CD1E0[];

extern s8 D_800CD280;

extern s32 D_800D2118;
extern f32 D_800D4198[];
extern f32 D_800D5210;
extern s16 D_800D530C;
extern s16 D_800D5560;
extern s32 D_800D6A40;
extern s8 D_800D6A90;
extern s16 D_800D6B40;

extern void func_80048054();

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
    D_800CD050 = (u16)0x5A;
}

INCLUDE_ASM(s32, "code_47D60", func_80047420);

INCLUDE_ASM(s32, "code_47D60", func_80047620);

INCLUDE_ASM(s32, "code_47D60", func_800477A4);

INCLUDE_ASM(s32, "code_47D60", func_80047898);

INCLUDE_ASM(s32, "code_47D60", func_800479AC);

INCLUDE_ASM(s32, "code_47D60", func_80047B30);

INCLUDE_ASM(s32, "code_47D60", func_80047B38);

INCLUDE_ASM(s32, "code_47D60", func_80047B48);

INCLUDE_ASM(s32, "code_47D60", func_80047B5C);

INCLUDE_ASM(s32, "code_47D60", func_80047B80);

INCLUDE_ASM(s32, "code_47D60", func_80047BAC);

INCLUDE_ASM(s32, "code_47D60", func_80047BDC);

INCLUDE_ASM(s32, "code_47D60", func_80047BEC);

INCLUDE_ASM(s32, "code_47D60", func_80047BFC);

INCLUDE_ASM(s32, "code_47D60", func_80047C0C);

INCLUDE_ASM(s32, "code_47D60", func_80047CDC);

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
        SetProcessDestructor(temp_s0->process, func_80048054);
        temp_s0->unk8 = 0;
        D_800A1776++;
        return temp_s0->process;
    }
    return NULL;
}

INCLUDE_ASM(s32, "code_47D60", func_80047F50);

INCLUDE_ASM(s32, "code_47D60", EndProcess);

// Process destructor used in InitProcess.
INCLUDE_ASM(void, "code_47D60", func_80048054);

INCLUDE_ASM(s32, "code_47D60", func_800480E4);

INCLUDE_ASM(s32, "code_47D60", func_80048128);

INCLUDE_ASM(s32, "code_47D60", func_8004819C);

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

INCLUDE_ASM(s32, "code_47D60", func_800499B0);

INCLUDE_ASM(s32, "code_47D60", func_80049F98);

INCLUDE_ASM(s32, "code_47D60", func_80049FB8);

INCLUDE_ASM(s32, "code_47D60", func_8004A0E0);

INCLUDE_ASM(s32, "code_47D60", func_8004A208);

INCLUDE_ASM(s32, "code_47D60", func_8004A354);

INCLUDE_ASM(s32, "code_47D60", func_8004A444);

INCLUDE_ASM(s32, "code_47D60", func_8004A468);

INCLUDE_ASM(s32, "code_47D60", func_8004A49C);