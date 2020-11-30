#include "common.h"

INCLUDE_ASM(const u8 *, "libultra/libc/string", strchr, const u8* str, s32 ch);

size_t strlen(const char *s) {
    const char *sc = s;
    while (*sc) {
        sc++;
    }
    return sc - s;
}

void *memcpy(void *s1, const void *s2, size_t n) {
    char *su1 = (char *)s1;
    const char *su2 = (const char *)s2;
    while (n > 0) {
        *su1++ = *su2++;
        n--;
    }
    return (void *)s1;
}
