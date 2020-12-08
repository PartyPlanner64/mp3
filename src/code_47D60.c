#include "common.h"
#include "process.h"

extern s8 D_800A1762;
extern s16 D_800A1774;
extern s16 D_800A1776;
extern s16 D_800A1778;

struct str800A177C {
    s16 unk0;
    s16 unk2;
    struct process *process;
    s32 unk8;
};
extern struct str800A177C *D_800A177C[];

extern s16 D_800B23C0;

extern s16 D_800CD050;
extern s8 D_800CD280;

extern void func_80048054();

INCLUDE_ASM(s32, "code_47D60", func_80047160);

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
        temp_s0 = &(*D_800A177C)[temp_v0];
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
