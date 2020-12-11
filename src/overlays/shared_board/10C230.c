#include "common.h"
#include "../../object.h"
#include "../../process.h"
#include "../../spaces.h"

extern s16 D_800A1768;

struct strCD058 {
    /* 0x00 - 800CD058 */ s8 unk0;
    /* 0x01 - 800CD059 */ s8 current_board_index;
    /* 0x02 - 800CD05A */ s8 total_turns;
    /* 0x03 - 800CD05B */ s8 current_turn;
    /* 0x04 - 800CD05C */ s8 current_game_length; // 00=Lite Play,01=Standard Play,02=Full Play,03=Custom Play
    /* 0x05 - 800CD05D */ s8 current_star_spawn; // Index of star space (index into star_spawn_indices)
    /* 0x06 - 800CD05E */ s8 star_spawn_indices[8];
    /* 0x0F - 800CD067 */ s8 current_player_index;
    /* 0x10 - 800CD068 */ s8 unk10;
    /* 0x11 - 800CD069 */ s8 current_space_index;
    /* 0x12 - 800CD070 */ s8 unk12;
    /* 0x13 - 800CD071 */ s8 unk13;
    /* 0x14 - 800CD072 */ s8 unk14;
    /* 0x15 - 800CD073 */ s8 unk15;

    // 800cd09c flag for re-roll
};
extern struct strCD058 D_800CD058;

// is 800CD0B0 part of above struct?

extern s16 D_800D4196;

struct str800D2010 {
    s32 unk0;
    s16 unk4;
    s16 unk6;
};
extern struct str800D2010 D_800D2010[];
extern struct str800D2010 D_800D20F0[];

extern s16 D_800D6B60;

extern u32 D_80101B40[];

extern s32 D_80105668;
extern s16 D_8010566C;
extern s16 D_80105664;
extern s16 D_800D1380;
extern s16 D_80105666;

void func_800F8610_10C230(s32 arg0, s16 arg1, s16 arg2) {
    struct str800D2010 *str;
    s32 temp;

    str = &D_800D20F0[D_800D6B60++];

    switch (arg0) {
        case -1:
            temp = D_800D2010[D_800A1768].unk0;
            break;

        case -2:
            temp = D_80101B40[D_800CD058.current_board_index];
            break;

        default:
            temp = arg0;
            break;
    }

    str->unk0 = temp;
    str->unk4 = arg1;
    str->unk6 = arg2;
    if (D_800D6B60 >= 5) {
        D_800D6B60 = 4;
    }
}

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F86B4_10C2D4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8774_10C394);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F884C_10C46C);

s16 func_800F8858_10C478() {
    return D_800D4196;
}

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8864_10C484);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F88D0_10C4F0);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F88FC_10C51C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8908_10C528);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F89D0_10C5F0);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8C74_10C894);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D48_10C968);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D54_10C974);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D60_10C980);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D6C_10C98C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D78_10C998);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D84_10C9A4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F915C_10CD7C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9168_10CD88);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9174_10CD94);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9198_10CDB8);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F91A4_10CDC4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F92A0_10CEC0);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F933C_10CF5C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F93A4_10CFC4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F95FC_10D21C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F965C_10D27C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F96E0_10D300);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9A68_10D688);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9C68_10D888);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9CA0_10D8C0);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9D1C_10D93C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9F84_10DBA4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA104_10DD24);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA388_10DFA8);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA448_10E068);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA640_10E260);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA818_10E438);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA95C_10E57C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FAB98_10E7B8);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FB578_10F198);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FB624_10F244);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC3D0_10FFF0);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC4E0_110100);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC594_1101B4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC7C8_1103E8);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC8A4_1104C4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC938_110558);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC968_110588);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC998_1105B8);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC9E0_110600);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FCA14_110634);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FCA4C_11066C);

