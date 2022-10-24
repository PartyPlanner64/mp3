#include "common.h"
#include "../../board.h"
#include "../../player.h"
#include "../../process.h"
#include "../../object.h"
#include "../../spaces.h"

extern s32 D_800A12D4;

extern u8 D_800CB99C;
extern s8 D_800CD067;
extern u16 D_800CD0B4[];
extern s16 D_800CDD58; // used with direction arrows
extern u16 D_800CE198;
extern u16 D_800D037C;
extern u8 D_800D03F8[];
extern s32 D_800D41C0;
extern s16 D_800D51F8; // used with direction arrows

extern s16 D_80105702; // window id

extern void *D_8011A8D8;
extern s32 D_8011E280[];
extern s16 D_8011D2A0_332E10[]; // feature flags for stars
extern s16 D_8011D2B0_332E20[]; // star spaces
extern s16 D_8011D2C0_332E30[]; // toad spaces
extern s32 D_8011D308;
extern struct object *D_8011D314;
extern struct object *D_8011D318;
extern u16 *D_8011D31C_332E8C; // list of hidden block skip spaces.
extern void *D_8011D320;
extern struct coords_3d D_8011D3A0[];
extern f32 *D_8011D3E0;
extern f32 *D_8011D3E8;
extern void *D_8011D578; // ai
extern void *D_8011D77C; // ai
extern void *D_8011DA58; // ai
extern void *D_8011DA84; // spaces
extern void *D_8011DA98; // chains
extern void *D_8011DB5C; // spaces
extern void *D_8011DB70; // chains
extern void *D_8011E010; // spaces
extern void *D_8011E024; // chains
extern void *D_8011E2CC;
extern void *D_8011E344;
extern void *D_8011E4D8;
extern void *D_8011E718;
extern void *D_8011E8B8;
extern f64 D_8011F968;
extern struct process *D_8011FAB8; // related to star tour
extern struct object *D_8011FABC;  // related to star tour
extern void *D_8011FAC0;           // used with direction arrows
extern void *D_8011FAC4;           // used with direction arrows
extern void *D_8011FAC8;           // used with direction arrows
extern void *D_8011FACC;           // used with direction arrows
extern void *D_8011FAD0;           // used with direction arrows
extern void *D_8011FAEC;
extern void *D_8011FB08;
extern void *D_8011FB0C;
extern void *D_8011FB10;
extern void *D_8011FB18[];
extern void *D_8011FB58;
extern s32 D_8011FB68;
extern struct object **D_8011FB98;
extern s32 D_80121D80[];

extern void func_80089A10(void *, f32, f32, f32);
extern f32 func_8008EF20(f32);
extern f32 func_800D8790(struct coords_3d *);
extern u16 func_800D9E0C(struct object *);
extern u16 func_800D9E80(struct object *);
extern void func_800E9730(f32);
extern void func_800E9AC8(f32);
extern f32 func_800EA660(f32);
extern f32 func_800EEF80(f32);
extern void func_800F68E0(s8, s32, s16);

extern s32 func_8010DE7C_3239EC();
extern s32 func_8010F2FC_324E6C();
extern s32 func_8010F6C4_325234();
extern s32 func_8010F730_3252A0();
extern s32 func_80117C60_32D7D0();
extern s32 func_8011093C_3264AC();
extern s32 func_80110BC8_326738();
extern s32 func_8010FC24_325794();
extern s32 func_80110194_325D04();
extern s32 func_801104E0_326050();
extern s32 func_80116F5C_32CACC();
extern s32 func_801177DC_32D34C();
extern s32 func_80111018_326B88();
extern s32 func_801112D8_326E48();
extern s32 func_80111678_3271E8();
extern s32 func_80112074_327BE4();
extern void func_80112BCC_32873C();
extern s32 func_801138E4_329454();
extern s32 func_80114B80_32A6F0();
extern s32 func_80115B80_32B6F0();
extern s32 func_80116DAC_32C91C();
extern s32 func_801176A4_32D214();
extern s32 func_8011C88C_3323FC();
extern s32 func_80118B7C_32E6EC();

// struct space_index_args {
// };

struct chain_args {
    s16 chainl;
    s16 chainr;
    s16 flags;
};

extern s16 GetAbsSpaceIndexFromChainSpaceIndex(u16 chain_index, u16 space_index);

// Get toad space index for current start space index.
s16 func_80105E80_31B9F0() {
    return D_8011D2C0_332E30[D_800CD058.star_spawn_indices[D_800CD058.current_star_spawn]];
}

INCLUDE_ASM(void, "overlays/board_chillywaters/chillywaters2", func_80105EA8_31BA18);

INCLUDE_ASM(void, "overlays/board_chillywaters/chillywaters2", func_80105FB0_31BB20);
// void func_80105FB0_31BB20() {
//     s8 temp_s0;
//     s8 temp_v1;
//     u8 temp_v0;

//     temp_v0 = D_800CD058.current_star_spawn + 1;
//     D_800CD058.current_star_spawn = temp_v0;
//     if (temp_v0 >= 8) {
//         temp_s0 = D_800CD058.unkD;
//         D_800CD058.current_star_spawn = 0;
//         func_80035FDC(4);
//         func_80105EA8_31BA18();
//         temp_v1 = D_800CD058.star_spawn_indices[0];
//         if (temp_s0 == temp_v1) {
//             D_800CD058.star_spawn_indices[0] = D_800CD058.unkE;
//             D_800CD058.unkD = temp_v1;
//         }
//     }
// }

void func_8010603C_31BBAC() {
    s32 i;
    struct strCD058 *loc;
    loc = &D_800CD058;

    for (i = 0; i < 8; i++) {
        func_80035FDC(D_8011D2A0_332E10[i]);
    }
    SetSpaceType(D_8011D2B0_332E20[loc->star_spawn_indices[loc->current_star_spawn]], 0xE);
    func_8003602C(D_8011D2A0_332E10[loc->star_spawn_indices[loc->current_star_spawn]]);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801060E0_31BC50);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80106154_31BCC4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80106544_31C0B4);

// Star tour at start of game.
INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801065D0_31C140);
// void D_801065D0_31C140() {
//     s32 temp_s0;
//     void *temp_s1;
//     s32 msgIdx;
//     struct space_data *spacedata;
//     s32 phi_v0;

//     D_800A12D4 = 0;
//     temp_s1 = func_800E5DD4(0, 0);
//     func_8004A520(0x12);
//     func_800EEFEC(temp_s1->unk0, 2, 0xF, D_8011D2D0);
//     func_800FFF44();
//     func_800D9B24(D_8011FA78[D_800CD058.star_spawn_indices[D_800CD058.current_star_spawn]]);
//     InitFadeIn(2, 0x10);

//     while (GetFadeStatus() != 0) {
//         SleepVProcess();
//     }

//     func_800E6FCC();
//     func_800E9730(3.0f);
//     D_80106544_31C0B4(temp_s1);
//     if ((D_800CD058.current_star_spawn == 0) && (func_80035F98(4) == 0)) {
//         msgIdx = D_800CD058.current_board_index == 2 ? 0x5E09 : 0x5E00;
//     }
//     else {
//         msgIdx = D_800CD058.current_board_index == 2 ? 0x5E09 : 0x5E01;
//     }
//     func_8005B43C(temp_s1->unk8, msgIdx, -1, -1);
//     func_80060C14(temp_s1->unk8, 1);
//     func_8004AA88(0x2A7);
//     func_800EE2C0(temp_s1->unk8);
//     func_800D9D84(temp_s1->unk0, -1, 0, 6, 2);
//     func_80060EA8(temp_s1->unk8, 1);
//     func_8001FDE8(*temp_s1->unk0->unk3C->unk40);
//     if ((D_800CD058.current_board_index != 2) || (phi_s3 = saved_reg_s3, ((GetRandomByte() & 1) != 0))) {
//         spacedata = GetSpaceData(D_8011D2C0[D_800CD058.star_spawn_indices[D_800CD058.current_star_spawn]]);
//     }
//     func_800E9748(&spacedata->coords);
//     func_800E9AC8(5.0f);
//     SleepProcess(5);

