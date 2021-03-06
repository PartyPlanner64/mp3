#include "common.h"
#include "object.h"

u8 D_800962F0 = 0;

struct overlay_info {
    u32 rom_start;
    u32 rom_end;
    u32 ram_start;
    u32 code_start;
    u32 code_end;
    u32 data_start;
    u32 data_end;
    u32 bss_start;
    u32 bss_end;
}; // sizeof 0x24

struct overlay_info D_800962F4[] = {
#ifndef CC_CHECK
    { &code_overlay0_ROM_START, &code_overlay0_ROM_END, &code_overlay0_VRAM, 0x801059A0, 0x80108BE0, 0x80108BE0, 0x80109B00, 0x80109B00, 0x80109D20 },
    { &code_overlay1_ROM_START, &code_overlay1_ROM_END, &code_overlay1_VRAM, 0x801059A0, 0x8010BF00, 0x8010BF00, 0x8010C0E0, 0x8010C0E0, 0x8010C1A0 },
    { &code_overlay2_ROM_START, &code_overlay2_ROM_END, &code_overlay2_VRAM, 0x801059A0, 0x8010AF60, 0x8010AF60, 0x8010B1C0, 0x8010B1C0, 0x8010CBD0 },
    { &code_overlay3_ROM_START, &code_overlay3_ROM_END, &code_overlay3_VRAM, 0x801059A0, 0x8010CCC0, 0x8010CCC0, 0x8010D2F0, 0x8010D2F0, 0x8010EE70 },
    { &code_overlay4_ROM_START, &code_overlay4_ROM_END, &code_overlay4_VRAM, 0x801059A0, 0x80109700, 0x80109700, 0x80109880, 0x80109880, 0x801098B0 },
    { &code_overlay5_ROM_START, &code_overlay5_ROM_END, &code_overlay5_VRAM, 0x801059A0, 0x8010B810, 0x8010B810, 0x8010B990, 0x8010B990, 0x8010DEC0 },
    { &code_overlay6_ROM_START, &code_overlay6_ROM_END, &code_overlay6_VRAM, 0x801059A0, 0x8010C370, 0x8010C370, 0x8010C760, 0x8010C760, 0x8010E1C0 },
    { &code_overlay7_ROM_START, &code_overlay7_ROM_END, &code_overlay7_VRAM, 0x801059A0, 0x80110CB0, 0x80110CB0, 0x801117F0, 0x801117F0, 0x80111AA0 },
    { &code_overlay8_ROM_START, &code_overlay8_ROM_END, &code_overlay8_VRAM, 0x801059A0, 0x8010ED60, 0x8010ED60, 0x8010F470, 0x8010F470, 0x8010F5C0 },
    { &code_overlay9_ROM_START, &code_overlay9_ROM_END, &code_overlay9_VRAM, 0x801059A0, 0x8010D3B0, 0x8010D3B0, 0x8010D9D0, 0x8010D9D0, 0x80110DF0 },
    { &code_overlay10_ROM_START, &code_overlay10_ROM_END, &code_overlay10_VRAM, 0x801059A0, 0x8010AA70, 0x8010AA70, 0x8010ADE0, 0x8010ADE0, 0x8010B0E0 },
    { &code_overlay11_ROM_START, &code_overlay11_ROM_END, &code_overlay11_VRAM, 0x801059A0, 0x80109100, 0x80109100, 0x80109260, 0x80109260, 0x801093E0 },
    { &code_overlay12_ROM_START, &code_overlay12_ROM_END, &code_overlay12_VRAM, 0x801059A0, 0x8010FD60, 0x8010FD60, 0x80110000, 0x80110000, 0x80110030 },
    { &code_overlay13_ROM_START, &code_overlay13_ROM_END, &code_overlay13_VRAM, 0x801059A0, 0x80110E70, 0x80110E70, 0x801116E0, 0x801116E0, 0x80113630 },
    { &code_overlay14_ROM_START, &code_overlay14_ROM_END, &code_overlay14_VRAM, 0x801059A0, 0x8010BDE0, 0x8010BDE0, 0x8010BF40, 0x8010BF40, 0x8010C040 },
    { &code_overlay15_ROM_START, &code_overlay15_ROM_END, &code_overlay15_VRAM, 0x801059A0, 0x8010E5B0, 0x8010E5B0, 0x8010EC20, 0x8010EC20, 0x8010F010 },
    { &code_overlay16_ROM_START, &code_overlay16_ROM_END, &code_overlay16_VRAM, 0x801059A0, 0x8010BB30, 0x8010BB30, 0x8010C010, 0x8010C010, 0x8010C3D0 },
    { &code_overlay17_ROM_START, &code_overlay17_ROM_END, &code_overlay17_VRAM, 0x801059A0, 0x80111220, 0x80111220, 0x80111650, 0x80111650, 0x80111680 },
    { &code_overlay18_ROM_START, &code_overlay18_ROM_END, &code_overlay18_VRAM, 0x801059A0, 0x8010C6A0, 0x8010C6A0, 0x8010C830, 0x8010C830, 0x801113F0 },
    { &code_overlay19_ROM_START, &code_overlay19_ROM_END, &code_overlay19_VRAM, 0x801059A0, 0x8010DE90, 0x8010DE90, 0x8010E590, 0x8010E590, 0x8010E670 },
    { &code_overlay20_ROM_START, &code_overlay20_ROM_END, &code_overlay20_VRAM, 0x801059A0, 0x8010D7F0, 0x8010D7F0, 0x8010DF40, 0x8010DF40, 0x8010E020 },
    { &code_overlay21_ROM_START, &code_overlay21_ROM_END, &code_overlay21_VRAM, 0x801059A0, 0x8010AF80, 0x8010AF80, 0x8010B2E0, 0x8010B2E0, 0x8010B470 },
    { &code_overlay22_ROM_START, &code_overlay22_ROM_END, &code_overlay22_VRAM, 0x801059A0, 0x8010EDA0, 0x8010EDA0, 0x8010F3D0, 0x8010F3D0, 0x8010F680 },
    { &code_overlay23_ROM_START, &code_overlay23_ROM_END, &code_overlay23_VRAM, 0x801059A0, 0x8010DB40, 0x8010DB40, 0x8010DE50, 0x8010DE50, 0x8010DF30 },
    { &code_overlay24_ROM_START, &code_overlay24_ROM_END, &code_overlay24_VRAM, 0x801059A0, 0x8010ABB0, 0x8010ABB0, 0x8010AEB0, 0x8010AEB0, 0x8010AEF0 },
    { &code_overlay25_ROM_START, &code_overlay25_ROM_END, &code_overlay25_VRAM, 0x801059A0, 0x80108550, 0x80108550, 0x801086D0, 0x801086D0, 0x80108700 },
    { &code_overlay26_ROM_START, &code_overlay26_ROM_END, &code_overlay26_VRAM, 0x801059A0, 0x8010A110, 0x8010A110, 0x8010A580, 0x8010A580, 0x8010A710 },
    { &code_overlay27_ROM_START, &code_overlay27_ROM_END, &code_overlay27_VRAM, 0x801059A0, 0x8010A820, 0x8010A820, 0x8010AA60, 0x8010AA60, 0x8010AB00 },
    { &code_overlay28_ROM_START, &code_overlay28_ROM_END, &code_overlay28_VRAM, 0x801059A0, 0x8010A8A0, 0x8010A8A0, 0x8010AB50, 0x8010AB50, 0x8010AD10 },
    { &code_overlay29_ROM_START, &code_overlay29_ROM_END, &code_overlay29_VRAM, 0x801059A0, 0x80110FC0, 0x80110FC0, 0x80111600, 0x80111600, 0x80115DA0 },
    { &code_overlay30_ROM_START, &code_overlay30_ROM_END, &code_overlay30_VRAM, 0x801059A0, 0x80109FE0, 0x80109FE0, 0x8010A110, 0x8010A110, 0x8010A2C0 },
    { &code_overlay31_ROM_START, &code_overlay31_ROM_END, &code_overlay31_VRAM, 0x801059A0, 0x80110080, 0x80110080, 0x801102E0, 0x801102E0, 0x801168E0 },
    { &code_overlay32_ROM_START, &code_overlay32_ROM_END, &code_overlay32_VRAM, 0x801059A0, 0x8010C280, 0x8010C280, 0x8010C460, 0x8010C460, 0x8010C5A0 },
    { &code_overlay33_ROM_START, &code_overlay33_ROM_END, &code_overlay33_VRAM, 0x801059A0, 0x8010C680, 0x8010C680, 0x8010C9B0, 0x8010C9B0, 0x8010D030 },
    { &code_overlay34_ROM_START, &code_overlay34_ROM_END, &code_overlay34_VRAM, 0x801059A0, 0x8010B0C0, 0x8010B0C0, 0x8010B4B0, 0x8010B4B0, 0x8010CF40 },
    { &code_overlay35_ROM_START, &code_overlay35_ROM_END, &code_overlay35_VRAM, 0x801059A0, 0x8010A160, 0x8010A160, 0x8010A560, 0x8010A560, 0x8010AC90 },
    { &code_overlay36_ROM_START, &code_overlay36_ROM_END, &code_overlay36_VRAM, 0x801059A0, 0x8010CF20, 0x8010CF20, 0x8010D340, 0x8010D340, 0x80110AF0 },
    { &code_overlay37_ROM_START, &code_overlay37_ROM_END, &code_overlay37_VRAM, 0x801059A0, 0x8010CB60, 0x8010CB60, 0x8010D0D0, 0x8010D0D0, 0x8010D400 },
    { &code_overlay38_ROM_START, &code_overlay38_ROM_END, &code_overlay38_VRAM, 0x801059A0, 0x8010E010, 0x8010E010, 0x8010E360, 0x8010E360, 0x8010E3A0 },
    { &code_overlay39_ROM_START, &code_overlay39_ROM_END, &code_overlay39_VRAM, 0x801059A0, 0x80109EC0, 0x80109EC0, 0x8010A2B0, 0x8010A2B0, 0x8010AD60 },
    { &code_overlay40_ROM_START, &code_overlay40_ROM_END, &code_overlay40_VRAM, 0x801059A0, 0x8010F550, 0x8010F550, 0x8010F880, 0x8010F880, 0x801102A0 },
    { &code_overlay41_ROM_START, &code_overlay41_ROM_END, &code_overlay41_VRAM, 0x801059A0, 0x80109930, 0x80109930, 0x80109AC0, 0x80109AC0, 0x80109C60 },
    { &code_overlay42_ROM_START, &code_overlay42_ROM_END, &code_overlay42_VRAM, 0x801059A0, 0x8010F290, 0x8010F290, 0x8010F6F0, 0x8010F6F0, 0x80111180 },
    { &code_overlay43_ROM_START, &code_overlay43_ROM_END, &code_overlay43_VRAM, 0x801059A0, 0x8010CD10, 0x8010CD10, 0x8010D230, 0x8010D230, 0x8010EC60 },
    { &code_overlay44_ROM_START, &code_overlay44_ROM_END, &code_overlay44_VRAM, 0x801059A0, 0x80110EE0, 0x80110EE0, 0x80111AC0, 0x80111AC0, 0x80111C60 },
    { &code_overlay45_ROM_START, &code_overlay45_ROM_END, &code_overlay45_VRAM, 0x801059A0, 0x8010C140, 0x8010C140, 0x8010C410, 0x8010C410, 0x8010DEE0 },
    { &code_overlay46_ROM_START, &code_overlay46_ROM_END, &code_overlay46_VRAM, 0x801059A0, 0x8010A6A0, 0x8010A6A0, 0x8010AA10, 0x8010AA10, 0x8010C480 },
    { &code_overlay47_ROM_START, &code_overlay47_ROM_END, &code_overlay47_VRAM, 0x801059A0, 0x8010C8B0, 0x8010C8B0, 0x8010CCA0, 0x8010CCA0, 0x8010CF80 },
    { &code_overlay48_ROM_START, &code_overlay48_ROM_END, &code_overlay48_VRAM, 0x801059A0, 0x8010AC10, 0x8010AC10, 0x8010AF20, 0x8010AF20, 0x8010CC40 },
    { &code_overlay49_ROM_START, &code_overlay49_ROM_END, &code_overlay49_VRAM, 0x801059A0, 0x80111B50, 0x80111B50, 0x80112590, 0x80112590, 0x801156A0 },
    { &code_overlay50_ROM_START, &code_overlay50_ROM_END, &code_overlay50_VRAM, 0x801059A0, 0x8010C590, 0x8010C590, 0x8010CBD0, 0x8010CBD0, 0x8010DEE0 },
    { &code_overlay51_ROM_START, &code_overlay51_ROM_END, &code_overlay51_VRAM, 0x801059A0, 0x8010C5A0, 0x8010C5A0, 0x8010C730, 0x8010C730, 0x8010C7E0 },
    { &code_overlay52_ROM_START, &code_overlay52_ROM_END, &code_overlay52_VRAM, 0x801059A0, 0x8010F150, 0x8010F150, 0x8010FB50, 0x8010FB50, 0x8010FBE0 },
    { &code_overlay53_ROM_START, &code_overlay53_ROM_END, &code_overlay53_VRAM, 0x801059A0, 0x8010B400, 0x8010B400, 0x8010BC00, 0x8010BC00, 0x8010BD30 },
    { &code_overlay54_ROM_START, &code_overlay54_ROM_END, &code_overlay54_VRAM, 0x801059A0, 0x80111550, 0x80111550, 0x801137C0, 0x801137C0, 0x801137F0 },
    { &code_overlay55_ROM_START, &code_overlay55_ROM_END, &code_overlay55_VRAM, 0x801059A0, 0x8010BE20, 0x8010BE20, 0x8010BF80, 0x8010BF80, 0x8010BFA0 },
    { &code_overlay56_ROM_START, &code_overlay56_ROM_END, &code_overlay56_VRAM, 0x801059A0, 0x8010C6C0, 0x8010C6C0, 0x8010CF80, 0x8010CF80, 0x8010D9F0 },
    { &code_overlay57_ROM_START, &code_overlay57_ROM_END, &code_overlay57_VRAM, 0x801059A0, 0x8010E4A0, 0x8010E4A0, 0x8010E6E0, 0x8010E6E0, 0x8010E710 },
    { &code_overlay58_ROM_START, &code_overlay58_ROM_END, &code_overlay58_VRAM, 0x801059A0, 0x8010E7A0, 0x8010E7A0, 0x8010F200, 0x8010F200, 0x8010F440 },
    { &code_overlay59_ROM_START, &code_overlay59_ROM_END, &code_overlay59_VRAM, 0x801059A0, 0x8010A260, 0x8010A260, 0x8010A460, 0x8010A460, 0x8010A4D0 },
    { &code_overlay60_ROM_START, &code_overlay60_ROM_END, &code_overlay60_VRAM, 0x801059A0, 0x80109B60, 0x80109B60, 0x80109EA0, 0x80109EA0, 0x80109F40 },
    { &code_overlay61_ROM_START, &code_overlay61_ROM_END, &code_overlay61_VRAM, 0x801059A0, 0x80109720, 0x80109720, 0x80109B00, 0x80109B00, 0x80109B70 },
    { &code_overlay62_ROM_START, &code_overlay62_ROM_END, &code_overlay62_VRAM, 0x801059A0, 0x8010A040, 0x8010A040, 0x8010A1F0, 0x8010A1F0, 0x8010A270 },
    { &code_swinging_with_sharks_ROM_START, &code_swinging_with_sharks_ROM_END, &code_swinging_with_sharks_VRAM, 0x801059A0, 0x8010ACE0, 0x8010ACE0, 0x8010B860, 0x8010B860, 0x8010BBC0 },
    { &code_overlay64_ROM_START, &code_overlay64_ROM_END, &code_overlay64_VRAM, 0x801059A0, 0x8010BD30, 0x8010BD30, 0x8010C090, 0x8010C090, 0x8010C1E0 },
    { &code_overlay65_ROM_START, &code_overlay65_ROM_END, &code_overlay65_VRAM, 0x801059A0, 0x80113CB0, 0x80113CB0, 0x80114940, 0x80114940, 0x80114BE0 },
    { &code_overlay66_ROM_START, &code_overlay66_ROM_END, &code_overlay66_VRAM, 0x801059A0, 0x8010A640, 0x8010A640, 0x8010A810, 0x8010A810, 0x8010AC50 },
    { &code_overlay67_ROM_START, &code_overlay67_ROM_END, &code_overlay67_VRAM, 0x801059A0, 0x8010D150, 0x8010D150, 0x8010D5D0, 0x8010D5D0, 0x8010D900 },
    { &code_overlay68_ROM_START, &code_overlay68_ROM_END, &code_overlay68_VRAM, 0x801059A0, 0x8010C1E0, 0x8010C1E0, 0x8010C5D0, 0x8010C5D0, 0x8010CB10 },
    { &code_overlay69_ROM_START, &code_overlay69_ROM_END, &code_overlay69_VRAM, 0x801059A0, 0x8010CB70, 0x8010CB70, 0x8010CE50, 0x8010CE50, 0x8010D100 },
    { &code_overlay70_ROM_START, &code_overlay70_ROM_END, &code_overlay70_VRAM, 0x801059A0, 0x80109740, 0x80109740, 0x80109F60, 0x80109F60, 0x8010A150 },
    { &code_overlay71_ROM_START, &code_overlay71_ROM_END, &code_overlay71_VRAM, 0x801059A0, 0x80105AE0, 0x80105AE0, 0x80105B00, 0x80105B00, 0x80105B00 },
    { &code_board_chillywaters_ROM_START, &code_board_chillywaters_ROM_END, &code_board_chillywaters_VRAM, 0x801059A0, 0x8011D250, 0x8011D250, 0x8011FA70, 0x8011FA70, 0x8011FBC0 },
    { &code_board_deepbloobersea_ROM_START, &code_board_deepbloobersea_ROM_END, &code_board_deepbloobersea_VRAM, 0x801059A0, 0x8011C630, 0x8011C630, 0x8011EBD0, 0x8011EBD0, 0x8011ED10 },
    { &code_board_spinydesert_ROM_START, &code_board_spinydesert_ROM_END, &code_board_spinydesert_VRAM, 0x801059A0, 0x8011C0E0, 0x8011C0E0, 0x8011EAC0, 0x8011EAC0, 0x8011EC10 },
    { &code_board_woodywoods_ROM_START, &code_board_woodywoods_ROM_END, &code_board_woodywoods_VRAM, 0x801059A0, 0x8011B710, 0x8011B710, 0x8011DFF0, 0x8011DFF0, 0x8011E120 },
    { &code_board_creepycavern_ROM_START, &code_board_creepycavern_ROM_END, &code_board_creepycavern_VRAM, 0x801059A0, 0x8011D010, 0x8011D010, 0x80120740, 0x80120740, 0x801208A0 },
    { &code_board_waluigisisland_ROM_START, &code_board_waluigisisland_ROM_END, &code_board_waluigisisland_VRAM, 0x801059A0, 0x8011B550, 0x8011B550, 0x8011E270, 0x8011E270, 0x8011E3B0 },
    { &code_overlay78_ROM_START, &code_overlay78_ROM_END, &code_overlay78_VRAM, 0x801059A0, 0x8010B7D0, 0x8010B7D0, 0x8010BA20, 0x8010BA20, 0x8010BAA0 },
    { &code_overlay79_ROM_START, &code_overlay79_ROM_END, &code_overlay79_VRAM, 0x801059A0, 0x8010E3E0, 0x8010E3E0, 0x8010EAF0, 0x8010EAF0, 0x8010EBD0 },
    { &code_overlay80_ROM_START, &code_overlay80_ROM_END, &code_overlay80_VRAM, 0x801059A0, 0x80109350, 0x80109350, 0x801094F0, 0x801094F0, 0x80109570 },
    { &code_overlay81_ROM_START, &code_overlay81_ROM_END, &code_overlay81_VRAM, 0x801059A0, 0x80107480, 0x80107480, 0x80107550, 0x80107550, 0x80107580 },
    { &code_overlay82_ROM_START, &code_overlay82_ROM_END, &code_overlay82_VRAM, 0x801059A0, 0x801080D0, 0x801080D0, 0x801082E0, 0x801082E0, 0x801083D0 },
    { &code_overlay83_ROM_START, &code_overlay83_ROM_END, &code_overlay83_VRAM, 0x801059A0, 0x80108D70, 0x80108D70, 0x80109060, 0x80109060, 0x80109080 },
    { &code_overlay84_ROM_START, &code_overlay84_ROM_END, &code_overlay84_VRAM, 0x801059A0, 0x801075C0, 0x801075C0, 0x80107760, 0x80107760, 0x801077A0 },
    { &code_overlay85_ROM_START, &code_overlay85_ROM_END, &code_overlay85_VRAM, 0x801059A0, 0x801097B0, 0x801097B0, 0x801099A0, 0x801099A0, 0x80109A50 },
    { &code_overlay86_ROM_START, &code_overlay86_ROM_END, &code_overlay86_VRAM, 0x801059A0, 0x80106E80, 0x80106E80, 0x80107950, 0x80107950, 0x80107AE0 },
    { &code_overlay87_ROM_START, &code_overlay87_ROM_END, &code_overlay87_VRAM, 0x801059A0, 0x80106DB0, 0x80106DB0, 0x80106EC0, 0x80106EC0, 0x80107060 },
    { &code_intro_ROM_START, &code_intro_ROM_END, &code_intro_VRAM, 0x801059A0, 0x80105EE0, 0x80105EE0, 0x80105F10, 0x80105F10, 0x80105F20 },
    { &code_overlay89_ROM_START, &code_overlay89_ROM_END, &code_overlay89_VRAM, 0x801059A0, 0x80106960, 0x80106960, 0x80106C10, 0x80106C10, 0x80106C40 },
    { &code_overlay90_ROM_START, &code_overlay90_ROM_END, &code_overlay90_VRAM, 0x801059A0, 0x80105AE0, 0x80105AE0, 0x80105B00, 0x80105B00, 0x80105B00 },
    { &code_overlay91_ROM_START, &code_overlay91_ROM_END, &code_overlay91_VRAM, 0x801059A0, 0x801186E0, 0x801186E0, 0x80119470, 0x80119470, 0x801194C0 },
    { &code_overlay92_ROM_START, &code_overlay92_ROM_END, &code_overlay92_VRAM, 0x801059A0, 0x80116570, 0x80116570, 0x80117600, 0x80117600, 0x80117640 },
    { &code_overlay93_ROM_START, &code_overlay93_ROM_END, &code_overlay93_VRAM, 0x801059A0, 0x80117400, 0x80117400, 0x801180C0, 0x801180C0, 0x80118110 },
    { &code_overlay94_ROM_START, &code_overlay94_ROM_END, &code_overlay94_VRAM, 0x801059A0, 0x80119C70, 0x80119C70, 0x8011B4E0, 0x8011B4E0, 0x8011B520 },
    { &code_overlay95_ROM_START, &code_overlay95_ROM_END, &code_overlay95_VRAM, 0x801059A0, 0x80115680, 0x80115680, 0x801163A0, 0x801163A0, 0x801163E0 },
    { &code_overlay96_ROM_START, &code_overlay96_ROM_END, &code_overlay96_VRAM, 0x801059A0, 0x80114480, 0x80114480, 0x80114D30, 0x80114D30, 0x80114D80 },
    { &code_overlay97_ROM_START, &code_overlay97_ROM_END, &code_overlay97_VRAM, 0x801059A0, 0x801149B0, 0x801149B0, 0x80114CB0, 0x80114CB0, 0x80114CF0 },
    { &code_overlay98_ROM_START, &code_overlay98_ROM_END, &code_overlay98_VRAM, 0x801059A0, 0x8010D290, 0x8010D290, 0x8010D860, 0x8010D860, 0x8010D950 },
    { &code_overlay99_ROM_START, &code_overlay99_ROM_END, &code_overlay99_VRAM, 0x801059A0, 0x80108C30, 0x80108C30, 0x80108DB0, 0x80108DB0, 0x80108E40 },
    { &code_overlay100_ROM_START, &code_overlay100_ROM_END, &code_overlay100_VRAM, 0x801059A0, 0x80109200, 0x80109200, 0x80109570, 0x80109570, 0x80109590 },
    { &code_overlay101_ROM_START, &code_overlay101_ROM_END, &code_overlay101_VRAM, 0x801059A0, 0x80108930, 0x80108930, 0x80108C10, 0x80108C10, 0x80108C50 },
    { &code_overlay102_ROM_START, &code_overlay102_ROM_END, &code_overlay102_VRAM, 0x801059A0, 0x801066E0, 0x801066E0, 0x801068C0, 0x801068C0, 0x80106AC0 },
    { &code_overlay103_ROM_START, &code_overlay103_ROM_END, &code_overlay103_VRAM, 0x801059A0, 0x80105F20, 0x80105F20, 0x80105F40, 0x80105F40, 0x80105F50 },
    { &code_overlay104_ROM_START, &code_overlay104_ROM_END, &code_overlay104_VRAM, 0x801059A0, 0x80109A80, 0x80109A80, 0x80109B20, 0x80109B20, 0x80109C30 },
    { &code_overlay105_ROM_START, &code_overlay105_ROM_END, &code_overlay105_VRAM, 0x801059A0, 0x80118EB0, 0x80118EB0, 0x8011A700, 0x8011A700, 0x8011B960 },
    { &code_overlay106_ROM_START, &code_overlay106_ROM_END, &code_overlay106_VRAM, 0x801059A0, 0x8010FAE0, 0x8010FAE0, 0x8010FE60, 0x8010FE60, 0x801100E0 },
    { &code_overlay107_ROM_START, &code_overlay107_ROM_END, &code_overlay107_VRAM, 0x801059A0, 0x80114A80, 0x80114A80, 0x801158B0, 0x801158B0, 0x80115CC0 },
    { &code_overlay108_ROM_START, &code_overlay108_ROM_END, &code_overlay108_VRAM, 0x801059A0, 0x8011B920, 0x8011B920, 0x8011C640, 0x8011C640, 0x8011CA90 },
    { &code_overlay109_ROM_START, &code_overlay109_ROM_END, &code_overlay109_VRAM, 0x801059A0, 0x80115260, 0x80115260, 0x80115B90, 0x80115B90, 0x80115DD0 },
    { &code_overlay110_ROM_START, &code_overlay110_ROM_END, &code_overlay110_VRAM, 0x801059A0, 0x80111AC0, 0x80111AC0, 0x80112120, 0x80112120, 0x801123C0 },
    { &code_overlay111_ROM_START, &code_overlay111_ROM_END, &code_overlay111_VRAM, 0x801059A0, 0x80114730, 0x80114730, 0x801151B0, 0x801151B0, 0x801156D0 },
    { &code_overlay112_ROM_START, &code_overlay112_ROM_END, &code_overlay112_VRAM, 0x801059A0, 0x8010D400, 0x8010D400, 0x8010DC00, 0x8010DC00, 0x8010DDF0 },
    { &code_overlay113_ROM_START, &code_overlay113_ROM_END, &code_overlay113_VRAM, 0x801059A0, 0x8010AAF0, 0x8010AAF0, 0x8010AD90, 0x8010AD90, 0x8010B080 },
    { &code_overlay114_ROM_START, &code_overlay114_ROM_END, &code_overlay114_VRAM, 0x801059A0, 0x801098C0, 0x801098C0, 0x801099E0, 0x801099E0, 0x8010A280 },
    { &code_overlay115_ROM_START, &code_overlay115_ROM_END, &code_overlay115_VRAM, 0x801059A0, 0x80108E70, 0x80108E70, 0x80108F30, 0x80108F30, 0x80109350 },
    { &code_overlay116_ROM_START, &code_overlay116_ROM_END, &code_overlay116_VRAM, 0x801059A0, 0x801088D0, 0x801088D0, 0x80108A30, 0x80108A30, 0x80108FA0 },
    { &code_overlay117_ROM_START, &code_overlay117_ROM_END, &code_overlay117_VRAM, 0x801059A0, 0x80105B40, 0x80105B40, 0x80105B80, 0x80105B80, 0x80105B80 },
    { &code_debug_message_check_ROM_START, &code_debug_message_check_ROM_END, &code_debug_message_check_VRAM, 0x801059A0, 0x80106500, 0x80106500, 0x80106E40, 0x80106E40, 0x80107010 },
    { &code_overlay119_ROM_START, &code_overlay119_ROM_END, &code_overlay119_VRAM, 0x801059A0, 0x8010F270, 0x8010F270, 0x8010F710, 0x8010F710, 0x80110DF0 },
    { &code_overlay120_ROM_START, &code_overlay120_ROM_END, &code_overlay120_VRAM, 0x801059A0, 0x80119410, 0x80119410, 0x8011A880, 0x8011A880, 0x8011AA50 },
    { &code_overlay121_ROM_START, &code_overlay121_ROM_END, &code_overlay121_VRAM, 0x801059A0, 0x801127A0, 0x801127A0, 0x80112E90, 0x80112E90, 0x801146E0 },
    { &code_overlay122_ROM_START, &code_overlay122_ROM_END, &code_overlay122_VRAM, 0x801059A0, 0x80114B50, 0x80114B50, 0x80114EA0, 0x80114EA0, 0x80117760 },
    { &code_overlay123_ROM_START, &code_overlay123_ROM_END, &code_overlay123_VRAM, 0x801059A0, 0x801134B0, 0x801134B0, 0x801146F0, 0x801146F0, 0x80115C00 },
    { &code_overlay124_ROM_START, &code_overlay124_ROM_END, &code_overlay124_VRAM, 0x801059A0, 0x80110530, 0x80110530, 0x80111490, 0x80111490, 0x80111570 },
    { &code_overlay125_ROM_START, &code_overlay125_ROM_END, &code_overlay125_VRAM, 0x801059A0, 0x8010A910, 0x8010A910, 0x8010ABE0, 0x8010ABE0, 0x8010AC40 },
    { 0x00552F50, 0x00552F50, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0 },
    { &code_overlay127_ROM_START, &code_overlay127_ROM_END, &code_overlay127_VRAM, 0x801059A0, 0x80108C90, 0x80108C90, 0x8010A070, 0x8010A070, 0x8010A290 }
#endif
};