// Some sort of main process loop during board play.
INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FCA7C_11069C);
// void func_800FCA7C_11069C(void) {
//     s16 temp_a0;
//     s16 temp_a0_3;
//     s16 temp_a0_5;
//     s16 temp_a1;
//     s16 temp_a1_2;
//     s16 temp_a1_3;
//     s16 temp_a1_4;
//     s16 temp_a1_5;
//     s16 temp_a1_6;
//     s16 temp_a3;
//     s16 temp_a3_2;
//     s16 temp_a3_3;
//     s16 temp_a3_4;
//     s16 temp_a3_5;
//     s16 temp_a3_6;
//     s16 temp_s0;
//     s16 temp_s0_10;
//     s16 temp_s0_11;
//     s16 temp_s0_12;
//     s16 temp_s0_2;
//     s16 temp_s0_3;
//     s16 temp_s0_5;
//     s16 temp_s0_6;
//     s16 temp_s0_7;
//     s16 temp_s0_8;
//     s16 temp_s0_9;
//     s16 temp_s1_2;
//     s16 temp_s5;
//     s16 temp_s5_2;
//     s16 temp_s5_3;
//     s16 temp_s5_4;
//     s16 temp_s5_5;
//     s16 temp_v0_3;
//     s16 temp_v0_5;
//     s16 temp_v1_2;
//     s32 temp_a0_2;
//     s32 temp_a0_4;
//     s32 temp_a0_6;
//     s32 temp_a0_7;
//     s32 temp_s0_13;
//     s32 temp_s0_14;
//     s32 temp_s1;
//     s32 temp_s1_10;
//     s32 temp_s1_3;
//     s32 temp_s1_4;
//     s32 temp_s1_5;
//     s32 temp_s1_6;
//     s32 temp_s1_7;
//     s32 temp_s1_8;
//     s32 temp_s1_9;
//     struct process *curProcess;
//     s32 temp_v0_6;
//     s32 temp_v1_3;
//     s8 temp_s0_4;
//     s8 temp_s3;
//     s8 temp_v0;
//     s8 temp_v1;
//     s8 temp_v1_14;
//     s8 temp_v1_5;
//     s8 temp_v1_6;
//     s8 temp_v1_7;
//     u16 temp_v1_11;
//     u16 temp_v1_12;
//     u16 temp_v1_13;
//     u32 temp_v1_4;
//     u8 temp_v1_10;
//     u8 temp_v1_8;
//     u8 temp_v1_9;
//     void *temp_a2;
//     void *temp_ret;
//     void *temp_s3_2;
//     s32 phi_s1;
//     s32 phi_a0;
//     s32 phi_s1_2;
//     s32 phi_v0;
//     s32 phi_v0_2;
//     s32 phi_s1_3;
//     s32 phi_v0_3;
//     s16 phi_s5;
//     s32 phi_s1_4;
//     ? phi_a1;
//     u8 phi_v0_4;
//     s16 phi_s1_5;
//     s32 phi_v1;
//     s16 phi_v0_5;
//     s32 phi_s0;
//     s32 phi_a0_2;
//     s32 phi_s1_6;

//     s32 i;
//     struct player *player;
//     struct space_data *spacedata;

//     curProcess = GetCurrentProcess();

//     while (TRUE) {
//         if (D_800D1240 < 2) {
//             phi_s1 = 0;
//             if (D_800CD058.current_player_index == 0) {
//                 for (i = 0; i < 4; i++) {
//                     GetPlayerStruct(phi_s1)->turn_color_status = 0;
//                     func_800F70F8_10AD18();
//                 }

//                 temp_v1 = D_800CD058.total_turns;
//                 if (temp_v1 >= 0) {
//                     temp_v1_2 = (temp_v1 - D_800CD058.current_turn) + 1;
//                     if (temp_v1_2 < 6 && temp_v1_2 > 0) {
//                         func_80035FDC(2);
//                     }
//                 }

//                 if ((func_80035F98(1) == 0) && (D_800CD058.current_turn >= 2)) {
//                     temp_v0 = D_800CD058.unk12;
//                     if (temp_v0 != 0) {
//                         if (temp_v0 == 1) {
//                             D_800CD058.unk12 = 2;
//     block_13:
//                             func_80035EF4(0);
//                             func_80035FDC(0);
//                             func_80060394(1, &subroutine_argC, 0x5900);
//                             temp_s1_2 = func_8005A968(0, 0, subroutine_argC, subroutine_argC, 0, (?32) (u8)2);
//                             temp_s0 = temp_s1_2;
//                             func_8005BEE0(temp_s0, 0);
//                             func_8005B43C(temp_s0, 0x5900, -1, -1);
//                             func_8005BDFC(temp_s0, 0);

//                             while (func_8005E0C0(temp_s1_2) != 0) {
//                                 SleepVProcess();
//                             }

//                             if ((D_800CD058.unk0 & 4) != 0) {
//                                 func_80035EF4(0x18);
//                                 func_80035EF4(0x28);
//                                 func_8005035C(1);
//                             }
//                             else {
//                                 func_80035EF4(0x16);
//                                 func_800500E0(1);
//                             }
//                             func_8005F364(temp_s1_2);
//                             func_80060394(1, &subroutine_argC, 0x5901);
//                             temp_s0_2 = func_8005A968(0, 0, subroutine_argC, subroutine_argC, 0, (?32) (u8)2);
//                             func_8005BEE0(temp_s0_2, 0);
//                             func_8005B43C(temp_s0_2, 0x5901, -1, -1);
//                             func_8005BDFC(temp_s0_2, 0);
//                             SleepProcess(15);
//                             func_8005F364(temp_s0_2);
//                         }
//                     } else {
//                         goto block_13;
//                     }
//                 }
//                 func_8003602C(1);
//                 D_800A12D4 = 0;
//                 D_80105660 = func_800EBAC8_FF6E8(-2, 7);
//             }
//         }