//     while (func_800E9AE0() != 0) {
//         SleepVProcess();
//     }

//     SleepProcess(5);
//     temp_s0 = func_800EEF80(7.0f);
//     func_800EF070(temp_s1->unk0, *(&D_8011D2D0 + (temp_s0 * 4)));
//     func_800D9CE8(temp_s1->unk0, -1, 2);
//     if (D_800CD058.current_board_index != 2) {
//         {
//             struct process *process;

//             process = InitProcess(D_80106154_31BCC4, 0x4800, 0, 0);
//             D_8011FAB8 = process;
//             process->user_data = spacedata;
//             SleepProcess(0x1E);
//             phi_v0 = temp_s0 * 4;
//         }
//     }
//     else {
//         D_8011FAB8 = NULL;
//         phi_v0 = temp_s0 * 4;
//     }
//     func_8005B43C(temp_s1->unk8, *(&D_8011D2EC + phi_v0), -1, -1);
//     func_80060C14(temp_s1->unk8, 1);
//     func_800EE2C0(temp_s1->unk8);
//     func_800D9D84(temp_s1->unk0, -1, 0, 6, 2);
//     func_80060EA8(temp_s1->unk8, 1);
//     func_8004A994(0x5A);
//     SleepProcess(0x1E);
//     InitFadeOut(2, 0x10);
//     SleepProcess(0x11);
//     D_800A12D4 = 1;
//     func_80100130();
//     func_80046558(D_8011FABC->unk3C->unk40->unk0);
//     func_800D9B54_ED774(D_8011FABC);
//     func_800D9AA4(D_8011FA78[D_800CD058.star_spawn_indices[D_800CD058.current_star_spawn]]]);
//     func_800E60D8(temp_s1);
//     func_800F8C74();
//     func_8004819C(1);
//     func_8004849C();
//     SleepVProcess();
// }

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010698C_31C4FC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80106EEC_31CA5C);

// View board map
void func_80106F60_31CAD0() {
    D_800CDD58 = 1;
    D_800D037C = 0;
    func_80047B80(GetCurrentProcess(), 0x80);
    func_8010067C(gPlayers[D_800CD058.current_player_index].controller);
    func_80047BAC(GetCurrentProcess(), 0x80);
    D_800CDD58 = 0;
    D_800D037C = 1;
}

// Exit the board map?
void func_80106FE8_31CB58() {
    D_800D037C = 0;
    func_80047B80(GetCurrentProcess(), 0x80);
    func_8010067C(gPlayers[D_800CD058.current_player_index].controller);
    D_800D037C = 1;
}

// setup arrows used during player direction decisions.
void func_80107044_31CBB4() {
    while (func_800E9AE0() != 0) {
        SleepVProcess();
    }
    SleepVProcess();
    D_8011FAC0 = func_800E210C(0, 0x92, 1);
    D_8011FAC4 = func_800E210C(1, 0xA0, 1);
    D_8011FAD0 = func_800E210C(0xD, 0xAE, 1);
    D_8011FAC8 = func_800E210C(3, 0xBC, 1);
    D_8011FACC = func_800E210C(0xB, 0xCA, 1);
    SleepProcess(3);
    D_800CDD58 = 1;
    D_800D51F8 = 1;
}

// teardown arrows
void func_80107114_31CC84() {
    D_800CDD58 = 0;
    D_800D51F8 = 0;
    func_800E21F4(D_8011FAC0);
    func_800E21F4(D_8011FAC4);
    func_800E21F4(D_8011FAD0);
    func_800E21F4(D_8011FAC8);
    func_800E21F4(D_8011FACC);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80107174_31CCE4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80107408_31CF78);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80107620_31D190);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80107750_31D2C0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801078E8_31D458);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80107BB4_31D724);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80107BD4_31D744);

// entrypoint 0
void func_80107BF4_31D764() {
    D_800CD058.current_board_index = 0;
    InitObjSys(10, 0);
    func_80048228(0x47, 0, 0x192);
}

// entrypoint 1
void func_80107C2C_31D79C(void) {
    InitObjSys(10, 0);

    func_800ED91C(0, 0, 0);
    func_800ED91C(1, 0, 0);
    func_800ED91C(2, 0, 0);
    func_800ED91C(3, 0, 0);

    func_80035FDC(3);
    func_80105EA8_31BA18();
    func_8003602C(0x12);

    D_800CD0B4[0] = 0;
    D_800CD0B4[-3] = 0;
    D_800CD0B4[-4] = 0;
    D_800CD0B4[-14] = 0;

    func_8004819C(1);
}

// setup routine
void func_80107CC4_31D834(void) {
    struct space_data *spacedata;
    struct coords_3d subroutine_arg4;

    InitObjSys(0xA0, 0x28);
    func_80019514(1, 0xFF, 0xFF, 0xFF);
    func_80019514(2, 0xC8, 0xC8, 0xC8);
    func_800F89D0(3, 0x23A, 5, 0);
    func_800EBCFC(&D_8011D31C_332E8C);
    func_800EBD54(&D_8011D320);
    spacedata = GetSpaceData(0x77);
    func_800ECB58(&(spacedata->coords), &(GetSpaceData(0x73)->coords), &subroutine_arg4);
    func_800EA660(func_800D8790(&subroutine_arg4) + 180.0f);
    spacedata = GetSpaceData(0x7C);
    func_800ECB58(&(spacedata->coords), &(GetSpaceData(0x6E)->coords), &subroutine_arg4);
    func_800EA660(func_800D8790(&subroutine_arg4) + 180.0f);
    spacedata = GetSpaceData(0x8F);
    func_800ECB58(&(spacedata->coords), &(GetSpaceData(0x80)->coords), &subroutine_arg4);
    func_800EA660(func_800D8790(&subroutine_arg4) + 180.0f);

    func_800E2960(0, func_8010DE7C_3239EC);
    func_800E2960(1, func_8010F2FC_324E6C);
    func_800E2960(9, func_8010F6C4_325234);
    func_800E2960(2, func_8010F730_3252A0);
    func_800E2960(3, func_80117C60_32D7D0);
    func_800E2960(4, func_8011093C_3264AC);
    func_800E2960(5, func_80110BC8_326738);
    func_800E2960(6, func_8010FC24_325794);
    func_800E2960(7, func_80110194_325D04);
    func_800E2960(8, func_801104E0_326050);
    func_800E2960(0xA, func_80116F5C_32CACC);
    func_800E2960(0xB, func_801177DC_32D34C);
    func_800E2960(0xE, func_80111018_326B88);
    func_800E2960(0xF, func_801112D8_326E48);
    func_800E2960(0x10, func_80111678_3271E8);
    func_800E2960(0x11, func_80112074_327BE4);
    func_800E2960(0x12, func_80112BCC_32873C);
    func_800E2960(0x13, func_801138E4_329454);
    func_800E2960(0x14, func_80114B80_32A6F0);
    func_800E2960(0x15, func_80115B80_32B6F0);
    func_800E2960(0xC, func_80116DAC_32C91C);
    func_800E2960(0xD, func_801176A4_32D214);
    func_800DA748(func_8011C88C_3323FC);

    {
        s32 i = 0;
        for (i = 0; i < 8; i++) {
            func_800EA6E0(i, D_8011D2C0_332E30[i]);
        }
    }

    if (func_80035F98(0xE) != 0) {
        func_8003602C(0xE);
        func_80105FB0_31BB20();
    }

    func_8010603C_31BBAC();
    func_80108250_31DDC0();
    func_8010841C_31DF8C();
    func_801086E0_31E250();
    func_801088B4_31E424();
    func_80108B24_31E694();
    func_80108BA4_31E714();
    func_80116AA0_32C610();
    func_800EBDAC();
    InitProcess(func_80118B7C_32E6EC, 0x4800, 0, 0);
}

