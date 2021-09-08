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
    { &overlays_overlay0_ROM_START, &overlays_overlay0_ROM_END, &overlays_overlay0_VRAM, 0x801059A0, 0x80108BE0, 0x80108BE0, 0x80109B00, 0x80109B00, 0x80109D20 },
    { &overlays_overlay1_ROM_START, &overlays_overlay1_ROM_END, &overlays_overlay1_VRAM, 0x801059A0, 0x8010BF00, 0x8010BF00, 0x8010C0E0, 0x8010C0E0, 0x8010C1A0 },
    { &overlays_overlay2_ROM_START, &overlays_overlay2_ROM_END, &overlays_overlay2_VRAM, 0x801059A0, 0x8010AF60, 0x8010AF60, 0x8010B1C0, 0x8010B1C0, 0x8010CBD0 },
    { &overlays_overlay3_ROM_START, &overlays_overlay3_ROM_END, &overlays_overlay3_VRAM, 0x801059A0, 0x8010CCC0, 0x8010CCC0, 0x8010D2F0, 0x8010D2F0, 0x8010EE70 },
    { &overlays_overlay4_ROM_START, &overlays_overlay4_ROM_END, &overlays_overlay4_VRAM, 0x801059A0, 0x80109700, 0x80109700, 0x80109880, 0x80109880, 0x801098B0 },
    { &overlays_overlay5_ROM_START, &overlays_overlay5_ROM_END, &overlays_overlay5_VRAM, 0x801059A0, 0x8010B810, 0x8010B810, 0x8010B990, 0x8010B990, 0x8010DEC0 },
    { &overlays_overlay6_ROM_START, &overlays_overlay6_ROM_END, &overlays_overlay6_VRAM, 0x801059A0, 0x8010C370, 0x8010C370, 0x8010C760, 0x8010C760, 0x8010E1C0 },
    { &overlays_overlay7_ROM_START, &overlays_overlay7_ROM_END, &overlays_overlay7_VRAM, 0x801059A0, 0x80110CB0, 0x80110CB0, 0x801117F0, 0x801117F0, 0x80111AA0 },
    { &overlays_overlay8_ROM_START, &overlays_overlay8_ROM_END, &overlays_overlay8_VRAM, 0x801059A0, 0x8010ED60, 0x8010ED60, 0x8010F470, 0x8010F470, 0x8010F5C0 },
    { &overlays_overlay9_ROM_START, &overlays_overlay9_ROM_END, &overlays_overlay9_VRAM, 0x801059A0, 0x8010D3B0, 0x8010D3B0, 0x8010D9D0, 0x8010D9D0, 0x80110DF0 },
    { &overlays_overlay10_ROM_START, &overlays_overlay10_ROM_END, &overlays_overlay10_VRAM, 0x801059A0, 0x8010AA70, 0x8010AA70, 0x8010ADE0, 0x8010ADE0, 0x8010B0E0 },
    { &overlays_overlay11_ROM_START, &overlays_overlay11_ROM_END, &overlays_overlay11_VRAM, 0x801059A0, 0x80109100, 0x80109100, 0x80109260, 0x80109260, 0x801093E0 },
    { &overlays_overlay12_ROM_START, &overlays_overlay12_ROM_END, &overlays_overlay12_VRAM, 0x801059A0, 0x8010FD60, 0x8010FD60, 0x80110000, 0x80110000, 0x80110030 },
    { &overlays_overlay13_ROM_START, &overlays_overlay13_ROM_END, &overlays_overlay13_VRAM, 0x801059A0, 0x80110E70, 0x80110E70, 0x801116E0, 0x801116E0, 0x80113630 },
    { &overlays_overlay14_ROM_START, &overlays_overlay14_ROM_END, &overlays_overlay14_VRAM, 0x801059A0, 0x8010BDE0, 0x8010BDE0, 0x8010BF40, 0x8010BF40, 0x8010C040 },
    { &overlays_overlay15_ROM_START, &overlays_overlay15_ROM_END, &overlays_overlay15_VRAM, 0x801059A0, 0x8010E5B0, 0x8010E5B0, 0x8010EC20, 0x8010EC20, 0x8010F010 },
    { &overlays_overlay16_ROM_START, &overlays_overlay16_ROM_END, &overlays_overlay16_VRAM, 0x801059A0, 0x8010BB30, 0x8010BB30, 0x8010C010, 0x8010C010, 0x8010C3D0 },
    { &overlays_overlay17_ROM_START, &overlays_overlay17_ROM_END, &overlays_overlay17_VRAM, 0x801059A0, 0x80111220, 0x80111220, 0x80111650, 0x80111650, 0x80111680 },
    { &overlays_overlay18_ROM_START, &overlays_overlay18_ROM_END, &overlays_overlay18_VRAM, 0x801059A0, 0x8010C6A0, 0x8010C6A0, 0x8010C830, 0x8010C830, 0x801113F0 },
    { &overlays_overlay19_ROM_START, &overlays_overlay19_ROM_END, &overlays_overlay19_VRAM, 0x801059A0, 0x8010DE90, 0x8010DE90, 0x8010E590, 0x8010E590, 0x8010E670 },
    { &overlays_overlay20_ROM_START, &overlays_overlay20_ROM_END, &overlays_overlay20_VRAM, 0x801059A0, 0x8010D7F0, 0x8010D7F0, 0x8010DF40, 0x8010DF40, 0x8010E020 },
    { &overlays_overlay21_ROM_START, &overlays_overlay21_ROM_END, &overlays_overlay21_VRAM, 0x801059A0, 0x8010AF80, 0x8010AF80, 0x8010B2E0, 0x8010B2E0, 0x8010B470 },
    { &overlays_overlay22_ROM_START, &overlays_overlay22_ROM_END, &overlays_overlay22_VRAM, 0x801059A0, 0x8010EDA0, 0x8010EDA0, 0x8010F3D0, 0x8010F3D0, 0x8010F680 },
    { &overlays_overlay23_ROM_START, &overlays_overlay23_ROM_END, &overlays_overlay23_VRAM, 0x801059A0, 0x8010DB40, 0x8010DB40, 0x8010DE50, 0x8010DE50, 0x8010DF30 },
    { &overlays_overlay24_ROM_START, &overlays_overlay24_ROM_END, &overlays_overlay24_VRAM, 0x801059A0, 0x8010ABB0, 0x8010ABB0, 0x8010AEB0, 0x8010AEB0, 0x8010AEF0 },
    { &overlays_overlay25_ROM_START, &overlays_overlay25_ROM_END, &overlays_overlay25_VRAM, 0x801059A0, 0x80108550, 0x80108550, 0x801086D0, 0x801086D0, 0x80108700 },
    { &overlays_overlay26_ROM_START, &overlays_overlay26_ROM_END, &overlays_overlay26_VRAM, 0x801059A0, 0x8010A110, 0x8010A110, 0x8010A580, 0x8010A580, 0x8010A710 },
    { &overlays_overlay27_ROM_START, &overlays_overlay27_ROM_END, &overlays_overlay27_VRAM, 0x801059A0, 0x8010A820, 0x8010A820, 0x8010AA60, 0x8010AA60, 0x8010AB00 },
    { &overlays_overlay28_ROM_START, &overlays_overlay28_ROM_END, &overlays_overlay28_VRAM, 0x801059A0, 0x8010A8A0, 0x8010A8A0, 0x8010AB50, 0x8010AB50, 0x8010AD10 },
    { &overlays_overlay29_ROM_START, &overlays_overlay29_ROM_END, &overlays_overlay29_VRAM, 0x801059A0, 0x80110FC0, 0x80110FC0, 0x80111600, 0x80111600, 0x80115DA0 },
    { &overlays_overlay30_ROM_START, &overlays_overlay30_ROM_END, &overlays_overlay30_VRAM, 0x801059A0, 0x80109FE0, 0x80109FE0, 0x8010A110, 0x8010A110, 0x8010A2C0 },
    { &overlays_overlay31_ROM_START, &overlays_overlay31_ROM_END, &overlays_overlay31_VRAM, 0x801059A0, 0x80110080, 0x80110080, 0x801102E0, 0x801102E0, 0x801168E0 },
    { &overlays_overlay32_ROM_START, &overlays_overlay32_ROM_END, &overlays_overlay32_VRAM, 0x801059A0, 0x8010C280, 0x8010C280, 0x8010C460, 0x8010C460, 0x8010C5A0 },
    { &overlays_overlay33_ROM_START, &overlays_overlay33_ROM_END, &overlays_overlay33_VRAM, 0x801059A0, 0x8010C680, 0x8010C680, 0x8010C9B0, 0x8010C9B0, 0x8010D030 },
    { &overlays_overlay34_ROM_START, &overlays_overlay34_ROM_END, &overlays_overlay34_VRAM, 0x801059A0, 0x8010B0C0, 0x8010B0C0, 0x8010B4B0, 0x8010B4B0, 0x8010CF40 },
    { &overlays_overlay35_ROM_START, &overlays_overlay35_ROM_END, &overlays_overlay35_VRAM, 0x801059A0, 0x8010A160, 0x8010A160, 0x8010A560, 0x8010A560, 0x8010AC90 },
    { &overlays_overlay36_ROM_START, &overlays_overlay36_ROM_END, &overlays_overlay36_VRAM, 0x801059A0, 0x8010CF20, 0x8010CF20, 0x8010D340, 0x8010D340, 0x80110AF0 },
    { &overlays_overlay37_ROM_START, &overlays_overlay37_ROM_END, &overlays_overlay37_VRAM, 0x801059A0, 0x8010CB60, 0x8010CB60, 0x8010D0D0, 0x8010D0D0, 0x8010D400 },
    { &overlays_overlay38_ROM_START, &overlays_overlay38_ROM_END, &overlays_overlay38_VRAM, 0x801059A0, 0x8010E010, 0x8010E010, 0x8010E360, 0x8010E360, 0x8010E3A0 },
    { &overlays_overlay39_ROM_START, &overlays_overlay39_ROM_END, &overlays_overlay39_VRAM, 0x801059A0, 0x80109EC0, 0x80109EC0, 0x8010A2B0, 0x8010A2B0, 0x8010AD60 },
    { &overlays_overlay40_ROM_START, &overlays_overlay40_ROM_END, &overlays_overlay40_VRAM, 0x801059A0, 0x8010F550, 0x8010F550, 0x8010F880, 0x8010F880, 0x801102A0 },
    { &overlays_overlay41_ROM_START, &overlays_overlay41_ROM_END, &overlays_overlay41_VRAM, 0x801059A0, 0x80109930, 0x80109930, 0x80109AC0, 0x80109AC0, 0x80109C60 },
    { &overlays_overlay42_ROM_START, &overlays_overlay42_ROM_END, &overlays_overlay42_VRAM, 0x801059A0, 0x8010F290, 0x8010F290, 0x8010F6F0, 0x8010F6F0, 0x80111180 },
    { &overlays_overlay43_ROM_START, &overlays_overlay43_ROM_END, &overlays_overlay43_VRAM, 0x801059A0, 0x8010CD10, 0x8010CD10, 0x8010D230, 0x8010D230, 0x8010EC60 },
    { &overlays_overlay44_ROM_START, &overlays_overlay44_ROM_END, &overlays_overlay44_VRAM, 0x801059A0, 0x80110EE0, 0x80110EE0, 0x80111AC0, 0x80111AC0, 0x80111C60 },
    { &overlays_overlay45_ROM_START, &overlays_overlay45_ROM_END, &overlays_overlay45_VRAM, 0x801059A0, 0x8010C140, 0x8010C140, 0x8010C410, 0x8010C410, 0x8010DEE0 },
    { &overlays_overlay46_ROM_START, &overlays_overlay46_ROM_END, &overlays_overlay46_VRAM, 0x801059A0, 0x8010A6A0, 0x8010A6A0, 0x8010AA10, 0x8010AA10, 0x8010C480 },
    { &overlays_overlay47_ROM_START, &overlays_overlay47_ROM_END, &overlays_overlay47_VRAM, 0x801059A0, 0x8010C8B0, 0x8010C8B0, 0x8010CCA0, 0x8010CCA0, 0x8010CF80 },
    { &overlays_overlay48_ROM_START, &overlays_overlay48_ROM_END, &overlays_overlay48_VRAM, 0x801059A0, 0x8010AC10, 0x8010AC10, 0x8010AF20, 0x8010AF20, 0x8010CC40 },
    { &overlays_overlay49_ROM_START, &overlays_overlay49_ROM_END, &overlays_overlay49_VRAM, 0x801059A0, 0x80111B50, 0x80111B50, 0x80112590, 0x80112590, 0x801156A0 },
    { &overlays_overlay50_ROM_START, &overlays_overlay50_ROM_END, &overlays_overlay50_VRAM, 0x801059A0, 0x8010C590, 0x8010C590, 0x8010CBD0, 0x8010CBD0, 0x8010DEE0 },
    { &overlays_overlay51_ROM_START, &overlays_overlay51_ROM_END, &overlays_overlay51_VRAM, 0x801059A0, 0x8010C5A0, 0x8010C5A0, 0x8010C730, 0x8010C730, 0x8010C7E0 },
    { &overlays_overlay52_ROM_START, &overlays_overlay52_ROM_END, &overlays_overlay52_VRAM, 0x801059A0, 0x8010F150, 0x8010F150, 0x8010FB50, 0x8010FB50, 0x8010FBE0 },
    { &overlays_overlay53_ROM_START, &overlays_overlay53_ROM_END, &overlays_overlay53_VRAM, 0x801059A0, 0x8010B400, 0x8010B400, 0x8010BC00, 0x8010BC00, 0x8010BD30 },
    { &overlays_overlay54_ROM_START, &overlays_overlay54_ROM_END, &overlays_overlay54_VRAM, 0x801059A0, 0x80111550, 0x80111550, 0x801137C0, 0x801137C0, 0x801137F0 },
    { &overlays_overlay55_ROM_START, &overlays_overlay55_ROM_END, &overlays_overlay55_VRAM, 0x801059A0, 0x8010BE20, 0x8010BE20, 0x8010BF80, 0x8010BF80, 0x8010BFA0 },
    { &overlays_overlay56_ROM_START, &overlays_overlay56_ROM_END, &overlays_overlay56_VRAM, 0x801059A0, 0x8010C6C0, 0x8010C6C0, 0x8010CF80, 0x8010CF80, 0x8010D9F0 },
    { &overlays_overlay57_ROM_START, &overlays_overlay57_ROM_END, &overlays_overlay57_VRAM, 0x801059A0, 0x8010E4A0, 0x8010E4A0, 0x8010E6E0, 0x8010E6E0, 0x8010E710 },
    { &overlays_overlay58_ROM_START, &overlays_overlay58_ROM_END, &overlays_overlay58_VRAM, 0x801059A0, 0x8010E7A0, 0x8010E7A0, 0x8010F200, 0x8010F200, 0x8010F440 },
    { &overlays_overlay59_ROM_START, &overlays_overlay59_ROM_END, &overlays_overlay59_VRAM, 0x801059A0, 0x8010A260, 0x8010A260, 0x8010A460, 0x8010A460, 0x8010A4D0 },
    { &overlays_overlay60_ROM_START, &overlays_overlay60_ROM_END, &overlays_overlay60_VRAM, 0x801059A0, 0x80109B60, 0x80109B60, 0x80109EA0, 0x80109EA0, 0x80109F40 },
    { &overlays_overlay61_ROM_START, &overlays_overlay61_ROM_END, &overlays_overlay61_VRAM, 0x801059A0, 0x80109720, 0x80109720, 0x80109B00, 0x80109B00, 0x80109B70 },
    { &overlays_overlay62_ROM_START, &overlays_overlay62_ROM_END, &overlays_overlay62_VRAM, 0x801059A0, 0x8010A040, 0x8010A040, 0x8010A1F0, 0x8010A1F0, 0x8010A270 },
    { &overlays_minigames_swinging_with_sharks_ROM_START, &overlays_minigames_swinging_with_sharks_ROM_END, &overlays_minigames_swinging_with_sharks_VRAM, 0x801059A0, 0x8010ACE0, 0x8010ACE0, 0x8010B860, 0x8010B860, 0x8010BBC0 },
    { &overlays_overlay64_ROM_START, &overlays_overlay64_ROM_END, &overlays_overlay64_VRAM, 0x801059A0, 0x8010BD30, 0x8010BD30, 0x8010C090, 0x8010C090, 0x8010C1E0 },
    { &overlays_overlay65_ROM_START, &overlays_overlay65_ROM_END, &overlays_overlay65_VRAM, 0x801059A0, 0x80113CB0, 0x80113CB0, 0x80114940, 0x80114940, 0x80114BE0 },
    { &overlays_overlay66_ROM_START, &overlays_overlay66_ROM_END, &overlays_overlay66_VRAM, 0x801059A0, 0x8010A640, 0x8010A640, 0x8010A810, 0x8010A810, 0x8010AC50 },
    { &overlays_overlay67_ROM_START, &overlays_overlay67_ROM_END, &overlays_overlay67_VRAM, 0x801059A0, 0x8010D150, 0x8010D150, 0x8010D5D0, 0x8010D5D0, 0x8010D900 },
    { &overlays_overlay68_ROM_START, &overlays_overlay68_ROM_END, &overlays_overlay68_VRAM, 0x801059A0, 0x8010C1E0, 0x8010C1E0, 0x8010C5D0, 0x8010C5D0, 0x8010CB10 },
    { &overlays_overlay69_ROM_START, &overlays_overlay69_ROM_END, &overlays_overlay69_VRAM, 0x801059A0, 0x8010CB70, 0x8010CB70, 0x8010CE50, 0x8010CE50, 0x8010D100 },
    { &overlays_overlay70_ROM_START, &overlays_overlay70_ROM_END, &overlays_overlay70_VRAM, 0x801059A0, 0x80109740, 0x80109740, 0x80109F60, 0x80109F60, 0x8010A150 },
    { &overlays_overlay71_ROM_START, &overlays_overlay71_ROM_END, &overlays_overlay71_VRAM, 0x801059A0, 0x80105AE0, 0x80105AE0, 0x80105B00, 0x80105B00, 0x80105B00 },
    { &overlays_board_chillywaters_ROM_START, &overlays_board_chillywaters_ROM_END, &overlays_board_chillywaters_VRAM, 0x801059A0, 0x8011D250, 0x8011D250, 0x8011FA70, 0x8011FA70, 0x8011FBC0 },
    { &overlays_board_deepbloobersea_ROM_START, &overlays_board_deepbloobersea_ROM_END, &overlays_board_deepbloobersea_VRAM, 0x801059A0, 0x8011C630, 0x8011C630, 0x8011EBD0, 0x8011EBD0, 0x8011ED10 },
    { &overlays_board_spinydesert_ROM_START, &overlays_board_spinydesert_ROM_END, &overlays_board_spinydesert_VRAM, 0x801059A0, 0x8011C0E0, 0x8011C0E0, 0x8011EAC0, 0x8011EAC0, 0x8011EC10 },
    { &overlays_board_woodywoods_ROM_START, &overlays_board_woodywoods_ROM_END, &overlays_board_woodywoods_VRAM, 0x801059A0, 0x8011B710, 0x8011B710, 0x8011DFF0, 0x8011DFF0, 0x8011E120 },
    { &overlays_board_creepycavern_ROM_START, &overlays_board_creepycavern_ROM_END, &overlays_board_creepycavern_VRAM, 0x801059A0, 0x8011D010, 0x8011D010, 0x80120740, 0x80120740, 0x801208A0 },
    { &overlays_board_waluigisisland_ROM_START, &overlays_board_waluigisisland_ROM_END, &overlays_board_waluigisisland_VRAM, 0x801059A0, 0x8011B550, 0x8011B550, 0x8011E270, 0x8011E270, 0x8011E3B0 },
    { &overlays_overlay78_ROM_START, &overlays_overlay78_ROM_END, &overlays_overlay78_VRAM, 0x801059A0, 0x8010B7D0, 0x8010B7D0, 0x8010BA20, 0x8010BA20, 0x8010BAA0 },
    { &overlays_overlay79_ROM_START, &overlays_overlay79_ROM_END, &overlays_overlay79_VRAM, 0x801059A0, 0x8010E3E0, 0x8010E3E0, 0x8010EAF0, 0x8010EAF0, 0x8010EBD0 },
    { &overlays_overlay80_ROM_START, &overlays_overlay80_ROM_END, &overlays_overlay80_VRAM, 0x801059A0, 0x80109350, 0x80109350, 0x801094F0, 0x801094F0, 0x80109570 },
    { &overlays_overlay81_ROM_START, &overlays_overlay81_ROM_END, &overlays_overlay81_VRAM, 0x801059A0, 0x80107480, 0x80107480, 0x80107550, 0x80107550, 0x80107580 },
    { &overlays_overlay82_ROM_START, &overlays_overlay82_ROM_END, &overlays_overlay82_VRAM, 0x801059A0, 0x801080D0, 0x801080D0, 0x801082E0, 0x801082E0, 0x801083D0 },
    { &overlays_overlay83_ROM_START, &overlays_overlay83_ROM_END, &overlays_overlay83_VRAM, 0x801059A0, 0x80108D70, 0x80108D70, 0x80109060, 0x80109060, 0x80109080 },
    { &overlays_overlay84_ROM_START, &overlays_overlay84_ROM_END, &overlays_overlay84_VRAM, 0x801059A0, 0x801075C0, 0x801075C0, 0x80107760, 0x80107760, 0x801077A0 },
    { &overlays_overlay85_ROM_START, &overlays_overlay85_ROM_END, &overlays_overlay85_VRAM, 0x801059A0, 0x801097B0, 0x801097B0, 0x801099A0, 0x801099A0, 0x80109A50 },
    { &overlays_overlay86_ROM_START, &overlays_overlay86_ROM_END, &overlays_overlay86_VRAM, 0x801059A0, 0x80106E80, 0x80106E80, 0x80107950, 0x80107950, 0x80107AE0 },
    { &overlays_overlay87_ROM_START, &overlays_overlay87_ROM_END, &overlays_overlay87_VRAM, 0x801059A0, 0x80106DB0, 0x80106DB0, 0x80106EC0, 0x80106EC0, 0x80107060 },
    { &overlays_intro_ROM_START, &overlays_intro_ROM_END, &overlays_intro_VRAM, 0x801059A0, 0x80105EE0, 0x80105EE0, 0x80105F10, 0x80105F10, 0x80105F20 },
    { &overlays_overlay89_ROM_START, &overlays_overlay89_ROM_END, &overlays_overlay89_VRAM, 0x801059A0, 0x80106960, 0x80106960, 0x80106C10, 0x80106C10, 0x80106C40 },
    { &overlays_overlay90_ROM_START, &overlays_overlay90_ROM_END, &overlays_overlay90_VRAM, 0x801059A0, 0x80105AE0, 0x80105AE0, 0x80105B00, 0x80105B00, 0x80105B00 },
    { &overlays_overlay91_ROM_START, &overlays_overlay91_ROM_END, &overlays_overlay91_VRAM, 0x801059A0, 0x801186E0, 0x801186E0, 0x80119470, 0x80119470, 0x801194C0 },
    { &overlays_overlay92_ROM_START, &overlays_overlay92_ROM_END, &overlays_overlay92_VRAM, 0x801059A0, 0x80116570, 0x80116570, 0x80117600, 0x80117600, 0x80117640 },
    { &overlays_overlay93_ROM_START, &overlays_overlay93_ROM_END, &overlays_overlay93_VRAM, 0x801059A0, 0x80117400, 0x80117400, 0x801180C0, 0x801180C0, 0x80118110 },
    { &overlays_overlay94_ROM_START, &overlays_overlay94_ROM_END, &overlays_overlay94_VRAM, 0x801059A0, 0x80119C70, 0x80119C70, 0x8011B4E0, 0x8011B4E0, 0x8011B520 },
    { &overlays_overlay95_ROM_START, &overlays_overlay95_ROM_END, &overlays_overlay95_VRAM, 0x801059A0, 0x80115680, 0x80115680, 0x801163A0, 0x801163A0, 0x801163E0 },
    { &overlays_overlay96_ROM_START, &overlays_overlay96_ROM_END, &overlays_overlay96_VRAM, 0x801059A0, 0x80114480, 0x80114480, 0x80114D30, 0x80114D30, 0x80114D80 },
    { &overlays_overlay97_ROM_START, &overlays_overlay97_ROM_END, &overlays_overlay97_VRAM, 0x801059A0, 0x801149B0, 0x801149B0, 0x80114CB0, 0x80114CB0, 0x80114CF0 },
    { &overlays_overlay98_ROM_START, &overlays_overlay98_ROM_END, &overlays_overlay98_VRAM, 0x801059A0, 0x8010D290, 0x8010D290, 0x8010D860, 0x8010D860, 0x8010D950 },
    { &overlays_overlay99_ROM_START, &overlays_overlay99_ROM_END, &overlays_overlay99_VRAM, 0x801059A0, 0x80108C30, 0x80108C30, 0x80108DB0, 0x80108DB0, 0x80108E40 },
    { &overlays_overlay100_ROM_START, &overlays_overlay100_ROM_END, &overlays_overlay100_VRAM, 0x801059A0, 0x80109200, 0x80109200, 0x80109570, 0x80109570, 0x80109590 },
    { &overlays_overlay101_ROM_START, &overlays_overlay101_ROM_END, &overlays_overlay101_VRAM, 0x801059A0, 0x80108930, 0x80108930, 0x80108C10, 0x80108C10, 0x80108C50 },
    { &overlays_overlay102_ROM_START, &overlays_overlay102_ROM_END, &overlays_overlay102_VRAM, 0x801059A0, 0x801066E0, 0x801066E0, 0x801068C0, 0x801068C0, 0x80106AC0 },
    { &overlays_overlay103_ROM_START, &overlays_overlay103_ROM_END, &overlays_overlay103_VRAM, 0x801059A0, 0x80105F20, 0x80105F20, 0x80105F40, 0x80105F40, 0x80105F50 },
    { &overlays_overlay104_ROM_START, &overlays_overlay104_ROM_END, &overlays_overlay104_VRAM, 0x801059A0, 0x80109A80, 0x80109A80, 0x80109B20, 0x80109B20, 0x80109C30 },
    { &overlays_overlay105_ROM_START, &overlays_overlay105_ROM_END, &overlays_overlay105_VRAM, 0x801059A0, 0x80118EB0, 0x80118EB0, 0x8011A700, 0x8011A700, 0x8011B960 },
    { &overlays_overlay106_ROM_START, &overlays_overlay106_ROM_END, &overlays_overlay106_VRAM, 0x801059A0, 0x8010FAE0, 0x8010FAE0, 0x8010FE60, 0x8010FE60, 0x801100E0 },
    { &overlays_overlay107_ROM_START, &overlays_overlay107_ROM_END, &overlays_overlay107_VRAM, 0x801059A0, 0x80114A80, 0x80114A80, 0x801158B0, 0x801158B0, 0x80115CC0 },
    { &overlays_overlay108_ROM_START, &overlays_overlay108_ROM_END, &overlays_overlay108_VRAM, 0x801059A0, 0x8011B920, 0x8011B920, 0x8011C640, 0x8011C640, 0x8011CA90 },
    { &overlays_overlay109_ROM_START, &overlays_overlay109_ROM_END, &overlays_overlay109_VRAM, 0x801059A0, 0x80115260, 0x80115260, 0x80115B90, 0x80115B90, 0x80115DD0 },
    { &overlays_overlay110_ROM_START, &overlays_overlay110_ROM_END, &overlays_overlay110_VRAM, 0x801059A0, 0x80111AC0, 0x80111AC0, 0x80112120, 0x80112120, 0x801123C0 },
    { &overlays_overlay111_ROM_START, &overlays_overlay111_ROM_END, &overlays_overlay111_VRAM, 0x801059A0, 0x80114730, 0x80114730, 0x801151B0, 0x801151B0, 0x801156D0 },
    { &overlays_overlay112_ROM_START, &overlays_overlay112_ROM_END, &overlays_overlay112_VRAM, 0x801059A0, 0x8010D400, 0x8010D400, 0x8010DC00, 0x8010DC00, 0x8010DDF0 },
    { &overlays_overlay113_ROM_START, &overlays_overlay113_ROM_END, &overlays_overlay113_VRAM, 0x801059A0, 0x8010AAF0, 0x8010AAF0, 0x8010AD90, 0x8010AD90, 0x8010B080 },
    { &overlays_overlay114_ROM_START, &overlays_overlay114_ROM_END, &overlays_overlay114_VRAM, 0x801059A0, 0x801098C0, 0x801098C0, 0x801099E0, 0x801099E0, 0x8010A280 },
    { &overlays_overlay115_ROM_START, &overlays_overlay115_ROM_END, &overlays_overlay115_VRAM, 0x801059A0, 0x80108E70, 0x80108E70, 0x80108F30, 0x80108F30, 0x80109350 },
    { &overlays_overlay116_ROM_START, &overlays_overlay116_ROM_END, &overlays_overlay116_VRAM, 0x801059A0, 0x801088D0, 0x801088D0, 0x80108A30, 0x80108A30, 0x80108FA0 },
    { &overlays_overlay117_ROM_START, &overlays_overlay117_ROM_END, &overlays_overlay117_VRAM, 0x801059A0, 0x80105B40, 0x80105B40, 0x80105B80, 0x80105B80, 0x80105B80 },
    { &overlays_debug_message_check_ROM_START, &overlays_debug_message_check_ROM_END, &overlays_debug_message_check_VRAM, 0x801059A0, 0x80106500, 0x80106500, 0x80106E40, 0x80106E40, 0x80107010 },
    { &overlays_overlay119_ROM_START, &overlays_overlay119_ROM_END, &overlays_overlay119_VRAM, 0x801059A0, 0x8010F270, 0x8010F270, 0x8010F710, 0x8010F710, 0x80110DF0 },
    { &overlays_overlay120_ROM_START, &overlays_overlay120_ROM_END, &overlays_overlay120_VRAM, 0x801059A0, 0x80119410, 0x80119410, 0x8011A880, 0x8011A880, 0x8011AA50 },
    { &overlays_overlay121_ROM_START, &overlays_overlay121_ROM_END, &overlays_overlay121_VRAM, 0x801059A0, 0x801127A0, 0x801127A0, 0x80112E90, 0x80112E90, 0x801146E0 },
    { &overlays_overlay122_ROM_START, &overlays_overlay122_ROM_END, &overlays_overlay122_VRAM, 0x801059A0, 0x80114B50, 0x80114B50, 0x80114EA0, 0x80114EA0, 0x80117760 },
    { &overlays_overlay123_ROM_START, &overlays_overlay123_ROM_END, &overlays_overlay123_VRAM, 0x801059A0, 0x801134B0, 0x801134B0, 0x801146F0, 0x801146F0, 0x80115C00 },
    { &overlays_overlay124_ROM_START, &overlays_overlay124_ROM_END, &overlays_overlay124_VRAM, 0x801059A0, 0x80110530, 0x80110530, 0x80111490, 0x80111490, 0x80111570 },
    { &overlays_overlay125_ROM_START, &overlays_overlay125_ROM_END, &overlays_overlay125_VRAM, 0x801059A0, 0x8010A910, 0x8010A910, 0x8010ABE0, 0x8010ABE0, 0x8010AC40 },
    { 0x00552F50, 0x00552F50, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0 },
    { &overlays_overlay127_ROM_START, &overlays_overlay127_ROM_END, &overlays_overlay127_VRAM, 0x801059A0, 0x80108C90, 0x80108C90, 0x8010A070, 0x8010A070, 0x8010A290 }
#endif
};

struct overlay_info D_800974F4[] = {
#ifndef CC_CHECK
    { &overlays_shared_board_ROM_START, &overlays_shared_board_ROM_END, 0x800D6B70, 0x800D6B70, 0x801007A0, 0x801007A0, 0x80102700, 0x80102700, 0x801059A0 },
    { &overlays_overlay129_ROM_START, &overlays_overlay129_ROM_END, 0x800D6B70, 0x800D6B70, 0x80100E10, 0x80100E10, 0x801029C0, 0x801029C0, 0x80105720 },
    { &overlays_overlay130_ROM_START, &overlays_overlay130_ROM_END, 0x800D6B70, 0x800D6B70, 0x800EB720, 0x800EB720, 0x800EBDC0, 0x800EBDC0, 0x800EC5E0 }
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
