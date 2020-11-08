#ifndef _SETJMP_H
#define _SETJMP_H

#include <ultra64.h>

typedef struct jump_buf
{
    void *sp;
    void *func;
    u32 regs[21];
} jmp_buf;

extern s32 setjmp(jmp_buf *jump_buf);
extern s32 longjmp(jmp_buf *jump_buf, s32 val);

#endif /* _SETJMP_H */