// entrypoint 2
void func_80108014_31DB84(void) {
    func_8004A520(0x18);
    D_800CE198 = 0x18;
    func_800F8D6C(0x18);
    func_80012220(2);
    func_80107CC4_31D834();
    func_800EBA60(&D_8011E2CC);
    func_800EBA60(&D_8011E718);
    func_800F8D48(&D_8011A8D8);
    func_800EBA60(&D_8011E344);
    func_800EBA60(&D_8011E4D8);
    func_800FF41C(0);
}

// entrypoint 3
void func_80108098_31DC08() {
    func_80012220(1);
    func_80107CC4_31D834();
    func_800FF41C(1);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801080C4_31DC34);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801081EC_31DD5C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108250_31DDC0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801082FC_31DE6C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010841C_31DF8C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108478_31DFE8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108574_31E0E4, s16 arg0);
// void D_80108574_31E0E4(s16 arg0) {
//     void *temp_v0;
//     void *temp_s2;
//     void *temp_s3;
//     struct object *obj;

//     temp_v0 = D_8011FB18[arg0];
//     if (temp_v0 == NULL) {
//         if (D_8011FB10 == NULL) {
//             temp_s3 = func_800D90C8_ECCE8(0x1E, 0);
//             func_800D9714(temp_s3);
//             D_8011FB10 = temp_s3;
//             obj = temp_s3;
//         }
//         else {
//             obj = func_800D975C(D_8011FB10);
//         }
//         D_8011FB18[arg0] = obj;
//         obj->unkA |= 2;
//         func_80089A20(&obj->coords, &(GetSpaceData(arg0)->coords));
//         func_80089A70(&obj->coords, D_8011D3A0[arg0].y, &obj->coords);
//         obj->unk3C->unk24 = D_8011D3E0[arg0];
//         obj->unk3C->unk2C = D_8011D3E8[arg0];
//         func_800D9B24(obj);
//     }
// }

// draw bank coins
void func_801086E0_31E250(void) {
    s32 i;

    D_8011FB10 = NULL;
    for (i = 0; i < 10; i++) {
        D_8011FB18[i] = NULL;
        func_80108574_31E0E4(i);
    }

    func_80108478_31DFE8();
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108748_31E2B8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801088B4_31E424);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108914_31E484);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108970_31E4E0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108A38_31E5A8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108AE8_31E658);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108B24_31E694);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108BA4_31E714);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108C1C_31E78C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108CA4_31E814);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108CC8_31E838);

void func_80108D28_31E898() {
    func_80116484_32BFF4(&D_8011DA84, &D_8011DA98, &D_8011D578);
    EndProcess(NULL);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108D60_31E8D0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108D98_31E908);

void func_80108DD0_31E940() {
    struct player *player;

    player = GetPlayerStruct(-1);
    if (GetAbsSpaceIndexFromChainSpaceIndex(player->reverse_chain_index, player->reverse_space_index) == 0x4B &&
        (player->flags2 & 0x80) == 0) {
        SetNextChainAndSpace(-1, 0xA, 0);
        player->flags2 &= 0xFE;
    } else {
        func_80116484_32BFF4(&D_8011DB5C, &D_8011DB70, &D_8011D77C);
    }
    EndProcess(0);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80108E80_31E9F0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109390_31EF00);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801093C8_31EF38);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109400_31EF70);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109430_31EFA0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109474_31EFE4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801094A4_31F014);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801094E8_31F058);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109518_31F088);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010955C_31F0CC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010958C_31F0FC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801095D0_31F140);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109600_31F170);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109644_31F1B4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109674_31F1E4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801096B8_31F228);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109718_31F288);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010973C_31F2AC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109760_31F2D0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109784_31F2F4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801097E4_31F354);

void func_80109808_31F378() {
    func_80108C1C_31E78C(0x59, 2, 7);
}

void func_8010982C_31F39C() {
    func_80108C1C_31E78C(0x47, 2, 7);
}

void func_80109850_31F3C0() {
    func_80108C1C_31E78C(0x7C, 10, 2);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109874_31F3E4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801098D4_31F444);

void func_801098F8_31F468() {
    func_80108C1C_31E78C(0x15, 5, 11);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010991C_31F48C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109940_31F4B0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109964_31F4D4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109988_31F4F8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801099AC_31F51C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801099D0_31F540);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801099F4_31F564);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109A28_31F598);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109A6C_31F5DC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109A90_31F600);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109AB4_31F624);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109AD8_31F648);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109E84_31F9F4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109EB4_31FA24);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109EF8_31FA68);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80109F54_31FAC4);

void func_8010A068_31FBD8() {
    func_80116484_32BFF4(&D_8011E010, &D_8011E024, &D_8011DA58);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010A098_31FC08);

// GetBasicPromptSelection
INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010A134_31FCA4);
// void D_8010A134_31FCA4(s32 arg0, s32 arg1) {
//     s16 sp18;
//     s32 temp_s0;
//     s32 temp_s2;
//     s32 i;
//     s32 phi_s1_2;
//     s32 phi_s2;
//     s32 phi_s2_2;
//     s32 phi_s0;
//     s32 phi_v0;
//     s32 phi_s2_3;

//     for (i = 0; i < 4; i++) {
//         if (i == D_800CD058.current_player_index) {
//             if ((gPlayers[i].flags & 1) != 0) {
//                 if (arg0 != 1) {
//                     if (arg0 >= 2) {
//                         phi_s2 = arg1 + 1;
//                         if (arg0 != 2) {
//                             goto block_13;
//                         }
//                     } else if (arg0 != 0) {
// block_13:
//                         phi_s2 = func_800DA190(arg0) + 1;
//                     } else {
//                         phi_s2 = func_800EF0D8(0) + 1;
//                     }
//                 } else {
//                     phi_s2 = func_800EF0D8(1) + 1;
//                 }
//                 &sp18[gPlayers[i].controller] = 0x400;
//                 break;
//             }
//             func_8005FE54(D_80105702, (sp + gPlayers[i].controller)->unk20);
//             *(gPlayers[i].controller + &sp18) = -1;
//         } else {
//             *(gPlayers[i].controller + &sp18) = 0;
//         }
//     }

//     if (phi_s2 != 0) {
//         func_8005B63C(D_80105702, 2, 2);
//         phi_s0 = 0;
//         do {
//             temp_s2 = phi_s2_2 - 1;
//             phi_s2_2 = temp_s2;
//             if (temp_s2 == 0) {
//                 *(gPlayers[D_800CD058.current_player_index].controller + &sp18) = -0x8000;
//             }
//             phi_v0 = 5;
//             if (phi_s0 == 0) {
//                 phi_v0 = func_800EDC40() & 0xFF;
//             }
//             func_8005F698(sp18, sp1A, sp1C, sp1E, phi_v0);
//             phi_s0 += 1;
//         } while (temp_s2 != 0);
//     }
//     else {
//         func_8005F744(sp18, sp1A, sp1C, sp1E);
//     }