struct overlay_info D_800974F4[] = {
#ifndef CC_CHECK
    { &code_shared_board_ROM_START, &code_shared_board_ROM_END, 0x800D6B70, 0x800D6B70, 0x801007A0, 0x801007A0, 0x80102700, 0x80102700, 0x801059A0 },
    { &code_overlay129_ROM_START, &code_overlay129_ROM_END, 0x800D6B70, 0x800D6B70, 0x80100E10, 0x80100E10, 0x801029C0, 0x801029C0, 0x80105720 },
    { &code_overlay130_ROM_START, &code_overlay130_ROM_END, 0x800D6B70, 0x800D6B70, 0x800EB720, 0x800EB720, 0x800EBDC0, 0x800EBDC0, 0x800EC5E0 }
#endif
};

struct str80097560 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct str80097560 D_80097560[] = {
    { 640.0f, 480.0f, 511.0f },
    { 640.0f, 480.0f, 511.0f },
    { 640.0f, 480.0f, 511.0f },
    { 640.0f, 480.0f, 511.0f },
    { 640.0f, 480.0f, 511.0f },
    { 0, 0, 0 }
};
struct str80097560 D_800975A8[] = {
    { 640.0f, 480.0f, 511.0f },
    { 640.0f, 480.0f, 511.0f },
    { 640.0f, 480.0f, 511.0f },
    { 640.0f, 480.0f, 511.0f },
    { 640.0f, 480.0f, 511.0f },
    { 0, 0, 0 }
};

