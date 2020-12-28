#include "common.h"
#include "../../board.h"
#include "../../player.h"
#include "../../process.h"
#include "../../object.h"
#include "../../spaces.h"

extern s32 D_800A12D4;

extern u16 D_800CE198;

extern struct event_table_entry *D_8011D1C4;
extern struct event_table_entry *D_8011D23C;
extern struct event_table_entry *D_8011D3D0;
extern struct event_table_entry *D_8011D478;

extern void *D_8011D598;

extern struct object *D_8011EB0C;

extern void func_8011A704_363574();

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801059D0_34E840);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801059F8_34E868);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80105B44_34E9B4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80105C50_34EAC0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80105D20_34EB90);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80105DB0_34EC20);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801061A0_34F010);

// Star tour.
INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010622C_34F09C);
// void func_8010622C_34F09C() {
//     s32 temp_a0;
//     s32 temp_a0_2;
//     s32 temp_s0;
//     struct space_data *temp_s2;
//     struct space_data *temp_s4;
//     void *temp_s1;
//     struct process *temp_v0;
//     struct process *temp_v0_2;
//     s32 msgIdx;
//     s32 phi_s2;
//     s32 phi_s4;

//     D_800A12D4 = 0;
//     temp_s1 = func_800E5DD4(0, 0);
//     func_8004A520(0x12);
//     func_800EEFEC(temp_s1->unk0, 2, 0xF, 0x000A007E);
//     func_800FFF44();
//     func_800D9B24(D_8011EAC8[D_800CD058.star_spawn_indices[D_800CD058.current_star_spawn]]]);
//     func_800D9B24(D_8011EAC8[D_800CD058.unk3E]);
//     func_80061FE8(2, 0x10);

//     while (func_800620BC() != 0) {
//         SleepVProcess();
//     }

//     func_800E6FCC();
//     func_800E9730(3.0f);
//     func_801061A0_34F010(temp_s1);
//     temp_s2 = GetSpaceData(D_8011C150[D_800CD058.star_spawn_indices[D_800CD058.current_star_spawn]]);
//     temp_s4 = GetSpaceData(D_8011C150[D_800CD096]);
//     phi_s2 = temp_s2;
//     phi_s4 = temp_s4;
//     if (func_800ECE9C(0x32) != 0) {
//         phi_s2 = temp_s4;
//         phi_s4 = temp_s2;
//     }
//     msgIdx = 0x5E0A;
//     if (D_800CD058.current_star_spawn == 0) {
//         if (func_80035F98(4) != 0) {
//             msgIdx = 0x5E0A;
//         }
//         else {
//             msgIdx = 0x5E09;
//         }
//     }
//     func_8005B43C(temp_s1->unk8, msgIdx, -1, -1);

//     func_80060C14(temp_s1->unk8, 1);
//     func_8004AA88(0x2A7);
//     temp_s0 = phi_s2;
//     func_800EE2C0(temp_s1->unk8);
//     func_800D9D84(temp_s1->unk0, -1, 0, 6, 2);
//     func_80060EA8(temp_s1->unk8, 1);
//     func_8001FDE8(*temp_s1->unk0->unk3C->unk40);
//     func_800E9748(&temp_s0->coords);
//     func_800E9AC8(5.0f);
//     SleepProcess(5);
//     while (func_800E9AE0() != 0) {
//         SleepVProcess();
//     }
//     SleepProcess(5);
//     func_800D9CE8(temp_s1->unk0, -1, 2);
//     temp_v0 = InitProcess(func_80105DB0_34EC20, 0x4800, 0, 0);
//     D_8011EB08 = temp_v0;
//     temp_v0->user_data = temp_s0;
//     SleepProcess(0x1E);
//     temp_a0 = D_800CC69C;
//     ((temp_s1->unk8 * 0x27C) + temp_a0)->unk20 = (u8)1;
//     SleepVProcess(temp_a0);

//     func_80060C14(temp_s1->unk8, 1);
//     func_800EE2C0(temp_s1->unk8);
//     func_800D9D84(temp_s1->unk0, -1, 0, 6, 2);
//     func_80060EA8(temp_s1->unk8, 1);
//     while (D_8011EB08 != 0) {
//         SleepVProcess();
//     }
//     func_800E9748(&phi_s4->coords);
//     func_800E9AC8(5.0f);
//     SleepProcess(5);

//     while (func_800E9AE0() != 0) {
//         SleepVProcess();
//     }
//     SleepProcess(5);

//     temp_v0_2 = InitProcess(func_80105DB0_34EC20, 0x4800, 0, 0);
//     D_8011EB08 = temp_v0_2;
//     temp_v0_2->user_data = phi_s4;
//     SleepProcess(0x1E);
//     temp_a0_2 = D_800CC69C;
//     ((temp_s1->unk8 * 0x27C) + temp_a0_2)->unk20 = (u8)1;
//     SleepVProcess(temp_a0_2);
//     func_80060C14(temp_s1->unk8, 1);
//     func_800EE2C0(temp_s1->unk8);
//     func_80060EA8(temp_s1->unk8, 1);
//     func_8004A994(0x5A);
//     SleepProcess(0x1E);
//     func_80062050(2, 0x10);
//     SleepProcess(0x11);
//     D_800A12D4 = 1;
//     func_80100130();
//     func_80046558(D_8011EB0C->unk3C->unk40->unk0);
//     func_800D9B54(D_8011EB0C);
//     func_800D9AA4(D_8011EAC8[D_800CD058.star_spawn_indices[D_800CD058.current_star_spawn]]);
//     func_800D9AA4(D_8011EAC8[D_800CD05D.unk39]);
//     func_800E60D8(temp_s1);
//     func_800F8C74();
//     func_8004819C(1);
//     func_8004849C();
//     SleepVProcess();
// }

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801066CC_34F53C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80106C2C_34FA9C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80106CA0_34FB10);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80106D28_34FB98);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80106D84_34FBF4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80106E54_34FCC4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80106EB4_34FD24);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107148_34FFB8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107360_3501D0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107490_350300);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107628_350498);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801078F4_350764);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107914_350784);

