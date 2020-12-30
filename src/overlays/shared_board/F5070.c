#include "common.h"
#include "../../board.h"
#include "../../heap_temporary.h"
#include "../../process.h"
#include "../../spaces.h"

extern void *data_128CC60_ROM_START; // hvq rom

struct hvq_table_initial {
    u32 count;
    u32 offsets[3];
};

struct hvq_metadata {
    /* 0x00 */ s32 tileWidth;
    /* 0x04 */ s32 tileHeight;
    /* 0x08 */ s32 tileCountX;
    /* 0x0C */ s32 tileCountY;
    /* 0x10 */ f32 fov;
    /* 0x14 */ f32 scaleFactor;
    /* 0x18 */ f32 cameraEyePosX;
    /* 0x1C */ f32 cameraEyePosZ;
    /* 0x20 */ f32 cameraEyePosY;
    /* 0x24 */ f32 lookatPointX;
    /* 0x28 */ f32 lookatPointZ;
    /* 0x2C */ f32 lookatPointY;
    /* 0x30 */ f32 cameraUpVecX;
    /* 0x34 */ f32 cameraUpVecZ;
    /* 0x38 */ f32 cameraUpVecY;
}; // sizeof 0x3C / 60

extern s8 D_800CD069;
extern s16 D_800D41C2;

extern u32 *D_80101240; // pointer to hvq dir offsets (table)
extern u32 *D_80101244; // pointer to hvq file offsets (table)
extern struct hvq_metadata *D_80101248; // pointer to current hvq metadata
extern s32 D_80101254;
extern s32 D_80101258;

extern void *D_801012C0;
extern u8 *D_801012C4;
extern u32 D_801012C8[];
extern u32 D_80101318[];
extern s32 D_80102180;
extern s8 D_80102C48;
extern void *D_80102C58[]; // function pointers given by board.

extern void *D_80102DB0; // hvq rom offset copied here
extern s32 D_80102DB4; // hvq directory count
extern s32 D_80102DB8; // hvq current file table ROM offset
extern s16 D_80102DC0;
extern s16 D_80102DC2;
extern s16 D_80102DC4;
extern s16 D_80102DC6; // total width
extern s16 D_80102DC8; // total height
extern f32 D_80102DBC;
extern void *D_80102DCC; // ? size 0x300

struct str102DD8 {
    s8 unk0;
    s8 unk1;
    s16 unk2;
    void *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
}; // sizeof 0x14
extern struct str102DD8 D_80102DD8[];

extern u8 D_801030A8[];

extern void *D_80103138;
extern struct process *D_80103410;
extern f32 D_80103418;
extern struct coords_3d D_80103450;

extern OSMesgQueue D_80103468;
extern OSMesg D_80103480;

extern OSThread D_80103EC0;
extern OSThread D_80103510;

extern s32 D_80104070;

extern OSMesgQueue D_80104880;
extern OSMesg D_80104898;

extern OSMesgQueue D_80104928;
extern OSMesg D_80104940;

extern OSMesgQueue D_801049D0;
extern OSMesg D_801049E8;

extern u16 D_80105210; // space count
extern u16 D_80105212; // chain count
extern struct space_data *D_80105214;
extern struct chain_data *D_80105218;

extern void *D_80105220[];
extern s16 D_80105260;
extern s16 D_80105262;
extern s8 D_80105268[]; // counts of each space type
extern struct event_list_entry *D_80105278;
extern struct event_list_entry *D_8010527C;
extern struct event_list_entry *D_80105280;
extern struct event_list_entry *D_80105284;
extern s32 D_80105288;
extern f32 D_80105290[]; // arrow angles
extern s32 D_801052B0; // arrow angle count

extern void *D_80105500[];

extern s16 D_80105540[];
extern s32 D_80105990; // current hvq bg index

extern s16 GetCurrentSpaceIndex();

extern void func_800E86CC_FC2EC();
extern void func_800E8DD4_FC9F4(f32);
extern void func_800E9730_FD350(f32);
extern void func_800E9AC8_FD6E8(f32);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E1450_F5070);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E17B0_F53D0);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E1828_F5448);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E18FC_F551C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E1934_F5554);

