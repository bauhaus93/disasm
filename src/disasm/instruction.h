#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <inttypes.h>

#include "operation.h"

typedef struct {
    Operation op;
    uint8_t size;
} Instruction;

#endif // INSTRUCTION_H
