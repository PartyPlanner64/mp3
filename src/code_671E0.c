#include "common.h"

// HVQ decoder library.

extern const char *D_800A7F50;
// const char *HVQMPS_MAGIC = "HVQ-MPS 1.1";
extern const char *D_800A7F5C;
// const char *HVQMPS_ERR = "Error : This file is not HVQ-MPS 1.1";

extern s32 D_800BE090;
extern s32 D_800BE098;

extern void *D_800BE094; // fn

extern void *D_800BE0A0;

extern void *D_800BE8B0;

extern void *D_800BF0C0;

extern s16 *D_800BF8D0;

extern s16 D_800C00D2;
extern s16 D_800C00D4;
extern u32 D_800C00D8;
extern u32 D_800C00DC;
extern u32 *D_800C00E0;

extern void *D_800C0160;

extern void *D_800C0BC4;
extern s32 D_800C0BC8;
extern s32 D_800C0BCC;
extern s32 D_800C0BD0;
extern s8 D_800C0BD4; // hvq mps unk1B

extern s16 D_800C1478; // hvq mps unk14
extern s16 D_800C147A; // hvq mps unk16
extern s16 D_800C1480;
extern s16 D_800C1482;
extern s16 D_800C1484;
extern s16 D_800C1486;
extern s16 D_800C1488;
extern s16 D_800C148A;
extern s8 D_800C148C; // hvq mps unk18
extern s8 D_800C148D; // hvq mps unk19

extern s32 D_800C1558;
extern s32 D_800C155C;

struct hvq_mps {
    s8 magic[16]; // "HVQ-MPS 1.1" with zero padding
    s32 len;
    s16 unk14;
    s16 unk16;
    s8 unk18;
    s8 unk19;
    s8 unk1A;
    s8 unk1B;

    // offsets from start of struct
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
};

INCLUDE_ASM(s32, "code_671E0", func_800665E0);

INCLUDE_ASM(s32, "code_671E0", func_80066894);

INCLUDE_ASM(s32, "code_671E0", func_80066A44);

INCLUDE_ASM(s32, "code_671E0", func_800677B8);

INCLUDE_ASM(s32, "code_671E0", func_80067D50);

INCLUDE_ASM(s32, "code_671E0", func_80068ECC);

INCLUDE_ASM(s32, "code_671E0", func_800694D0);

// Decodes an HVQS
INCLUDE_ASM(void, "code_671E0", func_800698E8, void *hvqsData, s32 arg1, s32 arg2, void *arg3);

// Decodes the HVQ-MPS 1.1 (first file in the tile set)
INCLUDE_ASM(void, "code_671E0", func_80069E68, struct hvq_mps *hvqMps);
// FIXME: Mediocre attempt. Might be -O2?
// void func_80069E68(struct hvq_mps *hvqMps) {
//     s16 temp_v0;
//     s32 temp_lo;
//     s32 temp_lo_2;
//     s8 temp_t1;
//     s16 *temp_a1;
//     u16 temp_v1;
//     u8 unk18temp;
//     u8 unk19temp;
//     u8 unk1Atemp;
//     u32 unk1Atemp2;
//     s32 unk1Atemp3;
//     void *temp_v1_3;
//     void *temp_v1_4;
//     void *temp_v1_5;
//     void *temp_v1_6;
//     s8 phi_t1;
//     s16 phi_a0;
//     void *phi_t0;
//     s8 *co160temp;
//     s32 phi_a3_2;
//     s8 ibyte;

//     if (func_80087B20(hvqMps, &D_800A7F50) != 0) {
//         osSyncPrintf_func_8007BE80(&D_800A7F5C);
//         return;
//     }

//     D_800C1478 = hvqMps->unk14;
//     D_800C147A = hvqMps->unk16;
//     unk18temp = hvqMps->unk18;
//     temp_lo = (D_800C1478 / 4) / unk18temp;
//     D_800C148C = unk18temp;
//     unk19temp = hvqMps->unk19;
//     temp_lo_2 = (D_800C147A / 4) / unk19temp;
//     D_800C1480 = (D_800C1478 / 4);
//     D_800C1482 = (D_800C147A / 4);
//     D_800C148D = unk19temp;
//     D_800C1484 = (D_800C1478 / 4) * (D_800C147A / 4);
//     D_800C1486 = temp_lo;
//     D_800C1488 = temp_lo_2;
//     D_800C148A = (temp_lo * temp_lo_2);

//     if (unk19temp == 1) {
//         D_800BE090 = 0;
//         D_800BE094 = func_800677B8;
//     }
//     else {
//         D_800BE090 = 1;
//         D_800BE094 = func_80067D50;
//     }

//     D_800C0BD4 = hvqMps->unk1B;
//     if (hvqMps->unk1B == 0) {
//         D_800C0BC8 = 0x46;
//         D_800C0BCC = 0x26;
//     } else {
//         D_800C0BC8 = 0x26;
//         D_800C0BCC = 0x46;
//     }

