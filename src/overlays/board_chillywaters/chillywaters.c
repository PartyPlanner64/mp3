#include "common.h"
#include "../../process.h"
#include "../../object.h"

extern u8 D_800CD059;
extern s8 D_800CD05A;
extern s8 D_800CD05B;
extern s8 D_800CD067;
extern u16 D_800CD0B4[];
extern u16 D_800CE198;
extern u8 D_800D03F8[];

extern void *D_8011E2CC;
extern void *D_8011E718;
extern void *D_8011A8D8;
extern s16 D_8011D2C0[];
extern void *D_8011D31C;
extern void *D_8011D320;
extern void *D_8011E344;
extern void *D_8011E4D8;
extern void *D_8011E8B8;
extern f64 D_8011F968;
extern s32 D_8011FB68;

extern void func_80089A10(void *, f32, f32, f32);
extern f32 func_800D8790(struct coords_3d *);
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

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801059D0_31B540);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80105A64_31B5D4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80105DB8_31B928);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80105E20_31B990);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80105E80_31B9F0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80105EA8_31BA18);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80105FB0_31BB20);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010603C_31BBAC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801060E0_31BC50);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80106154_31BCC4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80106544_31C0B4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801065D0_31C140);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010698C_31C4FC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80106EEC_31CA5C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80106F60_31CAD0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80106FE8_31CB58);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80107044_31CBB4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80107114_31CC84);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80107174_31CCE4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80107408_31CF78);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80107620_31D190);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80107750_31D2C0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801078E8_31D458);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80107BB4_31D724);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80107BD4_31D744);

// entrypoint 0
void func_80107BF4_31D764() {
    D_800CD059 = 0;
    func_80047160(0xA, 0);
    func_80048228(0x47, 0, 0x192);
}

// entrypoint 1
void func_80107C2C_31D79C(void) {
    func_80047160(0xA, 0);

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
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    struct coords_3d subroutine_arg4;

    func_80047160(0xA0, 0x28);
    func_80019514(1, 0xFF, 0xFF, 0xFF);
    func_80019514(2, 0xC8, 0xC8, 0xC8);
    func_800F89D0(3, 0x23A, 5, 0);
    func_800EBCFC(&D_8011D31C);
    func_800EBD54(&D_8011D320);
    temp_s0 = func_800EB160(0x77);
    func_800ECB58(temp_s0 + 8, func_800EB160(0x73) + 8, &subroutine_arg4);
    func_800EA660(func_800D8790(&subroutine_arg4) + 180.0f);
    temp_s0_2 = func_800EB160(0x7C);
    func_800ECB58(temp_s0_2 + 8, func_800EB160(0x6E) + 8, &subroutine_arg4);
    func_800EA660(func_800D8790(&subroutine_arg4) + 180.0f);
    temp_s0_3 = func_800EB160(0x8F);
    func_800ECB58(temp_s0_3 + 8, func_800EB160(0x80) + 8, &subroutine_arg4);
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
            func_800EA6E0(i, D_8011D2C0[i]);
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
    func_80047EA0(func_80118B7C_32E6EC, 0x4800, 0, 0);
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

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801080C4_31DC34);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801081EC_31DD5C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108250_31DDC0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801082FC_31DE6C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010841C_31DF8C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108478_31DFE8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108574_31E0E4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801086E0_31E250);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108748_31E2B8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801088B4_31E424);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108914_31E484);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108970_31E4E0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108A38_31E5A8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108AE8_31E658);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108B24_31E694);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108BA4_31E714);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108C1C_31E78C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108CA4_31E814);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108CC8_31E838);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108D28_31E898);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108D60_31E8D0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108D98_31E908);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108DD0_31E940);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80108E80_31E9F0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109390_31EF00);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801093C8_31EF38);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109400_31EF70);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109430_31EFA0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109474_31EFE4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801094A4_31F014);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801094E8_31F058);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109518_31F088);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010955C_31F0CC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010958C_31F0FC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801095D0_31F140);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109600_31F170);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109644_31F1B4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109674_31F1E4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801096B8_31F228);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109718_31F288);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010973C_31F2AC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109760_31F2D0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109784_31F2F4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801097E4_31F354);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109808_31F378);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010982C_31F39C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109850_31F3C0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109874_31F3E4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801098D4_31F444);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801098F8_31F468);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010991C_31F48C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109940_31F4B0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109964_31F4D4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109988_31F4F8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801099AC_31F51C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801099D0_31F540);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801099F4_31F564);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109A28_31F598);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109A6C_31F5DC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109A90_31F600);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109AB4_31F624);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109AD8_31F648);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109E84_31F9F4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109EB4_31FA24);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109EF8_31FA68);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80109F54_31FAC4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010A068_31FBD8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010A098_31FC08);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010A134_31FCA4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010A3B8_31FF28);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010A474_31FFE4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010A4B4_320024);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010A860_3203D0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010B394_320F04);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010B41C_320F8C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010B484_320FF4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010B65C_3211CC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010C914_322484);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010C9B4_322524);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010CA54_3225C4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010CE9C_322A0C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010CEC0_322A30);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010DCEC_32385C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010DE40_3239B0);