void func_800E1F28_F5B48() {
    D_80102C48 = 0;
    func_800E1934_F5554();
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E1F48_F5B68);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E1F70_F5B90);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2074_F5C94);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E20A4_F5CC4);

struct unkf800E210C {
    s8 unk0;
    s8 unk1;
    s16 unk2;
    s32 unk4;
    s16 unk8;
    s32 unkC;
};

struct strtemp_v0_2 {
    s8 unks[0x5C];
    struct unkf800E210C *unk5C;
};

void *func_800E210C_F5D2C(s16 arg0, s16 arg1, s8 arg2) {
    s32 temp_v0_3;
    struct unkf800E210C *temp_v0;
    struct strtemp_v0_2 *temp_v0_2;

    temp_v0 = (struct unkf800E210C *)MallocTemp(sizeof(struct unkf800E210C));
    if (temp_v0 != NULL) {
        temp_v0->unk0 = (s8)arg0;
        temp_v0->unk2 = arg1;
        temp_v0->unk1 = arg2;
        temp_v0_2 = func_80047620(0x100, 0, 0, -1, func_800E20A4_F5CC4);
        temp_v0->unk4 = temp_v0_2;
        temp_v0_2->unk5C = temp_v0;
        func_80047B38(temp_v0->unk4, 0x80);
        temp_v0->unk8 = -1;
        if (arg0 == 6) {
            temp_v0_3 = MallocTemp(8);
            temp_v0->unkC = temp_v0_3;
            func_8007BDC0(temp_v0_3, &D_80102180, D_800D41C2);
            return temp_v0;
        }
        temp_v0->unkC = 0;
    }
    return temp_v0;
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E21F4_F5E14);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2260_F5E80);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E22B4_F5ED4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E22CC_F5EEC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E22DC_F5EFC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2354_F5F74);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2390_F5FB0);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2904_F6524);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2954_F6574);

void func_800E2960_F6580(s32 arg0, void *arg1) {
    D_80102C58[arg0] = arg1;
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2974_F6594);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E29E8_F6608);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2B24_F6744);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2B4C_F676C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2BCC_F67EC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2C4C_F686C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2C74_F6894);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2C9C_F68BC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2CC4_F68E4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2CEC_F690C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2E28_F6A48);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E2F38_F6B58);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E3074_F6C94);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E3158_F6D78);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E31E4_F6E04);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E3284_F6EA4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E3394_F6FB4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E3420_F7040);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E3448_F7068);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E3470_F7090);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E3498_F70B8);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E34BC_F70DC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E34E0_F7100);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E3584_F71A4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E35F8_F7218);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E3734_F7354);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E378C_F73AC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E3F54_F7B74);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E400C_F7C2C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4160_F7D80);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E41FC_F7E1C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E44E4_F8104);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E455C_F817C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E48F4_F8514);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4954_F8574);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4978_F8598);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E49DC_F85FC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4A08_F8628);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4A6C_F868C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4A7C_F869C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4A88_F86A8);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4A94_F86B4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4B18_F8738);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4B60_F8780);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4BA0_F87C0);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4C68_F8888);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E4DC0_F89E0);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E5100_F8D20);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E53A4_F8FC4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E5604_F9224);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E57C8_F93E8);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E57D8_F93F8);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E5840_F9460);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E5B80_F97A0);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E5B90_F97B0);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E5BE4_F9804);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E5CE0_F9900);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E5D40_F9960);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E5DA8_F99C8);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E5DD4_F99F4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E60D8_F9CF8);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6120_F9D40);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E61C0_F9DE0);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6264_F9E84);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E639C_F9FBC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E63F0_FA010);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6404_FA024);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6420_FA040);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E644C_FA06C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E648C_FA0AC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6500_FA120);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E650C_FA12C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6538_FA158);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6564_FA184);

// reads in hvq table info from ROM.
void func_800E6630_FA250(void *hvqRomOffset) {
    s32 dirsSize;
    s32 temp_v0;
    s32 *hvqDirs;
    struct hvq_table_initial *hvqInitial;

    D_80102DB0 = hvqRomOffset;

    hvqInitial = MallocTemp(sizeof(struct hvq_table_initial));
    func_8004DA40(hvqRomOffset, hvqInitial, sizeof(struct hvq_table_initial));
    D_80102DB4 = hvqInitial->count;
    FreeTemp(hvqInitial);

    dirsSize = D_80102DB4 * 4;
    hvqDirs = MallocTemp(dirsSize);
    D_80101240 = hvqDirs;
    func_8004DA40(hvqRomOffset + 4, hvqDirs, dirsSize);

    D_80102DCC = MallocTemp(0x300);
    D_80101248 = NULL;
}

