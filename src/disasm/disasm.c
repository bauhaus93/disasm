#include "disasm.h"

Instruction *get_instruction(const void *addr) {
    if (addr == NULL) {
        return NULL;
    }
    Instruction *instr = (Instruction *)local_malloc(sizeof(Instruction));
    if (instr == NULL) {
        return NULL;
    }
    const void *curr_addr = addr;

    PrefixList *prefix_root = get_prefixes(curr_addr);
    int prefix_count = count_prefixes(prefix_root);
    instr->prefixes = prefix_root;

    OFFSET_ADDR(curr_addr, prefix_count);


    return instr;
}
