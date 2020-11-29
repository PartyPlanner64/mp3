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

extern u8 D_800ABFF0[1024]; // src copy
extern u8 D_800AC3F0[1024]; // window

//INCLUDE_ASM(s32, "decode", func_8000A2CC);
u16 DecodeLZ(struct decode_struct *decode) {
    u32 flag = 0;
    s32 windowPos = 958;
    s32 winTemp;

    bzero(&D_800AC3F0, 1024);

    while (decode->len) {
        flag = flag >> 1;
        if ((flag & 0x100) == 0) {
            if (decode->chunkLen >= 1024) {
                func_8004DA40(decode->src, &D_800ABFF0, 1024);
                decode->src += 1024;
                decode->chunkLen = 0;
            }
            flag = 0xFF00 | D_800ABFF0[decode->chunkLen++];
        }
        if ((flag & 0x1)) {
            if (decode->chunkLen >= 1024) {
                func_8004DA40(decode->src, &D_800ABFF0, 1024);
                decode->src += 1024;
                decode->chunkLen = 0;
            }
            {
                u8 temp = D_800ABFF0[decode->chunkLen++];
                winTemp = windowPos++;
                *(decode->dest++) = temp;
                D_800AC3F0[winTemp] = temp;
                windowPos &= 0x3FF;
                decode->len--;
            }
        }
        else {
            {
                s32 byte1;
                s32 byte2;
                s32 copyPos;
                s32 len;
                s32 i;
                s32 copyVal;

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                byte1 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                byte2 = D_800ABFF0[decode->chunkLen++];

                copyPos = byte1 | ((byte2 & 0xC0) << 2);
                len = (byte2 & 0x3F) + 3;
                for (i = 0; i < len; i++) {
                    {
                        winTemp = windowPos++;
                        *(decode->dest++) = (copyVal = D_800AC3F0[(copyPos + i) & 0x3FF]);
                        D_800AC3F0[winTemp] = copyVal;
                        windowPos &= 0x3FF;
                    }
                }
                decode->len -= len;
            }
        }
    }
    return flag;
}

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
