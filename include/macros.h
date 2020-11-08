#ifndef _MACROS_H_
#define _MACROS_H_

#include "ultra64.h"

#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...) \
  TYPE __attribute__((naked)) NAME(ARGS) { __asm__(".include \"include/macro.inc\"\n.include \"asm/nonmatchings/"FOLDER"/"#NAME".s\"\n.set reorder\n.set at"); }

#endif