//     func_8005E1D8(D_80105702, 0, 1);
// }

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010A3B8_31FF28);

void func_8010A474_31FFE4() {
    while (TRUE) {
        func_800F69F8(D_800CD058.current_player_index, func_800E4A7C(), 0x8000);
        SleepVProcess();
    }
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010A4B4_320024);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010A860_3203D0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010B394_320F04);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010B41C_320F8C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010B484_320FF4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010B65C_3211CC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010C914_322484);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010C9B4_322524);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010CA54_3225C4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010CE9C_322A0C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010CEC0_322A30);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010DCEC_32385C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010DE40_3239B0);

// boo event
INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010DE7C_3239EC);
// void D_8010DE7C_3239EC() {
//     struct player *player;
//     s16 space_index;
//     struct space_data *spacedata;
//     struct object *obj;
//     f32 temp_f22;
//     f32 phi_f20;
//     struct coords_3d subroutine_arg1A;
//     struct process *temp_s0_4_process;
//     struct coords_3d subroutine_arg23; // type guess, not known

//     func_800EBCC8(0);

//     player = GetPlayerStruct(-1);
//     func_800F2304(-1, -1, 2, func_800DBEC0(D_800CD058.current_player_index));

//     // GetAbsSpaceIndexFromChainSpaceIndex
//     space_index = func_800EB184(player->cur_chain_index, player->cur_space_index, 0);

//     if (space_index != 0x92) {
//         func_800D9B24(&obj, func_800D975C(D_8011FB08, -1, (u16)-1));
//         obj->unk30 = 30.0f;
//         spacedata = GetSpaceData(space_index); // GetSpaceData
//         func_80089A10(&obj->coords, spacedata->coords->x, spacedata->coords->y + 10.0f, spacedata->coords->z);
//         phi_s4 = NULL;
//     }
//     else {
//         spacedata = GetSpaceData(0x6A);
//         func_8004AA88(0x125, D_8011FB0C);
//         obj = func_800D90C8_ECCE8(0x33, NULL);
//         if (D_80121D80[D_800CD058] != 0) {
//             func_8001ED54(obj->unk3C->unk40->unk0);
//         }
//         func_8001C448(obj->unk3C->unk40->unk0);
//         func_800D9714(obj);
//         func_80089AB0(&subroutine_arg1A, &(GetSpaceData(space_index)->coords), spacedata);
//         func_800D88E8(&subroutine_arg1A);
//         func_80089A20(&obj->unk18, &subroutine_arg1A);
//         obj->unk28 = 0.0f;
//         func_80089A20(&obj->coords, spacedata);
//         func_800D9CE8(obj, -1, 1);
//         func_800D9AA4(obj);
//         temp_f22 = 1.0f / func_8008EF20(50.0f);

//         phi_f20 = 0.0f;
//         do {
//             obj->unk28 = func_8008EF20(phi_f20) * temp_f22;
//             obj->unk24 = (func_8008EF20(phi_f20) * temp_f22 * 0.99f) + 0.01f;
//             obj->unk2C = (func_8008EF20(phi_f20) * temp_f22 * 0.99f) + 0.01f;
//             if (D_8011E280[D_800CD058] != 0) {
//                 obj->unk24 = -obj->unk24;
//             }
//             SleepVProcess();
//             phi_f20 += 11.25f;
//         }
//         while (temp_f20 < 90.0f);

//         while (50.0f < phi_f20) {
//             obj->unk28 = func_8008EF20(phi_f20) * temp_f22;
//             obj->unk24 = (func_8008EF20(phi_f20) * temp_f22 * 0.99f) + 0.01f;
//             obj->unk2C = (func_8008EF20(phi_f20) * temp_f22 * 0.99f) + 0.01f;
//             if (D_8011E280[D_800CD058] != 0) {
//                 obj->unk24 = -obj->unk24;
//             }
//             SleepVProcess();
//             phi_f20 -= 11.25f;
//         }

//         obj->unk28 = 1.0f;
//         obj->unk24 = 1.0f;
//         obj->unk2C = 1.0f;

//         if (D_80121D80[D_800CD058] != 0) {
//             obj->unk24 = -1.0f;
//         }
//         func_800D9CE8(obj, -1, 0);
//         func_8001C92C(obj->unk3C->unk40->unk0, 1.2f); //0x3F99999A, 1.20000004768

//         while (TRUE) {
//             if (func_800D9E0C(obj) == 0) {
//                 SleepVProcess();
//                 continue;
//             }
//         }
//     }

//     func_8004AA88(0x257);
//     func_8010C914_322484(subroutine_arg23);
//     if (/*temp_s0_3*/ space_index != -1) {
//         func_800D9F5C(subroutine_arg23, &(GetSpaceData(space_index)->coords), 5);
//         func_800ED20C(-1, 5, temp_s0_3);
//         SleepProcess(5);
//         temp_s0_4_process = GetCurrentProcess();
//         LinkChildProcess(temp_s0_4_process, func_800E8EDC(1.6f)); // 0x3FCCCCCD
//         WaitForChildProcess();
//     }

//     if (gPlayers[current_player_index].flags < 5) {
//         func_800EC590(7, 0x6201);
//     }
//     else {
// loop_23:
// loop_24:
//         if (phi_s0 != D_800CD058.current_player_index) {
//             temp_v1 = ((phi_s0 * 8) - phi_s0) * 8;
//             phi_v0 = phi_s0 < 4;
//             if (gPlayers[temp_v1].coins == 0) {
//                 phi_v0 = phi_s0 < 4;
//                 if (gPlayers[temp_v1].stars == 0) {
// block_27:
//                     temp_s0_5 = phi_s0 + 1;
//                     temp_v0_3 = temp_s0_5 < 4;
//                     phi_s0 = temp_s0_5;
//                     phi_v0 = temp_v0_3;
//                     if (temp_v0_3 != 0) {
//                         goto loop_24;
//                     }
//                 }
//             }
//         } else {
//             goto block_27;
//         }
//         if (phi_v0 == 0) {
//             func_800EC590(7, 0x6202);
//         } else {
//             phi_s0_2 = 0;
// loop_31:
//             if ((phi_s0_2 == D_800CD058.current_player_index) || (phi_s0_3 = phi_s0_2, (((((phi_s0_2 * 8) - phi_s0_2)
//             * 8) + 0x800D0000)->unk1112 == 0))) {
//                 temp_s0_6 = phi_s0_2 + 1;
//                 phi_s0_2 = temp_s0_6;
//                 phi_s0_3 = temp_s0_6;
//                 if (temp_s0_6 < 4) {
//                     goto loop_31;
//                 }
//             }
//             if (phi_s0_3 == 4) {