// boo event
INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010DE7C_3239EC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010F050_324BC0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010F06C_324BDC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010F088_324BF8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010F1E4_324D54);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010F2FC_324E6C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010F6C4_325234);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010F730_3252A0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010F8F0_325460);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010FB54_3256C4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010FC24_325794);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8010FE54_3259C4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80110024_325B94);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80110194_325D04);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801104E0_326050);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801106A4_326214);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011093C_3264AC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80110BC8_326738);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80110E08_326978);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80111018_326B88);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801112D8_326E48);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80111678_3271E8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80112074_327BE4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801125BC_32812C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801127D8_328348);

void func_80112BCC_32873C(void) {
    s32 i;

    SleepProcess(10);
    for (i = 1; i < 64; i++) {
        func_800F68E0(D_800CD067, func_800E4A7C(), 255.0f - (i * 3.984f));
        SleepVProcess();
    }

    func_800F68E0(D_800CD067, func_800E4A7C(), 0);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80112C88_3287F8);
// void func_80112C88_3287F8() {
//     f32 temp_f0;
//     f32 temp_f20;
//     f64 temp_f22;
//     struct object *temp_s0;
//     struct object *temp_s1;
//     f32 phi_f20;

//     temp_s1 = GetCurrentProcess()->user_data;
//     temp_s0 = func_800D975C(D_8011FB68);
//     func_80089A20(&temp_s0->coords, &temp_s1->coords);
//     func_80089A10(&temp_s0->unk36, 2.0f, 2.0f, 2.0f);
//     temp_s0->unk48 = temp_s1->unk48 + 10.0f;
//     func_800D9AA4(temp_s0);
//     temp_f22 = D_8011F968;
//     phi_f20 = func_800EEF80(360.0f);

//     while (TRUE) {
//         SleepVProcess();
//         temp_f0 = temp_s0->unk48 + temp_f22;
//         temp_s0->unk48 = temp_f0;

//         if ((!((temp_s1->unk48 + 35.0f) <= temp_f0))) {
//             temp_f20 = phi_f20 + 40.0f;
//             func_8008A2A0((temp_s0->unk60->unk60 * 0xC0) + D_800D03F8 + 0x74, temp_f20);
//             phi_f20 = temp_f20;
//             continue;
//         }
//         break;
//     }

//     func_800D9B54(temp_s0);
//     func_80048008(0);
// }

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80112DDC_32894C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80112E18_328988);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80112FA8_328B18);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80113364_328ED4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801135FC_32916C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80113708_329278);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801138E4_329454);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80114590_32A100);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80114650_32A1C0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80114B80_32A6F0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011548C_32AFFC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801155C4_32B134);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80115734_32B2A4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801158FC_32B46C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80115B80_32B6F0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80116484_32BFF4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011667C_32C1EC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801166F4_32C264);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80116758_32C2C8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80116904_32C474);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80116A04_32C574);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80116AA0_32C610);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80116BA0_32C710);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80116DAC_32C91C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80116F0C_32CA7C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80116F5C_32CACC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801174D4_32D044);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801176A4_32D214);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_801177DC_32D34C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80117C60_32D7D0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80118308_32DE78);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80118A98_32E608);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80118AE8_32E658);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80118B7C_32E6EC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80118D6C_32E8DC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80118E2C_32E99C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80118EEC_32EA5C);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80119924_32F494);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80119A20_32F590);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80119A60_32F5D0);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80119B3C_32F6AC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80119C54_32F7C4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_80119D08_32F878);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011A764_3302D4);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011A794_330304);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011A838_3303A8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011A8B8_330428);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011A8D8_330448);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011B9A0_331510);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011BBA4_331714);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011BD48_3318B8);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011BD8C_3318FC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011BF3C_331AAC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011C470_331FE0);

// entrypoint 4
void func_8011C58C_3320FC() {
    func_80012220(2);
    func_800124BC(1, &D_8011E8B8);
    func_80107CC4_31D834();
    func_800FF41C(2);
    func_80047EA0(func_801065D0_31C140, 0x1005, 0x1000, 0);
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011C5E0_332150);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011C68C_3321FC);

s32 func_8011C750_3322C0() {
    s32 temp_s0;
    s32 phi_v1;

    temp_s0 = D_800CD05A - D_800CD05B + 1;

    phi_v1 = func_800E49DC(-1);
    if (phi_v1 == -1) {
        phi_v1 = 3;
    }

    return (phi_v1 < temp_s0) ? 0 : 1;
}

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011C7A4_332314);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011C88C_3323FC);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011CE94_332A04);

INCLUDE_ASM(s32, "overlays/board_chillywaters/chillywaters", func_8011D1F8_332D68);