//         D_800A12D4 = 1;

//         for (i = 0; i < 4; i++) {
//             func_800F4798_1083B8(i, GetPlayerStruct(i)->turn_color_status);
//             func_800F96E0_10D300(i, 1);
//             temp_v1_3 = D_800D1240;
//             if (temp_v1_3 != 8) {
//                 if ((temp_v1_3 < 8) || (temp_v1_3 >= 16) || (temp_v1_3 < 10)) {
//                     D_800CD0A8 = (u16) (D_800CD0A8 & ~1);
//                 }
//             }
//         }

//         func_800FC594_1101B4();
//         player = GetPlayerStruct(D_800CD058.current_player_index);
//         temp_s0_3 = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index);
//         GetSpaceData(temp_s0_3);
//         SetCurrentSpaceIndex(temp_s0_3);
//         temp_v1_4 = D_800D1240;
//         if (temp_v1_4 < 2) {
//             func_800EBAC8_FF6E8(-4, 7);
//             func_8001FDE8(GetPlayerStruct(0)->obj->unk3C->unk40->unk0);
//             func_8001FDE8(GetPlayerStruct(1)->obj->unk3C->unk40->unk0);
//             func_8001FDE8(GetPlayerStruct(2)->obj->unk3C->unk40->unk0);
//             func_8001FDE8(GetPlayerStruct(3)->obj->unk3C->unk40->unk0);
//             func_800F2304_105F24(-1, -1, 2);
//             func_800F915C_10CD7C(1);
//             if (D_800CD058.current_player_index == 4) {
//                 func_800E648C_FA0AC();
//             }
//             if (D_800A12CC == 0) {
//                 D_800C9938 = 1.0f;
//                 func_800E8DD4_FC9F4(1.0f);
//                 phi_v0 = func_800F29EC_10660C();
//             }
//             else {
//                 temp_v1_5 = D_800CD058.current_player_index;
//                 if (((temp_v1_5 == 4) | (temp_v1_5 == 0)) != 0) {
//                     D_800C9938 = 1.0f;
//                     func_800E8DD4_FC9F4(1.0f);
//                     phi_v0 = func_800F29EC_10660C();
//                 }
//                 else {
//                     D_800C9938 = 1.0f;
//                     phi_v0 = func_800E8EDC_FCAFC(1.0f);
//                 }
//             }
//             LinkChildProcess(curProcess, phi_v0);
//             WaitForChildProcess();
//     block_60:
//             SleepProcess(4);
//             func_800FF900_113520(-1, 3);
//             LinkChildProcess(curProcess, func_800E5CE0_F9900(D_800CD058.current_player_index));
//             WaitForChildProcess();
//             func_800EBAC8_FF6E8(-5, 7);
//         } else {
//             if (temp_v1_4 != 0xC) {
//                 if ((s32) temp_v1_4 >= 0xD) {
//                     if (temp_v1_4 != 0x12) {

//                     } else {
//                         phi_v0_2 = 0 * 8;
//                         phi_s1_3 = 0;
//     loop_38:
//                         phi_v0_3 = phi_s1_3 < 4;
//                         if (*(&D_800D1110 + ((phi_v0_2 - phi_s1_3) * 8)) == 3) {
//                             temp_s1_4 = phi_s1_3 + 1;
//                             phi_v0_2 = temp_s1_4 * 8;
//                             phi_s1_3 = temp_s1_4;
//                             if (temp_s1_4 < 4) {
//                                 goto loop_38;
//                             }
//                             phi_v0_3 = temp_s1_4 < 4;
//                         }
//                         if (phi_v0_3 == 0) {
//     block_42:
//     block_43:
//                             func_800FA640_10E260(temp_ret, 1);
//                         }
//                     }
//                 } else if (((s32) temp_v1_4 < 0xA) && ((s32) temp_v1_4 >= 8)) {
//                     goto block_43;
//                 }
//             } else {
//                 goto block_42;
//             }

//             while (func_800620BC() != 0) {
//                 SleepVProcess();
//             }

//             D_800D037C = 1;
//             if (D_800D1240 - 2 < 18) {
//                 func_800FA448_10E068();
//                 func_800F88D0_10C4F0();
//             }
//             else {
//                 goto block_60;
//             }
//         }

