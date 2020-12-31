#include "common.h"
#include "../../player.h"

extern u8 GetRandomByte();

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EDC20_101840);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EDC40_101860);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EDC4C_10186C);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EDC58_101878);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EDC74_101894);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EDC90_1018B0);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EDF90_101BB0);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EDFAC_101BCC);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EDFC8_101BE8);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EE2A4_101EC4);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EE2C0_101EE0);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EE2DC_101EFC);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EE614_102234);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EE688_1022A8);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EE694_1022B4);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EE6C0_1022E0);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EE700_102320);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EE740_102360);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EE7AC_1023CC);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EE884_1024A4);

void func_800EE94C_10256C(s32 arg0, s16 arg1, s32 arg2) {
    func_800D9D84_ED9A4(arg0, arg1, 0, 0xA, arg2 & 0xFFFF);
}

void func_800EE97C_10259C(s32 arg0) {
    while ((func_800D9E0C_EDA2C(arg0) & 1) == 0) {
        SleepVProcess();
    }
}

// calculates player placement
s32 func_800EE9C0_1025E0(s32 playerIndex) {
    s32 i;
    s32 placements[4];
    s32 placement;

    for (i = 0; i < 4; i++) {
        placements[i] = func_800EECB0_1028D0(i);
    }

    placement = 0;
    for (i = 0; i < 4; i++) {
        if (i != playerIndex) {
            placement += placements[playerIndex] < placements[i];
        }
    }

    return placement;
}

// calculates player placement with bonus stars
INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EEA58_102678);
// s32 func_800EEA58_102678(s32 playerIndex) {
//     s32 i;
//     s32 placements[4];
//     s32 placement;

//     s32 max;

//     // Check if bonus stars not enabled.
//     if (func_80035F98(0xF) == 0) {
//         return func_800EE9C0_1025E0(playerIndex);
//     }

//     // Calculate basic placement values to start.
//     for (i = 0; i < 4; i++) {
//         placements[i] = func_800EECB0_1028D0(i);
//     }

//     // Factor in Mini-Game star coins.
//     for (i = 0, max = -100000; i < 4; i++) { // FIXME: Why is delay slot not used?
//         if (max < gPlayers[i].minigame_star) {
//             max = gPlayers[i].minigame_star;
//         }
//     }
//     for (i = 0; i < 4; i++) {
//         if (gPlayers[i].minigame_star == max) {
//             placements[i] += 1000;
//         }
//     }

//     // Coin star
//     for (i = 0, max = -100000; i < 4; i++) {
//         if (max < gPlayers[i].max_coins) {
//             max = gPlayers[i].max_coins;
//         }
//     }
//     for (i = 0; i < 4; i++) {
//         if (gPlayers[i].max_coins == max) {
//             placements[i] += 1000;
//         }
//     }

//     // Happening star
//     for (i = 0, max = -100000; i < 4; i++) {
//         if (max < gPlayers[i].happening_space_count) {
//             max = gPlayers[i].happening_space_count;
//         }
//     }
//     for (i = 0; i < 4; i++) {
//         if (gPlayers[i].happening_space_count == max) {
//             placements[i] += 1000;
//         }
//     }

//     for (i = 0, placement = 0; i < 4; i++) {
//         if (i != playerIndex) {
//             placement += placements[playerIndex] < placements[i];
//         }
//     }

//     return placement;
// }

// A heuristic "score" used for player placement calculations.
s32 func_800EECB0_1028D0(s32 playerIndex) {
    return (gPlayers[playerIndex].stars * 1000) + gPlayers[playerIndex].coins;
}

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EECF0_102910);
// s32 func_800EECF0_102910(s32 playerIndex) {
//     s32 i;
//     s32 max;
//     s32 placement;

//     placement = (gPlayers[playerIndex].stars * 1000) + gPlayers[playerIndex].coins;

//     if (func_80035F98(0xF) != 0) {
//         for (i = 0, max = -100000; i < 4; i++) { // FIXME: Same delay slot issue.
//             if (max < gPlayers[i].minigame_star) {
//                 max = gPlayers[i].minigame_star;
//             }
//         }
//         if (gPlayers[playerIndex].minigame_star == max) {
//             placement += 1000;
//         }

//         for (i = 0, max = -100000; i < 4; i++) {
//             if (max < gPlayers[i].max_coins) {
//                 max = gPlayers[i].max_coins;
//             }
//         }
//         if (gPlayers[playerIndex].max_coins == max) {
//             placement += 1000;
//         }

//         for (i = 0, max = -100000; i < 4; i++) {
//             if (max < gPlayers[i].happening_space_count) {
//                 max = gPlayers[i].happening_space_count;
//             }
//         }
//         if (gPlayers[playerIndex].happening_space_count == max) {
//             placement += 1000;
//         }
//     }

//     return placement;
// }

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EEE84_102AA4);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EEF80_102BA0);

// Picks random number out of 100
INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EEFEC_102C0C);

void func_800EF068_102C88() {

}

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EF070_102C90);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EF0D8_102CF8);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EF200_102E20);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EF208_102E28);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EF3BC_102FDC);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EF67C_10329C);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EF698_1032B8);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EF768_103388);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EF844_103464);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EF898_1034B8);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EF8F4_103514);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EFA34_103654);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EFD8C_1039AC);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EFE0C_103A2C);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EFE58_103A78);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EFEF4_103B14);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800EFFE8_103C08);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F01D0_103DF0);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F0ABC_1046DC);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F0BF8_104818);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F0C64_104884);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F0D14_104934);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F0E28_104A48);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F0E34_104A54);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F0EF0_104B10);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F102C_104C4C);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F1C94_1058B4);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F1D34_105954);

INCLUDE_ASM(s32, "overlays/shared_board/101840", func_800F1EC8_105AE8);