struct str8000B364 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct str8000B364 D_800975F0[] = {
    { 0, 0, 320.0f, 240.0f },
    { 0, 0, 320.0f, 240.0f },
    { 0, 0, 320.0f, 240.0f },
    { 0, 0, 320.0f, 240.0f },
    { 0, 0, 320.0f, 240.0f },
    { 0, 0, 0, 0 }
};

u32 D_80097650 = 0x0000D9ED; // seed for random num generator.

extern s16 D_800D1FA2;

extern void func_800124BC(u8, struct str8000B364 *);
extern void func_80012508(u8, struct str80097560 *, struct str80097560 *);
extern void func_8004DB14(void *, void *, u32);

s32 func_8000B0A0(s32 arg0, s32 arg1) {
    return func_8001A150(ReadMainFS(arg0), arg1) & 0xFFFF;
}

s32 func_8000B0D4(s32 arg0, s32 arg1) {
    return func_8001A150(ReadMainFS(arg0), arg1) & 0xFFFF;
}

u32 func_8000B108(s32 arg0, s32 arg1) {
    return func_8001A150(ReadMainFS(arg0), arg1) & 0xFFFF;
}

s16 func_8000B13C(s32 arg0) {
    return func_8001A150(ReadMainFS(arg0), 0x1D);
}

