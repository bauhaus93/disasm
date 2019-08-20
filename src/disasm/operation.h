#ifndef OPERATION_H
#define OPERATION_H

#include <inttypes.h>
#include <stdlib.h>

#include "addressing_method.h"
#include "operand_type.h"
#include "utility.h"

typedef struct {
    AddressingMethod am;
    OperandType type;
} Operand;

typedef enum { OP_ADD, OP_PUSH_ES, OP_POP_ES } OperationType;

typedef struct {
    OperationType type;
    Operand operand[2];
    uint8_t operand_count;
} Operation;

#ifdef __cplusplus
extern "C" {
#endif

Operation *get_operation(const void *addr);

#ifdef __cplusplus
}
#endif

#endif // OPERATION_H