// entrypoint 0
INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107934_3507A4);

// entrypoint 1
INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107970_3507E0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107A04_350874);

// entrypoint 2
void func_80107CA4_350B14() {
    func_8004A520(0x1A);
    D_800CE198 = 0x1A;
    func_800F8D6C(0x1A);
    func_80012220(2);
    func_80107A04_350874();
    func_800EBA60(&D_8011D1C4);
    func_800EBA60(&D_8011D478);
    func_800F8D48(func_8011A704_363574);
    func_800EBA60(&D_8011D23C);
    func_800EBA60(&D_8011D3D0);
    func_800FF41C(0);
}

// entrypoint 3
INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107D28_350B98);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107D54_350BC4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107ECC_350D3C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107F30_350DA0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80107FF8_350E68);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108118_350F88);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108174_350FE4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108270_3510E0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801083DC_35124C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108444_3512B4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801085B0_351420);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108610_351480);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010866C_3514DC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108734_3515A4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801087E4_351654);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108820_351690);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801088A0_351710);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108918_351788);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801089AC_35181C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108AB8_351928);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108ADC_35194C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108B98_351A08);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108C48_351AB8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108C80_351AF0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108CB8_351B28);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108CF0_351B60);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108DA0_351C10);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108DD8_351C48);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108E30_351CA0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108E88_351CF8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108EE0_351D50);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80108F38_351DA8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109268_3520D8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801092C8_352138);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109328_352198);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109388_3521F8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801093E8_352258);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109448_3522B8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801094A8_352318);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109508_352378);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109568_3523D8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801095C8_352438);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109628_352498);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109688_3524F8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801096E8_352558);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109748_3525B8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801097A8_352618);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109808_352678);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109868_3526D8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801098C8_352738);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109AD8_352948);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109E90_352D00);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109E98_352D08);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109F3C_352DAC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80109F44_352DB4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010A1C8_353038);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010A284_3530F4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010A2C4_353134);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010A930_3537A0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010B46C_3542DC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010B4F4_354364);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010B55C_3543CC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010B734_3545A4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010C9EC_35585C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010CA8C_3558FC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010CB2C_35599C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010CF74_355DE4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010CF98_355E08);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010DDC4_356C34);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010DF18_356D88);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010DF54_356DC4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010F128_357F98);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010F144_357FB4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010F160_357FD0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010F2BC_35812C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010F3D4_358244);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010F79C_35860C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010F808_358678);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010F9C8_358838);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010FC2C_358A9C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010FCFC_358B6C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8010FF2C_358D9C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801100FC_358F6C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011026C_3590DC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801105B8_359428);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011077C_3595EC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80110A14_359884);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80110CA0_359B10);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80110EE0_359D50);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801110F0_359F60);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801113B0_35A220);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80111750_35A5C0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011214C_35AFBC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80112694_35B504);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801128B0_35B720);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80112CA4_35BB14);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80112D60_35BBD0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80112EB4_35BD24);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80112EF0_35BD60);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80113080_35BEF0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011343C_35C2AC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801136D4_35C544);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801137E0_35C650);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801139BC_35C82C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80114668_35D4D8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80114728_35D598);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80114C58_35DAC8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80115564_35E3D4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011569C_35E50C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011580C_35E67C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801159D4_35E844);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80115C58_35EAC8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011655C_35F3CC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80116754_35F5C4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801167CC_35F63C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80116830_35F6A0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801169DC_35F84C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80116ADC_35F94C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80116B78_35F9E8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80116C78_35FAE8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80116E84_35FCF4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80116FE4_35FE54);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80117034_35FEA4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801175AC_36041C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011777C_3605EC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801178B4_360724);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80117D38_360BA8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_801183E0_361250);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80118E3C_361CAC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80118F64_361DD4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011908C_361EFC);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80119120_361F90);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_80119290_362100);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011A2BC_36312C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011A338_3631A8);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011A550_3633C0);

INCLUDE_ASM(void, "overlays/board_spinydesert/spinydesert", func_8011A704_363574);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011B1FC_36406C);

// entrypoint 4
void func_8011B41C_36428C() {
    func_80012220(2);
    func_800124BC(1, &D_8011D598);
    func_80107A04_350874();
    func_800FF41C(2);
    InitProcess(func_8010622C_34F09C, 0x1005, 0x1000, 0);
}

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011B470_3642E0);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011B51C_36438C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011B5E0_364450);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011B634_3644A4);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011B71C_36458C);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011BD24_364B94);

INCLUDE_ASM(s32, "overlays/board_spinydesert/spinydesert", func_8011C088_364EF8);