//             }
//             phi_s0_4 = 0;
// loop_38:
//             if ((phi_s0_4 == D_800CD058.current_player_index) || (phi_s0_5 = phi_s0_4, (((((phi_s0_4 * 8) - phi_s0_4)
//             * 8) + 0x800D0000)->unk1116 == 0))) {
//                 temp_s0_7 = phi_s0_4 + 1;
//                 phi_s0_4 = temp_s0_7;
//                 phi_s0_5 = temp_s0_7;
//                 if (temp_s0_7 < 4) {
//                     goto loop_38;
//                 }
//             }
//             if ((phi_s0_5 != 4) && (temp_v1_2 = D_800CD058.current_player_index * 0x38, (((s32) (temp_v1_2 +
//             0x800D0000)->unk1112 < 0x32) == 0))) {
//                 if ((s32) (temp_v1_2 + 0x800D0000)->unk1116 >= 0x63) {
// block_45:
//                 }
//             } else {
//                 goto block_45;
//             }
//             func_800EC8EC(7, 0x6200, &subroutine_arg8, &subroutine_argC, 0, 0, 0, (u8)0, (u8)1, (u8)1);
//             temp_s0_8 = func_80107BB4_31D724(&subroutine_arg18);
//             func_800EC6C8(temp_s0_8);
//             func_800EC6EC();
//             temp_s0_8 = temp_s0_8;
//             if (temp_s0_8 != 2) {
//                 if ((s32) temp_s0_8 >= 3) {
//                     if (temp_s0_8 != 3) {

