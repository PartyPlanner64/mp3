#include "common.h"
#include "heap_permanent.h"
#include "process.h"
#include "player.h"

extern u16 D_800A190C;
extern u16 D_800A190E;

extern void *D_800CCF38;
extern u8 D_800CCF78[];
extern f32 D_800CD288[];
extern u16 D_800CD2F4;
extern s32 D_800CDD50;
extern f32 D_800CE1C8;
extern struct process *D_800D0448;
extern u8 D_800D09A8;

struct str800D138C {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
extern struct str800D138C D_800D138C;

extern struct process *D_800D170C;
extern u8 D_800D1710;
extern s16 D_800D1F36;
extern u16 D_800D4082;

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

struct triplefloat {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

struct str800D54F8 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
extern struct str800D54F8 D_800D54F8[];

extern u16 D_800D6A56;

struct str800D6ABC {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

extern struct str800D6ABC D_800D6ABC;

struct str800D6AE0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

extern struct str800D6AE0 D_800D6AE0[];

extern s32 func_8000985C(s16);

extern void func_8000E740();
extern void func_8000E78C();
extern void func_8000E7B8();
extern void func_8000E804();
extern void func_8000E978();

void func_8000E3C0() {
    s32 i;
    f32 zero;
    struct str800D6ABC *loc;

    SleepVProcess();

    func_8004F290();

    D_800D138C.unk0 = 325.0f;
    D_800D138C.unk4 = 0.0f;
    D_800D138C.unk8 = 0.0f;

    D_800CE1C8 = 2250.0f;

    loc = &D_800D6ABC;
    D_800D6ABC.unk8 = D_800D138C.unk4;
    D_800D6ABC.unk4 = D_800D138C.unk4;
    loc->unk0 = D_800D138C.unk4;

    for (i = 0; i < 4; i++) {
        D_800D6AE0[i].unk0 = 325.0f;
        (*(D_800D6AE0 + i)).unk8 = (zero = 0.0f);
        D_800D6AE0[i].unk4 = zero;

        D_800CD288[i] = 2250.0f;

        (*(D_800D54F8 + i)).unk8 = zero;
        (*(D_800D54F8 + i)).unk4 = zero;
        D_800D54F8[i].unk0 = zero;
    }

    D_800D1710 = 3;
    D_800D4082 = 0x1000;
    D_800CD2F4 = 0x2004;
    D_800D6A56 = 0x180;
    func_80061B50();
    func_8001A070(&MallocPerm, &FreePerm, D_800D4082, D_800CD2F4, D_800D6A56, D_800D1710);
    func_80012220(1);
    func_8004DC00();
    func_80036380(&data_1209850_ROM_START); // strings
    D_800D1F36 = 0;

loop_3:
    if (func_8000985C(D_800D1F36) == 0) {
        if (++D_800D1F36 < 4) {
            goto loop_3;
        }
    }

    if (D_800D1F36 == 4) {
        D_800D1F36 = -1;
    }

    GetAllocatedPermHeapSize();
    D_800D0448 = CreateProcess(&func_8000E740, 0xF000, 0x3000, 0);
    CreateProcess(&func_8000E78C, 0x4000, 0x3000, 0);
    D_800D170C = CreateProcess(&func_8000E7B8, 0x1000, 0x3000, 0);

    {
        s32 temp_s0;

        temp_s0 = func_8004FDC0();
        func_80035A50();
        func_8000E978();
        func_80000EA8(&D_800D5298);
        func_80050E78(0);
        func_80050800();
        if (temp_s0 != 0) {
            func_80048128(0x67, 0, 0x82);
        }
        else {
            func_80048128(0x58, 0, 0x84);
        }
    }

    D_800D5298.unk8 = &data_1881C40_ROM_START;
    D_800D5298.unkC = &data_1A56870_ROM_START;
    D_800A190E = 0;
    D_800A190C = 0;
    D_800D5298.unk0 = 0x70418F;
    D_800D5298.unk10 = &data_1EFD040_ROM_START;
    D_800D5298.unk28 = 1;
    D_800D5298.unk2C = 0;
    D_800D5298.unk14 = (void *)0x802E0000;
    D_800D5298.unk18 = 0x80000;
    D_800D5298.unk5C = 0x6E;
    D_800D5298.unk60 = 0;
    D_800D5298.unk64 = 0;
    D_800D5298.unk68 = D_800CDD50;
    D_800D5298.unk44 = 0x3C;
    func_800007FC(&D_800D5298);

    if ((D_800D09A8 & 1) != 0) {
        func_80000F30(1);
    }
    else {
        func_80000F30(0);
    }

    KillProcess(GetCurrentProcess());

    while (TRUE) {
        SleepVProcess();
    }
}

void func_8000E740() {
    while (TRUE) {
        SleepVProcess();
        func_800224BC();
        func_800143F0();
        func_8001BF90(0x2000000, 0x3D0800);
        func_8004DC98();
    }
}

void func_8000E78C() {
    while (TRUE) {
        SleepVProcess();
        func_80048504();
    }
}

void func_8000E7B8() {
    while (TRUE) {
        SleepVProcess();
        GetRandomByte();
        func_8000BA30();
        func_80014A3C(2);
        func_8001B0B4(&D_800CCF38, 2);
    }
}

void func_8000E804() {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80087A40(&gPlayers[i], 0, sizeof(struct player));
        if (func_8000985C(i) != 0) {
            D_800CCF78[i] = 0;
            gPlayers[i].flags &= 0xFE;
        }
        else {
            D_800CCF78[i] = 1;
            gPlayers[i].flags |= 0x01;
        }
        gPlayers[i].controller = i;
        gPlayers[i].coins = 10;
        gPlayers[i].bonus_coins = 0;
        gPlayers[i].id = i;
        gPlayers[i].cpu_difficulty = 0;
        gPlayers[i].stars = 0;
        gPlayers[i].minigame_star = 0;
        gPlayers[i].blue_space_count = 0;
        gPlayers[i].red_space_count = 0;
        gPlayers[i].happening_space_count = 0;
    }
}

void func_8000E978() {
    func_8000E804();
    func_80035C20(0, 0x64);
    func_80035C20(1, 0xE10);
    func_80035C20(2, 0xE10);
    func_80035C20(3, 0x708);
    func_80035C20(4, 0x3E8);
    func_80035C20(5, 0xE10);
    func_80035C20(6, 0xE10);
    func_80035C20(7, 0xE10);
    func_80035C20(8, 0);
    func_80035C20(9, 0x1518);
}