void func_800E66D4_FA2F4() {
    D_80101248 = NULL;
}

void func_800E66E0_FA300() {
    if (D_80101240 != NULL) {
        FreeTemp(D_80101240);
        D_80101240 = NULL;
        FreeTemp(D_80102DCC);
    }
}

// Called to show one of the HVQ backgrounds by index.
INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6720_FA340);
// FIXME: mostly regalloc left.
// void func_800E6720_FA340(s32 bgIndex, s32 arg1) {
//     s32 fileTableSize;
//     s32 fileCount;
//     struct hvq_table_initial *hvqInitial;

//     D_80105990 = bgIndex;
//     D_80102DB8 = D_80102DB0 + D_80101240[bgIndex];
//     hvqInitial = (struct hvq_table_initial *)MallocTemp(sizeof(struct hvq_table_initial));
//     func_8004DA40(D_80102DB8, hvqInitial, sizeof(struct hvq_table_initial));
//     fileCount = hvqInitial->count;
//     FreeTemp(hvqInitial);
//     fileTableSize = (fileCount + 1) * 4;
//     D_80101244 = (u32 *)MallocTemp(fileTableSize);
//     func_8004DA40(D_80102DB8 + 4, D_80101244, fileTableSize);
//     D_80101248 = (struct hvq_metadata *)MallocTemp(sizeof(struct hvq_metadata));
//     func_8004DA40(D_80102DB8 + D_80101244[0], D_80101248, sizeof(struct hvq_metadata));
//     D_80103450.x = D_80101248->cameraEyePosX;
//     D_80103450.y = D_80101248->cameraEyePosZ;
//     D_80103450.z = D_80101248->cameraEyePosY;
//     D_80101248->cameraEyePosX *= 5.0f;
//     D_80101248->cameraEyePosZ *= 5.0f;
//     D_80101248->cameraEyePosY *= 5.0f;
//     D_80101248->lookatPointX *= 5.0f;
//     D_80101248->lookatPointZ *= 5.0f;
//     D_80101248->lookatPointY *= 5.0f;
//     D_80103138 = MallocTemp(func_800E7330_FAF50(0));
//     func_8004DA40(D_80102DB8 + D_80101244[1], D_80103138, func_800E7330_FAF50(0));
//     D_80102DC4 = 0;
//     D_80102DC2 = 0;
//     D_80102DC6 = (D_80101248->tileWidth * D_80101248->tileCountX) / 2; // not confirmed
//     D_80102DC8 = (D_80101248->tileHeight * D_80101248->tileCountY) / 2;
//     D_80102DC0 = 1;
//     func_8001F95C(0, func_800E86CC_FC2EC);
//     func_800E7254_FAE74();
//     func_800E6FBC_FABDC();
//     if (arg1 != 0) {
//         func_800E90BC_FCCDC();
//     }
//     func_800E9730_FD350(1.0f);
//     func_800E9A54_FD674(0xFF);
//     func_800E9AC8_FD6E8(-1.0f);
//     D_80101254 = 0;
//     D_80101258 = 0;
//     func_800E8DD4_FC9F4(1.0f);
// }

void func_800E69BC_FA5DC(s32 bgIndex) {
    func_800E6720_FA340(bgIndex, 1);
}

void func_800E69D8_FA5F8() {
    if (D_80101244 != NULL) {
        FreeTemp(D_80101244);
        D_80101244 = NULL;
        FreeTemp(D_80101248);
        FreeTemp(D_80103138);
        func_8001F95C(0, 0);
        func_800E728C_FAEAC();
        func_800E9328_FCF48();
    }
}

void func_800E6A40_FA660(s16 arg0, s16 arg1) {
    D_80102DC2 = arg0;
    D_80102DC4 = arg1;
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6A54_FA674);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6A8C_FA6AC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6AC4_FA6E4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6C4C_FA86C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6C80_FA8A0);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6CF8_FA918);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6DEC_FAA0C);

