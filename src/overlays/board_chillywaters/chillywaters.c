#include "common.h"
#include "../../process.h"
#include "../../47D60.h"
#include "../../1A580.h"

struct unkfunc_801059D0 {
    f32 unk0;
    f32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    struct process *unk14;
};

s32 func_80105A64_31B5D4();

void func_801059D0_31B540(s16 arg0, s16 arg1) {
    struct process *process;
    struct unkfunc_801059D0 *temp_v0;

    process = InitProcess(&func_80105A64_31B5D4, 0x3F00U, 0x1000, 0);
    temp_v0 = (struct unkfunc_801059D0 *)HuMemAllocTag(0x18, 0x7918);
    process->user_data = temp_v0;
    temp_v0->unk14 = process;
    temp_v0->unk0 = (f32)arg0;
    temp_v0->unk4 = (f32)arg1;
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80105A64_31B5D4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80105DB8_31B928);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80105E20_31B990);
