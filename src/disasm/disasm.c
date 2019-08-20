#include "disasm.h"

Instruction *get_instruction(const void *addr) {
    if (addr == NULL) {
        return NULL;
    }
    Instruction *instr = (Instruction *)local_malloc(sizeof(Instruction));
    if (instr == NULL) {
        return NULL;
    }

    return instr;
}

