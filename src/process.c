#include "common.h"

#include <ultra64.h>
#include "process.h"
#include "heap.h"
#include "heap_permanent.h"

extern jmp_buf process_jmp_buf;
extern struct process *top_process;
extern struct process *current_process;
extern s16 process_count;

void InitProcessSys()
{
    process_count = 0;
    top_process = NULL;
}

void LinkProcess(struct process **root, struct process *process)
{
    struct process *src_process = *root;
    if (src_process != NULL && (src_process->priority >= process->priority))
    {
        while (src_process->next != NULL)
        {
            if (src_process->next->priority < process->priority)
            {
                break;
            }
            src_process = src_process->next;
        }

        process->next = src_process->next;
        process->youngest_child = src_process;
        src_process->next = process;
        if (process->next)
        {
            process->next->youngest_child = process;
        }
    }
    else
    {
        process->next = (*root);
        process->youngest_child = NULL;
        *root = process;
        if (src_process != NULL)
        {
            src_process->youngest_child = process;
        }
    }
}

void UnlinkProcess(struct process **root, struct process *process)
{
    if (process->next)
    {
        process->next->youngest_child = process->youngest_child;
    }
    if (process->youngest_child)
    {
        process->youngest_child->next = process->next;
    }
    else
    {
        *root = process->next;
    }
}

struct process *CreateProcess(process_func func, u16 priority, s32 stack_size, s32 extra_data_size)
{
    struct heap_node *process_heap;
    struct process *process;
    s32 alloc_size;

    if (stack_size == 0) {
        stack_size = 2048;
    }

    alloc_size = GetMemoryAllocSize(sizeof(struct process))
        + GetMemoryAllocSize(stack_size)
        + GetMemoryAllocSize(extra_data_size);

    process_heap = (struct heap_node *)MallocPerm(alloc_size);
    if (process_heap == NULL) {
        return NULL;
    }
    MakeHeap(process_heap, alloc_size);

    process = (struct process *)Malloc(process_heap, sizeof(struct process));
    process->heap = process_heap;
    process->exec_mode = EXEC_PROCESS_DEFAULT;
    process->stat = 0;
    process->priority = priority;
    process->sleep_time = 0;
    process->base_sp = Malloc(process_heap, stack_size) + stack_size - 8;
    process->prc_jump.func = func;
    process->prc_jump.sp = process->base_sp;
    process->destructor = NULL;
    process->user_data = NULL;
    process->dtor_idx = 0;
    LinkProcess(&top_process, process);
    process->oldest_child = NULL;
    process->relative = NULL;
    process_count++;
    return process;
}

void LinkChildProcess(struct process *process, struct process *child)
{
    UnlinkChildProcess(child);
    if (process->oldest_child)
    {
        process->oldest_child->new_process = child;
    }
    child->parent_oldest_child = process->oldest_child;
    child->new_process = NULL;
    process->oldest_child = child;
    child->relative = process;
}

void UnlinkChildProcess(struct process *process)
{
    if (process->relative)
    {
        if (process->parent_oldest_child)
        {
            process->parent_oldest_child->new_process = process->new_process;
        }
        if (process->new_process)
        {
            process->new_process->parent_oldest_child = process->parent_oldest_child;
        }
        else
        {
            process->relative->oldest_child = process->parent_oldest_child;
        }
        process->relative = NULL;
    }
}

struct process *CreateChildProcess(process_func func, u16 priority, s32 stack_size, s32 extra_data_size, struct process *parent)
{
    struct process *child = CreateProcess(func, priority, stack_size, extra_data_size);
    LinkChildProcess(parent, child);
    return child;
}

void WaitForChildProcess()
{
    struct process *process = GetCurrentProcess();
    if (process->oldest_child)
    {
        process->exec_mode = EXEC_PROCESS_WATCH;
        if (!setjmp(&process->prc_jump))
        {
            longjmp(&process_jmp_buf, 1);
        }
    }
}

struct process *GetCurrentProcess()
{
    return current_process;
}

s32 GetChildProcess(struct process *process)
{
    s32 i;
    struct process *curr_child = process->oldest_child;
    i = 0;
    while (curr_child)
    {
        curr_child = curr_child->parent_oldest_child;
        i++;
    }
    return i;
}

