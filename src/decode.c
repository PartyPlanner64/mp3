#include "common.h"

struct decode_struct
{
    u16 chunkLen;
    s16 pad;
    u8 *src;
    u8 *dest;
    u32 len;
};

typedef enum
{
    DECODE_NONE = 0,
    DECODE_LZ,       // lzss
    DECODE_SLIDE,    // yaz0/szs
    DECODE_FSLIDE,   // yaz0/szs, no loopback
    DECODE_FSLIDE_2, // yaz0/szs, no loopback
    DECODE_RLE       // custom rle variant
} EDecodeType;

extern u8 D_800ABFF0[1024]; // src copy
extern u8 D_800AC3F0[1024]; // window

void HuDecodeNone(struct decode_struct *decode)
{
    s32 copyLen;

    while (decode->len)
    {
        if (decode->len < 1024)
        {
            copyLen = (decode->len + 1) & 0xFFFFFFFE;
            decode->len = 0;
        }
        else
        {
            copyLen = 1024;
            decode->len -= 1024;
        }
        func_8004DA40(decode->src, decode->dest, copyLen);
        decode->src += copyLen;
        decode->dest += copyLen;
    }
}

// Type 1 decompression.
void HuDecodeLZ(struct decode_struct *decode)
{
    u16 flag = 0;
    u16 windowPos = 958;
    s32 winTemp;
    s32 i;
    s32 byte1;
    s32 byte2;
    s32 copyPos;
    s32 len;
    s32 copyVal;
    u8 temp;

    bzero(&D_800AC3F0, 1024);

    while (decode->len)
    {
        flag = flag >> 1;
        if ((flag & 0x100) == 0)
        {
            if (decode->chunkLen >= 1024)
            {
                func_8004DA40(decode->src, &D_800ABFF0, 1024);
                decode->src += 1024;
                decode->chunkLen = 0;
            }
            byte1 = D_800ABFF0[decode->chunkLen++];

            flag = 0xFF00 | (byte1 & 0xFF);
        }
        if ((flag & 0x1))
        {
            u32 read_val;
            if (decode->chunkLen >= 1024)
            {
                func_8004DA40(decode->src, &D_800ABFF0, 1024);
                decode->src += 1024;
                decode->chunkLen = 0;
            }
            read_val = D_800ABFF0[decode->chunkLen++];
            D_800AC3F0[windowPos++] = *(decode->dest++) = read_val;
            windowPos &= 0x3FF;
            decode->len--;
        }
        else
        {
            if (decode->chunkLen >= 1024)
            {
                func_8004DA40(decode->src, &D_800ABFF0, 1024);
                decode->src += 1024;
                decode->chunkLen = 0;
            }
            byte1 = D_800ABFF0[decode->chunkLen++];

            if (decode->chunkLen >= 1024)
            {
                func_8004DA40(decode->src, &D_800ABFF0, 1024);
                decode->src += 1024;
                decode->chunkLen = 0;
            }
            len = D_800ABFF0[decode->chunkLen++];

            byte1 = byte1 | ((len & 0xC0) << 2);
            len = 3 + (len & 0x3F);

            for (i = 0; i < len; i++)
            {
                {
                    winTemp = windowPos++;
                    *(decode->dest++) = (copyVal = D_800AC3F0[(byte1 + i) & 0x3FF]);
                    D_800AC3F0[winTemp] = copyVal;
                    windowPos &= 0x3FF;
                }
            }
            decode->len -= i;
        }
    }
}

