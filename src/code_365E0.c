#include "common.h"
#include "code_365E0.h"

// Function called by `main` overlay entrypoints, usually boards,
// that redirects to some particular function based on current state.
void func_800359E0(struct overlay_entrypoint *entrypoints, s16 index) {
    struct overlay_entrypoint *curEntrypoint;

    curEntrypoint = entrypoints;
    while (curEntrypoint->index >= 0) {
        if (curEntrypoint->index == index) {
            curEntrypoint->fn();
        }
        curEntrypoint++;
    }
}
