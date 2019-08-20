#ifndef DISASM_H
#define DISASM_H

#include "prefix.h"
#include "instruction.h"
#include "utility.h"

#ifdef __cplusplus
extern "C" {
#endif

Instruction *get_instruction(const void *addr);

#ifdef __cplusplus
}
#endif

#endif // DISASM_H
