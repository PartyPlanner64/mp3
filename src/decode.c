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

// Type 1 decompression.
INCLUDE_ASM(s32, "decode", DecodeLZ);
// void DecodeLZ(struct decode_struct *decode) {
//     u16 flag = 0;
//     u16 windowPos = 958;
//     s32 winTemp;
//     s32 i;
//     s32 byte1;
//     s32 byte2;
//     s32 copyPos;
//     s32 len;
//     s32 copyVal;
//     u8 temp;

//     bzero(&D_800AC3F0, 1024);

//     while (decode->len) {
//         flag = flag >> 1;
//         if ((flag & 0x100) == 0) {
//             if (decode->chunkLen >= 1024) {
//                 func_8004DA40(decode->src, &D_800ABFF0, 1024);
//                 decode->src += 1024;
//                 decode->chunkLen = 0;
//             }
//             byte1 = D_800ABFF0[decode->chunkLen++];

//             flag = 0xFF00 | (byte1 & 0xFF);
//         }
//         if ((flag & 0x1)) {
//             if (decode->chunkLen >= 1024) {
//                 func_8004DA40(decode->src, &D_800ABFF0, 1024);
//                 decode->src += 1024;
//                 decode->chunkLen = 0;
//             }
//             i = decode->chunkLen++;
//             i = D_800ABFF0[i];
//             byte1 = i;

//             len = windowPos++;
//             winTemp = len;
//             *(decode->dest++) = byte1;
//             D_800AC3F0[winTemp] = byte1;
//             windowPos &= 0x3FF;
//             decode->len--;
//         }
//         else {
//             if (decode->chunkLen >= 1024) {
//                 func_8004DA40(decode->src, &D_800ABFF0, 1024);
//                 decode->src += 1024;
//                 decode->chunkLen = 0;
//             }
//             byte1 = D_800ABFF0[decode->chunkLen++];

//             if (decode->chunkLen >= 1024) {
//                 func_8004DA40(decode->src, &D_800ABFF0, 1024);
//                 decode->src += 1024;
//                 decode->chunkLen = 0;
//             }
//             len = D_800ABFF0[decode->chunkLen++];

//             byte1 = byte1 | ((len & 0xC0) << 2);
//             len = 3 + (len & 0x3F);

//             for (i = 0; i < len; i++) {
//                 {
//                     winTemp = windowPos++;
//                     *(decode->dest++) = (copyVal = D_800AC3F0[(byte1 + i) & 0x3FF]);
//                     D_800AC3F0[winTemp] = copyVal;
//                     windowPos &= 0x3FF;
//                 }
//             }
//             decode->len -= i;
//         }
//     }
// }

