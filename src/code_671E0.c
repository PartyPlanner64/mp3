#include "common.h"

// HVQ decoder library.

INCLUDE_ASM(s32, "code_671E0", func_800665E0);

INCLUDE_ASM(s32, "code_671E0", func_80066894);

INCLUDE_ASM(s32, "code_671E0", func_80066A44);

INCLUDE_ASM(s32, "code_671E0", func_800677B8);

INCLUDE_ASM(s32, "code_671E0", func_80067D50);

INCLUDE_ASM(s32, "code_671E0", func_80068ECC);

INCLUDE_ASM(s32, "code_671E0", func_800694D0);

// Decodes an HVQS
INCLUDE_ASM(void, "code_671E0", func_800698E8, void *hvqsData, s32 arg1, s32 arg2, void *arg3);

// const char *HVQMPS_MAGIC = "HVQ-MPS 1.1";
// const char *HVQMPS_ERR = "Error : This file is not HVQ-MPS 1.1";

// Decodes the HVQ-MPS 1.1 (first file in the tile set)
INCLUDE_ASM(void, "code_671E0", func_80069E68, void *hvqMps);

INCLUDE_ASM(void, "code_671E0", func_8006A370, s32 arg0); // or s8?