//                     } else {
//                         if (subroutine_arg25 == -1) {
//                             func_80106FE8_31CB58();
//                             D_800CB99C = 1;
//                             func_80049FB8();
//                         } else {
//                             func_80106F60_31CAD0();
//                         }
//                         goto loop_23;
//                     }
//                 } else if ((s32) temp_s0_8 >= 0) {
// loop_53:
// loop_54:
// loop_55:
//                     if (phi_s0_6 != D_800CD058.current_player_index) {
//                         temp_v0_4 = phi_s0_6 * 8;
//                         if (subroutine_arg2F == 0) {
//                             temp_v0_5 = &subroutine_arg18 + phi_s1;
//                             phi_v0_2 = temp_v0_5;
//                             if ((((temp_v0_4 - phi_s0_6) * 8) + 0x800D0000)->unk1112 != 0) {
//                                 *temp_v0_5 = (u8)1;
// block_63:
//                                 *(&subroutine_arg8 + (phi_s1 * 0x10)) = (u8)8;
//                             } else {
// block_61:
//                                 *phi_v0_2 = (u8)0;
//                                 *(&subroutine_arg8 + (phi_s1 * 0x10)) = (u8)1;
//                             }
//                         } else if ((((temp_v0_4 - phi_s0_6) * 8) + 0x800D0000)->unk1116 == 0) {
// block_60:
//                             phi_v0_2 = &subroutine_arg18 + phi_s1;
//                             goto block_61;
//                         } else {
//                             *(&subroutine_arg18 + phi_s1) = (u8)1;
//                             goto block_63;
//                         }
//                     } else {
//                         goto block_60;
//                     }
//                     func_800E2260(phi_s0_6, &subroutine_arg8 + (phi_s1 * 0x10) + 1);
//                     temp_s0_9 = phi_s0_6 + 1;
//                     phi_s0_6 = temp_s0_9;
//                     phi_s1 = phi_s1 + 1;
//                     if (temp_s0_9 < 4) {
//                         goto loop_55;
//                     }
//                     func_800EC8EC(7, 0x5C02, &subroutine_arg8, &subroutine_argC, &subroutine_arg10,
//                     &subroutine_arg14, 0, (u8)1, (u8)1); temp_s0_10 = func_80107BD4_31D744(&subroutine_arg18);
//                     temp_s2_2 = temp_s0_10;
//                     func_800EC6C8();
//                     func_800EC6EC();
//                     temp_s0_10 = temp_s0_10;
//                     if (temp_s0_10 != 4) {
//                         if ((s32) temp_s0_10 < 5) {
//                             if (temp_s0_10 == -1) {
//                                 goto loop_23;
//                             }
//                             phi_s1_3 = 0;
//                             phi_s2_2 = temp_s2_2;
//                         } else {
//                             phi_s1_3 = 0;
//                             phi_s2_2 = temp_s2_2;
//                             if (temp_s0_10 == 5) {
//                                 if (subroutine_arg25 == -1) {
//                                     func_80106FE8_31CB58();
//                                     D_800CB99C = 1;
//                                     func_80049FB8();
//                                     phi_s0_6 = 0;
//                                     phi_s1 = 0;
//                                 } else {
//                                     func_80106F60_31CAD0();
//                                     goto loop_53;
//                                 }
//                                 goto loop_54;
//                             }
//                         }
//                     } else {
//                         phi_s0_7 = 0;
//                         phi_s2 = 0;
// loop_74:
//                         phi_s1_2 = 0;
// loop_75:
//                         phi_s2_3 = phi_s2;
//                         if (phi_s0_7 == func_800EE9C0(phi_s1_2)) {
//                             phi_s2_3 = phi_s2;
//                             if (D_800CD058.current_player_index != phi_s1_2) {
//                                 ((phi_s2 * 4) + &subroutine_arg8)->unk58 = phi_s1_2;
//                                 phi_s2_3 = phi_s2 + 1;
//                             }
//                         }
//                         temp_s1_2 = phi_s1_2 + 1;
//                         phi_s1_2 = temp_s1_2;
//                         phi_s2 = phi_s2_3;
//                         if (temp_s1_2 < 4) {
//                             goto loop_75;
//                         }
//                         temp_s0_11 = phi_s0_7 + 1;
//                         phi_s0_7 = temp_s0_11;
//                         phi_s2 = phi_s2_3;
//                         if (temp_s0_11 < 4) {
//                             goto loop_74;
//                         }
//                         phi_v0_3 = 0 * 4;
//                         phi_s0_8 = 0;
// loop_81:
//                         phi_s0_10 = phi_s0_8;
//                         if (func_800EEF80(100.0f) >= *(phi_v0_3 + 0x8011E274)) {
//                             temp_s0_12 = phi_s0_8 + 1;
//                             phi_v0_3 = temp_s0_12 * 4;
//                             phi_s0_8 = temp_s0_12;
//                             phi_s0_10 = temp_s0_12;
//                             if (temp_s0_12 < 3) {
//                                 goto loop_81;
//                             }
//                         }
//                         phi_s0_9 = phi_s0_10;
//                         if ((subroutine_arg2B << 0x10) != 0) {
// loop_84:
//                             temp_v1_3 = ((phi_s0_9 * 4) + &subroutine_arg8)->unk58;
//                             if (((temp_v1_3 * 0x38) + 0x800D0000)->unk1116 == 0) {
//                                 phi_s0_9 = phi_s0_9 - 1;
//                                 goto loop_84;
//                             }
// loop_86:
//                             if (temp_v1_3 != D_800CD058.current_player_index) {
//                                 goto loop_86;
//                             }
//                             phi_s0_9 = phi_s0_9 - 1;
//                             goto loop_84;
//                         }
//                         phi_v0_4 = phi_s0_10 * 4;
//                         phi_s0_11 = phi_s0_10;
//                         if (phi_s0_10 >= 0) {
// loop_90:
//                             temp_v1_4 = (phi_v0_4 + &subroutine_arg8)->unk58;
//                             temp_s0_13 = phi_s0_11 - 1;
//                             if ((((temp_v1_4 * 0x38) + 0x800D0000)->unk1112 == 0) || (temp_v1_4 ==
//                             D_800CD058.current_player_index)) {
//                                 phi_v0_4 = temp_s0_13 * 4;
//                                 phi_s0_11 = temp_s0_13;
//                                 if (temp_s0_13 >= 0) {
//                                     goto loop_90;
//                                 }
//                             }
//                         }
//                         phi_v0_5 = 2 * 4;
//                         phi_s0_12 = 2;
// loop_94:
//                         temp_v1_5 = (phi_v0_5 + &subroutine_arg8)->unk58;
//                         if ((((temp_v1_5 * 0x38) + 0x800D0000)->unk1112 == 0) || (phi_v0_7 = phi_s0_12 * 4,
//                         (temp_v1_5 == D_800CD058.current_player_index))) {
//                             temp_s0_14 = phi_s0_12 - 1;
//                             temp_v0_6 = temp_s0_14 * 4;
//                             phi_v0_5 = temp_v0_6;
//                             phi_s0_12 = temp_s0_14;
//                             phi_v0_7 = temp_v0_6;
//                             if (temp_s0_14 >= 0) {
//                                 goto loop_94;
//                             }
//                         }
//                         phi_s1_3 = 1;
//                         phi_s2_2 = (s16) (sp + phi_v0_7)->unk7A;
//                     }
//                     if ((subroutine_arg2B << 0x10) == 0) {
//                         func_800E1F48(D_800CD058.current_player_index, -5);
//                         phi_a1 = -5;
//                     } else {
//                         func_800E1F48(D_800CD058.current_player_index, -0x32);
//                         phi_a1 = -0x32;
//                     }
//                     func_800F5D44(D_800CD058.current_player_index, phi_a1);
//                     SleepProcess(0x1E);
//                     if ((s16) subroutine_arg2B == 1) {
//                         if (phi_s1_3 != 0) {
//                             phi_a1_2 = 0x6206;
// block_111:
//                             func_800EC590(7, phi_a1_2);
//                         }
//                     } else {
//                         temp_a0 = D_800CD05B;
//                         phi_v0_6 = 0U * 2;
//                         phi_s0_13 = 0U;
// loop_105:
//                         temp_v1_6 = phi_v0_6 + phi_s0_13;
//                         if (((s32) temp_a0 < (s32) (temp_v1_6 + 0x80121DD4) || ((s32) (temp_v1_6 + 0x80121DD3) <
//                         (s32) temp_a0)) {
//                             temp_s0_15 = phi_s0_13 + 1;
//                             phi_v0_6 = temp_s0_15 * 2;
//                             phi_s0_13 = temp_s0_15;
//                             if (temp_s0_15 < 6U) {
//                                 goto loop_105;
//                             }
//                         }
//                         if (phi_s1_3 == 0) {
//                             phi_a1_2 = func_800EEF80(6.0f, temp_a0) + 0x6207;
//                         } else {
//                             phi_a1_2 = 0x620D;
//                         }
//                         goto block_111;
//                     }
//                     D_8010C9B4_322524(subroutine_arg23);
//                     if ((subroutine_arg2B << 0x10) == 0) {
//                         temp_s0_16 = phi_s2_2;
//                         temp_s6 = D_8010CEC0_322A30(temp_s0_16);
//                         func_8010C914_322484(subroutine_arg23);
//                         phi_s6_3 = temp_s6;
//                         if (temp_s6 != -2) {
//                             if (temp_s6 == -1) {
//                                 temp_s6_2 = gPlayers[temp_s0_16].flags;
//                                 func_8007BDC0(&subroutine_arg8, 0x8011F8D4, temp_s6_2);
//                                 phi_a1_3 = 0x6214;
//                                 phi_s6 = temp_s6_2;
//                             } else {
//                                 func_8007BDC0(&subroutine_arg8, 0x8011F8D4, temp_s6);
//                                 phi_s0_14 = 0;
//                                 while (TRUE) {
//                                     phi_s0_15 = phi_s0_14;
//                                     if ((subroutine_arg27 - temp_s6) < (s32) (phi_s0_14 + 0x80121D94)) {
//                                         temp_s0_17 = phi_s0_14 + 1;
//                                         phi_s0_14 = temp_s0_17;
//                                         phi_s0_15 = temp_s0_17;
//                                         if (temp_s0_17 < 4) {
//                                             continue;
//                                         }
//                                         break;
//                                     }
//                                 }
//                                 phi_a1_3 = phi_s0_15 + 0x6210;
//                                 phi_s6 = temp_s6;
//                             }
//                             func_800EC8EC(7, phi_a1_3, &subroutine_arg8, 0);
//                             func_800EC6C8();
//                             func_800EC6EC();
//                             phi_s6_3 = phi_s6;
//                             if (phi_s6 != -2) {
//                                 D_800D037C = 0;
//                                 D_8011FB58 = func_800D90C8_ECCE8(0x19, 0);
//                                 func_800D9714(D_8011FB58);
//                                 func_800D9B24(D_8011FB58);
//                                 phi_s6_3 = phi_s6;
//                                 if (phi_s6 != 0) {
//                                     phi_f20_3 = 0.0f;
//                                     phi_s6_4 = phi_s6;
//                                     while (TRUE) {
//                                         temp_f20_3 = phi_f20_3 + ((f32) phi_s6 / 90.0f);
//                                         phi_s6_2 = phi_s6_4;
//                                         phi_f20_3 = temp_f20_3;
//                                         if (1.0f <= temp_f20_3) {
//                                             D_8010DE40_3239B0(subroutine_arg23);
//                                             func_800F5D44(D_800CD058.current_player_index, 1);
//                                             func_800F5BF4(phi_s2_2, -1, 0);
//                                             phi_s6_2 = phi_s6_4 - 1;
//                                             phi_f20_3 = temp_f20_3 - 1.0f;
//                                         }
//                                         SleepVProcess();
//                                         phi_s6_4 = phi_s6_2;
//                                         phi_s6_3 = phi_s6_2;
//                                         if (phi_s6_2 != 0) {
//                                             continue;
//                                         }
//                                         break;
//                                     }
//                                 }
//                                 func_800FFAEC(func_800FFA4C(phi_s2_2, 3, 5));
//                                 SleepProcess(0x14);
//                                 func_800D9B54_ED774(D_8011FB58);
//                                 func_800ECC0C(&(GetPlayerStruct(-1)->obj->unk18));
//                                 func_800F2304(-1, 5, 0);
//                                 SleepProcess(5);
//                                 func_8004ACE0(0x274, D_800CD058.current_player_index);
//                                 SleepProcess(0x2D);
//                                 D_800D037C = 1;
//                             } else {
// block_130:
//                             }
//                         } else {
//                             goto block_130;
//                         }
//                     } else {
//                         temp_s0_18 = func_8010CA54_3225C4(phi_s2_2);
//                         func_8010C914_322484(subroutine_arg23);
//                         if (temp_s0_18 != 0) {
//                             func_800EC590(7, 0x6205);
//                             D_8011D308 = 1;
//                             func_80106EEC_31CA5C(subroutine_arg23);
//                             D_8011D308 = 0;
//                             phi_s6_3 = (u16)0;
//                         } else {
//                             phi_s6_3 = (u16)-2;
//                             goto block_130;
//                         }
//                     }
//                     if (subroutine_arg25 == -1) {
//                         SleepProcess(0x14);
//                         func_800F2304(-1, -1, 2);
//                     }
//                     if (phi_s6_3 == -2) {
//                         SleepProcess(0x1E);
//                         func_800EC590(7, 0x6215);
//                     }
//                 }
//             } else {
//                 D_8010C9B4_322524(subroutine_arg23);
//                 func_800EC590(7, 0x6203);
//             }
//         }
//     }

//     if ((s16) subroutine_arg2B != 2) {
//         D_8010C9B4_322524(subroutine_arg23);
//     }

//     func_800ECC0C(subroutine_arg23 + 0x18);

//     if (subroutine_arg25 == -1) {
//         func_800D9B54_ED774(subroutine_arg23);
//     }