//         func_800FC7C8_1103E8();
//         D_800C9938 = 1.3f;
//         LinkChildProcess(curProcess, func_800E8EDC_FCAFC(1.3f));
//         temp_s1_5 = func_800DD6C4_F12E4(D_800CD058.current_player_index);
//         WaitForChildProcess();
//         SleepProcess(1);
//         if (D_800CD058.current_player_index != 4) {
//             D_800CDD58 = 1;
//             D_800D037C = 1;
//             D_800CDD64 = 1;
//             D_800CC4A0 = 1;
//         }
//         LinkChildProcess(curProcess, temp_s1_5);
//         WaitForChildProcess();
//         func_800FC8A4_1104C4();
//         D_800CDD58 = 0;
//         D_800CDD64 = 0;
//         D_800D41C0 = func_800DCD9C_F09BC(D_800CD058.current_player_index);
//         if ((D_80105660 == 0) && ((player->flags2 & 0x80) != 0)) {
//             player->next_chain_index = player->reverse_chain_index;
//             player->next_space_index = player->reverse_space_index;
//             player->flags2 = (player->unk17 ^ 1);
//         }
//         temp_s5 = GetCurrentSpaceIndex();
//         D_80105660 = func_800EBAC8_FF6E8(temp_s5, 9);
//         func_800F2304_105F24(-1, 0, 2);
//         phi_s5 = temp_s5;

//     loop_67:
//         if (D_800D41C0 != 0) {
//             func_800EBAC8_FF6E8(phi_s5, 8);

//             temp_s3 = player->cur_chain_index;
//             temp_s0_4 = player->cur_space_index;

//             player->cur_chain_index = player->next_chain_index;
//             player->cur_space_index = player->next_space_index;

//             for (i = 0; i < 4; i++) {
//                 func_800F96E0_10D300(i, (D_800CD058.unk15 * 5) + 5);
//             }

//             player->cur_chain_index = temp_s3;
//             player->cur_space_index = temp_s0_4;
//             if (((GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->next_chain_index, player->next_space_index))->unk2 & 0x8000) != 0)
//                 || (func_800F9A68_10D688(D_800CD058.current_player_index) != 0)) {
//                 func_8004ACE0(0x3A, D_800CD058.current_player_index);
//                 func_800F2304_105F24(-1, 2, 0);
//                 temp_v1_7 = D_800CD058.unk15;
//                 if (temp_v1_7 != 1) {
//                     if ((s32) temp_v1_7 < 2) {
//                         if (temp_v1_7 != 0) {

//                         } else {
//                             player->obj->unk34 = 8.0f;
//                             player->obj->unk38 = -2.0f;
//                             func_800ED410_101030(D_800CD058.current_player_index, 7);
//                         }
//                     } else if (temp_v1_7 != (u8)2) {

//                     } else {
//                         player->obj->unk34 = 2.0f;
//                         player->obj->unk38 = -0.125f;
//                         func_800ED410_101030(D_800CD058.current_player_index, 0x1E);
//                     }
//                 } else {
//                     player->obj->unk34 = 4.0f;
//                     player->obj->unk38 = -0.5f;
//                     func_800ED410_101030(D_800CD058.current_player_index, 0xF);
//                 }
//             } else {
//                 if (player->obj->unk46 != 0) {
//                     func_800F2304_105F24(-1, 0, 2);
//                 }
//                 temp_v1_6 = D_800CD058.unk15;
//                 if (temp_v1_6 != 1) {
//                     if ((s32) temp_v1_6 < 2) {
//                         if (temp_v1_6 != 0) {

//                         } else {
//                             func_8001C92C(player->obj->unk3C->unk40->unk0, 0x40000000);
//                             phi_a1 = 5;
//     block_92:
//                             func_800ED410_101030(D_800CD058.current_player_index, phi_a1);
//                         }
//                     } else if (temp_v1_6 != (u8)2) {

