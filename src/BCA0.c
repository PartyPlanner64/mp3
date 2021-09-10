#include "common.h"
#include "object.h"

u8 D_800962F0 = 0;

// NUPiOverlaySegment
struct overlay_info {
    u8 *rom_start;
    u8 *rom_end;
    u8 *ram_start;
    u8 *code_start;
    u8 *code_end;
    u8 *data_start;
    u8 *data_end;
    u8 *bss_start;
    u8 *bss_end;
}; // sizeof 0x24

struct overlay_info D_800962F4[] = {
#ifndef CC_CHECK
    { &overlays_overlay0_ROM_START, &overlays_overlay0_ROM_END, &overlays_overlay0_VRAM, &overlays_overlay0_TEXT_START, &overlays_overlay0_TEXT_END, &overlays_overlay0_DATA_START, 0x80109B00, 0x80109B00, 0x80109D20 },
    { &overlays_overlay1_ROM_START, &overlays_overlay1_ROM_END, &overlays_overlay1_VRAM, &overlays_overlay1_TEXT_START, &overlays_overlay1_TEXT_END, &overlays_overlay1_DATA_START, 0x8010C0E0, 0x8010C0E0, 0x8010C1A0 },
    { &overlays_overlay2_ROM_START, &overlays_overlay2_ROM_END, &overlays_overlay2_VRAM, &overlays_overlay2_TEXT_START, &overlays_overlay2_TEXT_END, &overlays_overlay2_DATA_START, 0x8010B1C0, 0x8010B1C0, 0x8010CBD0 },
    { &overlays_overlay3_ROM_START, &overlays_overlay3_ROM_END, &overlays_overlay3_VRAM, &overlays_overlay3_TEXT_START, &overlays_overlay3_TEXT_END, &overlays_overlay3_DATA_START, 0x8010D2F0, 0x8010D2F0, 0x8010EE70 },
    { &overlays_overlay4_ROM_START, &overlays_overlay4_ROM_END, &overlays_overlay4_VRAM, &overlays_overlay4_TEXT_START, &overlays_overlay4_TEXT_END, &overlays_overlay4_DATA_START, 0x80109880, 0x80109880, 0x801098B0 },
    { &overlays_overlay5_ROM_START, &overlays_overlay5_ROM_END, &overlays_overlay5_VRAM, &overlays_overlay5_TEXT_START, &overlays_overlay5_TEXT_END, &overlays_overlay5_DATA_START, 0x8010B990, 0x8010B990, 0x8010DEC0 },
    { &overlays_overlay6_ROM_START, &overlays_overlay6_ROM_END, &overlays_overlay6_VRAM, &overlays_overlay6_TEXT_START, &overlays_overlay6_TEXT_END, &overlays_overlay6_DATA_START, 0x8010C760, 0x8010C760, 0x8010E1C0 },
    { &overlays_overlay7_ROM_START, &overlays_overlay7_ROM_END, &overlays_overlay7_VRAM, &overlays_overlay7_TEXT_START, &overlays_overlay7_TEXT_END, &overlays_overlay7_DATA_START, 0x801117F0, 0x801117F0, 0x80111AA0 },
    { &overlays_overlay8_ROM_START, &overlays_overlay8_ROM_END, &overlays_overlay8_VRAM, &overlays_overlay8_TEXT_START, &overlays_overlay8_TEXT_END, &overlays_overlay8_DATA_START, 0x8010F470, 0x8010F470, 0x8010F5C0 },
    { &overlays_overlay9_ROM_START, &overlays_overlay9_ROM_END, &overlays_overlay9_VRAM, &overlays_overlay9_TEXT_START, &overlays_overlay9_TEXT_END, &overlays_overlay9_DATA_START, 0x8010D9D0, 0x8010D9D0, 0x80110DF0 },
    { &overlays_overlay10_ROM_START, &overlays_overlay10_ROM_END, &overlays_overlay10_VRAM, &overlays_overlay10_TEXT_START, &overlays_overlay10_TEXT_END, &overlays_overlay10_DATA_START, 0x8010ADE0, 0x8010ADE0, 0x8010B0E0 },
    { &overlays_overlay11_ROM_START, &overlays_overlay11_ROM_END, &overlays_overlay11_VRAM, &overlays_overlay11_TEXT_START, &overlays_overlay11_TEXT_END, &overlays_overlay11_DATA_START, 0x80109260, 0x80109260, 0x801093E0 },
    { &overlays_overlay12_ROM_START, &overlays_overlay12_ROM_END, &overlays_overlay12_VRAM, &overlays_overlay12_TEXT_START, &overlays_overlay12_TEXT_END, &overlays_overlay12_DATA_START, 0x80110000, 0x80110000, 0x80110030 },
    { &overlays_overlay13_ROM_START, &overlays_overlay13_ROM_END, &overlays_overlay13_VRAM, &overlays_overlay13_TEXT_START, &overlays_overlay13_TEXT_END, &overlays_overlay13_DATA_START, 0x801116E0, 0x801116E0, 0x80113630 },
    { &overlays_overlay14_ROM_START, &overlays_overlay14_ROM_END, &overlays_overlay14_VRAM, &overlays_overlay14_TEXT_START, &overlays_overlay14_TEXT_END, &overlays_overlay14_DATA_START, 0x8010BF40, 0x8010BF40, 0x8010C040 },
    { &overlays_overlay15_ROM_START, &overlays_overlay15_ROM_END, &overlays_overlay15_VRAM, &overlays_overlay15_TEXT_START, &overlays_overlay15_TEXT_END, &overlays_overlay15_DATA_START, 0x8010EC20, 0x8010EC20, 0x8010F010 },
    { &overlays_overlay16_ROM_START, &overlays_overlay16_ROM_END, &overlays_overlay16_VRAM, &overlays_overlay16_TEXT_START, &overlays_overlay16_TEXT_END, &overlays_overlay16_DATA_START, 0x8010C010, 0x8010C010, 0x8010C3D0 },
    { &overlays_overlay17_ROM_START, &overlays_overlay17_ROM_END, &overlays_overlay17_VRAM, &overlays_overlay17_TEXT_START, &overlays_overlay17_TEXT_END, &overlays_overlay17_DATA_START, 0x80111650, 0x80111650, 0x80111680 },
    { &overlays_overlay18_ROM_START, &overlays_overlay18_ROM_END, &overlays_overlay18_VRAM, &overlays_overlay18_TEXT_START, &overlays_overlay18_TEXT_END, &overlays_overlay18_DATA_START, 0x8010C830, 0x8010C830, 0x801113F0 },
    { &overlays_overlay19_ROM_START, &overlays_overlay19_ROM_END, &overlays_overlay19_VRAM, &overlays_overlay19_TEXT_START, &overlays_overlay19_TEXT_END, &overlays_overlay19_DATA_START, 0x8010E590, 0x8010E590, 0x8010E670 },
    { &overlays_overlay20_ROM_START, &overlays_overlay20_ROM_END, &overlays_overlay20_VRAM, &overlays_overlay20_TEXT_START, &overlays_overlay20_TEXT_END, &overlays_overlay20_DATA_START, 0x8010DF40, 0x8010DF40, 0x8010E020 },
    { &overlays_overlay21_ROM_START, &overlays_overlay21_ROM_END, &overlays_overlay21_VRAM, &overlays_overlay21_TEXT_START, &overlays_overlay21_TEXT_END, &overlays_overlay21_DATA_START, 0x8010B2E0, 0x8010B2E0, 0x8010B470 },
    { &overlays_overlay22_ROM_START, &overlays_overlay22_ROM_END, &overlays_overlay22_VRAM, &overlays_overlay22_TEXT_START, &overlays_overlay22_TEXT_END, &overlays_overlay22_DATA_START, 0x8010F3D0, 0x8010F3D0, 0x8010F680 },
    { &overlays_overlay23_ROM_START, &overlays_overlay23_ROM_END, &overlays_overlay23_VRAM, &overlays_overlay23_TEXT_START, &overlays_overlay23_TEXT_END, &overlays_overlay23_DATA_START, 0x8010DE50, 0x8010DE50, 0x8010DF30 },
    { &overlays_overlay24_ROM_START, &overlays_overlay24_ROM_END, &overlays_overlay24_VRAM, &overlays_overlay24_TEXT_START, &overlays_overlay24_TEXT_END, &overlays_overlay24_DATA_START, 0x8010AEB0, 0x8010AEB0, 0x8010AEF0 },
    { &overlays_overlay25_ROM_START, &overlays_overlay25_ROM_END, &overlays_overlay25_VRAM, &overlays_overlay25_TEXT_START, &overlays_overlay25_TEXT_END, &overlays_overlay25_DATA_START, 0x801086D0, 0x801086D0, 0x80108700 },
    { &overlays_overlay26_ROM_START, &overlays_overlay26_ROM_END, &overlays_overlay26_VRAM, &overlays_overlay26_TEXT_START, &overlays_overlay26_TEXT_END, &overlays_overlay26_DATA_START, 0x8010A580, 0x8010A580, 0x8010A710 },
    { &overlays_overlay27_ROM_START, &overlays_overlay27_ROM_END, &overlays_overlay27_VRAM, &overlays_overlay27_TEXT_START, &overlays_overlay27_TEXT_END, &overlays_overlay27_DATA_START, 0x8010AA60, 0x8010AA60, 0x8010AB00 },
    { &overlays_overlay28_ROM_START, &overlays_overlay28_ROM_END, &overlays_overlay28_VRAM, &overlays_overlay28_TEXT_START, &overlays_overlay28_TEXT_END, &overlays_overlay28_DATA_START, 0x8010AB50, 0x8010AB50, 0x8010AD10 },
    { &overlays_overlay29_ROM_START, &overlays_overlay29_ROM_END, &overlays_overlay29_VRAM, &overlays_overlay29_TEXT_START, &overlays_overlay29_TEXT_END, &overlays_overlay29_DATA_START, 0x80111600, 0x80111600, 0x80115DA0 },
    { &overlays_overlay30_ROM_START, &overlays_overlay30_ROM_END, &overlays_overlay30_VRAM, &overlays_overlay30_TEXT_START, &overlays_overlay30_TEXT_END, &overlays_overlay30_DATA_START, 0x8010A110, 0x8010A110, 0x8010A2C0 },
    { &overlays_overlay31_ROM_START, &overlays_overlay31_ROM_END, &overlays_overlay31_VRAM, &overlays_overlay31_TEXT_START, &overlays_overlay31_TEXT_END, &overlays_overlay31_DATA_START, 0x801102E0, 0x801102E0, 0x801168E0 },
    { &overlays_overlay32_ROM_START, &overlays_overlay32_ROM_END, &overlays_overlay32_VRAM, &overlays_overlay32_TEXT_START, &overlays_overlay32_TEXT_END, &overlays_overlay32_DATA_START, 0x8010C460, 0x8010C460, 0x8010C5A0 },
    { &overlays_overlay33_ROM_START, &overlays_overlay33_ROM_END, &overlays_overlay33_VRAM, &overlays_overlay33_TEXT_START, &overlays_overlay33_TEXT_END, &overlays_overlay33_DATA_START, 0x8010C9B0, 0x8010C9B0, 0x8010D030 },
    { &overlays_overlay34_ROM_START, &overlays_overlay34_ROM_END, &overlays_overlay34_VRAM, &overlays_overlay34_TEXT_START, &overlays_overlay34_TEXT_END, &overlays_overlay34_DATA_START, 0x8010B4B0, 0x8010B4B0, 0x8010CF40 },
    { &overlays_overlay35_ROM_START, &overlays_overlay35_ROM_END, &overlays_overlay35_VRAM, &overlays_overlay35_TEXT_START, &overlays_overlay35_TEXT_END, &overlays_overlay35_DATA_START, 0x8010A560, 0x8010A560, 0x8010AC90 },
    { &overlays_overlay36_ROM_START, &overlays_overlay36_ROM_END, &overlays_overlay36_VRAM, &overlays_overlay36_TEXT_START, &overlays_overlay36_TEXT_END, &overlays_overlay36_DATA_START, 0x8010D340, 0x8010D340, 0x80110AF0 },
    { &overlays_overlay37_ROM_START, &overlays_overlay37_ROM_END, &overlays_overlay37_VRAM, &overlays_overlay37_TEXT_START, &overlays_overlay37_TEXT_END, &overlays_overlay37_DATA_START, 0x8010D0D0, 0x8010D0D0, 0x8010D400 },
    { &overlays_overlay38_ROM_START, &overlays_overlay38_ROM_END, &overlays_overlay38_VRAM, &overlays_overlay38_TEXT_START, &overlays_overlay38_TEXT_END, &overlays_overlay38_DATA_START, 0x8010E360, 0x8010E360, 0x8010E3A0 },
    { &overlays_overlay39_ROM_START, &overlays_overlay39_ROM_END, &overlays_overlay39_VRAM, &overlays_overlay39_TEXT_START, &overlays_overlay39_TEXT_END, &overlays_overlay39_DATA_START, 0x8010A2B0, 0x8010A2B0, 0x8010AD60 },
    { &overlays_overlay40_ROM_START, &overlays_overlay40_ROM_END, &overlays_overlay40_VRAM, &overlays_overlay40_TEXT_START, &overlays_overlay40_TEXT_END, &overlays_overlay40_DATA_START, 0x8010F880, 0x8010F880, 0x801102A0 },
    { &overlays_overlay41_ROM_START, &overlays_overlay41_ROM_END, &overlays_overlay41_VRAM, &overlays_overlay41_TEXT_START, &overlays_overlay41_TEXT_END, &overlays_overlay41_DATA_START, 0x80109AC0, 0x80109AC0, 0x80109C60 },
    { &overlays_overlay42_ROM_START, &overlays_overlay42_ROM_END, &overlays_overlay42_VRAM, &overlays_overlay42_TEXT_START, &overlays_overlay42_TEXT_END, &overlays_overlay42_DATA_START, 0x8010F6F0, 0x8010F6F0, 0x80111180 },
    { &overlays_overlay43_ROM_START, &overlays_overlay43_ROM_END, &overlays_overlay43_VRAM, &overlays_overlay43_TEXT_START, &overlays_overlay43_TEXT_END, &overlays_overlay43_DATA_START, 0x8010D230, 0x8010D230, 0x8010EC60 },
    { &overlays_overlay44_ROM_START, &overlays_overlay44_ROM_END, &overlays_overlay44_VRAM, &overlays_overlay44_TEXT_START, &overlays_overlay44_TEXT_END, &overlays_overlay44_DATA_START, 0x80111AC0, 0x80111AC0, 0x80111C60 },
    { &overlays_overlay45_ROM_START, &overlays_overlay45_ROM_END, &overlays_overlay45_VRAM, &overlays_overlay45_TEXT_START, &overlays_overlay45_TEXT_END, &overlays_overlay45_DATA_START, 0x8010C410, 0x8010C410, 0x8010DEE0 },
    { &overlays_overlay46_ROM_START, &overlays_overlay46_ROM_END, &overlays_overlay46_VRAM, &overlays_overlay46_TEXT_START, &overlays_overlay46_TEXT_END, &overlays_overlay46_DATA_START, 0x8010AA10, 0x8010AA10, 0x8010C480 },
    { &overlays_overlay47_ROM_START, &overlays_overlay47_ROM_END, &overlays_overlay47_VRAM, &overlays_overlay47_TEXT_START, &overlays_overlay47_TEXT_END, &overlays_overlay47_DATA_START, 0x8010CCA0, 0x8010CCA0, 0x8010CF80 },
    { &overlays_overlay48_ROM_START, &overlays_overlay48_ROM_END, &overlays_overlay48_VRAM, &overlays_overlay48_TEXT_START, &overlays_overlay48_TEXT_END, &overlays_overlay48_DATA_START, 0x8010AF20, 0x8010AF20, 0x8010CC40 },
    { &overlays_overlay49_ROM_START, &overlays_overlay49_ROM_END, &overlays_overlay49_VRAM, &overlays_overlay49_TEXT_START, &overlays_overlay49_TEXT_END, &overlays_overlay49_DATA_START, 0x80112590, 0x80112590, 0x801156A0 },
    { &overlays_overlay50_ROM_START, &overlays_overlay50_ROM_END, &overlays_overlay50_VRAM, &overlays_overlay50_TEXT_START, &overlays_overlay50_TEXT_END, &overlays_overlay50_DATA_START, 0x8010CBD0, 0x8010CBD0, 0x8010DEE0 },
    { &overlays_overlay51_ROM_START, &overlays_overlay51_ROM_END, &overlays_overlay51_VRAM, &overlays_overlay51_TEXT_START, &overlays_overlay51_TEXT_END, &overlays_overlay51_DATA_START, 0x8010C730, 0x8010C730, 0x8010C7E0 },
    { &overlays_overlay52_ROM_START, &overlays_overlay52_ROM_END, &overlays_overlay52_VRAM, &overlays_overlay52_TEXT_START, &overlays_overlay52_TEXT_END, &overlays_overlay52_DATA_START, 0x8010FB50, 0x8010FB50, 0x8010FBE0 },
    { &overlays_overlay53_ROM_START, &overlays_overlay53_ROM_END, &overlays_overlay53_VRAM, &overlays_overlay53_TEXT_START, &overlays_overlay53_TEXT_END, &overlays_overlay53_DATA_START, 0x8010BC00, 0x8010BC00, 0x8010BD30 },
    { &overlays_overlay54_ROM_START, &overlays_overlay54_ROM_END, &overlays_overlay54_VRAM, &overlays_overlay54_TEXT_START, &overlays_overlay54_TEXT_END, &overlays_overlay54_DATA_START, 0x801137C0, 0x801137C0, 0x801137F0 },
    { &overlays_overlay55_ROM_START, &overlays_overlay55_ROM_END, &overlays_overlay55_VRAM, &overlays_overlay55_TEXT_START, &overlays_overlay55_TEXT_END, &overlays_overlay55_DATA_START, 0x8010BF80, 0x8010BF80, 0x8010BFA0 },
    { &overlays_overlay56_ROM_START, &overlays_overlay56_ROM_END, &overlays_overlay56_VRAM, &overlays_overlay56_TEXT_START, &overlays_overlay56_TEXT_END, &overlays_overlay56_DATA_START, 0x8010CF80, 0x8010CF80, 0x8010D9F0 },
    { &overlays_overlay57_ROM_START, &overlays_overlay57_ROM_END, &overlays_overlay57_VRAM, &overlays_overlay57_TEXT_START, &overlays_overlay57_TEXT_END, &overlays_overlay57_DATA_START, 0x8010E6E0, 0x8010E6E0, 0x8010E710 },
    { &overlays_overlay58_ROM_START, &overlays_overlay58_ROM_END, &overlays_overlay58_VRAM, &overlays_overlay58_TEXT_START, &overlays_overlay58_TEXT_END, &overlays_overlay58_DATA_START, 0x8010F200, 0x8010F200, 0x8010F440 },
    { &overlays_overlay59_ROM_START, &overlays_overlay59_ROM_END, &overlays_overlay59_VRAM, &overlays_overlay59_TEXT_START, &overlays_overlay59_TEXT_END, &overlays_overlay59_DATA_START, 0x8010A460, 0x8010A460, 0x8010A4D0 },
    { &overlays_overlay60_ROM_START, &overlays_overlay60_ROM_END, &overlays_overlay60_VRAM, &overlays_overlay60_TEXT_START, &overlays_overlay60_TEXT_END, &overlays_overlay60_DATA_START, 0x80109EA0, 0x80109EA0, 0x80109F40 },
    { &overlays_overlay61_ROM_START, &overlays_overlay61_ROM_END, &overlays_overlay61_VRAM, &overlays_overlay61_TEXT_START, &overlays_overlay61_TEXT_END, &overlays_overlay61_DATA_START, 0x80109B00, 0x80109B00, 0x80109B70 },
    { &overlays_overlay62_ROM_START, &overlays_overlay62_ROM_END, &overlays_overlay62_VRAM, &overlays_overlay62_TEXT_START, &overlays_overlay62_TEXT_END, &overlays_overlay62_DATA_START, 0x8010A1F0, 0x8010A1F0, 0x8010A270 },
    { &overlays_minigames_swinging_with_sharks_ROM_START, &overlays_minigames_swinging_with_sharks_ROM_END, &overlays_minigames_swinging_with_sharks_VRAM, &overlays_minigames_swinging_with_sharks_TEXT_START, &overlays_minigames_swinging_with_sharks_TEXT_END, &overlays_minigames_swinging_with_sharks_DATA_START, 0x8010B860, 0x8010B860, 0x8010BBC0 },
    { &overlays_overlay64_ROM_START, &overlays_overlay64_ROM_END, &overlays_overlay64_VRAM, &overlays_overlay64_TEXT_START, &overlays_overlay64_TEXT_END, &overlays_overlay64_DATA_START, 0x8010C090, 0x8010C090, 0x8010C1E0 },
    { &overlays_overlay65_ROM_START, &overlays_overlay65_ROM_END, &overlays_overlay65_VRAM, &overlays_overlay65_TEXT_START, &overlays_overlay65_TEXT_END, &overlays_overlay65_DATA_START, 0x80114940, 0x80114940, 0x80114BE0 },
    { &overlays_overlay66_ROM_START, &overlays_overlay66_ROM_END, &overlays_overlay66_VRAM, &overlays_overlay66_TEXT_START, &overlays_overlay66_TEXT_END, &overlays_overlay66_DATA_START, 0x8010A810, 0x8010A810, 0x8010AC50 },
    { &overlays_overlay67_ROM_START, &overlays_overlay67_ROM_END, &overlays_overlay67_VRAM, &overlays_overlay67_TEXT_START, &overlays_overlay67_TEXT_END, &overlays_overlay67_DATA_START, 0x8010D5D0, 0x8010D5D0, 0x8010D900 },
    { &overlays_overlay68_ROM_START, &overlays_overlay68_ROM_END, &overlays_overlay68_VRAM, &overlays_overlay68_TEXT_START, &overlays_overlay68_TEXT_END, &overlays_overlay68_DATA_START, 0x8010C5D0, 0x8010C5D0, 0x8010CB10 },
    { &overlays_overlay69_ROM_START, &overlays_overlay69_ROM_END, &overlays_overlay69_VRAM, &overlays_overlay69_TEXT_START, &overlays_overlay69_TEXT_END, &overlays_overlay69_DATA_START, 0x8010CE50, 0x8010CE50, 0x8010D100 },
    { &overlays_overlay70_ROM_START, &overlays_overlay70_ROM_END, &overlays_overlay70_VRAM, &overlays_overlay70_TEXT_START, &overlays_overlay70_TEXT_END, &overlays_overlay70_DATA_START, 0x80109F60, 0x80109F60, 0x8010A150 },
    { &overlays_overlay71_ROM_START, &overlays_overlay71_ROM_END, &overlays_overlay71_VRAM, &overlays_overlay71_TEXT_START, &overlays_overlay71_TEXT_END, &overlays_overlay71_DATA_START, 0x80105B00, 0x80105B00, 0x80105B00 },
    { &overlays_board_chillywaters_ROM_START, &overlays_board_chillywaters_ROM_END, &overlays_board_chillywaters_VRAM, &overlays_board_chillywaters_TEXT_START, &overlays_board_chillywaters_TEXT_END, &overlays_board_chillywaters_DATA_START, 0x8011FA70, 0x8011FA70, 0x8011FBC0 },
    { &overlays_board_deepbloobersea_ROM_START, &overlays_board_deepbloobersea_ROM_END, &overlays_board_deepbloobersea_VRAM, &overlays_board_deepbloobersea_TEXT_START, &overlays_board_deepbloobersea_TEXT_END, &overlays_board_deepbloobersea_DATA_START, 0x8011EBD0, 0x8011EBD0, 0x8011ED10 },
    { &overlays_board_spinydesert_ROM_START, &overlays_board_spinydesert_ROM_END, &overlays_board_spinydesert_VRAM, &overlays_board_spinydesert_TEXT_START, &overlays_board_spinydesert_TEXT_END, &overlays_board_spinydesert_DATA_START, 0x8011EAC0, 0x8011EAC0, 0x8011EC10 },
    { &overlays_board_woodywoods_ROM_START, &overlays_board_woodywoods_ROM_END, &overlays_board_woodywoods_VRAM, &overlays_board_woodywoods_TEXT_START, &overlays_board_woodywoods_TEXT_END, &overlays_board_woodywoods_DATA_START, 0x8011DFF0, 0x8011DFF0, 0x8011E120 },
    { &overlays_board_creepycavern_ROM_START, &overlays_board_creepycavern_ROM_END, &overlays_board_creepycavern_VRAM, &overlays_board_creepycavern_TEXT_START, &overlays_board_creepycavern_TEXT_END, &overlays_board_creepycavern_DATA_START, 0x80120740, 0x80120740, 0x801208A0 },
    { &overlays_board_waluigisisland_ROM_START, &overlays_board_waluigisisland_ROM_END, &overlays_board_waluigisisland_VRAM, &overlays_board_waluigisisland_TEXT_START, &overlays_board_waluigisisland_TEXT_END, &overlays_board_waluigisisland_DATA_START, 0x8011E270, 0x8011E270, 0x8011E3B0 },
    { &overlays_overlay78_ROM_START, &overlays_overlay78_ROM_END, &overlays_overlay78_VRAM, &overlays_overlay78_TEXT_START, &overlays_overlay78_TEXT_END, &overlays_overlay78_DATA_START, 0x8010BA20, 0x8010BA20, 0x8010BAA0 },
    { &overlays_overlay79_ROM_START, &overlays_overlay79_ROM_END, &overlays_overlay79_VRAM, &overlays_overlay79_TEXT_START, &overlays_overlay79_TEXT_END, &overlays_overlay79_DATA_START, 0x8010EAF0, 0x8010EAF0, 0x8010EBD0 },
    { &overlays_overlay80_ROM_START, &overlays_overlay80_ROM_END, &overlays_overlay80_VRAM, &overlays_overlay80_TEXT_START, &overlays_overlay80_TEXT_END, &overlays_overlay80_DATA_START, 0x801094F0, 0x801094F0, 0x80109570 },
    { &overlays_overlay81_ROM_START, &overlays_overlay81_ROM_END, &overlays_overlay81_VRAM, &overlays_overlay81_TEXT_START, &overlays_overlay81_TEXT_END, &overlays_overlay81_DATA_START, 0x80107550, 0x80107550, 0x80107580 },
    { &overlays_overlay82_ROM_START, &overlays_overlay82_ROM_END, &overlays_overlay82_VRAM, &overlays_overlay82_TEXT_START, &overlays_overlay82_TEXT_END, &overlays_overlay82_DATA_START, 0x801082E0, 0x801082E0, 0x801083D0 },
    { &overlays_overlay83_ROM_START, &overlays_overlay83_ROM_END, &overlays_overlay83_VRAM, &overlays_overlay83_TEXT_START, &overlays_overlay83_TEXT_END, &overlays_overlay83_DATA_START, 0x80109060, 0x80109060, 0x80109080 },
    { &overlays_overlay84_ROM_START, &overlays_overlay84_ROM_END, &overlays_overlay84_VRAM, &overlays_overlay84_TEXT_START, &overlays_overlay84_TEXT_END, &overlays_overlay84_DATA_START, 0x80107760, 0x80107760, 0x801077A0 },
    { &overlays_overlay85_ROM_START, &overlays_overlay85_ROM_END, &overlays_overlay85_VRAM, &overlays_overlay85_TEXT_START, &overlays_overlay85_TEXT_END, &overlays_overlay85_DATA_START, 0x801099A0, 0x801099A0, 0x80109A50 },
    { &overlays_overlay86_ROM_START, &overlays_overlay86_ROM_END, &overlays_overlay86_VRAM, &overlays_overlay86_TEXT_START, &overlays_overlay86_TEXT_END, &overlays_overlay86_DATA_START, 0x80107950, 0x80107950, 0x80107AE0 },
    { &overlays_overlay87_ROM_START, &overlays_overlay87_ROM_END, &overlays_overlay87_VRAM, &overlays_overlay87_TEXT_START, &overlays_overlay87_TEXT_END, &overlays_overlay87_DATA_START, 0x80106EC0, 0x80106EC0, 0x80107060 },
    { &overlays_intro_ROM_START, &overlays_intro_ROM_END, &overlays_intro_VRAM, &overlays_intro_TEXT_START, &overlays_intro_TEXT_END, &overlays_intro_DATA_START, &overlays_intro_DATA_END, &overlays_intro_BSS_START, &overlays_intro_BSS_END },
    { &overlays_overlay89_ROM_START, &overlays_overlay89_ROM_END, &overlays_overlay89_VRAM, &overlays_overlay89_TEXT_START, &overlays_overlay89_TEXT_END, &overlays_overlay89_DATA_START, 0x80106C10, 0x80106C10, 0x80106C40 },
    { &overlays_overlay90_ROM_START, &overlays_overlay90_ROM_END, &overlays_overlay90_VRAM, &overlays_overlay90_TEXT_START, &overlays_overlay90_TEXT_END, &overlays_overlay90_DATA_START, 0x80105B00, 0x80105B00, 0x80105B00 },
    { &overlays_overlay91_ROM_START, &overlays_overlay91_ROM_END, &overlays_overlay91_VRAM, &overlays_overlay91_TEXT_START, &overlays_overlay91_TEXT_END, &overlays_overlay91_DATA_START, 0x80119470, 0x80119470, 0x801194C0 },
    { &overlays_overlay92_ROM_START, &overlays_overlay92_ROM_END, &overlays_overlay92_VRAM, &overlays_overlay92_TEXT_START, &overlays_overlay92_TEXT_END, &overlays_overlay92_DATA_START, 0x80117600, 0x80117600, 0x80117640 },
    { &overlays_overlay93_ROM_START, &overlays_overlay93_ROM_END, &overlays_overlay93_VRAM, &overlays_overlay93_TEXT_START, &overlays_overlay93_TEXT_END, &overlays_overlay93_DATA_START, 0x801180C0, 0x801180C0, 0x80118110 },
    { &overlays_overlay94_ROM_START, &overlays_overlay94_ROM_END, &overlays_overlay94_VRAM, &overlays_overlay94_TEXT_START, &overlays_overlay94_TEXT_END, &overlays_overlay94_DATA_START, 0x8011B4E0, 0x8011B4E0, 0x8011B520 },
    { &overlays_overlay95_ROM_START, &overlays_overlay95_ROM_END, &overlays_overlay95_VRAM, &overlays_overlay95_TEXT_START, &overlays_overlay95_TEXT_END, &overlays_overlay95_DATA_START, 0x801163A0, 0x801163A0, 0x801163E0 },
    { &overlays_overlay96_ROM_START, &overlays_overlay96_ROM_END, &overlays_overlay96_VRAM, &overlays_overlay96_TEXT_START, &overlays_overlay96_TEXT_END, &overlays_overlay96_DATA_START, 0x80114D30, 0x80114D30, 0x80114D80 },
    { &overlays_overlay97_ROM_START, &overlays_overlay97_ROM_END, &overlays_overlay97_VRAM, &overlays_overlay97_TEXT_START, &overlays_overlay97_TEXT_END, &overlays_overlay97_DATA_START, 0x80114CB0, 0x80114CB0, 0x80114CF0 },
    { &overlays_overlay98_ROM_START, &overlays_overlay98_ROM_END, &overlays_overlay98_VRAM, &overlays_overlay98_TEXT_START, &overlays_overlay98_TEXT_END, &overlays_overlay98_DATA_START, 0x8010D860, 0x8010D860, 0x8010D950 },
    { &overlays_overlay99_ROM_START, &overlays_overlay99_ROM_END, &overlays_overlay99_VRAM, &overlays_overlay99_TEXT_START, &overlays_overlay99_TEXT_END, &overlays_overlay99_DATA_START, 0x80108DB0, 0x80108DB0, 0x80108E40 },
    { &overlays_overlay100_ROM_START, &overlays_overlay100_ROM_END, &overlays_overlay100_VRAM, &overlays_overlay100_TEXT_START, &overlays_overlay100_TEXT_END, &overlays_overlay100_DATA_START, 0x80109570, 0x80109570, 0x80109590 },
    { &overlays_overlay101_ROM_START, &overlays_overlay101_ROM_END, &overlays_overlay101_VRAM, &overlays_overlay101_TEXT_START, &overlays_overlay101_TEXT_END, &overlays_overlay101_DATA_START, 0x80108C10, 0x80108C10, 0x80108C50 },
    { &overlays_overlay102_ROM_START, &overlays_overlay102_ROM_END, &overlays_overlay102_VRAM, &overlays_overlay102_TEXT_START, &overlays_overlay102_TEXT_END, &overlays_overlay102_DATA_START, 0x801068C0, 0x801068C0, 0x80106AC0 },
    { &overlays_overlay103_ROM_START, &overlays_overlay103_ROM_END, &overlays_overlay103_VRAM, &overlays_overlay103_TEXT_START, &overlays_overlay103_TEXT_END, &overlays_overlay103_DATA_START, 0x80105F40, 0x80105F40, 0x80105F50 },
    { &overlays_overlay104_ROM_START, &overlays_overlay104_ROM_END, &overlays_overlay104_VRAM, &overlays_overlay104_TEXT_START, &overlays_overlay104_TEXT_END, &overlays_overlay104_DATA_START, 0x80109B20, 0x80109B20, 0x80109C30 },
    { &overlays_overlay105_ROM_START, &overlays_overlay105_ROM_END, &overlays_overlay105_VRAM, &overlays_overlay105_TEXT_START, &overlays_overlay105_TEXT_END, &overlays_overlay105_DATA_START, 0x8011A700, 0x8011A700, 0x8011B960 },
    { &overlays_overlay106_ROM_START, &overlays_overlay106_ROM_END, &overlays_overlay106_VRAM, &overlays_overlay106_TEXT_START, &overlays_overlay106_TEXT_END, &overlays_overlay106_DATA_START, 0x8010FE60, 0x8010FE60, 0x801100E0 },
    { &overlays_overlay107_ROM_START, &overlays_overlay107_ROM_END, &overlays_overlay107_VRAM, &overlays_overlay107_TEXT_START, &overlays_overlay107_TEXT_END, &overlays_overlay107_DATA_START, 0x801158B0, 0x801158B0, 0x80115CC0 },
    { &overlays_overlay108_ROM_START, &overlays_overlay108_ROM_END, &overlays_overlay108_VRAM, &overlays_overlay108_TEXT_START, &overlays_overlay108_TEXT_END, &overlays_overlay108_DATA_START, 0x8011C640, 0x8011C640, 0x8011CA90 },
    { &overlays_overlay109_ROM_START, &overlays_overlay109_ROM_END, &overlays_overlay109_VRAM, &overlays_overlay109_TEXT_START, &overlays_overlay109_TEXT_END, &overlays_overlay109_DATA_START, 0x80115B90, 0x80115B90, 0x80115DD0 },
    { &overlays_overlay110_ROM_START, &overlays_overlay110_ROM_END, &overlays_overlay110_VRAM, &overlays_overlay110_TEXT_START, &overlays_overlay110_TEXT_END, &overlays_overlay110_DATA_START, 0x80112120, 0x80112120, 0x801123C0 },
    { &overlays_overlay111_ROM_START, &overlays_overlay111_ROM_END, &overlays_overlay111_VRAM, &overlays_overlay111_TEXT_START, &overlays_overlay111_TEXT_END, &overlays_overlay111_DATA_START, 0x801151B0, 0x801151B0, 0x801156D0 },
    { &overlays_overlay112_ROM_START, &overlays_overlay112_ROM_END, &overlays_overlay112_VRAM, &overlays_overlay112_TEXT_START, &overlays_overlay112_TEXT_END, &overlays_overlay112_DATA_START, 0x8010DC00, 0x8010DC00, 0x8010DDF0 },
    { &overlays_minigame_results_ROM_START, &overlays_minigame_results_ROM_END, &overlays_minigame_results_VRAM, &overlays_minigame_results_TEXT_START, &overlays_minigame_results_TEXT_END, &overlays_minigame_results_DATA_START, 0x8010AD90, 0x8010AD90, 0x8010B080 },
    { &overlays_overlay114_ROM_START, &overlays_overlay114_ROM_END, &overlays_overlay114_VRAM, &overlays_overlay114_TEXT_START, &overlays_overlay114_TEXT_END, &overlays_overlay114_DATA_START, 0x801099E0, 0x801099E0, 0x8010A280 },
    { &overlays_overlay115_ROM_START, &overlays_overlay115_ROM_END, &overlays_overlay115_VRAM, &overlays_overlay115_TEXT_START, &overlays_overlay115_TEXT_END, &overlays_overlay115_DATA_START, 0x80108F30, 0x80108F30, 0x80109350 },
    { &overlays_overlay116_ROM_START, &overlays_overlay116_ROM_END, &overlays_overlay116_VRAM, &overlays_overlay116_TEXT_START, &overlays_overlay116_TEXT_END, &overlays_overlay116_DATA_START, 0x80108A30, 0x80108A30, 0x80108FA0 },
    { &overlays_overlay117_ROM_START, &overlays_overlay117_ROM_END, &overlays_overlay117_VRAM, &overlays_overlay117_TEXT_START, &overlays_overlay117_TEXT_END, &overlays_overlay117_DATA_START, 0x80105B80, 0x80105B80, 0x80105B80 },
    { &overlays_debug_message_check_ROM_START, &overlays_debug_message_check_ROM_END, &overlays_debug_message_check_VRAM, &overlays_debug_message_check_TEXT_START, &overlays_debug_message_check_TEXT_END, &overlays_debug_message_check_DATA_START, 0x80106E40, 0x80106E40, 0x80107010 },
    { &overlays_overlay119_ROM_START, &overlays_overlay119_ROM_END, &overlays_overlay119_VRAM, &overlays_overlay119_TEXT_START, &overlays_overlay119_TEXT_END, &overlays_overlay119_DATA_START, 0x8010F710, 0x8010F710, 0x80110DF0 },
    { &overlays_overlay120_ROM_START, &overlays_overlay120_ROM_END, &overlays_overlay120_VRAM, &overlays_overlay120_TEXT_START, &overlays_overlay120_TEXT_END, &overlays_overlay120_DATA_START, 0x8011A880, 0x8011A880, 0x8011AA50 },
    { &overlays_overlay121_ROM_START, &overlays_overlay121_ROM_END, &overlays_overlay121_VRAM, &overlays_overlay121_TEXT_START, &overlays_overlay121_TEXT_END, &overlays_overlay121_DATA_START, 0x80112E90, 0x80112E90, 0x801146E0 },
    { &overlays_start_screen_ROM_START, &overlays_start_screen_ROM_END, &overlays_start_screen_VRAM, &overlays_start_screen_TEXT_START, &overlays_start_screen_TEXT_END, &overlays_start_screen_DATA_START, 0x80114EA0, 0x80114EA0, 0x80117760 },
    { &overlays_overlay123_ROM_START, &overlays_overlay123_ROM_END, &overlays_overlay123_VRAM, &overlays_overlay123_TEXT_START, &overlays_overlay123_TEXT_END, &overlays_overlay123_DATA_START, 0x801146F0, 0x801146F0, 0x80115C00 },
    { &overlays_overlay124_ROM_START, &overlays_overlay124_ROM_END, &overlays_overlay124_VRAM, &overlays_overlay124_TEXT_START, &overlays_overlay124_TEXT_END, &overlays_overlay124_DATA_START, 0x80111490, 0x80111490, 0x80111570 },
    { &overlays_overlay125_ROM_START, &overlays_overlay125_ROM_END, &overlays_overlay125_VRAM, &overlays_overlay125_TEXT_START, &overlays_overlay125_TEXT_END, &overlays_overlay125_DATA_START, 0x8010ABE0, 0x8010ABE0, 0x8010AC40 },
    { 0x00552F50, 0x00552F50, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0, 0x801059A0 },
    { &overlays_overlay127_ROM_START, &overlays_overlay127_ROM_END, &overlays_overlay127_VRAM, &overlays_overlay127_TEXT_START, &overlays_overlay127_TEXT_END, &overlays_overlay127_DATA_START, 0x8010A070, 0x8010A070, 0x8010A290 }
#endif
};

struct overlay_info D_800974F4[] = {
#ifndef CC_CHECK
    { &overlays_shared_board_ROM_START, &overlays_shared_board_ROM_END, &overlays_shared_board_VRAM, &overlays_shared_board_TEXT_START, &overlays_shared_board_TEXT_END, &overlays_shared_board_DATA_START, 0x80102700, 0x80102700, 0x801059A0 },
    { &overlays_overlay129_ROM_START, &overlays_overlay129_ROM_END, &overlays_overlay129_VRAM, &overlays_overlay129_TEXT_START, &overlays_overlay129_TEXT_END, &overlays_overlay129_DATA_START, 0x801029C0, 0x801029C0, 0x80105720 },
    { &overlays_overlay130_ROM_START, &overlays_overlay130_ROM_END, &overlays_overlay130_VRAM, &overlays_overlay130_TEXT_START, &overlays_overlay130_TEXT_END, &overlays_overlay130_DATA_START, 0x800EBDC0, 0x800EBDC0, 0x800EC5E0 }
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