// Type 2 decompression.
void HuDecodeSlide(struct decode_struct *decode)
{
    s32 codeWordBitsRemaining;
    s32 curCodeWord;
    u8 *destOrig;

    // Advance past the first 4 bytes.
    if (decode->chunkLen >= 1024)
    {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024)
    {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024)
    {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024)
    {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;

    codeWordBitsRemaining = 0;
    curCodeWord = 0;
    destOrig = decode->dest;

    while (decode->len != 0)
    {
        // Read a new code word.
        if (codeWordBitsRemaining == 0)
        {
            {
                u32 chunkByte1, chunkByte2, chunkByte3, chunkByte4;

                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte1 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte2 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte3 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte4 = D_800ABFF0[decode->chunkLen++];

                curCodeWord = (chunkByte1 << 24) + (chunkByte2 << 16) + (chunkByte3 << 8) + chunkByte4;
                codeWordBitsRemaining = 32;
            }
        }

        if (curCodeWord < 0)
        {
            {
                u32 nextByte;

                // Copy the next byte from the source to the destination.
                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                nextByte = D_800ABFF0[decode->chunkLen++];

                *(decode->dest++) = nextByte;
                decode->len--;
            }
        }
        else
        {
            {
                u32 back, back2, count;
                u8 *ptr;

                // Interpret the next two bytes as a distance to travel backwards and a
                // a length to read.
                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back2 = D_800ABFF0[decode->chunkLen++];

                back2 = (back << 8) + (back2 & 0xFFFFFFFFFFFFFFFF); // Unlikely, but matching.
                count = (back << 8) >> 12;
                back2 &= 0xFFF;
                ptr = decode->dest - back2;
                if (count == 0)
                {
                    if (decode->chunkLen >= 1024)
                    {
                        func_8004DA40(decode->src, &D_800ABFF0, 1024);
                        decode->src += 1024;
                        decode->chunkLen = 0;
                    }

                    count = 0x12;
                    count += D_800ABFF0[decode->chunkLen++];
                }
                else
                {
                    count += 2;
                }
                decode->len -= count;

                while (count != 0)
                {
                    if (ptr - 1 < destOrig)
                    {
                        *(decode->dest++) = 0;
                    }
                    else
                    {
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
void HuDecodeFslide(struct decode_struct *decode)
{
    s32 codeWordBitsRemaining;
    s32 curCodeWord;
    u8 *destOrig;

    // Advance past the first 4 bytes.
    if (decode->chunkLen >= 1024)
    {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024)
    {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024)
    {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;
    if (decode->chunkLen >= 1024)
    {
        func_8004DA40(decode->src, &D_800ABFF0, 1024);
        decode->src += 1024;
        decode->chunkLen = 0;
    }
    decode->chunkLen++;

    codeWordBitsRemaining = 0;
    curCodeWord = 0;

    destOrig = decode->dest;

    while (decode->len != 0)
    {
        // Read a new code word.
        if (codeWordBitsRemaining == 0)
        {
            {
                u32 chunkByte1, chunkByte2, chunkByte3, chunkByte4;

                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte1 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte2 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte3 = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                chunkByte4 = D_800ABFF0[decode->chunkLen++];

                curCodeWord = (chunkByte1 << 24) + (chunkByte2 << 16) + (chunkByte3 << 8) + chunkByte4;
                codeWordBitsRemaining = 32;
            }
        }

        if (curCodeWord < 0)
        {
            {
                u32 nextByte;

                // Copy the next byte from the source to the destination.
                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                nextByte = D_800ABFF0[decode->chunkLen++];

                *(decode->dest++) = nextByte;
                decode->len--;
            }
        }
        else
        {
            {
                u32 back, back2, count;
                u8 *ptr;

                // Interpret the next two bytes as a distance to travel backwards and a
                // a length to read.
                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back = D_800ABFF0[decode->chunkLen++];

                if (decode->chunkLen >= 1024)
                {
                    func_8004DA40(decode->src, &D_800ABFF0, 1024);
                    decode->src += 1024;
                    decode->chunkLen = 0;
                }
                back2 = D_800ABFF0[decode->chunkLen++];

                back2 = (back << 8) + (back2 & 0xFFFFFFFFFFFFFFFF); // Unlikely, but matching.
                count = (back << 8) >> 12;
                back2 &= 0xFFF;
                ptr = decode->dest - back2;
                if (count == 0)
                {
                    if (decode->chunkLen >= 1024)
                    {
                        func_8004DA40(decode->src, &D_800ABFF0, 1024);
                        decode->src += 1024;
                        decode->chunkLen = 0;
                    }

                    count = 0x12;
                    count += D_800ABFF0[decode->chunkLen++];
                }
                else
                {
                    count += 2;
                }
                decode->len -= count;

                while (count != 0)
                {
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
void HuDecodeRLE(struct decode_struct *decode)
{
    s32 curCodeByte;
    s32 i;
    s32 byteValue;

    while (decode->len != 0)
    {
        if (decode->chunkLen >= 1024)
        {
            func_8004DA40(decode->src, &D_800ABFF0, 1024);
            decode->src += 1024;
            decode->chunkLen = 0;
        }

        curCodeByte = D_800ABFF0[decode->chunkLen++];
        if (curCodeByte < 0x80)
        {
            // No sign bit means we repeat the next byte n times.
            if (decode->chunkLen >= 1024)
            {
                func_8004DA40(decode->src, &D_800ABFF0, 1024);
                decode->src += 1024;
                decode->chunkLen = 0;
            }

            byteValue = D_800ABFF0[decode->chunkLen++];

            for (i = 0; i < curCodeByte; i++)
            {
                *(decode->dest++) = byteValue;
            }
        }
        else
        {
            // Having the sign bit means we read the next n bytes from the input.
            curCodeByte = curCodeByte - 0x80;

            for (i = 0; i < curCodeByte; i++)
            {
                if (decode->chunkLen >= 1024)
                {
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

void HuDecode(void *src, void *dest, s32 len, EDecodeType decodeType)
{
    struct decode_struct decodeStruct;
    struct decode_struct *decodePtr = &decodeStruct;
    decodeStruct.src = (u8 *)src;
    decodeStruct.dest = (u8 *)dest;
    decodeStruct.len = len;
    decodeStruct.chunkLen = 1024;
    switch (decodeType)
    {
    case DECODE_NONE:
        HuDecodeNone(decodePtr);
        break;

    case DECODE_LZ:
        HuDecodeLZ(decodePtr);
        break;

    case DECODE_SLIDE:
        HuDecodeSlide(decodePtr);
        break;

    case DECODE_FSLIDE:
    case DECODE_FSLIDE_2:
        HuDecodeFslide(decodePtr);
        break;

    case DECODE_RLE:
        HuDecodeRLE(decodePtr);
        break;

    default:
        break;
    }
}