void func_800E6EC8_FAAE8() {
    osCreateMesgQueue(&D_80103468, &D_80103480, 0x24);
    osCreateMesgQueue(&D_80104880, &D_80104898, 0x24);
    osCreateMesgQueue(&D_80104928, &D_80104940, 0x24);
    osCreateMesgQueue(&D_801049D0, &D_801049E8, 2);
    D_80104070 = 1;
    func_8007C810(&D_80103EC0, 0x64, func_800E6DEC_FAA0C, 0, &D_80104880, 1);
    osStartThread(&D_80103EC0);
    func_8007C810(&D_80103510, 0x65, func_800E6C80_FA8A0, 0, &D_80103EC0, 4);
    osStartThread(&D_80103510);
}

void func_800E6FBC_FABDC() {
    D_80104070 = 3;
}

void func_800E6FCC_FABEC() {
    D_80104070 = 1;
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E6FDC_FABFC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E7018_FAC38);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E7068_FAC88);

void func_800E7130_FAD50() {
    struct str102DD8 *cur;
    s32 i;

    cur = &D_80102DD8[0];
    for (i = 0; i < 36; i++) {
        cur->unk0 = 0;
        cur->unk1 = 0;
        cur->unk2 = -1;
        cur->unk4 = func_800199F8(0x1800);
        cur->unk8 = 0;
        cur++;
    }
    bzero(&D_801030A8, 0x90);
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E71A8_FADC8);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E71EC_FAE0C);

void func_800E7254_FAE74() {
    func_800E7130_FAD50();
    func_800E6EC8_FAAE8();
    D_80102DC0 |= 4;
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E728C_FAEAC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E72C4_FAEE4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E72DC_FAEFC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E7300_FAF20);

// Get size of hvq tile file by index.
u32 func_800E7330_FAF50(u16 arg0) {
    arg0++;
    return D_80101244[arg0 + 1] - D_80101244[arg0];
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E7358_FAF78);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E7384_FAFA4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E7514_FB134);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E76EC_FB30C);

INCLUDE_ASM(void, "overlays/shared_board/F5070", func_800E86CC_FC2EC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E8DC8_FC9E8);

INCLUDE_ASM(void, "overlays/shared_board/F5070", func_800E8DD4_FC9F4, f32 arg1);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E8DE0_FCA00);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E8EDC_FCAFC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E8F54_FCB74);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9044_FCC64);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E90BC_FCCDC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E92D4_FCEF4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9328_FCF48);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9344_FCF64);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9358_FCF78);

void func_800E9730_FD350(f32 arg0) {
    D_80103418 = arg0;
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E973C_FD35C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9748_FD368);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E982C_FD44C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E989C_FD4BC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E98E8_FD508);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9940_FD560);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9A54_FD674);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9A60_FD680);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9A94_FD6B4);

void func_800E9AC8_FD6E8(f32 arg0) {
    D_80102DBC = arg0;
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9AD4_FD6F4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9AE0_FD700);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9AF0_FD710);

void func_800E9BB0_FD7D0() {
    func_800E6630_FA250(&data_128CC60_ROM_START);
}

void func_800E9BD0_FD7F0(s32 bgIndex) {
    func_800E6720_FA340(bgIndex, 1);
    EndProcess(D_80103410);
    D_80103410 = NULL;
}

void func_800E9C00_FD820(s16 arg0, s16 arg1) {
    func_800E6A40_FA660(arg0, arg1);
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9C28_FD848);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9C94_FD8B4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9EF4_FDB14);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800E9F24_FDB44);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA0B8_FDCD8);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA200_FDE20);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA284_FDEA4);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA2BC_FDEDC);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA2D0_FDEF0);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA2E4_FDF04);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA320_FDF40);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA348_FDF68);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA358_FDF78);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA364_FDF84);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA4CC_FE0EC);

// File break?