u8 GetRandomByte() {
    u32 x;
    s32 x1;
    u32 x2;

    // Obviously a little rough...
    x1 = D_80097650;
    x1 = 0x41C64E6D * x1;
    x2 = x1;
    x = x2;
    x1 = 0x303A;
    D_80097650 = x2 + 0x3039;
    return (x + x1) >> 16;
}

void func_8000B1A0(s32 overlayIndex, u8 flags) {
    u32 rom_start;
    u32 code_start;
    u32 code_end;
    u32 data_start;
    u32 data_end;
    u32 bss_start;
    u32 bss_end;
    u32 ram_start;
    u8 *bssStartTemp;
    u32 bss_start_counter;

    rom_start = D_800974F4[overlayIndex].rom_start;
    code_start = D_800974F4[overlayIndex].code_start;
    code_end = D_800974F4[overlayIndex].code_end;
    data_start = D_800974F4[overlayIndex].data_start;
    data_end = D_800974F4[overlayIndex].data_end;
    bss_start = D_800974F4[overlayIndex].bss_start;
    bss_end = D_800974F4[overlayIndex].bss_end;
    ram_start = D_800974F4[overlayIndex].ram_start;

    if ((flags & 1) != 0) {
        func_8004DB14(rom_start, ram_start, code_end - code_start);
    }
    if ((flags & 2) != 0) {
        func_8004DB14(rom_start + (code_end - code_start), data_start, data_end - data_start);
    }
    if ((flags & 4) != 0) {
        bss_start_counter = bss_start;
        bssStartTemp = bss_start;
        while (bss_start_counter < bss_end) {
            *(bssStartTemp) = 0;
            bss_start_counter++;
            bssStartTemp = bssStartTemp + 1;
        }
    }
}

