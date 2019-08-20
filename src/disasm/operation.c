#include "operation.h"

static Operation *get_one_byte_operation(const void *addr);
static int fill_op_row0(Operation *op, uint8_t col);
static void fill_operands_same_type(Operation *op, char am_letter_first,
                                    char am_letter_second, OperandType type);

Operation *get_operation(const void *addr) {
    if (addr == NULL) {
        return NULL;
    }

    switch (*((const uint8_t *)addr)) {
    case 0x0F: // TODO two/three byte opcodes
        return NULL;
    default:
        return get_one_byte_operation(addr);
    }
}

static Operation *get_one_byte_operation(const void *addr) {
    Operation *op = (Operation *)local_malloc(sizeof(Operation));
    if (op == NULL) {
        return NULL;
    }

    uint8_t opcode = *((const uint8_t *)addr);
    uint8_t row = (opcode >> 4) & 0xF;
    uint8_t col = opcode & 0xF;

    switch (row) {
    case 0x0:
        fill_op_row0(op, col);
        break;
    default:
        break;
    }
    return op;
}

static int fill_op_row0(Operation *op, uint8_t col) {
    if (col <= 5) {
        op->type = OP_ADD;
    } else if (col == 6) {
        op->type = OP_PUSH_ES;
    } else if (col == 7) {
        op->type = OP_POP_ES;
    }

    switch (col) {
    case 0x0:
        fill_operands_same_type(op, 'E', 'G', 'b');
        break;
    case 0x1:
        fill_operands_same_type(op, 'E', 'G', 'v');
        break;
    case 0x2:
        fill_operands_same_type(op, 'G', 'E', 'b');
        break;
    case 0x3:
        fill_operands_same_type(op, 'G', 'E', 'v');
        break;
    case 0x4:
        break;
    }
    return 0;
}

static void fill_operands_same_type(Operation *op, char am_letter_first,
                                    char am_letter_second, OperandType type) {
    op->operand[0].am = get_addressing_method_by_letter(am_letter_first);
    op->operand[1].am = get_addressing_method_by_letter(am_letter_second);
    op->operand[0].type = type;
    op->operand[1].type = type;
    op->operand_count = 2;
}