//     if ((s16) subroutine_arg29 != -1) {
//         func_8004AA88(0x126);
//         func_800D9CE8(phi_s4, -1, 4);
//         func_8001C92C(*phi_s4->unk3C->unk28, 1.2f); // 0x3F99999A
//         temp_a0_2 = *phi_s4->unk3C->unk28;
//         func_8001C6A8(temp_a0_2,
//             (f32) ((((temp_a0_2 * 0xC0) + D_800D03F8)->unk2 * 0x18) + D_800CCF58)->unk2);

//         while (func_800D9E80(phi_s4) == 0) {
//             SleepVProcess();
//         }

//         temp_f22_2 = 1.0f / func_8008EF20(50.0f);
//         phi_f20_4 = 50.0f;
//         while (TRUE) {
//             phi_s4->unk28 = (f32) (func_8008EF20(phi_f20_4) * temp_f22_2);
//             phi_s4->unk24 = (f32) ((func_8008EF20(phi_f20_4) * temp_f22_2 * 0.2f) + 0.8f);
//             phi_s4->unk2C = (f32) ((func_8008EF20(phi_f20_4) * temp_f22_2 * 0.2f) + 0.8f);
//             if (*(((void *)0x800CD058->unk1 * 4) + 0x8011E280) != 0) {
//                 phi_s4->unk24 = (f32) -phi_s4->unk24;
//             }
//             SleepVProcess();
//             temp_f20_4 = phi_f20_4 + 11.25f;
//             phi_f20_4 = temp_f20_4;
//             if (temp_f20_4 < 90.0f) {
//                 continue;
//             }
//             break;
//         }

//         {
//             f32 phi_f20_5 = 90.0f;
//             while (TRUE) {
//                 phi_s4->unk28 = (f32) (func_8008EF20(phi_f20_5) * temp_f22_2);
//                 phi_s4->unk24 = (f32) ((func_8008EF20(phi_f20_5) * temp_f22_2 * 0.2f) + 0.8f);
//                 phi_s4->unk2C = (f32) ((func_8008EF20(phi_f20_5) * temp_f22_2 * 0.2f) + 0.8f);
//                 if (D_8011E280[0x800CD059] != 0) {
//                     phi_s4->unk24 = -phi_s4->unk24;
//                 }
//                 SleepVProcess();
//                 temp_f20_5 = phi_f20_5 - 11.25f;
//                 phi_f20_5 = temp_f20_5;
//                 if (0.0f < temp_f20_5) {
//                     continue;
//                 }
//                 break;
//             }
//         }

//         phi_s4->unk28 = 0.0f;
//         phi_s4->unk24 = 0.0f;
//         phi_s4->unk2C = 0.0f;

//         func_800D9B54_ED774(phi_s4);
//     }

//     if (subroutine_arg2D != 0) {
//         func_800DB884(D_800CD058->unkF);
//     }

//     {
//         struct process *proc;
//         if (subroutine_arg25 != -1) {
//             proc = GetCurrentProcess();
//             LinkChildProcess(proc, func_800E8EDC(1.3f)); // 0x3FA66666
//             WaitForChildProcess();
//         }
//     }

//     D_8010A098_31FC08();
// }

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010F050_324BC0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010F06C_324BDC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010F088_324BF8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010F1E4_324D54);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010F2FC_324E6C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010F6C4_325234);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010F730_3252A0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010F8F0_325460);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010FB54_3256C4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010FC24_325794);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8010FE54_3259C4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80110024_325B94);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80110194_325D04);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801104E0_326050);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801106A4_326214);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011093C_3264AC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80110BC8_326738);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80110E08_326978);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80111018_326B88);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801112D8_326E48);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80111678_3271E8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80112074_327BE4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801125BC_32812C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801127D8_328348);

void func_80112BCC_32873C() {
    s32 i;

    SleepProcess(10);
    for (i = 1; i < 64; i++) {
        func_800F68E0(D_800CD058.current_player_index, func_800E4A7C(), 255.0f - (i * 3.984f));
        SleepVProcess();
    }

    func_800F68E0(D_800CD058.current_player_index, func_800E4A7C(), 0);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80112C88_3287F8);
// void D_80112C88_3287F8() {
//     f32 temp_f0;
//     f32 temp_f20;
//     f64 temp_f22;
//     struct object *temp_s0;
//     struct object *temp_s1;
//     f32 phi_f20;

//     temp_s1 = GetCurrentProcess()->user_data;
//     temp_s0 = func_800D975C(D_8011FB68);
//     func_80089A20(&temp_s0->coords, &temp_s1->coords);
//     func_80089A10(&temp_s0->unk24, 2.0f, 2.0f, 2.0f);
//     temp_s0->unk30 = temp_s1->unk30 + 10.0f;
//     func_800D9AA4(temp_s0);
//     temp_f22 = D_8011F968;
//     phi_f20 = func_800EEF80(360.0f);

//     while (TRUE) {
//         SleepVProcess();
//         temp_f0 = temp_s0->unk30 + temp_f22;
//         temp_s0->unk30 = temp_f0;

//         if ((!((temp_s1->unk30 + 35.0f) <= temp_f0))) {
//             temp_f20 = phi_f20 + 40.0f;
//             func_8008A2A0((temp_s0->unk3C->unk3C * 0xC0) + D_800D03F8 + 0x74, temp_f20);
//             phi_f20 = temp_f20;
//             continue;
//         }
//         break;
//     }

//     func_800D9B54_ED774(temp_s0);
//     EndProcess(NULL);
// }

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80112DDC_32894C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80112E18_328988);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80112FA8_328B18);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80113364_328ED4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801135FC_32916C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80113708_329278);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801138E4_329454);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80114590_32A100);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80114650_32A1C0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80114B80_32A6F0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011548C_32AFFC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801155C4_32B134);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80115734_32B2A4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801158FC_32B46C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80115B80_32B6F0);

// helper used with chain split
INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80116484_32BFF4);
// FIXME: Pretty far off, but general idea is there.
// u8 func_80116484_32BFF4(s16 *spaceIndexArgs, struct chain_args *chainArgs, s32 *ai_data) {
//     struct player *player;
//     struct chain_args *chosenChainArgs;
//     void *temp_s2;
//     s32 temp_s0_2;
//     s16 flagsTemp;
//     s32 i, j;

//     func_800F2304(-1, -1, 2);
//     SleepVProcess();
//     func_80107044_31CBB4();
//     player = GetPlayerStruct(D_800CD058.current_player_index);

//     for (i = 0; i < 3; i++) {
//         for (j = 0; j < 2; j++) {
//             if (*(spaceIndexArgs + (i * 3) + j) != GetAbsSpaceIndexFromChainSpaceIndex(player->reverse_chain_index,
//             player->reverse_space_index)) {
//                 continue;
//             }
//             break;
//         }

//         if (j != 2) {
//             break;
//         }
//     }

//     chosenChainArgs = &chainArgs[i];
//     temp_s2 = func_800D76A0(D_800CD058.current_player_index, spaceIndexArgs + (i * 3), 2);
//     func_800D742C(temp_s2, D_800CD058.current_player_index, 0);
//     if (PlayerIsCPU(-1) != 0) {
//         {
//             s32 ai_choice;