// copies in an overlay and clears bss region.
void func_8000B2C4(s32 overlayIndex) {
    s32 rom_start;
    s32 rom_end;
    s8 *bss_start;
    s8 *bss_end;
    s8 *temp;

    rom_start = D_800962F4[overlayIndex].rom_start;
    rom_end = D_800962F4[overlayIndex].rom_end;
    bss_start = D_800962F4[overlayIndex].bss_start;
    bss_end = D_800962F4[overlayIndex].bss_end;

    func_8004DB14(rom_start, D_800962F4[overlayIndex].ram_start, rom_end - rom_start);

    temp = bss_start;
    while (bss_start < bss_end) {
        *(temp++) = 0;
        bss_start++;
    }

    D_800962F0 = 0;
}

void func_8000B364(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    u8 i;

    i = arg0;
    D_800975F0[i].unk0 = arg1;
    D_800975F0[i].unk4 = arg2;
    D_800975F0[i].unk8 = arg3;
    D_800975F0[i].unkC = arg4;
    func_800124BC(arg0, &D_800975F0[i]);
}

void func_8000B3C8(u32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    u8 i;

    i = arg0;
    D_80097560[i].unk0 = arg1;
    D_80097560[i].unk4 = arg2;
    D_80097560[i].unk8 = arg3;
    D_800975A8[i].unk0 = arg4;
    D_800975A8[i].unk4 = arg5;
    D_800975A8[i].unk8 = arg6;
    func_80012508(arg0, &D_80097560[i], &D_800975A8[i]);
}

void func_8000B460(struct object_indirect *arg0, u16 arg1, s32 arg2) {
    s16 temp_v0;

    temp_v0 = func_8000B13C(arg2);
    if (temp_v0 >= 0) {
        arg0->unk48[arg1] = temp_v0;
    }
}

s8 func_8000B4B4() {
    s8 ret;
    if (D_800D1FA2 > D_800962F0) {
        ret = D_800962F0++;
    }
    else {
        ret = -1;
    }
    return ret;
}

s32 func_8000B4F8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = ReadMainFS(arg0);
    temp_s0 = func_8001443C(temp_s1, arg1, arg2 & 0xFF);
    FreePerm(temp_s1);
    return temp_s0 & 0xFFFF;
}

s16 func_8000B554(s32 arg0, s32 arg1, s32 arg2) {
    s16 temp_s0;
    s32 temp_s1;

    temp_s1 = ReadMainFS(arg1);
    temp_s0 = func_800323CC(arg0, temp_s1, 0, arg2);
    FreePerm(temp_s1);
    return temp_s0;
}

s16 func_8000B5BC(s32 arg0) {
    return func_8001A150(func_80009CD8(arg0, 0x7918), 0);
}
