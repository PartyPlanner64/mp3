#include "common.h"

struct decode_struct {
    u16 chunkLen;
    s16 pad;
    u8 *src;
    u8 *dest;
    u32 len;
};

void DecodeNone(struct decode_struct *decode) {
    s32 copyLen;

    while (decode->len) {
        if (decode->len < 1024) {
            copyLen = (decode->len + 1) & 0xFFFFFFFE;
            decode->len = 0;
        }
        else {
            copyLen = 1024;
            decode->len -= 1024;
        }
        func_8004DA40(decode->src, decode->dest, copyLen);
        decode->src += copyLen;
        decode->dest += copyLen;
    }
}

INCLUDE_ASM(s32, "decode", func_8000A2CC);

INCLUDE_ASM(s32, "decode", func_8000A53C);

INCLUDE_ASM(s32, "decode", func_8000A9E8);

INCLUDE_ASM(s32, "decode", func_8000AE64);

INCLUDE_ASM(s32, "decode", DecodeFile);
// Correct except for jump table data.
// void DecodeFile(void *src, void *dest, s32 len, s32 decodeType)
// {
//     struct decode_struct decodeStruct;
//     struct decode_struct *decodePtr = &decodeStruct;
//     decodeStruct.src = (u8 *)src;
//     decodeStruct.dest = (u8 *)dest;
//     decodeStruct.len = len;
//     decodeStruct.chunkLen = 1024;
//     switch (decodeType) {
//         case 0:
//             DecodeNone(decodePtr);
//             break;

//         case 1:
//             func_8000A2CC(decodePtr); // DecodeLZ
//             break;

//         case 2:
//             func_8000A53C(decodePtr);
//             break;

//         case 3:
//         case 4:
//             func_8000A9E8(decodePtr);
//             break;

//         case 5:
//             func_8000AE64(decodePtr);
//             break;

//         default:
//             break;
//     }
// }