//             ai_choice = func_800DA190(ai_data[i]);
//             for (i = 0; i < ai_choice; i++) {
//                 func_800D7250(temp_s2, -2);
//             }
//             func_800D7250(temp_s2, -4);
//         }
//     }
//     temp_s0_2 = func_800D7518(temp_s2);
//     func_800D6CA0(temp_s2);
//     func_80107114_31CC84();
//     if (temp_s0_2 != 0) {
//         chosenChainArgs = chosenChainArgs + 1;
//     }
//     SetNextChainAndSpace(-1, chosenChainArgs->chainl, chosenChainArgs->chainr);
//     flagsTemp = chosenChainArgs->flags;
//     if (flagsTemp != 0) {
//         if (flagsTemp != 1) {
//             return 1;
//         }
//         flagsTemp = player->flags2 | 1;
//     }
//     else {
//         flagsTemp = player->flags2 & 0xFE;
//     }
//     player->flags2 = flagsTemp;
//     return flagsTemp;
// }

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011667C_32C1EC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801166F4_32C264);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80116758_32C2C8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80116904_32C474);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80116A04_32C574);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80116AA0_32C610);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80116BA0_32C710);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80116DAC_32C91C);

void func_80116F0C_32CA7C() {
    void *data;
    s32 i;

    i = 0x3C;
    data = GetCurrentProcess()->user_data;

    while (i != 0) {
        SleepVProcess();
        i--;
    }

    func_800FFAEC(data);
    EndProcess(NULL);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80116F5C_32CACC);

// Reverse pre-turn event.
INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801174D4_32D044);
// void func_801174D4_32D044() {
//     struct strCD058 *strCD058loc;
//     struct player *player;
//     s32 phi_a0;
//     s32 phi_a1;
//     f32 ftemp;

//     strCD058loc = &D_800CD058;

//     player = GetPlayerStruct(-1);
//     if ((player->flags2 & 0x80) != 0) {
//         // 0x3A03 "A Reverse Mushroom is forcing you to move in the opposite direction"
//         // 0x421C "Because of the "Reverse Curse", you'll now move in the opposite direction."
//         if ((player->flags2 & 0x40) == 0) {
//             phi_a1 = 0x3A03;
//             if ((player->flags2 & 0x14) == 0x10) {
//                 phi_a1 = 0x421C;
//             }
//         }
//         else {
//             phi_a1 = 0x421C;
//         }
//         func_800EC590(-1, phi_a1);

//         if ((player->flags2 & 4) != 0) {
//             if (D_8011FB98[strCD058loc->current_player_index] != NULL) {
//                 ftemp = 1.0f;
//                 do {
//                     func_80089A10(&(*(D_8011FB98 + strCD058loc->current_player_index)->unk24), ftemp, ftemp, ftemp);
//                     SleepVProcess();
//                     ftemp -= 0.08f;
//                 }
//                 while (ftemp >= 0.0f);
//             }
//             func_8011667C_32C1EC(strCD058loc->current_player_index);
//         }
//         if ((player->flags2 & 0x10) != 0) {
//             if (D_8011FB98[strCD058loc->current_player_index] != NULL) {
//                 ftemp = 1.0f;
//                 do {
//                     func_80089A10(&(D_8011FB98[strCD058loc->current_player_index]->unk24), ftemp, ftemp, ftemp);
//                     SleepVProcess();
//                     ftemp -= 0.08f;
//                 }
//                 while (ftemp >= 0.0f);
//             }
//             func_8011667C_32C1EC(strCD058loc->current_player_index);
//         }
//         player->flags2 &= 0xAB;
//     }
// }

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801176A4_32D214);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_801177DC_32D34C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80117C60_32D7D0);

INCLUDE_ASM(void, "overlays/board_chillywaters/chillywaters2", func_80118308_32DE78);

void func_80118A98_32E608() {
    struct player *player;

    player = GetPlayerStruct(-1);
    if (D_800D41C0 != 0) {
        if ((player->flags2 & 1) == 0) {
            SleepProcess(0xA);
            func_80118308_32DE78();
        }
    }
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80118AE8_32E658);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80118B7C_32E6EC);

struct object *func_80118D6C_32E8DC() {
    struct object *temp_a0;
    struct object *temp_ret;
    struct object *temp_v0;
    struct object *temp_v0_2;

    temp_v0 = D_8011D318;
    if (temp_v0 == NULL) {
        temp_v0_2 = func_800D90C8_ECCE8(0x2E, 0);
        D_8011D318 = temp_v0_2;
        func_800D9714(temp_v0_2);
        func_80089A20(&(D_8011D318->coords), &(GetSpaceData(0x81)->coords));
        temp_a0 = D_8011D318;
        temp_a0->coords.x = temp_a0->coords.x + 1.0f;
        temp_a0->coords.z = temp_a0->coords.z - 20.0f;
        temp_a0->unk24 = 1.2f;
        temp_a0->unk2C = 1.2f;
        func_800D9AA4(temp_a0);
        temp_ret = func_800D9B54_ED774(D_8011D314);
        D_8011D314 = NULL;
        return temp_ret;
    }
    return temp_v0;
}

void *func_80118E2C_32E99C() {
    struct object *temp_a0;
    struct object *temp_ret;
    struct object *temp_v0;
    struct object *temp_v0_2;

    temp_v0 = D_8011D314;
    if (temp_v0 == NULL) {
        temp_v0_2 = func_800D90C8_ECCE8(0x2D, 0);
        D_8011D314 = temp_v0_2;
        func_800D9714(temp_v0_2);
        func_80089A20(&(D_8011D314->coords), &(GetSpaceData(0x81)->coords));
        temp_a0 = D_8011D314;
        temp_a0->coords.x = temp_a0->coords.x + 1.0f;
        temp_a0->coords.z = temp_a0->coords.z - 20.0f;
        temp_a0->unk24 = 1.2f;
        temp_a0->unk2C = 1.2f;
        func_800D9AA4(temp_a0);
        temp_ret = func_800D9B54_ED774(D_8011D318);
        D_8011D318 = NULL;
        return temp_ret;
    }
    return temp_v0;
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80118EEC_32EA5C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80119924_32F494);

s32 func_80119A20_32F590(s32 arg0) {
    s32 temp_s1;

    temp_s1 = func_80119924_32F494(arg0++);
    return temp_s1 + func_80119924_32F494(arg0);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80119A60_32F5D0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80119B3C_32F6AC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80119C54_32F7C4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_80119D08_32F878);

void func_8011A764_3302D4() {
    s32 temp_v0;

    temp_v0 = func_800D90C8_ECCE8(0x36, 0);
    D_8011FAEC = temp_v0;
    func_800D9B24(temp_v0);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011A794_330304);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011A838_3303A8);

void func_8011A8B8_330428() {
    func_800D9B54_ED774(D_8011FAEC);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011A8D8_330448);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011B9A0_331510);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011BBA4_331714);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011BD48_3318B8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011BD8C_3318FC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011BF3C_331AAC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011C470_331FE0);

// entrypoint 4
void func_8011C58C_3320FC() {
    func_80012220(2);
    func_800124BC(1, &D_8011E8B8);
    func_80107CC4_31D834();
    func_800FF41C(2);
    InitProcess(func_801065D0_31C140, 0x1005, 0x1000, 0);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011C5E0_332150);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011C68C_3321FC);

s32 func_8011C750_3322C0() {
    s32 temp_s0;
    s32 phi_v1;
    struct strCD058 *loc;
    loc = &D_800CD058;

    temp_s0 = loc->total_turns - loc->current_turn + 1;

    phi_v1 = PlayerHasEmptyItemSlot(-1);
    if (phi_v1 == -1) {
        phi_v1 = 3;
    }

    return (phi_v1 < temp_s0) ? 0 : 1;
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011C7A4_332314);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011C88C_3323FC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011CE94_332A04);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters2", func_8011D1F8_332D68);
