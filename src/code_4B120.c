#include "common.h"

extern void *data_1881C40_ROM_START;
extern void *data_1A56870_ROM_START;

extern u8 D_800D09A8;

struct str800D5298 {
    s32 unk0;
    s32 unk4;
    void *unk8; // mbf0 rom
    void *unkC; // sbf0 rom
    void *unk10; // fxd0 rom
    void *unk14; // audio ram location?
    s32 unk18; // audio ram size?
    s32 unks1C24[3];
    s32 unk28;
    s32 unk2C;
    s32 unks3040[5];
    s32 unk44;
    s32 unks4858[5];
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
};
extern struct str800D5298 D_800D5298;

INCLUDE_ASM(s32, "code_4B120", func_8004A520);

INCLUDE_ASM(s32, "code_4B120", func_8004A5C4);

INCLUDE_ASM(s32, "code_4B120", func_8004A650);

INCLUDE_ASM(s32, "code_4B120", func_8004A670);

INCLUDE_ASM(s32, "code_4B120", func_8004A72C);

INCLUDE_ASM(s32, "code_4B120", func_8004A7C4);

INCLUDE_ASM(s32, "code_4B120", func_8004A880);

INCLUDE_ASM(s32, "code_4B120", func_8004A918);

INCLUDE_ASM(s32, "code_4B120", func_8004A950);

INCLUDE_ASM(s32, "code_4B120", func_8004A994);

INCLUDE_ASM(s32, "code_4B120", func_8004A9DC);

INCLUDE_ASM(s32, "code_4B120", func_8004AA04);

INCLUDE_ASM(s32, "code_4B120", func_8004AA38);

INCLUDE_ASM(s32, "code_4B120", func_8004AA60);

INCLUDE_ASM(s32, "code_4B120", func_8004AA88);

INCLUDE_ASM(s32, "code_4B120", func_8004AAD0);

INCLUDE_ASM(s32, "code_4B120", func_8004AB0C);

INCLUDE_ASM(s32, "code_4B120", func_8004AB7C);

INCLUDE_ASM(s32, "code_4B120", func_8004ABE8);

INCLUDE_ASM(s32, "code_4B120", func_8004AC10);

INCLUDE_ASM(s32, "code_4B120", func_8004AC5C);

INCLUDE_ASM(s32, "code_4B120", func_8004AC98);

INCLUDE_ASM(s32, "code_4B120", func_8004ACE0);

INCLUDE_ASM(s32, "code_4B120", func_8004AD50);

void func_8004AD70() {
    func_80007DD8(-1);
}

INCLUDE_ASM(s32, "code_4B120", func_8004AD8C);

INCLUDE_ASM(s32, "code_4B120", func_8004ADDC);

INCLUDE_ASM(s32, "code_4B120", func_8004AE00);

INCLUDE_ASM(s32, "code_4B120", func_8004AE28);

INCLUDE_ASM(s32, "code_4B120", func_8004AEF0);

INCLUDE_ASM(s32, "code_4B120", func_8004AFBC);

INCLUDE_ASM(s32, "code_4B120", func_8004B0D4);

INCLUDE_ASM(s32, "code_4B120", func_8004B1AC);

INCLUDE_ASM(s32, "code_4B120", func_8004B25C);

s32 func_8004B2C0() {
    return 0;
}

void func_8004B2C8(void) {
    struct str800D5298 *temp;

    func_80000EA8(&D_800D5298);

    temp = &D_800D5298;
    temp->unk28 = 1;
    D_800D5298.unk8 = &data_1881C40_ROM_START;
    D_800D5298.unkC = &data_1A56870_ROM_START;

    func_8000086C(temp);

    if ((D_800D09A8 & 1) == 0) {
        func_80000F30(0);
    }
    else {
        func_80000F30(1);
    }
}
