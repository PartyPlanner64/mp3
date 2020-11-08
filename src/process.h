#ifndef _PROCESS_H
#define _PROCESS_H

#include <ultra64.h>
#include "setjmp.h"

#define EXEC_PROCESS_DEFAULT 0
#define EXEC_PROCESS_SLEEPING 1
#define EXEC_PROCESS_WATCH 2
#define EXEC_PROCESS_DEAD 3

typedef void (*process_func)();

struct process
{
    /*0x00*/ struct process *next;
    /*0x04*/ struct process *youngest_child;
    /*0x08*/ struct process *oldest_child;
    /*0x0C*/ struct process *relative;
    /*0x10*/ struct process *parent_oldest_child;
    /*0x14*/ struct process *new_process;
    /*0x18*/ void *heap;
    /*0x1C*/ u16 exec_mode;
    /*0x1E*/ u16 stat;
    /*0x20*/ u16 priority;
    /*0x22*/ s16 dtor_idx;
    /*0x24*/ s32 sleep_time;
    /*0x28*/ void *base_sp;
    /*0x2C*/ jmp_buf prc_jump;
    /*0x88*/ process_func destructor;
    /*0x8C*/ void *user_data;
};

void InitProcessSys();
void LinkProcess(struct process **root, struct process *process);
void UnlinkProcess(struct process **root, struct process *process);
struct process *CreateProcess(process_func func, u16 priority, s32 stack_size, s32 extra_data_size);
void LinkChildProcess(struct process *process, struct process *child);
void UnlinkChildProcess(struct process *process);
struct process *CreateChildProcess(process_func func, u16 priority, s32 stack_size, s32 extra_data_size, struct process *parent);
void WaitForChildProcess();
struct process *GetCurrentProcess();
s32 GetChildProcess(struct process *process);
s32 SetKillStatusProcess(struct process *process);
void KillProcess(struct process *process);
void KillChildProcess(struct process *process);
void TerminateProcess(struct process *process);
void ExitProcess();
void SleepProcess(s32 time);
void SleepVProcess();
void WakeupProcess(struct process *process);
void SetProcessDestructor(struct process *process, process_func destructor);
void SetCurrentProcessDestructor(process_func destructor);
// void CallProcess(s32 time);
void *AllocProcessMemory(s32 size);
void FreeProcessMemory(void *ptr);

#endif /* _PROCESS_H */