s32 SetKillStatusProcess(struct process *process)
{
    if (process->exec_mode != EXEC_PROCESS_DEAD)
    {
        WakeupProcess(process);
        process->exec_mode = EXEC_PROCESS_DEAD;
        return 0;
    }
    else
    {
        return -1;
    }
}

void KillProcess(struct process *process)
{
    KillChildProcess(process);
    UnlinkChildProcess(process);
    SetKillStatusProcess(process);
}

void KillChildProcess(struct process *process)
{
    struct process *curr_child = process->oldest_child;
    while (curr_child != NULL)
    {
        if (curr_child->oldest_child != NULL) {
            KillChildProcess(curr_child);
        }
        SetKillStatusProcess(curr_child);
        curr_child = curr_child->parent_oldest_child;
    }
    process->oldest_child = NULL;
}

void TerminateProcess(struct process *process)
{
    if (process->destructor)
    {
        process->destructor();
    }
    UnlinkProcess(&top_process, process);
    process_count--;
    longjmp(&process_jmp_buf, 2);
}

void ExitProcess()
{
    struct process *process = GetCurrentProcess();
    KillChildProcess(process);
    UnlinkChildProcess(process);
    TerminateProcess(process);
}

void SleepProcess(s32 time)
{
    struct process *process = GetCurrentProcess();
    if (time != 0 && process->exec_mode != EXEC_PROCESS_DEAD)
    {
        process->exec_mode = EXEC_PROCESS_SLEEPING;
        process->sleep_time = time;
    }
    if (!setjmp(&process->prc_jump))
    {
        longjmp(&process_jmp_buf, 1);
    }
}

void SleepVProcess()
{
    SleepProcess(0);
}

void WakeupProcess(struct process *process)
{
    process->sleep_time = 0;
}

void SetProcessDestructor(struct process *process, process_func destructor)
{
    process->destructor = destructor;
}

void SetCurrentProcessDestructor(process_func destructor)
{
    struct process *process = GetCurrentProcess();
    SetProcessDestructor(process, destructor);
}

#ifdef NONMATCHING
// void CallProcess(s32 time)
// {
//     struct process *cur_proc_local;
//     s32 ret;

//     current_process = top_process;
//     ret = setjmp(&process_jmp_buf);
//     while (1)
//     {
//         switch (ret)
//         {
//             case 2:
//                 FreePerm(current_process->heap);

//             case 1:
//                 current_process = current_process->next;
//                 break;
//         }

//         cur_proc_local = current_process;
//         if (cur_proc_local == NULL)
//         {
//             break;
//         }

//         if ((cur_proc_local->stat & 0x1))
//         {
//             if (cur_proc_local->exec_mode != 1)
//             {
//                 ret = 1;
//                 continue;
//             }
//         }

//         switch (cur_proc_local->exec_mode)
//         {
//             case EXEC_PROCESS_SLEEPING:
//                 ret = 1;
//                 if (cur_proc_local->sleep_time <= 0)
//                 {
//                     continue;
//                 }
//                 if ((cur_proc_local->sleep_time -= time) > 0)
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     cur_proc_local->sleep_time = 0;
//                     cur_proc_local->exec_mode = EXEC_PROCESS_DEFAULT;
//                 }
//                 break;

//             case EXEC_PROCESS_WATCH:
//                 if (cur_proc_local->oldest_child != NULL)
//                 {
//                     ret = 1;
//                 }
//                 else
//                 {
//                     cur_proc_local->exec_mode = EXEC_PROCESS_DEFAULT;
//                     ret = 0;
//                 }
//                 break;

//             case EXEC_PROCESS_DEAD:
//                 cur_proc_local->prc_jump.func = ExitProcess;

//             case 0:
//                 longjmp(&cur_proc_local->prc_jump, 1);
//                 break;
//         }
//     }
// }
#else
INCLUDE_ASM(s32, "process", CallProcess);
#endif

void *AllocProcessMemory(s32 size)
{
    struct process *process = GetCurrentProcess();
    return (void *)Malloc((struct heap_node *)process->heap, size);
}

void FreeProcessMemory(void *ptr)
{
    Free(ptr);
}
