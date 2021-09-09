#include "common.h"
#include "../../player.h"
#include "../../process.h"

extern s16 D_800D1380;

extern void *D_80101A8C_E985C;
extern void *D_80101A90_E9860;
extern void *D_80101A94_E9864;
extern void *D_80101A98_E9868;

extern s16 D_80105494;
extern s16 D_80105496;

extern struct player *func_800F375C_DB52C(s32); // GetPlayerStructDuel

extern void func_800F5BB4_DD984(s32);
extern void func_800F5EB0_DDC80(s32);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FBF00_E3CD0);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FBFA4_E3D74);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC030_E3E00);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC108_E3ED8);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC114_E3EE4);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC120_E3EF0);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC18C_E3F5C);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC198_E3F68);

// Called to set up the board. (duel)
void func_800FC260_E4030(s32 bgIndex, s16 boardDefFile) {
    struct process *process;
    s32 *unkallocated;
    s32 i;

    func_800E8D10_D0AE0();
    func_800E4F50_CCD20(&bin_hvq_ROM_START);
    if (bgIndex >= 0) {
        func_800E52DC_CD0AC(bgIndex);
    }
    func_800E94D0_D12A0();
    if (boardDefFile >= 0) {
        func_800E9B10_D18E0(0x13, boardDefFile);
    }
    func_800D7EB8_BFC88();
    func_800F3F4C_DBD1C();
    func_800F3DFC_DBBCC(0);
    func_800F3DFC_DBBCC(1);

    for (i = 0; i < 2; i++) {
        func_800D8944_C0714(func_800F375C_DB52C(i)->obj);
        func_800F375C_DB52C(i)->obj->unkA |= 2;
        func_800D8E88_C0C58(func_800F375C_DB52C(i)->obj);
    }

    func_8001FDE8(*(func_800F375C_DB52C(0)->obj->unk3C->unk40));
    func_8001FDE8(*(func_800F375C_DB52C(1)->obj->unk3C->unk40));
    func_800F8C68_E0A38(0);
    func_800F8C68_E0A38(1);
    func_800F4300_DC0D0();
    func_800DF1B0_C6F80();
    func_800E0CEC_C8ABC();
    func_800E2870_CA640();
    func_800F6390_DE160();

    for (i = 0; i < 2; i++) {
        {
            s32 temp1 = gPlayers[i].game_guy_space_count;
            s32 temp2 = gPlayers[i].unk35;
            gPlayers[i].game_guy_space_count = 0;
            gPlayers[i].unk35 = 0;
            func_800F5BB4_DD984(i);
            func_800F5EB0_DDC80(i);
            gPlayers[i].game_guy_space_count = temp1;
            gPlayers[i].unk35 = temp2;
            func_800F5BB4_DD984(i);
            func_800F5EB0_DDC80(i);
        }
    }

    func_800DAB1C_C28EC();
    func_8005A6B0();
    func_800EB664_D3434();
    D_80105494 = -1;
    D_800D1380 = 0;
    D_80105496 = 0;
    func_800F4080_DBE50();
    D_80101A8C_E985C = NULL;
    D_80101A90_E9860 = NULL;
    D_80101A94_E9864 = NULL;
    D_80101A98_E9868 = NULL;

    for (i = 0; i < 2; i++) {
        process = InitProcess(func_800FC198_E3F68, 0, 0, 0x40);
        unkallocated = (s32 *)Malloc(process->heap, 16); // TODO: What type is this?
        process->user_data = unkallocated;
        *unkallocated = i;
        func_80047B80(process, 0xA0);
    }
}

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC4E4_E42B4);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC590_E4360);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC59C_E436C);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC5A8_E4378);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC5B4_E4384);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC5C0_E4390);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC5CC_E439C);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC5D8_E43A8);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC888_E4658);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC894_E4664);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC8A0_E4670);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC8C4_E4694);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC8D0_E46A0);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC8DC_E46AC);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC8E8_E46B8);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FC9FC_E47CC);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FCAB4_E4884);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FCC84_E4A54);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FCCCC_E4A9C);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FCD44_E4B14);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FCF50_E4D20);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FD298_E5068);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FD498_E5268);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FD4DC_E52AC);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FD55C_E532C);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FD5F0_E53C0);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FD620_E53F0);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FD6F4_E54C4);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FF420_E71F0);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FF480_E7250);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FF640_E7410);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FF944_E7714);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FF970_E7740);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FF97C_E774C);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FF9AC_E777C);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FF9D8_E77A8);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FF9E8_E77B8);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FFA1C_E77EC);

INCLUDE_ASM(s32, "overlays/overlay129/E3CD0", func_800FFA28_E77F8);
