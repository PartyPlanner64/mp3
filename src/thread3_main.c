#include "common.h"
#include "heap_permanent.h"
#include "heap_temporary.h"
#include "process.h"

extern s32 D_800A08B0;
extern void *D_800A1240[3];
extern void *D_800A124C;
extern void *D_800A125C;
extern s32 D_800A12A0;
extern u8 D_800CCF52;
extern OSMesgQueue D_800CCF38;
extern OSMesgQueue D_800CCF60;
extern s32 D_800D1F70;
extern u32 D_800D2094;

extern void *data_557E20_ROM_START;

#define INTR_MESG_BUF_SIZE 256
#define OTHER_MESG_BUF_SIZE 8

extern void func_8000E3C0();
extern s32 func_8004D6AC(s32, s32, s32);
extern void func_800639F8(void *, OSMesgQueue *, s32);

INCLUDE_ASM(void, "thread3_main", func_800354A0);

// void func_800354A0() {
//     s32 iVar5;
//     s32 stopLooping;

//     OSMesg msg;
//     OSMesg intrMesgBuf[INTR_MESG_BUF_SIZE + 4];

//     OSMesg otherMsg;
//     OSMesg otherMesgBuf[OTHER_MESG_BUF_SIZE + 4];

//     iVar5 = 0;
//     stopLooping = FALSE;

//     if (osTvType == TV_TYPE_NTSC) {
//         func_80050F90(2, 1);
//     }
//     else if (osTvType != TV_TYPE_NTSC) {
//         stopLooping = FALSE;
//         func_80050F90(0x1E, 1);
//     }
//     else {
//         goto spinloop; // FIXME: This jump cannot be reached, but it is present in the ROM.
//     }

//     // This is all that MP1 did:
//     //func_80050F90(osTvType == TV_TYPE_NTSC ? 2 : 0x1E, 1);

//     MakePermHeap((void *)0x80140000, 0x1A0000);
//     MakeTempHeap((void *)0x80128000, 0x18000);

//     D_800CCF52 = 3;

//     func_8000EA10(&D_800A1240, 3, 2, &D_800A124C, &D_800A125C);

//     if (osTvType == TV_TYPE_PAL) {
//         while (TRUE) {}
//     }

//     func_8004D410(0, 0x20, 0xD2, 0x20, 0xD4);
//     func_80051750();
//     func_80008F3C(4, 1);
//     func_8005A3C0();
//     func_80009880();
//     func_8004D9A0();

//     func_80009AC0(&data_557E20_ROM_START);

//     InitProcessSys();

//     osCreateMesgQueue(&D_800CCF38, &intrMesgBuf[4], INTR_MESG_BUF_SIZE);
//     func_800511C4(&intrMesgBuf, &D_800CCF38, 1);
//     osCreateMesgQueue(&D_800CCF60, &otherMesgBuf[4], OTHER_MESG_BUF_SIZE);
//     func_800511C4(&otherMesgBuf, &D_800CCF60, 2);

//     func_800094E4();
//     func_8007D740(2);
//     func_8000F094(2);
//     CreateProcess(func_8000E3C0, 1, 0, 0);

//     while (!stopLooping) {
//         if (osRecvMesg(&D_800CCF60, &otherMsg, 0) != -1) {
//             break;
//         }

//         osRecvMesg(&D_800CCF38, &msg, OS_MESG_BLOCK);
//         switch ((s32)msg) {
//             case 1:
//                 {
//                     s32 temp_s0;
//                     s16 temp_s1;

//                     if (D_800D2094 - iVar5 >= 2) {
//                         iVar5 = D_800D2094;
//                         if (D_800A12A0 < D_800CCF52) {
//                             func_8004D7D8();
//                             temp_s1 = func_8004D6AC(0xC8, 0, 0);
//                             func_800094E4();
//                             func_800098FC();
//                             temp_s0 = D_800A08B0;
//                             CallProcess(1);
//                             if (temp_s0 != D_800A08B0) {
//                                 D_800A12A0++;
//                             }
//                             func_8004D6E8(temp_s1);
//                             func_8004D814();
//                         }
//                     }
//                 }
//                 break;

//             case 777:
//                 D_800A12A0--;
//                 D_800D1F70++;
//                 break;

//             case 2:
//                 stopLooping = TRUE;
//                 break;
//         }
//     }

// spinloop:
//     while (TRUE) {}
// }

// INCLUDE_ASM(s32, "thread3_main", func_800357AC);

void func_800357AC(s16 count) {
    s16 i = 0;
    for (i = 0; i < count; i++) {
        func_80087A40(*(&D_800A1240[i]), 0, 0x25800); // sizeof(gZBuffer) ?
    }
}