//                     } else {
//                         func_8001C92C(player->obj->unk3C->unk40->unk0, 0x3F400000);
//                         phi_a1 = 0xF;
//                         goto block_92;
//                     }
//                 } else {
//                     func_8001C92C(player->obj->unk3C->unk40->unk0, 1.0f);
//                     phi_a1 = 0xA;
//                     goto block_92;
//                 }
//                 func_8001C92C(player->obj->unk3C->unk40->unk0, 1.0f);
//             }
//             player->reverse_chain_index = player->cur_chain_index;
//             player->reverse_space_index = player->cur_space_index;
//             player->cur_chain_index = player->next_chain_index;
//             player->cur_space_index = player->next_space_index;
//             if ((player->flags2 & 1) != 0) {
//                 phi_v0_4 = player->next_space_index - 1;
//             } else {
//                 phi_v0_4 = player->next_space_index + 1;
//             }
//             player->next_space_index = phi_v0_4;
//             temp_s0_5 = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index);
//             temp_s3_2 = GetSpaceData(temp_s0_5);
//             SetCurrentSpaceIndex(temp_s0_5);
//             if ((temp_s3_2->space_type - 1) < 15) {
//                 func_800DBFBC_EFBDC(D_800CD058.current_player_index);
//                 D_800D41C0--;
//                 func_800EB97C_FF59C(temp_s5_2);
//             }
//             if (D_800D41C0 != 0) {
//                 func_800F95FC_10D21C(temp_s3_2->space_type);
//             } else {
//                 func_800F965C_10D27C(temp_s3_2->space_type);
//             }
//             func_800E455C_F817C();
//             D_80105660 = func_800EBAC8_FF6E8(temp_s5_2, 1);
//             phi_s5 = temp_s5_2;
//             if ((s32) D_80105664 < 0) {
//                 goto loop_67;
//             }
//             D_800D1240 = (?32) (u8)2;
//             SleepProcess(-1);
//             phi_s5 = temp_s5_2;
//             if ((D_80105660 & 1) != 0) {
//                 temp_v0_3 = GetCurrentSpaceIndex();
//                 temp_s5_3 = temp_v0_3;
//                 D_80105660 = func_800EBAC8_FF6E8(temp_v0_3, 2);
//                 phi_s5 = temp_s5_3;
//                 if ((s32) D_80105664 >= 0) {
//                     D_800D1240 = 3;
//                     SleepProcess(-1);
//                     phi_s5 = temp_s5_3;
//                 }
//             }
//             if ((D_80105660 & 2) != 0) {
//                 D_800D41C0 = 0;
//             } else {
//                 func_800DB884_EF4A4(D_800CD058.current_player_index);
//                 SleepProcess(10);
//             }
//             goto loop_67;
//         }
//         if (D_800CD058.current_board_index == 3) {
//             D_800CD09E = 0;
//         }
//         temp_v1_8 = player->flags2;
//         if ((temp_v1_8 & 0x80) != 0) {
//             if ((temp_v1_8 & 1) != 0) {
//                 temp_v1_9 = player->reverse_chain_index;
//                 player->reverse_chain_index = player->next_chain_index;
//                 player->next_chain_index = temp_v1_9;
//                 temp_v1_10 = player->reverse_space_index;
//                 player->reverse_space_index = player->next_space_index;
//                 player->next_space_index = temp_v1_10;
//             }
//             player->flags2 = (player->flags2 & 0x7E);
//         }
//         func_800F2304_105F24(-1, -1, 2);
//         temp_s5_4 = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index);
//         if ((GetSpaceData(temp_s5_4)->space_type - 1) < 15) {
//             func_800FF900_113520(-1, 3);
//             player->happening_space_count++;
//         }
//         D_800D1240 = 4;
//         D_80105660 = func_800EBAC8_FF6E8(temp_s5_4, 3);
//         if (D_80105664 >= 0) {
//             SleepProcess(-1);
//             if ((D_80105660 & 1) != 0) {
//                 D_80105660 = func_800EBAC8_FF6E8(GetCurrentSpaceIndex(), 4);
//                 if (D_80105664 >= 0) {
//                     D_800D1240 = 5;
//                     SleepProcess(-1);
//                 }
//             }
//             SleepProcess(0x1E);
//         }
//         func_800ECC0C_10082C(&subroutine_arg8);
//         temp_a2 = &player->unk24->unk18;
//         func_800ED1E4_100E04(temp_a2, &subroutine_arg8, temp_a2, 8);
//         temp_s0_6 = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index);
//         spacedata = GetSpaceData(temp_s0_6);
//         if ((D_800D124E == temp_s0_6) || (D_800D4080 != 0)) {
//             func_800FF900_113520(-1, 5);
//             LinkChildProcess(curProcess, func_800E8EDC_FCAFC(0x3FCCCCCD));
//             temp_s1_7 = func_800DDDD4_F19F4(D_800CD058.current_player_index);
//             func_800DE858_F2478();
//             func_80060394(1, &subroutine_argC, 0x3F00);
//             temp_a3 = (s16) subroutine_argC;
//             temp_s0_7 = func_80061188(-1, 0xA0 - ((s32) (temp_a3 + ((u32) (subroutine_argC << 0x10) >> 0x1F)) >> 1), 0x96, temp_a3, (?32) subroutine_argC, 0);
//             func_8005B43C(temp_s0_7, 0x3F00, -1, -1);
//             func_80061388(temp_s0_7);
//             func_800600C0(temp_s0_7, 1);
//             WaitForChildProcess();
//             func_800600C0(temp_s0_7, 0);
//             func_800EDC58_101878(temp_s0_7, player->unk1D);
//             func_80061A5C(temp_s0_7, 0);
//             func_8005F364(temp_s0_7);
//             func_800DE868_F2488();