// Type 2 decompression.
void func_8000A53C(struct decode_struct *decode) {
    s32 codeWordBitsRemaining;
    s32 curCodeWord;
    u8 *destOrig;

    // Advance past the first 4 bytes.
    if (decode->chunkLen >= 1024) {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;

    codeWordBitsRemaining = 0;
    curCodeWord = 0;
    destOrig = decode->dest;

    while (decode->len != 0) {
        // Read a new code word.
        if (codeWordBitsRemaining == 0) {
            {
                u32 chunkByte1, chunkByte2, chunkByte3, chunkByte4;

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte1 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte2 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte3 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte4 = D_800ABFF0[decode->chunkLen++];

                curCodeWord = (chunkByte1 << 24) + (chunkByte2 << 16) + (chunkByte3 << 8) + chunkByte4;
                codeWordBitsRemaining = 32;
            }
        }

        if (curCodeWord < 0) {
            {
                u32 nextByte;

                // Copy the next byte from the source to the destination.
                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                nextByte = D_800ABFF0[decode->chunkLen++];

                *(decode->dest++) = nextByte;
                decode->len--;
            }
        }
        else {
            {
                u32 back, back2, count;
                u8 *ptr;

                // Interpret the next two bytes as a distance to travel backwards and a
                // a length to read.
                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back2 = D_800ABFF0[decode->chunkLen++];

                back2 = (back << 8) + (back2 & 0xFFFFFFFFFFFFFFFF); // Unlikely, but matching.
                count = (back << 8) >> 12;
                back2 &= 0xFFF;
                ptr = decode->dest - back2;
                if (count == 0) {
                    if (decode->chunkLen >= 1024) {
                        func_8004DA40(decode->src, &D_800ABFF0, 1024);
                        decode->src += 1024;
                        decode->chunkLen = 0;
                    }

                    count = 0x12;
                    count += D_800ABFF0[decode->chunkLen++];
                }
                else {
                    count += 2;
                }
                decode->len -= count;

                while (count != 0) {
                    if (ptr - 1 < destOrig) {
                        *(decode->dest++) = 0;
                    }
                    else {
                        *(decode->dest++) = *(ptr - 1);
                    }
                    count--;
                    ptr++;
                }
            }
        }

        curCodeWord <<= 1;
        codeWordBitsRemaining--;
    }
}

// Type 3/4 decompression.
// Only difference from Type 2 is the handling for when the lookback
// looks prior to the destOrig pointer. Since this just doesn't handle that
// case, it's probably inferior to the Type 2 decoder.
void func_8000A9E8(struct decode_struct *decode) {
    s32 codeWordBitsRemaining;
    s32 curCodeWord;
    u8 *destOrig;

    // Advance past the first 4 bytes.
    if (decode->chunkLen >= 1024) {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024) {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;

    codeWordBitsRemaining = 0;
    curCodeWord = 0;

    destOrig = decode->dest;

    while (decode->len != 0) {
        // Read a new code word.
        if (codeWordBitsRemaining == 0) {
            {
                u32 chunkByte1, chunkByte2, chunkByte3, chunkByte4;

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte1 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte2 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte3 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte4 = D_800ABFF0[decode->chunkLen++];

                curCodeWord = (chunkByte1 << 24) + (chunkByte2 << 16) + (chunkByte3 << 8) + chunkByte4;
                codeWordBitsRemaining = 32;
            }
        }

        if (curCodeWord < 0) {
            {
                u32 nextByte;

                // Copy the next byte from the source to the destination.
                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                nextByte = D_800ABFF0[decode->chunkLen++];

                *(decode->dest++) = nextByte;
                decode->len--;
            }
        }
        else {
            {
                u32 back, back2, count;
                u8 *ptr;

                // Interpret the next two bytes as a distance to travel backwards and a
                // a length to read.
                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back2 = D_800ABFF0[decode->chunkLen++];

                back2 = (back << 8) + (back2 & 0xFFFFFFFFFFFFFFFF); // Unlikely, but matching.
                count = (back << 8) >> 12;
                back2 &= 0xFFF;
                ptr = decode->dest - back2;
                if (count == 0) {
                    if (decode->chunkLen >= 1024) {
                        func_8004DA40(decode->src, &D_800ABFF0, 1024);
                        decode->src += 1024;
                        decode->chunkLen = 0;
                    }

                    count = 0x12;
                    count += D_800ABFF0[decode->chunkLen++];
                }
                else {
                    count += 2;
                }
                decode->len -= count;

                while (count != 0) {
                    *(decode->dest++) = *(ptr - 1);
                    count--;
                    ptr++;
                }
            }
        }

        curCodeWord <<= 1;
        codeWordBitsRemaining--;
    }
}

// Type 5 decompression.
void func_8000AE64(struct decode_struct *decode) {
    s32 curCodeByte;
    s32 i;
    s32 byteValue;

    while (decode->len != 0) {
        if (decode->chunkLen >= 1024) {
            func_8004DA40(decode->src, &D_800ABFF0, 1024);
            decode->src += 1024;
            decode->chunkLen = 0;
        }

        curCodeByte = D_800ABFF0[decode->chunkLen++];
        if (curCodeByte < 0x80) {
            // No sign bit means we repeat the next byte n times.
            if (decode->chunkLen >= 1024) {
                func_8004DA40(decode->src, &D_800ABFF0, 1024);
                decode->src += 1024;
                decode->chunkLen = 0;
            }

            byteValue = D_800ABFF0[decode->chunkLen++];

            for (i = 0; i < curCodeByte; i++) {
                *(decode->dest++) = byteValue;
            }
        }
        else {
            // Having the sign bit means we read the next n bytes from the input.
            curCodeByte = curCodeByte - 0x80;

            for (i = 0; i < curCodeByte; i++) {
                if (decode->chunkLen >= 1024) {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }

                byteValue = D_800ABFF0[decode->chunkLen++];
                *(decode->dest++) = byteValue;
            }
        }

        decode->len -= curCodeByte;
    }
}

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
