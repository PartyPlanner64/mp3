#include "common.h"
#include "player.h"

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

INCLUDE_ASM(s32, "4B120", func_8004A520);

INCLUDE_ASM(s32, "4B120", func_8004A5C4);

INCLUDE_ASM(s32, "4B120", func_8004A650);

INCLUDE_ASM(s32, "4B120", func_8004A670);

INCLUDE_ASM(s32, "4B120", func_8004A72C);

INCLUDE_ASM(s32, "4B120", func_8004A7C4);

INCLUDE_ASM(s32, "4B120", func_8004A880);

INCLUDE_ASM(s32, "4B120", func_8004A918);

INCLUDE_ASM(s32, "4B120", func_8004A950);

INCLUDE_ASM(s32, "4B120", func_8004A994);

INCLUDE_ASM(s32, "4B120", func_8004A9DC);

INCLUDE_ASM(s32, "4B120", func_8004AA04);

INCLUDE_ASM(s32, "4B120", func_8004AA38);

INCLUDE_ASM(s32, "4B120", func_8004AA60);

INCLUDE_ASM(s32, "4B120", func_8004AA88);

INCLUDE_ASM(s32, "4B120", func_8004AAD0);

INCLUDE_ASM(s32, "4B120", func_8004AB0C);

INCLUDE_ASM(s32, "4B120", func_8004AB7C);

INCLUDE_ASM(s32, "4B120", func_8004ABE8);

INCLUDE_ASM(s32, "4B120", func_8004AC10);

INCLUDE_ASM(s32, "4B120", func_8004AC5C);

INCLUDE_ASM(s32, "4B120", func_8004AC98);

INCLUDE_ASM(s32, "4B120", func_8004ACE0);

INCLUDE_ASM(s32, "4B120", func_8004AD50);

void func_8004AD70() {
    func_80007DD8(-1);
}

INCLUDE_ASM(s32, "4B120", func_8004AD8C);

void func_8004ADDC(s16 arg0) {
    func_80007C80(-1, arg0);
}

void func_8004AE00(s16 arg0, s16 arg1) {
    func_80007C80(arg0, arg1);
}

INCLUDE_ASM(s32, "4B120", func_8004AE28);

INCLUDE_ASM(s32, "4B120", func_8004AEF0);

INCLUDE_ASM(s32, "4B120", func_8004AFBC);

INCLUDE_ASM(s32, "4B120", func_8004B0D4);

INCLUDE_ASM(s32, "4B120", func_8004B1AC);

void func_8004B25C(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if ((gPlayers[arg0].flags & 1) == 0) {
        func_8005A674(gPlayers[arg0].controller, arg1, arg2, arg3);
    }
}

s32 func_8004B2C0() {
    return 0;
}

void func_8004B2C8(void) {
    struct str800D5298 *temp;

    func_80000EA8(&D_800D5298);

    temp = &D_800D5298;
    temp->unk28 = 1;
    D_800D5298.unk8 = &bin_audio_mbf0_ROM_START;
    D_800D5298.unkC = &bin_audio_sbf0_ROM_START;

    func_8000086C(temp);

    if ((D_800D09A8 & 1) == 0) {
        func_80000F30(0);
    }
    else {
        func_80000F30(1);
    }
}