//             while ((func_800DE84C_F246C() & 0xFF) == 0) {
//                 SleepVProcess(1);
//             }

//             func_80060394(1, &subroutine_argC, 0x3F01);
//             temp_a3_2 = (s16) subroutine_argC;
//             temp_s0_8 = func_80061188(-1, 0xA0 - ((s32) (temp_a3_2 + ((u32) (subroutine_argC << 0x10) >> 0x1F)) >> 1), 0x96, temp_a3_2, (?32) subroutine_argC, 0);
//             func_8005B43C(temp_s0_8, 0x3F01, -1, -1);
//             func_80061388(temp_s0_8);
//             func_800EDC58_101878(temp_s0_8, player->unk1D);
//             func_80061A5C(temp_s0_8, 0);
//             func_8005F364(temp_s0_8);
//             func_800DE868_F2488();
//             LinkChildProcess(curProcess, temp_s1_7);
//             WaitForChildProcess();
//             LinkChildProcess(curProcess, func_800E8EDC_FCAFC(0x3FA66666));
//             WaitForChildProcess();
//             SleepProcess(1);
//             temp_v1_11 = D_800D6A44;
//             temp_a0 = temp_v1_11 + 1;
//             D_800D6A44 = temp_a0;
//             *(&D_800D59E0 + ((s32) (temp_v1_11 << 0x10) >> 0xF)) = (u16) D_800D124E;
//             temp_a1 = temp_a0;
//             temp_a0_2 = (s32) (temp_a0 << 0x10) >> 0x1F;
//             temp_a1_2 = temp_a1 - (((MULT_HI(temp_a1, 0x66666667) >> 2) - temp_a0_2) * 0xA);
//             D_800D6A44 = temp_a1_2;
//             D_800D124E = (u16)-1;
//             func_800FC594_1101B4(temp_a0_2, temp_a1_2);
//         }
//         if ((D_800CE1C4 == temp_s5_5) || (D_800D2130 != 0)) {
//             func_800FF900_113520(-1, 5);
//             LinkChildProcess(curProcess, func_800E8EDC_FCAFC(0x3FCCCCCD));
//             temp_s1_8 = func_800DE7E4_F2404(D_800CD058.current_player_index);
//             func_800DE858_F2478();
//             func_80060394(1, &subroutine_argE, 0x3F00);
//             temp_a3_3 = (s16) subroutine_argE;
//             temp_s0_9 = func_80061188(-1, 0xA0 - ((s32) (temp_a3_3 + ((u32) (subroutine_argE << 0x10) >> 0x1F)) >> 1), 0x96, temp_a3_3, (?32) subroutine_argE, 0);
//             func_8005B43C(temp_s0_9, 0x3F00, -1, -1);
//             func_80061388(temp_s0_9);
//             func_800600C0(temp_s0_9, 1);
//             WaitForChildProcess();
//             func_800600C0(temp_s0_9, 0);
//             func_800EDC58_101878(temp_s0_9, player->unk1D);
//             func_80061A5C(temp_s0_9, 0);
//             func_8005F364(temp_s0_9);
//             func_800DE868_F2488();

//             while ((func_800DE84C_F246C() & 0xFF) == 0) {
//                 SleepVProcess(curProcess);
//             }