s32 func_800EA4F0_FE110(s16 param_1) {
    s32 i;
    u32 *ptr;

    D_80105260 = param_1;

    switch (param_1) {
        case 0:
        default:
            ptr = D_801012C8;
            break;

        case 1:
            ptr = D_80101318;
            break;
    }

    for (i = 0; i < 16; i++) {
        if (ptr[i] != 0) {
            D_80105220[i] = ReadMainFS(ptr[i]);
        }
        else {
            D_80105220[i] = NULL;
        }
    }
}

void func_800EA5A4_FE1C4() {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_80105220[i] != NULL) {
            FreeMainFS(D_80105220[i]);
        }
        D_80105220[i] = NULL;
    }
}

void func_800EA60C_FE22C() {
    s32 i;

    func_800EA4F0_FE110(0);
    D_801012C0 = 0;
    D_801052B0 = 0;

    for (i = 0; i < 16; i++) {
        D_80105500[i] = NULL;
    }
}

// Set arrow angle
void func_800EA660_FE280(f32 angle) {
    if (D_801052B0 != 8) {
        D_80105290[D_801052B0++] = angle;
    }
}

void func_800EA694_FE2B4() {
    func_800EA5A4_FE1C4();
}

void func_800EA6B0_FE2D0(s16 arg0) {
    func_800EA5A4_FE1C4();
    func_800EA4F0_FE110(arg0);
}

void func_800EA6E0_FE300(s32 arg0, s16 arg1) {
    D_80105540[arg0] = arg1;
}

// Draws spaces
INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EA6F4_FE314);

u16 *func_800EAE00_FEA20(u8 *arr, s32 index) {
    u16 offset = *((u16 *)(arr + index));
    return (u16 *)(arr + offset);
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EAE10_FEA30);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EB09C_FECBC);

struct space_data *GetSpaceData(s16 index) {
    return &D_80105214[index];
}

s16 GetAbsSpaceIndexFromChainSpaceIndex(u16 chain_index, u16 space_index) {
    return D_80105218[chain_index].space_indices[space_index];
}

s16 GetChainLength(u16 chain_index) {
    return D_80105218[chain_index].len;
}

s16 GetChainSpaceIndexFromAbsSpaceIndex(s16 abs_space_index, s16 chain_index) {
    s32 i;
    for (i = 0; i < GetChainLength(chain_index); i++) {
        if (GetAbsSpaceIndexFromChainSpaceIndex(chain_index, i) == abs_space_index) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EB24C_FEE6C);

s32 func_800EB310_FEF30(s16 absSpaceIndex, s8 *arg1, s8 *arg2) {
    s16 chainSpaceIndex;
    s32 i;

    for (i = 0; i < D_80105212; i++) {
        if (*arg1 != i) {
            chainSpaceIndex = GetChainSpaceIndexFromAbsSpaceIndex(absSpaceIndex, i);
            if (chainSpaceIndex != -1) {
                *arg1 = (s8)i;
                *arg2 = (s8)chainSpaceIndex;
                return 0;
            }
        }
    }
    return -1;
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EB3C0_FEFE0);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EB4F0_FF110);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EB5DC_FF1FC, s32 arg0, u8 arg1);

void SetSpaceType(s16 space_index, s32 space_type) {
    struct space_data *space;

    space = GetSpaceData(space_index);
    space->space_type = space_type;
}

// Change spaces of old type to new type on a given chain.
void func_800EB820_FF440(u16 chain_index, u16 old_type, u8 new_type) {
    s32 chain_len;
    s16 absidx;
    struct space_data *space;
    s32 i;

    i = 0;
    chain_len = GetChainLength(chain_index);
    for (i = 0; i < chain_len; i++) {
        absidx = GetAbsSpaceIndexFromChainSpaceIndex(chain_index, i);
        space = GetSpaceData(absidx);
        if (space->space_type == old_type) {
            space->space_type = new_type;
        }
    }
}

void func_800EB8BC_FF4DC() {
    struct process *process;
    struct space_data *space;
    f32 fval;
    f32 fOrig;

    process = GetCurrentProcess();
    space = GetSpaceData((s16)process->user_data);

    fOrig = space->sx;
    fval = fOrig + 0.03f;
    if (D_801012C0 != NULL) {
        do {
            SleepVProcess();
            fval -= 0.005f;
            if (fval <= fOrig) {
                fval = fOrig;
            }

            space->sx = fval;
            space->sz = fval;
        }
        while (!(fval <= fOrig) && D_801012C0 != NULL);
    }

    EndProcess(NULL);
}

