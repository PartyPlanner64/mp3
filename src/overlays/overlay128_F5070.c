#include "common.h"
#include "../spaces.h"

extern void *data_128CC60_ROM_START; // hvq rom

extern s8 D_800CD069;

extern void *D_80101240; // pointer to hvq dir offsets
extern s32 D_80101248;

extern void *D_801012C0;
extern u32 D_801012C8[];
extern u32 D_80101318[];
extern void *D_80102C58[]; // function pointers given by board.

extern void *D_80102DB0; // hvq rom offset copied here
extern s32 D_80102DB4; // hvq directory count
extern void *D_80102DCC; // ? size 0x300

extern struct space_data *D_80105214;
extern struct chain_data *D_80105218;

extern void *D_80105220[];
extern s16 D_80105260;
extern s16 D_80105262;
extern f32 D_80105290[]; // arrow angles
extern s32 D_801052B0; // arrow angle count

extern void *D_80105500[];

extern s16 D_80105540[];

struct hvq_rom_initial {
    u32 dirCount;
    u32 dirOffsets[3];
};

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E1450_F5070);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E17B0_F53D0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E1828_F5448);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E18FC_F551C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E1934_F5554);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E1F28_F5B48);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E1F48_F5B68);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E1F70_F5B90);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2074_F5C94);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E20A4_F5CC4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E210C_F5D2C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E21F4_F5E14);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2260_F5E80);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E22B4_F5ED4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E22CC_F5EEC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E22DC_F5EFC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2354_F5F74);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2390_F5FB0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2904_F6524);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2954_F6574);

void func_800E2960_F6580(s32 arg0, void *arg1) {
    D_80102C58[arg0] = arg1;
}

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2974_F6594);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E29E8_F6608);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2B24_F6744);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2B4C_F676C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2BCC_F67EC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2C4C_F686C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2C74_F6894);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2C9C_F68BC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2CC4_F68E4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2CEC_F690C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2E28_F6A48);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E2F38_F6B58);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E3074_F6C94);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E3158_F6D78);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E31E4_F6E04);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E3284_F6EA4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E3394_F6FB4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E3420_F7040);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E3448_F7068);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E3470_F7090);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E3498_F70B8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E34BC_F70DC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E34E0_F7100);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E3584_F71A4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E35F8_F7218);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E3734_F7354);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E378C_F73AC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E3F54_F7B74);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E400C_F7C2C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4160_F7D80);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E41FC_F7E1C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E44E4_F8104);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E455C_F817C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E48F4_F8514);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4954_F8574);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4978_F8598);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E49DC_F85FC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4A08_F8628);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4A6C_F868C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4A7C_F869C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4A88_F86A8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4A94_F86B4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4B18_F8738);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4B60_F8780);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4BA0_F87C0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4C68_F8888);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E4DC0_F89E0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E5100_F8D20);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E53A4_F8FC4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E5604_F9224);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E57C8_F93E8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E57D8_F93F8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E5840_F9460);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E5B80_F97A0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E5B90_F97B0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E5BE4_F9804);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E5CE0_F9900);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E5D40_F9960);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E5DA8_F99C8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E5DD4_F99F4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E60D8_F9CF8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6120_F9D40);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E61C0_F9DE0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6264_F9E84);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E639C_F9FBC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E63F0_FA010);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6404_FA024);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6420_FA040);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E644C_FA06C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E648C_FA0AC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6500_FA120);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E650C_FA12C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6538_FA158);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6564_FA184);