//             LinkChildProcess(curProcess, temp_s1_8);
//             WaitForChildProcess();
//             func_80060394(1, &subroutine_argE, 0x3F02);
//             temp_a3_4 = (s16) subroutine_argE;
//             temp_s0_10 = func_80061188(-1, 0xA0 - ((s32) (temp_a3_4 + ((u32) (subroutine_argE << 0x10) >> 0x1F)) >> 1), 0x96, temp_a3_4, (?32) subroutine_argE, 0);
//             func_8005B43C(temp_s0_10, 0x3F02, -1, -1);
//             func_80061388(temp_s0_10);
//             func_800EDC58_101878(temp_s0_10, player->unk1D);
//             func_80061A5C(temp_s0_10, 0);
//             func_8005F364(temp_s0_10);
//             LinkChildProcess(curProcess, func_800E8EDC_FCAFC(0x3FA66666));
//             WaitForChildProcess();
//             SleepProcess(1);
//             temp_v1_12 = D_800D1FEC;
//             temp_a0_3 = temp_v1_12 + 1;
//             D_800D1FEC = temp_a0_3;
//             *(&D_800CE1E8 + ((s32) (temp_v1_12 << 0x10) >> 0xF)) = (u16) D_800CE1C4;
//             temp_a1_3 = temp_a0_3;
//             temp_a0_4 = (s32) (temp_a0_3 << 0x10) >> 0x1F;
//             temp_a1_4 = temp_a1_3 - (((MULT_HI(temp_a1_3, 0x66666667) >> 2) - temp_a0_4) * 0xA);
//             D_800D1FEC = temp_a1_4;
//             D_800CE1C4 = (u16)-1;
//             func_800FC594_1101B4(temp_a0_4, temp_a1_4);
//         }
//         if ((D_800CC4E4 == temp_s5_5) || (D_800D1708 != 0)) {
//             func_800FF900_113520(-1, 5);
//     loop_145:
//             phi_s1_5 = (u16)0;
//     loop_146:
//             if ((s32) *(&D_80101E71 + ((s32) (phi_s1_5 << 0x10) >> 0xF)) < (s32) (s16) (func_800EEF80_102BA0(0x42C80000) + 1)) {
//                 phi_s1_5 = phi_s1_5 + 1;
//                 goto loop_146;
//             }
//             if (D_800CD0AA != 0) {
//                 if (*(&D_80101E70 + ((s32) (phi_s1_5 << 0x10) >> 0xF)) == 0x12) {
//                     goto loop_145;
//                 }
//             }
//             LinkChildProcess(curProcess, func_800E8EDC_FCAFC(0x3FCCCCCD));
//             func_800DE414_F2034(D_800CD058.current_player_index, *(&D_80101E70 + ((s32) (phi_s1_5 << 0x10) >> 0xF)));
//             func_800DE858_F2478();
//             func_80060394(1, &subroutine_arg10, 0x3F00);
//             temp_a3_5 = (s16) subroutine_arg10;
//             temp_s0_11 = func_80061188(-1, 0xA0 - ((s32) (temp_a3_5 + ((u32) (subroutine_arg10 << 0x10) >> 0x1F)) >> 1), 0x96, temp_a3_5, (?32) subroutine_arg10, 0);
//             func_8005B43C(temp_s0_11, 0x3F00, -1, -1);
//             func_80061388(temp_s0_11);
//             func_800600C0(temp_s0_11, 1);
//             WaitForChildProcess();
//             func_800600C0(temp_s0_11, 0);
//             func_800EDC58_101878(temp_s0_11, player->unk1D);
//             func_80061A5C(temp_s0_11, 0);
//             func_8005F364(temp_s0_11);
//             func_800DE868_F2488();

//             while ((func_800DE84C_F246C() & 0xFF) == 0) {
//                 SleepVProcess();
//             }
//             func_800DE868_F2488();
//             temp_s1_9 = phi_s1_5 + 0x3F04;
//             func_8006022C(temp_s1_9, 0);
//             func_80060394(1, &subroutine_arg10, 0x3F03);
//             temp_a3_6 = (s16) subroutine_arg10;
//             temp_s0_12 = func_80061188(-1, 0xA0 - ((s32) (temp_a3_6 + ((u32) (subroutine_arg10 << 0x10) >> 0x1F)) >> 1), 0x96, temp_a3_6, (?32) subroutine_arg10, 0);
//             func_8005B6BC(temp_s0_12, temp_s1_9, 0);
//             func_8005B43C(temp_s0_12, 0x3F03, -1, -1);
//             func_80061388(temp_s0_12);
//             func_800EDC58_101878(temp_s0_12, player->unk1D);
//             func_80061A5C(temp_s0_12, 0);
//             func_8005F364(temp_s0_12);
//             if (func_800E49DC_F85FC(D_800CD058.current_player_index) == -1) {
//                 func_800EC414_100034(0x3F0A);
//             }
//             func_800DE858_F2478();
//             SleepProcess(5);

