#include "common.h"

// entrypoint 0
void func_801059D0_31B3E0() {
    if (func_80035EB0(0) != 0) {
        func_80035FDC(1);
    }
    else {
        func_8003602C(1);
    }
    InitObjSys(0xA, 0);
    func_800F86B4();
    func_80048228(0x47, 1, 0x192);
    func_80048460(0, 0x47, 1, 0x192);
}

// entrypoint 1
void func_80105A44_31B454() {
    InitObjSys(0xA, 0);
    func_800F8774();
}

void func_80105A6C_31B47C() {
    func_8004819C(1);
    func_8004849C();
    SleepVProcess();
}

// entrypoint 2
void func_80105A98_31B4A8() {
    InitObjSys(0xA, 0xA);
    func_8004A208();
    InitProcess(func_80105A6C_31B47C, 0x1005, 0, 0);
}