// reads in hvq table info from ROM.
void func_800E6630_FA250(void *hvqRomOffset) {
    s32 dirsSize;
    s32 temp_v0;
    s32 *hvqDirs;
    struct hvq_rom_initial *hvqInitial;

    D_80102DB0 = hvqRomOffset;

    hvqInitial = MallocTemp(sizeof(struct hvq_rom_initial));
    func_8004DA40(hvqRomOffset, hvqInitial, sizeof(struct hvq_rom_initial));
    D_80102DB4 = hvqInitial->dirCount;
    FreeTemp(hvqInitial);

    dirsSize = D_80102DB4 * 4;
    hvqDirs = MallocTemp(dirsSize);
    D_80101240 = hvqDirs;
    func_8004DA40(hvqRomOffset + 4, hvqDirs, dirsSize);

    D_80102DCC = MallocTemp(0x300);
    D_80101248 = 0;
}

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E66D4_FA2F4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E66E0_FA300);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6720_FA340);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E69BC_FA5DC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E69D8_FA5F8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6A40_FA660);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6A54_FA674);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6A8C_FA6AC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6AC4_FA6E4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6C4C_FA86C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6C80_FA8A0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6CF8_FA918);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6DEC_FAA0C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6EC8_FAAE8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6FBC_FABDC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6FCC_FABEC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E6FDC_FABFC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E7018_FAC38);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E7068_FAC88);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E7130_FAD50);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E71A8_FADC8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E71EC_FAE0C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E7254_FAE74);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E728C_FAEAC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E72C4_FAEE4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E72DC_FAEFC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E7300_FAF20);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E7330_FAF50);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E7358_FAF78);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E7384_FAFA4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E7514_FB134);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E76EC_FB30C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E86CC_FC2EC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E8DC8_FC9E8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E8DD4_FC9F4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E8DE0_FCA00);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E8EDC_FCAFC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E8F54_FCB74);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9044_FCC64);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E90BC_FCCDC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E92D4_FCEF4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9328_FCF48);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9344_FCF64);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9358_FCF78);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9730_FD350);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E973C_FD35C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9748_FD368);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E982C_FD44C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E989C_FD4BC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E98E8_FD508);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9940_FD560);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9A54_FD674);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9A60_FD680);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9A94_FD6B4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9AC8_FD6E8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9AD4_FD6F4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9AE0_FD700);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9AF0_FD710);

void func_800E9BB0_FD7D0() {
    func_800E6630_FA250(&data_128CC60_ROM_START);
}

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9BD0_FD7F0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9C00_FD820);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9C28_FD848);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9C94_FD8B4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9EF4_FDB14);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800E9F24_FDB44);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA0B8_FDCD8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA200_FDE20);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA284_FDEA4);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA2BC_FDEDC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA2D0_FDEF0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA2E4_FDF04);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA320_FDF40);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA348_FDF68);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA358_FDF78);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA364_FDF84);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA4CC_FE0EC);

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

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EA6F4_FE314);

u16 *func_800EAE00_FEA20(u8 *arr, s32 index) {
    u16 offset = *((u16 *)(arr + index));
    return (u16 *)(arr + offset);
}

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EAE10_FEA30);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EB09C_FECBC);

struct space_data *GetSpaceData(s16 index) {
    return &D_80105214[index];
}

s16 GetAbsSpaceIndexFromChainSpaceIndex(u16 chain_index, u16 space_index) {
    return D_80105218[chain_index].space_indices[space_index];
}

s16 GetChainLength(u16 chain_index) {
    return D_80105218[chain_index].len;
}

s16 GetChainSpaceIndexFromAbsSpaceIndex(s16 abs_space_index, s32 chain_index) {
    s32 i;
    for (i = 0; i < GetChainLength(chain_index); i++) {
        if (GetAbsSpaceIndexFromChainSpaceIndex(chain_index, i) == abs_space_index) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EB24C_FEE6C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EB310_FEF30);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EB3C0_FEFE0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EB4F0_FF110);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EB5DC_FF1FC, s32 arg0, u8 arg1);

void SetSpaceType(s16 space_index, s32 space_type) {
    struct space_data *space;

    space = GetSpaceData(space_index);
    space->space_type = space_type;
}

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EB820_FF440);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EB8BC_FF4DC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EB97C_FF59C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EB9C0_FF5E0);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EBA60_FF680);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EBAC8_FF6E8);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EBCB0_FF8D0);

void SetCurrentSpaceIndex(s16 space_index) {
    D_800CD069 = space_index;
}

s16 GetCurrentSpaceIndex() {
    return D_800CD069;
}

s16 func_800EBCD4_FF8F4(s32 arg0) {
    return func_800EB5DC_FF1FC(2, arg0);
}

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EBCFC_FF91C);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EBD54_FF974);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EBDAC_FF9CC);

INCLUDE_ASM(s32, "overlays/overlay128_F5070", func_800EBEAC_FFACC);

void func_800EBEC8_FFAE8() {
    D_80105262 = 1;
}

void func_800EBED8_FFAF8() {
    D_80105262 = 0;
}