//             while ((func_800DE84C_F246C() & 0xFF) == 0) {
//                 SleepVProcess();
//             }
//             SleepProcess(10);
//             LinkChildProcess(curProcess, func_800E8EDC_FCAFC(0x3FA66666));
//             WaitForChildProcess();
//             SleepProcess(1);
//             temp_v1_13 = D_800D1F7A;
//             temp_a0_5 = temp_v1_13 + 1;
//             D_800D1F7A = temp_a0_5;
//             *(&D_800CC378 + ((s32) (temp_v1_13 << 0x10) >> 0xF)) = (u16) D_800CC4E4;
//             temp_a1_5 = temp_a0_5;
//             temp_a0_6 = (s32) (temp_a0_5 << 0x10) >> 0x1F;
//             temp_a1_6 = temp_a1_5 - (((MULT_HI(temp_a1_5, 0x66666667) >> 2) - temp_a0_6) * 0xA);
//             D_800D1F7A = temp_a1_6;
//             D_800CC4E4 = (u16)-1;
//             func_800FC594_1101B4(temp_a0_6, temp_a1_6);
//         }
//         if (spacedata->space_type != SPACE_HAPPENING) {
//             temp_v0_5 = func_800FA818_10E438(1);
//             if ((temp_v0_5 << 0x10) != 0) {
//                 D_800CD0B0.unk0 = temp_v0_5;
//                 D_800CD0B0.unk2 = (s16) (1 << player->unk1D);
//                 func_800FF900_113520(player->unk1D, 3);
//                 temp_v0_6 = func_800FAB98_10E7B8(player, 0);
//                 if (temp_v0_6 != 0) {
//                     if (temp_v0_6 == 1) {
//                         SleepProcess(-1);
//                     }
//                     func_800FA95C_10E57C();
//                     func_800FA448_10E068();
//                 }
//             }
//         }
//         func_800ECDD4_1009F4(-1, spacedata->space_type);
//         func_800F4798_1083B8(D_800CD058.unkF, player->unk1C);
//         if ((spacedata->space_type - 1) < 15) {
//             phi_v1 = 1;
//             if (func_80035F98(2) != 0) {
//                 phi_v1 = 2;
//             }
//             temp_s0_13 = (phi_v1 * 2) + phi_v1;
//             func_800E1F48_F5B68(D_800CD058.current_player_index, temp_s0_13);
//             func_800F5D44_109964(D_800CD058.current_player_index, temp_s0_13);
//             SleepProcess(0x1E);
//         }
//         D_800D1240 = 7;
//         D_80105660 = func_800EBAC8_FF6E8(temp_s5_5, 5);
//         if (D_80105664 >= 0) {
//             SleepProcess(-1);
//             SleepProcess(0x1E);
//         }
//         D_800D037C = 0;
//         if (D_800CD058.current_player_index >= 3) {
//             func_800EBAC8_FF6E8(-3, 7);
//             func_8001FDE8(GetPlayerStruct(3)->obj->unk3C->unk40->unk0);
//             D_800A12D4 = 0;
//             func_800F7108_10AD28();
//             LinkChildProcess(curProcess, func_800E0A14_F4634());
//             WaitForChildProcess();
//             if (D_800CD058.unk10 >= 0) {
//                 D_800D1240 = 0;
//                 temp_v1_14 = D_800CD058.total_turns;
//                 phi_v0_5 = 3;
//                 if ((s32) temp_v1_14 >= 0) {
//                     phi_v0_5 = 3;
//                     if (D_800CD058.current_turn >= temp_v1_14) {
//                         phi_v0_5 = 0x23;
//                         if (D_800CD0AA == 2) {
//                             phi_v0_5 = 3;
//                         }
//                     }
//                 }
//                 D_80105664 = phi_v0_5;
//                 D_80105666 = 1;
//                 D_800D1380 = 10;

//                 for (i = 0; i < 4; i++) {
//                     func_800F482C_10844C(i);
//                 }

//                 SleepProcess(-1);
//             }
//         }
//         if (func_800F933C_10CF5C() != 0) {
//             D_800D1240 = 0;
//             D_80105664 = 1;
//             SleepProcess(-1);
//         }
//         SleepProcess(4);
//         LinkChildProcess(curProcess, func_800F292C_10654C());
//         WaitForChildProcess();
//         func_800F92A0_10CEC0();

//         for (i = 0; i < 4; i++) {
//             func_800ECC28_100848(i);
//             func_800D9CE8_ED908(GetPlayerStruct(i)->obj, -1, 2);
//         }

//         SleepVProcess(temp_a0_7);

//         if ((D_800CD058.current_board_index == 0) && (func_80035F98(0x12) != 0)) {
//             func_800EBEC8_FFAE8();
//             func_8003602C(0x12);
//         }

//         func_800FF840_113460(0);
//         D_800D1240 = 1;
//     }
// }


INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF0F8_112D18);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF158_112D78);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF41C_11303C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF75C_11337C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF788_1133A8);

void func_800FF794_1133B4(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_80105668 = arg0;
    D_8010566C = arg1;
    D_80105664 = 8;
    D_800D1380 = arg2;
    D_80105666 = arg3;
}

void func_800FF7C4_1133E4(s32 arg1, s16 arg2, s16 arg3) {
    func_800FF794_1133B4(arg1, arg2, arg3, 0);
}

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF7F0_113410);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF800_113420);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF834_113454);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF840_113460);