void func_800EB97C_FF59C(s16 space_index) {
    struct process *process;
    process = InitProcess(func_800EB8BC_FF4DC, 0xEF00, 0, 0);
    process->user_data = (void *)space_index;
}

void func_800EB9C0_FF5E0(s16 space_index, struct event_list_entry *event_list) {
    switch (space_index) {
        case -2:
            D_80105278 = event_list;
            return;

        case -3:
            D_8010527C = event_list;
            return;

        case -4:
            D_80105280 = event_list;
            return;

        case -5:
            D_80105284 = event_list;
            return;
    }

    {
        struct space_data *space;
        space = GetSpaceData(space_index);
        space->event_list = event_list;
    }
}

// EventTableHydrate
void func_800EBA60_FF680(struct event_table_entry *table) {
    while (table->space_index != -1) {
        func_800EB9C0_FF5E0(table->space_index, table->event_list);
        table++;
    }
}

// ExecuteEventForSpace
s32 func_800EBAC8_FF6E8(s16 space_index, s16 activation_type) {
    struct event_list_entry *event_list;
    s16 cur_space_index;
    s32 ret;

    if (((D_800CD058.current_player_index == 4) & (activation_type != 1)) != 0) {
        return 0;
    }

    switch (space_index) {
        case -2:
            event_list = D_80105278;
            break;

        case -3:
            event_list = D_8010527C;
            break;

        case -4:
            event_list = D_80105280;
            break;

        case -5:
            event_list = D_80105284;
            break;

        default:
            event_list = GetSpaceData(space_index)->event_list;
            break;
    }

    ret = 0;
    cur_space_index = GetCurrentSpaceIndex();
    SetCurrentSpaceIndex(space_index);

    if (event_list != NULL) {
        while (event_list->activation_type != 0) {
            if (event_list->activation_type == activation_type) {
                D_80105288 = 0;

                switch (event_list->execution_type) {
                    case 1:
                        event_list->event_fn();
                        break;

                    case 2:
                        {
                            struct process *cur_process = GetCurrentProcess();
                            struct process *space_process = InitProcess(event_list->event_fn, 0x4800, 0, 0);
                            LinkChildProcess(cur_process, space_process);
                            WaitForChildProcess();
                        }
                        break;
                }

                ret = ret | D_80105288;
            }
            event_list++;
        }
    }

    SetCurrentSpaceIndex(cur_space_index);
    return ret;
}

void func_800EBCB0_FF8D0(s32 unk) {
    D_80105288 = unk;
}

void SetCurrentSpaceIndex(s16 space_index) {
    D_800CD069 = space_index;
}

s16 GetCurrentSpaceIndex() {
    return D_800CD069;
}

s16 func_800EBCD4_FF8F4(s32 arg0) {
    return func_800EB5DC_FF1FC(2, arg0);
}

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EBCFC_FF91C);

INCLUDE_ASM(s32, "overlays/shared_board/F5070", func_800EBD54_FF974);

// Refreshes cached space type data, prompting redraw of spaces.
void func_800EBDAC_FF9CC() {
    s32 stype;
    s32 i;
    s32 spaceCountOfType;

    if (D_801012C4 != NULL) {
        FreeTemp(D_801012C4);
    }
    D_801012C4 = MallocTemp(128 * 16);

    for (stype = 0; stype < 16; stype++) {
        spaceCountOfType = 0;
        for (i = 0; i < D_80105210; i++) {
            if (GetSpaceData(i)->space_type == stype) {
                *(D_801012C4 + (stype * 128) + spaceCountOfType) = i;
                spaceCountOfType++;
            }
        }
        *(D_801012C4 + (stype * 128) + spaceCountOfType) = 0xFF;
        D_80105268[stype] = spaceCountOfType;
    }
}

// Reads space index from the cached space type data.
u8 func_800EBEAC_FFACC(s32 spaceType, s32 index) {
    return *(D_801012C4 + (spaceType * 128) + index);
}

void func_800EBEC8_FFAE8() {
    D_80105262 = 1;
}

void func_800EBED8_FFAF8() {
    D_80105262 = 0;
}