//     {
//         s8 *temp_v1_3 = (s8 *)hvqMps + hvqMps->unk1C;
//         D_800C0BD0 = D_800C0BC8 * 2;
//         if (*((s32 *)temp_v1_3) != 0) {
//             D_800C00E0 = (u32 *) (temp_v1_3 + 4);
//             D_800C00D8 = 0;
//             if (D_800BE8B0 != NULL) {
//                 D_800BE098 = 0x100;
//                 D_800BE8B0 = func_800665E0(&D_800C00D8, &D_800BE8B0);
//             }
//         }
//         else {
//             D_800C00E0 = NULL;
//             D_800C00D8 = 0;
//         }
//     }

//     {
//         s8 *temp_v1_4 = (s8 *)hvqMps + hvqMps->unk20;
//         if (*((s32 *)temp_v1_4) != 0) {
//             D_800C00E0 = (u32 *) (temp_v1_4 + 4);
//             D_800C00D8 = 0;
//             if (D_800BE0A0 != NULL) {
//                 D_800BE098 = 0x100;
//                 D_800BE0A0 = func_800665E0(&D_800C00D8, &D_800BE0A0);
//             }
//         }
//         else {
//             D_800C00E0 = NULL;
//             D_800C00D8 = 0;
//         }
//     }

//     {
//         s8 *temp_v1_5 = (s8 *)hvqMps + hvqMps->unk24;
//         if (*((s32 *)temp_v1_5) != 0) {
//             D_800C00E0 = (u32 *) (temp_v1_5 + 4);
//             D_800C00D8 = 0;
//             if (D_800BF0C0 != 0) {
//                 D_800BE098 = 0x100;
//                 D_800BF0C0 = func_800665E0(&D_800C00D8, &D_800BF0C0);
//             }
//         } else {
//             D_800C00E0 = NULL;
//             D_800C00D8 = 0;
//         }
//     }

//     {
//         s8 *temp_v1_6 = (s8 *)hvqMps + hvqMps->unk28;
//         if (*((s32 *)temp_v1_6) != 0) {
//             D_800C00E0 = (u32 *) (temp_v1_6 + 4);
//             D_800C00D8 = 0;
//             if (D_800BF8D0 != 0) {
//                 D_800BE098 = 0x100;
//                 D_800BF8D0 = func_800665E0(&D_800C00D8, &D_800BF8D0);
//             }
//         }
//         else {
//             D_800C00E0 = NULL;
//             D_800C00D8 = 0;
//         }
//     }

//     unk1Atemp = hvqMps->unk1A;
//     unk1Atemp2 = unk1Atemp >> 4;

//     {
//         s16 *phi_a1;
//         s16 *phi_a2;
//         s16 *phi_a3;
//         s16 *phi_t0;

//         ibyte = 0;
//         phi_a1 = ((s8 *)&D_800BF0C0) + 2;
//         phi_a2 = ((s8 *)&D_800BE0A0) + 2;
//         phi_a3 = ((s8 *)&D_800BF8D0) + 2;
//         phi_t0 = ((s8 *)&D_800BE8B0) + 2;

//         while (ibyte < 0x100) {
//             *phi_a1 = ((s32)(ibyte << 0x18) >> 0x16);
//             *phi_a2 = (ibyte << unk1Atemp2);
//             *phi_a3 = (ibyte * 16);
//             *phi_t0 = ibyte;

//             ibyte++;
//             phi_a1++;
//             phi_a2++;
//             phi_a3++;
//             phi_t0++;
//         }
//     }

//     D_800C00D2 = (0x7F << unk1Atemp2);
//     unk1Atemp3 = 0xC - (unk1Atemp & 0xF);
//     D_800C1558 = unk1Atemp3;
//     D_800C00D4 = (-0x80 << unk1Atemp2);
//     D_800C155C = (1 << (unk1Atemp3 - 1));
//     D_800C0BC4 = &D_800C0160;

//     ibyte = 0;
//     co160temp = (s8 *)&D_800C0160;

//     for (phi_a3_2 = 0xA64; phi_a3_2 > 0; phi_a3_2--) {
//         temp_a1 = (s16 *)&D_800BF8D0;
//         while (*temp_a1 >= 0x100) {
//             if (D_800C00D8 == 0) {
//                 D_800C00D8 = 0x80000000;
//                 D_800C00DC = *D_800C00E0++;
//             }
//             D_800C00D8 >>= 1;
//             if ((D_800C00DC & D_800C00D8) != 0) {
//                 temp_a1 = (s16 *)&D_800BF8D0 + *temp_a1 + 201;
//             }
//             else {
//                 temp_a1 = (s16 *)&D_800BF8D0 + *temp_a1 + 2;
//             }
//         }

//         temp_v0 = (s16 *)&D_800BF8D0 + *temp_a1 + 2;
//         temp_t1 = ibyte + temp_v0;
//         *co160temp = temp_t1;
//         ibyte = temp_t1;
//         co160temp = co160temp + 1;
//     }
// }

INCLUDE_ASM(void, "code_671E0", func_8006A370, s32 arg0); // or s8?
